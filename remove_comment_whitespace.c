#include <stdio.h>
#include <stdbool.h>

// Function to remove comments from a C program
void removeComments(char* prgm) {
    bool s_cmt = false; // Flag for single-line comment
    bool m_cmt = false; // Flag for multiline comment
    int i = 0; // Index for traversing the input program
    int line_number = 1; // Track line numbers

    while (prgm[i] != '\0') {
        if (s_cmt && prgm[i] == '\n') {
            s_cmt = false;
            putchar(prgm[i]); // Print newline character
            line_number++;
        } else if (m_cmt && prgm[i] == '*' && prgm[i + 1] == '/') {
            m_cmt = false, i++;
        } else if (s_cmt || m_cmt) {
            // Skip characters inside comments
        } else if (prgm[i] == '/' && prgm[i + 1] == '/') {
            s_cmt = true, i++;
        } else if (prgm[i] == '/' && prgm[i + 1] == '*') {
            m_cmt = true, i++;
        } else {
            putchar(prgm[i]);
        }
        i++;
    }
}

// Function to remove spaces from a string in-place
void removeSpaces(char* s) {
    char* d = s; // Destination pointer
    while (*s) {
        if (*s != ' ' || (*(s + 1) != ' ' && *(s + 1) != '\n'))
            *d++ = *s; // Copy non-space characters
        s++;
    }
    *d = '\0'; // Null-terminate the modified string
}

int main() {
    // Read the input C file
    FILE* file = fopen("insert_sort.c", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    char prgm[10000]; // Adjust the buffer size as needed
    int c;
    int i = 0;
    while ((c = fgetc(file)) != EOF) {
        prgm[i++] = c;
    }
    prgm[i] = '\0';
    fclose(file);

    printf("Original program:\n");
    printf("%s\n", prgm);

    printf("\nModified Program (without comments and extra spaces):\n");
    // Remove whitespaces
    removeSpaces(prgm);

    // Remove comments
    removeComments(prgm);

    return 0;
}