#include "quickjs-libc.h"

typedef JSValue hostFunction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv);

__attribute__((import_module("env"), import_name("wasmHostFunction")))
JSValue wasmHostFunction(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv);

hostFunction* getWASMHostFunction() {
    return &wasmHostFunction;
}

int main(int argc, char **argv) {
  return 0;
}
