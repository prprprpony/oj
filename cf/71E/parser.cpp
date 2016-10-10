/*
parse first 100 elements from pt-data1.csv to c++ code
I found the file on this site through google
http://php.scripts.psu.edu/djh300/cmpsc221/p3s11-pt-data.htm
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main()
{
	string s;
	while (v.size() < 100 && getline(cin, s)) {
		for (auto & x : s)
			if (x == ',')
				x = ' ';
		stringstream ss(s);
		int n;
		string e;
		ss >> n >> e;
		v.push_back(e);
	}
	cout << "const char * pt[] = {\"Pony\"";
	for (auto x : v)
		cout << ",\"" << x << '"';
	cout << "};\n";
}
