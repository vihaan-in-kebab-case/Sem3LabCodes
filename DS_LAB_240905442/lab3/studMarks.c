#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name[50];
    int roll_no;
    float marks;
} student;

void readDetails(student* s, int n)
{
    int i;
    printf("enter name, roll number, and marks for %d students\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", s -> name);
        scanf("%d", &s -> roll_no);
        scanf("%f", &s -> marks);
        s++;
    }
}

void displayDetails(student* s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("name: %s\nroll no: %d\nmarks: %f\n\n", s->name, s->roll_no, s->marks);
        s++;
    }
}

student* findTopper(student* s, int n)
{
    student* max = s;
    int i;
    for(i=0 ; i < n ; i++)
    {
        if(max->marks < s->marks)
            max = s;
        s++;
    }
    return max;
}

int main()
{
    int n;
    printf("enter total number of students\n");
    scanf("%d", &n);
    student students[n];

    readDetails(&students[0], n);
    displayDetails(&students[0], n);
    student* topper = findTopper(&students[0], n);
    printf("student with highest marks:\nname: %s\nroll no: %d\nmarks: %f\n", topper->name, topper-> roll_no, topper -> marks);
    return 0;
}