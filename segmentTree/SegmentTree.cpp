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
T segTree[4*N];
ll data[N];

T mrg(T data1, T data2){
    return data1+data2;
}

void update(T nodeP, int l, int r, T newV, int posV){
    if(l == r){
        segTree[nodeP] = newV; 
        return;
    }
    int mid = l + ((r-l)>>1);
    T nodeL = (nodeP*2), nodeR = (nodeP*2)+1; 
    if(posV > mid) update(nodeR, mid+1, r, newV, posV);
    else update(nodeL, l, mid, newV, posV);
    segTree[nodeP] = mrg(segTree[nodeL],segTree[nodeR]);
    return;
}

T query(T nodeP, int l, int r, int i, int j){
    if(l >= i && r <= j) return segTree[nodeP];
    if(l > j || r < i)  return -oo; // Usar un valor neutro

    int mid = l + ((r-l)>>1);   
    T nodeL = (nodeP*2), nodeR = (nodeP*2)+1; 
    T dataL = query(nodeL, l, mid, i, j), dataR = query(nodeR, mid+1, r, i, j);
    
    if(dataL == -oo) return dataR;
    if(dataR == -oo) return dataL;

    return  mrg(dataL, dataR);
}
// update(1,0,n-1, newV, posV)
// query(1,0,n-1, i, j) 
