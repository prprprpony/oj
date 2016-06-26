#include<iostream>
//#include<cstdio>
#include<string>
#include<sstream>
const int maxint=2147483647;

using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s;
    while(getline(cin,s))
    {
        stringstream ss(s);
        int bin[3][3];        //bin[x][0]=Brown;bin[x][1]=Green;bin[x][2]=Clear
        int total[3]={0,0,0};//total[0]=Brown;total[1]=Green;total[2]=Clear
        int moves,minmoves=maxint;
        string order="000";
        for(int bn=0;bn<3;bn++)
            for(int cr=0;cr<3;cr++)
            {
                ss>>bin[bn][cr];
                total[cr]+=bin[bn][cr];
            }
        //int times=0;
        for(int g=0;g<3;g++)
            for(int c=0;c<3;c++)
            {
                if(c==g)continue;
                int b=3-c-g;
                moves=total[0]-bin[b][0]+total[1]-bin[g][1]+total[2]-bin[c][2];
                if(moves<=minmoves)
                {
                    minmoves=moves;
                    order[b]='B';
                    order[g]='G';
                    order[c]='C';
                    //cout<<"case"<<times++<<":"<<order<<' '<<moves<<endl;
                }
            }
        cout<<order<<" "<<minmoves<<endl;
    }

    return 0;
}
