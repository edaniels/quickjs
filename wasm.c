#include "quickjs-libc.h"

int main(int argc, char **argv) {
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
