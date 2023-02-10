//Algorithm or Logic: Greatest common divisor (GCD)
//Complexity: O( log(min(a, b))
// CC++ Ya trae el gcd
//Euclidean algorithm:  GCD(a,b) = GCD(b,r) : a= x*b + r  GCD(a,0)=a.

ll gcd1(ll a, ll b) {
    while (b) { // b != 0
        a %= b;  // a=r  mcd(r,b)
        swap(a, b); // mcd(b,r)
    }
    return a;
}

// Recursion
ll gcdr(ll a, ll b) {
    if(b == 0) return a;
    return gcdr(b, a%b);
}

ll gcd_ext(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_ext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}

//Algorithm or Logic: Least common multiple (LCM)
//Complexity: O( log(min(a, b))
//The least common multiple of two numbers is equal to the product of the numbers divided by their greatest common factor.

ll lcm1 (ll a, ll b){
    return ((a*b) / gcd1(a,b));
}
