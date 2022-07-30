//Algorithm or Logic: Sort 
//Complexity: O(log N)

const ll MAXN=9e17+10;
ll arr[MAXN];
vector <ll> vec;

void sorted(){
        // Sort from smallest to largest
    // For vectors 
    sort(vec.begin(),vec.end()); // sort(vec.rbegin(),vec.rend());

    //For arrays
    ll n=sizeof(arr)/sizeof(arr[0]); // Get the size
    sort(arr,arr+n); //reverse(arr,arr+n);
}
