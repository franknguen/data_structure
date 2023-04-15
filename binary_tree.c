/**
    Code for https://journaldev.com article
    Purpose: Performs Level Order Traversal across a Binary Tree
    @author: Vijay Ramachandran
    @date: 28-01-2020
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue_node Queue_node;
typedef struct Queue Queue;

// Define the Tree Node here
struct Node {
    int value;
    // Pointers to the left and right children
    Node* left, *right;
};


// Define the Queue Node here
struct Queue_node {
    Node* data;
    Queue_node* next;
};

// Define the complete Queue Structure here
struct Queue {
    Queue_node* front, *rear; 
    int count;
};


Queue* init_queue() {
    // Creates a new Queue
    Queue* queue = (Queue*) malloc (sizeof(Queue));
    if (queue) {
        queue->front = queue->rear = NULL;
        queue->count = 0;
    }
    return queue;
}

void enqueue(Queue* queue, Node* data) {
    // Adds the node to the queue
    Queue_node* new_node = (Queue_node*) malloc (sizeof(Queue_node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->count == 0) {
        queue->front = new_node;
    }
    else {
        queue->rear->next = new_node;
    }

    queue->count ++;
    queue->rear = new_node;
    return;
}

Node* dequeue(Queue* queue) {
    // Pops the first node from the queue
    if (queue->count == 0)
        return NULL;
    Node* data = queue->front->data;
    if (queue->front->next) {
        queue->front = queue->front->next;
        queue->count --;
    }
    else {
        queue->front = NULL;
        queue->rear = NULL;
        queue->count --;
    }
    return data;
}

void print_queue(Queue* queue) {
    if (queue->count == 0)
        return;
    Queue_node* temp = queue->front;
    while (temp) {
        printf("%d -> ", temp->data->value);
        temp = temp->next;
    }
    printf("\n");
}

void free_queue(Queue* queue) {
    Queue_node* temp = queue->front;
    if (queue->count == 0)
        return;
    while(temp) {
        Queue_node* del_node = temp;
        temp = temp->next;
        del_node->next = NULL;
        free(del_node);
    }
}


Node* init_tree(int data) {
    // Creates the tree and returns the
    // root node
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}

void update_node(Node* node, int data) {
    // Updates the new value of node to be data
    if (node)
        node->value = data;
}

Node* create_node(int data) {
    // Creates a new node
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}


void insert_node(Node* root, Node* node) {
    // Inserts node into a tree having 
    // root as the root node
    
    // Strategy : Add the nodes to a queue
    // and check if children exists
    // If not, insert to the node. Otherwise,
    // pop the node from the queue and check
    // until the queue is empty
    Queue* q = init_queue();
    enqueue(q, root);
    while(q->count > 0) {
        Node* temp = dequeue(q);
        if (!temp->left && !temp->right) {
            // If this is a leaf node, insert to the left
            temp->left = node;
            free_queue(q);
            return;
        }
        else if (!temp->left) {
            // Insert on it's left
            temp->left = node;
            free_queue(q);
            return;
        }
        else if (!temp->right) {
            // Insert on it's right
            temp->right = node;
            free_queue(q);
            return;
        }
        else {
            // This is not a leaf node.
            // Push both children to the queue
            // and go to the next iteration
            enqueue(q, temp->left); 
            enqueue(q, temp->right); 
        }
    }
    
}

void print_tree(Node* root) {
    if (!root)
        return;
    print_tree(root->left);
    printf("%d -> ", root->value);
    print_tree(root->right);
}

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void print_level(Node* root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no
    
    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        printf("%d -> ", root->value);
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}

void print_tree_level_order(Node* root) {
    if (!root)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        printf("Level %d: ", i);
        print_level(root, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    printf("\n");
}

int main() {
    // Program to demonstrate Level Order Traversal

    // Create the root node having a value of 10
    Node* root = init_tree(10);
    
    // Insert nodes onto the tree
    insert_node(root, create_node(20));
    insert_node(root, create_node(30));
    insert_node(root, create_node(40));
    insert_node(root, create_node(50));
    
    // Level Order Traversal
    print_tree_level_order(root);

    // Free the tree!
    free_tree(root);
    return 0;
}