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

/**
 * longestCommonPrefix: Leetcode #14
 *
 * @x
 *
 * to find the longest common prefix string amongst an array of strings
 * 
 */
char * longestCommonPrefix(char ** strs, int strsSize);
void tb_longestCommonPrefix();

/**
 * strStr: Leetcode #28
 *
 * @x
 *
 * to find the index of the first occurance in a string
 * 
 */
int strStr(char * haystack, char * needle);
void tb_strStr();

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

/* testbench for romanToInt */
void tb_romanToInt() 
{ 

    printf("@frk: test for romanToInt...\n");
    
    /* test for char to int */
    tf_char_to_int(); 

    /* */
    printf("\n result = %d", romanToInt("III")); 
    printf("\n result = %d", romanToInt("LVIII")); 
    printf("\n result = %d", romanToInt("MCMXCIV")); 

} 

/* testbench for longestCommonPrefix */
void tb_longestCommonPrefix()
{
    printf("@frk: test for longestCommonPrefix...\n");
    
    char* test_str1[] = {"flower","flow","flight"};
    char* test_str2[] = {"aaa","aaafl","aaaxxxx"};
    char* test_str3[] = {"dog","racecar","car"};

    printf("\n %s",longestCommonPrefix(test_str1,3));
    printf("\n %s",longestCommonPrefix(test_str2,3));
    printf("\n %s",longestCommonPrefix(test_str3,3));

}

/* testbench for strStr */
void tb_strStr()
{
    printf("@frk: test for strStr...\n");
    
    char *str1 = "leetcode!";
    char *str2 = "leet";

    printf("\n result=%d",strStr(str1, str2));
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
    
    int numRows    = 5;
    int* returnSize;
    int** returnColumnSizes;
    int** ret =  generate(numRows, returnSize, returnColumnSizes);
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
    
    tb_longestCommonPrefix();
    printf("\n---------------------------------------------------\n");

    tb_strStr();
    printf("\n---------------------------------------------------\n");

    tb_getRow();
    printf("\n---------------------------------------------------\n");

    tb_generate();
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

/* */
char * longestCommonPrefix(char ** strs, int strsSize)
{
    /* handle the empty input */
    if (strsSize == 0) 
    {
        char* result = (char*) malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }

    /* */
    char* result = (char*) malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(result, strs[0]);

    /* */
    for (int i = 1; i < strsSize; i++) 
    {
        int j = 0;
        while ((result[j] != '\0') && (strs[i][j] != '\0') && (result[j] == strs[i][j])) 
        {
            j++;
        }

        result[j] = '\0';
       
        /* handle the empty prefix */	
	if (j == 0) 
        {
            free(result);
            char* empty_result = (char*) malloc(sizeof(char));
            empty_result[0] = '\0';
            return empty_result;
        }
    }

    /* */
    return result;
}

/* */
int strStr(char * haystack, char * needle)
{
    /* */
    int result = -1;
    int leng1  = strlen(haystack);
    int leng2  = strlen(needle);
    
    /* */
    if (leng1 < leng2)
        return result;

    /* */
    for (int i=0; i<= (leng1 - leng2); i++)
    {
        int tem=0;

	/* */
        for (int j=0; j<leng2; j++)
	{
            if(haystack[i+j] != needle[j])
	    {
                tem = 1;
            }
        }

	/* */
        if (tem == 0)
	{
            result = i;
            break;
        }
    }
    
    /**/
    return result;
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
	for(int j=1; j<i; j++){
	    ret[i][j]=ret[i-1][j-1] + ret[i-1][j];
	}
    }

    /* */
    return ret;
}

/***********************************************************************/
