// Sebastian "Seishi" GG
#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

typedef long long ll;

const int N = 100;

template <class T>
struct info
{
    T ans, mxpref, mxsuf, sum;
};

template<class T>
info<T> mrg(info<T> L, info<T> R)
{
    info<T> all;
    all.ans = max(max(L.ans, R.ans), L.mxsuf + R.mxpref);
    all.mxpref = max(L.mxpref,L.sum + R.mxpref);
    all.mxsuf = max(R.mxsuf,R.sum + L.mxsuf);
    all.sum = L.sum + R.sum;
    return all;
}

info<int> val[8*N];

template<class T>
void update(T node, T l, T r, T posa, T valx)
{
    if( l == r){
        val[node] = {valx,valx,valx,valx};
        return;
    }
    T m = (l+r)/2;
    if(posa<=m) update(node*2,l,m,posa,valx);
    else update(node*2+1,m+1,r,posa,valx);
    val[node] = mrg(val[node*2], val[node*2 + 1]);
        // node -> la posicion del nodo en el arreglo
        // if(izq) update izq
        //  else update der
        //  merge
}

template<class T>
info<T> query(T node, T l, T r, T a, T b){
    if(a <= l && r <= b) return val[node];
    if(r < a || b < l) return {-100000, -10000,-10000,-10000};
    T m = (l+r)/2;
    return mrg(query(node*2, l, m, a, b), query(node*2+1,m+1,r,a,b));
}

int main()
{  

    return 0;
}


/*
 vector <int> v = {1,3,1,-7,14,-3};
    for(int i = 0; i < (int)v.size(); i++){
        update<int>(1,0,5,i,v[i]);
    } 
    cout << query(1,0,5,3,3).ans << endl;

    //cout << val[1].ans << endl;
    //update<int> (1,0,5,4,-2);


*/
