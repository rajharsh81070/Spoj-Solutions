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

int merge_sort(int arr[], int left, int mid, int right){
	int n1 = mid-left+1, n2 = right-mid;
	int arr1[n1], arr2[n2];
	for(int i=0; i<n1; i++)
		arr1[i] = arr[left+i];
	for(int i=0; i<n2; i++)
		arr2[i] = arr[mid+i+1];
	int i = 0, j = 0, count_inversion = 0, k = left;
	while(i<n1 && j<n2){
		if(arr1[i] > arr2[j]){
			arr[k] = arr2[j];
			j++;
			count_inversion += (n1-i);
		}
		else{
			arr[k] = arr1[i];
			i++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = arr1[i];
		k++;
		i++;
	}
	while(j < n2){
		arr[k] = arr2[j];
		k++;
		j++;
	}
	return count_inversion;
}

int merge(int arr[], int left, int right){
	int count_inversion = 0;
	if(left<right){
		int mid = left + (right-left)/2;
		count_inversion = merge(arr, left, mid) + merge(arr, mid+1, right) + merge_sort(arr, left, mid, right);
	}
	return count_inversion;
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
		int n;
		get1(n);
		unordered_map <string, int> mp;
		f(i, 1, n+1){
			string str;
			get1(str);
			mp[str] = i;
		}
		int arr[n+1] = {0};
		f(i, 1, n+1){
			string str;
			get1(str);
			arr[i] = mp[str];
		}
		int count_inversion = merge(arr, 1, n);
		pln(count_inversion);
	}
	// tick();
}