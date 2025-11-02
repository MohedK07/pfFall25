#include <stdio.h>

#define ROWS 3
#define COLS 3

// Bit flags
#define POWER_ON 1     // Bit 0
#define OVERLOAD 2     // Bit 1
#define MAINT_REQ 4    // Bit 2

// Function declarations
void updateSector(int grid[ROWS][COLS]);
void querySector(int grid[ROWS][COLS]);
void systemDiagnostic(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS] = {0};  // 2D grid initialized to 0 (all OFF)
    int choice;

    while (1) {
        printf("\n===== IESCO Power Grid Monitoring =====\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateSector(grid);
                break;
            case 2:
                querySector(grid);
                break;
            case 3:
                systemDiagnostic(grid);
                break;
            case 4:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to update a sector's status flags
void updateSector(int grid[ROWS][COLS]) {
    int row, col, flagChoice, action;
    printf("\nEnter row (0-%d): ", ROWS - 1);
    scanf("%d", &row);
    printf("Enter column (0-%d): ", COLS - 1);
    scanf("%d", &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    printf("\nSelect flag to modify:\n");
    printf("1. Power ON/OFF\n");
    printf("2. Overload Warning\n");
    printf("3. Maintenance Required\n");
    printf("Enter your choice: ");
    scanf("%d", &flagChoice);

    printf("Enter 1 to SET the flag, 0 to CLEAR it: ");
    scanf("%d", &action);

    int flag;
    switch (flagChoice) {
        case 1: flag = POWER_ON; break;
        case 2: flag = OVERLOAD; break;
        case 3: flag = MAINT_REQ; break;
        default: printf("Invalid flag choice!\n"); return;
    }

    if (action == 1)
        grid[row][col] |= flag;  // Set bit
    else
        grid[row][col] &= ~flag; // Clear bit

    printf("Sector (%d, %d) updated successfully.\n", row, col);
}

// Function to query a sector and print readable report
void querySector(int grid[ROWS][COLS]) {
    int row, col;
    printf("\nEnter row (0-%d): ", ROWS - 1);
    scanf("%d", &row);
    printf("Enter column (0-%d): ", COLS - 1);
    scanf("%d", &col);

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid coordinates!\n");
        return;
    }

    int status = grid[row][col];
    printf("\nSector (%d, %d) Status Report:\n", row, col);
    printf("Power: %s\n", (status & POWER_ON) ? "ON" : "OFF");
    printf("Overload: %s\n", (status & OVERLOAD) ? "Yes" : "No");
    printf("Maintenance Required: %s\n", (status & MAINT_REQ) ? "Yes" : "No");
}

// Function to scan entire grid for overloaded or maintenance-required sectors
void systemDiagnostic(int grid[ROWS][COLS]) {
    int overloadCount = 0, maintCount = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] & OVERLOAD)
                overloadCount++;
            if (grid[i][j] & MAINT_REQ)
                maintCount++;
        }
    }

    printf("\n===== System Diagnostic Report =====\n");
    printf("Total sectors overloaded: %d\n", overloadCount);
    printf("Total sectors needing maintenance: %d\n", maintCount);
    printf("====================================\n");
}
