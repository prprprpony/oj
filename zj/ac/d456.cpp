#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    cin.ignore(42, '\n');
    while (T--) {
        string s, circddc;
        getline(cin, s);
        getline(cin, circddc);
        vector<bool> vis(2);
        deque<int> pos;
        for (int i = s.size() - 1; i >= 0 && pos.size() < 2; --i)
            for (int j = 0; j < 2; ++j)
                if (s[i] == circddc[j] && !vis[j]) {
                    pos.push_front(i);
                    vis[j] = true;
                    break;
                }
        
        for (int i = 0; i <= pos[0]; ++i)
            cout << s[i];
        for (int i = pos[1]; i < s.size(); ++i)
            cout << s[i];
        cout << '\n';
        for (int i = pos[0] + 1; i < pos[1]; ++i)
            cout << s[i];
        cout << '\n';
    }
}
