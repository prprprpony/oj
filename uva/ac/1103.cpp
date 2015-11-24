#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>


using namespace std;

typedef struct
{
  int b;
  vector<bool> sur;
} egy;


bool g[202][204],vis[202][204];
int h,w;
int idx[202][204]={0};

void index(int i,int j,int c)
{
    idx[i][j]=c;
    for(int m=-1;m<=1;m++)
        for(int n=-1;n<=1;n++)
        {
            int k=i+m,l=j+n;
            if(k<0 || l<0 || k>=h || l>=4*w)continue;
            else if(!idx[k][l] && g[k][l]==g[i][j])index(k,l,c);
        }
    return;
}

void countb(int i,int j,egy& ch)
{
    if(!g[i][j])return;
    vis[i][j]=1;

    for(int m=-1;m<=1;m++)
        for(int n=-1;n<=1;n++)
        {
            int k=i+m,l=j+n;
            if(k<0 || l<0 || k>=h || l>=4*w)continue;
            else if(!vis[k][l])
            {
                int id=idx[k][l];
                if(!g[k][l] && !ch.sur[id])
                {
                    ch.b++;
                    ch.sur[id]=1;
                }
                countb(k,l,ch);
            }
        }
    return;

}

int main()
{
    //freopen("in.txt","r",stdin);
    int cases=0;
    while(cin>>h>>w && h && w)
    {
        cases++;
	//initialize variables
	memset(g,0,sizeof(g));
        //input
        for(int i=1;i<=h;i++)
            for(int j=1;j<=w;j++)
            {
                char c;
                cin>>c;
                if(isalpha(c))c=10+c-'a';
                else c=c-'0';

                int k=4;
                while(k--)
                {
                    g[i][4*j-3+k]=c%2;
                    c/=2;
                }
            }
	h+=2;
	w++;

        //numbering blocks,starting from 1
        int cnt=0,bn=0;
        memset(idx,0,sizeof(idx));
        for(int i=0;i<h;i++)
            for(int j=0;j<4*w;j++)
                if(!idx[i][j])
                {
                    if(g[i][j])bn++;

                    index(i,j,++cnt);
                }

        /* print g & idx
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<4*w;j++)
                cout<<g[i][j];
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<4*w;j++)
                cout<<idx[i][j];
            cout<<endl;
        }
        cout<<endl;
        */

        ///* calculate answer
        egy ch[bn];
        int cb=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<bn;i++)
        {
            ch[i].b=0;
            ch[i].sur.resize(cnt+1,0);
        }

        for(int i=0;i<h;i++)
            for(int j=0;j<4*w;j++)
                if(g[i][j]&&!vis[i][j])
                {
                    countb(i,j,ch[cb++]);
                }
        //*/
        //print ans
        string s;
        for(int i=0;i<bn;i++)
        {
	    //cout<<"ch["<<i<<"].b="<<ch[i].b<<endl;
            if(ch[i].b==2)s.push_back('A');
            else if(ch[i].b==4)s.push_back('J');
            else if(ch[i].b==6)s.push_back('D');
            else if(ch[i].b==5)s.push_back('S');
            else if(ch[i].b==1)s.push_back('W');
            else if(ch[i].b==3)s.push_back('K');
            //else cout<<"error:ch["<<i<<"].b="<<ch[i].b<<endl;
        }
        sort(s.begin(),s.end());
        cout<<"Case "<<cases<<": "<<s<<endl;

    }

    return 0;
}
