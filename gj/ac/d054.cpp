#include<cstdio>
#include<cmath>

using namespace std;

int pow10(int p)
{
    int r=1;
    for(int i=0;i<p;i++)
        r*=10;
    return r;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bool font[10][8][8];
    char in[10][65];
    int prt,mag,out[4],n=0;

    for(int num=0;num<10;num++)
        gets(in[num]);
    for(int num=0;num<10;num++)
        for(int r=0;r<8;r++)
            for(int c=0;c<8;c++)
                font[num][r][c]=in[num][r*8+c]-'0';
    scanf("%d,%d",&prt,&mag);

    if(prt!=0)
        {
            for(int p=(int)log10(prt);p>=0;p--)
            {
                out[n]=prt/pow10(p);
                prt%=pow10(p);
                n++;
            }
        }
    else
    {
        out[0]=0;
        n=1;
    }

    for(int r=0;r<8*mag;r++)
    {
        for(int o=0;o<n;o++)
        {
            for(int c=0;c<8*mag;c++)
            {
                if(font[out[o]][r/mag][c/mag])
                    printf("*");
                else printf("_");
            }
            if(o!=(n-1))
            {
                for(int i=0;i<3;i++)
                    printf("_");
            }
            else printf("\n");
        }

    }

    return 0;
}
