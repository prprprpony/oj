#include <iostream>
#include <utility>
#include <string>
#include <stack>
#include <cctype>
#define MAXN 26
#define R first
#define C second
using namespace std;
typedef pair<int,int> pii;

pii m[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        char c;
        cin >> c;
        c -= 'A';
        cin >> m[c].R >> m[c].C;
    }

    string s;
    while (cin >> s) {
        bool error = false;
        int ans = 0;
        stack<pii> st;
        for (char c : s) {
            if (isalpha(c)) {
                st.push(m[c - 'A']);
            } else if (c == ')') {
                pii a = st.top();
                st.pop();
                if (st.top().C != a.R) {
                    error = true;
                    goto output;
                }
                ans += st.top().R * a.R * a.C;
                st.top().C = a.C;
            }
        }

output:
        if (error)
            cout << "error";
        else
            cout << ans;
        cout << '\n';
    }

    return 0;
}
