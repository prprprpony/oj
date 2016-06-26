#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int n;

    while(cin>>n)
    {
        while(n--)
        {
            string c;
            cin>>c;
            int lc=c.size(),row,col;
            while(isdigit(c[--lc]));
            if(lc==0||(lc>=1)?!isdigit(c[lc-1]):0)
            {
                sscanf(&c[lc+1],"%d",&row);
                col=0;
                for(int i=0;i<=lc;i++)
                {
                    col*=26;
                    col+=(c[i]-'A'+1);
                }
                cout<<"R"<<row<<"C"<<col<<endl;
            }
            else
            {
                sscanf(&c[lc+1],"%d",&col);
                c.resize(lc);
                sscanf(&c[1],"%d",&row);

                c.clear();
                while(col)
                {
                    c.push_back(((col%26)?col%26:26+0*col--)+'A'-1);
                    col/=26;
                }
                for(int i=c.size()-1;i>=0;i--)cout<<c[i];
                cout<<row<<endl;

            }

        }
    }

    return 0;
}
