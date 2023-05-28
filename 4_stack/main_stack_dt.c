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
#include <string.h>

/***********************************************************************/
// funs declerations
/***********************************************************************/

/**
 * Leetcode #20 
 * isValid: - 
 * @value
 *  
 * return:
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 */
bool isValid(char * s);
void tb_isValid();

/**
 * Leetcode #26
 * removeDuplicates: 
 * @value
 *  
 * return:
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 */
int removeDuplicates(int* nums, int numsSize);
void tb_removeDuplicates();

/**
 * Leetcode #27
 * removeDuplicates: 
 * @value
 *  
 * return:
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 */
int removeElement(int* nums, int numsSize, int val);
void tb_removeElement();

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

/* testbench for tb_isValid */
void tb_isValid()
{
    printf("@frk: test for isValid...\n");

    printf("\n %d",isValid("{{{{}}}}"));

}

/* testbench for tb_isValid */
void tb_removeDuplicates()
{
    printf("@frk: test for removeDuplicates...\n");

    int arr1[10] = {1,1,2,2,3,4,4,4,4,4};    
    int arr2[10] = {1,2,3,4,5,5,5,5,5,5};
    int arr3[10] = {1,1,1,1,1,1,1,1,1,1};

    removeDuplicates(arr1,10);
    
    printf("\n--------------------------");
    removeDuplicates(arr2,10);
    
    printf("\n--------------------------");
    removeDuplicates(arr3,10);

}

/* testbench for tb_isValid */
void tb_removeElement()
{
    printf("@frk: test for removeElement...\n");
    
    int array[7]={1,2,3,4,5,5,5};
    int numsSize = 7;
    int val = 5;

    removeElement(array,numsSize,val);

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

    tb_isValid();
    printf("\n---------------------------------------------------\n");

    tb_removeDuplicates();
    printf("\n---------------------------------------------------\n");

    tb_removeElement();
    printf("\n---------------------------------------------------\n");

    printf("\nPASS-TEST\n");
    return 0;
}

/***********************************************************************/
// funs implements
/***********************************************************************/

/* */
bool isValid(char * s)
{
    int length = strlen(s);

    // Stack to solve the baracket close in order
    int top = -1;
    char stack[length];

    // The function iterates through each character in the string.
    for (int i=0; i<length; i++)
    {
        // If an opening bracket('{', '[', or '('), push onto the stack.
        if( (s[i]=='{') || (s[i]=='[') || (s[i]=='(') )
        {
            stack[++top]=s[i];
        } else 
            {
                /** If a closing bracket is encountered, the function 
                  * checks whether the stack is empty or if the top of 
                  * the stack contains the corresponding opening bracket. 
                 */ 
                if ( s[i]==')' )
                {
                    /** If the stack is empty or the brackets do not match, 
                      * the function immediately returns false.
                     */ 
                    if ( (top == -1) || (stack[top]!='(') ) 
                    {
                        return false;
                    } 
                    /* If the brackets match, the top of the stack is popped. */
                    else {
                        top--;
                    }
                } 
                //
                else if (s[i]==']')
                {
                    //
                    if ( (top == -1) || (stack[top]!='[') ) 
                    {
                        return false;
                    } else {
                        top--;
                    }
                } 
                //
                else if (s[i]=='}')
                {
                    //
                    if ( (top==-1) || (stack[top]!='{') ) 
                    {
                        return false;
                    } else {
                        top--;
                    }
                }
            }
    }
    /**
      * After iterating through all characters, the function checks whether the stack is empty.
      * If it is empty, all brackets were properly closed, and the function returns true.
      * Otherwise, there are unclosed brackets, and the function returns false.
     */
    return top==-1;
}

/* */
int removeDuplicates(int* nums, int numsSize)
{
    /*Stack to save output values*/
    int top = -1;
    int stack[numsSize];
    stack[++top] = nums[0];

    /* iterating through all array */
    for (int i=1; i<numsSize; i++)
    {
        /* if the number is different to stack top */ 
        if (nums[i] != stack[top])
        {
            /* push it into stack */
            stack[++top]=nums[i];
        }
    }

    for (int i=0; i<numsSize; i++)
    {
        /* assign nums to stack when all iteration finished */
        nums[i]=stack[i];
    }
    
    /* The length of the modified array is equal to the index of the top of the stack, plus one. */
    return top+1;
}

/* */
int removeElement(int* nums, int numsSize, int val)
{
    int result = 0;

    if (numsSize == 0)
    {
        nums = NULL;
        result = 0;
        return result;
    }

    /*Stack to save output values*/
    int top = -1;
    int stack[numsSize];

    /* iterating through all array */
    for (int j = 0; j < numsSize; j++ )
    {
        if (nums[j] != val)
        {
            stack[++top] = nums[j];
        }
    }
    result = top + 1;

    for(int i=0; i<numsSize; i++)
    {
        nums[i] = (i <= top) ? stack[i] : 0;
    }

    /*  */
    return result;
}
/***********************************************************************/
