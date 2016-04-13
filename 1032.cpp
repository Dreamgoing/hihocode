//
// Created by 王若璇 on 16/3/2.
//
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
/*
 * 最长回文子串问题:
 * 1.枚举字串中心位置
 * f[i]表示以第i个字符为中心的最长回文子串的长度
 * f[i]>=min{f[i-2],f[i-1]-2}
 * suffix
 * 后缀数组: 后缀数组 SA 是一个一维数组,
 * 它保存1..n 的某个排列 SA[1], SA[2],......,SA[n],并且保证 Suffix(SA[i]) < Suffix(SA[i+1]),1≤i<n。
 * 也就是将 S 的 n 个后缀从小到大进行排序之后把排好序的后缀的开头位置顺 次放入 SA 中。
 * 名次数组:名次数组 Rank[i]保存的是 Suffix(i)在所有后缀中从小到大排 列的“名次”。
 * 详情见"后缀数组---处理字符串的有力工具"*/
/********************************/
/*回文串 Manacher algorithm
 * 利用了动态规划的思想
 * p[i]表示以i为中心最大回文子串的长度
 * f(i) ≥ min{f(2*j-i) , f(j) -2*(i-j))
 * 用上述公式进行优化
 * 两个条件只是做了剪枝和优化*/
using namespace std;
const int max_n = 1e6+100;
int manacher(string str,int p[]){
    int maxID = 0;
    int maxRad = 0;
    int maxL = 0;
    int str_len = str.length();
    for(int i = 1;i<str_len;i++){
        if(maxRad>i){
            p[i] = min(p[2*maxID-i],maxRad+i);
        } else{
            p[i]=1;
        }
        while (i>p[i]&&str[i-p[i]]==str[i+p[i]]){
            p[i]++;
        }
        if(maxRad<p[i]+i){
            maxRad = p[i]+i;
            maxID = i;
        }
        if(maxL<p[i]){
            maxL = p[i];
        }
    }
    return maxL;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string str;
    string copy;
    char strc[max_n];
    char copyc[max_n];
    int p[max_n];
    while (cin>>n){
        for (int i = 0; i < n; i++) {
            cin>>str;
            memset(p,0,sizeof(p));
            int j = 1;
            strcpy(strc,str.c_str());
            for(int i = 0;i<str.length();i++,j+=2){
                copyc[j] = strc[i];
                copyc[j+1] = '*';
            }
            copyc[0] = '&';
            copyc[j] = '0';
            copy = copyc;
            cout<<copy<<endl;
            cout<<manacher(copy,p)-1<<endl;
        }
    }

    return 0;
}
