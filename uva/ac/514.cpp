#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n, a;
    bool none;
    while (cin >> n && n > 0) {
        none = false;
        while (!none) {
            stack<int> st;
            bool fail = false;
            for (int i = 0, j = 1; i < n; i++) {
                cin >> a;
                if (a == 0) {
                    none = true;
                    break;
                }
                if (!fail) {
                    if (a > j) {
                        while (a > j && j <= n) {
                            st.push(j);
                            j++;
                        }
                        j++;
                    } else if (a < j) {
                        if (st.empty() || st.top() != a)
                            fail = true;
                        else
                            st.pop();
                    } else {
                        j++;
                    }
                }
            }
            if (!none)
                cout << (fail ? "No" : "Yes") << '\n';
        }
        cout << '\n';
    }
    return 0;
}
