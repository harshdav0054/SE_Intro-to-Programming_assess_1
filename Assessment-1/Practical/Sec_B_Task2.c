#include <stdio.h>

void main()
{
    float hours[7];
    float total = 0, average;
    int i, maxDay = 0;

    for(i = 0; i < 7; i++)
    {
        do
        {
            printf("Enter study hours for Day %d: ", i + 1);
            scanf("%f", &hours[i]);

            if(hours[i] < 0 || hours[i] > 24)
            {
                printf("Invalid! Enter between 0 and 24.\n");
            }

        } while(hours[i] < 0 || hours[i] > 24);

        total += hours[i];

        if(hours[i] > hours[maxDay])
        {
            maxDay = i;
        }
    }

    average = total / 7;

    printf("\nTotal Hours = %.2f", total);
    printf("\nAverage Hours = %.2f", average);
    printf("\nHighest Study Day = Day %d", maxDay + 1);

    printf("\n\nStudy Chart\n");

    for(i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);

        for(int j = 0; j < (int)hours[i]; j++)
        {
            printf("*");
        }

        printf("\n");
    }

}