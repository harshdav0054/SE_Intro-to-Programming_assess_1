#include <stdio.h>

int main()
{
    int arr[10];
    int i, j;
    int max, min;
    int sum = 0;
    float mean;

    printf("Enter 10 integers:\n");

    // Input
    for(i = 0; i < 10; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Find minimum, maximum and sum
    max = min = arr[0];

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
                int temp = arr[j];
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

    // Compare mean
    if((mean - min) == (max - mean))
    {
        printf("\n\nMean is exactly midway between minimum and maximum.");
    }
    else if((mean - min) < (max - mean))
    {
        printf("\n\nMean is closer to the minimum value.");
    }
    else
    {
        printf("\n\nMean is closer to the maximum value.");
    }

    return 0;
}