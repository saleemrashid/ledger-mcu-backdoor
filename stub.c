#include "util.h"

#define GENERATE_FUNCTION(NAME, ADDRESS, REPLACEMENT, SIZE) \
    void __attribute__((naked)) SECTION(stub, NAME) _stub_##NAME(void) { \
        __asm__ volatile ("push {r4, lr}"); \
        __asm__ volatile ("bl _real_" #NAME); \
        __asm__ volatile ("pop  {r4, pc}"); \
    }

#define GENERATE_BRANCH(NAME, ADDRESS, ...) \
    void __attribute__((naked)) SECTION(branch, NAME) _branch_##NAME(void) { \
        __asm__ volatile ("bl _wrap_" #NAME); \
    }

#define GENERATE_NOOP(NAME, ADDRESS, REPLACEMENT) \
    void __attribute__((naked)) SECTION(noop, NAME) __noop_##NAME(void) { \
        __asm__ volatile ("nop"); \
    }

SYMBOL_TABLE

#undef GENERATE_FUNCTION
#undef GENERATE_BRANCH
#undef GENERATE_NOOP
