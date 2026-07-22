#include <stdio.h>

struct Expense
{
    char category[30];
    float amount;
};

void main()
{
    struct Expense e[10];
    int choice, count = 0;
    float total = 0;

    FILE *fp;

    while(1)
    {
        printf("\n1. Add Expense");
        printf("\n2. View Expenses");
        printf("\n3. Save & Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            if(count < 10)
            {
                printf("Enter Category: ");
                scanf("%s", e[count].category);

                printf("Enter Amount: ");
                scanf("%f", &e[count].amount);

                count++;
            }
            else
            {
                printf("Expense List Full!");
            }
        }
        else if(choice == 2)
        {
            total = 0;

            printf("\nCategory\tAmount\n");

            for(int i = 0; i < count; i++)
            {
                printf("%s\t\t%.2f\n",
                e[i].category,
                e[i].amount);

                total += e[i].amount;
            }

            printf("Total = %.2f\n", total);
        }
        else if(choice == 3)
        {
            fp = fopen("expenses.txt","w");

            for(int i = 0; i < count; i++)
            {
                fprintf(fp,"%s,%.2f\n",
                e[i].category,
                e[i].amount);
            }

            fclose(fp);

            printf("Data Saved Successfully!");
            break;
        }
        else
        {
            printf("Invalid Choice!");
        }
    }

}