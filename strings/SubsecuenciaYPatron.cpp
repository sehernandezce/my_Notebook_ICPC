/*
Dado un string de tamaño 2*10**5, y un patron. Encontrar la cantidad de veces que sale ese patron como subsecuencia
https://www.techiedelight.com/es/count-number-times-pattern-appears-given-string-subsequence/

*/
#include <iostream>
using namespace std;
 
// Función para contar el número de veces patrón `Y[0…n)`
// aparece en una string dada `X[0…m)` como una subsecuencia
int count(string X, string Y)
{
    int m = X.size();
    int n = Y.size();
 
    // `T[i][j]` almacena el número de veces el patrón `Y[0…j)`
    // aparece en una string dada `X[0…i)` como una subsecuencia
    int T[m + 1][n + 1];
 
    // si el patrón `Y` está vacío, hemos encontrado una subsecuencia
    for (int i = 0; i <= m; i++) {
        T[i][0] = 1;
    }
 
    // si la string de entrada `X` está vacía
    for (int j = 1; j <= n; j++) {
        T[0][j] = 0;
    }
 
    /*
      Si el carácter actual de la string y el patrón coinciden,
        1. Excluir el carácter actual tanto de la string como del patrón
        2. Excluya solo el carácter actual de la string
 
      De lo contrario, si el carácter actual de la string y el patrón no coinciden,
      excluir el carácter actual de la string
    */
 
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) {
            T[i][j] = ((X[i - 1] == Y[j - 1]) ? T[i - 1][j - 1] : 0) + T[i - 1][j];
        }
    }
 
    // devuelve la última entrada en la tabla de búsqueda
    return T[m][n];
}