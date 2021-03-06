## vim: ft=automake comments=b\:#,b\:##,b\:#\! formatoptions+=tcqlor
## =============================================================================
## 
# @(#) File: doc/manual/Makefile.am  Version: @VERSION@  Date: @PACKAGE_DATE@
##
## -----------------------------------------------------------------------------
##
## Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
## Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
## Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>
##
## All Rights Reserved.
##
## This program is free software; you can redistribute it and/or modify it under
## the terms of the GNU Affero General Public License as published by the Free
## Software Foundation; version 3 of the License.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
## FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
## details.
##
## You should have received a copy of the GNU Affero General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>, or
## write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
## 02139, USA.
##
## -----------------------------------------------------------------------------
##
## U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
## behalf of the U.S. Government ("Government"), the following provisions apply
## to you.  If the Software is supplied by the Department of Defense ("DoD"), it
## is classified as "Commercial Computer Software" under paragraph 252.227-7014
## of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
## successor regulations) and the Government is acquiring only the license rights
## granted herein (the license rights customarily provided to non-Government
## users).  If the Software is supplied to any unit or agency of the Government
## other than DoD, it is classified as "Restricted Computer Software" and the
## Government's rights in the Software are defined in paragraph 52.227-19 of the
## Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
## the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
## (or any successor regulations).
##
## -----------------------------------------------------------------------------
##
## Commercial licensing and support of this software is available from OpenSS7
## Corporation at a fee.  See http://www.openss7.com/
##
## =============================================================================

include ../../am/openss7.am

info_TEXINFOS		=

if DOCUMENTATION
## DOCUMENTATION

info_TEXINFOS		+= \
			openss7.texi

openss7_TEXINFOS	= \
			bugs.texi \
			configure.texi \
			descrip.texi \
			kmod.texi \
			install.texi \
			news.texi \
			prerequisites.texi \
			releases.texi \
			rpm.texi \
			todo.texi \
			tree.texi \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/bsd.texi \
			$(top_srcdir)/scripts/texi/decmit.texi \
			$(top_srcdir)/scripts/texi/fdl12.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/fdl.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/gpl.texi \
			$(top_srcdir)/scripts/texi/hp.texi \
			$(top_srcdir)/scripts/texi/install.texi \
			$(top_srcdir)/scripts/texi/isode.texi \
			$(top_srcdir)/scripts/texi/lesser.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/mit.texi \
			$(top_srcdir)/scripts/texi/quick.texi \
			$(top_srcdir)/scripts/texi/sunrpc.texi \
			$(top_srcdir)/scripts/texi/testsuite.texi \
			$(top_srcdir)/scripts/texi/uidlpi.texi \
			$(top_srcdir)/scripts/texi/uinpi.texi \
			$(top_srcdir)/scripts/texi/ui.texi \
			$(top_srcdir)/scripts/texi/uitpi.texi \
			$(top_srcdir)/scripts/texi/uslbsd.texi \
			$(top_srcdir)/scripts/texi/compat.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/mail.texi \
			$(top_srcdir)/scripts/texi/versions.texi

if DEVELOPMENT
## DEVELOPMENT

info_TEXINFOS		+= \
			STREAMS.texi \
			STREAMS_FAQ.texi \
			SPG2.texi \
			SPG.texi \
			porting.texi \
			dlpi_porting.texi \
			libxnet.texi \
			libxnsl.texi \
			x25_porting.texi \
			x400p.texi

STREAMS_TEXINFOS	= \
			install.texi \
			releases.texi \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/quick.texi \
			$(top_srcdir)/scripts/texi/testsuite.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/mail.texi \
			$(top_srcdir)/scripts/texi/versions.texi

STREAMS_FAQ_TEXINFOS	= \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

SPG2_TEXINFOS		= \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

SPG_TEXINFOS		= \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

porting_TEXINFOS	= \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

libxnet_TEXINFOS	= \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

libxnsl_TEXINFOS	= \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

