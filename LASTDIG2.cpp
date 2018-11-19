#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    // your code goes here
    ll t;
    cin>>t;
    while(t--){
        string s1;
        ll b;
        cin>>s1>>b;
        if(b==0) {
            cout<<1<<endl;continue;
        }
        ll a;
        a=s1[s1.length()-1]-'0';
        if(a==0) {
            cout<<0<<endl;continue;
        }
        ll rem[4],temp=a%10;
        for(ll i=0;i<4;i++){
            rem[i]=temp;
                temp=(temp*a)%10;
        }
        ll left_over=b%4;
        if(left_over==0 ) left_over=4;
        cout<<rem[--left_over]<<endl;
    }
    return 0;
}
