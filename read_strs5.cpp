#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys\stat.h>

#include "read_strs5.h"

size_t file_len(FILE* read) {
    struct stat file_info = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    fstat(fileno(read), &file_info);
    return file_info.st_size;
}

size_t str_num(const char* text) {
    size_t i = 0, str_num = 1;
    while(text[i] != '\0') {
        if (text[i] == '\n')
            str_num++;
        i++;
    }
    return str_num;
}

size_t alpha_count(const char* str) {
    size_t i = 0, res = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i]))
            res++;
        i++;
    }
    return res;
}

void read_strings(char** strings, char* text) {
    strings[0] = text;
    size_t i = 0, str_num = 1;
    while (text[i] != '\0') {
        if (text[i] == '\n') {
            text[i] = '\0';
            strings[str_num] = text + i + 1;
            str_num++;
        }
        i++;
    }
}

void print_strings(char** strings, size_t str_num, const char* filename) {
    FILE* res = fopen(filename, "w");
    if (res == nullptr) {
        printf("ERROR!");
    }
    for (size_t i = 0; i < str_num; i++) {
        if (alpha_count(strings[i]) == 0)
            continue;
        fprintf(res, "%s\n", strings[i]);
    }
    fclose(res);
}

void clear_strings(char** strings, size_t str_num) {
    for (size_t i = 0; i < str_num; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }
    free(strings);
}