x25_porting_TEXINFOS	= \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/uidlpi.texi \
			$(top_srcdir)/scripts/texi/uinpi.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

x400p_TEXINFOS		= \
			$(top_srcdir)/scripts/texi/agpl3.texi \
			$(top_srcdir)/scripts/texi/fdl13.texi \
			$(top_srcdir)/scripts/texi/gpl3.texi \
			$(top_srcdir)/scripts/texi/lgpl3.texi \
			$(top_srcdir)/scripts/texi/funding.texi \
			$(top_srcdir)/scripts/texi/macros.texi \
			$(top_srcdir)/scripts/texi/versions.texi

if MAINTAINER_MODE
if AMDEP
openss7_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
STREAMS_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
STREAMS_FAQ_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
SPG2_TEXINFOS		+= $(top_builddir)/scripts/texi/args.texi
SPG_TEXINFOS		+= $(top_builddir)/scripts/texi/args.texi
porting_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
libxnet_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
libxnsl_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
x25_porting_TEXINFOS	+= $(top_builddir)/scripts/texi/args.texi
x400p_TEXINFOS		+= $(top_builddir)/scripts/texi/args.texi
endif
endif

EXTRA_info_TEXINFOS	= \
			$(top_builddir)/scripts/texi/args.texi \
			$(info_TEXINFOS) \
			$(openss7_TEXINFOS) \
			$(STREAMS_TEXINFOS) \
			$(STREAMS_FAQ_TEXINFOS) \
			$(SPG2_TEXINFOS) \
			$(SPG_TEXINFOS) \
			$(porting_TEXINFOS) \
			$(libxnet_TEXINFOS) \
			$(libxnsl_TEXINFOS) \
			$(x25_porting_TEXINFOS) \
			$(x400p_TEXINFOS)
			
if PKG_BUILD_INDEP
## PKG_BUILD_INDEP

FIG_FIGS		= \
			SPG_fig01.fig \
			SPG_fig02.fig \
			SPG_fig03.fig \
			SPG_fig04.fig \
			SPG_fig05.fig \
			SPG_fig06.fig \
			SPG_fig07.fig \
			SPG_fig08.fig \
			SPG_fig09.fig \
			SPG_fig10.fig \
			SPG_fig11.fig \
			SPG_fig12.fig \
			SPG_fig13.fig \
			SPG_fig14.fig \
			SPG_fig15b.fig \
			SPG_fig15.fig \
			SPG_fig16.fig \
			SPG_fig17.fig \
			SPG_fig18a.fig \
			SPG_fig18.fig \
			SPG_fig19.fig \
			SPG_fig20.fig \
			SPG_fig21.fig \
			SPG_fig22.fig \
			SPG_fig23.fig \
			SPG_fig24.fig \
			SPG_fig25.fig \
			SPG_fig26.fig \
			SPG_fig27.fig \
			SPG_fig28.fig \
			SPG_fig29.fig \
			SPG_fig30.fig \
			SPG_fig31.fig \
			SPG_fig32.fig \
			SPG_fig33.fig \
			SPG_fig34.fig \
			SPG_fig35.fig \
			SPG_fig36.fig \
			SPG_fig37.fig \
			SPG_fig38.fig \
			SPG_fig39.fig \
			SPG_fig40.fig \
			SPG_fig41.fig \
			SPG_fig42.fig \
			SPG_fig43.fig \
			SPG_fig44.fig \
			SPG_fig45.fig \
			SPG_fig46.fig \
			SPG_fig47.fig \
			SPG_fig48.fig \
			SPG_fig49.fig \
			SPG_fig50.fig \
			SPG_fig51.fig \
			SPG_fig52.fig \
			SPG_fig53.fig \
			SPG_fig54.fig \
			SPG_fig55.fig \
			SPG_fig56.fig

## PKG_BUILD_INDEP
endif

## DEVELOPMENT
endif

## DOCUMENTATION
endif

include ../../am/info.am

## =============================================================================
## vim: ft=automake comments=b\:#,b\:##,b\:#\! formatoptions+=tcqlor
