//MATH
//combinatorics, permutations and others

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

ll sumS(ll x)
{
    ll sum = 0;
    while(x){
        sum += (x%10);
        x/=10;
    }

    return sum;
}
