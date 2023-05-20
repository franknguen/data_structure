/***********************************************************************/
/**
    LeetCode 
    Purpose: #94, binary tree inorder traversal
    @author: Frank Nguen
    @date:   0x-05-2023
    https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
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
 * Definition for a binary tree node.
 *
*/
struct TreeNode {
    //
    int val;
    
    //
    struct TreeNode *left;
    
    //
    struct TreeNode *right;
};

/**
 * createNode: - (or newNode)
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
struct TreeNode* createNode(int value);
void tb_createNode();

/**
 * insertNode: -
 * @value
 *  
 * return:
 *
 * to insert node ... 
 * 
 */
void insertNode(struct TreeNode* root, int value);
void tb_insertNode();

/**
 * printTree: -
 * @value
 *  
 * return:
 *
 * to print tree 
 * 
 */
void printTree(struct TreeNode* root, int level);
void tb_printTree();

/**
 * inorderTraversalHelper: -
 * @value
 *  
 * return:
 *
 * to help save value on recursive ... 
 * 
 */
void inorderTraversalHelper(struct TreeNode* root, int* result, int* idx);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
void tb_inorderTraversal();

/**
 * inorderTraversal: -
 * @value
 *  
 * return:
 *
 * There are several ways to traverse a binary tree, including in-order, 
 * pre-order, and post-order traversal. Here's an example of in-order 
 * traversal, which visits the left subtree, then the current node, 
 * then the right subtree:
 */
void inorderTraversal_1(struct TreeNode* root);
void tb_inorderTraversal_1();

/**
 * isSameTree: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q);
void tb_isSameTree();

/**
 * isSymmetric: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isSymmetricHelper(struct TreeNode* left, struct TreeNode* right);
bool isSymmetric(struct TreeNode* root);
void tb_isSymmetric();

/**
 * maxDepth: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
int maxDepth(struct TreeNode* root);
void tb_maxDepth();

/**
 * sortedArrayToBST: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
struct TreeNode* sortedArrayToBSTHelper(int* nums, int start, int end);
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
void tb_sortedArrayToBST();

/**
 * hasPathSum: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool hasPathSum(struct TreeNode* root, int targetSum);
void tb_hasPathSum();

/**
 * minDepth: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
int minDepth(struct TreeNode* root);
void tb_minDepth();

/**
 * isBalanced: -
 * @value
 *  
 * return:
 *
 * to 
 * 
 */
bool isBalanced(struct TreeNode* root);
void tb_isBalanced();

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

/* testbench for creatNode */
void tb_creat_node()
{
    printf("@frk: test for creat_node...\n");

    /* make root*/
    struct TreeNode* root = createNode(2);

    /* insert left/right node*/
    root->left         = createNode(1);
    root->right        = createNode(2);
    root->right->left  = createNode(3);
    root->right->right = createNode(4);
    root->left->left   = createNode(5);

    /*print tree*/   
    printTree(root, 0);
}

/* testbench for insertNode */
void tb_insert_node()
{
    printf("@frk: test for insert_node...\n");

    /* make root*/
    struct TreeNode* root = createNode(7);

    /* insert left/right node*/
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 7);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 9);
    insertNode(root, 13);
    insertNode(root, 10);
    insertNode(root, 11);
    insertNode(root, 12);
    insertNode(root, 8);

    /*print tree*/   
    printTree(root, 0);
}

/* testbench for inorderTravel_1*/
void tb_inorderTraversal_1()
{
    printf("@frk: test for inorderTraversal_1...\n");

    /* make root*/
    struct TreeNode* root = createNode(2);

    /* insert left/right node*/
    root->left         = createNode(1);
    root->right        = createNode(2);
    root->right->left  = createNode(3);
    root->right->right = createNode(4);
    root->left->left   = createNode(5);

    /*print tree*/   
    printTree(root, 0);

    /**/
    inorderTraversal_1(root);
}

/* testbench for inorderTravel*/
void tb_inorderTraversal()
{
    printf("@frk: test for inorderTraversal...\n");

    /* make root*/
    struct TreeNode* root = createNode(2);

    /* insert left/right node*/
    root->left         = createNode(1);
    root->right        = createNode(2);
    root->right->left  = createNode(3);
    root->right->right = createNode(4);
    root->left->left   = createNode(5);

    /*print tree*/   
    printTree(root, 0);

    /**/
    int* result;
    int returnSize;

    result = inorderTraversal(root, &returnSize);

    for(int i=0; i<returnSize; i++)
    {
        printf(" %d,", result[i]);
    }

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

    tb_creat_node();
    printf("\n---------------------------------------------------\n");

    tb_insert_node();
    printf("\n---------------------------------------------------\n");

    tb_inorderTraversal_1();
    printf("\n---------------------------------------------------\n");

    tb_inorderTraversal();
    printf("\n---------------------------------------------------\n");

    printf("\n---------------------------------------------------\n");
    printf("\nPASS-TEST\n");
    return 0;
}

/***********************************************************************/
// funs implements
/***********************************************************************/

