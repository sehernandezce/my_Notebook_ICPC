//Algorithm or Logic: Binary indexed tree / Fenwick tree One Dimension
//Complexity: O(log n) -> Range sum query or Updating a value
// Index 1 to n
struct indexTree{ 
    int n = 0;
    ll tree[MAXN] = {0}; 
    indexTree(int len):n(len){}
    void add(int i, ll x){
        //int ax = i;
        while(i<=n){
            tree[i] += x;
            i += i&-i;
        }
        //cout << tree[ax] << " ";
    }
    ll sum (int i){
        ll s = 0;
        while(i >= 1){
            s += tree[i];
            i -= i&-i; // i&-i calcula p(i) -> 
                       //La mayor potencia de 2 que divide a i p(6) = 2;
                       //Least Significant Bit of i having a value of 1
        }
        return s;
    }
    ll sum(int l, int r){
        //cout << sum(r) << " - " << sum(l-1) << endl;
        return sum(r) - sum(l-1);
    }

    //
    ll get(int i){ // Return a single element's value
        return sum(i,i);
    }
    void update(int i, ll val){
        add(i, val - get(i));
    }
};
//

///REVISAR!!
int n;
ll bit[200002];
void update(int pos, ll val) {
	for (; pos <= n; pos += pos & -pos) bit[pos] += val;
}

ll query(int a, int b) {
	ll ans = 0;
	for (; b; b -= b & -b) ans += bit[b];
	for (a--; a; a -= a & -a) ans -= bit[a];
	return ans;
}
