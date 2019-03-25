#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
    int num;
    int password;
    struct Node *next;
}list;
list *head,*p,*s;

int circulation(int n)
{
    int i;
    head=(list*)malloc(sizeof(list));
    p=head;
    for(i=1;i<n;i++)
    {
        s=(list*)malloc(sizeof(list));
        p->next=s;
        p=s;
    }
    p->next=head;
    s=head;
    return 0;
}

int input(int n)
{
    int i,k;
    printf("\n«Î ‰»Î√‹¬Î: \n");
    for( i=1;i<=n;i++)
    {
        scanf("%d",&k);
        s->num=i;
        s->password=k;
        s=s->next;
    }
    s=p;
    return 0;
}

int output(int m,int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<m;j++)
        {
            s=s->next;
        }
        p=s->next;
        m=p->password;
        printf("%d ",p->num);
        s->next=p->next;
        free(p);
    }
    return 0;
}
void main()
{   int m,n;
    printf(" ‰»Î m    n: \n");
    scanf("%d %d",&m,&n);
    circulation( n);
    input( n);
    printf("\nÀ≥–Ú:\n");
    output( m,n);
}
