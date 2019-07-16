#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int id;
int math;
int English;
int C;
int average;
char name[20];
}Stu;

int main()
{
int i = 0;
int average = 0;
Stu data[5];
FILE* fp;

printf("請輸入五位同學的資料:\n");

for(int idx = 0;idx < 5; ++idx)
{
printf("學號 名字 數學 英文 程式\n");
scanf("%d %s %d %d %d",&(data[idx].id),data[idx].name,&(data[idx].math),&(data[idx].English),&(data[idx].C));

data[idx].average = (data[idx].math+data[idx].English+data[idx].C)/3;

}

if((fp=fopen("stud","w")) == NULL )
{
printf("open error!!!\n");
exit(0);
}

for(int idx = 0; idx <5 ;++idx)
{
fprintf(fp,"%d %s %d %d %d %d\n",data[idx].id,data[idx].name,data[idx].math,data[idx].English,data[idx].C,data[idx].average);

}
fclose(fp);

return 0;
}

