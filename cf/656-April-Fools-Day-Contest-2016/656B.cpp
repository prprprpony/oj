#include <iostream>
using namespace std;
const int maxn = 16;
int m[maxn];
int r[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    int cnt = 0;
    for (int d = 0; d < 1e5; d++) {
        for (int i = 0; i < n; i++) {
            if (d % m[i] == r[i]) {
                ++cnt;
                break;
            }
        }
    }
    cout << cnt / 1e5 << endl;
    
    return 0;
}
