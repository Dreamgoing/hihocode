//
// Created by 王若璇 on 16/4/6.
//
//max_flow algorithm Ford_Fulkerson implementation
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int max_n = 10000;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    int cap;
    int rev;
    Edge(){}
    Edge(int _to,int _cap,int _rev){
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
vector<Edge> graph[max_n];
bool visit[max_n];
void add_edge(int from,int to,int cap){
    graph[from].push_back(Edge{to,cap,(int)graph[to].size()});
    graph[to].push_back(Edge{from,0,(int)graph[from].size()-1});
}
int n,m;
//use dfs to find an augmenting path and add flow
/*int dfs(int v,int t,int f){
    if(v==t){
        return f;
    }
    visit[v] = true;
    for(int i = 0;i<graph[v].size();i++){
        Edge &e = graph[v][i];
        if(!visit[e.to]&&e.cap>0){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                return d;
            }

        }
    }
    return 0;

}*/
int match[max_n];
bool dfs(int v){
    visit[v] = true;
    for(int i = 0;i<graph[v].size();i++){
        int u = graph[v][i].to;
        int w = match[u];
        if(w<0||!visit[w]&&dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }

    }
    return false;
}
int bipartite_matching(){
    int res = 0;
    memset(match,-1, sizeof(match));
    for(int v = 0;v<n;v++){
        if(match[v]<0){
            memset(visit,0, sizeof(visit));
            if(dfs(v)){
                res++;
            }

        }
    }
    return res;
}
/*int max_flow(int s,int t){
    int flow = 0;
    for(;;){
        memset(visit,0, sizeof(visit));
        //int f = dfs(s,t,inf);
        if(f==0){
            return flow;
        }
        flow+=f;
    }
}*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n>>m){
        for(int i = 0;i<m;i++){
            int a,b;
            cin>>a>>b;
            add_edge(a,b,1);
        }
        cout<<bipartite_matching()<<endl;

    }
    return 0;
}

