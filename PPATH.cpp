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

#define MAXN 10000

bool check[MAXN];
vector <int> prime;

void sieve(){
	memset(check, true, sizeof(check));
	for(int i=2; i<MAXN; i+=2)
		check[i] = false;
	for(int i=3; i*i<MAXN; i+=2){
		if(check[i]){
			for(int j=i*i; j<MAXN; j+=2*i)
				check[j] = false;
		}
	}
	for(int i=1000; i<MAXN; i++){
		if(check[i])
			prime.pb(i);
	}
}

int main(void)
{
	fast();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	sieve();
	unordered_map<int, list<int>>adjList;
	f(i, 0, prime.z-1){
		int x = prime[i];
		vi tmp1;
		while(x > 0){
			int n = x%10;
			x/=10;
			tmp1.pb(n);
		}
		f(j, i+1, prime.z){
			vi tmp2;
			int y = prime[j];
			while(y > 0){
				int n = y%10;
				y/=10;
				tmp2.pb(n);
			}
			int count = 0;
			f(i, 0, 4){
				if(tmp1[i]!=tmp2[i])
					count++;
			}
			if(count==1){
				adjList[prime[i]].push_back(prime[j]);
				adjList[prime[j]].push_back(prime[i]);
			}
		}
	}
	/*for(auto i: adjList){
		int row = i.first;
		cout << row << "->";
		for(auto node: i.second)
			cout << node << ',';
		cout << '\n';
	}*/
	int t;
	get1(t);
	w(t){
		int x, y;
		get2(x, y);
		queue<int>q;
		bool *visited = new bool [MAXN]{0};
		int *dist = new int [MAXN]{0};
		int *parent = new int [MAXN]{-1};
		q.push(x);
		visited[x] = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int neighbour: adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		// int temp = y;
		/*while(temp!=-1){
			pls(temp);
			temp = parent[temp];
		}*/
		pln(dist[y]);
	}
	// tick();
}