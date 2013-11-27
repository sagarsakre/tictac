#include"main.h"
void sleep_me();
int initgame()
{
	printf("Hello, Welcome to tictactoe Game, Please enter your choice\n");
	printf(" Two Player - 1 \n");
	printf(" Single Player - 2 \n");
	scanf("%d", &gametype);
	if(gametype==1){
		return 1;
	}
	else{
	printf(" Enter the difficulty level\n");
	printf(" EASY -   1\n");
	printf(" MEDIUM - 2\n"); 
	printf(" HARD -   3\n");
	printf(" ENTER your choice: ");
	scanf("%d",&LEVEL);
	return 2;
	}
}
int
toss()
{
  srand(time(NULL));
  printf(" Toss betwen PLAYER_1 and PLAYER_2");
  sleep_me();
  int itoss;
  char bchar;
  int i=0;
  int j=rand()%1000;
  for(;j>=0;j--){
	if(i){
	  itoss=PLAYER_1;
	}
	else{
	  itoss=PLAYER_2;
	}
	  i=!i;
	}
	if(itoss==PLAYER_1){
	  printf("\nPlayer 1 won the toss its his turn");
	}
	else{
	  printf("\nPlayer 2 won the toss its his turn");
	}
	
	return itoss;
}
void sleep_me()
{
  int i=1;
  int j;
  int k;
  printf("\n[ | ]");
  printf("\b\b\b");
  for(;i>0;i--)
  {
	printf("|");
	fflush(stdout);
	sleep(1);
	printf("\b");
	fflush(stdout);
	printf("/");
	fflush(stdout);
	sleep(1);
	printf("\b");
	fflush(stdout);
	printf("--");
	fflush(stdout);
	sleep(1);
	printf("\b\b");
	fflush(stdout);
	printf("\\ ");
	fflush(stdout);
	sleep(1);
	printf("\b\b");
	fflush(stdout);
  }
  printf(" ]");
  fflush(stdout);
}
	
	
	
	
