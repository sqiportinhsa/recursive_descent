#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#include "descent.h"

#define WARNING(checkup, message, ...)                     \
        if (!(checkup)) {                                  \
            printf("Error: " message, ##__VA_ARGS__);      \
            fflush(stdout);                                \
            abort();                                       \
        }

int descent(const char *pointer) {

    assert(pointer != nullptr);

    int val = get_add_sub(&pointer);

    WARNING(*pointer == '\0', "unexpected symbol: <%c>\n", *pointer);

    return val;
}

int get_value(const char **pointer) {

    assert(pointer != nullptr);

    int val = 0;

    const char *pointer_before = *pointer;

    while (isdigit(**pointer)) {

        val = (val * 10) + **pointer - '0';

        ++(*pointer);
    }

    WARNING(pointer_before != *pointer, "incorrect value. Digit expected. Got: <%c>\n", **pointer);

    return val;
}

int get_add_sub(const char **pointer) {

    assert(pointer != nullptr);

    int val = get_mul_and_div(pointer);

    while (**pointer == '+' || **pointer == '-') {

        char op = **pointer;

        ++(*pointer);

        int val2 = get_mul_and_div(pointer);

        if (op == '+') {

            val += val2;

        } else {

            val -= val2;

        }
    }

    return val;
}

int get_mul_and_div(const char **pointer) {

    assert(pointer != nullptr);

    int val = get_from_brackets(pointer);

    while (**pointer == '*' || **pointer == '/') {

        char op = **pointer;

        ++(*pointer);

        int val2 = get_from_brackets(pointer);

        if (op == '*') {

            val *= val2;

        } else {

            val /= val2;

        }
    }

    return val;
}

int get_from_brackets(const char **pointer) {

    assert(pointer != nullptr);

    int val = 0;

    if (**pointer == '(') {

        ++(*pointer);

        val = get_add_sub(pointer);

        WARNING(**pointer == ')', "close bracket ')' expected\n");

        ++(*pointer);

    } else {

        val = get_value(pointer);
    }

    return val;
}

#undef WARNING
