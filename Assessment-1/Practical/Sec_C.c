#include <stdio.h>

struct StudyLog
{
    char subject[40];
    float hours[7];
};

void report(struct StudyLog s[], int n)
{
    int i, j;
    float total, average;

    printf("\n========== WEEKLY REPORT ==========\n");

    for(i = 0; i < n; i++)
    {
        total = 0;

        printf("\nSubject : %s\n", s[i].subject);

        for(j = 0; j < 7; j++)
        {
            total += s[i].hours[j];
        }

        average = total / 7;

        printf("Total Hours : %.2f\n", total);
        printf("Average Hours : %.2f\n", average);

        printf("Progress Chart:\n");

        for(j = 0; j < 7; j++)
        {
            printf("Day %d : ", j + 1);

            for(int k = 0; k < (int)s[i].hours[j]; k++)
            {
                printf("*");
            }

            printf("\n");
        }
    }
}

void saveFile(struct StudyLog s[], int n)
{
    FILE *fp;

    fp = fopen("productivity_log.txt", "w");

    for(int i = 0; i < n; i++)
    {
        fprintf(fp,"%s", s[i].subject);

        for(int j = 0; j < 7; j++)
        {
            fprintf(fp,",%.2f", s[i].hours[j]);
        }

        fprintf(fp,"\n");
    }

    fclose(fp);

    printf("\nData Saved Successfully in productivity_log.txt\n");
}

int main()
{
    struct StudyLog s[3] =
    {
        {"Python",{0,0,0,0,0,0,0}},
        {"HTML",{0,0,0,0,0,0,0}},
        {"C Programming",{0,0,0,0,0,0,0}}
    };

    int choice;
    int day;
    int i;

    while(1)
    {
        printf("\n===== Student Productivity Tracker =====");
        printf("\n1. Log Today's Study Hours");
        printf("\n2. View Weekly Report");
        printf("\n3. Save & Exit");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter Day (1-7): ");
            scanf("%d",&day);

            if(day<1 || day>7)
            {
                printf("Invalid Day!");
                continue;
            }

            for(i=0;i<3;i++)
            {
                printf("Enter %s Study Hours : ",s[i].subject);
                scanf("%f",&s[i].hours[day-1]);
            }
        }
        else if(choice==2)
        {
            report(s,3);
        }
        else if(choice==3)
        {
            saveFile(s,3);
            printf("Thank You!\n");
            break;
        }
        else
        {
            printf("Invalid Choice!");
        }
    }

    return 0;
}