/***********************************************************************/
/**
    LeetCode 
    Purpose: Linked list data structure
    @author: Frank Nguen
    @date:   0x-05-2023
*/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/***********************************************************************/
// funs declerations
/***********************************************************************/

/**
 * Definition for a list node.
 *
*/
struct ListNode {
    // value stores in List node
    int val;
    
    // pointer to next List node
    struct ListNode *next;

};

/**
 * printNode: - 
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
void printNode(struct ListNode* root);

/**
 * newListNode: - (or newNode)
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct ListNode* newListNode(int value);
void tb_newListNode();

/**
 * Leetcode #2
 * addTwoNumbers:
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void tb_addTwoNumbers();

/**
 * Leetcode #21
 * mergeTwoLists:
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
void tb_mergeTwoLists();

/**
 * Leetcode #26
 * deleteDuplicates:
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct ListNode* deleteDuplicates(struct ListNode* head);
void tb_deleteDuplicates();

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

/* testbench for newListNode */
void tb_newListNode()
{
    printf("@frk: test for creat_node...\n");

    struct ListNode* head_a = NULL; 
     
    head_a             = newListNode(1); 
    head_a->next       = newListNode(5); 
    head_a->next->next = newListNode(6); 

    printNode(head_a); 

}

/* testbench for addTwoNumbers */
void tb_addTwoNumbers()
{
    printf("@frk: test for addTwoNumbers...\n");

    struct ListNode* head_a = NULL; 
    struct ListNode* head_b = NULL; 
    struct ListNode* head_j = NULL; 
     
    head_a             = newListNode(1); 
    head_a->next       = newListNode(5); 
    head_a->next->next = newListNode(6); 

    head_b                               = newListNode(2); 
    head_b->next                         = newListNode(3); 

    head_j = addTwoNumbers(head_a, head_b); 

    printNode(head_a);
    printf("\n ----------");
    printNode(head_b); 
    printf("\n ----------");
    printNode(head_j); 

}

/* testbench for mergeTwoLists */
void tb_mergeTwoLists()
{
    printf("@frk: test for mergeTwoLists...\n");

    struct ListNode* head_a = NULL; 
    struct ListNode* head_b = NULL; 
    struct ListNode* head_j = NULL; 
     
    head_a             = newListNode(1); 
    head_a->next       = newListNode(5); 
    head_a->next->next = newListNode(6); 

    head_b                               = newListNode(2); 
    head_b->next                         = newListNode(3); 

    head_j = mergeTwoLists(head_a, head_b); 

    printNode(head_a);
    printf("\n ----------");
    printNode(head_b); 
    printf("\n ----------");
    printNode(head_j); 

}

void tb_deleteDuplicates()
{
    printf("@frk: test for deleteDuplicates...\n");

    struct ListNode* head_a = NULL; 
    struct ListNode* head_b = NULL; 
     
    head_a                   = newListNode(1); 
    head_a->next             = newListNode(5); 
    head_a->next->next       = newListNode(5);
    head_a->next->next->next = newListNode(6); 

    printNode(head_a);
    printf("\n ----------");

    head_b = deleteDuplicates(head_a);

    printNode(head_b); 
    printf("\n ----------");

}

/***********************************************************************/
/**
 * main - main program, test case
 * problems: convert a string into zigzag string
 */
/***********************************************************************/

int main()
{

    printf("@frk: start testing ...................................");
    printf("\n---------------------------------------------------\n");

    tb_newListNode();
    printf("\n---------------------------------------------------\n");

    tb_addTwoNumbers();
    printf("\n---------------------------------------------------\n");

    tb_mergeTwoLists();
    printf("\n---------------------------------------------------\n");

    tb_deleteDuplicates();
    printf("\n---------------------------------------------------\n");

    printf("\nPASS-TEST\n");
    return 0;
}

/***********************************************************************/
// funs implements
/***********************************************************************/

/* */
void printNode(struct ListNode* root)
{
    // loop continues untill list == NULL
    while(root != NULL)
    {  
        // print value of current node
        printf("\nfrk-printNode: List: %d", root->val);  
        
        // move to next node 
        root = root->next;

    }  
}

/* */
struct ListNode* newListNode(int value)
{
    // allocate memory for a new ListNode
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));  
    
    // set the value of ListNode to given value
    result->val  = value;  
    
    // set the next pointer of ListNode to NULL
    result->next = NULL;  
    
    return result;  
}

/* */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    // create a new ListNode to store the result, initialized with 0
    struct ListNode *head_result = newListNode(0);
    
    // create a pointer to the current position in the result list
    struct ListNode* head_cur = head_result; 
    
    //
    int sum;
    int rem = 0; 
    int i = 0;
    
    // Iterate until both input lists and the remainder are exhausted
    while ( (l1 != NULL) || (l2 != NULL) || (rem != 0)) 
    {
        // Calculate the sum of the corresponding nodes and the remainder
        sum = rem + ((l1 == NULL) ? 0 : (l1->val)) + ((l2 == NULL) ? 0 : (l2->val)); 
        rem = sum/10; 
        sum %= 10; 
        
        // Create a new ListNode for the current digit sum and attach it to the result list
        head_cur->next = newListNode(sum); 
        
        // Move the current position pointer to the newly created ListNode
        head_cur = head_cur->next; 
        
        // Move to the next nodes in the input lists, or set to 0 if reached the end
        l1 = (l1 == NULL) ? 0 : (l1->next); 
        l2 = (l2 == NULL) ? 0 : (l2->next); 
        
    }  
    
    // Return the result list, skipping the initial 0 node
    return head_result->next; 
}

/* */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    // Create a new ListNode to store the merged list, initialized with 0
    struct ListNode* head_result = newListNode(0); 
    
    // Create a pointer to the current position in the merged list
    struct ListNode* head_cur    = head_result;  
    
    int i = 0; 

    // Iterate until either of the input lists is exhausted
    while( (list1!=NULL) && (list2!=NULL) ){ 
        
        // Check which value is smaller and add it to the merged list
        if (list1->val < list2->val)
        { 
            // Create a new ListNode with the value from list1 and attach it to the merged list
            head_cur->next = newListNode(list1->val); 
            
            // Move to the next node in list1
            list1 = list1->next; 

        } else { 
            // Create a new ListNode with the value from list2 and attach it to the merged list
            head_cur->next = newListNode(list2->val); 
            
            // Move to the next node in list2
            list2 = list2->next; 
        } 

        // Increment the position counter and move the current position pointer
        i++; 
        head_cur = head_cur->next; 
    }; 

    // Attach the remaining nodes from either list1 or list2 to the merged list
    head_cur->next = (list1 == NULL) ? (list2) : (list1);     

    // Return the merged list, skipping the initial 0 node
    return head_result->next; 

}

/**/
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    /* check wheather input list is empty or only one node */
    if( (head == NULL) || (head->next) == NULL )
    {
        return head;
    }

    /* initial a pointer to track current node */
    struct ListNode* cur = head;

    /* travel the linked list */
    while( cur->next != NULL)
    {
        /**/
        if(cur->val == cur->next->val)
        {
            /**/
            struct ListNode* tem = cur->next;
            cur->next = tem->next;
            free(tem);
        } else {
            /**/
            cur = cur->next;
        }
    }

    /**/
    return head;
}


/***********************************************************************/
