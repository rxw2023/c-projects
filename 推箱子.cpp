
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define WIDTH 8
#define HEIGHT 8
int map[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 4, 1, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 3, 0, 3, 4, 1},
	{1, 4, 0, 3, 2, 1, 1, 1},
	{1, 1, 1, 1, 3, 1, 0, 0},
	{0, 0, 0, 1, 4, 1, 0, 0},
	{0, 0, 0, 1, 1, 1, 0, 0}
};
int x,y;//人的位置 
int boxs;//箱子的个数
/*
0 空
1 墙
2 人
3 箱子
4 目的地(球)
5 已完成的箱子
*/ 
void initData();
void drawMap();
void moveUp();
void moveLeft();
void moveDown();
void moveRight(); 
int main(int argc, char *argv[] ){
	char direction;//存键盘的方向 
	initData();   //初始化数据 
    while(1){
	system("cls");
	drawMap();
	if(!boxs){
		break;
	}
	direction=getch();
	switch(direction){
		case 'w':
			moveUp();
			break;
		case 'a':
			moveLeft();
			break;
		case 's':
			moveDown();
			break;
		case 'd':
			moveRight();
			break;
	} 
}
printf("恭喜你完成游戏！*");
return 0;
}
void initData(){
int i,j;
printf("游戏加载中，请稍后......");
for(i=0;i<HEIGHT;i++){
	for(j=0;j<WIDTH;j++){
		if(map[i][j]==2){
			x=j;
			y=i;
		}
		if(map[i][j]==3){
			boxs++;
		}
	}
}
}
void drawMap( ){
	int i,j;
	for(i=0;i<WIDTH;i++){
		for(j=0;j<HEIGHT;j++){
			switch(map[i][j]){
				case 0:
				      printf("  ");
				      break;
				case 1:
					  printf("■");
					  break;
				case 2:
					  printf("♀");
					  break;
				case 3:
				      printf("◆");
					  break;
			    case 4:
				      printf("●");
				      break;
				case 5:
					  printf("★");
					  break;
			}
		}
		printf("\n");
	}
}
void moveUp(){
	//定义变量存放人物上方的坐标
	int ux, uy; 
	
	//当上方没有元素时，直接return	
	if(y == 0){
		return;
	}
	
	//记录上方坐标
	ux = x;
	uy = y - 1; 
	
	//上方为已完成方块
	if(map[uy][ux] == 5){
		return;
	} 
	
	//假设上方为墙，直接return 
	if(map[uy][ux] == 1){
		return;
	}
	
	//假设上方为箱子
	if(map[uy][ux] == 3){
		//判断箱子上方是否为墙 
		if(map[uy - 1][ux] == 1){
			return;
		}
		
		//判断箱子上方是否为球
		if(map[uy - 1][ux] == 4){
			//将箱子上面内容赋值为5★ 
			map[uy - 1][ux] = 5;
			map[uy][ux] = 0;
					
			//箱子的数目减1	
			boxs--; 
		}else{
			//移动箱子
			map[uy - 1][ux] = 3;
		}
	}
	map[y][x] = 0;
	map[uy][ux] = 2;
	y = uy; 
} 
void moveLeft(){
	//定义变量存放人物左边的坐标
	int lx, ly; 
	
	//当左边没有元素时，直接return	
	if(x == 0){
		return;
	}
	
	//记录左边坐标
	lx = x - 1;
	ly = y; 
	
	//左边为已完成方块
	if(map[ly][lx] == 5){
		return;
	} 
	
	//假设左边为墙，直接return 
	if(map[ly][lx] == 1){
		return;
	}
	
	//假设左边为箱子
	if(map[ly][lx] == 3){
		//判断箱子左边是否为墙 
		if(map[ly][lx - 1] == 1){
			return;
		}
		
		//判断箱子左边是否为球
		if(map[ly][lx - 1] == 4){
			//将箱子左边内容赋值为5★ 
			map[ly][lx - 1] = 5;
			map[ly][lx] = 0;
		
			//箱子的数目减1 
			boxs--; 
		}else{
			//移动箱子 
			map[ly][lx - 1] = 3; 
		}
	}
	map[y][x] = 0;
	map[ly][lx] = 2;
	x = lx; 
}

void moveDown(){
	//定义变量存放人物下方的坐标
	int dx, dy; 
	
	//当下方没有元素时，直接return	
	if(y == HEIGHT - 1){
		return;
	}
	
	//记录下方坐标
	dx = x;
	dy = y + 1; 
	
	//下方为已完成方块
	if(map[dy][dx] == 5){
		return;
	} 
	
	//假设下方为墙，直接return 
	if(map[dy][dx] == 1){
		return;
	}
	
	//假设下方为箱子
	if(map[dy][dx] == 3){
		//判断箱子下方是否为墙 
		if(map[dy + 1][dx] == 1){
			return;
		}
		
		//判断箱子下方是否为球
		if(map[dy + 1][dx] == 4){
			//将箱子下面内容赋值为5★ 
			map[dy + 1][dx] = 5;
			map[dy][dx] = 0;
			
			//箱子的数目减1 
			boxs--; 
		}else{
			//移动箱子
			map[dy + 1][dx] = 3; 
		}
	}
	map[y][x] = 0;
	map[dy][dx] = 2;
	y = dy; 
}

void moveRight(){
	//定义变量存放人物右边的坐标
	int rx, ry; 
	
	//当右边没有元素时，直接return	
	if(x == WIDTH - 1){
		return;
	}
	
	//记录右边坐标
	rx = x + 1;
	ry = y; 
	
	//右边为已完成方块
	if(map[ry][rx] == 5){
		return;
	} 
	
	//假设右边为墙，直接return 
	if(map[ry][rx] == 1){
		return;
	}
	
	//假设右边为箱子
	if(map[ry][rx] == 3){
		//判断箱子右边是否为墙 
		if(map[ry][rx + 1] == 1){
			return;
		}
		
		//判断箱子左边是否为球
		if(map[ry][rx + 1] == 4){
			//将箱子右边内容赋值为5★ 
			map[ry][rx + 1] = 5;
			map[ry][rx] = 0;
			
			//箱子的数目减1 
			boxs--; 
		}else{
			//移动箱子 
			map[ry][rx + 1] = 3; 
		}
	}
	map[y][x] = 0;
	map[ry][rx] = 2;
	x = rx; 
}
