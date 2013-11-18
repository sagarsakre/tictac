#include"main.h"
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
