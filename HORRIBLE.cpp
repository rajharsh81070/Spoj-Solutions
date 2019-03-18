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
#define get1(x) cin>>x
#define get2(x, y) cin>>x>>y
#define get3(x, y, z) cin>>x>>y>>z
#define put(x) cout<<x
#define pls(x) cout<<x<<' '
#define pln(x) cout<<x<<"\n"
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=b-1;i>=a;i--)
#define vput(a) f(i,0,a.z) pls(a[i]); nl;
#define vget(v) f(i,0,v.z) get1(v[i]);
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
#define lb(v,x) lower_bound(all(v),x)-v.begin()
#define ub(v,x) upper_bound(all(v),x)-v.begin()
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

void updateRange(ll tree[], ll lazy[], int ss, int se, int qs, int qe, ll value, int index)
{
	// resolving the lazy value
	if(lazy[index]!=0)
	{
		tree[index] += ((se-ss+1)*lazy[index]);
		if(ss!=se)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}

	// No Overlapping
	if(ss>qe || se<qs)
		return ;

	// Complete Overlapping
	if(ss>=qs && se<=qe)
	{
		tree[index] += ((se-ss+1)*value);
		if(ss!=se)
		{
			lazy[2*index] += value;
			lazy[2*index + 1] += value;
		}
		return ;
	}
	// Partial Overlapping

	int mid = (ss+se) >> 1;

	updateRange(tree, lazy, ss, mid, qs, qe, value, 2*index);

	updateRange(tree, lazy, mid+1, se, qs, qe, value, 2*index + 1);

	tree[index] = tree[2*index] + tree[2*index + 1];

	return ;
}

ll queryRange(ll tree[], ll lazy[], int ss, int se, int qs, int qe, int index)
{
	if(lazy[index]!=0)
	{
		tree[index] += ((se-ss+1)*lazy[index]);
		if(ss!=se)
		{
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index]; 
		}
		lazy[index] = 0;
	}

	if(ss>qe || se<qs)
		return 0;

	if(ss>=qs && se<=qe)
		return tree[index];

	int mid = (se+ss) >> 1;

	ll RightAns = queryRange(tree, lazy, ss, mid, qs, qe, 2*index);

	ll leftAns = queryRange(tree, lazy, mid+1, se, qs, qe, 2*index + 1);

	return leftAns+RightAns;
}

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t;
	get1(t);
	w(t)
	{
		int n, Q;
		get2(n, Q);
		ll tree[4*n + 5] = {0};
		ll lazy[4*n + 5] = {0};
		//ll arr[n] = {0};
		//build(arr, 0, n-1, tree, 1);
		w(Q)
		{
			int c, left, right; ll value;
			get1(c);
			if(c)
			{
				get2(left, right);
				ll result = queryRange(tree, lazy, 1, n, left, right, 1);
				pln(result);
			}
			else
			{
				get3(left, right, value);
				updateRange(tree, lazy, 1, n, left, right, value, 1);
				//f(i, 1, 4*n+5) pls(tree[i]);
				//nl;
			}
		}
		//f(i, 1, 4*n+5) pls(tree[i]);
		//nl;
	}
}