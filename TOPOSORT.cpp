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

struct compare  
 {  
   bool operator()(const int& l, const int& r)  
   {  
       return l > r;  
   }  
 };  

class Graph{
	int n;
	map<int , list<int>> adjList;
public:
	Graph(int v){
		n = v;
	}
	void addEdge(int u, int v){
		adjList[u].pb(v);
	}
	void topoSort(){
		// map<int, bool>visited;
		priority_queue<int,vector<int>, compare > q;
		map<int, int>inDegree;
		vi ordering;
		int cnt = 0;

		f(u, 1, n+1){
			// visited[node] = false;
			// watch(u);
			inDegree[u] = 0;
		}
		for(auto i:adjList){
			int node = i.first;
			for(int u: adjList[node])
				inDegree[u]++;
		}
		f(u, 1, n+1){
			// int u = node.first;
			if(!inDegree[u])
				q.push(u), watch(u);
		}
		while(!q.empty()){
			int node = q.top();
			ordering.pb(node);
			q.pop();
			for(auto neighbour:adjList[node]){
				inDegree[neighbour]--;
				if(!inDegree[neighbour])
					q.push(neighbour);
			}
			cnt++;
		}
		// watch(cnt);
		if(cnt!=n)
			put("Sandro fails.");
		else
			vput(ordering);
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
	// vi arr(n+1, 0);
	Graph g(n);
	w(m){
		int x, y;
		get2(x, y);
		g.addEdge(x, y);
	}
	// vput(arr);
	// int V = total(arr);
	g.topoSort();
	// tick();
}