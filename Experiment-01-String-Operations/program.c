#include <stdio.h>

/* Find length of string */
int length(char str[])
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

/* a. Find substring */
void substring(char str[], int position, int n)
{
    int i;

    printf("Substring: ");

    for (i = 0; i < n && str[position + i] != '\0'; i++)
        printf("%c", str[position + i]);

    printf("\n");
}

/* b. Check palindrome */
void palindrome(char str[])
{
    int i = 0;
    int j = length(str) - 1;
    int flag = 0;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            flag = 1;
            break;
        }

        i++;
        j--;
    }

    if (flag == 0)
        printf("String is palindrome\n");
    else
        printf("String is not palindrome\n");
}

/* c. Compare two strings */
void compare(char str1[], char str2[])
{
    int i = 0;
    int flag = 0;

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            flag = 1;
            break;
        }

        i++;
    }

    if (flag == 0)
        printf("Strings are matching\n");
    else
        printf("Strings are not matching\n");
}

/* d. Copy one string into another */
void copy(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }

    str2[i] = '\0';
}

/* e. Reverse a string */
void reverse(char str[])
{
    int i = 0;
    int j = length(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    char str1[100], str2[100], str3[100];
    int choice;
    int position, n;
    char ch;

    do
    {
        printf("\n-----------------------------\n");
        printf("     STRING OPERATIONS\n");
        printf("-----------------------------\n");

        printf("1. Substring\n");
        printf("2. Palindrome\n");
        printf("3. Compare\n");
        printf("4. Copy\n");
        printf("5. Reverse\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter string: ");
                scanf("%s", str1);

                printf("Enter position: ");
                scanf("%d", &position);

                printf("Enter number of characters: ");
                scanf("%d", &n);

                substring(str1, position, n);
                break;

            case 2:
                printf("Enter string: ");
                scanf("%s", str1);

                palindrome(str1);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);

                printf("Enter second string: ");
                scanf("%s", str2);

                compare(str1, str2);
                break;

            case 4:
                printf("Enter string: ");
                scanf("%s", str1);

                copy(str1, str3);

                printf("Copied string: %s\n", str3);
                break;

            case 5:
                printf("Enter string: ");
                scanf("%s", str1);

                reverse(str1);

                printf("Reversed string: %s\n", str1);
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("\nProgram ended.\n");

    return 0;
}