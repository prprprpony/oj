#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    while( scanf("%d%d%d",&a,&b,&c) != EOF )
    {
        int D = b*b - 4*a*c;

        if(D<0)printf("No real root\n");
        else if( D == 0 )printf("Two same roots x=%d\n", -b/2/a );
        else printf("Two different roots x1=%d , x2=%d\n", (-b+ (int)(sqrt(D)+0.5))/2/a , (-b - (int)(sqrt(D)+0.5))/2/a  );
    }
    return 0;
}
