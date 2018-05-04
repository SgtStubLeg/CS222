#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Student.h"
#include "trees.h"


/* Get rid of switch statements.
* Put houses into an array
* Get rid of mallocs
*/ 
Student* nodeGenerator();
void add(char* firstname, char* lastname, int points, int year, char* house, Student** houses);
void changePoints(Student** root, int points);
void clean(Student* root);
void inorder(Student* root, int index);
void preorder(Student* root, int index);
void postorder(Student* root, int index);
int sumScore(Student* root);
int findIndex(char* house);

int main(){
  //used to check if the specified house is a valid house
  int houseFlag;
  char command [100];  
	int i;
	char firstName [100];
	char lastName [100];
	int points;
	int year;
	char house[100];
	int index;

	Student* gryffindor = NULL;
	Student* ravenclaw = NULL;
	Student* hufflepuff = NULL;
	Student* slytherin = NULL;
	Student* deceased = NULL;

	Student* houses[5];
	houses[0] = gryffindor;
	houses[1] = ravenclaw;
	houses[2] = hufflepuff;
	houses[3] = slytherin;
	houses[4] = deceased;

  do{
    houseFlag=0;
    printf("Enter command: ");
    scanf("%s", command);

    //prints out the help menu
    if(strcmp(command, "help")==0){
      FILE* helpMenu = fopen("help.txt", "r");
      int fileRead = fgetc(helpMenu);

      while(fileRead != EOF){
	printf("%c", fileRead);
	fileRead = fgetc(helpMenu);
      }
      printf("\n");
    }
    //loads a specified file into the roster
    else if(strcmp(command, "load")==0){
      char fileName[100];
      scanf("%s", fileName);
      FILE* file = fopen(fileName, "r");

      if(file != NULL){
	while(!feof(file)){
	  fscanf(file, "%s %s %d %d %s", firstName, lastName, &points, &year, house);
	  int index = findIndex(house);
	  add(firstName, lastName, points, year, house, houses);
	}
	printf("Successfully loaded data from %s.\n", fileName);
      }
      else
	printf("Load failed. Invalid file: %s.\n", fileName);
    }
    else if(strcmp(command, "save")==0){
      
    }

    else if(strcmp(command, "clear")==0){
	for(i = 0; i < 5; i++)
		clean(houses[i]);
    }

    else if(strcmp(command, "inorder")==0){
	for(i = 0; i < 4; i++)
		inorder(houses[i], i);
	
    }
    else if(strcmp(command, "preorder")==0){
	for(i = 0; i < 5; i++)
		preorder(houses[i], i);
    }
    else if(strcmp(command, "postorder")==0){
	for(i = 0; i < 5; i++)
		postorder(houses[i], i);
      
    }
    else if(strcmp(command, "add")==0){

  scanf("%s", firstName);
  
  scanf("%s", lastName);
  
  scanf("%d", &points);
  
  scanf("%d", &year);
  
  scanf("%s", house);
      add(firstName, lastName, points, year, house, houses);
	
    }
    else if(strcmp(command, "kill")==0){
	Student* temp;
      scanf("%s", firstName);
   
      scanf("%s", lastName);

      scanf("%s", house);

      if(strcmp(house, "Gryffindor") == 0){
		temp = search(firstName, lastName, houses[0]);
		houses[0] = delete(houses[0], firstName, lastName);
		temp->left = NULL;
		temp->right = NULL;
		insert(&deceased, temp);
		
	}else if(strcmp(house, "Ravenclaw") == 1){
		temp = search(firstName, lastName, houses[1]);
		houses[1] = delete(houses[1], firstName, lastName);
		temp->left = NULL;
		temp->right = NULL;
		insert(&deceased, temp);
		
	}else if(strcmp(house, "Hufflepuff") == 2){
		temp = search(firstName, lastName, houses[2]);
		houses[2] = delete(houses[2], firstName, lastName);
		temp->left = NULL;
		temp->right = NULL;
		insert(&deceased, temp);
		
	}else if(strcmp(house, "Slytherin") == 3){
		temp = search(firstName, lastName, houses[3]);
		houses[3] = delete(houses[3], firstName, lastName);
		temp->left = NULL;
		temp->right = NULL;
		insert(&deceased, temp);
		
	}else
		printf("Kill failed. Invalid house: %s\n", house);
    }
    else if(strcmp(command, "find")==0){
      Student* temp;
      scanf("%s", firstName);
   
      scanf("%s", lastName);
      
      scanf("%s", house);

      index = findIndex(house);

      if(index < 0)
	printf("Find failed. Invalid house: %s\n", house);
      else {
	temp = search(firstName, lastName, houses[index]);
	if(temp == NULL)
		printf("Find failed. %s %s was not found in %s House\n",firstName, lastName, house);
	else
		printf("%s %s\t\tPoints: %d\tYear: %d House: %s\n", temp->first, temp->last, temp->points, temp->year, HOUSE_NAMES[index]);
	}
      
    }
    else if(strcmp(command, "points")==0){
            Student* temp;
      scanf("%s", firstName);
   
      scanf("%s", lastName);
      
      scanf("%s", house);

      scanf("%d", &points);

	index = findIndex(house);
 
	temp = search(firstName, lastName, houses[index]);


      if(index < 0)
	printf("Find failed. Invalid house: %s\n", house);
      else { 
	temp = search(firstName, lastName, houses[index]);
	if(temp == NULL)
		printf("Find failed. %s %s was not found in %s House\n",firstName, lastName, house);
	else	
		changePoints(&temp, points);

      }
    }else if(strcmp(command, "score")==0){
	int score = 0;
        score = sumScore(houses[0]);
	printf("Gryffindor: %d\n", score);
 	score = sumScore(houses[1]);
	printf("Ravenclaw: %d\n", score);
  	score = sumScore(houses[2]);
	printf("Hufflepuff: %d\n", score);
  	score = sumScore(houses[3]);
	printf("Slytherin: %d\n", score);
    }

    //prints if specified command is unknown
    else if(strcmp(command, "quit") != 0){
      fprintf(stderr,"Unknown command: %s\n", command);
      
    }
  }while(strcmp(command, "quit") != 0);

  printf("All data cleared.\n");
	for(i = 0; i < 5; i++)
		clean(houses[i]);

  return 0;
}

