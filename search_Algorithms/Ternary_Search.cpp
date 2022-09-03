//Algorithm or Logic: Ternary Search 
//Complexity: O(N log N)

dd SearchTer(dd f[], ll l, ll r, dd err){
    bool b=true;
    while(abs(r-l) >= err)
    {   
        ll m1 = (2*l + r) / 3;
        ll m2 = (l + 2 * r) / 3;

        if(f[m1] >= f[m2]){ // max f[m1] < f[m2]
            l = m1;
        }else{
            r = m2;
        }
    }
    return l + ((r-l) / 2);
}
//Note
//Buscar el máximo de la función unimodal f() dentro de [l,r]
//Para encontrar el minimo, invierta la instrucción if / else o invierta la comparación
// Sirve para hallar el mínimo de una función que es concava

