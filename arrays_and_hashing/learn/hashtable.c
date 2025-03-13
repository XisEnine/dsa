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
    int count;   /**< Number of nodes in the bucket */
} Bucket;

/**
 * @brief Checks if a number is prime
 * @param num The number to check
 * @return true if the number is prime, false otherwise
 */
bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

/**
 * @brief Generates an array of prime numbers
 * @param size The number of prime numbers to generate
 * @param primeTable Array to store the generated prime numbers
 */
void primeTableCreation(int size, int *primeTable) {
    int count = 0, num = 2;
    while (count < size + 1) {
        if (isPrime(num)) {
            primeTable[count] = num;
            count++;
        }
        ++num;
    }
}

/**
 * @brief Initializes all buckets in the hash table
 * @param buckets Array of buckets
 * @param size Number of buckets
 */
void initializeBuckets(Bucket buckets[], int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].head = NULL;
        buckets[i].count = 0;
    }
}

/**
 * @brief Generates a hash key for a given word
 * @param word The word to hash
 * @param cnt Index for the prime table
 * @param size Size of the hash table
 * @param primeTable Array of prime numbers
 * @return The generated hash key
 */
int hashKeyGen(char word[], int cnt, int size, int primeTable[]) {
    int asciiSum = 0, in = 0;
    while (word[in] != '\0') {
        asciiSum += (int)word[in];
        in++;
    }
    return (asciiSum * primeTable[cnt]) % size;
}

/**
 * @brief Creates a new node with the given name and age
 * @param name Person's name
 * @param age Person's age
 * @return Pointer to the newly created node
 */
Node* createNode(char name[], int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    strncpy(newNode->person_name, name, MAX_SIZE - 1);
    newNode->person_name[MAX_SIZE - 1] = '\0';  // Ensure null termination
    newNode->age = age;
    newNode->next = NULL;
    
    return newNode;
}

/**
 * @brief Inserts a person into the hash table
 * @param cnt Index for the prime table
 * @param hashKey The bucket index
 * @param buckets Array of buckets
 * @param name Person's name
 */
void insertTable(int cnt, int hashKey, Bucket buckets[], char name[]) {
    int age;
    printf("Enter age for %s: ", name);
    scanf("%d", &age);
    
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
    
    // Create new node
    Node* newNode = createNode(name, age);
    
    // Add to the beginning of the chain (could also add to the end)
    newNode->next = buckets[hashKey].head;
    buckets[hashKey].head = newNode;
    buckets[hashKey].count++;
    
    printf("Person added to bucket %d\n", hashKey);
}

/**
 * @brief Searches for a person in the hash table
 * @param buckets Array of buckets
 * @param size Size of the hash table
 * @param name Person's name to search
 * @param primeTable Array of prime numbers
 * @param cnt Index for the prime table
 * @return Pointer to the node if found, NULL otherwise
 */
Node* searchPerson(Bucket buckets[], int size, char name[], int primeTable[], int cnt) {
    int hashKey = hashKeyGen(name, cnt, size, primeTable);
    
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
 * @param primeTable Array of prime numbers
 * @param cnt Index for the prime table
 * @return true if person was deleted, false otherwise
 */
bool deletePerson(Bucket buckets[], int size, char name[], int primeTable[], int cnt) {
    int hashKey = hashKeyGen(name, cnt, size, primeTable);
    
    Node* current = buckets[hashKey].head;
    Node* prev = NULL;
    
    // Find the node to delete
    while (current != NULL) {
        if (strcmp(current->person_name, name) == 0) {
            // If it's the head node
            if (prev == NULL) {
                buckets[hashKey].head = current->next;
            } else {
                prev->next = current->next;
            }
            
            free(current);
            buckets[hashKey].count--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    
    return false; // Person not found
}

/**
 * @brief Prints the contents of the hash table
 * @param buckets Array of buckets
 * @param size Size of the hash table
 */
void printTable(Bucket buckets[], int size) {
    for (int i = 0; i < size; i++) {
        if (buckets[i].count > 0) {
            printf("Bucket %d (Chain length: %d):\n", i, buckets[i].count);
            
            Node* current = buckets[i].head;
            int j = 0;
            
            while (current != NULL) {
                printf("  [%d] Name: %s, Age: %d\n", j++, current->person_name, current->age);
                current = current->next;
            }
        }
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
        buckets[i].count = 0;
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
    
    // Generate prime number table
    int primeTable[size + 1];
    primeTableCreation(size + 1, primeTable);
    
    // Initialize the hash table with buckets
    Bucket* buckets = (Bucket*)malloc(size * sizeof(Bucket));
    if (buckets == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    initializeBuckets(buckets, size);
    
    int choice, cnt = 0;
    char name[MAX_SIZE];
    
    do {
        printf("\n----- Hash Table Operations -----\n");
        printf("1. Insert a person\n");
        printf("2. Search for a person\n");
        printf("3. Delete a person\n");
        printf("4. Print hash table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                int hashKey = hashKeyGen(name, cnt, size, primeTable);
                insertTable(cnt, hashKey, buckets, name);
                cnt++;
                break;
                
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                Node* result = searchPerson(buckets, size, name, primeTable, cnt);
                if (result != NULL) {
                    printf("Person found! Name: %s, Age: %d\n", result->person_name, result->age);
                } else {
                    printf("Person not found\n");
                }
                break;
                
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                if (deletePerson(buckets, size, name, primeTable, cnt)) {
                    printf("Person deleted successfully\n");
                } else {
                    printf("Person not found\n");
                }
                break;
                
            case 4:
                printTable(buckets, size);
                break;
                
            case 5:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 5);
    
    // Free allocated memory
    freeHashTable(buckets, size);
    free(buckets);
    
    return 0;
}
