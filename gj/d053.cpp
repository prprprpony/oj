#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int i,j,c=0;
    long int n,o;
    scanf("%d",&n);
    o=n;
    long int sqrtn=(int)sqrt(n)+1;
    bool prime[sqrtn];
    int pf[sqrtn];
    for(i=2;i<sqrtn;i++)
    {
        prime[i]=1;
    }
    for(i=2;i<sqrtn;i++)
    {
        if(prime[i])
        {
            for(j=2;i*j<sqrtn;j++)
                prime[i*j]=0;
            while(n%i==0)
            {
                n/=i;
                pf[c]=i;
                c++;
            }
            if(n==1)break;
        }
    }
    if(n!=1)
        {
            pf[c]=n;
            c++;
        }
    printf("%d = ",o);
    for(i=0;i<c-1;i++)
        printf("%d * ",pf[i]);
    printf("%d\n",pf[i]);

    return 0;
}
