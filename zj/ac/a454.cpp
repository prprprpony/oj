#include<cstdio>
#include<cstring>
//#include<iostream>
//doubly-linked list
int node[1001];
int nextn[1001][1001];
//nextn[x][1000]=size of nextn[x]
int dp[1001];

int L_Sum(int n)
{
    if(dp[n]!=0)return dp[n];
    if(nextn[n][1000]==0){dp[n]=node[n];return dp[n];}
    int Sum=0;
    for(int i=1;i<=nextn[n][1000];i++)
    {
        int t=L_Sum(nextn[n][i]);
        Sum=(t>Sum)?t:Sum;
    }
    dp[n]=node[n]+Sum;
    return dp[n];
}

using namespace std;
int main()
{
    /*file
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    */

    int M;
    scanf("%d",&M);
    while(M--)
    {
        int N,ans=0;
        scanf("%d",&N);
        bool is_start[N+1];
        for(int i=1;i<=N;i++)is_start[i]=1;
        memset(dp,0,(N+1)*sizeof(int));

        //input
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&node[i],&nextn[i][1000]);
            for(int j=1;j<=nextn[i][1000];j++)
            {
                int t;
                scanf("%d",&t);
                nextn[i][j]=t;
                is_start[t]=0;
            }
        }
        //test input
        /*
        for(int i=1;i<=N;i++)
        {
            cout<<"is_start["<<i<<"]="<<is_start[i]<<";node["<<i<<"]="<<node[i]<<";nextn amount="<<nextn[i][1000]<<endl;
            for(int j=1;j<=nextn[i][1000];j++)
            {
                cout<<"nextn["<<j<<"]="<<nextn[i][j]<<endl;
            }
        }
        */
        //processing
        for(int i=1;i<=N;i++)
        {
            if(is_start[i])
            {
                int t=L_Sum(i);
                ans=(t>ans)?t:ans;
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
