//
// Created by 王若璇 on 16/3/1.
//
/*
 * kmp算法
 * NEXT数组
 * NEXT[0] = -1
 * NEXT[i] = max{ 0<=k< i | str.substring(1, k) == str.substring(i - k +1 , i) }
 * 其中str.substring(i, j)表示str从位置i到位置j的子串，如果i>j则,substring为空*/
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int max_n = 1e6+100;
void getNext(string pattern,int pattern_next[]){
    int parrern_len = pattern.length();
    //memset(pattern_next,0, sizeof(pattern_next));
    pattern_next[0]=0;
    int p=0,q=0;
    for(int i = 1;i < parrern_len;i++){
        q = i;
        while(p>0&&pattern[q]!=pattern[p]){
            p = pattern_next[p-1];
        }
        if(pattern[q]==pattern[p]){
            p++;
        }
        pattern_next[q] = p;
    }
}
int kmp(string pattern,string original,int pattern_next[]){
    int patter_len = pattern.length();
    int original_len = original.length();
    getNext(pattern,pattern_next);
    int num = 0;
    int p = 0;
    for(int i = 0;i<original_len;i++){
        while (p&&original[i]!=pattern[p]){
            p = pattern_next[p-1];
        }
        if(pattern[p]==original[i]){
            p++;
        }
        if(p==patter_len){
            num++;
        }
    }
    return num;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int pattern_next[max_n];
    string pattern,original;
    while (cin>>n){
        for(int i = 0;i<n;i++){
            cin>>pattern>>original;
            memset(pattern_next,0, sizeof(pattern_next));
            cout<<kmp(pattern,original,pattern_next)<<endl;
        }

    }

    return 0;
}

