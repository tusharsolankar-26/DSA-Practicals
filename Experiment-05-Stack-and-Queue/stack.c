#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct stack
{
    int s[SIZE];
    int top;
};

int isFull(struct stack *st)
{
    if (st->top >= SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *st)
{
    if (st->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *st, int item)
{
    st->top++;
    st->s[st->top] = item;
}

void pop(struct stack *st)
{
    int item;

    if (isEmpty(st))
    {
        printf("\nStack is empty! Underflow.\n");
    }
    else
    {
        item = st->s[st->top];
        st->top--;

        printf("\nThe popped element is: %d\n", item);
    }
}

void display(struct stack *st)
{
    int i;

    if (isEmpty(st))
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nStack elements are:\n");

        for (i = st->top; i >= 0; i--)
        {
            printf("%d\n", st->s[i]);
        }

        printf("TOP = %d\n", st->top);
    }
}

int main()
{
    struct stack st;
    int choice;
    int item;
    char ans;

    st.top = -1;

    do
    {
        
        printf("IMPLEMENTATION OF STACK\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the item to be pushed: ");
                scanf("%d", &item);

                if (isFull(&st))
                {
                    printf("\nStack is full!\n");
                }
                else
                {
                    push(&st, item);
                    printf("\nItem %d pushed successfully.\n", item);
                }
                break;

            case 2:
                pop(&st);
                break;

            case 3:
                display(&st);
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ans);

    } while (ans == 'y' || ans == 'Y');

    printf("\nProgram ended.\n");

    return 0;
}