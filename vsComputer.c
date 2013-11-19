#include"main.h"
int is_row(int i)
{
  int j,sum=0;
  for(j=0;j<3;j++)
  {
	if(matrix[i][j]==PLAYER_1)
	  return 0;
	sum+=matrix[i][j];
  }
  if (sum==PLAYER_2+PLAYER_2)
	  for(j=0;j<3;j++)
	  {
		if(matrix[i][j]==0)
		  return j;
	  }
}
int is_col(int j)
{
  int i,sum=0;
  for(i=0;i<3;i++)
  {
	if(matrix[i][j]==PLAYER_1)
	  return 0;
	sum+=matrix[i][j];
  }
  if (sum==PLAYER_2+PLAYER_2)
	  for(i=0;i<3;i++)
	  {
		if(matrix[i][j]==0)
		  return i;
	  }
}

void play_random()
{
  int pos;
	do{
	pos=rand()%9;
	}while(check_inputs(pos/3,pos%3));
	printf("computer will play at %d %d",pos/3,pos%3);
}
void computer_turn(){
	int pos,i,j;
	if(LEVEL==1){
	  play_random();
	}
	
	else if(LEVEL==2){
	  printf("Level 2 selected");
	  for(i=0;i<3;i++)
	  {
		if(j=is_row(i)){
		  printf("computer will play at %d %d",i,j);
		  return;
		}
	  }
	  
	  for(j=0;j<3;j++)
	  {
		if(i=is_col(j)){
		  printf("computer will play at %d %d",i,j);
		  return;
		}
	  }
	  play_random();
	}
}
