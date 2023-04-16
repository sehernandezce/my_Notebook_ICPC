//Algorithm or Logic: Binary Search 
//Complexity: O(N log N)

// version 1
ll binarySearch(ll size, ll target){
    ll l=0,r=size-1;
    while (l<=r) // (r-l > 1)  // answer may be in r
    {   
        ll mid = l + ((r-l) >> 1);
        if(dat[mid] == target) return mid;
        if(dat[mid] > target) r=mid-1;
        else l=mid+1;
    }
    return -1; 
}

// ll i=lower_bound(v.begin(), v.end(), value) - v.begin() ; array -> ll i=lower_bound(dat,dat+n,k) - dat  
//1° numero >=k
// // Busca el primero que no sea menor a a[i]
ll binarySearch(ll size, ll value){ // N=size; search -> value O(log N)
    ll l=0,r=size-1;
    while (l<=r)
    {   
        ll mid = l + ((r-l) >> 1); //  ((l+r) >> 1) // (n >> k) n/a^k
        if(data[mid]>=value) r=mid-1;
        else l=mid+1;
    }
    return l==size ? -1 : l; // ans is l  
}

///
ll arr[MAXN];
void bs2(ll n, ll x){
    ll k = 0;
    for(ll b = n/2; b>=1; b/=2){
        while(k+b <n && arr[k+b] <=x) k +=b;
    }
    if(arr[k] == x){
        // x found at index K
    }
}

///
lf pote(lf mid, int k){
    lf ans = 1.0;
    while(k--){
        ans*=mid;
    }
    return ans;
}

lf sqrtBinary(lf x, int k){
    lf lo = 0.0, hi = x+1.0, err = 1e-7;
    lf ans = 0.0;
    while(abs(hi - lo) > err){
        lf mid = lo + ((hi - lo)/2.0);
        // cout << precise(mid,8) << " " << precise(hi,8) << " " << precise(lo,8) << endl;
        if(pote(mid,k) >= x){
            hi = mid;
            ans = mid;
        }else{
            lo = mid;
        }
    }
    return ans;
}
