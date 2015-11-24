#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int main()
{
	char g[5][15],in;
	int r,c,num_case=1;
	while( (in=getchar()) && in!='0')
    {
        if(in=='\n')
        {
            r++;
            c=0;
            if(r==5) //process answer
            {



                r=0;
            }

            continue;
        }
        else if(in=='#')
            in=' ';
        g[r][c]=in;
    }


    return 0;
}
