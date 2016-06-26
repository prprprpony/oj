#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

int p[30240]={0},pn=0;
bitset<10> p_used[30240];

int generate_p(bitset<10> used,int num,int n)
{
    for(int i=0;i<=9;i++)
        if(!used[i])
        {
            used[i]=1;

            if( (n+1) == 5 )
            {
                p[pn]=num*10+i;
                p_used[pn]=used;
                pn++;
            }
            else generate_p(used,num*10+i,n+1);

            used[i]=0;
        }
}

bool is_ans(int num,bitset<10> used)
{
    int cnt=5;
    while( cnt-- )
    {
        int r=num%10;
        if( used[r] )
            return false;
        else 
        {
            used[r]=true;
            num/=10;
        }
    }
    
    return true;
}

int main()
{
    int n;
    bitset<10> used;
    generate_p(used,0,0);
    bool first=true;

    while( cin>>n && n>0)
    {
        if(!first)printf("\n");
        first=false;
        bool hav_sol=false;
        int ans;
        for( int i=0 ; ( ans = n*p[i]) <= 98765 ; i++)
        {
            if( is_ans( ans , p_used[i] ) )
            {
                hav_sol=true;
                printf("%05d / %05d = %d\n", ans , p[i] , n );
            }
        }

        if(!hav_sol)
            printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
