//
// Created by Germain Jones on 23/08/2023.
//
#include "stdio.h"

char *test() {
    char string[] = "hello", *ptr = string;
    string[3] = 'z';
    return ptr;
}

int main() {
    printf("%s", test());
}