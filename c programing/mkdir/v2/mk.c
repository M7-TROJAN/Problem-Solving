#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FAST = 1, NORMAL = 2, ADVANCED = 3 } Mood;

void welcome(void);
void createFoldersFast(void);
void createFoldersNormal(void);
void createFoldersAdvanced(void);

int main(int argc, char* argv[]) {
    Mood mode;

    welcome();
    if (scanf("%d", (int*)&mode) != 1) {
        puts("Invalid choice.");
        system("PAUSE");
        return 1;
    }

    while (mode != FAST && mode != NORMAL && mode != ADVANCED) {
        printf("Invalid mode.\n");
        printf("Enter mode number: ");
        if (scanf("%d", (int*)&mode) != 1) {
            puts("Invalid choice.");
            system("PAUSE");
            return 1;
        }
    }

    if (mode == FAST)
        createFoldersFast();
    else if (mode == NORMAL)
        createFoldersNormal();
    else if (mode == ADVANCED)
        createFoldersAdvanced();
    else
        puts("Invalid choice.");

    return 0;
}

void welcome(void) {
    printf("\n\a"
           "\t\t**************************************\n"
           "\t\t*                                    *\n"
           "\t\t*                                    *\n"
           "\t\t*         Hello, Tro<m7>jan          *\n"
           "\t\t*                                    *\n"
           "\t\t*                                    *\n"
           "\t\t**************************************\n\n\n");
    printf("Please choose the mode:\n");
    printf("(1) Fast mode\n"
           "(2) Normal mode\n"
           "(3) Advanced mode\n");
    printf("Enter your choice number: ");
}

void createFoldersFast(void) {
    int count;
    printf("Enter the number of folders you want to create: ");
    if (scanf("%d", &count) != 1) {
        puts("Invalid input.");
        system("PAUSE");
        return;
    }

    for (int i = 1; i <= count; i++) {
        char command[30];
        sprintf(command, "mkdir \"%d\"", i);
        if (system(command) != 0) {
            printf("Failed to create folder: %d\n", i);
        }
        printf("%d\r", i);
    }
    puts("\nDone. All folders are created.");
    system("PAUSE");
}

void createFoldersNormal(void) {
    int count;
    printf("How many folders do you want to create?: ");
    if (scanf("%d", &count) != 1) {
        puts("Invalid input.");
        system("PAUSE");
        return;
    }
    system("mkdir \"new folder\"");
    count -= 1;
    for (int i = 1; i <= count; i++) {
        char command[30];
        sprintf(command, "mkdir \"new folder(%d)\"", i + 1);
        system(command);
        printf("%d\r", i + 1);
    }
    puts("\nDone. All folders are created.");
    system("PAUSE");
}

void createFoldersAdvanced(void) {
    int count;
    printf("How many folders do you want to create?: ");
    if (scanf("%d", &count) != 1) {
        puts("Invalid input.");
        system("PAUSE");
        return;
    }
    while ((getchar()) != '\n'); // Clear the input buffer

    for (int i = 1; i <= count; i++) {
        printf("Enter folder name: ");
        char folderName[100];
        if (fgets(folderName, sizeof(folderName), stdin) == NULL) {
            puts("Failed to read input.");
            system("PAUSE");
            return;
        }

        // Remove the trailing newline character
        folderName[strcspn(folderName, "\n")] = '\0';

        char command[110];
        sprintf(command, "mkdir \"%s\"", folderName);
        if (system(command) != 0) {
            printf("Failed to create folder: %s\n", folderName);
        }
    }
    puts("\nDone. All folders are created.");
    system("PAUSE");
}