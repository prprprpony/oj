//#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <set>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string line,word;
    set<string> dict;
    while(getline(cin,line))
    {
        for(int i=0;i<line.size();i++)
        {
            if(isalpha(line[i]))line[i]=tolower(line[i]);
            else line[i]=' ';
        }
        stringstream ss(line);
        while(ss>>word)dict.insert(word);
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();it++)
        cout<<*it<<endl;

    return 0;
}
