#include <stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s)
{
    if(s->marks >= 90)
        s->grade = 'A';
    else if(s->marks >= 75)
        s->grade = 'B';
    else if(s->marks >= 60)
        s->grade = 'C';
    else if(s->marks >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void printTopper(struct Student s[], int n)
{
    int top = 0;

    for(int i = 1; i < n; i++)
    {
        if(s[i].marks > s[top].marks)
        {
            top = i;
        }
    }

    printf("\nTopper: %s", s[top].name);
    printf("\nMarks: %.2f\n", s[top].marks);
}

int main()
{
    struct Student s[3];

    for(int i = 0; i < 3; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].rollno);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);

        assignGrade(&s[i]);
    }

    printf("\n--------------------------------------------");
    printf("\nName\tRoll\tMarks\tGrade");
    printf("\n--------------------------------------------");

    for(int i = 0; i < 3; i++)
    {
        printf("\n%s\t%d\t%.2f\t%c",
        s[i].name,
        s[i].rollno,
        s[i].marks,
        s[i].grade);
    }

    printf("\n--------------------------------------------");

    printTopper(s,3);

}