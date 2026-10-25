
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("%d pushed into stack\n", value);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

void display()
{
    struct node *temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
