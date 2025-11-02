#include <stdio.h>
#define MAX 5  // maximum stack size

// Function prototypes
void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1; // stack is empty initially
    int choice;

    while (1) {
        printf("\n===== STACK MENU =====\n");
        printf("1. PUSH (Insert)\n");
        printf("2. POP (Remove)\n");
        printf("3. PEEK (Top Element)\n");
        printf("4. DISPLAY (All Elements)\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("\nExiting program... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to PUSH element onto the stack
void push(int stack[], int *top) {
    if (*top == MAX - 1) {
        printf("Stack Overflow! Cannot insert more elements.\n");
        return;
    }
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    (*top)++;
    stack[*top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to POP element from the stack
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("Popped %d from the stack.\n", stack[*top]);
    (*top)--;
}

// Function to PEEK (see top element)
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Function to DISPLAY all elements in the stack
void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("\nCurrent Stack Elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