int sumScore(Student* root){
	
	if (root == NULL)
		return 0;
	return(root->points + sumScore(root->left) + sumScore(root->right));

}




void inorder(Student* root, int index){
	if (root != NULL){
		inorder(root->left, index);
		printf("%s %s\t\tPoints: %d\tYear: %d House: %s\n", root->first, root->last, root->points, root->year, HOUSE_NAMES[index]);
		inorder(root->right, index);
	}

}

void preorder(Student* root, int index){
	if (root != NULL){
		printf("%s %s\t\tPoints: %d\tYear: %d House: %s\n", root->first, root->last, root->points, root->year, HOUSE_NAMES[index]);
		preorder(root->left, index);
		preorder(root->right, index);
	}
}

void postorder(Student* root, int index){
	if (root != NULL){
		postorder(root->left, index);
		postorder(root->right, index);
		printf("%s %s\t\tPoints: %d\tYear: %d House: %s\n", root->first, root->last, root->points, root->year, HOUSE_NAMES[index]);
		
	}

}



void add(char* firstName, char* lastName, int points, int year, char* house, Student** houses ){

  Student* node = malloc(sizeof(Student));
     
  int index;
  index = findIndex(house);

  
  if(index < 0){
    printf("Add failed. Invalid house: %s\n", house);
    return;
  }
  else if(year<1 || year>7){
    printf("Add failed. Invalid year: %d\n", year);
    return;
  }

  node->first = firstName;
  node->last = lastName;
  node->points = points;
  node->year = year;
  node->house = houses[index];

 
    switch(index){
    case 0:
      houses[0] = insert(&(houses[0]), node);
      if(houses[0] == NULL)
	printf("Add failed. Student named %s %s already present in roster.\n", node->first, node->last);
      break;
    case 1:
      houses[1] = insert(&(houses[1]), node);
      if(houses[1] == NULL)
	printf("Add failed. Student named %s %s already present in roster.\n", node->first, node->last);
      break;
    case 2:
      houses[2] = insert(&(houses[2]), node);
      if(houses[2] == NULL)
	printf("Add failed. Student named %s %s already present in roster.\n", node->first, node->last);
      break;
    case 3:
      houses[3] = insert(&(houses[3]), node);
      if(houses[3] == NULL)
	printf("Add failed. Student named %s %s already present in roster.\n", node->first, node->last);
      break;
    }
  

}

int findIndex(char* house){
	if(strcmp(house, "Gryffindor") == 0)
		return 0;
	else if(strcmp(house, "Ravenclaw") == 0)
		return 1;
	else if(strcmp(house, "Hufflepuff") == 0)
		return 2;
	else if(strcmp(house, "Slytherin") == 0)
		return 3;
	else 
		return -1;
}



void changePoints(Student** root, int points){
	(*root)->points += points;

}

void clean(Student* root){
  if(root != NULL){
    clean(root->left);
    clean(root->right);
    free(root->first);
    free(root->last);
    free(root);
  }
}
