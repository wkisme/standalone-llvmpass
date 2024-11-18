Need to build llvm with shared library:  
    X86
        cmake  -DBUILD_SHARED_LIBS=ON -DLLVM_TARGETS_TO_BUILD=X86  -DLLVM_ENABLE_PROJECTS=clang -DLLVM_ENABLE_RUNTIMES=compiler-rt -DCMAKE_INSTALL_PREFIX=~/install/llvm2 -DCMAKE_BUILD_TYPE=Release  -G Ninja ../llvm
    AARCH64
        cmake  -DBUILD_SHARED_LIBS=ON -DLLVM_TARGETS_TO_BUILD=AArch64  -DLLVM_ENABLE_PROJECTS=clang -DLLVM_ENABLE_RUNTIMES=compiler-rt -DCMAKE_INSTALL_PREFIX=~/install-aarch64/llvm -DCMAKE_BUILD_TYPE=Release  -G Ninja ../llvm
