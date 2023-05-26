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
 * romanToInt: Leetcode #13
 *
 * @x
 *
 * Roman to integer
 * 
 */
int char_to_int(char s);
int romanToInt(char* s);
void tb_romanToInt();

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

/* testbench for newListNode */
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

/* testbench for newListNode */
void tb_isPalindrom()
{
	printf("@frk: test for two_Sum...\n");

	isPalindrome(121);
        isPalindrome(-121);
	isPalindrome(122);
	
}

/*  */
void tf_char_to_int(void)
{ 
    printf("\n@frk_debug [%d]", char_to_int('I')); 
    printf("\n@frk_debug [%d]", char_to_int('V')); 
    printf("\n@frk_debug [%d]", char_to_int('X')); 
    printf("\n@frk_debug [%d]", char_to_int('L')); 
    printf("\n@frk_debug [%d]", char_to_int('C')); 
    printf("\n@frk_debug [%d]", char_to_int('D')); 
    printf("\n@frk_debug [%d]", char_to_int('M')); 
    printf("\n@frk_debug [%d]", char_to_int('a')); 
} 

void tb_romanToInt() 
{ 
    /* test for char to int */
    tf_char_to_int(); 

    /* */
    printf("\n result = %d", romanToInt("III")); 
    printf("\n result = %d", romanToInt("LVIII")); 
    printf("\n result = %d", romanToInt("MCMXCIV")); 

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
 
    tb_romanToInt();
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
int char_to_int(char s)
{ 
    /* return value */
    int value; 

    /* assign coresponding value */
    value = (s == 'I') ? 1    : 
            (s == 'V') ? 5    : 
            (s == 'X') ? 10   : 
            (s == 'L') ? 50   : 
            (s == 'C') ? 100  : 
            (s == 'D') ? 500  : 
            (s == 'M') ? 1000 : 0 ; 
    
    /* return it */
    return value; 
} 

/* */
int romanToInt(char * s)
{ 
    /* */
    int length = strlen(s); // length of the string 
    int result = 0;         // result variable   
    
    /* interate through the Roman numeral string */
    for (register int i=0; i<length; i=(char_to_int(s[i]) < char_to_int(s[i+1])) ? (i+2) : (i+1) ) 
    { 
        /* If the current character represents a smaller value than the next character, subtract it from the result */	 
        result = ( char_to_int(s[i]) < char_to_int(s[i+1]) ) ? (result + char_to_int(s[i+1]) - char_to_int(s[i])) : (result + char_to_int(s[i]));  
    } 
    return result; 
} 

/***********************************************************************/
