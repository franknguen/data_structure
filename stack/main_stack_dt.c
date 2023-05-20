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

    // printf("\n@frk-dbg: length=%d", length);
    for (int i=0; i<length; i++){
        if((s[i]=='{')||(s[i]=='[')||(s[i]=='('))
        {
            stack[++top]=s[i];
        } else 
        {
            if (s[i]==')')
            {
                if ((top == -1)||(stack[top]!='(')) {
                    return false;
                } else {
                    top--;
                }
            } else if (s[i]==']')
            {
                if ((top == -1)||(stack[top]!='[')) {
                    return false;
                } else {
                    top--;
                }
            } else if (s[i]=='}')
            {
                if ((top == -1)||(stack[top]!='{')) {
                    return false;
                } else {
                    top--;
                }
            }
        }
    }
    return top==-1;
}

/* */
int removeDuplicates(int* nums, int numsSize){
    int stack[numsSize];
    int top = -1;
    // printf("\n@frk-dbg: nums[0]=%d",nums[0]);
    stack[++top] = nums[0];

    // for (int i=0; i<numsSize; i++)
    // {
    //     printf("\n@frk-dbg: nums[%d]=%d",i,nums[i]);
    // }
    int k;
    for (int i=1; i<numsSize; i++)
    {
        // printf("\n@frk-dbg: i=%d",i);
        if (nums[i] != stack[top]){
            stack[++top]=nums[i];
        }
    }
    // printf("\n@frk-dbg: top=%d",top);
    for (int i=0; i<numsSize; i++)
    {
        // printf("\n@frk-dbg: stack[%d]=%d",i,stack[i]);
        nums[i]=stack[i];
    }    
    return top+1;
}

/* */
int removeElement(int* nums, int numsSize, int val){
    int result = 0;

    if (numsSize == 0){
        nums = NULL;
        result = 0;
        return result;
    }

    // // /*Test array only*/
    // for(int i=0; i<numsSize; i++){
    //     printf("\n@frk-dbg: Array[%d]=[%d]",i,nums[i]);
    // }

    /*Stack to save output values*/
    int top = -1;
    int stack[numsSize];
    // printf("\n--------------------------------------");    

    for (int j = 0; j < numsSize; j++ ){
        if (nums[j] != val){
            // printf("\n@frk-dbg: nums[%d]=[%d]",j,nums[j]);
            stack[++top] = nums[j];
            // printf("\n@frk-dbg: stack[%d]=[%d]",top,stack[top]);
        }
    }
    result = top + 1;
    //nums = stack;
    // printf("\n--------------------------------------");    

    for(int i=0; i<numsSize; i++){
        nums[i] = (i <= top) ? stack[i] : 0;
        // printf("\n@frk-dbg: num[%d]=[%d]",i,nums[i]);
    }
    // printf("\n--------------------------------------");    

    /*Result stores here*/
    // printf("\n@frk-dbg: result=[%d]", result);
    return result;
}
/***********************************************************************/
