#include <stdio.h>

#define MAX 50

// Global arrays
char names[MAX][50];
float rent[MAX];
float water[MAX];
float electricity[MAX];
int count = 0;

// Function prototypes
void addTenant();
void updateAllBills();
void displayBills();

int main() {
    int choice;

    do {
        printf("\n===== BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("1. Add Tenant\n");
        printf("2. Update All Bills (Rent + Water + Electricity)\n");
        printf("3. Display Tenant Bills\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addTenant();
        }
        else if (choice == 2) {
            updateAllBills();
        }
        else if (choice == 3) {
            displayBills();
        }
        else if (choice == 4) {
            printf("Exiting system...\n");
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Add tenant
void addTenant() {
    printf("Enter tenant name: ");
    scanf(" %[^\n]", names[count]);

    rent[count] = 0;
    water[count] = 0;
    electricity[count] = 0;

    count++;

    printf("Tenant added successfully!\n");
}

// Combined update function
void updateAllBills() {
    int i, option;

    if (count == 0) {
        printf("No tenants available.\n");
        return;
    }

    printf("\nSelect a tenant to update bills:\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    printf("Enter number: ");
    scanf("%d", &option);

    int index = option - 1;

    if (index >= 0 && index < count) {
        printf("\nUpdating bills for %s\n", names[index]);

        printf("Enter new rent amount: ");
        scanf("%f", &rent[index]);

        printf("Enter new water bill: ");
        scanf("%f", &water[index]);

        printf("Enter new electricity bill: ");
        scanf("%f", &electricity[index]);

        printf("Bills updated successfully!\n");
    }
    else {
        printf("Invalid tenant selection!\n");
    }
}

// Display all tenant bills
void displayBills() {
    int i;

    if (count == 0) {
        printf("No tenants to display.\n");
        return;
    }

    printf("\n===== TENANT BILL SUMMARY =====\n");

    for (i = 0; i < count; i++) {
        float total = rent[i] + water[i] + electricity[i];

        printf("\nTenant: %s\n", names[i]);
        printf("Rent: %.2f\n", rent[i]);
        printf("Water: %.2f\n", water[i]);
        printf("Electricity: %.2f\n", electricity[i]);
        printf("TOTAL BILL: %.2f\n", total);
    }
}