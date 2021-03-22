#include "StringUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ev_size(const void* in)
{
   const char* in_str = (char *)in;
   const char* in_str_itr = in_str;
   int total_length = strlen(in_str);
   int counter = 0;
   while(in_str)
   {  
      if(((counter + 1) < total_length) && ((*(in_str_itr) == ' ') && (*(in_str_itr+1) == ' ')))
         break;
      in_str_itr++;
      counter++;
   }
   return counter;
}