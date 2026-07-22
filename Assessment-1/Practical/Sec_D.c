#include <stdio.h>

int main()
{
    int arr[10];
    int i, j, temp;
    int max, min;
    int sum = 0;
    float mean;
    float d1, d2;

    printf("Enter 10 integers:\n");

    // Input
    for(i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    max = min = arr[0];

    // Find max, min and sum
    for(i = 0; i < 10; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];

        sum += arr[i];
    }

    // Calculate mean
    mean = (float)sum / 10;

    // Bubble Sort
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display Results
    printf("\nMinimum Value = %d", min);
    printf("\nMaximum Value = %d", max);
    printf("\nMean = %.2f\n", mean);

    printf("\nSorted Array: ");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    // Improved comparison using absolute difference
    d1 = mean - min;
    d2 = max - mean;

    if(d1 < 0)
        d1 = -d1;

    if(d2 < 0)
        d2 = -d2;

    if(d1 == d2)
    {
        printf("\n\nMean is exactly midway between minimum and maximum.");
    }
    else if(d1 < d2)
    {
        printf("\n\nMean is closer to the minimum value.");
    }
    else
    {
        printf("\n\nMean is closer to the maximum value.");
    }

    return 0;
}