#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    int n,m;cin >> n >> m;
    // vector<int> a,b,c,d;
    vector<pair<int,int>> choc(n),box(m);
    for(int i=0;i<n;i++){
        cin >> choc[i].first;
    }
    for(int i=0;i<n;i++){
        cin >> choc[i].second;
    }
    for(int i=0;i<m;i++){
        cin >> box[i].first;
    }
    for(int i=0;i<m;i++){
        cin >> box[i].second;
    }
    sort(choc.begin(),choc.end());
    sort(box.begin(),box.end());
    n--;m--;int ok = 1;
    while(n > -1){
        if(choc[n].first > box[m].first){
            ok = 0;
            break;
        }
        if(choc[n].first <= box[m].first &&
                choc[n].second <= box[m].second){
            choc.pop_back();box.pop_back();
            n--;m--;continue;
        }
        if(choc[n].second)continue;;
    }
}