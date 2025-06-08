#include <stdio.h>
#include <stdlib.h>

// struct for Tree
struct Tree
{
	int data;          // to store the data
	struct Tree *left; // left and right pointers
	struct Tree *right;
};

// struct from Queue
struct Queue
{
	struct Tree *q[100];
	int front;
	int last;
};

// intiliase queue data structure
void initQueue(struct Queue *q)
{
	q->front = -1;
	q->last = -1;
}
// isEmpty()
int isEmpty(struct Queue *q)
{
	return q->front == -1;
}
// isFull()
int isFull(struct Queue *q)
{
	return q->last == 99;
}
// enqueue
void enqueue(struct Queue *q, struct Tree *node)
{
	// edge case : Check if its full
	if (isFull(q))
	{
		printf("Queue is Full.\n");
		return;
	}
	// for first node.
	if (isEmpty(q))
	{
		q->front = 0;
	}
	q->last++;
	q->q[q->last] = node;
}
// dequeue
void dequeue(struct Queue *q)
{
	if (isEmpty(q))
	{
		printf("Queue is Empty.\n");
		return;
	}

	q->front++;

	// Reset if queue becomes empty after this dequeue
	if (q->front > q->last)
	{
		q->front = -1;
		q->last = -1;
	}
}

// Function list

struct Tree *createNode(int x)
{
	struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
	// edge case : if new node is empty  we return null
	if (newNode == NULL)
	{
		printf("Memory Allocation failed.\n");
		return NULL;
	}
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// Use single pointer if you just read/traverse or modify nodes deeper in the tree.
// Use double pointer if you want to create or reassign the root node (or any pointer you want to change outside the function).
void insertNode(struct Tree **root, int x, struct Queue *q)
{
	struct Tree *newNode = createNode(x);

	if (*root == NULL)
	{
		*root = newNode;
		enqueue(q, newNode);
		return;
	}

	while (!isEmpty(q))
	{
		// This takes the reference of front node in queue
		struct Tree *temp = q->q[q->front];

		if (temp->left == NULL)
		{
			// we add in left and enqueue it and reutrn same for right
			temp->left = newNode;
			enqueue(q, newNode);
			return;
		}
		else if (temp->right == NULL)
		{
			temp->right = newNode;
			enqueue(q, newNode);
			return;
		}
		else
		{
			dequeue(q);
		}
	}
}

void preOPrderTraversal(struct Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preOPrderTraversal(root->left);
	preOPrderTraversal(root->right);
}
void postOrderTraversal(struct Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%d ", root->data);
}
void inOrderTraversal(struct Tree *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrderTraversal(root->left);
	printf("%d ", root->data);
	inOrderTraversal(root->right);
}
void LevelOrder(struct Tree *root, struct Queue *q)
{
	if (root == NULL)
	{
		printf("Tree is Empty\n");
		return;
	}

	initQueue(q);
	enqueue(q, root);

	while (!isEmpty(q))
	{
		struct Tree *temp = q->q[q->front];
		dequeue(q);
		printf("%d ", temp->data); // 👈 print the node's data

		if (temp->left != NULL)
			enqueue(q, temp->left);
		if (temp->right != NULL)
			enqueue(q, temp->right);
	}
}

int search(int val,struct Tree* root) {
	// will recursively search for elements
	if(root == NULL){
		return 0;
	}
	if(root->data == val){
		printf("Value has been found\n");
		return 1;
	}

	// Search in left and right subtree
	int leftSearch = search(val, root->left);
	if (leftSearch) return 1;  // If found in left, return early

	int rightSearch = search(val, root->right);
	return rightSearch;

}
struct Tree *findMax(struct Tree *root) {
	if (root == NULL) {
		return NULL;
	}

	struct Queue q;
	initQueue(&q);
	enqueue(&q, root);

	struct Tree *maxNode = root;

	while (!isEmpty(&q)) {
		struct Tree *temp = q.q[q.front];
		dequeue(&q);

		if (temp->data > maxNode->data) {
			maxNode = temp;
		}

		if (temp->left != NULL) enqueue(&q, temp->left);
		if (temp->right != NULL) enqueue(&q, temp->right);
	}

	return maxNode;
}

struct Tree *findMin(struct Tree *root) {
	if (root == NULL) {
		return NULL;
	}

	struct Queue q;
	initQueue(&q);
	enqueue(&q, root);

	struct Tree *minNode = root;

	while (!isEmpty(&q)) {
		struct Tree *temp = q.q[q.front];
		dequeue(&q);

		if (temp->data < minNode->data) {
			minNode = temp;
		}

		if (temp->left != NULL) enqueue(&q, temp->left);
		if (temp->right != NULL) enqueue(&q, temp->right);
	}

	return minNode;
}


int countNode(struct Tree *root) {
	if (root == NULL)
		return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}
int height(struct Tree *root) {
	if (root == NULL)
		return 0;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int isFullBT(struct Tree *root) {
	if (root == NULL)
		return 1;

	if ((root->left == NULL && root->right == NULL))
		return 1;

	if (root->left && root->right)
		return isFullBT(root->left) && isFullBT(root->right);

	return 0;
}

int getDepth(struct Tree *node) {
	int d = 0;
	while (node != NULL) {
		d++;
		node = node->left;
	}
	return d;
}

int isPerfectBTHelper(struct Tree *root, int depth, int level) {
	if (root == NULL)
		return 1;

	// Check leaf node
	if (root->left == NULL && root->right == NULL)
		return (depth == level + 1);

	// Check if it's not a full node
	if (root->left == NULL || root->right == NULL)
		return 0;

	return isPerfectBTHelper(root->left, depth, level + 1) &&
		isPerfectBTHelper(root->right, depth, level + 1);
}

int isPerfectBT(struct Tree *root) {
	int d = getDepth(root);
	return isPerfectBTHelper(root, d, 0);
}

int main(void)
{
	struct Tree *Node = NULL;
	struct Queue q,q1;
	initQueue(&q);
	int n;
	int i = 1;
	scanf("%d", &n);
	while (n--)
	{
		printf("Insert Node number : %d ", i);
		int data;
		scanf("%d", &data);
		insertNode(&Node, data, &q);
		i += 1;
	}
	inOrderTraversal(Node);
	printf("\n");
	preOPrderTraversal(Node);
	printf("\n");
	postOrderTraversal(Node);
	printf("\n");
	LevelOrder(Node,&q1);
	printf("\n");
	int s = search(5,Node);
	printf("Total nodes: %d\n", countNode(Node));
	printf("Height of tree: %d\n", height(Node));
	printf("Is Full Binary Tree: %s\n", isFullBT(Node) ? "Yes" : "No");
	printf("Is Perfect Binary Tree: %s\n", isPerfectBT(Node) ? "Yes" : "No");
	return 0;
}
