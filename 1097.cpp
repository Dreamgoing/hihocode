//
// Created by 王若璇 on 16/3/11.
//
/*prim algorithm*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int max_n = 2000;
const int inf = 0x3f3f3f3f;
int graph[max_n][max_n];
int minCost[max_n];
bool visit[max_n];
int prim(int cost[][max_n],int n){
    int res = 0;
    for(int i = 0;i<=n;i++){
        minCost[i] = inf;
        visit[i] = false;
    }
    minCost[0] = inf;
    minCost[1] = 0;
    while (true){
        int v = 0;
        for(int i = 1;i<=n;i++){
            if (minCost[i] < minCost[v] && !visit[i]) {
                v = i;
            }
        }
        if(v==0){
            break;
        }
        visit[v] = true;
        res+=minCost[v];
        for(int i = 1;i<=n;i++){
            minCost[i] = min(minCost[i],cost[v][i]);
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        memset(graph,inf, sizeof(graph));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cin>>graph[i][j];
            }
        }
        cout<<prim(graph,n)<<endl;
    }
    return 0;
}