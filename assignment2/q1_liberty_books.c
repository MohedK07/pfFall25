#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 50

// Function declarations
void addBook(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int count);

int main() {
    int isbns[MAX_BOOKS];
    char titles[MAX_BOOKS][TITLE_LEN];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== Liberty Books Menu =====\n");
        printf("1. Add New Book\n");
        printf("2. Process Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("\nExiting program... Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new book
void addBook(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("\nInventory is full. Cannot add more books.\n");
        return;
    }

    int newISBN;
    printf("\nEnter ISBN: ");
    scanf("%d", &newISBN);

    // Check for duplicate ISBN
    for (int i = 0; i < *count; i++) {
        if (isbns[i] == newISBN) {
            printf("A book with this ISBN already exists!\n");
            return;
        }
    }

    isbns[*count] = newISBN;

    printf("Enter Title (single word): ");
    scanf("%s", titles[*count]);

    printf("Enter Price: ");
    scanf("%f", &prices[*count]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++; // increase book count
    printf("Book added successfully!\n");
}

// Function to process a sale
void processSale(int isbns[], int quantities[], int count) {
    int searchISBN, qty, found = 0;

    if (count == 0) {
        printf("\nNo books in inventory!\n");
        return;
    }

    printf("\nEnter ISBN to process sale: ");
    scanf("%d", &searchISBN);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == searchISBN) {
            found = 1;
            printf("Enter quantity to sell: ");
            scanf("%d", &qty);

            if (quantities[i] >= qty) {
                quantities[i] -= qty;
                printf("Sale successful! Remaining stock: %d\n", quantities[i]);
            } else {
                printf("Not enough stock available! Current stock: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

// Function to generate low stock report
void lowStockReport(int isbns[], char titles[][TITLE_LEN], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\nNo books in inventory!\n");
        return;
    }

    int found = 0;
    printf("\n===== Low Stock Report (Quantity < 5) =====\n");
    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("All books have sufficient stock.\n");
    }
}
