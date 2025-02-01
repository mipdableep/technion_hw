#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 1024

bool read_line(char *line, int length) {
    int i = 0;
    int ch;
    while (i < length - 1 && (ch = getchar()) != EOF && ch != '\n') {
        line[i++] = (char) ch;
    }
    line[i] = '\0';

    if (ch != '\n' && ch != EOF)
        return false;
    return true;
}

bool string_copy(char *target, int length, char *src) {
    int i;
    for (i = 0; i < length - 1; i++) {
        if (src[i] == '\0') {
            target[i] = '\0';
            return true;
        } else {
            target[i] = src[i];
        }
    }
    if (src[i] == '\0') {
        target[i] = '\0';
        return true;
    }
    target[length - 1] = '\0';
    return false;
}

int analyze_sentence_length(char *sentence) {
    int counter = 0;
    while (sentence[counter] != '\0') {
        counter++;
    }
    return counter;
}

int analyze_sentence_words(char *sentence) {
    int i = 0, word_counter = 0;
    bool in_white_space = true;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            in_white_space = true;
        } else {
            if (in_white_space) {
                word_counter++;
                in_white_space = false;
            }
        }
        i++;
    }
    return word_counter;
}

int analyze_sentence_vowels(char *sentence) {
    int i = 0, vowel_counter = 0;
    while (sentence[i] != '\0') {
        char c = sentence[i];
        // clang-format off
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            // clang-format on
            vowel_counter++;
        }
        i++;
    }
    return vowel_counter;
}

int analyze_sentence(char *sentence, char *operation) {
    if (strcmp(operation, "length") == 0) {
        return analyze_sentence_length(sentence);
    }
    if (strcmp(operation, "words") == 0) {
        return analyze_sentence_words(sentence);
    }
    if (strcmp(operation, "vowels") == 0) {
        return analyze_sentence_vowels(sentence);
    }
    return -1;
}

bool w_len_end(char *sentence, int start, int *end, int *len) {
    *len = 0;
    int i;
    for (i = start; sentence[i] != '\0' && sentence[i] != ' '; i++) {
        *end = i;
    }
    *len = i - start;
    if (sentence[i] == '\0') {
        return true;
    } else {
        return false;
    }
}

void copy_substring(char *target, char *src, int len) {
    for (int i = 0; i < len; i++) {
        target[i] = src[i];
    }
    target[len] = '\0';
}

void get_longest_word(char *sentence, char *word) {
    int longest_len = 0, i = 0;
    bool found = false, sentence_end = false;
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            int c_end = 0, c_len = 0;
            sentence_end = w_len_end(sentence, i, &c_end, &c_len);
            if (c_len > longest_len) {
                copy_substring(word, sentence + i, c_len);
                longest_len = c_len;
                found = true;
            }
            if (sentence_end)
                return;
            i = c_end;
        }
        i++;
    }
    if (!found) {
        word[0] = '\0';
    }
}

void get_shortest_word(char *sentence, char *word) {
    int shortest_len = MAX_STRING_LEN, i = 0;
    bool found = false, sentence_end = false;
    while (sentence[i] != '\0') {
        if (sentence[i] != ' ') {
            int c_end = 0, c_len = 0;
            sentence_end = w_len_end(sentence, i, &c_end, &c_len);
            if (c_len < shortest_len) {
                copy_substring(word, sentence + i, c_len);
                shortest_len = c_len;
                found = true;
            }
            if (sentence_end)
                return;
            i = c_end;
        }
        i++;
    }
    if (!found) {
        word[0] = '\0';
    }
}

void get_word(char *sentence, char *word, bool shortest) {
    if (shortest) {
        get_shortest_word(sentence, word);
    } else {
        get_longest_word(sentence, word);
    }
}

int main(void) {
    char line[MAX_STRING_LEN] = "";
    printf("Enter a string to be analyzed: ");
    if (read_line(line, sizeof(line)) == false) {
        return -1;
    }
    int line_length = analyze_sentence(line, "length");
    int num_words = analyze_sentence(line, "words");
    int num_vowels = analyze_sentence(line, "vowels");
    // clang-format off
    printf(
"The length of the sentence \"%s\" is %d.\nIt has %d words and %d vowels.\n",
           line, line_length, num_words, num_vowels);
    // clang-format on
    char longest_word[MAX_STRING_LEN], shortest_word[MAX_STRING_LEN];
    get_word(line, shortest_word, true);
    get_word(line, longest_word, false);
    printf("The longest word is \"%s\"\n", longest_word);
    printf("The shortest word is \"%s\"\n", shortest_word);
    return 0;
}
