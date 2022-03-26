#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    int n,m;cin >> n >> m;n++;m++;
    vector<int> a(n),b(m),c(n+m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n+m-1;i++){
        cin >> c[i];
    }
    b[0] = c[0]/a[0];
    b[1] = (c[1] - b[0]*a[1])/a[0];
    int k;
    for(int i = 1;i<m/2;i++){
        k = 0;
        for(int j=max(0,i-int(a.size())+1);j<min(i,int(b.size()));j++){
            // cout << "i j : " << i << " " << j << "\n";
            // cout << k << " " << b[j] << " " << a[i-j] << "\n";
            // if(i-j >= a.size() || j >= b.size())continue;
            k += b[j]*a[i-j];
            // cout << "k : " << k << "\n";
        }
        b[i] = (c[i]-k)/a[0];
    }
    b[m-1] = c[n+m-2]/a[n];
    for(int i = m-2;i>m/2;i--){
        k = 0;
        for(int j=max(0,i-int(a.size())+1);j<min(i,int(b.size()));j++){
            // cout << "i j : " << i << " " << j << "\n";
            // cout << k << " " << b[j] << " " << a[i-j] << "\n";
            // if(i-j >= a.size() || j >= b.size())continue;
            k += b[j]*a[i-j];
            // cout << "k : " << k << "\n";
        }
        b[i] = (c[i+n-1]-k)/a[0];
    }
    // b[m-1] = c[n+m-1]/a[n-1];
    // cout << "\n";
    for(auto element : b){
        cout << element << " ";
    }
}