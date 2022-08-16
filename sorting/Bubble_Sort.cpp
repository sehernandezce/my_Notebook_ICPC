//Algorithm or Logic: Bubble Sort
//Complexity: O(n^2)

ll arr[MAXN];
void bubble_sort(ll n){
    for(ll i=0; i<n; i++){
        for(ll j=0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
