#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    bool first=true;
    int n;
    cin>>n;
    while(n--)
    {

        int size_l,tmp;
        cin>>size_l;
        vector<int> v[4];

        for(int j=0;j<size_l;j++)
            for(int i=0;i<4;i++)
            {
                cin>>tmp;
                v[i].push_back(tmp);
            }
        int sum_n=size_l*size_l;
        vector<int> sum_2[2];

        for(int i=0;i<2;i++)
            for(int f=0;f<size_l;f++)
                for(int s=0;s<size_l;s++)
                {
                    sum_2[i].push_back( ((i)?1:-1)*( v[2*i][f] + v[ 2*i+1 ][s] ) );
                }

        for(int i=0;i<2;i++)
            sort(sum_2[i].begin(),sum_2[i].end());

        int AB=0,CD=0,ans=0;

        while( AB<sum_n && CD <sum_n )
        {
            if(sum_2[0][AB]==sum_2[1][CD])
            {
                int common=sum_2[0][AB];
                int ab=AB,cd=CD;

                while(AB < sum_n)
                    if(sum_2[0][AB]== common)AB++;
                    else break;
                while(CD < sum_n)
                    if( sum_2[1][CD]== common )CD++;
                    else break;

                ans+=( (CD-cd)*(AB-ab) );
            }
            else if(sum_2[0][AB]>sum_2[1][CD])
                CD++;
            else AB++;
            }

            if(!first)cout<<endl;
            cout<<ans<<endl;
            first=false;
    }

    return 0;
}
