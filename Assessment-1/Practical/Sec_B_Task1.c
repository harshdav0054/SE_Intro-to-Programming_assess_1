#include <stdio.h>

void main()
{
    float percentage;

    printf("Enter Percentage: ");
    scanf("%f", &percentage);

    if (percentage < 0 || percentage > 100)
    {
        printf("Error! Please enter a percentage between 0 and 100.");
    }
    else if (percentage >= 90)
    {
        printf("Grade: A\n");
        printf("Excellent! Keep it up.");
    }
    else if (percentage >= 75)
    {
        printf("Grade: B\n");
        printf("Good Work! Keep pushing.");
    }
    else if (percentage >= 60)
    {
        printf("Grade: C\n");
        printf("Nice! You can do even better.");
    }
    else if (percentage >= 45)
    {
        printf("Grade: D\n");
        printf("Work harder next time.");
    }
    else
    {
        printf("Grade: F\n");
        printf("Don't give up. Practice more.");
    }

}