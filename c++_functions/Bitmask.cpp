// Algorithm or Logic: Bit manipulation/Bitmask/Bitmasking
// Complexity: O(n) 

#define var n << b
void bitmask(){
    ll n,b;
    n << b; // n <<= b; n / 2^b
    n >> b; // n >>= b; n * 2^b   
}

// Note
// It is useful for when we have several representations but they can only be given the status of is or is not.
// Allows for better space management.

// More info: https://www.youtube.com/watch?v=h6O6qVw0e5M&ab_channel=makigas%3Atutorialesdeprogramaci%C3%B3n
// https://youtu.be/oL5bmRUbAJ4
// mod(%) O(n^3)
// Div(/) Mult(*) O(n^2)  
// bitwise O(n) 
// Operator and(&) or(|) xor(^) not op(!)
// left shift(<<) right shift op(>>)
    // equivalent
//or(|) -> sum(+) , Union(U)
//and(&) -> intersection(), product(*), extracting bits
//__builtin_popcount(x) // count 1
// More info: https://es.wikipedia.org/wiki/L%C3%B3gica_binaria
// https://es.wikipedia.org/wiki/Operador_a_nivel_de_bits
