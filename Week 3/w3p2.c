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

// Enter number of students to enter: 3

// Enter details:
// Enter roll no: 1
// Enter name: Name1
// Enter grade: A

// Enter roll no: 2
// Enter name: Name2
// Enter grade: C

// Enter roll no: 3
// Enter name: Name3
// Enter grade: B

// Roll:   1
// Name:   Name1
// Grade:  A

// Roll:   2
// Name:   Name2
// Grade:  C

// Roll:   3
// Name:   Name3
// Grade:  B
