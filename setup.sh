#!/bin/bash

EXTRA_DEPS=(cmake g++)

echo 'Installing dependencies...'

for dep in "${EXTRA_DEPS[@]}"
do
    sudo apt-get install $dep
done

mkdir libs
git clone https://github.com/google/googletest.git libs/googletest
make -C libs/googletest/googletest/make gtest.a
cp libs/googletest/googletest/make/gtest.a libs
