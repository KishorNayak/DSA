#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define mp =make_pair
 
int crossproduct(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3){
    ll temp = (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
    if(temp==0) return 0;
    return (temp<0) ? -1 : 1 ; 
}
bool onsegment(pair<int,int>p1,pair<int,int>p2,pair<int,int>p3){
    if(min(p1.first,p2.first) <= p3.first && max(p2.first,p1.first) >= p3.first &&
     max(p1.second,p2.second) >= p3.second && min(p1.second,p2.second)<=p3.second) return true;
    return false;
}
bool solve(){
    int x1,x2,x3,y1,y2,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    pair<int,int>p1,p2,p3,p4;
    p1={x1,y1};p2={x2,y2};p3={x3,y3};p4={x4,y4};
 
    int c1=crossproduct(p1,p2,p3);
    int c2=crossproduct(p1,p2,p4);
    int c3=crossproduct(p3,p4,p1);
    int c4=crossproduct(p3,p4,p2);
 
    if(c1 != c2 && c3 != c4)return true;
    if(c1==0 && onsegment(p1,p2,p3))return true;
    if(c2==0 && onsegment(p1,p2,p4))return true;
    if(c3==0 && onsegment(p3,p4,p1))return true;
    if(c4==0 && onsegment(p3,p4,p2))return true;
 
    return false;
}
int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
cout<<(solve()?"YES" : "NO" )<<endl;
}
return 0;
}
