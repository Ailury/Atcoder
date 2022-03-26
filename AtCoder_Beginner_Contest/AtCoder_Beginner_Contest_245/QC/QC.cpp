#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    int n,k,t=0;cin >> n  >> k;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int x,xx,c,cc;x = a[0];xx = b[0];
    for(int i=1;i<n;i++){
        if(abs(a[i]-x)<=k || abs(a[i]-xx)<=k)c = a[i];
        else c = 2000000001;
        if(abs(b[i]-x)<=k || abs(b[i]-xx)<=k)cc = b[i];
        else cc = 2000000001;
        if(c==2000000001 && cc == 2000000001){
            t = 1;
            // cout << i << "\n";
            // cout << x << " " << xx << " " << a[i] << " " << b[i] << "\n";
        }
        x = c;
        xx = cc;
        
    }
    if(t)cout << "No";
    else cout << "Yes";
}