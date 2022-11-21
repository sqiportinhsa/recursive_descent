#include <stdlib.h>

#include "auxiliary.h"

#include "Libs/file_reading.h"

const char *get_input_file(int argc, const char **argv) {
    CLArgs args = parse_cmd_line(argc, argv);

    if (args.output != nullptr) {
        printf("Warning: unexpected -o flag");
    }

    return args.input;
}

char *get_input(const char *input_file) {
    
    size_t amount_of_symbols = count_elements_in_file(input_file);

    char *input = (char*) calloc(amount_of_symbols, sizeof(char));

    amount_of_symbols = read_file(input, amount_of_symbols, input_file);

    return input;
}
