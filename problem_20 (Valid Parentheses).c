//
// Created by Germain Jones on 20/08/2023.
//
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
//#include <string.h

bool isValid(char *s) {
    char openers[strlen(s)];
    int openers_pointer = -1;
    for (int i = 0; i < strlen(s); ++i) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{':
                openers[++openers_pointer] = s[i];
                break;
            case ')':
                if (openers_pointer == -1 || openers[openers_pointer] != '(') { return false; }
                --openers_pointer;
                break;
            case ']':
                if (openers_pointer == -1 || openers[openers_pointer] != '[') { return false; }
                --openers_pointer;
                break;
            case '}':
                if (openers_pointer == -1 || openers[openers_pointer] != '{') { return false; }
                --openers_pointer;
                break;
        }
    }
    return (openers_pointer == -1);
}

int main() {
    if (isValid("()")) { printf("true\n"); } else { printf("false\n"); }
    return 0;
}
