#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_strs5.h"
#include "Qsort.h"

int main() {
    FILE* read = fopen("Onegin.txt", "r");
    size_t len = file_len(read);
    char* text5 = (char*) calloc(len + 1, sizeof(char));
    fread(text5, sizeof(char), len, read);
    size_t num = str_num(text5);
    char** strings = (char**) calloc(num, sizeof(char*));
    read_strings(strings, text5);
    my_qsort(strings, 0, num - 1, str_compare_lr);
    print_strings(strings, num, "Onegin_lr.txt");
    my_qsort(strings, 0, num - 1, str_compare_rl);
    print_strings(strings, num, "Onegin_rl.txt");
    clear_strings(strings, num);
    fclose(read);
    read = nullptr;
    return 0;
}
