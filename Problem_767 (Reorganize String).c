//
// Created by Germain Jones on 23/08/2023.
//

#define LOWERCASE_A_IN_ASCII 97

#include "stdio.h"

struct character {
    int frequency;
    char cha;
};

struct character characters[26];

void fillStructCharacters() {
    for (int i = 0; i < 26; ++i) {
        characters[i].frequency = 0;
        characters[i].cha = LOWERCASE_A_IN_ASCII + i;
    }
}

int findMaxFrequencyWithExclusion(int excluded_index) {
    int max_index = excluded_index == 0 ? 1 : 0;
    for (int i = 0; i < 26; ++i) {
        if (i == excluded_index) { continue; }
        if (characters[max_index].frequency < characters[i].frequency) { max_index = i; }
    }
    return max_index;
}

// I know this is bad practise to combine, but it's faster and that's the goal on leetcode.
int findLengthOfStringAndCountCharFrequency(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        characters[s[i] - LOWERCASE_A_IN_ASCII].frequency++;
        i++;
    }
    return i;
}

char *reorganizeString(char *s) {
    fillStructCharacters();
    int s_len = findLengthOfStringAndCountCharFrequency(s);
    char new_string[s_len+1], *new_string_ptr = new_string;
    int previous_index = -1;
    int max_index;
    char str[] = *s;
    for (int i = 0; i < s_len; ++i) {
        max_index = findMaxFrequencyWithExclusion(previous_index);
        if (0 < characters[max_index].frequency) {
            str->i = characters[max_index].cha;
            characters[max_index].frequency--;
        } else {
            return "fuck";
        }
    }
    new_string[s_len+1] = '\0';
    return new_string_ptr;
}


int main() {
    char * string = reorganizeString("a");
    printf("%s", string);
    return 0;
}
