#include <stdio.h>
#include <stdlib.h>

// Define structure for a BST node
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new Node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("Memory error\n");
    return NULL;
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Function to insert a new value into BST using double pointer
void insert(Node **root, int val) {
  if (*root == NULL) {
    // If tree is empty, create new node
    *root = createNode(val);
    return;
  }

  if (val < (*root)->data) {
    // Insert into left subtree
    insert(&((*root)->left), val);
  } else if (val > (*root)->data) {
    // Insert into right subtree
    insert(&((*root)->right), val);
  }
  // If value is equal, do nothing (no duplicates allowed)
}

// Function to search for a value in BST using double pointer
Node *search(Node **root, int val) {
  if (*root == NULL || (*root)->data == val) {
    // Either tree is empty or node is found
    return *root;
  }

  if (val < (*root)->data) {
    // Search in left subtree
    return search(&((*root)->left), val);
  } else {
    // Search in right subtree
    return search(&((*root)->right), val);
  }
}

// Function to find the node with minimum value in a subtree
Node *findMin(Node *root) {
  if (root == NULL)
    return NULL;

  while (root->left != NULL) {
    root = root->left; // Keep going left
  }
  return root;
}

// Function to delete a node with given key using double pointer
void deleteNode(Node **root, int key) {
  if (*root == NULL) {
    // Tree is empty
    return;
  }

  if (key < (*root)->data) {
    // Key is smaller, go left
    deleteNode(&((*root)->left), key);
  } else if (key > (*root)->data) {
    // Key is larger, go right
    deleteNode(&((*root)->right), key);
  } else {
    // Node found
    Node *temp;
    if ((*root)->left == NULL && (*root)->right == NULL) {
      // Case 1: No children
      free(*root);
      *root = NULL;
    } else if ((*root)->left == NULL) {
      // Case 2: Only right child
      temp = (*root)->right;
      free(*root);
      *root = temp;
    } else if ((*root)->right == NULL) {
      // Case 2: Only left child
      temp = (*root)->left;
      free(*root);
      *root = temp;
    } else {
      // Case 3: Two children
      Node *successor = findMin((*root)->right);
      (*root)->data = successor->data;                // Copy successor's value
      deleteNode(&((*root)->right), successor->data); // Delete successor
    }
  }
}

// Function to perform inorder traversal (Left -> Root -> Right)
void inorder(Node *root) {
  if (root == NULL)
    return;

  inorder(root->left);       // Visit left subtree
  printf("%d ", root->data); // Visit current node
  inorder(root->right);      // Visit right subtree
}

// Function to free all nodes of the BST using double pointer
void freeTree(Node **root) {
  if (*root == NULL)
    return;

  freeTree(&((*root)->left));  // Free left subtree
  freeTree(&((*root)->right)); // Free right subtree
  free(*root);                 // Free current node
  *root = NULL;                // Set pointer to NULL after freeing
}

// Main function to demonstrate the operations
int main() {
  Node *root = NULL; // Start with an empty tree

  // Insert nodes into BST
  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 70);
  insert(&root, 20);
  insert(&root, 40);
  insert(&root, 60);
  insert(&root, 80);
  insert(&root, 65);

  printf("Inorder traversal after inserts: ");
  inorder(root);
  printf("\n");

  // Search for a node
  Node *found = search(&root, 60);
  if (found != NULL)
    printf("Found: %d\n", found->data);
  else
    printf("Not found!\n");

  // Delete a node
  deleteNode(&root, 70); // Delete root node

  printf("Inorder traversal after deletion: ");
  inorder(root);
  printf("\n");

  // Free all allocated memory
  freeTree(&root);

  return 0;
}
