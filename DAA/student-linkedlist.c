#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PStudent createStudent(char name[], int rollNo, int marks[]);

typedef struct _Student
{
    char name[30];
    int rollNo;
    int marks[5];
} Student, *PStudent;

typedef struct _Node
{
    PStudent student;
    struct _Node *next;
} Node, *PNode;

PStudent stdHead = NULL;

void main()
{
    int marks[] = {10, 20, 30, 40, 50};
    insertStudent("John", 1, marks);
    insertStudent("Doe", 2, marks);
    insertStudent("Jane", 3, marks);
    insertStudent("Doe", 4, marks);
    insertStudent("Jane", 5, marks);
    displayStudent();
    freeStudent();
}

PStudent createStudent(char name[], int rollNo, int marks[])
{
    PStudent student = (PStudent)malloc(sizeof(Student));

    strcpy(student->name, name);
    student->rollNo = rollNo;

    for (int i = 0; i < 5; i++)
        student->marks[i] = marks[i];

    return student;
}

void insertStudent(char name[], int rollNo, int marks[])
{
    PStudent student = createStudent(name, rollNo, marks);
    PNode node = (PNode)malloc(sizeof(Node));

    node->student = student;
    node->next = NULL;

    if (stdHead == NULL)
        stdHead = student;
    else
    {
        PNode temp = stdHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void displayStudent() {}

void freeStudent() {}