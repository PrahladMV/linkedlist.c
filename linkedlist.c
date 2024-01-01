/*This is a  C program that I made that uses a linked list to represent a class of students 
and allows you to identify a student based on their ID. This program includes additional
functionality such as freeing memory, handling user input, and providing a menu for better
interaction. The program allows you to add students, display the student list, and search for a student by ID. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct Student {
    int id;
    char name[50];
    struct Student* next;
} Student;

// Function to create a new student node
Student* createStudent(int id, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the end of the linked list
Student* insertStudent(Student* head, int id, const char* name) {
    Student* newStudent = createStudent(id, name);

    if (head == NULL) {
        return newStudent;
    }

    Student* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newStudent;
    return head;
}

// Function to search for a student by ID
Student* findStudent(Student* head, int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Student not found
}

// Function to display the list of students
void displayStudents(Student* head) {
    printf("Student List:\n");
    Student* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeStudents(Student* head) {
    Student* current = head;
    while (current != NULL) {
        Student* next = current->next;
        free(current);
        current = next;
    }
}

// Main function
int main() {
    Student* classList = NULL;

    int choice;
    do {
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                char name[50];
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter student name: ");
                scanf("%s", name);
                classList = insertStudent(classList, id, name);
                printf("Student added successfully!\n");
                break;
            }
            case 2:
                displayStudents(classList);
                break;
            case 3: {
                int searchId;
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                Student* foundStudent = findStudent(classList, searchId);
                if (foundStudent != NULL) {
                    printf("Student found: ID: %d, Name: %s\n", foundStudent->id, foundStudent->name);
                } else {
                    printf("Student with ID %d not found\n", searchId);
                }
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free the memory allocated for the linked list
    freeStudents(classList);

    return 0;
}
