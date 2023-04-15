/**
    Code for https://journaldev.com article
    Purpose: A Depth First Search Implementation
    @author: Vijay Ramachandran
    @date: 14-02-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph Graph;

typedef struct Node Node;

struct Node {
    // To represent the linked list node.
    // Contains the vertex index
    int vertex;
    // Vertex Key
    int key;
    // And a pointer to the next element in the linked list
    Node* next;
};

struct Graph {
    // Key List
    int* key_list;
    // Number of vertices
    int v;
    // Array of Adjacency Lists
    Node** adj_lists;
};

// Define the Stack here
typedef struct StackNode StackNode;

struct StackNode{
    // Stack of integers
    int data;
    StackNode* next;
};

int is_empty(StackNode* stack) {
    // Check if stack is empty
    if (!stack)
        return 1;
    return 0;
}

StackNode* push(StackNode* stack, int data) {
    // Pushes the data into the stack
    StackNode* node = (StackNode*) malloc (sizeof(StackNode));
    StackNode* temp = stack;
    node->data = data;
    node->next = temp;
    stack = node;
    return stack;
}

StackNode* pop(StackNode* stack) {
    // Pops the head of the stack
    if (!stack)
        return NULL;
    StackNode* temp = stack;
    stack = stack->next;
    temp->next = NULL;
    free(temp);
    return stack;
}

int top(StackNode* stack) {
    // Return the top of the stack
    if (!stack)
        return INT_MIN;
    return stack->data;
}

StackNode* init_stack(int data) {
    // Initializes the stack
    StackNode* stack = (StackNode*) malloc (sizeof(StackNode));
    stack->data = data;
    stack->next = NULL;
    return stack;
}

void free_stack(StackNode* stack) {
    // Free the stack
    if (!stack)
        return;
    StackNode* temp = stack;
    stack = stack->next;
    temp->next = NULL;
    free(temp);
    free_stack(stack);
}

void print_stack(StackNode* stack) {
    if (!stack)
        return;
    StackNode* temp = stack;
    printf("Stack: \n");
    while(temp) {
        printf("Data: %d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Adjacency Lists for the Graph
Node** init_adjacency_lists(Graph g) {
    // Initializes an adjacency matrix for the graph
    if (g.adj_lists)
        return g.adj_lists;
    // Allocates memory for the lists
    // There is a list for every vertex in the graph
    // which means there are g.v adjacent lists
    Node** adj_lists = (Node**) calloc (g.v,  sizeof(Node*));

    // Set them to NULL initially
    for (int i = 0; i < g.v; i++)
        adj_lists[i] = NULL;
    
    printf("Initialized Adjacency Lists!\n");
    return adj_lists;
}

void free_list(Node* list) {
    // Frees all nodes in the list, headed by 'list'
    Node* temp = list;
    while(temp) {
        Node* rm_node = temp;
        temp = rm_node->next;
        rm_node->next = NULL;
        free(rm_node);
    }
}

void free_adj_lists(Graph g) {
    // Free the adjacency matrix
    if (!g.adj_lists)
        return;
    for (int i=0; i<g.v; i++)
        free_list(g.adj_lists[i]);
    free(g.adj_lists);
}

void print_list(Node* list) {
    // Prints the linked list
    Node* temp = list;
    while(temp) {
        printf("Node: %d, Key: %d -> ", temp->vertex, temp->key);
        temp = temp->next;
    }
    printf("\n");
}

Node* create_node(int vertex, int key) {
    // Creates a LinkedList node to hold the vertex
    Node* node = (Node*) calloc (1, sizeof(Node));
    node->next = NULL;
    node->vertex = vertex;
    node->key = key;
    return node;
}

void add_edge(Graph g, int i, int j) {
    // Adds an edge connecting two vertices i and j
    if (!g.adj_lists) {
        fprintf(stderr, "Adjacency Lists not initialized!\n");
        exit(1);
    }
    
    else if (i > g.v || j > g.v) {
        fprintf(stderr, "Invalid Vertex Number\n");
        exit(1);
    }

    // Create the new node in the souce vertex
    // adjacency list and add the destination
    // vertex to it
    
    // Create a node containing the dst vertex index
    Node* node = create_node(j, g.key_list[j-1]);

    // Insert at the source list
    // Let's insert at the top, since it doesn't
    // matter whether we insert at the head or not
    node->next = g.adj_lists[i-1];
    // Make the new node as the head
    g.adj_lists[i-1] = node;
}

void remove_edge(Graph g, int i, int j) {
    // Sets the edge from i to j as zero
    if (!g.adj_lists) {
        fprintf(stderr, "Adjacency Lists not initialized!\n");
        exit(1);
    }
    // Search for vertex j in i's adjacency list
    Node* temp = g.adj_lists[i-1];
    if (!temp) {
        return;
    }
    if (!(temp->next)) {
        if (temp->vertex == j) {
            free(temp);
            g.adj_lists[i-1] = NULL;
        }
        return;
    }
    while (temp->next) {
        if (temp->vertex == j) {
            // We have found an edge! Remove this element.
            Node* rm_node = temp;
            temp->next = rm_node->next;
            rm_node->next = NULL;
            free(rm_node);
            return;
        }
        temp = temp->next;
    }
    // No element found :(
    return;
}

int check_if_exists(Graph g, int i, int j) {
    // Checks if there is an edge from vertex i to j
    if (!g.adj_lists) {
        fprintf(stderr, "Adjacency Lists not initialized!\n");
        exit(1);
    }
    else if (i > g.v || j > g.v) {
        fprintf(stderr, "Invalid Vertex Number\n");
        return 0;
    }
    
    // Search for vertex j in i's adjacency list
    Node* temp = g.adj_lists[i-1];
    if (!temp) {
        return 0;
    }
    if (!(temp->next)) {
        if (temp->vertex == j) {
            return 1;
        }
        return 0;
    }
    while (temp->next) {
        if (temp->vertex == j) {
            // We have found an edge! Remove this element.
            return 1;
        }
        temp = temp->next;
    }
    // No element found :(
    return 0;
}

int DFS_recursive(Graph g, int start_vertex, int key, StackNode** stack, int* visited_list, int start) {
    // Recursive DFS function that is used to perform DFS()
    if (start)
        *stack = push(*stack, g.key_list[start_vertex-1]);

    printf("Current Node: key: %d\n", g.key_list[start_vertex - 1]);
    // Mark the current node as visited
    visited_list[start_vertex - 1] = 1;

    // While the stack is not empty
    while (!is_empty(*stack)) {
        if (g.key_list[start_vertex - 1] == key) {
            return 1;
        }
        else {
            // Not found. Go to the next node
            Node* node = g.adj_lists[start_vertex - 1];
            if (!node) {
                // Dead End. Go back after popping current node
                *stack = pop(*stack);
            }

            while (node) {
                // If any of it's neighbours are not visited
                if(visited_list[node->vertex - 1] == 0) {
                    // Go to that node and do a DFS from that node
                    if (DFS_recursive(g, node->vertex, key, stack, visited_list, 1) == 1)
                        return 1;
                    else {
                        // Pop the recently visited neighbour from the stack
                        *stack = pop(*stack);
                    }
                }
                node = node->next;
            }
        }
    }

    return 0;  
}

int DFS(Graph g, int start_vertex, int key) {
    // Performs a DFS on the Graph from start_vertex
    // and returns 1 if the destination key is found
    printf("Start Vertex: %d, Key: %d\n", start_vertex, g.key_list[start_vertex - 1]);
    if (g.key_list[start_vertex-1] == key) {
        return 1;
    }
    
    // Keep a visited list of nodes
    int* visited_list = (int*) calloc (g.v, sizeof(int));

    // Initialize the Stack
    StackNode* stack = init_stack(g.key_list[start_vertex-1]);

    // Perform the DFS
    int ret_val = DFS_recursive(g, start_vertex, key, &stack, visited_list, 0);

    // Free Stuff and exit
    free_stack(stack);
    free(visited_list);
    return ret_val;
}

void dfs_print(Graph g, int src, int dst) {
    // Find the vertex for the src key
    int start = -1;
    for (int i=0; i<g.v; i++) {
        if (g.key_list[i] == src)
            start = i + 1;
    } 
    if (start == -1) {
        fprintf(stderr, "Error: Key %d not found\n", src);
        return;
    }
    printf("Performing DFS on the Graph...\n");
    int ret_val = DFS(g, start, dst);
    if (ret_val == 1)
        printf("Key: %d is found!\n", dst);
    else
        printf("Key: %d is not found.\n", dst);
}

int main() {
    // Graph with 6 vertices
    int vertex_list[] = {6, 2, 5, 14, 7, 1};
    Graph g = {vertex_list, 6, NULL};
    printf("Created a Graph Structure with %d vertices\n", g.v);
    g.adj_lists = init_adjacency_lists(g);

    // Let's connect the 6 vertices using edges
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    add_edge(g, 2, 5);
    add_edge(g, 3, 6);
    add_edge(g, 6, 5);

    // Print the Adjacency Lists
    for (int i=0; i<g.v; i++) {
        printf("Vertex: %d , Key: %d => ", i+1, g.key_list[i]);
        print_list(g.adj_lists[i]);
    }

    // Print a Depth First Search from 6 to 14
    printf("\n");
    dfs_print(g, 6, 7);
    printf("\n");
    dfs_print(g, 6, 8);
    printf("\n");
    dfs_print(g, 6, 14);
    printf("\n");
    free_adj_lists(g);
    return 0;
}