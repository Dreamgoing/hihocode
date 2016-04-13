//
// Created by 王若璇 on 16/3/11.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int max_n = 10100;
const int max_m = 40400;
int color[max_n]={0};
vector<int> graph[max_n];
void init(int n){
    for(int i = 0;i<=n;i++){
        graph[i].clear();
    }
    memset(color,0, sizeof(color));
}
bool dfs(int u,int c){
    bool res = true;
    if(color[u]!=0){
        return c==color[u];

    } else{
        color[u] = c;
        for(int i = 0;i<graph[u].size();i++){
            res = res&&dfs(graph[u][i],-c);
        }

    }
    return res;

}
bool solve(int n){
    bool res = true;
    memset(color,0,sizeof(color));
    for(int i = 1;i<=n;i++){
        if(color[i]==0){
            res = res&&dfs(i,1);
            //cout<<res<<" *"<<endl;
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tCase = 0;
    cin>>tCase;
    while (tCase--){
        int n,m;
        cin>>n>>m;
        init(n);
        for(int i = 0;i<m;i++){
            int u,v;
            cin>>u>>v;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }
        if(solve(n)){
            cout<<"Correct"<<endl;
        } else{
            cout<<"Wrong"<<endl;
        }
    }


    return 0;
}
