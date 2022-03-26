#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    auto it=v.begin();
    int i=0;
    while(it!=v.end()){
        if(i==*it){
            i++;
            it++;
            continue;
        }else if( i < *it){
            cout << i;
            break;
        }else if(i > *it)it++;
    }
    if(it==v.end())cout << i;
}