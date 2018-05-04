#include <stdio.h>

int length(char string[]){
  int i;
  while(string[i] != '\0')
    i++;
  return i;
}

void reverse(char string[]){
  int i, size = length(string);
  for(i=0;i<size/2;i++){
    char temp = string[i];
    string[i] = string[size-i-1];
    string[size-i-1]=temp;
  }  
}

int main(){
  char text[] = "I like potatoes!";
  int size = length(text);
  printf("Length of \"%s\" is: %d.\n", text, size);
  reverse(text);
  printf("%s",text);
  return 0;
}

