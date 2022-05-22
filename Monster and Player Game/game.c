// Name and Surname - Javad Ibrahimli
// ITU ID number - 040210932

//In the first part of the code I added headers which I need to use for my project.
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h> 

//It is my function prototypes
void mapplotter(char a[][33]); 

//Main function starts
int main(){
	
	printf("Welcome to Monster and Player game.\nTry to escape from Monster.\n"); // here i added my intro 
	
	char map[17][33];
	//Here i initialized the design elements of my Map
	for(int m=0;m<17;m++){
		for(int n=0;n<33;n++){
			if(m==0){ 
				if(n%2==0){			//ceiling
					map[m][n]=' ';
				}
				else
					map[m][n]='_'; //floor
			}else{
				if(n%2==0){
					map[m][n]='|'; //left side
				}
				else
					map[m][n]='_'; //right side
			}
		}
	}
	//Here I set the locations of Walls and Escape point. ( I set escape point and  according to Word document about C project tasks)
	map[3][19]='W'; map[4][19]='W'; map[9][5]='W'; map[10][5]='W'; map[3][27]='W'; map[4][27]='W'; map[6][13]='W'; map[6][15]='W'; map[6][17]='W'; map[7][13]='W'; map[10][7]='W'; map[10][9]='W'; map[10][11]='W'; map[11][11]='W'; map[9][21]='W'; map[10][21]='W'; map[11][21]='W'; map[12][21]='W'; map[12][23]='W'; map[15][5]='W'; map[15][5]='W'; map[15][7]='W'; map[8][1]='E';
	
	//using getchar, I get difficulty level 
	int mx,my,px,py=0;  // here i set variables for 2 main x and y locations of elements in game
	int gameruns=1; int again=1; int difficulty,e; int turn=0;
		while(gameruns){
			if(again){
				printf("Difficulty levels:\n Press 1 for Easy Mode\n Press 2 for Hard Mode\n"); 
			}
			while(again){
				if(scanf("%d",&difficulty)==0){ 
					e=getchar();
					while(e!='\n'&&e!=EOF){		
						e=getchar();
					}
				}
				if(difficulty==1||difficulty==2){ //here i used if  else statements for choosing the best difficulty level for game
					break;
				}
				else{
					
					printf("Please enter 1 for EASY and 2 for HARD mode.\n");  //It runs when input is invalid ( not 1 or 2)
				}
			}
			if(again){		
				srand(time(NULL));   //Location of Player and Monster
				do{
					px=rand()%16+1; py=rand()%16+1;		//Manhattan distance between Player and escape point shouldn't be less than 16
				}while((abs(px-1)+abs(py-8))<16 || map[py][2*px-1]=='W');
				do{
					mx=rand()%16+1; my=rand()%16+1;		// distance between monster and player can not be less than 16
				}while((abs(mx-px)+abs(my-py))<16 || map[my][2*mx-1]=='W');
				map[py][2*px-1]='P'; map[my][2*mx-1]='M';
				again=0;
				mapplotter(map);
			}
			//Main move variants of Player( I used Boolean)
			int move;
			printf("Move your player\n 'W' for move up.\n 'A' for left. \n 'D' for right.\n 'S' for down. " );
			while(turn==0){				
				move=getchar();
				if (move!='\n'){
					switch(move){   // I used switch- cases in order to declare that uppercase and lowercase letters are same
						case 'W':
						case 'w':
							if(map[py-1][2*px-1]!='W'&& (py-1)>0){
								map[py][2*px-1]='_';
								py--;
								map[py][2*px-1]='P';  // every up,down,left and right command did the same things in different directions.
								turn=1;
							}
							else{
								goto hitwall; 
							}
							break;
						case 'A':
						case 'a':
							if(map[py][2*(px-1)-1]!='W'&& (px-1)>0){  //It  moves removes the '_' and changes it to player's icon, then changes previous  place of icon to '_'
								map[py][2*px-1]='_';
								px--;
								map[py][2*px-1]='P';
								turn=1;
							}else{
								goto hitwall;
							}
							break;
						case 'S':
						case 's':
							if(map[py+1][2*px-1]!='W'&&(py+1)<17){
								map[py][2*px-1]='_';
								py++;
								map[py][2*px-1]='P';
								turn=1;
							}else{
								goto hitwall;
							}
							break;
						case 'D':
						case 'd':
							if(map[py][2*(px+1)-1]!='W'&&(px+1)<17){
								map[py][2*px-1]='_';
								px++;
								map[py][2*px-1]='P';
								turn=1;
							}else{
								goto hitwall;
							}
							break;
						hitwall:
						default:
							printf("Enter a turn move.\n");
							break;
					}
				}
			}
			turn=difficulty;		//this statement chekcs both for hardness and Monster's turn end
			
			//There I designed a code for Easy mode
			int direct;
			while(turn==1){
				direct=rand()%4;  //0:up 1:left 2:down 3:right
				switch(direct){
					case 0:
						if(map[my-1][2*mx-1]!='W'&&(my-1)>0 &&map[my-1][2*mx-1]!='E'){
							map[my][2*mx-1]='_';
							my--;
							map[my][2*mx-1]='M';
							turn=0;
						}
						break;
					case 1:
						if(map[my][2*(mx-1)-1]!='W'&&(mx-1)>0 &&map[my][2*(mx-1)-1]!='E'){
							map[my][2*mx-1]='_';
							mx--;
							map[my][2*mx-1]='M';
							turn=0;
						}
						break;
					case 2:
						if(map[my+1][2*mx-1]!='W'&&(my+1)<17&&map[my+1][2*mx-1]!='E'){
							map[my][2*mx-1]='_';
							my++;
							map[my][2*mx-1]='M';
							turn=0;
						}
						break;
					case 3:
						if(map[my][2*(mx+1)-1]!='W'&&(mx+1)<17 &&map[my][2*(mx+1)-1]!='E'){
							map[my][2*mx-1]='_';
							mx++;
							map[my][2*mx-1]='M';
							turn=0;
						}
						break;	
				}
			}
			//There I designed code for Hard mode
			int a,b,f;	
			f=0;
			while(turn==2){
				f++;
				direct=random()%2;
				a=0; b=0;
				if((mx-px)>0){		//Player is left of monster
					if((my-py)>0){		//Player is above from Monster
						if(map[my-1][2*mx-1]!='W'&&(my-1)>0 &&map[my-1][2*mx-1]!='E'){		//up
							a=1;
						}
						if(map[my][2*(mx-1)-1]!='W'&&(mx-1)>0 &&map[my][2*(mx-1)-1]!='E'){	//left
							b=1;
						}
						if(a==1&&b==1){					
							if(direct){
								map[my][2*mx-1]='_';
								my--;
								map[my][2*mx-1]='M';
								turn=1;
							}if(!direct){
								map[my][2*mx-1]='_';
								mx--;
								map[my][2*mx-1]='M';
								turn=1;
							}
						}else if(a==1&&b==0){				//up side
							map[my][2*mx-1]='_';
								my--;
								map[my][2*mx-1]='M';
								turn=1;
						}if(b==1&&a==0){					//left side
							map[my][2*mx-1]='_';
								mx--;
								map[my][2*mx-1]='M';
								turn=1;
						}
					}else{				//Player is located below the monster
						if(map[my][2*(mx-1)-1]!='W'&&(mx-1)>0 &&map[my][2*(mx-1)-1]!='E'){		//left
							a=1;
						}
						if(map[my+1][2*mx-1]!='W'&&(my+1)<17&&map[my+1][2*mx-1]!='E'){	//down
							b=1;
						}
						if(a==1&&b==1){				
							if(direct){
								map[my][2*mx-1]='_';
								mx--;
								map[my][2*mx-1]='M';
								turn=1;
							}if(!direct){
								map[my][2*mx-1]='_';
								my++;
								map[my][2*mx-1]='M';
								turn=1;
							}
						}else if(a==1&&b==0){				//left
								map[my][2*mx-1]='_';
								mx--;
								map[my][2*mx-1]='M';
								turn=1;
						}if(b==1&&a==0){					//down
								map[my][2*mx-1]='_';
								my++;
								map[my][2*mx-1]='M';
								turn=1;
						}
					}
				}
				else{				//Player is located right side of Monster
					if((my-py)>0){		//Player is located above of monster
						if(map[my][2*(mx+1)-1]!='W'&&(mx+1)<17 &&map[my][2*(mx+1)-1]!='E'){		//right
							a=1;
						}
						if(map[my-1][2*mx-1]!='W'&&(my-1)>0 &&map[my-1][2*mx-1]!='E'){	//up
							b=1;
						}
						if(a==1&&b==1){					
							if(direct){
								map[my][2*mx-1]='_';
								mx++;
								map[my][2*mx-1]='M';
								turn=1;
							}if(!direct){
								map[my][2*mx-1]='_';
								my--;
								map[my][2*mx-1]='M';
								turn=1;
							}
						}else if(a==1&&b==0){				//right
							map[my][2*mx-1]='_';
							mx++;
							map[my][2*mx-1]='M';
							turn=1;
						}if(b==1&&a==0){					//up
							map[my][2*mx-1]='_';
							my--;
							map[my][2*mx-1]='M';
							turn=1;
						}
					}else{				//player is located below from monster
						if(map[my][2*(mx+1)-1]!='W'&&(mx+1)<17 &&map[my][2*(mx+1)-1]!='E'){		//up
							a=1;
						}
						if(map[my+1][2*mx-1]!='W'&&(my+1)<17&&map[my+1][2*mx-1]!='E'){	//left
							b=1;
						}
						if(a==1&&b==1){					
							if(direct){
								map[my][2*mx-1]='_';
								mx++;
								map[my][2*mx-1]='M';
								turn=1;
							}if(!direct){
								map[my][2*mx-1]='_';
								my++;
								map[my][2*mx-1]='M';
								turn=1;
							}
						}else if(a==1&&b==0){				//right
							map[my][2*mx-1]='_';
							mx++;
							map[my][2*mx-1]='M';
							turn=1;
						}if(b==1&&a==0){					//down
							map[my][2*mx-1]='_';
							my++;
							map[my][2*mx-1]='M';
							turn=1;
						}
					}
				}
				if (f>5){		//I designed this part of code in order to mitigate the problem of infinite loop - bug. 
						turn=1;
					}
			}
			turn=0;
			system("clear"); // I used clar system
			mapplotter(map);
			
			//How to now if player  can't win 
			char c; //temp value yes or no
			int end=1;
			while((abs(px-mx)+abs(py-my))<=1){
				if(end==1){		//Here i used printf in order to show lose message
					printf("Monster catched you. Game Over.\nPlay again? Y/N\n");
				}
				scanf("%c%c",&c,&c);  //I took 2 c.
				if(c=='Y'||c=='y'){   // I wrote code in order to declare that uppercase and lowercase letter is same
					again=1;
					map[my][2*mx-1]='_'; map[py][2*px-1]='_';
					break;
				}else if(c=='N'||c=='n'){
					gameruns=0;
					break;
				}else{
					end=0;
					printf("Please type in Y for yes or N for no.\n");   // In case input is invalid
				}
			}
			//How to check if player won
			while(px==1 && py==8){
				if(end==1){			
					printf("Your player won. You escaped from Monster. \nPlay again? Y/N?\n"); //won message
				}
				scanf("%c%c",&c,&c);
				if(c=='Y'||c=='y'){
					again=1;
					map[py][2*px-1]='E'; map[my][2*mx-1]='_';
					break;
				}else if(c=='N'||c=='n'){
					gameruns=0;
					break;
				}else{
					end=0;
					printf("Please type in Y for yes or N for no.\n"); 
				}
			}
		}
return 0;
}

void mapplotter(char a[][33]){   //structure of mapplotter function  
	for(int i=0;i<17;i++){
		for(int j=0;j<33;j++){
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
}

//THANKS FOR PLAYING
