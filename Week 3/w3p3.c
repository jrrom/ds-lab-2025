#include <stdio.h>

typedef struct Student {
    int roll_no;
    char name[50];
    float marks
} Student;

void read_student(Student* current) {
    printf("Enter roll no: ");
    scanf("%d", &current->roll_no);
    printf("Enter name: ");
    getchar();
    scanf("%s", &current->name);
    printf("Enter marks: ");
    getchar();
    scanf("%f", &current->marks);
    printf("\n");
}

void display_student(Student current) {
    printf("Roll:\t%d\n", current.roll_no);
    printf("Name:\t%s\n", current.name);
    printf("Grade:\t%f\n", current.marks);
    printf("\n");
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

    for (int i = 0; i < n; i++) {
        read_student(&students[i]);
    }

    sort_students(students, n);

    Student max = students[0];
    for (int i = 0; i < n; i++) {
        if (students[i].marks > max.marks) max = students[i];
    }

    printf("Details of student with the most marks: \n");
    display_student(max);
}

// Enter number of students to enter: 3

// Enter details:
// Enter roll no: 1
// Enter name: Name1
// Enter marks: 50

// Enter roll no: 2
// Enter name: Name2
// Enter marks: 90

// Enter roll no: 3
// Enter name: Name3
// Enter marks: 60

// Details of student with the most marks:
// Roll:   2
// Name:   Name2
// Grade:  90.000000
