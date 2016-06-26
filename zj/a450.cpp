#include<cstdio>
#include<algorithm>
using namespace std;


inline int LowerBound(int* arr,int n,int val)
{
    int left=0,right=n-1,mid;
    mid=(left+right)/2;

    while( right > left )
    {
        if( *(arr+mid) >= val )
            right=mid;
        else
            left=mid+1;

        mid=(left+right)/2;
    }

    return mid;
}

inline int UpperBound(int* arr,int n,int val)
{
    int left=0,right=n-1,mid;
    mid=(left+right)/2;

    while( right > left )
    {
        if( *(arr+mid) > val )
            right=mid;
        else
            left=mid+1;

        mid=(left+right)/2;
    }

    return ( *(arr+mid) <= val )?mid+1:mid;
}



int main()
{
    int n,q;
    while( scanf("%d%d",&n,&q) != EOF )
    {
        int len[n];
        for(int i=0;i<n;i++)
            scanf("%d",&len[i]);

        sort( len , len+n );

        /*
        printf("\nsorted array=\n");
        for(int i=0;i<n;i++)
            printf("%d ",len[i]);
        printf("\n\n");
        */

        int a,b;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&a,&b);
            int left,right;
            left=LowerBound(len,n,a);
            right=UpperBound(len,n,b)-1;

            int ans=right-left+1;

            /*
            printf("\nQ%d left=%d right=%d\n",i,left,right);
            printf("number in the range:\n");
            for(int j=left;j<=right;j++)
                printf("%d ",len[j]);
            printf("\n\n");
            */

            if(ans)printf("%d\n",ans);
            else printf("The candies are too short\n");
        }
    }

    return 0;
}
