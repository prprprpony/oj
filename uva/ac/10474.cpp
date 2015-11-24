#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q,cases=0;
    while(scanf("%d%d",&n,&q)&&(n!=0)&&(q!=0))
    {
        int m[n],que;
        for(int i=0;i<n;i++)
            scanf("%d",&m[i]);
        sort(m,m+n);
        cases++;
        printf("CASE# %d:\n",cases);
        while(q--)
        {
            scanf("%d",&que);
            int p=lower_bound(m,m+n,que)-m;
            if(m[p]==que)printf("%d found at %d\n",que,p+1);
            else printf("%d not found\n",que);
        }
    }

    return 0;
}
