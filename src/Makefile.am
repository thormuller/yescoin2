AM_CPPFLAGS =  $(INCLUDES)
AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS)

if USE_LIBSECP256K1
secp256k1/libsecp256k1.la: $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	@$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)
endif

if EMBEDDED_LEVELDB
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/include
LEVELDB_CPPFLAGS += -I$(srcdir)/leveldb/helpers/memenv
LIBLEVELDB += $(builddir)/leveldb/libleveldb.a
LIBMEMENV  += $(builddir)/leveldb/libmemenv.a

# NOTE: This dependency is not strictly necessary, but without it make may try to build both in parallel, which breaks the LevelDB build system in a race
$(LIBLEVELDB): $(LIBMEMENV)

$(LIBLEVELDB) $(LIBMEMENV):
	@echo "Building LevelDB ..." && $(MAKE) -C $(@D) $(@F) CXX="$(CXX)" \
	  CC="$(CC)" PLATFORM=$(TARGET_OS) AR="$(AR)" $(LEVELDB_TARGET_FLAGS) \
          OPT="$(CXXFLAGS) $(CPPFLAGS)"
endif

YESCOIN_CONFIG_INCLUDES=-I$(builddir)/config
YESCOIN_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS)

if USE_LIBSECP256K1
YESCOIN_INCLUDES += -I$(srcdir)/secp256k1/include
endif

LIBYESCOIN_SERVER=libyescoin_server.a
LIBYESCOIN_WALLET=libyescoin_wallet.a
LIBYESCOIN_COMMON=libyescoin_common.a
LIBYESCOIN_CLI=libyescoin_cli.a
LIBYESCOIN_UTIL=libyescoin_util.a
LIBYESCOIN_CRYPTO=crypto/libyescoin_crypto.a
LIBYESCOINQT=qt/libyescoinqt.a

noinst_LIBRARIES = \
  libyescoin_server.a \
  libyescoin_common.a \
  libyescoin_cli.a \
  libyescoin_util.a \
  crypto/libyescoin_crypto.a
if ENABLE_WALLET
YESCOIN_INCLUDES += $(BDB_CPPFLAGS)
noinst_LIBRARIES += libyescoin_wallet.a
endif

bin_PROGRAMS =
TESTS =

if BUILD_YESCOIND
  bin_PROGRAMS += yescoind
endif

if BUILD_YESCOIN_CLI
  bin_PROGRAMS += yescoin-cli
endif

.PHONY: FORCE
# yescoin core #
YESCOIN_CORE_H = \
  addrman.h \
  alert.h \
  allocators.h \
  base58.h \
  bloom.h \
  chainparams.h \
  chainparamsbase.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  core.h \
  crypter.h \
  db.h \
  hash.h \
  init.h \
  key.h \
  keystore.h \
  leveldbwrapper.h \
  limitedmap.h \
  main.h \
  miner.h \
  mruset.h \
  netbase.h \
  net.h \
  noui.h \
  pow.h \
  protocol.h \
  rpcclient.h \
  rpcprotocol.h \
  rpcserver.h \
  script.h \
  serialize.h \
  sync.h \
  threadsafety.h \
  timedata.h \
  tinyformat.h \
  txdb.h \
  txmempool.h \
  ui_interface.h \
  uint256.h \
  util.h \
  version.h \
  walletdb.h \
  wallet.h \
  compat/sanity.h

JSON_H = \
  json/json_spirit.h \
  json/json_spirit_error_position.h \
  json/json_spirit_reader.h \
  json/json_spirit_reader_template.h \
  json/json_spirit_stream_reader.h \
  json/json_spirit_utils.h \
  json/json_spirit_value.h \
  json/json_spirit_writer.h \
  json/json_spirit_writer_template.h

obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
libyescoin_util_a-version.$(OBJEXT): obj/build.h

# server: shared between yescoind and yescoin-qt
libyescoin_server_a_CPPFLAGS = $(YESCOIN_INCLUDES)
libyescoin_server_a_SOURCES = \
  addrman.cpp \
  alert.cpp \
  bloom.cpp \
  checkpoints.cpp \
  init.cpp \
  leveldbwrapper.cpp \
  main.cpp \
  miner.cpp \
  net.cpp \
  noui.cpp \
  pow.cpp \
  rpcblockchain.cpp \
  rpcmining.cpp \
  rpcmisc.cpp \
  rpcnet.cpp \
  rpcrawtransaction.cpp \
  rpcserver.cpp \
  timedata.cpp \
  txdb.cpp \
  txmempool.cpp \
  $(JSON_H) \
  $(YESCOIN_CORE_H)

