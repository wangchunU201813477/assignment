#include<stdio.h>
#define n 25
#define m (2*n-1)
#define maxval 10000.0
#define maxsize 100
typedef struct
{
 char ch;
 float weight;
 int lchild,rchild,parent;
}hufmtree;
typedef struct
{
 char bits[n];
 int start;
 char ch;
}codetype;

void huffman(hufmtree tree[]);
void huffmancode(codetype code[],hufmtree tree[]);
void decode(hufmtree tree[]);

void main()
{
 printf("                            ——哈夫曼编码——\n");
 printf("总共有%d个字符\n",n);
 hufmtree tree[m];
 codetype code[n];
 int i,j;
 huffman(tree);
 huffmancode(code,tree);
 printf("【输出每个字符的哈夫曼编码】\n");
 for(i=0;i<n;i++)
 {
  printf("%c: ",code[i].ch);
  for(j=code[i].start;j<n;j++)
   printf("%c ",code[i].bits[j]);
  printf("\n");
 }
 printf("【读入电文，并进行译码】\n");
 decode(tree);
}

void huffman(hufmtree tree[])
{
 int i,j,p1,p2;
 float small1,small2,f;
 char c;
 for(i=0;i<m;i++)
 {
  tree[i].parent=0;
  tree[i].lchild=-1;
  tree[i].rchild=-1;
  tree[i].weight=0.0;
 }
 printf("【依次读入前%d个结点的字符及权值(中间用空格隔开)】\n",n);
 for(i=0;i<n;i++)
 {
  printf("输入第%d个字符为和权值",i+1);
  scanf("%c %f",&c,&f);
  getchar();
  tree[i].ch=c;
  tree[i].weight=f;
 }
 for(i=n;i<m;i++)
 {
  p1=0;p2=0;
  small1=maxval;small2=maxval;
  for(j=0;j<i;j++)
   if(tree[j].parent==0)
    if(tree[j].weight<small1)
    {
     small2=small1;
     small1=tree[j].weight;
     p2=p1;
     p1=j;
    }
    else
     if(tree[j].weight<small2)
     {
      small2=tree[j].weight;
      p2=j;
     }
  tree[p1].parent=i;
  tree[p2].parent=i;
  tree[i].lchild=p1;
  tree[i].rchild=p2;
  tree[i].weight=tree[p1].weight+tree[p2].weight;
 }
}

void huffmancode(codetype code[],hufmtree tree[])

{
 int i,c,p;
 codetype cd;
 for(i=0;i<n;i++)
 {
  cd.start=n;
  cd.ch=tree[i].ch;
  c=i;
  p=tree[i].parent;
  while(p!=0)
  {
   cd.start--;
   if(tree[p].lchild==c)
    cd.bits[cd.start]='0';
   else
    cd.bits[cd.start]='1';
   c=p;
   p=tree[p].parent;
  }
  code[i]=cd;
 }
}

void decode(hufmtree tree[])
{
 int i,j=0;
 char b[maxsize];
 char endflag='2';
 i=m-1;
 printf("输入发送的编码(以'2'为结束标志)：");
 gets(b);
 printf("译码后的字符为");
 while(b[j]!='2')
 {
  if(b[j]=='0')
   i=tree[i].lchild;
  else
   i=tree[i].rchild;
  if(tree[i].lchild==-1)
  {
   printf("%c",tree[i].ch);
   i=m-1;
  }
  j++;
 }
 printf("\n");
 if(tree[i].lchild!=-1&&b[j]!='2')
  printf("\nERROR\n");
}
