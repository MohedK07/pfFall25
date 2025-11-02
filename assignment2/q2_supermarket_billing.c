#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 4
#define MAX_NAME 50

// Function declarations
void getCustomerInfo(char name[], char cnic[]);
void displayInventory(int codes[], int qty[], int price[]);
void addToCart(int codes[], int qty[], int price[], int *total);
void displayBill(int total);
void showInvoice(char name[], char cnic[], int total);

int main() {
    int productCodes[MAX_PRODUCTS] = {1, 2, 3, 4};
    int stockQty[MAX_PRODUCTS] = {50, 10, 20, 8};
    int pricePerProduct[MAX_PRODUCTS] = {100, 200, 300, 150};
    int choice;
    int totalBill = 0;
    char customerName[MAX_NAME], cnic[20];

    while (1) {
        printf("\n===== Supermarket Menu =====\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getCustomerInfo(customerName, cnic);
                break;
            case 2:
                displayInventory(productCodes, stockQty, pricePerProduct);
                break;
            case 3:
                addToCart(productCodes, stockQty, pricePerProduct, &totalBill);
                break;
            case 4:
                displayBill(totalBill);
                break;
            case 5:
                showInvoice(customerName, cnic, totalBill);
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function: Enter customer info
void getCustomerInfo(char name[], char cnic[]) {
    printf("\nEnter customer name: ");
    scanf("%s", name);
    printf("Enter customer CNIC: ");
    scanf("%s", cnic);
    printf("Customer info recorded successfully.\n");
}

// Function: Display inventory
void displayInventory(int codes[], int qty[], int price[]) {
    printf("\nProduct Code | Quantity | Price per Product\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%d\t\t%d\t\t%d\n", codes[i], qty[i], price[i]);
    }
}

// Function: Add to cart and update stock
void addToCart(int codes[], int qty[], int price[], int *total) {
    int code, quantity, found = 0;
    printf("\nEnter product code to purchase: ");
    scanf("%d", &code);

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (codes[i] == code) {
            found = 1;
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (qty[i] >= quantity) {
                qty[i] -= quantity;
                int cost = quantity * price[i];
                *total += cost;
                printf("Added to cart! Cost: %d | Remaining stock: %d\n", cost, qty[i]);
            } else {
                printf("Not enough stock available!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Invalid product code!\n");
    }
}

// Function: Display total bill
void displayBill(int total) {
    if (total == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    printf("\nYour total bill (before discount): %d\n", total);
    char promo[20];
    printf("Do you have a promo code? (type Eid2025 if yes, otherwise type no): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        float discount = total * 0.25;
        float finalBill = total - discount;
        printf("Promo applied! Discount: %.2f | Final bill: %.2f\n", discount, finalBill);
    } else {
        printf("No discount applied. Final bill: %d\n", total);
    }
}

// Function: Show invoice
void showInvoice(char name[], char cnic[], int total) {
    printf("\n===== CUSTOMER INVOICE =====\n");
    printf("Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("Total Bill (without discount): %d\n", total);
    printf("With Eid2025 discount (25%% off): %.2f\n", total * 0.75);
    printf("=============================\n");
}