# wallet: shared between yescoind and yescoin-qt, but only linked
# when wallet enabled
libyescoin_wallet_a_CPPFLAGS = $(YESCOIN_INCLUDES)
libyescoin_wallet_a_SOURCES = \
  db.cpp \
  crypter.cpp \
  rpcdump.cpp \
  rpcwallet.cpp \
  wallet.cpp \
  walletdb.cpp \
  $(YESCOIN_CORE_H)

# crypto primitives library
crypto_libyescoin_crypto_a_CPPFLAGS = $(YESCOIN_CONFIG_INCLUDES)
crypto_libyescoin_crypto_a_SOURCES = \
  crypto/sha1.cpp \
  crypto/sha2.cpp \
  crypto/ripemd160.cpp \
  crypto/common.h \
  crypto/sha2.h \
  crypto/sha1.h \
  crypto/ripemd160.h

# common: shared between yescoind, and yescoin-qt and non-server tools
libyescoin_common_a_CPPFLAGS = $(YESCOIN_INCLUDES)
libyescoin_common_a_SOURCES = \
  allocators.cpp \
  base58.cpp \
  chainparams.cpp \
  coins.cpp \
  core.cpp \
  hash.cpp \
  key.cpp \
  keystore.cpp \
  netbase.cpp \
  protocol.cpp \
  script.cpp \
  $(YESCOIN_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
libyescoin_util_a_CPPFLAGS = $(YESCOIN_INCLUDES)
libyescoin_util_a_SOURCES = \
  chainparamsbase.cpp \
  rpcprotocol.cpp \
  sync.cpp \
  uint256.cpp \
  util.cpp \
  version.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  $(YESCOIN_CORE_H)

if GLIBC_BACK_COMPAT
libyescoin_util_a_SOURCES += compat/glibc_compat.cpp
libyescoin_util_a_SOURCES += compat/glibcxx_compat.cpp
endif

# cli: shared between yescoin-cli and yescoin-qt
libyescoin_cli_a_SOURCES = \
  rpcclient.cpp \
  $(YESCOIN_CORE_H)

nodist_libyescoin_util_a_SOURCES = $(srcdir)/obj/build.h
#

# yescoind binary #
yescoind_LDADD = \
  $(LIBYESCOIN_SERVER) \
  $(LIBYESCOIN_COMMON) \
  $(LIBYESCOIN_UTIL) \
  $(LIBYESCOIN_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBMEMENV)

if USE_LIBSECP256K1
  yescoind_LDADD += secp256k1/libsecp256k1.la
endif

if ENABLE_WALLET
yescoind_LDADD += libyescoin_wallet.a
endif
yescoind_SOURCES = yescoind.cpp
#

if TARGET_WINDOWS
yescoind_SOURCES += yescoind-res.rc
endif

yescoind_LDADD += $(BOOST_LIBS) $(BDB_LIBS)
yescoind_CPPFLAGS = $(YESCOIN_INCLUDES)

# yescoin-cli binary #
yescoin_cli_LDADD = \
  $(LIBYESCOIN_CLI) \
  $(LIBYESCOIN_COMMON) \
  $(LIBYESCOIN_UTIL) \
  $(LIBYESCOIN_CRYPTO) \
  $(BOOST_LIBS)
yescoin_cli_SOURCES = \
  yescoin-cli.cpp

if USE_LIBSECP256K1
  yescoin_cli_LDADD += secp256k1/libsecp256k1.la
endif
yescoin_cli_CPPFLAGS = $(YESCOIN_INCLUDES)
#

if TARGET_WINDOWS
yescoin_cli_SOURCES += yescoin-cli-res.rc
endif

CLEANFILES = leveldb/libleveldb.a leveldb/libmemenv.a *.gcda *.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb secp256k1

clean-local:
	-$(MAKE) -C leveldb clean
	-$(MAKE) -C secp256k1 clean
	rm -f leveldb/*/*.gcno leveldb/helpers/memenv/*.gcno
	-rm -f config.h

.rc.o:
	@test -f $(WINDRES)
	$(AM_V_GEN) $(WINDRES) -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(CXXFLAGS)  -c -o $@ $<

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
