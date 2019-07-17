SUBDIRS = .

AM_CPPFLAGS  = -I$(top_builddir)/src/lib -I$(top_srcdir)/src/lib
AM_CPPFLAGS += $(BOOST_INCLUDES)
AM_CXXFLAGS  = $(KEA_CXXFLAGS)

# Define rule to build logging source files from message file
free_subnet_cmds_messages.h free_subnet_cmds_messages.cc: s-messages
s-messages: free_subnet_cmds_messages.mes
	$(top_builddir)/src/lib/log/compiler/kea-msg-compiler $(top_srcdir)/src/hooks/dhcp/free_subnet_cmds/free_subnet_cmds_messages.mes
	touch $@

# Tell automake that the message files are built as part of the build process
# (so that they are built before the main library is built).
BUILT_SOURCES = free_subnet_cmds_messages.h free_subnet_cmds_messages.cc

# Ensure that the message file and doxygen file is included in the distribution
EXTRA_DIST = free_subnet_cmds_messages.mes

# Get rid of generated message files on a clean
CLEANFILES = *.gcno *.gcda free_subnet_cmds_messages.h free_subnet_cmds_messages.cc s-messages

# convenience archive

noinst_LTLIBRARIES = libfree_subnet_cmds.la

libfree_subnet_cmds_la_SOURCES  = free_subnet_cmds.cc free_subnet_cmds.h
libfree_subnet_cmds_la_SOURCES += free_subnet_cmds_callouts.cc
libfree_subnet_cmds_la_SOURCES += free_subnet_cmds_log.cc free_subnet_cmds_log.h
libfree_subnet_cmds_la_SOURCES += version.cc

nodist_libfree_subnet_cmds_la_SOURCES = free_subnet_cmds_messages.cc free_subnet_cmds_messages.h

libfree_subnet_cmds_la_CXXFLAGS = $(AM_CXXFLAGS)
libfree_subnet_cmds_la_CPPFLAGS = $(AM_CPPFLAGS)

# install the shared object into $(libdir)/hooks
lib_hooksdir = $(libdir)/hooks
lib_hooks_LTLIBRARIES = libdhcp_free_subnet_cmds.la

libdhcp_free_subnet_cmds_la_SOURCES  =
libdhcp_free_subnet_cmds_la_LDFLAGS  = $(AM_LDFLAGS)
libdhcp_free_subnet_cmds_la_LDFLAGS  += -avoid-version -export-dynamic -module
libdhcp_free_subnet_cmds_la_LIBADD  = libfree_subnet_cmds.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/dhcpsrv/libkea-dhcpsrv.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/process/libkea-process.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/config/libkea-cfgclient.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/cc/libkea-cc.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/hooks/libkea-hooks.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/asiolink/libkea-asiolink.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/dhcp/libkea-dhcp++.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/eval/libkea-eval.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/dhcp_ddns/libkea-dhcp_ddns.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/stats/libkea-stats.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/dns/libkea-dns++.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/cryptolink/libkea-cryptolink.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/log/libkea-log.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/util/threads/libkea-threads.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/util/libkea-util.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(top_builddir)/src/lib/exceptions/libkea-exceptions.la
libdhcp_free_subnet_cmds_la_LIBADD  += $(LOG4CPLUS_LIBS)
libdhcp_free_subnet_cmds_la_LIBADD  += $(CRYPTO_LIBS)
libdhcp_free_subnet_cmds_la_LIBADD  += $(BOOST_LIBS)
