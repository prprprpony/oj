#include<algorithm>
#include<cstdio>
using namespace std;
int box[55],w[1005],M,N;
bool iddfs( int num , int prev_box )
{
    if( num == -1 )return true;
    for(int i=( ( prev_box>=0 && w[num]==w[num+1] )?prev_box:0 ) ; i < M ; i++ )
    {
        if(w[num]>box[i])continue;

        box[i]-=w[num];
        bool result=iddfs(num-1,i);
        box[i]+=w[num];
        if(result)return true;
    }
    return false;
}


int main()
{
    //freopen("in.txt","r",stdin);
    while( scanf("%d%d",&M,&N) != EOF )
    {
        int boxsum=0;
        for(int i=0;i<M;i++)
        {
            scanf("%d",&box[i]);
            boxsum+=box[i];
        }
        for(int i=0;i<N;i++)scanf("%d",&w[i]);

        sort(box,box+M);
        sort(w,w+N);

        int depth,wsum=0;
        for(depth=0;depth<N;depth++)
        {
            wsum+=w[depth];
            if( wsum > boxsum )
            {
                //printf("wsum(%d) > boxsum(%d)\n",wsum,boxsum);
                break;
            }
            if( w[depth] > box[M-1] )
            {
                //printf(" w[%d] > box[%d] \n",depth,M-1);
                break;
            }

            if( !iddfs(depth,-1) )
            {
                //printf(" iddfs(%d) false \n",depth);
                break;
            }
        }

        printf("%d\n",depth);

    }

    return 0;
}
