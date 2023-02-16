//Algorithm or Logic: Ternary Search 
//Complexity: O(N log N)

dd SearchTer(dd f[], double l, double r, dd err){
    bool b=true;
    while(abs(r-l) > err) //
    {   
        double m1 =  l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if(f[m1] >= f[m2]){ // max >> f[m1] < f[m2]
            l = m1;
        }else{
            r = m2;
        }
    }
    return f(l); //l + ((r-l) / 2);
}
//Note
//Buscar el máximo de la función unimodal f() dentro de [l,r]
//Para encontrar el minimo, invierta la instrucción if / else o invierta la comparación
// Sirve para hallar el mínimo de una función que es concava

