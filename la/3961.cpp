#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const int inf = 1e9;
struct node
{
    pii v,m;
    bool r;
    int s;
    node * c[2];
};
int sz(node*t) {return t?t->s:0;}
pii mv(node*t) {return t?t->m:pii{inf,inf};}
void rev(node*t)
{
    if (t) t->r=!t->r;
}
void push(node*t)
{
    if(t&&t->r) {
        swap(t->c[0],t->c[1]);
        t->r=0;
        rev(t->c[0]);
        rev(t->c[1]);
    }
}
void pull(node*t)
{
    if(t) {
        t->m=min(t->v,min(mv(t->c[0]),mv(t->c[1])));
        t->s=1+sz(t->c[0])+sz(t->c[1]);
    }
}
void rot(node*&t,bool d)
{
    push(t);
    node*k=t->c[!d];
    push(k);
    t->c[!d]=k->c[d];
    k->c[d]=t;
    pull(t);
    pull(k);
	t=k;
}
int find_min(node*t,int i=0)
{
	assert(t);
    push(t);
	return t->v == t->m ? i + sz(t->c[0]) + 1 : (mv(t->c[0])==t->m?find_min(t->c[0],i):find_min(t->c[1],i+sz(t->c[0])+1));
}
void splay(node*&t,int k)
{
	assert(t);
    push(t);
    int i=sz(t->c[0])+1;
    if (i==k)
        return;
    bool d=i<k;
    if (d) k-=i;
    node*&p=t->c[d];
    push(p);
    i=sz(p->c[0])+1;
    if (i!=k) {
        bool d1=i<k;
        if(d1) k-=i;
        splay(p->c[d1],k);
        if(d==d1)
            rot(t,!d);
        else
            rot(p,d);
    }
    rot(t,!d);
}
node*meld(node*l,node*r)
{
    if (!l||!r)return l?l:r;
    splay(l,sz(l));
    l->c[1]=r;
    pull(l);
    return l;
}
void print(node*t)
{
	if(!t)return;
	cout<<t<<';';
	cout<<t->v.F<<','<<t->v.S<<';';
	cout<<t->m.F<<','<<t->m.S<<';';
	cout<<t->c[0]<<';';
	cout<<t->c[1]<<';';
	cout<<t->s<<';';
	cout<<'\n';
	print(t->c[0]);
	print(t->c[1]);
}
const int N = 1e5+87;
int main()
{
    int n;
    while (scanf("%d",&n) == 1 && n) {
		node*rt=NULL;
        for (int i = 0; i < n; ++i) {
			node*t=new node();
            scanf("%d",&t->v.F);
			t->v.S=i;
			t->c[0]=rt;
			pull(rt=t);
        }
        for (int i = 0; i < n; ++i) {
/*
			puts("before splay");
			print(rt);
			puts("");
*/
			int k=find_min(rt);
//			cout << "k="<<k << '\n';
            splay(rt,k);
/*
			puts("after splay");
			print(rt);
			puts("");
*/
            printf("%d%c",sz(rt->c[0])+1+i," \n"[i==n-1]);
            rev(rt->c[0]);
            node*t=rt;
            rt=meld(rt->c[0],rt->c[1]);
            delete t;
/*
			puts("after delete");
			print(rt);
			puts("");
*/
        }
    }
}
