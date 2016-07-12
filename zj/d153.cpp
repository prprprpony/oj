#include <iostream>
#include <algorithm>
using namespace std;
int a[40000];
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        nth_element(a, a + (N - 1) / 2, a + N);
        cout << a[(N - 1) / 2] << '\n';
    }
}
