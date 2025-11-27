#include <stdio.h>
#include <string.h>

struct employee {
    int id;
    char name[50];
    char designation[50];
    double salary;
};

void displayEmployees(struct employee e[], int n) {
    printf("\n=================================================================\n");
    printf("ID\tNAME\t\t\tDESIGNATION\t\tSALARY\n");
    printf("=================================================================\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%-20s\t%-20s\t%.2lf\n", e[i].id, e[i].name, e[i].designation, e[i].salary);
    }
    printf("=================================================================\n");
}

void findHighestSalary(struct employee e[], int n) {
    int max = 0;
    for(int i = 1; i < n; i++) {
        if(e[i].salary > e[max].salary) {
            max = i;
        }
    }
    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d | Name: %s | Designation: %s | Salary: %.2lf\n\n",
           e[max].id, e[max].name, e[max].designation, e[max].salary);
}

void searchEmployee(struct employee e[], int n) {
    int choice;
    printf("Search by (1 = ID, 2 = Name): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        int id;
        printf("Enter Employee ID: ");
        scanf("%d", &id);
        for(int i = 0; i < n; i++) {
            if(e[i].id == id) {
                printf("FOUND: %s - %s - %.2lf\n", e[i].name, e[i].designation, e[i].salary);
                return;
            }
        }
        printf("Employee ID %d not found!\n", id);
    }
    else if (choice == 2) {
        char name[50];
        printf("Enter Employee Name: ");
        scanf(" %49[^\n]", name);
        for(int i = 0; i < n; i++) {
            if(strcmp(e[i].name, name) == 0) {
                printf("FOUND: ID=%d | %s | Salary: %.2lf\n", e[i].id, e[i].designation, e[i].salary);
                return;
            }
        }
        printf("Employee '%s' not found!\n", name);
    }
}

void giveBonus(struct employee e[], int n, double threshold) {
    for(int i = 0; i < n; i++) {
        if(e[i].salary < threshold) {
            e[i].salary *= 1.10;
        }
    }
}

int main() {
    struct employee emp[100];
    int n;
    
    printf("Number of employees you want to enter: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        printf("\n--- Employee %d ---\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Name: ");
        scanf(" %49[^\n]", emp[i].name);
        printf("Enter Designation: ");
        scanf(" %49[^\n]", emp[i].designation);
        printf("Enter Salary: ");
        scanf("%lf", &emp[i].salary);
    }
    
    displayEmployees(emp, n);
    findHighestSalary(emp, n);
    searchEmployee(emp, n);

    return 0;
}
/*
    If the company decides to award a 10% bonus to employees earning less than a specific amount 
    (for example, 50,000), this can be done by creating a separate function such as:

    void giveBonus(struct employee emp[], int n, double threshold) {
        for(int i = 0; i < n; i++) {
            if(emp[i].salary < threshold) {
                emp[i].salary *= 1.10;
            }
        }
    }

    Since arrays of structures in C are passed by reference, any salary updates made inside this 
    function will automatically modify the actual employee records stored in the original array.
*/
