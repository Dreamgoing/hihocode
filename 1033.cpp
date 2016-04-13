//
// Created by 王若璇 on 16/3/10.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
const int mod = (int)1e9+7;
typedef long long ll;
ll dp[20][300][10];//dp[i][j][k] 表示第 i 位 ,和为 j 在,第 i 位填 k ,有多少种
unordered_map<int,vector<ll> > mmp;
void init(){
    for(int i = 0;i<9;i++){
        dp[1][i+100][i] = 1;
    }
    for(int i = 2;i<20;i++){
        if(i%2==0){
            for(int j = 0;j<9;j++){
                for(int k = 0;k<=280;k++){
                    long long tmp = dp[i-1][k][j];
                    for(int m = 0;m<9;m++){
                        dp[i][k-m][m] += tmp;
                    }
                }
            }
        } else{
            for(int j = 0;j<9;j++){
                for(int k = 0;k<=280;k++){
                    long long tmp = dp[i-1][k][j];
                    for(int m = 0;m<9;m++){
                        dp[i][k+m][m] += tmp;
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long l,r,k;
    while (cin>>l>>r>>k){
        init();
        for()

    }


    return 0;
}
