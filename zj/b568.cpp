#include <iostream>
using namespace std;
const int M = 7e5;
bool ok[M + 1];
int stack[M + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ok[0] = true;
    for (int i = 0; i < n && !ok[M]; ++i) {
        int c;
        cin >> c; 
        int top = 0;
        for (int i = 0; i <= M; ++i)
            if (ok[i])
                stack[top++] = i + c > M ? (i + c) % M : i + c;
        while (top)
            ok[stack[--top]] = true;
    }
    for (int i = M; i >= 0; --i)
        if (ok[i]) {
            cout << i << '\n';
            break;
        }
}
