#include "String.h"

static char CharToUpper(char letter);
static char CharToLower(char letter);


String strnew(const char * content)
{
  String str = {NULL, 0};
  
  while(content[str.len] != '\0')
    str.len++;
  
  str.buffer = (char *)calloc(str.len + 1, sizeof(char));
  for (int i = 0; i < str.len; i++)
    str.buffer[i] = content[i];

  return str;
}

String StrJoin(const String strs[], int nb_of_str)
{
  String str = {NULL, 0};
  for (int i = 0; i < nb_of_str; i++)
    str.len += strs[i].len;
  
  str.buffer = (char *)calloc(str.len + 1, sizeof(char));
  for(int i = 0, j = 0, k = 0; i < str.len; i++, j++)
  {
    if (j == strs[k].len)
    {
      j = 0;
      k++;
    }
    str.buffer[i] = strs[k].buffer[j];
  }
  return str;
}

String StrCopy(const String str)
{
  return strnew(str.buffer);
}

String *StrSplit(const String str, const String sprtr)
{
  int nb_of_str = 1;
  // for (int i = )
}

void str_capitalize(String *str)
{
  str->buffer[0] = CharToUpper(str->buffer[0]);
}

void str_lower_case(String *str)
{
  for (int i = 0; i < str->len; i++)
  {
    str->buffer[i] = CharToLower(str->buffer[i]);
  }
}

void str_upper_case(String *str)
{
  for (int i = 0; i < str->len; i++)
  {
    str->buffer[i] = CharToUpper(str->buffer[i]);
  }
}

void str_swap_case(String *str)
{
  for (int i = 0; i < str->len; i++)
  {
    if(str->buffer[i] >= 'A' && str->buffer[i] <= 'Z')
    {
      str->buffer[i] = CharToLower(str->buffer[i]);
    }
    else if(str->buffer[i] >= 'a' && str->buffer[i] <= 'z')
    {
      str->buffer[i] = CharToUpper(str->buffer[i]);
    }
  }
}

void str_append(String *base, const String tail)
{
  base->buffer = realloc(base->buffer, base->len + tail.len + 1);
  for (int i = 0; i < tail.len + 1; i++)
    base->buffer[base->len + i] = tail.buffer[i];
  base->len += tail.len;
}

void str_add(String *base, const String front)
{
  base->buffer = realloc(base->buffer, base->len + front.len + 1);
  for (int i = base->len; i >= 0; i--)
    base->buffer[front.len + i] = base->buffer[i];
  for (int i = 0; i < front.len; i++)
    base->buffer[i] = front.buffer[i];
  base->len += front.len;
}

void str_insert(String *base, const String substr, int index)
{
  base->buffer = realloc(base->buffer, base->len + substr.len + 1);
  for (int i = base->len; i >= index; i--)
    base->buffer[substr.len + i] = base->buffer[i];
  for (int i = 0; i < substr.len; i++)
    base->buffer[i + index] = substr.buffer[i];
  base->len += substr.len;
}

void str_replace(String *base, const String oldstr, const String newstr)
{
  int start;
  while((start = strFind(*base, oldstr)) != -1)
  {
    if(oldstr.len == newstr.len)
    {
      for (int i = start, j = 0; j < newstr.len; i++, j++)
      {
        base->buffer[i] = newstr.buffer[j];
      }
    }
    else 
    {
      // TODO: complete
    }
  }
}

int strCount(const String str, const char target)
{
  int count = 0;
  for (int i = 0; i < str.len; i++)
    if (str.buffer[i] == target)
      count++;
  return count;
}

int strFind(const String str, const String substr)
{
  for(int i = 0; i < str.len; i++)
  {
    if (str.buffer[i] == substr.buffer[0] && str.len - i >= substr.len)
    {
      bool result = true;
      for (int j = i, k = 0; k < substr.len; j++, k++)
      {
        if(str.buffer[j] != substr.buffer[k])
          result = false;
      }
      if (result)
        return i;
    }
  }
  return -1;
}

bool strStartsWith(const String base, const String front)
{
  if (base.len < front.len)
    return false;
  for (int i = 0; i < front.len; i++)
    if (base.buffer[i] != front.buffer[i])
      return false;
  return true;
}

bool strEndWith(const String base, const String tail)
{
  if (base.len < tail.len)
    return false;
  int start = base.len - tail.len;
  for (int i = start, j = 0; i < base.len; i++, j++)
    if (base.buffer[i] != tail.buffer[j])
      return false;
  return true;
}

bool strIsAlNum(const String str)
{
  for (int i = 0; i < str.len; i++)
  {
    char letter = CharToLower(str.buffer[i]);
    if (!((letter >= 'a' && letter <= 'z') || (letter >= '0' && letter <= '9')))
      return false;
  }
  return true;
}

bool strIsAlpha(const String str)
{
  for (int i = 0; i < str.len; i++)
  {
    char letter = CharToLower(str.buffer[i]);
    if (!(letter >= 'a' && letter <= 'z'))
      return false;
  }
  return true;
}

bool strIsNumer(const String str)
{
  for (int i = 0; i < str.len; i++)
  {
    char letter = CharToLower(str.buffer[i]);
    if (!(letter >= '0' && letter <= '9'))
      return false;
  }
  return true;
}

bool strIsLower(const String str)
{
  for (int i = 0; i < str.len; i++)
    if (str.buffer[i] >= 'A' && str.buffer[i] <= 'Z')
      return false;
  return true;
}

bool strIsUpper(const String str)
{
  for (int i = 0; i < str.len; i++)
    if (str.buffer[i] >= 'a' && str.buffer[i] <= 'z')
      return false;
  return true;
}

bool strIsSpace(const String str)
{
  for (int i = 0; i < str.len; i++)
    if (str.buffer[i] != ' ')
      return false;
  return true;
}

bool strEquals(const String str1, const String str2)
{
  if (str1.len != str2.len)
    return false;
  for (int i = 0; i < str1.len; i++)
    if (str1.buffer[i] != str2.buffer[i])
      return false;
  return true;
}

void str_free(const String str)
{
  free(str.buffer);
}

static char CharToUpper(char letter)
{
  if (letter >= 'a' && letter <= 'z')
    return letter - 32;
  else
    return letter;
}

static char CharToLower(char letter)
{
  if (letter >= 'A' && letter <= 'Z')
    return letter + 32;
  else
    return letter;
}