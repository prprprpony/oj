#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs( vector< vector<bool> >& g , vector<int>& longest_path , int start , vector<int>& finish )
{
	if( longest_path[start] >=0 ) return longest_path[start];

	for(int i=1 ; i < g[start].size() ; i++)
	{
		if( g[start][i] )
		{
			int cur = 1 + dfs( g , longest_path , i , finish ) ;

			if( cur > longest_path[start] )
			{
				longest_path[start] = cur;
				finish[start] = finish[i];
			}

			else if( cur == longest_path[start] )
			{
				finish[start] = min( finish[start] , finish[i] );
			}
		}
	}

	if(longest_path[start] == -1)
	{
		longest_path[start] = 0;
		finish[start]=start;
	}
	
	return longest_path[start];
}

int main()
{
	int n,num_cases=0;
	while( cin>>n && n!=0 )
	{
		vector< vector<bool> > g( n+1 , vector<bool>(n+1,0) );
		vector<int> longest_path(n+1,-1),finish(n+1,n+1);
		int start,p,q;

		cin>>start;
		while( cin>>p>>q  && p!=0 && q!=0)
		{
			g[p][q] = true;
		}
		int ans= dfs( g , longest_path , start , finish );
		
		cout<<"Case "<< ++num_cases <<": The longest path from "<< start <<" has length "<< ans <<", finishing at "<< finish[start] <<"."<<endl<<endl;
	}
	
	return 0;
}
