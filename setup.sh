#!/bin/bash

EXTRA_DEPS=(cmake g++ libcurlpp-dev libcurl4-openssl-dev postgresql-9.4)

echo 'Installing dependencies...'

for dep in "${EXTRA_DEPS[@]}"
do
    sudo apt-get install $dep
done

# Make directories
mkdir -p test/include
mkdir -p test/lib
mkdir lib
mkdir include

# Google Test setup
git clone https://github.com/google/googletest.git test/googletest
make -C test/googletest/googletest/make gtest.a
cp test/googletest/googletest/make/gtest.a test/lib/libgtest.a
cp -r test/googletest/googletest/include/gtest test/include
rm -rf test/googletest

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
