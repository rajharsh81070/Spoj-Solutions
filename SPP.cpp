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

vl arr;
int arr2[5] = {1, 5, 0, 2, 1};

vector < vector <ll> > matrixMultiplication(vector < vector <ll> > A, vector < vector <ll> > B)
{
	vector < vector <ll> > C(6, vector <ll> (6));

	f(i, 1, 6)
	{
		f(j, 1, 6)
		{
			f(k, 1, 6)
			{
				C[i][j] = (C[i][j]%mod + (A[i][k]*B[k][j])%mod)%mod;
			}
		}
	}
	return C;
}

vector < vector <ll> > fastExponentiation(vector < vector <ll> > T, ll b)
{
	if(b==1)
		return T;
	
	vector < vector <ll> > X = fastExponentiation(T, b/2);

	X = matrixMultiplication(X, X);

	if(b&1)
		X = matrixMultiplication(X, T);


	return X;
}

ll matrixExponentiation(ll n)
{
	if(n < 5)
	{
		int x = n;
		return arr[n];
	}
	vl F1(6);
	f(i, 1, 6)
		F1[i] = arr[i-1];

	vector < vector <ll> > T(6, vector<ll> (6));

	f(i, 1, 6)
	{
		f(j, 1, 6)
		{
			if(i < 5)
			{
				if(j == i+1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
				continue;
			}
		}
		T[5][i] = arr2[i-1];
	}

	T = fastExponentiation(T, n-1);

	ll result = 0;

	f(i, 1, 6)
		result = (result + (T[1][i]*F1[i])%mod)%mod;

	return result;

}

int main(void)
{
	int t;
	get(t);
	w(t)
	{
		f(i, 0, 5)
		{
			ll x;
			get(x);
			arr.pb(x);
		}
		ll n;
		get(n);
		pln(matrixExponentiation(n));
		arr.clear();
	}

}