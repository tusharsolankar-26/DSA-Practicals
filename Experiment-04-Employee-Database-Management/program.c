#include <stdio.h>
#include <string.h>

#define MAX 30

//  Employee structure 
struct Employee
{
    
    int emp_no;
    char name[20];
    float salary;
};


void displayRecord(struct Employee emp)
{
    printf("\nEmployee No : %d", emp.emp_no);
    printf("\nName        : %s", emp.name);
    printf("\nSalary      : %f\n", emp.salary);
}

void create(struct Employee emp[], int *n)
{
    int i;

    printf("\nEnter number of employees: ");
    scanf("%d", n);

    for (i = 0; i < *n; i++)
    {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Enter employee number: ");
        scanf("%d", &emp[i].emp_no);

        printf("Enter name: ");
        scanf("%19s", emp[i].name);

        printf("Enter salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\nEmployee database created successfully.\n");
}

// Display Function 
void display(struct Employee emp[], int n)
{
    int i;

    if (n == 0)
    {
        printf("\nDatabase is empty.\n");
        return;
    }

    printf("\n========== EMPLOYEE DATABASE ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee %d", i + 1);
        displayRecord(emp[i]);
    }
}

// Search Function 
void search(struct Employee emp[], int n)
{
    int i;
    int emp_no;
    int found = 0;

    printf("\nEnter employee number to search: ");
    scanf("%d", &emp_no);

    for (i = 0; i < n; i++)
    {
        if (emp[i].emp_no == emp_no)
        {
            printf("\nEmployee found!");
            displayRecord(emp[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}

// Modify Function 
void modify(struct Employee emp[], int n)
{
    int i;
    int emp_no;
    int found = 0;

    printf("\nEnter employee number to modify: ");
    scanf("%d", &emp_no);

    for (i = 0; i < n; i++)
    {
        if (emp[i].emp_no == emp_no)
        {
            printf("\nEnter new name: ");
            scanf("%19s", emp[i].name);

            printf("Enter new salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee record modified successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}

//Append Function 
void append(struct Employee emp[], int *n)
{
    if (*n >= MAX)
    {
        printf("\nDatabase is full.\n");
        return;
    }

    printf("\nEnter employee number: ");
    scanf("%d", &emp[*n].emp_no);

    printf("Enter name: ");
    scanf("%19s", emp[*n].name);

    printf("Enter salary: ");
    scanf("%f", &emp[*n].salary);

    (*n)++;

    printf("\nEmployee added successfully.\n");
}

// Delete Function 
void deleteEmployee(struct Employee emp[], int *n)
{
    int i, j;
    int emp_no;
    int found = 0;

    printf("\nEnter employee number to delete: ");
    scanf("%d", &emp_no);

    for (i = 0; i < *n; i++)
    {
        if (emp[i].emp_no == emp_no)
        {
            for (j = i; j < *n - 1; j++)
            {
                emp[j] = emp[j + 1];
            }

            (*n)--;

            printf("\nEmployee deleted successfully.\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}

// Sorting 
void sort(struct Employee emp[], int n)
{
    int i, j;
    struct Employee temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (emp[j].emp_no > emp[j + 1].emp_no)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    printf("\nEmployee database sorted by employee number.\n");
}

int main()
{
    struct Employee emp[MAX];

    int n = 0;
    int choice;
    char ch;

    do
    {
        
        printf("EMPLOYEE DATABASE\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Search Employee\n");
        printf("4. Modify Employee\n");
        printf("5. Append Employee\n");
        printf("6. Delete Employee\n");
        printf("7. Sort Database\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create(emp, &n);
                break;

            case 2:
                display(emp, n);
                break;

            case 3:
                search(emp, n);
                break;

            case 4:
                modify(emp, n);
                break;

            case 5:
                append(emp, &n);
                break;

            case 6:
                deleteEmployee(emp, &n);
                break;

            case 7:
                sort(emp, n);
                break;

            case 8:
                printf("\nExit\n");
                return 0;

        }

        if (choice != 8)
        {
            printf("\nDo you want to continue? (y/n): ");
            scanf(" %c", &ch);
        }
        else
        {
            ch = 'n';
        }

    } while (ch == 'y' || ch == 'Y');

    printf("\nProgram ended.\n");

    return 0;
}