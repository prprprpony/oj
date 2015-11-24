#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    freopen("in.txt","w",stdout);
    srand(time(NULL));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<12;i++)
        {
            int t=(int)round((double)rand()/RAND_MAX*2);
            if(t==0)cout<<'r';
            if(t==1)cout<<'g';
            if(t==2)cout<<'b';
        }
        cout<<endl;
    }
    return 0;
}
