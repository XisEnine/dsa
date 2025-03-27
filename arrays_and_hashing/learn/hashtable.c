#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256  /**< Maximum size for strings */

/**
 * @struct Node
 * @brief Node structure for chaining in the hash table
 */
typedef struct Node {
    char person_name[MAX_SIZE];  /**< Person's name */
    int age;                     /**< Person's age */
    struct Node* next;           /**< Pointer to the next node in the chain */
} Node;

/**
 * @struct Bucket
 * @brief Bucket structure for the hash table
 */
typedef struct {
    Node* head;  /**< Pointer to the first node in the bucket */
} Bucket;

/**
 * @brief Initializes all buckets in the hash table
 * @param buckets Array of buckets
 * @param size Number of buckets
 */
void initializeBuckets(Bucket buckets[], int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].head = NULL;
    }
}

/**
 * @brief Generates a hash key for a given word using djb2 algorithm
 * @param word The word to hash
 * @param size Size of the hash table
 * @return The generated hash key
 */
unsigned int hashKeyGen(const char *word, int size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % size;
}

/**
 * @brief Creates a new node with the given name and age
 * @param name Person's name
 * @param age Person's age
 * @return Pointer to the newly created node
 */
Node* createNode(const char name[], int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strncpy(newNode->person_name, name, MAX_SIZE - 1);
    newNode->person_name[MAX_SIZE - 1] = '\0'; // Ensure null termination
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Clears the input buffer after scanf operations
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Inserts a person into the hash table
 * @param hashKey The bucket index
 * @param buckets Array of buckets
 * @param name Person's name
 */
void insertTable(int hashKey, Bucket buckets[], const char name[]) {
    int age;
    printf("Enter age for %s: ", name);
    scanf("%d", &age);
    clearInputBuffer();  // Clear the input buffer
    
    // Check if person already exists
    Node* current = buckets[hashKey].head;
    while (current != NULL) {
        if (strcmp(current->person_name, name) == 0) {
            printf("Person already exists. Updating age to %d\n", age);
            current->age = age;
            return;
        }
        current = current->next;
    }
    
    // Create new node and insert at head
    Node* newNode = createNode(name, age);
    newNode->next = buckets[hashKey].head;
    buckets[hashKey].head = newNode;
    printf("Person added to bucket %d\n", hashKey);
}

/**
 * @brief Searches for a person in the hash table
 * @param buckets Array of buckets
 * @param size Size of the hash table
 * @param name Person's name to search
 * @return Pointer to the node if found, NULL otherwise
 */
Node* searchPerson(Bucket buckets[], int size, const char name[]) {
    int hashKey = hashKeyGen(name, size);
    Node* current = buckets[hashKey].head;
    while (current != NULL) {
        if (strcmp(current->person_name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Person not found
}

/**
 * @brief Deletes a person from the hash table
 * @param buckets Array of buckets
 * @param size Size of the hash table
 * @param name Person's name to delete
 * @return true if person was deleted, false otherwise
 */
bool deletePerson(Bucket buckets[], int size, const char name[]) {
    int hashKey = hashKeyGen(name, size);
    Node *current = buckets[hashKey].head, *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->person_name, name) == 0) {
            if (prev == NULL) {
                buckets[hashKey].head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

/**
 * @brief Prints the hash table contents
 * @param buckets Array of buckets
 * @param size Size of the hash table
 */
void printHashTable(Bucket buckets[], int size) {
    printf("\n----- Hash Table Contents -----\n");
    int totalEntries = 0;
    
    for (int i = 0; i < size; i++) {
        if (buckets[i].head != NULL) {
            printf("Bucket number: %d\n", i);
            Node* current = buckets[i].head;
            int cnt = 1;
            
            while (current != NULL) {
                printf("[%d] Name: %s, Age: %d\n", cnt, current->person_name, current->age);
                current = current->next;
                cnt++;
                totalEntries++;
            }
            printf("\n");  // Add a line break between buckets
        }
    }
    
    if (totalEntries == 0) {
        printf("Hash table is empty.\n");
    } else {
        printf("Total entries: %d\n", totalEntries);
    }
}

/**
 * @brief Frees all memory allocated for the hash table
 * @param buckets Array of buckets
 * @param size Size of the hash table
 */
void freeHashTable(Bucket buckets[], int size) {
    for (int i = 0; i < size; i++) {
        Node* current = buckets[i].head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        buckets[i].head = NULL;
    }
}

/**
 * @brief Main function
 * @return 0 on successful execution
 */
int main(void) {
    int size;
    printf("Enter the size of the hash table: ");
    scanf("%d", &size);
    clearInputBuffer();  // Clear the input buffer after scanf
    
    Bucket* buckets = (Bucket*)malloc(size * sizeof(Bucket));
    if (buckets == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    initializeBuckets(buckets, size);
    int choice;
    char name[MAX_SIZE];
    
    do {
        printf("\n----- Hash Table Operations -----\n");
        printf("1. Insert a person\n");
        printf("2. Search for a person\n");
        printf("3. Delete a person\n");
        printf("4. Display hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%255s", name);
                clearInputBuffer();
                insertTable(hashKeyGen(name, size), buckets, name);
                break;
                
            case 2:
                printf("Enter name to search: ");
                scanf("%255s", name);
                clearInputBuffer();
                Node* result = searchPerson(buckets, size, name);
                if (result != NULL) {
                    printf("Found: %s, Age: %d\n", name, result->age);
                } else {
                    printf("Person '%s' not found\n", name);
                }
                break;
                
            case 3:
                printf("Enter name to delete: ");
                scanf("%255s", name);
                clearInputBuffer();
                if (deletePerson(buckets, size, name)) {
                    printf("Person '%s' deleted successfully\n", name);
                } else {
                    printf("Person '%s' not found\n", name);
                }
                break;
                
            case 4:
                printHashTable(buckets, size);
                break;
                
            case 5:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    freeHashTable(buckets, size);
    free(buckets);
    return 0;
}
