#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Qsort.h"

size_t my_qsort(char* arr[], size_t left, size_t right,
                int (*comp)(const char*, const char*)) {
    if (right - left == 0)
        return 1;
    if (right - left == 1) {
        if ((*comp)(arr[left], arr[right]) == 1)
            swap(arr, left, right);
        return 2;
    }
    size_t mid = 0;                                             // unite lines 19 and 20
    mid = partition(arr, left, right, comp);
    my_qsort(arr, left, mid, comp);
    my_qsort(arr, mid + 1, right, comp);
    return right - left + 1;
}

void swap(char* arr[], size_t left, size_t right) {
    char* temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

size_t partition(char* arr[], size_t left, size_t right,
                 int (*comp)(const char*, const char*)) {
    size_t mid = (left + right) / 2;                            // left + (right - left) / 2 to avoid overflow
    char* separator = arr[mid];                                 // why not just random element?
    while (left <= right) {
        while ((*comp)(arr[left], separator) == -1)
            left++;
        while ((*comp)(arr[right], separator) == 1)
            right--;
        if (left < right) {
            swap(arr, left, right);
            left++;
            right--;
        }
        else
            return right;
    }
    return right;
}

int str_compare_lr(const char* str1, const char* str2) {
    size_t ch1 = 0, ch2 = 0;            // if those are not chars, then index1 and index2?
    while (str1[ch1] != '\0' && str2[ch2] != '\0') {
        while (!isalpha(str1[ch1]))     // what if str1 like " "? str1[ch1] != '\0' when ch1 == 0, but then you'll go out of str bounds because isalpha('\0') == 0 
            ch1++;
        while (!isalpha(str2[ch2]))
            ch2++;
        if (str1[ch1] == '\0' || str2[ch2] == '\0')
            break;

        int alpha1 = 0, alpha2 = 0;
        if (isupper(str1[ch1]))         //
            alpha1 = str1[ch1] - 'A';   //
        else                            //
            alpha1 = str1[ch1] - 'a';   //
                                        //
        if (isupper(str2[ch2]))         //
            alpha2 = str2[ch2] - 'A';   //  instead of all this you could just compare toupper (or tolower) results
        else                            //
            alpha2 = str2[ch2] - 'a';   //
                                        //
        if (alpha1 > alpha2)            //
            return 1;                   //
        else if (alpha1 < alpha2)       //
            return -1;                  //
        else {
            ch1++;
            ch2++;
        }
    }
    if (str1[ch1] == '\0' && str2[ch2] == '\0')
        return 0;
    else if (str1[ch1] == '\0' && str2[ch2] != '\0')
        return -1;
    else
        return 1;
}

int str_compare_rl(const char* str1, const char* str2) {
    int ch1 = strlen(str1), ch2 = strlen(str2);             // strlen is compelled to go through all string length to compute, it is really slow;
                                                            // would be no need in this if you saved length of each string in struct 
    while (ch1 >= 0 && ch2 >= 0) {
        while (!isalpha(str1[ch1]) && ch1 >= 0)
            ch1--;
        while (!isalpha(str2[ch2]) && ch2 >= 0)
            ch2--;
        if (ch1 < 0 || ch2 < 0)
            break;

        int alpha1 = 0, alpha2 = 0;
        if (isupper(str1[ch1]))
            alpha1 = str1[ch1] - 'A';
        else
            alpha1 = str1[ch1] - 'a';

        if (isupper(str2[ch2]))
            alpha2 = str2[ch2] - 'A';
        else
            alpha2 = str2[ch2] - 'a';

        if (alpha1 > alpha2)
            return 1;
        else if (alpha1 < alpha2)
            return -1;
        else {
            ch1--;
            ch2--;
        }
    }
    if (ch1 < 0 && ch2 < 0)  
        return 0;
    else if (ch1 < 0 && ch2 >= 0)
        return -1;
    else
        return 1;
}
