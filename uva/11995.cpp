#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int n;
    int op;
    int v;
    while (scanf("%d", &n) == 1) {
        bool isq = true, iss = true, ispq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        while (n--) {
            scanf("%d%d", &op, &v);
            switch (op) {
            case 1:
                if (iss) s.push(v);
                if (isq) q.push(v);
                if (ispq) pq.push(v);
                break;
            case 2:
                if (iss) {
                    if (s.empty() || v != s.top())
                        iss  = false;
                    else
                        s.pop();
                }
                if (isq) {
                    if (q.empty() || v != q.front())
                        isq = false;
                    else
                        q.pop();
                }
                if (ispq) {
                    if (pq.empty() || v != pq.top())
                        ispq = false;
                    else
                        pq.pop();
                }
            }
        }

        if (iss && !isq && !ispq)
            puts("stack");
        else if (!iss && isq && !ispq)
            puts("queue");
        else if (!iss && !isq && ispq)
            puts("priority queue");
        else if (!iss && !isq && !ispq)
            puts("impossible");
        else
            puts("not sure");
    }

    return 0;
}
