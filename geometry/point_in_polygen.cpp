#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define for(i,a,n) for(int i=a;i<n;i++)
#define x first
#define y second
#define mp make_pair

int crossproduct(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3){
    ll temp = (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
    if(temp==0) return 0;
    return (temp<0) ? -1 : 1 ; 
}
bool onsegment(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3){
    if(min(p1.first,p2.first) <= p3.first && max(p2.first,p1.first) >= p3.first &&
     max(p1.second,p2.second) >= p3.second && min(p1.second,p2.second)<=p3.second) return true;
    return false;
}

int solve(pair<ll,ll>p1,pair<ll,ll>p2,pair<ll,ll>p3,pair<ll,ll>p4){
    int c1=crossproduct(p1,p2,p3);
    int c2=crossproduct(p1,p2,p4);
    int c3=crossproduct(p3,p4,p1);
    int c4=crossproduct(p3,p4,p2);
 
    if(c1 != c2 && c3 != c4)return 1;
    // if(c1==0 && onsegment(p1,p2,p3))return 2;
    // if(c2==0 && onsegment(p1,p2,p4))return 2;
    // if(c3==0 && onsegment(p3,p4,p1))return 2;
    // if(c4==0 && onsegment(p3,p4,p2))return 2; 
    return 0;
}

void solve(){
int n,m;
cin>>n>>m;
vector<pair<int,int> >v(n);
for(i,0,n)cin>>v[i].x>>v[i].y;
for(i,0,m){
    pair<ll,ll>p;
    cin>>p.x>>p.y;
    int cnt=0;
    bool jump =false;
    for(j,0,n){
        if(crossproduct(v[j],v[(j+1)%n],p) == 0 && onsegment(v[j],v[(j+1)%n],p)){
            jump = true;
            break;
        }
        int t = solve(v[j],v[(j+1)%n],p,{INT_MAX,INT_MAX+1});
        cnt += t;
    }
    if(jump)cout<<"BOUNDARY"<<endl;
    else if(cnt&1)cout<<"INSIDE"<<endl;
    else cout<<"OUTSIDE"<<endl;
}
}

int main(){
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
