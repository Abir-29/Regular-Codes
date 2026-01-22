#include<bits/stdc++.h>
using namespace std;

void swapy(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

int partition(vector<int>&arr,int st,int end){
    int idx=st-1;
    for(int j=st;j<end;j++)
    {
        if(arr[j]<arr[end])
        {
            idx++;
            swapy(arr[idx],arr[j]);
        }
    }
    idx++;
    swapy(arr[idx],arr[end]);
    return idx;
}

void quickSort(vector<int>&arr,int st,int end){
   if(st<=end){ int pivIdx=partition(arr,st,end);
    quickSort(arr,st,pivIdx-1);
    quickSort(arr,pivIdx+1,end);
   }
}

int main(){
    vector<int>arr={3,4,1,2,8,5};
    int l=arr.size();
    quickSort(arr,0,l-1);
    for(int i=0;i<l;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}