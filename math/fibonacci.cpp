/*
Algorithm or Logic: Fibonacci
Complexity:O(n)
Storage: 
Link: 
More info: 
https://quantdare.com/numeros-de-fibonacci/
https://www.wextensible.com/temas/recursivos/fibonacci.html
calculator: https://es.numberempire.com/fibonaccinumbers.php
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll; 

/* 
int fibo(int i){
    if(i<2) return i;
    return (fibo(i-1) + fibo(i-2));
}
*/


//  Time O(n) ; storage >long long when n>92
ll fibo(int n){
    ll preant=0,ant=1,ans=0;
    //cout << "0 1 ";
    for(int i=2; i<=n; i++) {
        ans=preant+ant;
        //cout << ans << " ";
        preant=ant;
        ant=ans;
    }
    //cout << endl;
    return n<2 ? n : ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t; 
    //fibo(t);
    cout << fibo(t) << endl;

    return 0;
}
