//
// Created by 王若璇 on 16/4/11.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 1100;
const int max_st = 1<<11;
int a[max_n];
int dp[max_n][max_st];
int n,m,q;
int upm=0;
int uppre = 0;
int ans = 0;
bool ok[max_n];
void init(){
    memset(ok,0, sizeof(ok));
    for(int i = 0;i<upm;i++){
        int val = i;
        int num = 0;
        while (val>0){
            num+=val&1;
            val = val>>1;
        }
        ok[i] = (num<=q);
    }
}
void solve(){
    uppre = upm&(!(1<<(m-1)));
    dp[0][1] = a[0];
    dp[0][0] = 0;
    for(int i = 1;i<n;i++){
        for(int k = 0;k<upm;k++){
            if(dp[i-1][k]==-1){
                continue;
            }
            //cout<<hex<<~(1<<(m-1))<<endl;
            int tmp = k&(~(1<<(m-1)));
            int aa = tmp<<1|1;
            int bb = tmp<<1|0;
            int s1 = (k<<1|1)&(upm-1);
            int s0 = (k<<1)&(upm-1);
            //cout<<aa<<" "<<s1<<" "<<bb<<" "<<s0<<endl;
            //cout<<hex<<" k "<<k<< " tmp "<<tmp<<endl;
            dp[i][bb] = max(dp[i][bb],dp[i-1][k]);
            if(ok[aa]){
                dp[i][aa] = max(dp[i][aa],dp[i-1][k]+a[i]);
            }
          //  cout<<dp[i][s0]<<" "<<dp[i][s1]<<endl;

        }

    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while (cin>>n>>m>>q){
        memset(dp,-1, sizeof(dp));
        memset(dp[0],0, sizeof(dp[0]));
        upm = 1<<m;
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        ans = 0;
        init();
        solve();
        for(int i = 0;i<upm;i++){
            ans = max(ans,dp[n-1][i]);
        }
        cout<<ans<<endl;

    }

    return 0;
}
