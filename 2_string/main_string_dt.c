/***********************************************************************/
/**
    LeetCode 
    Purpose: Strings data structure
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

/***********************************************************************/
// The tbs for each funs and so on...
/***********************************************************************/

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

/***********************************************************************/
/**
 * main - main program, test case
 */
/***********************************************************************/

int main()
{

    printf("@frk: start testing ...............................");
    printf("\n---------------------------------------------------\n");

    tb_romanToInt();
    printf("\n---------------------------------------------------\n");
    
    tb_longestCommonPrefix();
    printf("\n---------------------------------------------------\n");

    tb_strStr();
    printf("\n---------------------------------------------------\n");

    printf("\nPASS-TEST\n");
    return 0;
}

/***********************************************************************/
// funs implements
/***********************************************************************/

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

/***********************************************************************/

