#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;
	bool first=1;
	while(cin>>n)
	{
		if(!first)cout<<endl;

		string name[n];
		map<string,int> gain;
		for(int i=0;i<n;i++)
		{
			cin>>name[i];
			gain[name[i]]=0;
		}
		for(int i=0;i<n;i++)
		{
			string s;
			int p,bud;
			cin>>s;
			cin>>bud;
			gain[s]-=bud;
			cin>>p;
			gain[s]+=(p)?bud%p:bud;
			for(int j=0;j<p;j++)
			{
				string m;
				cin>>m;
				gain[m]+=(bud/p);
			}
		}
		for(int i=0;i<n;i++)
			cout<<name[i]<<" "<<gain[name[i]]<<endl;

		first=0;
	}

	return 0;
}
