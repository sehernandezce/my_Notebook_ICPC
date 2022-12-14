//Algorithm or Logic: Lazy Segment Tree
//Complexity: update/query : O(log n) space: O(4*n)
// 1 to n (segmentTree) // array of value (0 to n-1) // query/udpate are 1 to n
// Update Range / Query Range
vector<ll> tree(4*MAXN), lazy(4*MAXN);
struct segTreeLazy{
    int left(int p) {return p << 1;}
    int right(int p) {return (p << 1) + 1;}

    void update(int p, int L, int R, int i, int j, ll v){
        if(i>R || j<L) return;
        if(L == i && R == j){
            tree[p] = v;
            lazy[p] = v; // Can be Change!
            
        }else{
            mrgPush(p);
            int mid = L + ((R-L) >> 1);
            update(left(p),L,mid,i,min(mid,j),v);
            update(right(p),mid+1,R,max(i,mid+1),j,v);
            ll p1 = tree[left(p)], p2 = tree[right(p)];
            tree[p] = mrg(p1,p2);
        }
    }
    
    ll query(int p, int L, int R, int i, int j){
        if(i > R || j < L) return -oo; // Can be Change!
        if(L >= i && R<= j) return tree[p];
        
        mrgPush(p);
        int mid = L + ((R-L) >> 1);
        ll p1 = query(left(p),L,mid,i,min(j,mid)); // if(p1 > -oo) return p2; // Can be Change!
        ll p2 = query(right(p),mid+1,R,max(i,mid+1),j); // if(p2 > -oo) return p1; // Can be Change!
        return mrg(p1,p2); 
    }

    void mrgPush(int p){ // Can be Change!
        if(lazy[p] != -1){
            tree[left(p)] = lazy[p];
            tree[right(p)] = lazy[p];
            lazy[left(p)] = lazy[p];
            lazy[right(p)] = lazy[p];
            lazy[p] = -1;
        }
    }

    ll mrg(ll p1, ll p2){ // Can be Change!
        return max(p1,p2);
    }
};
//segTreeLazy stl; stl.update(1,0,n-1,i,i,ax); // Create 
//stl.query(1,0,n-1,0,a-1); // Query
//