/**/
void printTree(struct TreeNode* root, int level) 
{
    //
    if (root != NULL) 
    {
        //
        printTree(root->right, level+1);

        //
        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        //
        printf("%d\n", root->val);
        
        //
        printTree(root->left, level+1);

    }
    else {
        // do nothing
    }
}

/**/
struct TreeNode* createNode(int value) 
{
    /* */
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    /* */
    node->val = value;

    /* */
    node->left = NULL;

    /* */
    node->right = NULL;

    return node;
}

/**/
void insertNode(struct TreeNode* root, int value) 
{
    /* */	
    if (root == NULL) 
    {
        root = createNode(value);
        return;
    }

    /* */
    if (value < root->val) 
    {
        //
        if (root->left == NULL) {
            //
            root->left = createNode(value);
        } else {
            //
            insertNode(root->left, value);
        }
    } else {
        //
        if (root->right == NULL) 
        {
            //
            root->right = createNode(value);
        } else {
            //
            insertNode(root->right, value);
        }
    }
}

/**/
void inorderTraversal_1(struct TreeNode* root) 
{
    //
    if (root != NULL) 
    {
        //
        inorderTraversal_1(root->left);

        //
        printf("%d ", root->val);

        //
        inorderTraversal_1(root->right);

    }
}

/**/
void inorderTraversalHelper(struct TreeNode* root, int* result, int* idx) 
{
    //    
    if (root == NULL) 
        return;
    
    //
    inorderTraversalHelper(root->left, result, idx);
    
    //
    result[*idx] = root->val;
    
    //
    (*idx)++;
    
    //
    inorderTraversalHelper(root->right, result, idx);

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    //    
    int* result = malloc(sizeof(int) * 1000); // assuming the tree has at most 1000 nodes
    
    //
    *returnSize = 0;
    
    //
    inorderTraversalHelper(root, result, returnSize);
    
    return result;
}

/* */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{    
    /* Base case: Both nodes are NULL */
    if (p == NULL && q == NULL) 
        return true;

    /* If one node is NULL and the other is not, or their values are different */
    if (p == NULL || q == NULL || p->val != q->val) 
        return true;

    /* Recursively check the left and right subtrees */
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/* */
bool isSymmetricHelper(struct TreeNode* left, struct TreeNode* right) {
    
    /* Base case: Both nodes are NULL */
    if (left == NULL && right == NULL) 
        return true;

    /* If one node is NULL and the other is not, or their values are different */ 
    if (left == NULL || right == NULL || left->val != right->val) {
        return false;
    }

    /* Recursively check the corresponding nodes on the left and right subtrees */
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) 
{
    //    
    if (root == NULL) 
        return true;

    /* Pass the left and right subtrees of the root to the helper function */
    return isSymmetricHelper(root->left, root->right);
}

/*  */
int maxDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    } 
    else    
    {
        //
        int left_depth  = maxDepth(root->left);
        
        //
        int right_depth = maxDepth(root->right);

        //
        return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);

    }
}

/*  */
struct TreeNode* sortedArrayToBSTHelper(int* nums, int start, int end) 
{
    //    
    if (start > end) 
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    
    struct TreeNode* root = createNode(nums[mid]);

    root->left = sortedArrayToBSTHelper(nums, start, mid - 1);

    root->right = sortedArrayToBSTHelper(nums, mid + 1, end);

    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    //
    if (nums == NULL || numsSize == 0) 
    {
        return NULL;
    }
    //
    return sortedArrayToBSTHelper(nums, 0, numsSize - 1);
}

//
bool hasPathSum(struct TreeNode* root, int targetSum)
{
    // 
    if(root == NULL)
        return false;
    
    // if only have root value
    if( (root->left == NULL) && (root->right == NULL) && (targetSum == root->val) )
        return true;
    else
    // 
        return ( (hasPathSum(root->right,targetSum-root->val)) || (hasPathSum(root->left,targetSum-root->val)) );

}

/**/
 int minDepth(struct TreeNode* root) 
 {
    //
    if (root == NULL) {
        return 0;
    }

    // If the current node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int leftDepth  = INT_MAX;
    
    int rightDepth = INT_MAX;

    // Calculate the minimum depth of the left subtree
    if (root->left != NULL) 
    {
        leftDepth = minDepth(root->left);
    }

    // Calculate the minimum depth of the right subtree
    if (root->right != NULL) 
    {
        rightDepth = minDepth(root->right);
    }

    // Return the minimum depth among the left and right subtrees, plus 1 for the current node
    return (leftDepth < rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

/**/
bool isBalanced(struct TreeNode* root)
{
    //
    if(root == NULL)
    {
        return true;
    } 
    else 
    {

        int left_depth  = maxDepth(root->left);

        int right_depth = maxDepth(root->right);

        int k = (left_depth > right_depth) ? (left_depth - right_depth) : (right_depth - left_depth);
        
        return ( (k < 2) && (isBalanced(root->left)) && (isBalanced(root->right)) ) ? (true) : (false);
    }
}

/***********************************************************************/
