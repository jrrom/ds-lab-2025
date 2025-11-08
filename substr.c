#include <stdio.h>
#include <stdlib.h>

char* insert_substring(char a[], char b[], int index) {
    char *c = (char *)malloc(sizeof(char) * 128);

    int i, j, k;
    for (i = 0, k = 0; a[i] != '\0'; i++, k++) {
        if (i == index) {
            for (j = 0; b[j] != '\0'; j++, k++) {
                c[k] = b[j];
            }
        }
        c[k] = a[i];
    }
    c[k] = '\0';

    return c;
}

int main() {
    char a[] = "Hello Wd";
    char b[] = "orl";

    char *c = insert_substring(a, b, 7);
    printf("%s\n", c);
}
