#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

bool error;

struct Node 
{
    int val;
    Node *child[2];

    Node()
    {
        val = -1;
        for (int i = 0 ; i < 2; ++i)
            child[i] = NULL;
    }

    int index(char c)
    {
        switch (c) {
        case 'L':
            return 0;
            break;
        case 'R':
            return 1;
            break;
        case ')':
            return -1;
            break;
        }
    }

    void add(char* pos, const int& v)
    {
        int i = index(*pos);
        if (i != -1) {
            if (child[i] == NULL)
                child[i] = new Node;
            child[i]->add(pos + 1, v);
        } else {
            if (val == -1)
                val = v;
            else
                error = true;
        }
    }

    void clear()
    {
        for (int i = 0; i < 2; ++i) {
            if (child[i] != NULL) {
                child[i]->clear();
                delete child[i];
                child[i] = NULL;
            }
        }
        val = -1;
    }

    bool complete()
    {
        if (val == -1)
            return false;
        for (int i = 0 ; i < 2; ++i)
            if (child[i] != NULL)
                if (!child[i]->complete())
                    return false;
        return true;
    }
};


int main()
{
    char buf[300];
    int v;
    char *pos;
    Node root;
    Node* it;
    while (scanf("%s", buf) == 1) {
        if (buf[1] != ')') {
            sscanf(buf+1, "%d", &v);
            for (pos = buf; *pos != ','; ++pos);
            root.add(pos + 1, v);
        } else {
            if (error || !root.complete())
                printf("not complete\n");
            else {
                queue<Node*> q;
                q.push(&root);
                while (!q.empty()) {
                    it = q.front();
                    q.pop();
                    for (int i = 0; i < 2; ++i)
                        if (it->child[i] != NULL)
                            q.push(it->child[i]);
                    printf("%d", it->val);
                    putchar(!q.empty() ? ' ' : '\n');
                }
            }

            error = false;
            root.clear();
        }
    }

    return 0;
}
