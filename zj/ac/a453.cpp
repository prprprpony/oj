#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int M,a,b,c;
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int D=b*b-4*a*c;
        if(D<0)printf("No\n");
        else if(D==0)printf("Yes\n");
        else if(floor(sqrt(D))*floor(sqrt(D))==D)printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
