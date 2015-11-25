#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF) {
        vector<string> name(n);
        for (i = 0; i < n; i++)
            cin >> name[i];
        sort(name.begin(), name.end());
        for (i = 0; i < n; i++)
            cout << name[i] << endl;
    }
    return 0;
}
