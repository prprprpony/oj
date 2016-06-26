#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> v;
    string s;
    while (cin >> s) {
        if (s == "half")
            v.push_back(0);
        else
            v.push_back(1);
    }
    long long apple = 0;
    long long ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        ans += p * apple + p / 2 * v[i];
        apple = 2 * apple + v[i];
    }
    cout << ans << endl;
    
    return 0;
}
