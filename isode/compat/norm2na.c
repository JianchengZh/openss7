/*****************************************************************************

 @(#) $RCSfile$ $Name$($Revision$) $Date$

 -----------------------------------------------------------------------------

 Copyright (c) 2001-2007  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2000  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation, version 3 of the license.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 details.

 You should have received a copy of the GNU General Public License along with
 this program.  If not, see <http://www.gnu.org/licenses/>, or write to the
 Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 -----------------------------------------------------------------------------

 Last Modified $Date$ by $Author$

 -----------------------------------------------------------------------------

 $Log$
 *****************************************************************************/

#ident "@(#) $RCSfile$ $Name$($Revision$) $Date$"

static char const ident[] = "$RCSfile$ $Name$($Revision$) $Date$";

/* norm2na.c - normalize NSAPaddr to NSAP struct */

#ifndef	lint
static char *rcsid =
    "Header: /xtel/isode/isode/compat/RCS/norm2na.c,v 9.0 1992/06/16 12:07:00 isode Rel";
#endif

/* 
 * Header: /xtel/isode/isode/compat/RCS/norm2na.c,v 9.0 1992/06/16 12:07:00 isode Rel
 *
 *
 * Log: norm2na.c,v
 * Revision 9.0  1992/06/16  12:07:00  isode
 * Release 8.0
 *
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */

/* LINTLIBRARY */

#include <sys/types.h>
#include <stdio.h>
#include "psap.h"
#include "isoaddrs.h"
#include "tailor.h"
#include "internet.h"
#ifdef HAVE_STRING_H
#include <string.h>
#endif				/* HAVE_STRING_H */

/* Encoding on "unrealNS" addresses based on

   	"An interim approach to use of Network Addresses",
	S.E. Kille, January 16, 1989

 */

/*  */

int
norm2na(p, len, na)
	char *p;
	int len;
	struct NSAPaddr *na;
{
	na->na_stack = NA_NSAP;

