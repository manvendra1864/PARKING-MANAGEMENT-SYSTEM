#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void ShowDetails();
void Delete();
void two_wheeler();
void three_wheeler();
void four_wheeler();
void six_wheeler();
int Menu();
void SaveData();
void LoadData();

// Global Variables
int notwo = 0, nothree = 0, nofour = 0, nosix = 0, amount = 0, count = 0, ch, choice;

int main() {
    LoadData();  // Load Data from the file at the beginning

    while (1) {
        switch (Menu()) {
            case 1:
                two_wheeler();
                break;
            case 2:
                three_wheeler();
                break;
            case 3:
                four_wheeler();
                break;
            case 4:
                six_wheeler();
                break;
            case 5:
                ShowDetails();
                break;
            case 6:
                Delete();
                break;
            case 7:
                SaveData();  // Save Data to the file before exiting
                exit(0);
            default:
                printf("\nInvalid Choice!");
        }

        while (getchar() != '\n'); // Clear input buffer
        printf("\n\nPress Enter to continue...");
        while (getchar() != '\n'); // Wait for Enter key
    }

    return 0;
}

int Menu() {
    printf("\n\nPARKING MANAGEMENT SYSTEM");
    printf("\n\n1: Entry For Two-Wheelers ");
    printf("\n2: Entry For Three-Wheelers ");
    printf("\n3: Entry For Four-Wheelers ");
    printf("\n4: Entry For Six-Wheelers ");
    printf("\n5: Show Status ");
    printf("\n6: Delete Entry ");
    printf("\n7: Exit ");
    printf("\n\nEnter Your Choice: ");
    scanf("%d", &ch);
    return ch;
}

void ShowDetails() {
    printf("\nNumber of Two-Wheelers: %d", notwo);
    printf("\nNumber of Three-Wheelers: %d", nothree);
    printf("\nNumber of Four-Wheelers: %d", nofour);  // Added newline here
    printf("\nNumber of Six-Wheelers: %d", nosix);
    printf("\nNumber of Total Vehicles: %d", count);
    printf("\nTotal Gain Amount: %d\n", amount);  // Added newline here
}

int DeleteMenu() {
    do {
        printf("\n1: Delete Two-Wheeler ");
        printf("\n2: Delete Three-Wheeler ");
        printf("\n3: Delete Four-Wheeler ");
        printf("\n4: Delete Six-Wheeler ");
        printf("\n5: Reset List ");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("\nInvalid Choice! Please choose again.");
        }
    } while (choice < 1 || choice > 5);

    return choice;
}

void Delete() {
    switch (DeleteMenu()) {
        case 1:
            notwo = 0, amount = amount - 50, count--;
            printf("\nEntry Deleted!");
            break;
        case 2:
            nothree = 0, amount = amount - 100, count--;
            printf("\nEntry Deleted!");
            break;
        case 3:
            nofour = 0, amount = amount - 150, count--;
            printf("\nEntry Deleted!");
            break;
        case 4:
            nosix = 0, amount = amount - 200, count--;
            printf("\nEntry Deleted!");
            break;
        case 5:
            notwo = nothree = nofour = nosix = amount = count = 0;
            printf("\nList Reset!");
            break;
        default:
            printf("\nInvalid Choice!");
    }

    SaveData();  // Save data after the delete operation
}

void two_wheeler() {
    printf("\nEntry Successful");
    notwo++;
    amount = amount + 50;
    count++;
    SaveData();  // Save data after the entry operation
}

void three_wheeler() {
    printf("\nEntry Successful");
    nothree++;
    amount = amount + 100;
    count++;
    SaveData();  // Save data after the entry operation
}

void four_wheeler() {
    printf("\nEntry Successful");
    nofour++;
    amount = amount + 150;
    count++;
    SaveData();  // Save data after the entry operation
}

void six_wheeler() {
    printf("\nEntry Successful");
    nosix++;
    amount = amount + 200;
    count++;
    SaveData();  // Save data after the entry operation
}

void SaveData() {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        printf("\nError opening file for writing.");
        exit(1);
    }

    fprintf(file, "%d %d %d %d %d %d", notwo, nothree, nofour, nosix, amount, count);
    fclose(file);
}

void LoadData() {
    FILE *file = fopen("data.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d %d %d %d %d %d", &notwo, &nothree, &nofour, &nosix, &amount, &count);
        fclose(file);
    }
}