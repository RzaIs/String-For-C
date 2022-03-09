#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(int argc, char ** argv)
{
	String str1 = strnew("HELLO");
	String str2 = strnew("~WORLDLLO");
	String str3 = strnew("~HOW_ARE_YOULLO");

	String strings[] = {str1, str2, str3};

	String joind = StrJoin( strings, 3);

	str_replace(&joind, strnew("LLO"), strnew("$_$_$"));

	printf("%s, %d\n", joind, joind.len);
	return 0;
}