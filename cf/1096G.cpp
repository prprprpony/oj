#include<bits/stdc++.h>
using namespace std;
const int P=998244353,root=3,MAXNUM=1<<20;
int bigmod(long long a,int b){
	if(b==0)return 1;
	return (bigmod((a*a)%P,b/2)*(b%2?a:1ll))%P;
}
int inv(int a,int b){
	if(a==1)return 1;
	return (((long long)(a-inv(b%a,a))*b+1)/a)%b;
}
std::vector<long long> ps(MAXNUM);
std::vector<int> rev(MAXNUM);
struct poly{
	std::vector<unsigned int> co;
	int n;//polynomial degree = n
	poly(int d){n=d;co.resize(n+1,0);}
	void trans2(int NN){
		int r=0,st,N;
		unsigned int a,b;
		while((1<<r)<(NN>>1))++r;
		for(N=2;N<=NN;N<<=1,--r){
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; b=(ps[i<<r]*co[ss+i])%P;
					co[st+i]=a+b; if(co[st+i]>=P)co[st+i]-=P;
					co[ss+i]=a+P-b; if(co[ss+i]>=P)co[ss+i]-=P;
				}
			}
		}
	}
	void trans1(int NN){
		int r=0,st,N;
		unsigned int a,b;
		for(N=NN;N>1;N>>=1,++r){
			for(st=0;st<NN;st+=N){
				int i,ss=st+(N>>1);
				for(i=(N>>1)-1;i>=0;--i){
					a=co[st+i]; b=co[ss+i];
					co[st+i]=a+b; if(co[st+i]>=P)co[st+i]-=P;
					co[ss+i]=((a+P-b)*ps[i<<r])%P;
				}
			}
		}
	}
	poly operator*(const poly& _b)const{
		poly a=*this,b=_b;
		int k=n+b.n,i,N=1;
		while(N<=k)N*=2;
		a.co.resize(N,0); b.co.resize(N,0);
		int r=bigmod(root,(P-1)/N),Ni=inv(N,P);
		ps[0]=1;
		for(i=1;i<N;++i)ps[i]=(ps[i-1]*r)%P;
		a.trans1(N);b.trans1(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*b.co[i])%P
			;
		r=inv(r,P);
		for(i=1;i<N/2;++i)std::swap(ps[i],ps[N-i]);
		a.trans2(N);
		for(i=0;i<N;++i)a.co[i]=((long long)a.co[i]*Ni)%P;
		a.n=n+_b.n; return a;
	}
};
template<class T>
T qpow(const T & a,int b)
{
    if (b == 1)
        return a;
    T r = qpow(a,b/2);
    r = r * r;
    if (b&1)
        r = r * a;
    return r;
}
int main()
{
    int n,k;
    cin >> n >> k;
    poly a(9);
    while (k--) {
        int d;
        cin >> d;
        a.co[d] = 1;
    }
    a=qpow(a,n/2);
    long long ans=0;
    for (auto v : a.co)
        ans = (ans + v * 1ll * v) % P;
    cout << ans << '\n';
}
