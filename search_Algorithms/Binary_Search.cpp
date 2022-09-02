//Algorithm or Logic: Binary Search 
//Complexity: O(N log N)

// version 1
ll binarySearch(ll size, ll target){
    ll l=0,r=size-1;
    while (l<=r)
    {   
        ll mid = l + ((r-l) >> 1);
        if(dat[mid] == target) return mid;
        if(dat[mid] > target) r=mid-1;
        else l=mid+1;
    }
    return -1; 
}

// ll i=lower_bound(v.begin(), v.end(), value) - v.begin() ; array -> ll i=lower_bound(dat,dat+n,k) - dat  1° numero >=k
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
