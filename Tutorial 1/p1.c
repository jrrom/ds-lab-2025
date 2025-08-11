#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int severity;
    char arrival[6]; // HH:MM\0
} Patient;

Patient patients[100000];
int size = 0;

void display(int i) {
    printf("ID:\t%d\tSeverity:\t%d\tPosition:\t%d\tTime:\t%s\n",
           patients[i].id,
           patients[i].severity,
           i + 1,
           patients[i].arrival
          );
}

int binsearch(int i) {
    Patient new_patients[100000];
    memcpy(new_patients, patients, sizeof(int) * size);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (new_patients[i].id < new_patients[j].id) {
                Patient swap  = new_patients[j];
                new_patients[j] = new_patients[i];
                new_patients[i] = swap;
            }
        }
    }

    int low = 0;
    int high = size;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (new_patients[mid].id == i) return 1;

        if (new_patients[mid].id > i) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

void add() {
    int id;
    int severity;
    char arrival[6];
    printf("\nAdding:\n");
    printf("Enter id: ");
    scanf("%d", &id);
    printf("Enter severity: ");
    scanf("%d", &severity);
    printf("Enter arrival time: ");
    getchar();
    fgets(arrival, 6, stdin);

    patients[size].id = id;
    patients[size].severity = severity;
    strcpy(patients[size].arrival, arrival);

    size++;
    selection_sort();
}

void selection_sort() {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            // severity DESC
            if (patients[min].severity < patients[j].severity) {
                min = j;
                continue;
            }

            // arrival ASC
            if (patients[min].severity == patients[j].severity)
                if (strcmp(patients[min].arrival, patients[j].arrival) < 0)
                    min = j;
        }
        Patient swap = patients[i];
        patients[i] = patients[min];
        patients[min] = swap;
    }
}

void rank() {
    int nums;
    printf("\nTo rank: \n");
    printf("Enter number of rows: ");
    scanf("%d", &nums);

    if (nums > size + 1) {
        printf("Error: The number of rows exceeds size");
        return;
    }

    for (int i = 0; i < nums; i++) {
        display(i);
    }
}

void find() {
    int search;
    printf("\nTo find: \n");
    printf("Enter id to search: ");
    scanf("%d", &search);
    for (int i = 0; i < size; i++) {
        if (patients[i].id == search) {
            display(i);
            return;
        }
    }
    printf("Error: ID not found\n");
}

void update() {
    int search;
    printf("\nEnter id to update: \n");
    scanf("%d", &search);
    for (int i = 0; i < size; i++) {
        if (patients[i].id == search) {
            int severity;
            printf("Enter new severity: ");
            scanf("%d", &severity);
            patients[i].severity = severity;
            printf("\nUpdated:\n");
            display(i);
            printf("\n");
            return;
        }
    }
    printf("Error: ID not found\n");
}

void exists() {
    int exists;
    printf("\nEnter id to see if it exists: ");
    scanf("%d", &exists);
    if (binsearch(exists)) printf("It exists\n");
    else printf("It doesn't exist\n");
}

int main() {
    printf("Patient Management Menu\n");
    while(1) {
        printf("\n---\n");
        printf("\nChoose your option:\n");
        printf("Enter A to ADD\n");
        printf("Enter R to RANK\n");
        printf("Enter F to FIND\n");
        printf("Enter U to UPDATE\n");
        printf("Enter E to EXIST\n");
        printf("Enter Q to QUIT\n");
        printf("-> ");

        char in;
        scanf(" %c", &in);

        switch(in) {
            case 'A':
                add();
                break;
            case 'R':
                rank();
                break;
            case 'F':
                find();
                break;
            case 'U':
                update();
                break;
            case 'E':
                exists();
                break;
            default:
                return 0;
        }
    }
}
