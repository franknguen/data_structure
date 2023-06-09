/***********************************************************************/
/**
    LeetCode 
    Purpose: Array data structure
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
 * twoSum: Leetcode #1
 *
 * @nums
 * 
 * @numsSize
 * 
 * @target 
 * 
 * @returnsize
 *
 * given an array of integers nums and an integer target. Return indices
 * of the two numbers such that they add up to target.
 * 
 */
int *twoSum(int* nums, int numSize, int target, int* returnSize);
void tb_twoSum();

/**
 * isPalindrome: Leetcode #2
 *
 * @x
 *
 * given an integer x, return true if x is palindrome, false if otherwise
 * 121: true; -121: false
 * 
 */
bool isPalindrome(int x);
void tb_isPalindrome();

/**
 * climbStairs -  Leetcode #70
 * @n:            input number
 *    
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 *
 * return:        int 
 */
int climbStairs(int n);
void tb_climbStairs();

/**
 * getRow: Leetcode #119
 *
 * @rowIndex
 *
 * @returnSize
 *
 * to return the (indexed) row of a Pascal triangle 
 * 
 */
int* getRow(int rowIndex, int* returnSize);
void tb_getRow();

/**
 * generate: Leetcode #118
 *
 * @numRows
 *
 * @returnSize
 *
 * @returnColumnSizes
 *
 * to return an array of arrays. that is to return the first numRows of Pascal triangle 
 * 
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes);
void tb_generate();

/**
 * maxProfit: Leetcode #121
 *
 * @
 *
 * @
 *
 * to return the maximum profit you can achieve from this transaction. 
 * If you cannot achieve any profit, return 0. 
 * 
 */
int maxProfit(int* prices, int pricesSize);
void tb_maxProfit();


/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

/* testbench for twoSum */
void tb_twoSum()
{
	printf("@frk: test for two_Sum...\n");
	
	/**/
	int nums[4] = {2, 7, 11, 15};
	int target  = 9;
	int returnSize;

	/**/
	int* ret = twoSum(nums, 4, target, &returnSize);
	
	/**/
	printf("\n results: %d, %d", ret[0], ret[1]);

}

/* testbench for isPalindrom */
void tb_isPalindrom()
{
     printf("@frk: test for isPalindrom...\n");

     isPalindrome(121);
     isPalindrome(-121);
     isPalindrome(122);
	
}

/* testbench for climbStairs */
void tb_climbStairs()
{
    printf("@frk: test for climbStair...\n");
    for(int i=0; i<40; i++) {
    	printf("\n n=[%d], climbStairs[%d]=[%d]", i, i,  climbStairs(i));
    } 
}

/* testbench for getRow */
void tb_getRow()
{
    printf("@frk: test for getRow...\n");
    int n    = 6;
    int* len;
    int* ret = malloc(7*sizeof(int));
    ret = getRow(n, len);
    for(int i=0; i<7; i++){
    	printf("\n *(ret+%d)=[%d]",i,*(ret+i));
    }

}

/* testbench for generate*/
void tb_generate()
{
    printf("@frk: test for generate...\n");
    
    int   numRows    = 5;
    int   returnSize;
    int*  returnColumnSizes;
    
    /* */
    int** triangle =  generate(numRows, &returnSize, &returnColumnSizes);

    /* */
    for(int i=0; i<returnSize; i++){
    	for(int j=0; j<returnColumnSizes[i]; j++){
	    printf("%d", triangle[i][j]);
	}
	printf("\n");
    }

    /* */
    free(triangle);
}

/* testbench for maxProfit */
void tb_maxProfit()
{
    printf("@frk: test for maxProfit...\n");

    int prices[] = {1, 4, 3, 5};
    int pricesSize = 4;
    int profit = maxProfit(prices, pricesSize);
    printf("\n max profit = %d", profit);

}

/***********************************************************************/
/**
 * main - main program, test case
 */
/***********************************************************************/

int main()
{

    printf("@frk: start testing ...............................");
    printf("\n---------------------------------------------------\n");

    tb_twoSum();
    printf("\n---------------------------------------------------\n");

    tb_isPalindrom();
    printf("\n---------------------------------------------------\n");
 
    tb_getRow();
    printf("\n---------------------------------------------------\n");

    tb_generate();
    printf("\n---------------------------------------------------\n");

    tb_maxProfit();
    printf("\n---------------------------------------------------\n");


   printf("\nPASS-TEST\n");
    return 0;
}

