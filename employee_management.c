#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee emp;
    FILE *file;
    int choice;

    printf("1. Add Employee\n");
    printf("2. View Employee\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter Employee ID: ");
        scanf("%d", &emp.id);

        printf("Enter Employee Name: ");
        scanf("%s", emp.name);

        printf("Enter Employee Salary: ");
        scanf("%f", &emp.salary);

        file = fopen("employee.txt", "a");

        if (file == NULL) {
            printf("Unable to open file.");
            return 1;
        }

        fprintf(file, "%d %s %.2f\n",
                emp.id, emp.name, emp.salary);

        fclose(file);

        printf("\nEmployee added successfully.");
    }
    else if (choice == 2) {
        file = fopen("employee.txt", "r");

        if (file == NULL) {
            printf("No employee data found.");
            return 1;
        }

        printf("\n--- Employee Details ---\n");

        while (fscanf(file, "%d %s %f",
                      &emp.id, emp.name, &emp.salary) != EOF) {
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n\n", emp.salary);
        }

        fclose(file);
    }
    else {
        printf("Invalid choice.");
    }

    return 0;
}
