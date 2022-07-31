#include <bits/stdc++.h>
void dfs(int node, vector<vector<int>> &adj, vector<int>& vtd, stack<int>& st){
    vtd[node]=true;
    for(int it:adj[node]){
        if(!vtd[it]) dfs(it,adj,vtd,st);
    }
    st.push(node);
}
void revDfs(int node, vector<vector<int>> &trans, vector<int>& vtd, vector<vector<int>>& ans,int& i){
    ans[i].push_back(node);
    vtd[node]=true;
    for(int it:trans[node]){
        if(!vtd[it]) revDfs(it,trans,vtd,ans,i);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &adj)
{
    //topo sort
    //transpose topo sort
    //dfs 2
    vector<int> vtd(n+1,false);
    stack<int> st;
    //TOPO SORT
    for(int i=0;i<n;i++){
        if(!vtd[i])
            dfs(i,adj,vtd,st);
    }
    //TRANSPOSE
    vector<vector<int>> trans;
    for(int i=0;i<n;i++){
        //make vtd falase so as to be reafy for dfs 2
        vtd[i]=0;
        for(int it:adj[i])
            trans[it].push_back(i);
    }
    //DFS 2 in rev order, that's why we made transpose
    vector<vector<int>> ans;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        int i=0;
        if(!vtd[t]){
            revDfs(t,trans,vtd,ans,i);
            i++;
        }
    }
}            