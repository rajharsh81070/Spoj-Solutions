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

class Graph{
	// int n;
	map<int , list<int>> adjList;
public:
	void addEdge(int u, int v, bool bidirec=true){
		adjList[u].pb(v);
		if(bidirec)
			adjList[v].pb(u);
	}
	void connected_components_helper(int src, map<int, bool> &visited){
		visited[src] = true;
		for(auto node:adjList[src]){
			if(!visited[node])
				connected_components_helper(node, visited);
		}
	}
	bool connected_components(int src){
		int connected_component = 1;
		map<int , bool> visited;
		connected_components_helper(src, visited);
		for(auto node:adjList){
			int v = node.first;
			if(!visited[v]){
				connected_components_helper(src, visited); 
				connected_component++;
			}
		}
		// watch(connected_component);	
		if(connected_component>1)
			return false;
		else
			return true;
	}
	bool cycle_detection(int node, map<int , bool> &visited, int parent){
		visited[node] = true;
		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				bool check = cycle_detection(neighbour, visited, node);
				if(check)
					return true;
			}
			else if(parent!=neighbour)
				return true;
		}
		return false;
	}
	bool isCyclic(){
		map<int , bool> visited;
		for(auto i:adjList){
			int node = i.first;
			if(!visited[node]){
				bool check = cycle_detection(node, visited, node);
				if(check)
					return true;
			}
		}
		return false;
	}
};

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	get2(n, m);
	Graph g;
	w(m){
		int x, y;
		get2(x, y);
		g.addEdge(x, y);
	}
	// watch(g.connected_components(1));
	// watch(!g.isCyclic());
	if(g.connected_components(1) && (!g.isCyclic()))
		put("YES");
	else
		put("NO");
	// tick();
}