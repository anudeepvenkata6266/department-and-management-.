#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "employees.dat"
#define MAX_NAME_LEN 100
#define MAX_DEPT_LEN 100
#define MAX_CONTACT_LEN 50
#define MAX_ROLE_LEN 100

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char gender[10];
    char department[MAX_DEPT_LEN];
    char role[MAX_ROLE_LEN];
    char contact[MAX_CONTACT_LEN];
} Employee;

// ------------------ FUNCTION DECLARATIONS ------------------
void addEmployee();
void viewEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();
int idExists(int id);
void saveEmployee(Employee e);
void loadEmployees(Employee employees[], int *count);
void writeAllEmployees(Employee employees[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n=================================\n");
        printf(" EMPLOYEE DEPARTMENT MANAGEMENT\n");
        printf("=================================\n");
        printf("1. Add New Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("---------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD EMPLOYEE ------------------
void addEmployee() {
    Employee e;

    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    getchar();

    if (idExists(e.id)) {
        printf("Error: Employee ID already exists!\n");
        return;
    }

    printf("Enter Full Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &e.age);
    getchar();

    printf("Enter Gender: ");
    fgets(e.gender, sizeof(e.gender), stdin);
    e.gender[strcspn(e.gender, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = '\0';

    printf("Enter Job Role: ");
    fgets(e.role, sizeof(e.role), stdin);
    e.role[strcspn(e.role, "\n")] = '\0';

    printf("Enter Contact Info: ");
    fgets(e.contact, sizeof(e.contact), stdin);
    e.contact[strcspn(e.contact, "\n")] = '\0';

    saveEmployee(e);
    printf("Employee added successfully!\n");
}

// ------------------ SAVE EMPLOYEE ------------------
void saveEmployee(Employee e) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);
}

// ------------------ CHECK ID EXISTS ------------------
int idExists(int id) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Employee e;
    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.id == id) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL EMPLOYEES ------------------
void viewEmployees() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No employee records found.\n");
        return;
    }

    Employee e;
    printf("\n%-10s %-20s %-5s %-10s %-15s %-20s %-15s\n",
           "ID", "Name", "Age", "Gender", "Department", "Role", "Contact");
    printf("---------------------------------------------------------------------------------------------\n");

    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("%-10d %-20s %-5d %-10s %-15s %-20s %-15s\n",
               e.id, e.name, e.age, e.gender, e.department, e.role, e.contact);
    }
    fclose(fp);
}

// ------------------ SEARCH EMPLOYEE ------------------
void searchEmployee() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    Employee e;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDepartment: %s\nRole: %s\nContact: %s\n",
                   e.id, e.name, e.age, e.gender, e.department, e.role, e.contact);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No employee found with ID %d.\n", id);

    fclose(fp);
}

// ------------------ UPDATE EMPLOYEE ------------------
void updateEmployee() {
    Employee employees[100];
    int count = 0, id, found = 0;

    loadEmployees(employees, &count);

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            found = 1;

            printf("Enter new contact: ");
            fgets(employees[i].contact, sizeof(employees[i].contact), stdin);
            employees[i].contact[strcspn(employees[i].contact, "\n")] = '\0';

            printf("Enter new department: ");
            fgets(employees[i].department, sizeof(employees[i].department), stdin);
            employees[i].department[strcspn(employees[i].department, "\n")] = '\0';

            printf("Enter new job role: ");
            fgets(employees[i].role, sizeof(employees[i].role), stdin);
            employees[i].role[strcspn(employees[i].role, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllEmployees(employees, count);
        printf("Employee record updated successfully.\n");
    } else {
        printf("Employee ID not found.\n");
    }
}

// ------------------ DELETE EMPLOYEE ------------------
void deleteEmployee() {
    Employee employees[100];
    int count = 0, id, found = 0;

    loadEmployees(employees, &count);

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            found = 1;

            printf("Are you sure you want to delete %s (ID %d)? (y/n): ",
                   employees[i].name, id);
            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    employees[j] = employees[j + 1];

                count--;
                writeAllEmployees(employees, count);
                printf("Employee deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Employee ID not found.\n");
}

// ------------------ LOAD & WRITE ALL EMPLOYEES ------------------
void loadEmployees(Employee employees[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;

    *count = 0;
    while (fread(&employees[*count], sizeof(Employee), 1, fp))
        (*count)++;
    fclose(fp);
}

void writeAllEmployees(Employee employees[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(employees, sizeof(Employee), count, fp);
    fclose(fp);
}