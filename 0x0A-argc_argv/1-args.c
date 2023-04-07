#include "main.h"
#include <stdio.h>
/**
 *main - prints the number of arguments passed into it.
 *@argc: a count of the arguments supplied to the program 
 *@argv: an array of pointers to the strings which are those arguments
 *Return: integer.
 */

int main(int argc, char *argv[])
{
	if(argc > 0)
	{
		printf("%d\n", argc);
		return (0);
	}
	return (0);
}
