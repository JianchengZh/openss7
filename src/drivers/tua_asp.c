/*****************************************************************************

 @(#) File: src/drivers/tua_asp.c

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation, version 3 of the license.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

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

 *****************************************************************************/

static char const ident[] = "src/drivers/tua_asp.c (" PACKAGE_ENVR ") " PACKAGE_DATE;

/*
 *  =========================================================================
 *
 *  TUA Peer --> TUA Received Messages
 *
 *  =========================================================================
 */
/*
 *  UA_RKMM_REG_REQ	0x1
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_reg_req(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  UA_RKMM_REG_RSP	0x2
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_reg_rsp(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  UA_RKMM_DEREG_REQ	0x3
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_dereg_req(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  UA_RKMM_DEREG_RSP	0x4
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_dereg_rsp(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_UNI	0x0
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_uni(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_BEG	0x1
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_beg(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_CON	0x2
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_con(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_END	0x3
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_end(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_U_ABT	0x4
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_u_abt(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_P_ABT	0x5
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_p_abt(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TDHM_NOT	0x6
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_not(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TCHM_IVK	0x0
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_ivk(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TCHM_RES	0x1
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_res(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TCHM_U_ERR	0x2
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_u_err(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  TUA_TCHM_REJ	0x3
 *  -------------------------------------------------------------------------
 */
static int
tua_recv_rej(asp_t * asp, mblk_t *msg)
{
	(void) asp;
	(void) msg;
	return (-EOPNOTSUPP);
}

/*
 *  Common defined ASP/SGP management procedures.
 */
extern int (*ua_asp_mgmt[]) (asp_t *, mblk_t *);
extern int (*ua_asp_asps[]) (asp_t *, mblk_t *);
extern int (*ua_asp_aspt[]) (asp_t *, mblk_t *);

static int (*tua_rkmm[]) (asp_t *, mblk_t *) = {
	NULL,			/* (reserved) 0x0 */
	    tua_recv_reg_req,	/* UA_RKMM_REG_REQ 0x1 */
	    tua_recv_reg_rsp,	/* UA_RKMM_REG_RSP 0x2 */
	    tua_recv_dereg_req,	/* UA_RKMM_DEREG_REQ 0x3 */
	    tua_recv_dereg_rsp	/* UA_RKMM_DEREG_RSP 0x4 */
};
static int (*tua_tdhm[]) (asp_t *, mblk_t *) = {
	tua_recv_uni,		/* TUA_TDHM_UNI 0x0 */
	    tua_recv_beg,	/* TUA_TDHM_BEG 0x1 */
	    tua_recv_con,	/* TUA_TDHM_CON 0x2 */
	    tua_recv_end,	/* TUA_TDHM_END 0x3 */
	    tua_recv_u_abt,	/* TUA_TDHM_U_ABT 0x4 */
	    tua_recv_p_abt,	/* TUA_TDHM_P_ABT 0x5 */
	    tua_recv_not	/* TUA_TDHM_NOT 0x6 */
};
static int (*tua_tchm[]) (asp_t *, mblk_t *) = {
	tua_recv_ivk,		/* TUA_TCHM_IVK 0x0 */
	    tua_recv_res,	/* TUA_TCHM_RES 0x1 */
	    tua_recv_u_err,	/* TUA_TCHM_U_ERR 0x2 */
	    tua_recv_rej	/* TUA_TCHM_REJ 0x3 */
};

static struct msg_class msg_decode[] = {
	{ua_asp_mgmt, UA_MGMT_LAST},	/* UA_CLASS_MGMT 0x0 */
	{NULL, 0},		/* UA_CLASS_XFER 0x1 */
	{NULL, 0},		/* UA_CLASS_SNMM 0x2 */
	{ua_asp_asps, UA_ASPS_LAST},	/* UA_CLASS_ASPS 0x3 */
	{ua_asp_aspt, UA_ASPT_LAST},	/* UA_CLASS_ASPT 0x4 */
	{NULL, 0},		/* UA_CLASS_Q921 0x5 */
	{NULL, 0},		/* UA_CLASS_MAUP 0x6 */
	{NULL, 0},		/* UA_CLASS_CNLS 0x7 */
	{NULL, 0},		/* UA_CLASS_CONS 0x8 */
	{tua_rkmm, UA_RKMM_LAST},	/* UA_CLASS_RKMM 0x9 */
	{tua_tdhm, TUA_TDHM},	/* UA_CLASS_TDHM 0xa */
	{tua_tchm TUA_TCHM}	/* UA_CLASS_TCHM 0xb */
};

int
tua_asp_recv_msg(asp_t * asp, mblk_t *msg)
{
	return ua_recv_msg(q, msg, msg_decode);
}
