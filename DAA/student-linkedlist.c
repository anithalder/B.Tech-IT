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

PStudent stdHead = NULL;

void main()
{
}

PStudent createStudent(char name[], int rollNo, int marks[])
{
    PStudent newStudent = (PStudent)malloc(sizeof(Student));
    int size = sizeof(marks) / sizeof(marks[0]);

    if (!newStudent)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(newStudent->name, name);
    newStudent->rollNo = rollNo;

    for (int i = 0; i < size; i++)
        newStudent->marks[i] = marks[i];

    return newStudent;
}

void insertStudent(char name[], int rollNo, int marks[])
{
    PStudent temp = stdHead;
    if (!stdHead)
        stdHead = createStudent(name, rollNo, marks);
    else
    {
        // while (temp != NULL)
        //     temp
    }
}

void displayStudent() {}

void freeStudent() {}