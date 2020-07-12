## why

minimal [argument parsing](./example.c) shouldn't require a hundred lines of code.

## what

header only argument parsing for c inspired by the simplicity of [argh](https://pythonhosted.org/argh/).

## example

```c
#include "argh.h"

int main(int argc, char **argv) {
    if (strcmp(argv[argc - 1], "-h") == 0 || strcmp(argv[argc - 1], "--help") == 0) {
        fprintf(stderr, "usage: example [-l|--lz4] [-h N|--head N] [-p|--prefix] POS1 ... POSN\n");
        exit(1);
    }
    bool prefix = false;
    bool lz4 = false;
    int head = 0;
    ARGH_PARSE {
        ARGH_NEXT();
        if      ARGH_BOOL("-p", "--prefix") { prefix = true;}
        else if ARGH_BOOL("-l", "--lz4")    { lz4 = true; }
        else if ARGH_FLAG("-h", "--head")   { head = atol(ARGH_VAL()); }
    }
    printf("head: %d, prefix: %d, lz4: %d\n", head, prefix, lz4);
    for (int i = 0; i < ARGH_ARGC; i++)
        printf("pos arg %d: %s\n", i, ARGH_ARGV[i]);
}
```

```bash
>> make

>> ./example -lph5 asdf 123
head: 5, prefix: 1, lz4: 1
pos arg 0: asdf
pos arg 1: 123

>> ./example --lz4 asdf -p 123 --head 5
head: 5, prefix: 1, lz4: 1
pos arg 0: asdf
pos arg 1: 123


>> ./example asdf 123 --head 5 --lz4
head: 5, prefix: 0, lz4: 1
pos arg 0: asdf
pos arg 1: 123
```
