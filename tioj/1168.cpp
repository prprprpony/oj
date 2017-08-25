#include<cstdio>
#include<algorithm>
#include "lib1168.h"
using namespace std;
const int N = 1e6 + 5;
struct deap
{
	int v[N],n;
	deap() : n(2) {}
	int sz()
	{
		return n - 2;
	}
	int mn()
	{
		return v[2];
	}
	int mx()
	{
		return sz() > 1 ? v[3] : v[2];
	}
	void upmn(int i,const int & a)
	{
		for (; i > 2 && a < v[i/2]; v[i] = v[i/2], i/=2);
		v[i] = a;
	}
	void upmx(int i,const int & a)
	{
		for (; i > 3 && v[i/2] < a; v[i] = v[i/2], i/=2);
		v[i] = a;
	}
	void up(int i,const int & a)
	{
		int p = 1<<__lg(i)>>1;
		int j = i ^ p;
		if (i&p) {
			if (j * 2 < n) {
				j *= 2;
				if (j + 1 < n && v[j] < v[j+1])
					++j;
			}
			if (a < v[j]) {
				v[i] = v[j];
				upmn(j,a);
			} else {
				upmx(i,a);
			}
		} else {
			if (j >= n)
				j /= 2;
			if (j >= 3 && v[j] < a) {
				v[i] = v[j];
				upmx(j,a);
			} else {
				upmn(i,a);
			}
		}
	}
	void ins(const int & a)
	{
		up(n++,a);
	}
	void pmn()
	{
		int a(v[--n]);
		if (n == 2)
			return;
		int i = 2;
		while (i*2<n) {
			int c = i * 2;
			if (c+1 < n && v[c+1] < v[c])
				++c;
			v[i] = v[c];
			i = c;
		}
		up(i,a);
	}
	void pmx()
	{
		int a(v[--n]);
		if (n <= 3)
			return;
		int i = 3;
		while (i*2<n) {
			int c = i*2;
			if (c+1 < n && v[c] < v[c+1])
				++c;
			v[i] = v[c];
			i = c;
		}
		up(i,a);
	}
} d;
void pop_big() {d.pmx();}
void pop_small() {d.pmn();}
void push(int s) {d.ins(s);}
int big() {return d.mx();}
int small() {return d.mn();}
