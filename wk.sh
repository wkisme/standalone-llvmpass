#!/bin/bash

clang -emit-llvm -c flavor.c
opt -load-pass-plugin=./libMyPass.so -passes=my-pass  -S flavor.bc -o output
