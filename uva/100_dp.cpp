#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
//#include<chrono>

using namespace std;
/*
class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};
*/
typedef long long ll;
int clp=0;
int CL(int a,vector<int>& cl)
{
    if(a==1)
        return 1;
    int c=0;
    while(a>=cl.max_size())
    {
        a=(a%2)?3*a+1:a/2;
        cout<<a<<endl;
        c++;
    }
    if(a>=cl.size())
    {
         cl.resize(a+1,0);
         cout<<clp++<<"times:"<<a+1<<endl;
    }
    if(cl[a])
        return cl[a];
    return cl[a]=1+c+CL((a%2)?3*a+1:a/2,cl);
}

int main()
{
    int i,j;
    vector<int> cl;

    /*
    while(scanf("%d%d",&i,&j)!=EOF)
    {
        ll mcl=0;
        //Timer tmr;
        for(int k=i;k<=j;k++)mcl=max(mcl,CL(k,cl));
        //double t=tmr.elapsed();
        //cout<<t<<endl;

        printf("%d %d %d\n",i,j,mcl);
    }
    */

    /*Single number test
    while(cin>>i)cout<<CL(i,cl)<<endl;
    //*/

    /*Calculate one number
    ll a;
    while(cin>>a)
    {
        ll cl=0;
        ll Maxa=0;
        while(a!=1)
        {
            Maxa=(Maxa>a)?Maxa:a;
            a=(a%2)?3*a+1:a/2;
            cout<<"step"<<++cl<<":a="<<a<<endl;
        }
        cout<<"Max="<<Maxa<<endl;
    }
    */

    return 0;
}
