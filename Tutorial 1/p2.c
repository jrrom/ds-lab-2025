#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[24];
    int freq;
} Entry;

char *read_file(const char *fname, size_t *len_out) {
    FILE *f = fopen(fname, "rb");
    if (!f) {
        printf("Could not open file %s\n", fname);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);

    char *buf = malloc(len + 1);
    if (!buf) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    fread(buf, 1, len, f);
    buf[len] = '\0';
    fclose(f);

    if (len_out) *len_out = len;
    return buf;
}

void lowercase(char *s) {
    while (*s) {
        if (*s >= 'A' && *s <= 'Z')
            *s += 32; // shift to lowercase
        s++;
    }
}

void add_word(Entry *arr, int *count, const char *w) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(arr[i].word, w) == 0) {
            arr[i].freq++;
            return;
        }
    }
    strncpy(arr[*count].word, w, sizeof(arr[0].word) - 1);
    arr[*count].word[sizeof(arr[0].word) - 1] = '\0';
    arr[*count].freq = 1;
    (*count)++;
}

void selection_sort(Entry *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].freq > arr[max_idx].freq) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            Entry temp = arr[i];
            arr[i] = arr[max_idx];
            arr[max_idx] = temp;
        }
    }
}

int main() {
    char filename[100];
    int k;

    printf("Enter file name: ");
    scanf("%99s", filename);
    printf("Enter number of top words to display: ");
    scanf("%d", &k);

    size_t len;
    char *buffer = read_file(filename, &len);
    lowercase(buffer);

    Entry entries[10000];
    int count = 0;
    int total_words = 0;

    char *p = buffer;
    while (*p) {
        // skip non-letter characters
        while (*p && !isalpha((unsigned char)*p)) p++;
        if (!*p) break;

        char word[24];
        int wlen = 0;
        while (*p && isalpha((unsigned char)*p) && wlen < 23) {
            word[wlen++] = *p++;
        }
        word[wlen] = '\0';

        if (wlen > 0) {
            add_word(entries, &count, word);
            total_words++;
        }
    }

    selection_sort(entries, count);

    printf("\nTop %d words:\n", k);
    for (int i = 0; i < k && i < count; i++) {
        double pct = 100.0 * entries[i].freq / total_words;
        printf("%-20s %5d  %6.2f%%\n", entries[i].word, entries[i].freq, pct);
    }

    free(buffer);
    return 0;
}

