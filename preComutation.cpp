#include<bits/stdc++.h>
using namespace std;
const int M= 1e9+7;
const int N = 1e5+10;
long long fact[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    fact[0]=fact[1]=1;
    for(int i=2;i<=N;i++){
        fact[i]=fact[i-1]*i;
    }
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<< fact[n] << endl;
    }
    //0(T*N)=0(N^2); Brute force
    //0(N)   Much optimized
return 0;
}