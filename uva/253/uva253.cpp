#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool num_check(string a,string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    return a==b;
}

string turn(int fixed,string i,bool t)
{
    string o;
    int a=0,b=2;
    if(a==fixed||a==5-fixed)a++;
    if(b==fixed||b==5-fixed)b--;
    if(fixed>2)swap(a,b);
    o.resize(6);
    o[0]=i[fixed];
    o[5]=i[5-fixed];
    char tmp=i[5-b];
    o[1+t]=i[a];
    o[2+t*2]=i[b];
    o[3-t*2]=i[5-b];
    o[4-t]=i[5-a];
    return o;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string dice;
    while(cin>>dice)
    {
        string a,b;
        a.insert(a.begin(),dice.begin(),dice.begin()+6);
        b.insert(b.begin(),dice.begin()+6,dice.begin()+12);
        bool same=0;

        if(!num_check(a,b))
        {
            cout<<"FALSE"<<endl;
            continue;
        }
        for(int i=0;i<6;i++)
        {
            if(a[0]==b[i]&&a[5]==b[5-i])
            {
                string c=turn(i,b,0);
                for(int i=0;i<4;i++)
                {
                    c=turn(0,c,1);
                    if(a==c)
                    {
                        same=1;
                        break;
                    }
                }
            }
            if(same)break;
        }
        string out=(same)?"TRUE":"FALSE";
        cout<<out<<endl;

    }

    return 0;
}
