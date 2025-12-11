#include <stdio.h>
#include <string.h>

// Function declarations
void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void updateAllBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void recordPayment(char names[][50], int total[], int n);
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n);

int main() {
    int n, choice;

    printf("How many tenants? ");
    scanf("%d", &n);

    char names[n][50];
    int rent[n], elec[n], water[n], total[n];

    enterTenants(names, rent, elec, water, total, n);

    while (1) {
        printf("\n===== ADVANCED BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("1. Display All Bills\n");
        printf("2. Update Rent + Electricity + Water (All in One)\n");
        printf("3. Record Payment\n");
        printf("4. Search Tenant\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) 
            displayBills(names, rent, elec, water, total, n);
        else if (choice == 2) 
            updateAllBills(names, rent, elec, water, total, n);
        else if (choice == 3) 
            recordPayment(names, total, n);
        else if (choice == 4) 
            searchTenant(names, rent, elec, water, total, n);
        else if (choice == 5) {
            printf("Exiting system...\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Enter tenant names and initialize all bills
void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nEnter tenant %d name: ", i + 1);
        scanf("%s", names[i]);

        rent[i] = 0;
        elec[i] = 0;
        water[i] = 0;
        total[i] = 0;
    }
}

// Display full billing list
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int i;

    printf("\n--- FULL BILLING LIST ---\n");
    printf("No.   Name        Rent   Elec   Water   TOTAL\n");

    for (i = 0; i < n; i++) {
        printf("%d    %-10s  %5d  %5d  %5d  %6d\n", 
            i+1, names[i], rent[i], elec[i], water[i], total[i]);
    }
}

// NEW: Update rent, electricity, and water *in one function*
void updateAllBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int num, newRent, newElec, newWater;

    printf("\nSelect tenant number to update bills: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    num--; // convert to array index

    printf("Updating bills for %s\n", names[num]);

    printf("Enter new Rent: ");
    scanf("%d", &newRent);

    printf("Enter Electricity bill: ");
    scanf("%d", &newElec);

    printf("Enter Water bill: ");
    scanf("%d", &newWater);

    rent[num] = newRent;
    elec[num] = newElec;
    water[num] = newWater;

    // Recalculate total
    total[num] = rent[num] + elec[num] + water[num];

    printf("Bills updated successfully!\n");
}

// Record payment
void recordPayment(char names[][50], int total[], int n) {
    int num, pay;

    printf("\nSelect tenant to record payment: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    num--;

    printf("Enter amount paid by %s: ", names[num]);
    scanf("%d", &pay);

    if (pay > total[num]) {
        printf("Payment exceeds total bill!\n");
    } else {
        total[num] -= pay;
        printf("Payment recorded! Remaining balance: %d\n", total[num]);
    }
}

// Search tenant by name
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    char search[50];
    int i, found = 0;

    printf("\nEnter tenant name to search: ");
    scanf("%s", search);

    for (i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("\n--- Tenant Found ---\n");
            printf("Name: %s\n", names[i]);
            printf("Rent: %d\n", rent[i]);
            printf("Electricity: %d\n", elec[i]);
            printf("Water: %d\n", water[i]);
            printf("Total Balance: %d\n", total[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Tenant not found!\n");
    }
}