#include<stdio.h>
#define PLAYER_1 -1
#define PLAYER_2 1
int matrix[3][3];
void initMatrix()
{
	int i=0,j=0;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		matrix[i][j]=0;
}
void printMatrix()
{
int i,j;
  for(i=0;i<3;i++)
	{
	  printf("     ");
	for(j=0;j<3;j++)
	if(matrix[i][j]==PLAYER_1)
	printf(" x ");
	else if(matrix[i][j]==PLAYER_2)
	printf(" o ");
	else 
	    printf(" - ");
	printf("\n");
	}
}
int check_match(int PLAYER) 
{
	int i;
//	compare horizaontally
	for(i=0;i<3;i++)
	{
	if(matrix[i][0]==PLAYER&&matrix[i][1]==PLAYER&&matrix[i][2]==PLAYER)
	return 1;
	}
//	compare vertically
	for(i=0;i<3;i++)
	{
	if(matrix[0][i]==PLAYER&&matrix[1][i]==PLAYER&&matrix[2][i]==PLAYER)
	return 1;
	}
	if(matrix[0][0]==PLAYER&&matrix[1][1]==PLAYER&&matrix[2][2]==PLAYER)
	return 1;
	
	if(matrix[0][2]==PLAYER&&matrix[1][1]==PLAYER&&matrix[2][0]==PLAYER)
	return 1;
	return 0;

		
}
void main()
{
	int i,x=0,y=0,j;
	initMatrix();
	for(i=0;i<4;i++)
	{
		do{
		printf("Matrix is \n");
		printMatrix();
		printf("enter your choice (x,y) : ");
		scanf("%d %d",&x,&y);
		if(matrix[x][y]==PLAYER_1||matrix[x][y]==PLAYER_2)
		{
		  printf("ERROR: %d %d is already filled Please select some other box\n",x,y);
		  continue;
		}
		 else 
		   break;
		}
		while(1);
		matrix[x][y]=PLAYER_1;
		if(check_match(PLAYER_1))
		{
		printMatrix();
		printf("PLAYER_1 wins");
		exit(0);
		}
		do{
		printf("Matrix is \n");
		printMatrix();
		printf("enter your choice Player 2(x,y) : ");
		scanf("%d %d",&x,&y);
		if(matrix[x][y]==PLAYER_1||matrix[x][y]==PLAYER_2)
		{
		  printf("ERROR: %d %d is already filled Please select some other box\n",x,y);
		  continue;
		}
		 else 
		   break;
		}
		while(1);
                matrix[x][y]=PLAYER_2;
		if(check_match(PLAYER_2))
		{
		printMatrix();
		printf("PLAYER_2 wins");
		exit(0);
		}
	}
	
}
