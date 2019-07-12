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
#define watch(x) cout << (#x) << " is " << (x) << endl

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

void tick(){
	static clock_t oldt;
	clock_t newt=clock();
	double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;
	oldt = newt;
	cout << '\n' << "The execution time is : " << diff << '\n';
}

int V;
unordered_map <string, int> hsh;
vector<vector<pair<int, int>>>graph;

void make_graph() {
	f(i, 1, V+1) {
		string str;
		get1(str);
		hsh[str] = i;
		int N;
		get1(N);
		w(N) {
			int idx, cost;
			get2(idx, cost);
			graph[i].pb(mp(idx, cost));
		}
	}
}

int dijkstra(int src, int des) {
	vector <int> dist(V+1);
	f(i, 1, V+1) dist[i] = INT_MAX;

	set <pair <int, int> > q;
	q.insert({0, src});
	dist[src] = 0;
	while(!q.empty()) {
		auto p = *q.begin();
		int par = p.Y;
		int dist_par = p.X;
		q.erase(q.begin());
		for(auto child: graph[par]) {
			int destination = child.X;
			if(dist[destination] > child.Y + dist_par) {
				auto f = q.find({dist[destination], destination});
				if(f!=q.end()) {
					q.erase(f);
				}
				dist[destination] = child.Y + dist_par;
				q.insert({dist[destination], destination});
			}
		}
	}
	return dist[des];
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
	w(t){
		get1(V);
		graph.resize(V+1);
		make_graph();
		int P;
		get1(P);
		w(P) {
			string s1, s2;
			get2(s1, s2);
			int ans = dijkstra(hsh[s1], hsh[s2]);
			pln(ans);
		}
		hsh.clear();
		graph.clear();
	}
	// tick();
}	