/***********************************************************************/
// funs implements
/***********************************************************************/

/* */
int *twoSum(int* nums, int numSize, int target, int* returnSize)
{
	/* set the returnSize to 2*/
	*returnSize = 2;

	/* allocate memory for result array*/
	int* ret = malloc((*returnSize)*sizeof(int));

	/* iterate over each pair of number in arrays*/
	for(int i=0; i<numSize; i++)
	{
		for(int j=i+1; j<numSize; j++)
		{
			/* check if sum of two numbers equal to target */
			if( *(nums+i) + *(nums+j) == target) 
			{
				/* store indices into ret array */
				*ret     = i;
				*(ret+1) = j;

				/* return */
				return ret;	
			}		
		}
	}
	return ret;
}

/* */
bool isPalindrome(int x)
{
	/* check if input is negative */
	if ( x<0 )
		return false;
	
	/* store the original number, reverse number */
	int original        = x;        //
	//int reverse    = 0;           // 
	long long reverse   = 0;        // to fix run time error

	/* reverse the digits of number */
	while( x != 0 )
	{
		/* build reverse number */
		reverse = reverse*10 + ( x%10 );
		
		/* remove the lastest digit from original number */
		x/=10;
	}

	/**/
	return original == reverse;
}

/* */
int searchInsert(int* nums, int numsSize, int target)
{
    int result=0;
    
    /*  */
    if(nums[0] >= target){
        return 0;
    } else if (target == nums[numsSize-1]){
                return numsSize-1;
            } else if (target > nums[numsSize-1]){
                return numsSize;
            } else {
                for (int i=1; i<numsSize; i++)
                {
                    if ((nums[i] >= target)){
                        result = i;
                        break;
                    }
                }
            }
	/*  */
	return result;
}

/*  */
int climbStairs(int n)
{
    int rt[45];

    rt[0] = 1;
    rt[1] = 2;

    for(int i=0; i<43; i++)
    {
        rt[i+2] = rt[i] + rt[i+1];
    }

    return rt[n-1];
}

/*  */
int* getRow(int rowIndex, int* returnSize)
{
    /* size of return result */
    *returnSize = rowIndex+1;

    /* allocate memory for return result */
    int* ret = malloc((*returnSize)*sizeof(int));

    /* */
    *(ret)              = 1;
    *(ret+rowIndex)     = 1;
    
    /* */
    if(rowIndex<2)
       return ret;

    /* */ 
    for(int i=2; i<=rowIndex; i++)
    {
       /*  */
       *(ret+i-1)=1;
       
       /*  */
       for(int j=i-1; j>0; j--)
       {
	  /*  */
	  *(ret+j)=*(ret+j)+*(ret+j-1);
       }
    }
    /* */
    return ret;
}

/*  */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    /* */
    *returnSize = numRows ;
    
    /* */
    *returnColumnSizes = malloc(numRows*sizeof(int*));

    /* */
    int** ret = malloc(numRows*sizeof(int*));

    /* Pascal triangle */
    for(int i=0; i<numRows; i++)
    {
	/**/
	(*returnColumnSizes)[i] = i+1;

	/**/
    	ret[i] = malloc((i+1)*sizeof(int));
	
	/**/
	ret[i][0] = 1;
	ret[i][i] = 1;

	/**/
	for(int j=1; j<i; j++){
	    ret[i][j]=ret[i-1][j-1] + ret[i-1][j];
	}
    }

    /* */
    return ret;
}

/* */
int maxProfit(int* prices, int pricesSize)
{
   int ret = 0;
   int tem = prices[0];

   //
   for(int i=1; i<pricesSize; i++)
   {
       printf("\n iter[%d]", i);
       if( prices[i]<tem )
       {
           tem = prices[i];
	   printf("\n@frk: tem = %d", tem);
       } 
       else 
       {
           if (ret < prices[i] - tem)
	   {
	       ret = prices[i] - tem;
	       printf("\n@frk: ret = %d", ret);
	   }
       }
   } 

   //
   return ret;
}
/***********************************************************************/

