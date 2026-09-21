#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    int mid;

    if (low > high)
        return -1;

    mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[100];
    int n, i, key, result;
    char ch;

    do
    {
        printf("   RECURSIVE BINARY SEARCH\n");
       

        printf("Enter number of elements: ");
        scanf("%d", &n);

        printf("Enter %d sorted elements:\n", n);

        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Enter element to search: ");
        scanf("%d", &key);

        result = binarySearch(arr, 0, n - 1, key);

        if (result == -1)
        {
            printf("Element %d is not found in the array.\n", key);
        }
        else
        {
            printf("Element %d is found at index %d.\n", key, result);
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("\nProgram ended.\n");

    return 0;
}