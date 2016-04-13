//
// Created by 王若璇 on 16/3/10.
//
/*Floyd Warshall algroithm to solve the shortest path*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int max_n = 1000;
const int inf = 0x3f3f3f3f;
int graph[max_n][max_n];
int dist[max_n][max_n];
void printSolution(int dist[][max_n],int n){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin>>n>>m){
        fork
        int a,b,c;
        memset(graph,inf, sizeof(graph));
        memset(dist,inf, sizeof(dist));
        for(int i = 0;i<m;i++){
            cin>>a>>b>>c;
            if(c<graph[a][b]){
                graph[a][b] = c;
                graph[b][a] = c;
                dist[a][b] = c;
                dist[b][a] = c;
            }


        }
        for(int i = 0;i<=n;i++){
            dist[i][i] = 0;
        }

        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        printSolution(dist,n);

    }


    return 0;
}
