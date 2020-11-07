#ifndef __CTL_H__
#define __CTL_H__

#include <stdlib.h>
#include <stdint.h>

#define CAT(a, b) a##b

#define PASTE(a, b) CAT(a, b)

#define TEMP(type, name) PASTE(PASTE(name, _), type)

#define IMPL(container, name) PASTE(container, PASTE(_, name))

#define iterate(iterator, ...)    \
    while(!iterator.done)         \
    {                             \
        __VA_ARGS__               \
        iterator.step(&iterator); \
    }                             \
(void) 0

#define foreach(container, variable, iterator, ...) {                         \
    IMPL(container, it) iterator = IMPL(IMPL(container, it), each)(variable); \
    iterate(iterator, __VA_ARGS__);                                           \
}                                                                             \
(void) 0

#define len(a) (sizeof(a) / sizeof(*(a)))

#endif
