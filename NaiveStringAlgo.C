//Naive String Algorithm
#include <stdio.h>
#include <string.h>

void naiveStringMatch(char *text, char *pattern) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i;
    int j;
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern to search: ");
    gets(pattern);

    printf("Matching positions:\n");
    naiveStringMatch(text, pattern);

    return 0;
}

