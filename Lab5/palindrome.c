#include <stdio.h>
#include <string.h>

int isPalindrome(char string[1024], int length);
char toLower(char letter);

int main(){
  int initialString, stringLength=0, i=0;
  char palindrome[1024];
  
  initialString = getchar();
  
 while(initialString != EOF && initialString != '\n'){
    if(stringLength<1024){
      palindrome[i] = initialString;
      i++;
      stringLength++;
    }
    initialString = getchar();
  }

 printf("The string \"");

 for(i=0;i<stringLength;i++)
   printf("%c", palindrome[i]);
 
  palindrome[stringLength] = '\0';

  if(isPalindrome(palindrome, stringLength) == 1)
    printf("\" is a palindrome.\n");
  else
    printf("\" is not a palindrome.\n");
  return 0;
}

int isPalindrome(char string[], int length){
  int i;
  for(i=0;i<length;i++)
    if(toLower(string[i]) != toLower(string[length-1-i]))
      return 0;
  return 1;
}

char toLower(char letter){
  if(letter>='A' && letter <='Z')
    letter+=('a'-'A');
   
  return letter+=('a'-'A');
}
