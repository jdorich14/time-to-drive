#!/bin/bash

EXTRA_DEPS=(cmake g++)

echo 'Installing dependencies...'

for dep in "${EXTRA_DEPS[@]}"
do
    sudo apt-get install $dep
done

# Make directories
mkdir -p test/lib
mkdir lib
mkdir include

# Google Test setup
git clone https://github.com/google/googletest.git test/googletest
make -C test/googletest/googletest/make gtest.a
cp test/googletest/googletest/make/gtest.a test/lib

# JsonCpp setup
git clone https://github.com/open-source-parsers/jsoncpp.git
mkdir jsoncpp/build
cd jsoncpp/build
cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=on -DBUILD_SHARED_LIBS=off -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ..
make
cd ../..
cp jsoncpp/build/src/lib_json/libjsoncpp.a lib
cp -r jsoncpp/include/json include
rm -rf jsoncpp
pwd
