

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Structure to represent an instruction
typedef struct Instruction {
    char command[100];
    struct Instruction* next;
} Instruction;

// Function to add an instruction to the linked list
void addInstruction(Instruction** head, const char* command) {
    Instruction* newInstruction = (Instruction*)malloc(sizeof(Instruction));
    if (newInstruction == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Copy the command to the new instruction node
    printf(newInstruction->command, sizeof(newInstruction->command), "%s", command);
    newInstruction->next = NULL;
     // If the linked list is empty, make the new instruction the head
    if (*head == NULL)
    {
        *head = newInstruction;
    }
    else
    {
        // Find the last instruction and append the new instruction
        Instruction* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newInstruction;
    }
}

// Function to display all instructions in the linked list
void displayInstructions(Instruction* head)
{
    printf("Instructions:\n");
    while (head != NULL)
    {
        printf("%s\n", head->command);
        head = head->next;
    }
}

// Function to free the memory allocated for the linked list
void freeInstructions(Instruction** head)
{
    while (*head != NULL) 
    {
        Instruction* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Instruction* head = NULL;
    printf("Welcome to the Stable Diffusion Platform\n");
    printf("Add instructions (type 'exit' to stop):\n");
    char input[100];
    do {
        printf("* ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") != 0) 
        {
            addInstruction(&head, input);
        }
    } while (strcmp(input, "exit") != 0);
    // Display instructions
    displayInstructions(head);
     // Free allocated memory
    freeInstructions(&head);
    return 0;
}

