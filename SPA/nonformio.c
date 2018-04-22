#include<stdio.h>
/// Program to understand the usage of Non-Formatted I/O functions
void main()
{
    int ch='a';
    char char1,char2;
    // putchar writes a SINGLE character in the output stream
    // Even when a string is provided, it'd print the first character of it
    putchar(++ch);  // Increment and print -> b
    putchar(ch++);  // Print and Increment -> b
    putchar(ch);    // Print               -> c
    putchar(ch--);  // Print and Decrement -> c
    putchar(ch);    // Print               -> b
    // getchar() allows the user to input a single character
    // THAT SAME INPUT is passed as an argument to the putchar() function
    // putchar() prints the character value of the variable 'char1'
    putchar(getchar());
    // usage of getchar()
    char2=getchar();
    // getchar() accepts an character input from the user. char2 gets the 'return'
    // value of 'getchar()'
}
