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

#define MAXN 10005 
bool visited[MAXN];
int dist[MAXN];

class Graph{
	map < int , list<int> > adjList;
public:
	void addEdge(int u, int v, bool bidirec=true){
		adjList[u].pb(v);
		if(bidirec)
			adjList[v].pb(u);
	}
	void bfs(int src){
		queue <int> q;
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int neighbour: adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					dist[neighbour] = dist[node] + 1;
					// watch(neighbour);
					// watch(dist[neighbour]);
					visited[neighbour] = true;
				}
			}
		}
	}
};

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	get1(n);
	Graph g;
	int a, b;
	int j=n-1;
	w(j){
		get2(a, b);
		g.addEdge(a, b);
	}
	g.bfs(1);
	int tmp = -1, index;
	for(int i=1; i<=n; i++){
		// watch(dist[i]);
		if(tmp<dist[i])
			tmp = dist[i], index = i;
	}
	// watch(index);
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	g.bfs(index);
	int ans = -1;
	for(int i=0; i<n; i++){
		// watch(dist[i]);
		if(ans<dist[i])
			ans = dist[i];
	}
	pln(ans);
	// tick();
}