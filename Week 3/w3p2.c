#include <stdio.h>

typedef struct Student {
    int roll_no;
    char name[50];
    char grade;
} Student;

void read_students(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        Student* current = &students[i];
        printf("Enter roll no: ");
        scanf("%d", &current->roll_no);
        printf("Enter name: ");
        getchar();
        scanf("%s", &current->name);
        printf("Enter grade: ");
        getchar();
        scanf("%c", &current->grade);
        printf("\n");
    }
}

void display_students(Student students[], int size) {
    for (int i = 0; i < size; i++) {
        Student current = students[i];
        printf("Roll:\t%d\n", current.roll_no);
        printf("Name:\t%s\n", current.name);
        printf("Grade:\t%c\n", current.grade);
        printf("\n");
    }
}

void sort_students(Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j - 1].roll_no > students[j].roll_no) {
                Student swap = students[j - 1];
                students[j - 1] = students[j];
                students[j] = swap;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students to enter: ");
    scanf("%d", &n);

    printf("\nEnter details:\n");
    Student students[n];

    read_students(students, n);

    sort_students(students, n);

    display_students(students, n);
}