	if ((len == 8) && ((p[0] == 0x36) || (p[0] == 0x37))) {
		int xlen;		/* SEK - X121 form */
		register char *cp, *cp2, *dp;
		char nsap[14];

		dp = nsap;
		for (cp2 = (cp = p + 1) + 7; cp < cp2; cp++) {
			register int j;

			if ((j = ((*cp & 0xf0) >> 4)) > 9)
				goto concrete;
			*dp++ = j + '0';

			if ((j = (*cp & 0x0f)) > 9) {
				if (j != 0x0f)
					goto concrete;
			} else
				*dp++ = j + '0';
		}

		for (cp = nsap, xlen = 14; *cp == '0'; cp++, xlen--)
			continue;
		na->na_dtelen = xlen;
		for (cp2 = na->na_dte; xlen-- > 0;)
			*cp2++ = *cp++;
		*cp2 = '\0';
		na->na_stack = NA_X25;
		na->na_community = SUBNET_INT_X25;
	} else {
		register struct ts_interim *ts, *tp;

		tp = NULL;
		for (ts = ts_interim; ts->ts_name; ts++)
			if (len > ts->ts_length && (tp == NULL || ts->ts_length > tp->ts_length)
			    && bcmp(p, ts->ts_prefix, ts->ts_length) == 0)
				tp = ts;
		if (tp) {
			int i, ilen, rlen;
			register char *cp, *dp, *ep;
			char nsap[NASIZE * 2 + 1];

			if (tp->ts_syntax == NA_NSAP)
				goto lock_and_load;
			dp = nsap;
			for (cp = p + tp->ts_length, ep = p + len; cp < ep; cp++) {
				register int j;

				if ((j = ((*cp & 0xf0) >> 4)) > 9) {
				      concrete:;
					LLOG(addr_log, LLOG_EXCEPTIONS,
					     ("invalid concrete encoding"));
					goto realNS;
				}
				*dp++ = j + '0';

				if ((j = (*cp & 0x0f)) > 9) {
					if (j != 0x0f)
						goto concrete;
				} else
					*dp++ = j + '0';
			}
			*dp = '\0';

			cp = nsap;
		      lock_and_load:;
			na->na_community = tp->ts_subnet;
			switch (na->na_stack = tp->ts_syntax) {
			case NA_NSAP:
				goto unrealNS;

			case NA_X25:
				if ((int) strlen(cp) < 1) {
					LLOG(addr_log, LLOG_EXCEPTIONS,
					     ("missing DTE+CUDF indicator: %s", nsap));
					goto realNS;
				}
				(void) sscanf(cp, "%1d", &i);
				cp += 1;
				switch (i) {
				case 0:	/* DTE only */
					break;

				case 1:	/* DTE+PID */
				case 2:	/* DTE+CUDF */
					if ((int) strlen(cp) < 1) {
						LLOG(addr_log, LLOG_EXCEPTIONS,
						     ("missing DTE+CUDF indicator: %s", nsap));
						goto realNS;
					}
					(void) sscanf(cp, "%1d", &ilen);
					cp += 1;
					rlen = ilen * 3;
					if ((int) strlen(cp) < rlen) {
						LLOG(addr_log, LLOG_EXCEPTIONS,
						     ("bad DTE+CUDF length: %s", nsap));
						goto realNS;
					}
					if (i == 1) {
						if (ilen > NPSIZE) {
							LLOG(addr_log, LLOG_EXCEPTIONS,
							     ("PID too long: %s", nsap));
							goto realNS;
						}
						dp = na->na_pid;
						na->na_pidlen = ilen;
					} else {
						if (ilen > CUDFSIZE) {
							LLOG(addr_log, LLOG_EXCEPTIONS,
							     ("CUDF too long: %s", nsap));
							goto realNS;
						}
						dp = na->na_cudf;
						na->na_cudflen = ilen;
					}
					for (; rlen > 0; rlen -= 3) {
						(void) sscanf(cp, "%3d", &i);
						cp += 3;

						if (i > 255) {
							LLOG(addr_log, LLOG_EXCEPTIONS,
							     ("invalid PID/CUDF: %s", nsap));
							goto realNS;
						}
						*dp++ = i & 0xff;
					}
					break;

				default:
					LLOG(addr_log, LLOG_EXCEPTIONS,
					     ("invalid DTE+CUDF indicator: %s", nsap));
					goto realNS;
				}
				(void) strcpy(na->na_dte, cp);
				na->na_dtelen = strlen(na->na_dte);
				break;

			case NA_TCP:
				if ((int) strlen(cp) < 12) {
					LLOG(addr_log, LLOG_EXCEPTIONS,
					     ("missing IP address: %s", nsap));
					goto realNS;
				}
				{
					int q[4];

					(void) sscanf(cp, "%3d%3d%3d%3d", q, q + 1, q + 2, q + 3);
					(void) sprintf(na->na_domain,
						       "%d.%d.%d.%d", q[0], q[1], q[2], q[3]);
				}
				cp += 12;

				if (*cp) {
					if ((int) strlen(cp) < 5) {
						LLOG(addr_log, LLOG_EXCEPTIONS,
						     ("missing port: %s", nsap));
						goto realNS;
					}
					(void) sscanf(cp, "%5d", &i);
					cp += 5;
					na->na_port = htons((unsigned short) i);

					if (*cp) {
						if ((int) strlen(cp) < 5) {
							LLOG(addr_log, LLOG_EXCEPTIONS,
							     ("missing tset: %s", nsap));
							goto realNS;
						}
						(void) sscanf(cp, "%5d", &i);
						cp += 5;
						na->na_tset = (unsigned short) i;

						if (*cp) {
							LLOG(addr_log, LLOG_EXCEPTIONS,
							     ("extra TCP information: %s", nsap));
						}
					}
				}
				break;

			default:
				LLOG(addr_log, LLOG_NOTICE,
				     ("unknown syntax %d for DSP: %s", ts->ts_syntax, nsap));
				goto realNS;
			}
		} else {
		      realNS:;
			na->na_stack = NA_NSAP;
			na->na_community = SUBNET_REALNS;
		      unrealNS:;
			if (len > sizeof na->na_address) {
				LLOG(addr_log, LLOG_EXCEPTIONS,
				     ("NSAP address too long: %d octets", len));
				return NOTOK;
			}
			bcopy(p, na->na_address, na->na_addrlen = len);
		}
	}

	return OK;
}

static inline void
dummy(void)
{
	(void) rcsid;
}