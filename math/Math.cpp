//MATH
//combinatorics, permutations and others

//Algorithm or Logic: number of digits for factorial
//Complexity: O(n)

//n = 1 + floor(log10(n) + log10(n-1) + log10(n-2) + ... log10(1))  

//Algorithm or Logic: Given array find the subarray with the largest possible sum
//Complexity: O(n)
ll arr[MAXN];
ll sumTMax(ll n){
    ll best = 0, sum = 0;
    forn(k,n){
        sum = max(arr[k],sum+arr[k]);
        best = max(best,sum);
    }
    return best;
}


//Algorithm or Logic: Number of pairs given n elements
//Complexity: O(1)
//

ll sumN(ll n){
    n--;
    return n*(n+1)/2;
}

//Algorithm or Logic: sum of the digits of the number n
//Complexity: O(?)
//

ll sumS(ll x){
    ll sum = 0;
    while(x){
        sum += (x%10);
        x/=10;
    }
    return sum;
}

//Algorithm or Logic: Reconstruir el numero en base 10
//Complexity: O(n)
//
ll num[MAXN];
ll ok(ll base, ll size){ // num * base^0 + num * base^1 + num * base^2+ ... + num * base^exp 
    ll bx=1,sum=0;
    size-=1;
    sum=num[size]; // binary if(num[size] == 1) sum <<= 1;
    while(size--){
        bx*=base; // bx++;
        sum+=bx*num[size]; // if(num[size] == 1) sum<<=bx 
    }

  return sum;
}

//Algorithm or Logic: Función exponencial
//Complexity: O(n)
ll ok(ll a, ll x){ // a^x
  ll ans=1;
  while(x--){
    ans*=a;
  }
  return ans;
}

//Algorithm or Logic: Función exponencial
//Complexity: O(log n)
typedef long long ll;
ll expfast(ll b, ll e){
    if(e & 0LL) return 1;
    if(e & 1) return (expfast(b*b,e >> 1) * b);
    return expfast(b*b, e >> 1);
}

//Algorithm or Logic: Find sqrt(x) with some precision
//Complexity: O(nlogn)
//

typedef long double ll;

ll ok(ll mid, ll k){ // mid^k
  ll ans=1;
  while(k--){
    ans*=mid;
  }
  return ans;
}

ll bs (ll x, ll err, ll k){
    ll l = 0.0, r = x;
    while(r - l > err){
        ll mid = l + ((r-l)/2);
        if (ok(mid,k) < x) l = mid; 
        else r = mid;
    }
    return l + ((r-l)/2);
}
