#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() { //康威生命游戏。版本 1：仅用单个 main 函数实现
 const int HT = 23, WD = 39, RATE = 30;
 int map[HT + 2][WD + 2] = {0}; //游戏地图（中心为游戏区域，四周为空）
 int bak[HT + 2][WD + 2] = {0}; //更新前用于备份当前地图
 int ix, iy, n;
 //初始化
 srand(time(0)); //初始化随机数种子
 for (iy = 1; iy <= HT; iy++) //行循环
  for (ix = 1; ix <= WD; ix++) //列循环
   map[iy][ix] = ((rand() % 100) < RATE) ? 1 : 0; //初始化地图
 printf("康威生命游戏\n 地图行数: %d, 列数: %d\n", HT, WD);
 printf("初始存活率：%d%%\n 按回车键开始", RATE);
 getchar();                                                                                                                                                                                                                                                                       
 int count = 0; //更新轮数
 while (1) { //无限循环，中途可用 break 退出
  //绘制地图
  for (iy = 1; iy <= HT; iy++) { //行循环
   for (ix = 1; ix <= WD; ix++) //列循环
    printf((map[iy][ix] ? "[]" : " "));
   printf("\n");
  }
  printf("生命游戏。更新轮数：%d \n 回车键更新，x 退出", ++count);
//  if (getchar() == 'x') //获取字符用作判断。x 键退出
//   break;
//  sleep(1);
  system("cls");
  //复制当前地图数据用于更新
  for (iy = 1; iy <= HT; iy++)
   for (ix = 1; ix <= WD; ix++)
    bak[iy][ix] = map[iy][ix];
  //计算每个格点周围的生命体个数并据此更新其生死状态
  for (iy = 1; iy <= HT; iy++) {
   for (ix = 1; ix <= WD; ix++) {
    n = bak[iy-1][ix-1] + bak[iy-1][ix] + bak[iy-1][ix+1]
    + bak[iy][ix-1] + bak[iy][ix+1]
    + bak[iy+1][ix-1] + bak[iy+1][ix] + bak[iy+1][ix+1];
    if (n <= 1) map[iy][ix] = 0; //稀少而死亡
    //if (n == 2 || n == 3) map[iy][ix] = map[iy][ix];//不变
    if (n == 3 && map[iy][ix] == 0) map[iy][ix] = 1; //繁殖
    if (n >= 4) map[iy][ix] = 0; //过多而死亡
   }
  }
 }
 printf("\n 游戏结束。谢谢使用。");
 return 0;
}
//重要: ×
//备注: -
