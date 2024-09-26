#include <stdio.h>
#include <stdbool.h>

void main() {
    int rec_num;        // Employee number
    int salary;         // Employee salary
    const int leave = 15;  // Number of leave days
    char name[100];     // Employee name
    char gender;        // Employee gender (F for Female, M for Male, O for Other)
    char dept;          // Employee department (A, B, or C)
    bool ML = false;   // Flag to indicate if maternity leave is allowed

    // Prompt the user to enter the employee name
    printf("Enter employee name: ");
    scanf("%99s", name); // Use %99s to prevent buffer overflow

    // Prompt the user to enter the employee number
    printf("Enter employee number: ");
    scanf("%d", &rec_num);

    // Get department input and validate it
    while (true) {
        printf("Enter Department A, B, or C: ");
        scanf(" %c", &dept); // Space before %c to consume any leftover newline

        switch (dept) {
            case 'A':
            case 'B':
            case 'C':
                break; // Exit loop if input is valid
            default:
                printf("Invalid input. ");
                continue; // Prompt again
        }
        break; // Exit loop if input is valid
    }

    // Get salary input based on department and validate it
    while (true) { // Get salary input based on department and validate it
        // Prompt for salary based on department
        if (dept == 'A') {
            printf("Enter employee salary between 1000 to 5000: ");
        } else if (dept == 'B') {
            printf("Enter employee salary between 5001 to 10000: ");
        } else {
            printf("Enter employee salary between 10001 to 20000: ");
        }
        scanf("%d", &salary);
        getchar(); // Consume the newline character left by scanf

        // Validate salary range based on department
        if ((dept == 'A' && salary >= 1000 && salary <= 5000) ||
            (dept == 'B' && salary >= 5001 && salary <= 10000) ||
            (dept == 'C' && salary >= 10001 && salary <= 20000)) {
            break; // Exit loop if salary is within valid range
            }
        // Inform the user of invalid salary and prompt again
        printf("Invalid salary. ");
    }

    while (true) { // Get gender input and validate it
        printf("Enter %s gender F, M, or O: ", name);
        scanf("%c", &gender);
        getchar(); // Consume the newline character left by scanf

        if (gender == 'F' || gender == 'M' || gender == 'O') { // Check if the entered gender is valid
            // Set maternity leave flag if gender is Female
            if (gender == 'F') {
                printf("%s is allowed maternity leave\n", name);
                ML = true;
            }
            break; // Exit loop if input is valid
        }
        // Inform the user of invalid input and prompt again
        printf("Invalid input. ");
    }

    // Print formatted employee details
    printf("Formatted Employee Details: \n%d\t%s\t%c\t%c\t%d\t%d\n", rec_num, name, gender, dept, salary, leave);
    // Print detailed employee summary
    printf("Employee Summary: \nEmployee number: %d\nEmployee name: %s\nEmployee gender: %c\nEmployee department: %c\nEmployee Salary: %d\nEmployee leaves accumulation: %d\n", rec_num, name, gender, dept, salary, leave);

    // Print maternity leave information if applicable
    if (ML) {
        printf("Maternity leave allowed\n");
    }
}
