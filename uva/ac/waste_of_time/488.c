#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,f;
        scanf("%d%d",&a,&f);
        while(f--)
        {
            int i;
            for(i=1;i<=a;i++)
            {
                int j=i;
                while(j--)printf("%d",i);
                printf("\n");
            }
            for(i-=2;i>=1;i--)
            {
                int j=i;
                while(j--)printf("%d",i);
                printf("\n");
            }
            if(f)printf("\n");

        }
        if(n)printf("\n");
    }


}
