#include <stdio.h>
#include <stdlib.h>

#include "descent.h"
#include "auxiliary.h"

int main(int argc, const char **argv) {

    const char *input_filename = get_input_file(argc, argv);

    char *input = get_input(input_filename);

    int val = descent(input);

    printf("%d\n", val);

    free(input);

    return 0;
}