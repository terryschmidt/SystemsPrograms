#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TEXT_LEN        64
#define LO_NUM_LIMIT    0
#define HI_NUM_LIMIT    2000000000
#define LO_STRING_LEN_LIMIT 4
#define HI_STRING_LEN_LIMIT 8

void copyTheString(char*,const char*);
void reverseTheString(char*);
int stringLength(const char*);
int compareTheString(const char*, char*);

int isPalindrome  (const char*  cPtr)
{

   int test, length;
   char *reverse;
 
   length = stringLength(cPtr);    
   reverse = (char*)malloc(length+1);    
 
   copyTheString(reverse,cPtr);
   reverseTheString(reverse);
 
   test = compareTheString(cPtr, reverse);
 
   free(reverse);
 
   if ( test == 0 )
      return 1;
   else
      return 0;

}

int stringLength(const char *string)
{
   int textLength = 0;  
 
   while(*string)
   {
      textLength++;
      string++;
   }
 
   return textLength;
}
 
void copyTheString(char *destination, const char *source)
{
   while(*source)
   {
      *destination = *source;
      source++;
      destination++;
   }
   *destination = '\0';
}
 
void reverseTheString(char *string) 
{
   int length, x;
   char *begin, *end, temp;
 
   length = stringLength(string);
 
   begin = string;
   end = string;
 
   for ( x = 0 ; x < ( length - 1 ) ; x++ )
       end++;
 
   for ( x = 0 ; x < length/2 ; x++ ) 
   {        
      temp = *end;
      *end = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}
 
int compareTheString(const char *begin, char *end)
{
   while(*begin==*end)
   {
      if ( *begin == '\0' || *end == '\0' )
         break;
 
      begin++;
      end++;
   }
   if( *begin == '\0' && *end == '\0' )
      return 0;
   else
      return -1;
}


int main  ()
{
  char* heapPtr;
  heapPtr = malloc(64*sizeof(char));


  
  int n;
  int result;
  char inputText[TEXT_LEN]  = "\0";
  n = -1;


  while(n < LO_NUM_LIMIT || n > HI_NUM_LIMIT)
  {
    printf("Please enter an integer from 0 to 2000000000: ");
    scanf("%d",&n);
  }
  
  char Number[TEXT_LEN];
  snprintf(Number,TEXT_LEN,"%d",n);

  

  while(strlen(inputText) < LO_STRING_LEN_LIMIT || strlen(inputText) > HI_STRING_LEN_LIMIT)
  {
    printf("Please enter text between 4-8 chars: ");
    scanf("%s",&inputText);
  }

  result = isPalindrome(Number);

  if(result == 1)
    snprintf(heapPtr,TEXT_LEN,"%s %s %s",Number,inputText,Number);
  else
    snprintf(heapPtr,TEXT_LEN,"%s %s",inputText,Number);

  printf("%s\n",heapPtr);
  free(heapPtr);

  return(EXIT_SUCCESS);
}
