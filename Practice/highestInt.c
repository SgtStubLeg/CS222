#include <stdio.h>

int highestBit(unsigned int number);

int main(){
  printf("%d n",highestBit(0));
  return 0;
}

int highestBit(unsigned int number){
  if(number == 0)
    return -1;

    /* could also start at 31 and move backwards*/
    int bit;
    int highest=0;
    for(bit=0;bit<=31;bit++){
      if(number & (1<<bit))
	highest=bit;
    }

    return highest;
  
}
