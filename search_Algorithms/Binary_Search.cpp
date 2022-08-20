//Algorithm or Logic: Binary Search 
//Complexity: O(N log N)

// Best version
ll binarySearch(ll size, ll target){
    ll l=0,r=size-1;
    ll ans=-1;
    while (l<=r)
    {   
        ll mid = l + ((r-l) >> 1);
        if(data[mid] >= target) r=mid-1, ans=mid;
        else l=mid+1;
    }
    return ans; 
}

// basic Version 
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
