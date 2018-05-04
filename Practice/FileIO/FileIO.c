#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int size;
  printf("Give me an integer: ");
  scanf("%d", &size);
  
  printf("Enter a file name: ");
  char fileName[100];
  scanf("%s",fileName);

  FILE* file = fopen(fileName, "w");//opens file for writing
  fprintf(file, "Size: %d\n", size);

  int i;
  srand(time(NULL));
  for(i=0;i<size;i++)
    fprintf(file, "%d\n", rand() % 1000000000);
  
  fclose(file);
  return 0;
}
