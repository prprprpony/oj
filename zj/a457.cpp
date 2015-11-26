#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxk = 100000;
struct Node
{
    int s;
    int r;
};

struct Range
{
    int l;
    int r;
    Range(int a = 0, int b = 0) : l(a), r(b) {}
};

Node n[maxk];
Node tmp[maxk];
int ans;

bool cmp(const Node &a, const Node &b)
{
    return a.s != b.s ? a.s < b.s : a.r < b.r;
}

void merge(int left, int mid, int right) // merge [left, mid) and [mid, right)
{
    int left_size = mid - left;
    int i = 0, j = mid; // i for left side(tmp[0 .. left_size - 1]), j for right side(n[mid .. right - 1])
    memcpy(tmp, n + left, left_size * sizeof(Node));
    for (int k = left; k < right; k++) {
        if (i >= left_size)
            break;
        if (j >= right) {
            memcpy(n + k, tmp + i, (left_size - i) * sizeof(Node));
            break;
        }

        if (n[j].r < tmp[i].r) {
            n[k] = n[j++];
            ans += left_size - i; // caculate reverse order number
        } else {
            n[k] = tmp[i++];
        }
    }
}

void merge_sort(int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, mid, right);
}

void merge_sort(Range rg)
{
    merge_sort(rg.l, rg.r);
}

int main()
{
    int k;
    scanf("%d%*d",&k);
    ans = 0;
    for (int i = 0; i < k; i++)
        scanf("%d", &n[i].s);
    for (int i = 0; i < k; i++)
        scanf("%d", &n[i].r);
    sort(n, n + k, cmp);
    queue<Range> q;
    {
        bool equality = n[0].s == n[1].s;
        Range rg(0, 2);
        for (int i = 2; i < k; i++) {
            if ((n[i].s == n[i - 1].s) == equality) {
                rg.r++;
            } else {
                if (!equality) {
                    rg.r--;
                    merge_sort(rg);
                    q.push(rg);
                    rg = Range(rg.r, rg.r + 2);
                } else {
                    q.push(rg);
                    rg = Range(rg.r, rg.r + 1);
                }
                equality = !equality;
            }
        }
    }

    if (q.size() == 0) {
        merge_sort(0, k);
    } else {
        Range rg[2];
        while (q.size() > 1) {
            if (q.front().r == k) {
                q.push(q.front());
                q.pop();
                continue;
            }
            for (int i = 0; i < 2; i++) {
                rg[i] = q.front();
                q.pop();
            }
            merge(rg[0].l, rg[0].r, rg[1].r);
            rg[0].r = rg[1].r;
            q.push(rg[0]);
        }
    }

    printf("%d\n",ans);

    return 0;
}
