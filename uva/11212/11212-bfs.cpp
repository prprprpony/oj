#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXNODE 362880
using namespace std;

int n;
bool vis[MAXNODE];
int F[20] = {0};
int P10[20] = {0};

struct Node
{
    int state;
    int depth;
    int heuristic;
    int _hash;

    Node(int s = 0, int d = 0,int h = 0): state(s), depth(d), heuristic(h), _hash(0) {};

    friend bool operator>(const Node& a, const Node& b)
    {
        return (a.depth != b.depth) ? a.depth > b.depth : a.heuristic > b.heuristic;
    }

    inline int pow10(int p)
    {
        if (P10[p])
            return P10[p];
        int i, v;
        for (P10[p] = 1, i = 1, v = 10; i <= p; i <<= 1, v *= v)
            if (i&p)
                P10[p] *= v;
        return P10[p];
    }

    int f(int x)
    {
        return (F[x] != 0) ? (F[x]) : (F[x] = x * f(x-1));
    }

    inline int getDigit(int i)
    {
        return state / pow10(i) % 10;
    }

    inline int getRange(int i, int j)
    {
        return (i <= j) ? (state / pow10(i) % pow10(j-i+1)) : 0;
    }

    inline void setDigit(int i, int v)
    {
        state = state % pow10(i) + v * pow10(i) + getRange(i+1, n-1) * pow10(i+1);
        _hash = 0;
    }

    inline void setRange(int i, int j, int v)
    {
        state = state % pow10(i) + v * pow10(i) + getRange(j+1, n-1) * pow10(j+1);
        _hash = 0;
    }

    inline int hash()
    {
        if (_hash)
            return _hash;
        bool used[n+1] = {0};
        int cnt;
        int c;
        int i, j;
        for (i = n - 1; i >= 0; --i) {
            for (cnt = 0, j = 1, c = getDigit(i); j < c; ++j)
                if (!used[j])
                    ++cnt;
            _hash += cnt * f(i);
            used[c] = true;
        }
        return _hash;
    }
};


int bfs(Node start)
{
    if (start.hash() == 0)
        return 0;

    priority_queue<Node, vector<Node>, greater<Node> > heap;
    heap.push(start);
    int i, j, k, dh;
    Node node;

    while (true) {
        node = Node(heap.top().state, heap.top().depth + 1, heap.top().heuristic);

        for (i = 0; i < n-1; ++i) {
            for (j = i; j < n-1; ++j) {
                int oi = i, oj = j;
                int state_ij = node.getRange(i, j);
                int state_end= node.getRange(j+1, n-1);

                for (k = j+1; k < n; k = j+1) {
                    dh = 0;
                    if (i-1 > -1 && node.getDigit(i-1) + 1 == node.getDigit(i))
                        ++dh;
                    if (node.getDigit(j) + 1 == node.getDigit(k))
                        ++dh;
                    if (k+1 < n && node.getDigit(k) + 1 == node.getDigit(k+1))
                        ++dh;

                    node.setDigit(i, node.getDigit(k));
                    node.setRange(i+1, j+1, state_ij);

                    k = i;
                    ++i;
                    ++j;


                    if (k > 0 && node.getDigit(k-1) + 1 == node.getDigit(k))
                        --dh;
                    if (node.getDigit(k) + 1 == node.getDigit(i))
                        --dh;
                    if (j+1 < n && node.getDigit(j) + 1 == node.getDigit(j+1))
                        --dh;
                    
                    node.heuristic += dh;
                    if (node.hash() == 0)
                        return node.depth;
                    else if(!vis[node.hash()]) {
                        heap.push(node);
                        vis[node.hash()] = true;
                    }
                    node.heuristic -= dh;
                }
                


                i = oi;
                j = oj;
                node.setRange(i, j, state_ij);
                node.setRange(j+1, n-1, state_end);
            }

        }

        heap.pop();
    }
}

int main()
{
    int i;
    int h;
    int p;
    int case_num = 1;
    int state;
    F[0] = 1;
    while (scanf("%d", &n) != EOF && n > 1) {

/*        
        Node node(0,0,0);
        printf("%d! = %d\n", n, node.f(n));
        while (true) {
            scanf("%d", &state);
            for (i = 1; i < n; ++i) {
                scanf("%d", &p);
                if (p != (state%10)+1)
                    ++h;
                state *= 10;
                state += p;
            }
            node = Node(state, 0, h);
            printf("hash(%d) = %d\n", state, node.hash());
        }
*/

        memset(vis, 0, sizeof(vis));
        h = 0;
        scanf("%d", &state);
        for (i = 1; i < n; ++i) {
            scanf("%d", &p);
            if (p != (state%10)+1)
                ++h;
            state *= 10;
            state += p;
        }

        printf("Case %d: %d\n", case_num++, bfs(Node(state, 0, h)));
    }
    return 0;
}
