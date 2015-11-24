#include<iostream>
using namespace std;

int main()
{
    long long a,b,t;
    while(cin>>a>>b)
    {
        t=(a>b)?a:b;
        a=(a>b)?b:a;
        b=t;
        cout<<b-a<<endl;
    }

    return 0;
}
