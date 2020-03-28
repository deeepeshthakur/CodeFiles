#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

inline long long __min(long long a, long long b){
    return (a==-1 || b==-1)?(a+b+1):(min(a,b));
}

long long valf(long long val, int k, long long cum_suml, long long cum_sumr, int num_l, int num_r){
    if(k<=0)
        return 0ll;
    long long ans=-1;
    if(num_l>=k){
        ans=__min(ans,(val-1)*num_l-cum_suml+k);
    }
    if(num_r>=k){
        ans=__min(ans,cum_sumr-(val+1)*num_r+k);
    }
    ans=__min(ans,cum_sumr-(val+1)*num_r+(val-1)*num_l-cum_suml+k);
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n,0ll);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }  

    sort(full(a));
    int cnt_dist=0;
    vector<long long> dist_elements,sum_cum;
    vector<int> number_of_elements;
    long long tot_sum=0;
    for(int i=0;i<n;i++){
        tot_sum+=a[i];
        if(cnt_dist>0 && dist_elements[cnt_dist-1]==a[i]){
            sum_cum[cnt_dist-1]+=a[i];
            number_of_elements[cnt_dist-1]++;
        }
        else{
            dist_elements.pb(a[i]);
            sum_cum.pb(a[i]);
            number_of_elements.pb(1);
            cnt_dist++;
        }
    }

    long long ans=-1,sum_so_far=0;
    long long l,r,mid,v1,v2,v3;
    int ele_so_far=0;
    cnt_dist=dist_elements.size();
    for(int i=0;i<cnt_dist;i++){
        ans=__min(ans,valf(dist_elements[i],k-number_of_elements[i],sum_so_far,tot_sum-sum_cum[i]-sum_so_far,ele_so_far,n-ele_so_far-number_of_elements[i]));
        if(i>0&&dist_elements[i]-dist_elements[i-1]>1){
            l=dist_elements[i-1]+1;r=dist_elements[i]-1;
            while(r-l>1){
                mid=(l+r)/2;
                v1=valf(mid-1,k,sum_so_far,tot_sum-sum_so_far,ele_so_far,n-ele_so_far);
                v2=valf(mid,k,sum_so_far,tot_sum-sum_so_far,ele_so_far,n-ele_so_far);
                v3=valf(mid+1,k,sum_so_far,tot_sum-sum_so_far,ele_so_far,n-ele_so_far);
                if(v1>=v2&&v2>=v3){
                    l=mid;
                }
                else{
                    r=mid;
                }
            }
            v1=valf(l,k,sum_so_far,tot_sum-sum_so_far,ele_so_far,n-ele_so_far);
            v2=valf(r,k,sum_so_far,tot_sum-sum_so_far,ele_so_far,n-ele_so_far);
            ans=__min(ans,__min(v1,v2));
        }
        sum_so_far+=sum_cum[i];
        ele_so_far+=number_of_elements[i];        
    }
    cout<<ans<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}