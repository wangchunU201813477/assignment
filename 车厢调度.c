#include<stdio.h>
#define MaxLen 100
struct snode{
int data[MaxLen];
int top;
}s;
int n;
void Initstack()
{
s.top=-1;
}
void push(int q)
{
s.top++;
s.data[s.top]=q;
}
int pop()
{
int temp;
temp=s.data[s.top];
s.top--;
return temp;
}
int Emptys()
{
if(s.top==-1)
return 1;
else
return 0;
}
void process(int pos,int path[],int curp)
{
int m,i;
if(pos<n)
{
push(pos+1);
process(pos+1,path,curp);
pop();
}


if(!Emptys())
{
m=pop();
path[curp]=m;
curp++;
process(pos,path,curp);
push(m);
}
if(pos==n&&Emptys())
{
for(i=0;i<curp;i++)
printf("%2d",path[i]);
printf("\n");
}
}
void main()
{
int path[MaxLen];
printf("输入要调度车厢总数:");
scanf("%d",&n);
Initstack();
push(1);
printf("所有输出序列:\n");
process(1,path,0);
}
