//Algorithm or Logic: Binary Search 
//Complexity: O(log N)

ll binarySearch(ll size, ll value){ // search -> value O(log)
    ll l=0,r=size-1;
    while (l<=r)
    {   
        ll mid = ((l+r) >> 1); //(n >> k) n/a^k
        if(data[mid]>=value) r=mid-1;
        else l=mid+1;
    }
    return l==size ? -1 : l; // ans is l  
}
