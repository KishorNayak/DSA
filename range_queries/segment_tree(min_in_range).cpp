#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fori(i,n) for(int i=0;i<n;i++)
#define fir first
#define sec second
#define mp make_pair
const int m = 8*1e5+9;
int segtree[m];

void build(int arr[],int low,int high,int ind){
    if(low==high){
        segtree[ind]=arr[low];
        return;
    }
    int mid = (low+high)>>1;
    build(arr,low,mid,2*ind+1);
    build(arr,mid+1,high,2*ind+2);
    segtree[ind] = min(segtree[2*ind+1],segtree[2*ind+2]);
}

int minimum(int ind,int low,int high,int a,int b){
    if(low>=a && high<=b)return segtree[ind];
    if(high<a || low > b )return INT_MAX;
    int mid = (low+high)>>1;
    int left = minimum(2*ind+1,low,mid,a,b);
    int right = minimum(2*ind+2,mid+1,high,a,b);
    return min(left,right);
}

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    arr[0]=INT_MAX;
    fori(i,n)cin>>arr[i+1];
    build(arr,0,n,0);
    fori(i,q){
        int a,b;
        cin>>a>>b;
        cout<<minimum(0,0,n,a,b)<<endl;
    }
}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
