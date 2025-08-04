#include <stdio.h>

int len(char str[]) {
    int count = 0;
    for (count = 0; str[count]; count++);
    return count;
}

void concat(char a[], char b[], char result[]) {
    int first = len(a);
    for (int i = 0; a[i]; i++) result[i] = a[i];
    for (int j = 0; b[j]; j++) result[first + j] = b[j];
}

int compare(char a[], char b[]) {
    for (int i = 0; a[i] && b[i]; i++) {
        int difference = (int)(a[i]) - (int)(b[i]);
        if (difference == 0) continue;
        else return difference;
    }
    return 0;
}

void insert_substring(char a[], int index, char sub[], char result[]) {
    int offset = 0;
    for (int i = 0; a[i]; i++) {
        if (i == index) {
            int j;
            for (j = 0; sub[j]; j++) result[i + j] = sub[j];
            offset += j;
        }

        result[i + offset] = a[i];
    }
}

void delete_substring(char a[], char sub[]) {
    int i = 0, j = 0, k;
    while (a[i]) {
        for (k = 0; sub[k] && a[i + k] == sub[k]; k++);

        if (sub[k] == '\0') {
            i += k;
        } else {
            a[j++] = a[i++];
        }
    }
    a[j] = '\0';
}

int main() {
    char str[]  = "Hello";
    char str2[] = " World World";
    // a) Getting length
    printf("Getting length:\n");
    printf("%d\n", len(str));
    // b) Concatenating
    printf("Showing concatenation:\n");
    char concatenated[len(str) + len(str2) + 2];
    concat(str, str2, concatenated);
    printf("%s\n", concatenated);
    // c) Comparison
    printf("Showing comparison:\n");
    char str3[] = "Hello";
    printf("%d\n", compare(str, str2));
    printf("%d\n", compare(str, str3));
    // d) Inserting substring
    printf("Showing substring insertion:\n");
    char inserted[100];
    insert_substring(str, 3, str3, inserted);
    printf("%s\n", inserted);
    // e) Deleting substring
    printf("Showing substring deletion:\n");
    delete_substring(str2, " Wor");
    printf("%s\n", str2);
}

// Getting length:
// 5
// Showing concatenation:
// Hello World World
// Showing comparison:
// 40
// 0
// Showing substring insertion:
// HelHellolo
// Showing substring deletion:
// ldld
