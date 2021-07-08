#pragma once
#include "v8.h"

namespace BytecodeCompiler 
{
    struct Bytecode
    {
        v8::ScriptCompiler::CachedData* bytecode;
        uint32_t version;

        Bytecode(v8::ScriptCompiler::CachedData* bytecode, uint32_t version) : bytecode(bytecode), version(version) {}
        ~Bytecode() { delete bytecode; }
    };

    extern uint32_t GetVersion();
    extern Bytecode* CompileSourceIntoBytecode(v8::Isolate* isolate, v8::ScriptOrigin& origin, const char* sourceCode);
}
