# Data-Structures-assignment-
CODE SHOWING ARRAY
#include <stdio.h>
int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array elements: \n");
    for (int i = 0; i < length; i++) {
        printf("Element at index %d: %d\n", i, numbers[i]);
    }
    return 0;
}
CODE SHOWING A LINKED LIST
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void printList(struct Node* n) {
    while (n != NULL) {
        printf(" %d ->", n->data);
        n = n->next;
    }
    printf(" NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    
    head->data = 1; 
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL; // End of the list

    printf("Linked List Path:\n");
    printList(head);

    return 0;
}
CODE SHOWING A QUEUE 
#include <stdio.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;


void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue is Full!");
    else {
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}


void dequeue() {
    if (front == -1)
        printf("\nQueue is Empty!");
    else {
        printf("\nDeleted -> %d", items[front]);
        front++;
        if (front > rear) front = rear = -1; // Reset queue if empty
    }
}


void display() {
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", items[i]);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue();
    display();

    return 0;
}
CODE SHOWING A STACK
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed: %d\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped: %d\n", stack[top]);
        top--;
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current Stack (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}
CODE SHOWING A TREE 
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void printInOrder(struct Node* root) {
    if (root == NULL) return;

    printInOrder(root->left);       // Visit left subtree
    printf("%d -> ", root->data);   // Visit current node
    printInOrder(root->right);      // Visit right subtree
}

int main() {
    
    struct Node* root = createNode(1);

    
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order Traversal of the Tree:\n");
    printInOrder(root);
    printf("NULL\n");

    return 0;
}
CODE SHOWING A GRAPH
#include <stdio.h>

#define V 4 


void init(int arr[V][V]) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[V][V], int i, int j) {
    arr[i][j] = 1;
    arr[j][i] = 1; // Because it's undirected
}

void printMatrix(int arr[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[V][V];

    init(adjMatrix);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 3);

    printf("Adjacency Matrix Representation:\n");
    printMatrix(adjMatrix);

    return 0;
}


