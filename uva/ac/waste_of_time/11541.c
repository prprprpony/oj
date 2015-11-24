#include <stdio.h>

int main()
{
    int T,i,len;
    char c;

    scanf("%d%*[ \n\t]",&T);

    for( i = 1 ; i <= T ; i++ )
    {
        printf("Case %d: ",i);

        while( ( c = getchar() ) != '\n' )
        {
            scanf("%d",&len);

            while(len--)
                putchar(c);
        }

        putchar('\n');
    }

    return 0;
}
