#include <iostream>

int search_pattern(char* str, char* txt) {
    int pattern_length = std::strlen(str);
    int text_length = std::strlen(txt);
    
    for (int i = 0; i < text_length; i++) {
        int j = 0;
        for(j = 0; j < pattern_length; j++) {
            if((str[j]) != txt[i + j]) break;
        }
        if(j == pattern_length) return i;
    }
    return -1;
};

int main () {
    char text[] = "AABBAAABBABB";
    char pattern[] = "AB";

    std::cout << search_pattern(pattern, text);
    return 1;
};