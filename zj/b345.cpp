#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
const int N = 1e5,M = 99999997;
struct node
{
	int v,m,s;
	node*c[2];
} mem[N];
node*ptr=mem;
int sz(node*t){return t?t->s:0;}
int mv(node*t){return t?t->m:inf;}
void pull(node*t)
{
	t->s=1+sz(t->c[0])+sz(t->c[1]);
	t->m=min(t->v,min(mv(t->c[0]),mv(t->c[1])));
}
int find_m(node*t,int s=0)
{
	assert(t);
	return t->v==t->m?s+sz(t->c[0])+1:(t->c[0]&&t->c[0]->m==t->m?find_m(t->c[0],s):find_m(t->c[1],s+sz(t->c[0])+1));
}
void rot(node*&t,bool d)
{
	node*k=t->c[!d];
	t->c[!d]=k->c[d];
	pull(t);
	k->c[d]=t;
	pull(t=k);
}
void splay(node*&t,int k)
{
	int i=sz(t->c[0])+1;
	if(i==k)return;
	bool d=i<k;
	if(d)k-=i;
	node*&p=t->c[d];
	i=sz(p->c[0])+1;
	if (i!=k) {
		bool d1=i<k;
		if(d1)k-=i;
		splay(p->c[d1],k);
		if(d==d1)
			rot(t,!d);
		else
			rot(p,d);
	}
	rot(t,!d);
}
node*meld(node*a,node*b)
{
	if(!a||!b) return a?a:b;
	splay(a,sz(a));
	a->c[1]=b;
	pull(a);
	return a;
}
void remove(node*&t,int k)
{
	splay(t,k);
	node*p=meld(t->c[0],t->c[1]);
	// delete t;
	t=p;
}
typedef pair<int,int> pii;
#define F first
#define S second
pii a[N],b[N];
int x[N];
int main()
{
	int n;
	scanf("%d",&n);
	assert(n<=N);
	for (int i = 0;i < n;++i) {
		scanf("%d",&a[i].F);
		a[i].S=i;
	}
	sort(a,a+n);
	for (int i = 0;i < n;++i) {
		scanf("%d",&b[i].F);
		b[i].S=i;
	}
	sort(b,b+n);
	for (int i=0;i<n;++i) x[b[i].S] = a[i].S;
	node*rt=NULL;
	for(int i=0;i<n;++i) {
		node*t=ptr++;
		t->v=x[i];
		t->c[0]=rt;
		pull(rt=t);
		// splay(rt,i/2+1);
	}
	int ans=0;
	for(int i=0;i<n;++i) {
		int k=find_m(rt);
		ans=(ans+k-1)%M;
		remove(rt,k);
	}
	printf("%d\n",ans);
}
