#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int student_id;
    char* first_name;
    char* last_name;
    float gpa;
    char* major;
} Student;

struct Node {
    Student* s;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;

void add_student() {
    Node* new     = (Node*)malloc(sizeof(Node));
    Student* s    = (Student*)malloc(sizeof(Student));
    s->first_name = (char *)malloc(sizeof(char) * 100);
    s->last_name  = (char *)malloc(sizeof(char) * 100);
    s->major      = (char *)malloc(sizeof(char) * 100);
    new->s        = s;
    new->next     = NULL;

    printf("Enter student id, first name, last name, gpa and major: ");
    scanf("%d", &new->s->student_id);
    scanf("%s", new->s->first_name);
    scanf("%s", new->s->last_name);
    scanf("%f", &new->s->gpa);
    scanf("%s", new->s->major);

    if (!head) {
        head = new;
        return;
    }

    Node* current;
    for (current = head; current->next; current = current->next);
    current->next = new;
}

void delete_student(int id) {
    if (head->s->student_id == id) {
        free(head);
        head = NULL;
        return;
    }
    
    Node *prev = head;

    for (Node *next = head->next; next; next = next->next, prev = next) {
        if (next->s->student_id == id) {
            Node *after = next->next;
            free(next);
            prev->next = after;
            return;
        }
    } 
}

void find_student_by_id(int id) {
    for (Node *current = head; current; current = current->next) {
        Student *s = current->s;
        if (s->student_id == id) {
            printf("%d\t%s\t%s\t%f\t%s\n",
                   s->student_id, s->first_name, s->last_name, s->gpa, s->major);
        }
    }
}

void print_all_students() {
    for (Node *current = head; current; current = current->next) {
        Student *s = current->s;
        printf("%d\t%s\t%s\t%f\t%s\n",
               s->student_id, s->first_name, s->last_name, s->gpa, s->major);
    }
}


float get_gpa_average() {
    float gpa = 0;
    int count = 0;
    for (Node *current = head; current; current = current->next) {
        gpa += current->s->gpa;
        count++;
    }
    return gpa / count;
}

int main() {
    printf("Enter 'a' to add student, 'd' to delete, 'f' to find, 'p' to print all students, 'g' for gpa\n");
    while (1) {
        char c;
        int id;
        scanf("%c", &c);
        switch (c) {
        case 'a':
            add_student();
            printf("\n");
            break;
        case 'd':
            printf("Enter id : ");
            scanf("%d", &id);
            delete_student(id);
            printf("\n");
            break;
        case 'f':
            printf("Enter id : ");
            scanf("%d", &id);
            find_student_by_id(id);
            printf("\n");
            break;
        case 'p':
            print_all_students();
            printf("\n");
            break;
        case 'g':
            printf("The average gpa is : %f\n\n", get_gpa_average());
            break;
        default:
            return 0;
        }
    }
}
