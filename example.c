#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "argh.h"

#define USAGE "example [-l|--lz4] [-h N|--head N] [-p|--prefix] POS1 ... POSN"

int main(int argc, char **argv) {
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
        printf("positional arg %d: %s\n", i, ARGH_ARGV[i]);
}
