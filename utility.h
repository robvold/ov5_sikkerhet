#pragma once
#include <stdio.h>
#include <string.h>



char *formatString(char *str) {
  int len = strlen(str);
  char returnStr[len];

  for (int i = 0; i < len; i++) {
    if (str[i] == '&') {
      returnStr[i] = (char)"&amp";
    } else if (str[i] == '<') {
      returnStr[i] = (char)'&lt';
    } else if (str[i] == '>') {
      returnStr[i] = (char)'&gt';
    } else {
      returnStr[i] = str[i];
    }
  }

  char *retStr = returnStr;
  return retStr;
}