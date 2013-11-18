#include"main.h"
void computer_turn(){
	int pos;
	if(LEVEL==1){
	do{
	pos=rand()%9;
	}while(check_inputs(pos/3,pos%3));
	printf("computer will play at %d %d",pos/3,pos%3);
	}
	else if(LEVEL==2){
	
	}
	}
