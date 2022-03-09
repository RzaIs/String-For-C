#ifndef __STRING_H__
#define __STRING_H__


#include <stdlib.h>
#include <stdbool.h>

typedef struct _String
{
  char * buffer;
  int len;
} String;

String strnew(const char * content);

String StrJoin(const String strs[], int nb_of_str);
String StrCopy(const String str);
// String StrSubstr(const String str, int s, int e);

// String *StrSplit(const String str, const String sprtr);

void str_capitalize(String *str);
void str_lower_case(String *str);
void str_upper_case(String *str);
void str_swap_case(String *str);

void str_append(String *base, const String tail);
void str_add(String *base, const String front);
void str_insert(String *base, const String substr, int index);
// void str_replace(String *base, const String oldstr, const String newstr);

int strCount(const String str, const char target);
int strFind(const String str, const String substr);

bool strStartsWith(const String base, const String front);
bool strEndsWith(const String base, const String tail);
bool strIsAlNum(const String str);
bool strIsAlpha(const String str);
bool strIsNumer(const String str);
bool strIsLower(const String str);
bool strIsUpper(const String str);
bool strIsSpace(const String str);
bool strEquals(const String str1, const String str2);
// bool strIsEmpty(const String str);
// bool strContains(const String str, const String substr);

// char strCharAt(const String str);


void str_free(const String str);

#endif // __STRING_H__