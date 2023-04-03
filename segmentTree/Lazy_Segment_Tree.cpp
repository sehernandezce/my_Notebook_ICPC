// Lazy Segment Tree
// Update range and Query range
typedef long long T;
T segTreeLazy[8*N];
T lazy[8*N];
T neutro = 0;

T mrg(T d1, T d2){ // Can be Change!
    return d1+d2;
}

void mrgPush(int p, int l, int r){ // Can be Change!
    int mid = l + ((r-l)>> 1);
    int lef = (p<<1), rig = (p<<1)+1;
    segTreeLazy[lef] += (lazy[p]*(mid-l+1));
    segTreeLazy[rig] += (lazy[p]*(r-(mid+1)+1));
    lazy[lef] += lazy[p];
    lazy[rig] += lazy[p];
    lazy[p] = neutro;
}

void update(int p, int l, int r, int i, int j, T newVal){
    if(l > j  || r < i) return;
    
    if(l == i && r == j){
        // Can be change!
        segTreeLazy[p] += (newVal*(r-l+1));
        lazy[p] += newVal; 
    }
    else{
        mrgPush(p,l,r);
        int mid = l + ((r-l)>>1);
        int lef = (p << 1), rig = (p<<1) + 1;
        
        update(lef, l, mid, i, min(j,mid), newVal);       
        update(rig, mid+1, r, max(i, mid+1), j, newVal);

        T vlef = segTreeLazy[lef];
        T vrig = segTreeLazy[rig];
        segTreeLazy[p] = mrg(vlef, vrig);
    }
}

T query(int p, int l, int r, int i, int j){

    if(l >= i && j >= r) return segTreeLazy[p];
    if(l > j  || r < i) return neutro;

    mrgPush(p,l,r);
    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;

    T vlef = query(lef, l, mid, i, min(j,mid)); // query(lef, l, mid, i, j);
    T vrig = query(rig, mid+1, r, max(i,mid+1),j); //query(rig, mid+1, r, i, j);
    
    if(vlef == neutro) return vrig;
    if(vrig == neutro) return vlef;

    return mrg(vlef, vrig);
}

void print(int p, int l, int r, int i, int j){
    
    if(l > j  || r < i) return;
    int mid = l + ((r-l)>>1);
    int lef = (p << 1), rig = (p<<1) + 1;
    cout << "l: " << l << " r: " << r << " seg: " << segTreeLazy[p] << " lazy:  " << lazy[p] << endl;
    
    if(l == r) return;
    print(lef, l, mid, i, min(j,mid));
    print(rig, mid+1, r, max(i,mid+1), j);
} 
//print(1, 0, n-1, 0, n-1);
/*
Indexado i y j de 0 a n-1
update(1,0, n-1, i, j, x); Incrementar en x los valores del rango i,j
query(1,0, n-1, i, j); // Query en rangos i, j
*/