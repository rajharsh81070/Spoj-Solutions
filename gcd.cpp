#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define inf 1e9
typedef long long ll;
typedef long double ld;
typedef unsigned long long int ul;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<float> vf;
typedef vector <ld> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define vec(x) vector<x >
#define z size()
#define get(x) cin>>x
#define put(x) cout<<x
#define pls(x) cout<<x<<' '
#define pln(x) cout<<x<<"\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=b-1;i>=a;i--)
#define vput(a) f(i,0,a.z) pls(a[i]); nl;
#define vget(v) f(i,0,v.z) get(v[i]);
#define vsort(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define vuni(v) v.erase(unique(all(v)),v.end())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define vmin(v) *min_element(all(v))
#define vmax(v) *max_element(all(v))
#define total(v) accumulate(all(v),ll(0))

#define bs(v,x) binary_search(all(v),x)
#define parray(a,n) f(i,0,n) pls(a[i]); nl;
#define ppair(x) cout<<x.first<<' '<<x.second<<"\n";
#define vp(x,y) vector<pair<x,y> >
#define p(x,y) pair<x,y >
#define endl '\n'
#define nl cout<<'\n';
#define w(a) while(a--)
#define wh(a) while(a)

ll maxi=LLONG_MAX;
ll mini=LLONG_MIN;

void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }

#define con continue
#define bk break
#define ret return
#define setpr fixed<<setprecision
#define gl(a) getline(cin,a)
#define ppb pop_back
#define pq priority_queue

vi prime(1000000001, 1);
vi primeAtk ;

int main()
{
	int t;
	get(t);
	for(int i = 4;i < 1000000001; i+=2)
		prime[i] = 0;
	for(int i = 3; i < 1000000001; i+=2)
	{
		if(prime[i])
		{
			for(int j = i*i; j < 1000000001; j+=2*i)
				prime[j] = 0;
			primeAtk.pb(prime[i]);
		}
	}
	vput(primeAtk);
	prime[0] = 0;
	prime[1] = 0;
	w(t)
	{
		int n;
		get(n);
	}
	return 0;
}
