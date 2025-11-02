#include <stdio.h>
#include <string.h>

// Function prototypes
void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char str[]);

int main() {
    int choice;
    char message[200];

    while (1) {
        printf("\n===== TCS Secure Message System =====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf

        switch (choice) {
            case 1:
                printf("\nEnter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0'; // remove newline
                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;

            case 3:
                printf("Exiting system... Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to reverse a string in place
void reverseString(char str[]) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to encode message
void encodeMessage(char message[]) {
    reverseString(message); // Step 1: reverse

    for (int i = 0; message[i] != '\0'; i++) {
        unsigned char ch = message[i];

        // Step 2: toggle 2nd and 5th bits (positions start from 0)
        ch ^= (1 << 1); // toggle 2nd bit
        ch ^= (1 << 4); // toggle 5th bit

        message[i] = ch;
    }

    printf("\nEncoded message:\n%s\n", message);
}

// Function to decode message (reverse of encoding)
void decodeMessage(char message[]) {
    // Step 1: untoggle bits (same as toggling again)
    for (int i = 0; message[i] != '\0'; i++) {
        unsigned char ch = message[i];
        ch ^= (1 << 1);
        ch ^= (1 << 4);
        message[i] = ch;
    }

    // Step 2: reverse again to restore original order
    reverseString(message);

    printf("\nDecoded message:\n%s\n", message);
}
