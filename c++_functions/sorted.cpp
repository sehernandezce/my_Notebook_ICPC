//Algorithm or Logic: Sort 
//Complexity: O(Nlog N)

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


// Note
/*

bool comp(string a, string b) {
if (a.size() == b.size()) return a < b;
else return a.size() < b.size();
}
Now a vector of strings can be sorted as follows:
sort(v.begin(), v.end(), comp);
*/
