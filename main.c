#include "main.h"

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
int check_inputs(int x, int y)
{
  //check for the upper boundries
  if(x<0||x>2||y<0||y>2)
  {
    printf("ERROR: out of boundries");
    return 1;
  }
  else if(matrix[x][y]==PLAYER_1||matrix[x][y]==PLAYER_2)
  {
	  printf("ERROR: %d %d is already filled Please select some other box\n",x,y);
	  return 1;
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

	for(i=0;i<3;i++){
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
	initgame();
	//printf("initgame over");
	if(toss()==PLAYER_1)
	{
	}
	else{
	  goto compturn;
	}
	for(i=0;i<8;i++)
	{
	  if(mCount>=9){
		printf("match tie, ");
		exit(0);
	  }
		do{
		printf("\n Matrix is \n");
		printMatrix();
		printf("enter your choice (x,y) : ");
		scanf("%d %d",&x,&y);
		if(check_inputs(x,y))
		  continue;
		 else 
		   break;
		}
		while(1);
		
		matrix[x][y]=PLAYER_1;
		mCount++;
		if(check_match(PLAYER_1))
		{
		printMatrix();
		printf("PLAYER_1 wins");
		exit(0);
		}
compturn:
		do{
		if(gametype==2){
		  sleep_me();
		  computer_turn(&x,&y);
		  if(check_inputs(x,y))
		  continue;
		 else 
		   break;
		}
		else{
		printf("enter your choice Player 2(x,y) : ");
		scanf("%d %d",&x,&y);
		if(check_inputs(x,y))
		  continue;
		 else 
		   break;
		} 
		}while(1);
		printf("\n Matrix is \n");
		//printMatrix();
		matrix[x][y]=PLAYER_2;
		mCount++;
		if(check_match(PLAYER_2))
		{
		printMatrix();
		printf("PLAYER_2 wins");
		exit(0);
		}
}
}
