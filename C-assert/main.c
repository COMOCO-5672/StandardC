#define NDEBUG

#include <assert.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int val = 0;

static void field_abort(int sig) {
    if (val == 1) {
        puts("SUCCESS testing <assert.h>");
        exit(EXIT_SUCCESS);
    } else {
        puts("FAILURE testing <assert.h>");
        exit(EXIT_FAILURE);
    }
}

static void dummy() {
    int i = 0;
    assert(i == 0);
    assert(i == 1);
}

#undef NDEBUG

#include <assert.h>

int main() {

    assert(signal(SIGABRT, &field_abort) != SIG_ERR);
    dummy();
    assert(val == 0);
    ++val;
    fputs("Sample assertion failure --\n", stderr);
    assert(val == 0);
    puts("PAILURE testing <assert.h>");
    return (EXIT_FAILURE);
}

