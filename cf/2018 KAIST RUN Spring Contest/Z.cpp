#include<bits/stdc++.h>
using namespace std;
const int N = 5487;
template<class T>
bool cmax(T & a,const T & b) {return a < b ? a = b, 1 : 0;}
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 2;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i + 2 < n; ++i) {
        if (a[i] == a[i+1])
            continue;
        bool b = a[i] < a[i+1];
        for (int j = i + 2; j < n && (a[j-1] != a[j]) && (a[j-1] < a[j]) != b; ++j, b ^= 1) {
            cmax(ans, j - i + 1);
        }
    }
    cout << ans << endl;
}
