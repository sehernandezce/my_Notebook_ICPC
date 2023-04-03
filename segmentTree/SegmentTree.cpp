struct info{ // Can be Change!
    ll mn;
    int pos;
    bool operator >(const ll &p){ // Can be Change!
        if(pos == p && p == -1) return true;
        return false; 
    }
};

//Algorithm or Logic: Segment Tree
//Complexity: update/query : O(log n) space: O(4*n)
template<class T>
struct segTree{
    int n; 
    vector<T> tree; vector <T> val; 
    
    segTree<T>(){}
    segTree<T>(int x, vector<T>& st ,vector<T>& vals):n(x), tree(st),val(vals){build(1,0,n-1);}
    
    int left(int p) {return p << 1;}
    int right(int p) {return (p << 1) + 1;}
    
    void build(int p, int L, int R){
        if(L == R)
            tree[p] = val[L];
        else{
            int mid = L + ((R-L)>>1);
            build(left(p),L,(mid));
            build(right(p),(mid+1),R);
            T p1 = tree[left(p)], p2 = tree[right(p)];

            //
            tree[p] = mrg(p1,p2);
            //
        }
    }

    T query(int p, int L, int R, int i, int j){
        if(i > R || j < L) return {oo,-1}; // Segmento fuera del rango // Can be Change!
        if(L >= i && R<= j) return tree[p]; // Dentro del rango
        
        int mid = L + ((R-L)>>1);
        T p1 = query(left(p), L, mid, i, j);
        T p2 = query(right(p), mid+1, R, i, j);

        if(p1 > -1) return p2;
        if(p2 > -1) return p1;

        return (mrg(p1,p2));
    }
    
    T DoQuery(int i, int j){return query(1,0,n-1,i-1,j-1);}

    T mrg(T p1, T p2){ // Can be Change!
        T all;
        all.mn = min(p1.mn,p2.mn);
        if(p1.mn > p2.mn) all.pos = p2.pos;
        else all.pos = p1.pos;

        return all;
    }

    void update(int p, int L, int R, int ind, T valNew){
        if(L == R){
            tree[p] = valNew;
        }
        else{
            int mid = L + ((R-L)>>1);
            if(ind <= mid) update(left(p),L,(mid), ind, valNew);
            else update(right(p),(mid+1),R, ind, valNew);
            
            T p1 = tree[left(p)], p2 = tree[right(p)];
            tree[p] = mrg(p1,p2);
        }
    }
    void DoUpdate(int ind, T valNew){update(1,0,n-1,ind-1,valNew);}
};
////// SEGMENT TREE
typedef long long T;
T segTree[8*N];
T neutro = 0;

T mrg(T d1, T d2){
    return __gcd(d1,d2);
}

void update(int p, int l, int r, T val, int pos){
    if(l == r){
        segTree[p] = val;
        return;
    }
    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;
    if(mid < pos) update(rig,mid+1,r, val, pos);
    else update(lef, l, mid, val, pos);
    segTree[p] = mrg(segTree[lef], segTree[rig]);
    return;
}

T query(int p, int l, int r, int i, int j){
    if(l >= i && j >= r) return segTree[p];
    if(l > j  || r < i) return neutro;

    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;
    T vlef = query(lef, l, mid, i, j);
    T vrig = query(rig, mid+1, r, i, j);
    
    if(dataL == neutro) return dataR;
    if(dataR == neutro) return dataL;

    return mrg(vlef, vrig);
}
// update(1,0,n-1, newV, posV)
// query(1,0,n-1, i, j) 
// i,j, posV indexadas de 0 a n-1
