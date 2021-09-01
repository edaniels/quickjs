#include "quickjs-libc.h"

static JSContext *JS_NewCustomContext(JSRuntime *rt)
{
  JSContext *ctx = JS_NewContextRaw(rt);
  if (!ctx)
    return NULL;
  JS_AddIntrinsicBaseObjects(ctx);
  return ctx;
}

int main(int argc, char **argv)
{
  JSRuntime *rt;
  JSContext *ctx;
  rt = JS_NewRuntime();
  js_std_set_worker_new_context_func(JS_NewCustomContext);
  js_std_init_handlers(rt);
  ctx = JS_NewCustomContext(rt);
  JS_FreeContext(ctx);
  JS_FreeRuntime(rt);
  return 0;
}

// TODO(erd): remove below
struct _thing {
    int a;
    int b;
};

struct _thing _returnThing() {
    struct _thing t;
    t.a = 2;
    t.b = 4;
    return t;
}

int _useThing(struct _thing t) {
    return t.a + t.b;
}
