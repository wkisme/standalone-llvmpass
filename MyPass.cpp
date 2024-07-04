#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
using namespace llvm;

class MyPass : public PassInfoMixin<MyPass> {
public:
    PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
        errs() << "Hello from MyPass!\n";
        return PreservedAnalyses::all();
    }

    static bool isRequired() { return true; }
};

llvm::PassPluginLibraryInfo getMyPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "MyPass", LLVM_VERSION_STRING, [](PassBuilder &PB) {
        PB.registerPipelineParsingCallback(
            [](StringRef Name, ModulePassManager &MPM, ArrayRef<PassBuilder::PipelineElement>) {
                if (Name == "my-pass") {
                    MPM.addPass(MyPass());
                    return true;
                }
                return false;
            });
    }};
}

extern "C" LLVM_ATTRIBUTE_WEAK llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return getMyPassPluginInfo();
}

