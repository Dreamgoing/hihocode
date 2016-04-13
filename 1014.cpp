//
// Created by 王若璇 on 16/3/1.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int max_n = 100000;
const int char_num = 26;
struct TrieNode{
    int prefix_num;
    TrieNode* node[char_num];
    TrieNode(){
        prefix_num = 0;
    }
}*root;
void insert(string str){
    TrieNode *tmp_root = root;
    int str_len = str.length();
    int pos = 0;
    int c_pos = 0;
    for(pos=0;pos<str_len;pos++){
        c_pos = str[pos]-'a';
        if(tmp_root->node[c_pos]!=NULL){
            tmp_root = tmp_root->node[c_pos];
        } else{
            tmp_root->node[c_pos] = new TrieNode();
            tmp_root = tmp_root->node[c_pos];
        }
        tmp_root->prefix_num++;
    }
}
int getPrefixNum(string prefix){
    TrieNode *tmp_root = root;
    int c_pos = 0;
    for(int i = 0;i<prefix.length();i++){
        c_pos = prefix[i]-'a';
        if(tmp_root->node[c_pos]!=NULL){
            tmp_root = tmp_root->node[c_pos];
        } else{
            return 0;
        }
    }
    return tmp_root->prefix_num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    while (cin>>n){
        string word;
        root = new TrieNode();
        for(int i = 0;i < n;i++){
            cin>>word;
            insert(word);
        }
        cin>>m;
        string prefix;
        for(int i = 0;i < m;i++){
            cin>>prefix;
            cout<<getPrefixNum(prefix)<<endl;
        }


    }
    return 0;
}
