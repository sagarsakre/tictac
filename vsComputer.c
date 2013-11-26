#include"main.h"
int XPOS,YPOS;
int is_danger(){
  int i,j,sum,zeropos;
  for(i=0;i<3;i++){
	sum=0;
	for(j=0;j<3;j++){
	  if(matrix[i][j]==0)
		zeropos=j;
	  sum+=matrix[i][j];
	}
	
	switch(sum){
	  case PLAYER_2+PLAYER_2: 
		printf("1 computer would play at %d %d ", i,zeropos);
		XPOS=i;
		YPOS=zeropos;
		return 1;
		break;
	  case PLAYER_1+PLAYER_1: 
		printf("2 computer would play at %d %d ", i,zeropos);
		XPOS=i;
		YPOS=zeropos;
		return 1;
		break;
	  default:
		break;
	}
  }

  //check for verticle match
  for(j=0;j<3;j++){
	sum=0;
	for(i=0;i<3;i++){
	  if(matrix[i][j]==0)
		zeropos=i;
	  sum+=matrix[i][j];
	}
	
	switch(sum){
	  case PLAYER_2+PLAYER_2: 
		printf("3 computer would play at %d %d ", zeropos,j);
		XPOS=zeropos;
		YPOS=j;
		return 1;
		break;
	  case PLAYER_1+PLAYER_1: 
		printf("4 computer would play at %d %d ",zeropos,j);
		XPOS=zeropos;
		YPOS=j;
		return 1;
		break;
	  default:
		break;
	}
  }

// diagonal check
  sum=0;
  for(i=0;i<3;i++){
	sum+=matrix[i][i];
	if(matrix[i][i]==0)
	   zeropos=i;
  }
  if((sum==PLAYER_2+PLAYER_2)||(sum==PLAYER_1+PLAYER_1)){
	printf("5 computer would play at %d %d ", zeropos,zeropos);
	XPOS=zeropos;
	YPOS=zeropos;
	return 1;
  }
return 0;
}

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
	printf("6 computer will play at %d %d",pos/3,pos%3);
	XPOS=pos/3;
	YPOS=pos%3;
}
void computer_turn(int *x1,int *y1){
	int pos,i,j;
	if(LEVEL==1){
	  play_random();
	}
	
	else if(LEVEL==2){
	  if(is_danger()){
			*x1=XPOS;
		*y1=YPOS;
		return;
	  }
	//  printf("Level 2 selected");
/*	  for(i=0;i<3;i++)
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
	  */
	  play_random();
	  	*x1=XPOS;
	*y1=YPOS;
	}


}
