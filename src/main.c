#include <stdio.h>
#include <stdlib.h>
#include "str.h"

int main(int argc, char ** argv)
{
	String str1 = strnew("HELLO");
	String str2 = strnew("~WORLDLLO");
	String str3 = strnew("~HOW~ARE~YOULLO");

	String strings[] = {str1, str2, str3};

	String joind = StrJoin( strings, 3);

	// int size;
	// String *strings2 = StrSplit(joind, strnew("~"), &size);
	// for (int i = 0; i < size; i++)
	// 	printf("  -> %s\n", strings2[i]);

	str_replace(&joind, strnew("~"), strnew("$$"));

	printf("%s, %d\n", joind, joind.len);
	return 0;
}