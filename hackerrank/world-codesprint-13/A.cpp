#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        st.insert(a);
    }
    bool f = 1;
    for (int i = 1; i <= n; ++i)
        if (!st.count(i)) {
            if (f)
                f = 0;
            else
                cout << ' ';
            cout << i;
        }
    cout << endl;
}
