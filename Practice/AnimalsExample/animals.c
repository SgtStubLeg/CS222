//chooses an animal based on user input

#include <stdio.h>
#include <string.h>

/*
these two parameters can be named anything
i.e ...
int main(int count, char** args)
but standard is
*/
int main(int argc, char** argv){
  if(argc != 2 || argv[1][0] != '-'){
    printf("Usage: animals [-y | -o | -t]\n");
  }
  else{
    if(argv[1][0] == '-'){
      if(strcmp(argv[1],"-y")==0)
	printf("Yak\n");
      else if(strcmp(argv[1],"-c")==0)
	printf("Cormorant\n");
      else if(strcmp(argv[1],"-t")==0)
	printf("Tasmanian devil\n");
    }
    else
      printf("Unknown animal\n");
  }
  return 0;
}

