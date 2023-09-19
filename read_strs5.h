#ifndef READ_STRS5_H_INCLUDED
#define READ_STRS5_H_INCLUDED

#include <stdio.h>

size_t file_len(FILE* read);

size_t str_num(const char* text);

size_t alpha_count(const char* str);

void read_strings(char** strings, char* text);

void print_strings(char** strings, size_t str_num, const char* filename);

void clear_strings(char** strings, size_t str_num);

#endif // READ_STRS5_H_INCLUDED
