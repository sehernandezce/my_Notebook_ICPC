//Algorithm or Logic: Lazy Segment Tree (increase each value in range [a,b] by u, what is the value at position k?)
//Complexity: update/query : O(log n) space: O(4*n)
// 1 to n (segmentTree) // array of value (0 to n-1) // query/udpate are 1 to n
// Update Range / Query k-position
vector<ll> tree(4*MAXN), lazy(4*MAXN);
struct segTreeLazy{
    int left(int p) {return p << 1;}
    int right(int p) {return (p << 1) + 1;}
 
    void update(int p, int L, int R, int i, int j, ll v){
        if(i>R || j<L) return;
        if(L == i && R == j){
            tree[p] += v;
            lazy[p] += v; // Can be Change!
        }else{
            mrgPush(p);
            int mid = L + ((R-L) >> 1);
            update(left(p),L,mid,i,min(mid,j),v);
            update(right(p),mid+1,R,max(i,mid+1),j,v);
            // Can be Change! merge
        }
    }
    
    ll query(int p, int L, int R, int k){
        if(L == R) return tree[p];
        mrgPush(p);
        int mid = L + ((R-L) >> 1);
        if(k <= mid) return query(left(p),L,mid,k);
        else return query(right(p),mid+1,R,k);
    }
 
    void mrgPush(int p){ // Can be Change!
        tree[left(p)]+=lazy[p];
        tree[right(p)]+=lazy[p];
        lazy[left(p)]+=lazy[p];
        lazy[right(p)]+=lazy[p];
        lazy[p] = 0;
    }
};
//segTreeLazy stl; stl.update(1,0,n-1,i,i,ax); // Create 
//stl.query(1,0,n-1,k-1) // Query
//