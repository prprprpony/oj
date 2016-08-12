#include <cstdio>
using namespace std;
const int maxn = 2e5 + 228;
const int maxh = 29;
struct Node
{
	int s;
	Node * c[2];
	Node() : s(0), c{NULL, NULL} {}
};
bool ok(Node * t) {return t && t->s;}
Node * insert(Node * t, int x, int h)
{
	if (!t)
		t = new Node();
	++t->s;
	if (h >= 0) {
		int i = (x & (1 << h)) >> h;
		t->c[i] = insert(t->c[i], x, h-1);
	}
	return t;
}
void erase(Node * t, int x, int h)
{
	--t->s;
	if (h >= 0) {
		int i = (x & (1 << h)) >> h;
		erase(t->c[i], x, h-1);
	}
}
int query(Node * t, int x, int h)
{
	if (h < 0)
		return 0;
	int i = (x & (1 << h)) >> h;
	if (ok(t->c[i^1]))
		return (1 << h) ^ query(t->c[i^1], x, h-1);
	else
		return query(t->c[i], x, h-1);
}
int main()
{
	int q;
	scanf("%d ", &q);
	Node * t = insert(NULL, 0, maxh);
	while (q--) {
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		switch (c) {
			case '+':
				t = insert(t, x, maxh);
				break;
			case '-':
				erase(t, x, maxh);
				break;
			case '?':
				printf("%d\n", query(t, x, maxh));
				break;
		}
	}
}
