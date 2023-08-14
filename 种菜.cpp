 #include <stdio.h>
#define N 2
struct menu
{
    int min;
    char name[20];
};
int main()
{
    struct menu a[N],temp;
    int i,j;
    int time;
    printf("请输入您的总时长：\n");
    scanf("%d",&time);
    for(i=0; i<N; i++)
    {
        printf("输入第%d种菜的名称和烹饪时长：",i+1);
        scanf("%s",a[i].name);
        scanf("%d",&a[i].min);
    }
    for(i=0; i<N; i++)
        for(j=0; j<N-i; j++)
            if(a[j].min<a[j-i].min);
    {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
    }
    printf("\n流程已为您规划好\n");
    for(i=0; i<N; i++)
printf("%d %d min 后,放入 %10s\n",i+1,time-a[i].min,a[i].name);
    return 0;
}
//重要: ×
//备注: -
