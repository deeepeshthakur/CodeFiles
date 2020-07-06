#include<bits/stdc++.h>
using namespace std;

// long long f(long long l,long long r,long long x,long long y){
//     // cout<<"called "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
//     if(l>r) return 0;
//     if(l==r) return r;
//     long long curr=0;
//     vector<int> bz(45,0);

//     for(long long i=44;i>=0;i--){
//         long long tmp=1ll<<i;
//         if(curr+tmp<=r)
//             if((tmp&x)==(tmp&y)){
//                 if((tmp&x)>0){
//                     curr+=tmp;
//                     bz[i]=1;
//                 }
//             }
//             else i=-1;
//     }

//     for(long long i=44;i>=0;i--)
//         if(bz[i]==0 && curr+(1ll<<i)<=r && (x&(1ll<<i))!=(y&(1ll<<i))){
//             curr+=(1ll<<i);
//             bz[i]=1;
//             i=-1;
//         }
    
//     for(long long i=44;i>=0;i--)
//         if(bz[i]==0 && curr+(1ll<<i)<=r){
//             if(bz[i]==0 && (x&curr)>(y&curr) && (y&(1ll<<i))>0){
//                 bz[i]=1;
//                 curr+=(1ll<<i);
//             }
//             if(bz[i]==0 && (x&curr)<(y&curr) && (x&(1ll<<i))>0){
//                 bz[i]=1;
//                 curr+=(1ll<<i);
//             }
//         }

//     for(long long i=44;i>=0;i--)
//         if(bz[i]==0 && (curr+(1ll<<i))<=r && ((x|y)&(1ll<<i))>0){
//             bz[i]=1;
//             curr+=(1ll<<i);
//         }

//     if(curr<l){
//         for(long long i=44;i>=0;i--)
//             if(bz[i]==0 && curr+(1ll<<i)<l){
//                 bz[i]=1;
//                 curr+=(1ll<<i);
//             }

//         for(long long i=0;i<45;i++)
//             if(bz[i]==0 && curr+(1ll<<i)>=l && curr+(1ll<<i)<=r){
//                 bz[i]=1;
//                 curr+=(1ll<<i);
//                 i=50;
//             }
//     }
//     return curr;
// }

long long bestof(long long a,long long b,long long x,long long y){
    if(a>b) swap(a,b);
    if((a&x)*(a&x) < (b&x)*(b&y)) return b;
    return a;
}

long long dpf(long long l,long long r, long long x, long long y,map<pair<long long,long long>,long long>& ht, int which){ 
    cout<<l<<" "<<r<<"\n";
    if(ht.find({l,r})==ht.end()){
        if(which==0){
            long long p2=(r+1)/2,prev=dpf(0,p2-1,x,y,ht,0),curr=prev+p2;
            ht.insert({{l,r},bestof(prev,curr,x,y)});
        }
        if(which==1){
            if(l==0)
                ht.insert({{l,r},dpf(0,r,x,y,ht,0)});
            else{
                long long p2=(r+1)/2;
                if(l>=3*p2/2)
                    ht.insert({{l,r},dpf(l-3*p2/2,p2/2 -1,x,y,ht,1)+3*p2/2});
                else
                    ht.insert({{l,r},bestof(dpf(l-p2,p2/2-1,x,y,ht,1)+p2,dpf(0,p2/2-1,x,y,ht,0)+3*p2/2,x,y)});
            }
        }
        if(which==2){
            long long mul=8;
            while(mul<r) mul*=2;
            if(r==mul-1)
                ht.insert({{l,r},dpf(0,mul/2-1,x,y,ht,0)+mul/2});
            else{
                mul/=2;
                if(r<=mul+mul/2-1) ht.insert({{l,r},dpf(max(0ll,l-mul),r-mul,x,y,ht,2)+mul});
                else ht.insert({{l,r},bestof(dpf(0ll,mul/2-1,x,y,ht,0)+mul,dpf(0,r-mul-mul/2,x,y,ht,2)+mul+mul/2,x,y)});
            }
        }
        if(which==3){   
            long long mx=-1,ind=-1;
            for(long long i=0;i<4;i++) if(l<=i && i<=r && mx<(x&i)*(y&i)) { ind=i;mx=(x&ind)*(y&ind);}
            for(long long i=4;i<=r;i*=2)
                if(!(i>r || 2*i-1<l))
                    if(l<=i && 2*i-1<=r)
                        ind=bestof(ind,dpf(0,i-1,x,y,ht,true)+i,x,y);
                    else
                        if(i<l && 2*i-1<=r)
                            ind=bestof(ind,dpf(l,2*i-1,x,y,ht,1),x,y);                        
                        else
                            ind=bestof(ind,dpf(i,r,x,y,ht,2),x,y);
            ht.insert({{l,r},ind});
        }
    }
    return ht.find({l,r})->second;
}

long long f(long long l,long long r,long long x, long long y){
    map<pair<long long,long long>,long long> ht;
    for(long long i=0;i<8;i++){
        for(long long j=i;j<8;j++){
            long long mx=-1,ind=-1;
            for(long long k=i;k<=j;k++){
                if((x&k)*(y&k)>mx){
                    mx=(x&k)*(y&k);
                    ind=k;
                }
            }
            ht.insert({{i,j},ind});
        }
    }

    for(long long i=8;i<=r;i*=2){
        dpf(0,i-1,x,y,ht,0);
    }
    return dpf(l,r,x,y,ht,3);
}

int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long x,y,curr_l,curr_r,curr=0,ans=0,mx=-1;
        cin>>x>>y>>curr_l>>curr_r;
        ans=f(curr_l,curr_r,x,y);
        cout<<ans<<"\n";
    }
    return 0;
}