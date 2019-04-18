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

int c, r;
char mat[1001][1001];
int dist[1001*1001];
bool visited[1001*1001];

bool isSafe(int i, int j){
	if((i>=0 && i<r) && (j>=0 && j<c) && mat[i][j]=='.')
		return true;

	return false;
}

unordered_map < int, vector<int> > adjList;

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
		adjList.clear();
		get2(c, r);
		f(i, 1, r+1){
			f(j, 1, c+1){
				get1(mat[i][j]);
			}
		}
		int src = 0;
		f(i, 1, r+1){
			f(j, 1, c+1){
				if(mat[i][j]=='.'){
					int i_idx = (i-1)*c + (j);
					// watch(i_idx);
					if(isSafe(i, j-1)){
						src = i_idx;
						adjList[i_idx].pb(i_idx-1);
					}
					if(isSafe(i, j+1)){
						adjList[i_idx].pb(i_idx+1);
					}
					if(isSafe(i-1, j)){
						adjList[i_idx-c].pb(i_idx);
					}
					if(isSafe(i+1, j)){
						// watch(i_idx);
						adjList[i_idx+c].pb(i_idx);
					}
				}
			}
		}
		int res = 0;
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		bfs(src);
		int idx, ans = -1; 
		f(i, 0, r*c + 1){
			if(ans < dist[i])
				ans = dist[i], idx = i;
		}
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		bfs(idx);
		ans = -1;
		f(i, 0, r*c + 1){
			if(ans < dist[i])
				ans = dist[i];
		}
		if(ans > res)
			res = ans;
		// pls(idx);
		put("Maximum rope length is ");
		put(res);
		pln('.');
	}
	// tick();
}	