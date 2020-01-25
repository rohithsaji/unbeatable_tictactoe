#include<stdio.h>
int b=0;
struct Ai
{
int i,j;
int score;
};
int Check(char a[3][3])
{
int i,B[8],j ;
for(i=0;i<8;i++)
{
B[i]=0;
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]=='o')
{
if((i==0 && j==0)||(i==0 && j==1)|| (i==0 && j==2))
B[0]++;
if((i==1 && j==0)||(i==1&&j==1)|| (i==1&&j==2))
B[1]++;
if((i==2&&j==0)||(i==2&&j==1)|| (i==2&&j==2))
B[2]++;
if((i==0&&j==0)||(i==1&&j==1)|| (i==2&&j==2))
B[3]++;
if((i==0&&j==2)||(i==1&&j==1)|| (i==2&&j==0))
B[4]++;
if((i==0&&j==0)||(i==1&&j==0)|| (i==2&&j==0))
B[5]++;
if((i==0&&j==1)||(i==1&&j==1)|| (i==2&&j==1))
B[6]++;
if((i==0&&j==2)||(i==1&&j==2)|| (i==2&&j==2))
B[7]++;
}
}
}
for(i=0;i<8;i++)
{
if(B[i]==3)
return 1;
}
for(i=0;i<8;i++)
{
B[i]=0;
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]=='x')
{
if((i==0&&j==0)||(i==0&&j==1)|| (i==0&&j==2))
B[0]++;
if((i==1&&j==0)||(i==1&&j==1)|| (i==1&&j==2))
B[1]++;
if((i==2&&j==0)||(i==2&&j==1)|| (i==2&&j==2))
B[2]++;
if((i==0&&j==0)||(i==1&&j==1)|| (i==2&&j==2))
B[3]++;
if((i==0&&j==2)||(i==1&&j==1)|| (i==2&&j==0))
B[4]++;
if((i==0&&j==0)||(i==1&&j==0)|| (i==2&&j==0))
B[5]++;
if((i==0&&j==1)||(i==1&&j==1)|| (i==2&&j==1))
B[6]++;
if((i==0&&j==2)||(i==1&&j==2)|| (i==2&&j==2))
B[7]++;
}
}
}
for(i=0;i<8;i++)
{
if(B[i]==3)
return 2;
}
return 0;
}
void Print(char a[3][3])
{
printf("****************\n");
printf("*  %c  *  %c  *  %c  *\n",a[0][0],a[0][1],a[0][2]);
printf("****************\n");
printf("*  %c  *  %c  *  %c  *\n",a[1][0],a[1][1],a[1][2]);
printf("****************\n");
printf("*  %c  *  %c  *  %c  *\n",a[2][0],a[2][1],a[2][2]);
printf("****************\n");
}
int END(char a[3][3])
{
int i,j,b=0;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(a[i][j]!=0)
b++;
}
}
if(b==9)
return 1;
else
return 0;
}
struct Ai AI(char a[3][3])
{
struct Ai A[10];
//static int b=1;
int x,k=-1;
int i,j;
b++;
//printf("*************\n B=%d\n",b);
//printf("11111111\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
//printf("222222\n");
  if(a[i][j]==0)
{
//printf("222222\n");
if(b%2==0)
a[i][j]='x';
else
a[i][j]='o';
//Print(a);
k++;
A[k].i=i;
A[k].j=j;
x=Check(a);
if(x==1)
{
//printf("first\n");
A[k].score=10;
}
else if(x==2)
{
//printf("second\n");
A[k].score=-10;
}
else 
{
if(END(a))
{
//printf("000000000000\n");
A[k].score=0;
}
else
{
//printf("8888888\n");
A[k].score=AI(a).score;
//a[i][j]=0;
}
}
//Print(a);
a[i][j]=0;
//printf("###### DELETE %d %d "  ,i,j);
}
}
}
if(b%2==0)
{
int small=0;
for(i=0;i<=k;i++)
{
//printf("%d= %d \n",i+1,A[i].score);
if(A[i].score<A[small].score)
small=i;
}
b--;
return A[small];
}
else
{
int big=0;
for(i=0;i<=k;i++)
{
//printf("%d= %d \n",i+1,A[i].score);
if(A[i].score>A[big].score)
big=i;
}
b--;
return A[big];
}
}




void main()
{
int i ,j;
char c;
int I,J;
int k;
struct Ai A;
//char a[3][3]={0,0,'o','o',0,0,'o','x','x'};
char a[3][3];
BEGIN:
for(i=0;i<3;i++)
for(j=0;j<3;j++)
a[i][j]=0;
printf("***************** TIC TAC TOE ****************\n");
//Print(a);
printf("YOU ARE 'X'!!!\n");
while(!END(a))
{

//system("clear");
Print(a);
start:
printf("Enter x y coordinates (123)\n");
scanf("%d %d",&i,&j);

if(!((i>=1&&i<=3) && (j>=1&&j<=3)))
{
printf("i=%d j=%d",i,j);
printf("INVALID INPUT!!!\n");
i=0;j=0;
goto start;
}
if(a[i-1][j-1]!=0)
{
printf("CANNOT BE PLACED THERE!\n");
goto start;
}
//printf("*********");
I=i-1;
J=j-1;
a[I][J]='x';
//system("clear");
A=AI(a);
I=A.i;
J=A.j;
a[I][J]='o';
//Print(a))
if(Check(a)==1)
{
printf(" YOU LOST CANT BEAT ME!!!\n");
break;
}
b=0;
}
Print(a);
if(END(a))
{
printf("GAME IS TIED!!!!\n");
}
END:
printf("DO YOU WANT TO PLAY AGAIN?(y/n)\n");
scanf("%c",&c);
if(c!='y'&&c!='n')
{
printf("INVALID INPUT!");
goto END;
}
else
goto BEGIN;
}
