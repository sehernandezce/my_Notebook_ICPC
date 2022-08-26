//Algorithm or Logic: Linear Search 
//Complexity: O(N)
//example
vector <ll> vec;
ll linearSearch(ll kelem, ll nmax){
    ll sum=0,cont=0;
    while ( cont < kelem && sum + nmax - vec[cont] < nmax ){
            sum += nmax - vec[cont];
            cont++;
    }

    return cont;
}

// Note: sort(vec.rbegin(),vec.rend());