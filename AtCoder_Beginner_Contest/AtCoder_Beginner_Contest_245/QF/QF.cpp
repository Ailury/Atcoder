#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int dfs(int i,int &f,vector<vector<int>> &g,vector<int> &kosaraju){
    if(kosaraju[i])return 0;
    kosaraju[i] = f++;
    // cout << "house "<< i << " f : " << kosaraju[i] << "\n";
    for(auto house : g[i]){
        // cout << "house " << i << " to house " << house <<"\n";
        dfs(house,f,g,kosaraju);
    }
    kosaraju[i] = f++;
    // cout << "house "<< i << " f : " << kosaraju[i] << "\n";
    return kosaraju[i];
}

int main(){
    int n,m,x,y;cin >> n >> m;
    vector<vector<int>> g(n+5);
    vector<vector<int>> gt(n+5);
    vector<vector<int>> gf(n+5);
    for(int i=0;i<m;i++){
        cin >> x >> y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        vector<int> u(n+5);
        int f = 1;
        gf[dfs(i,f,gt,u)/2].push_back(i);
    }
    vector<int> u(n+5);
    int ans = 0;
    for(int f=gf.size()-1;f>-1;f--){
        for(auto i : gf[f]){
            int ff = 1;
            int x = dfs(i,ff,g,u);
            if(x>2)ans += x/2;
        }
    }cout << ans;
}