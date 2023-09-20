#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_strs5.h"
#include "Qsort.h"

int main() {
    FILE* read = fopen("Onegin.txt", "r");                  // naming, read is unclear (not only here!); implement reading file name from command line/console
    size_t len = file_len(read);
    char* text5 = (char*) calloc(len + 1, sizeof(char));    // check if memory was not correctly allocated; fix naming   
    fread(text5, sizeof(char), len, read);                  // you open file in "r" mode; in Windows fread will read less than len symbols because of '\r';
                                                            // therefore it is obligatory to save fread result as quantity of symbols that have been read
    size_t num = str_num(text5);                            // make struct to have len, num, strings, text5 (fix naming) at one group and pass only pointer to struct
    char** strings = (char**) calloc(num, sizeof(char*));   // calloc result check
    read_strings(strings, text5);
    my_qsort(strings, 0, num - 1, str_compare_lr);
    print_strings(strings, num, "Onegin_lr.txt");
    my_qsort(strings, 0, num - 1, str_compare_rl);
    print_strings(strings, num, "Onegin_rl.txt");
    clear_strings(strings, num);
    fclose(read);
    read = nullptr;                                         // free(text5) should be whether here or in clear_strings, but done explicitly, not in a cycle
    return 0;
}
