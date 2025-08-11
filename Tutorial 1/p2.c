#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char word[24];
    int freq;
} Entry;

Entry entries[1000];
int entriesSize = 0;

int main() {
    // Getting the size of the file
    char fname[] = "C:\\Users\\MAHE\\Desktop\\Jerome\\Tutorial1\\test.txt";
    FILE *file = fopen(fname, "rb");
    if (file == NULL) {
        printf("The given file could not be found!\n");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    
    // =======
    // Buffer!
    // =======
    char* buffer = (char*)malloc(size + 1);
    int buf_size = 0;
    // =======

    // Assigning chars
    fseek(file, 0, SEEK_SET);
    char c;
    while ((c = getc(file)) != EOF) {
        if (c >= 'a' && c <= 'z')
            buffer[buf_size++] = c;
        else if (c == ' ' || c == '\n')
            buffer[buf_size++] = c;
        else if (c >= 'A' && c <= 'Z')
            buffer[buf_size++] = (char) (c + 32);
    }
    buffer[buf_size++] = '\0';

    printf("The read file is \n\n--- %s ---\n%s\n", fname, buffer);
    printf("---");

    // ==================
    free(buffer);
}
