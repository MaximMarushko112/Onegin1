#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

size_t my_qsort(char* arr[], size_t left, size_t right,
                int (*comp)(const char*, const char*));

void swap(char* arr[], size_t left, size_t right);

size_t partition(char* arr[], size_t left, size_t right,
                 int (*comp)(const char*, const char*));

int str_compare_lr(const char* str1, const char* str2);

int str_compare_rl(const char* str1, const char* str2);

#endif // QSORT_H_INCLUDED
