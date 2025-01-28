#include <stdio.h>
#include <stdlib.h>

void addNumbers();
void subtractNumbers();
void guessingGame();

int getArrowKey() {
    system("/bin/stty raw"); // Disable line buffering
    int c = getchar();
    if (c == 27) { // Escape sequence
        getchar(); // Skip '['
        c = getchar(); // Actual arrow key
    }
    system("/bin/stty cooked"); // Restore terminal
    return c;
}

int handleMenu() {
    int selected = 1;
    int c;

    while (1) {
        // Clear screen and show menu
        system("clear");
        printf("Main Menu (Use ↑/↓ arrows, Enter to select)\n\n");
        printf("%s1. Add Two Numbers\n", selected == 1 ? "> " : "  ");
        printf("%s2. Subtract Two Numbers\n", selected == 2 ? "> " : "  ");
        printf("%s3. Guessing Game\n", selected == 3 ? "> " : "  ");
        printf("%s4. Exit\n", selected == 4 ? "> " : "  ");
        fflush(stdout);

        c = getArrowKey();
        if (c == 'A') { // Up arrow
            selected = (selected == 1) ? 4 : selected - 1;
        } else if (c == 'B') { // Down arrow
            selected = (selected == 4) ? 1 : selected + 1;
        } else if (c == 13) { // Enter key
            return selected;
        }
    }
}

int main() {
    int choice;
    
    do {
        choice = handleMenu();
        system("clear");
        
        switch(choice) {
            case 1:
                addNumbers();
                break;
            case 2:
                subtractNumbers();
                break;
            case 3:
                guessingGame();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
        }
        if(choice != 4) {
            printf("\nPress Enter to return to menu...");
            while(getchar() != '\n'); // Clear input buffer
            getchar(); // Wait for Enter
        }
    } while(choice != 4);

    return 0;
}

// Keep your existing functions below (addNumbers, subtractNumbers, guessingGame)
// [Paste the original functions here unchanged]