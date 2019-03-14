#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a,b;
	cin >> a >> b;
	while(a!=-1&&b!=-1){
		int r=0;
		if(a>b)
			swap(a,b);
		if(a==0&&b==0);
		else
			r = ceil(b/(a+1.0));
		cout << r << "\n";
		cin >> a >> b;
	}
}
