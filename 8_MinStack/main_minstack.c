/***********************************************************************/
/**
  *  LeetCode 
  *  Purpose: Min stack data structure Leetcode 155
  *           Design a stack that supports push, pop, top, 
  *  and retrieving the minimum element in constant time.
  *  @author: Frank Nguen
  *  @date:   0x-06-2023
*/
/***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_STACK_SIZE 30000

/***********************************************************************/
// funs declerations
/***********************************************************************/
/**
 * Definition for a list node.
 *
*/
typedef struct 
{
    int  top;    // index
    int* stack;  // stack
} MinStack;      // typedef
#if 1
/**
 * minStackCreate: -  initializes the stack object.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
MinStack* minStackCreate();

/**
 * minStackPush: -  pushes the element val onto the stack.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
void minStackPush(MinStack* obj, int val);

/**
 * minStackPop: -  removes the element on the top of the stack.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
void minStackPop(MinStack* obj);

/**
 * minStackTop: -  gets the top element of the stack.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
int minStackTop(MinStack* obj);

/**
 * minStackGetMin: -  retrieves the minimum element in the stack.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
int minStackGetMin(MinStack* obj);

/**
 * minStackFree: -  initializes the stack object.
 * @value
 *  
 * return:
 *
 * to create or new node
 * 
 */
void minStackFree(MinStack* obj);

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/
/* testbench for minStackCreate() */
void tb_minStackCreate()
{
    printf("\n Testing for minStackCreate():");

    MinStack* n_MinStack = minStackCreate();

    printf("\n %d", n_MinStack->top);

    return;
}

/* testbench for minStackPush() */
void tb_minStackPush()
{
    printf("\n Testing for minStackPush():");

    MinStack* n_MinStack = minStackCreate();
    printf("\n I just created a minStack:");
    printf("\n top=[%d]", n_MinStack->top);

    minStackPush(n_MinStack, 1);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top-1]);

    return;
}

/* testbench for main() */
void tb_full()
{
    printf("\n Testing for minStackPush():");

    MinStack* n_MinStack = minStackCreate();
    printf("\n I just created a minStack:");
    printf("\n top=[%d]", n_MinStack->top);

    minStackPush(n_MinStack, 5);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    minStackPush(n_MinStack, 3);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    minStackPush(n_MinStack, 2);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    minStackPush(n_MinStack, 4);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    minStackPush(n_MinStack, 6);
    printf("\n I just pushed into the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    minStackPop(n_MinStack);
    printf("\n I just poped from the minStack:");
    printf("\n top=[%d]", n_MinStack->top);
    printf("\n top val=[%d]", n_MinStack->stack[n_MinStack->top]);

    printf("\n get min of minStack:");
    printf("\n stack min val=[%d]", minStackGetMin(n_MinStack));

    minStackFree(n_MinStack);
    printf("\n I just free minStack:");

    return;
}

/***********************************************************************/
/**
 * main - main program, test case
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * 
 * minStackPop(obj);
 *
 * int param_3 = minStackTop(obj);
 *
 * int param_4 = minStackGetMin(obj);
 *
 * minStackFree(obj);
 *
 * You must implement a solution with O(1) time complexity for each function.
 */
/***********************************************************************/
int main()
{
    printf("\n---------------------------------------------------\n");
    tb_full();

    printf("\n---------------------------------------------------\n");
    printf("\nPASS-TEST\n");
    return 0;
}
#endif
/***********************************************************************/
// funs implements
/***********************************************************************/
/**
 * minStackCreate: -  initializes the stack object.
 */
MinStack* minStackCreate() 
{
    /**/
    MinStack* a_MinStack = (MinStack*)malloc(sizeof(MinStack));

    /**/
    a_MinStack->top      = -1;
    
    /**/
    a_MinStack->stack    = (int*)malloc(sizeof(int)*MAX_STACK_SIZE); 

    /**/
    return a_MinStack;
}

/**
 * minStackPush: -  pushes the element val onto the stack.
 */
void minStackPush(MinStack* obj, int val) 
{
    /**/

    if (obj->top < MAX_STACK_SIZE)
        obj->stack[++obj->top] = val;

    /**/
    return;  
}

/**
 * minStackPop: -  removes the element on the top of the stack.
 */
void minStackPop(MinStack* obj) 
{
    /**/
    if(obj->top >= 0)
        obj->top--;

    /**/
    return;  
}

/**
 * minStackTop: -  gets the top element of the stack.
 */
int minStackTop(MinStack* obj) 
{
    return obj->stack[obj->top];
}

/**
 * minStackGetMin: -  retrieves the minimum element in the stack.
 */
int minStackGetMin(MinStack* obj) 
{
    /**/
    int ret = obj->stack[0];

    /**/
    for(int i=1; i<=obj->top; i++)
    {
        /**/
        if(ret > obj->stack[i])
        {
            ret = obj->stack[i];
        }
    }

    /**/
    return ret;
}

/**
 * minStackFree: -  initializes the stack object.
 */
void minStackFree(MinStack* obj) 
{
    if(obj == NULL)
        return;

    /**/
    if(obj->top>=0)
        obj->top = -1;
    /**/
    free(obj->stack);
    
    /**/
    free(obj);
    
    /**/
    return;
}


/***********************************************************************/
