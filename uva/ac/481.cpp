#include <bits/stdc++.h>
#define MAXN (int)1e5 + 42
using namespace std;
int a[MAXN];
int p[MAXN];
bool cmp(int i, int j) {
    return a[i] < a[j];
}
int main()
{
    vector<int> tail;
    scanf("%d", a);
    tail.push_back(0);
    p[0] = -1;
    int i = 0;
    while (scanf("%d", &a[++i]) == 1) {
        if (a[i] > a[tail.back()]) {
            p[i] = tail.back();
            tail.push_back(i);
        } else {
            vector<int>::iterator lb = lower_bound(tail.begin(), tail.end(), i, cmp);
            *lb = i;
            p[i] = lb != tail.begin() ? *(lb - 1) : -1;
        }
    }
    printf("%d\n-\n", tail.size());
    stack<int> st;
    for (int i = tail.back(); i != -1; i = p[i])
        st.push(a[i]);
    while (!st.empty()) {
        printf("%d\n", st.top());
        st.pop();
    }
    return 0;
}
