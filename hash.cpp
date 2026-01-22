/*Given an array of n integers and m quires
in each quirey we have to output the count of a given 
number in the array.

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int hsh[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
    arr.push_back(t);
    hsh[arr[i]]++;
    }
    int m;
    cin>>m;
    while(m--){
        int a;
        cin>>a;
        cout<<hsh[a]<<endl;
    }
return 0;
}