#include<cstdio>
#include<stack>
using namespace std;

typedef struct
{
    int p;
    int n;
} position;

position p[25];

stack<int> pile[25];
stack<int> tmp;

int n;


void clearup(int b)
{
    int op=p[b].p;
    int r;
    r=pile[op].top;
    while(r!=b)
    {
        pile[op].pop;
        p[r].p=r;
        p[r].n=p[pile[r].top].n+1;
        pile[r].push(r);
        r=pile[op].top;
    }
}
void moveb(int o1,int o2,char m)
{
    clearup(o1);
    if(m=='n')clearup(o2);
    pile[p[o1].p].pop;
    pile[p[o2].p].push(o1);
    p[o1].p=p[o2].p;
    p[o1].n=p[o2].n+1;
}
void pileb(int o1,int o2,char m)
{
    int t=0
    if(m=='n')clearup(o2);
    while(pile[p[o1.p]].top!=o1)
    {
        tmp.push(pile[p[o1].p].top);
        pile[p[o1.p]].pop;
        t++;
    }
    moveb(o1,o2,'v');
    for(int i=0;i<t;i++)
    {
        p[tmp.top].p=p[pile[o2].top].p;
        p[tmp.top].n=p[pile[o2].top].n+1;
        pile[p[o2].p].push(tmp.top);
        tmp.pop;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p[n].p=n;
        p[n].n=0;
        pile[i].push(i);
    }
    char c1[5],c2[5];
    int o1,o2;
    while(scanf("%s",c1)&&c1[0]!=q)
    {
        scanf("%d%s%d",&o1,c2,&o2);
        switch(c1[0])
        {
            case 'm':
                moveb(o1,o2,c2[1]);
                break;
            case 'p':
                pileb(o1,o2,c2[1])
                break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d:",n)
        int s=pile[i].size/sizeof(int);
        char prt[25];
        for(int k=s-1;k>=0;k--)
        {
            prt[k]=pile[i].top;
            pile[i].pop;
        }
        for(int j=0;j<s;j++)
            printf(" %d",prt[j]);
        printf("\n");
    }

    return 0;
}
