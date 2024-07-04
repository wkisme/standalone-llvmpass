#!/bin/bash

export PATH=$HOME/install/llvm/bin:$PATH
export LD_LIBRARY_PATH=$HOME/install/llvm/lib:$LD_LIBRARY_PATH
export C_INCLUDE_PATH=$HOME/install/llvm/include:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=$HOME/install/llvm/include:$CPLUS_INCLUDE_PATH

export LLVM_DIR=$HOME/install/llvm/lib/cmake/llvm
