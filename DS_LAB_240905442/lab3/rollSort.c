#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[500];
    int roll;
    char grade;
};

void readStud(struct student s[], int n)
{
    int i;
    printf("enter name, roll number, and grade for %d students\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].roll);
        scanf("%c", &s[i].grade);
    }
}

void display(struct student s[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("name: %s\nroll no: %d\ngrade: %c\n\n", s[i].name, s[i].roll, s[i].grade);
}

void sortStud(struct student s[], int n)
{
    int i, j, tempR;
    char tempN[500];
    char tempG;
    for(i=0 ; i<n-1 ; i++)
    {
        for(j=0 ; j<n-i-1 ; j++)
        {
            if(s[j].roll > s[j+1].roll)
            {
                tempR = s[j].roll;
                s[j].roll = s[j+1].roll;
                s[j+1].roll = tempR;

                strcpy(tempN, s[j].name);
                strcpy(s[j].name, s[j+1].name);
                strcpy(s[j+1].name, tempN);

                tempG = s[j].grade;
                s[j].grade = s[j+1].grade;
                s[j+1].grade = tempG;
            }
        }
    }
}

int main()
{
    int n;
    printf("enter total number of students\n");
    scanf("%d", &n);

    struct student students[n];

    readStud(students, n);
    printf("unsorted students:\n");
    display(students, n);
    sortStud(students, n);
    printf("sorted students:\n");
    display(students, n);
    return 0;
}