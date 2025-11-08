#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[100];
} Student;

Student* createStudent() {
    Student* s = (Student *)malloc(sizeof(Student));
    printf("Enter id: ");
    scanf("%d", &s->id);
    printf("Enter name: ");
    scanf("%s", s->name);

    return s;
}

void display(Student* s) {
    printf("ID: %d\tName: %s\n", s->id, s->name);
}

int main() {
    Student* s = createStudent();
    display(s);
}
