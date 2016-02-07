#include <string>
#include <iostream>
using namespace std;
string line;
char b[] = "()[]";

inline bool isopen(char c) {
    return c == b[0] || c == b[2];
}

inline int getid(char c) {
    for (int i = 0; i < 4; i++)
        if (c == b[i])
            return i;
}

int dfs(int l) {
    if (!isopen(line[l]))
        return 0;
    int id = getid(line[l]);
    int i, r;
    for (i = l + 1; i < line.size(); i += r) {
        if (line[i] != b[id^1]) {
            if (!(r = dfs(i)))
                return 0;
        } else {
            return i - l + 1;
        }
    }
    return 0;
}

int main()
{
    bool ok;
    while (getline(cin, line)) {
        ok = true;
        for (int i = 0, r; i < line.size(); i += r) {
            if (!(r = dfs(i))) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Correct" : "Error") << endl;
    }

    return 0;
}
