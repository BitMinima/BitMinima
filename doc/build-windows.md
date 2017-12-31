How to build BitMinima Core for Windows (32bit).

1. Use Ubuntu 14.04.5-desktop-i386
http://releases.ubuntu.com/14.04/

2. 
apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils
apt-get install libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev
apt-get install software-properties-common
add-apt-repository ppa:bitcoin/bitcoin
apt-get update
apt-get install libdb4.8-dev libdb4.8++-dev
apt-get install libminiupnpc-dev
apt-get install libzmq3-dev
apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler
apt-get install libqt4-dev libprotobuf-dev protobuf-compiler
apt-get install libqrencode-dev
apt-get install libdb4.8 libdb4.8++
apt-get install g++-mingw-w64-i686 mingw-w64-i686-dev

cd depends
make HOST=i686-w64-mingw32
cd ..
./autogen.sh
./configure --prefix=`pwd`/depends/i686-w64-mingw32
make
make install

3. Check /depends/i686-w64-mingw32 and rename.

###############################################################################################################
BELOW FOR ORIGINAL BITCOIN   BELOW FOR ORIGINAL BITCOIN   BELOW FOR ORIGINAL BITCOIN   BELOW FOR ORIGINAL BITCOIN
###############################################################################################################

WINDOWS BUILD NOTES
====================

Some notes on how to build Bitcoin Core for Windows.

Most developers use cross-compilation from Ubuntu to build executables for
Windows. This is also used to build the release binaries.

Building on Windows itself is possible (for example using msys / mingw-w64),
but no one documented the steps to do this. If you are doing this, please contribute them.

Cross-compilation
-------------------

These steps can be performed on, for example, an Ubuntu VM. The depends system
will also work on other Linux distributions, however the commands for
installing the toolchain will be different.

First install the toolchains:

    sudo apt-get install g++-mingw-w64-i686 mingw-w64-i686-dev g++-mingw-w64-x86-64 mingw-w64-x86-64-dev

To build executables for Windows 32-bit:

    cd depends
    make HOST=i686-w64-mingw32 -j4
    cd ..
    ./configure --prefix=`pwd`/depends/i686-w64-mingw32
    make

To build executables for Windows 64-bit:

    cd depends
    make HOST=x86_64-w64-mingw32 -j4
    cd ..
    ./configure --prefix=`pwd`/depends/x86_64-w64-mingw32
    make

For further documentation on the depends system see [README.md](../depends/README.md) in the depends directory.

