//Algorithm or logic: Border
//Complexity: O(n)
int border[5*N];
void bord(int n, string& s){
    int i = 1, j =0;
    border[0] = 0;
    while(i<n){
        while(j>0 && s[i] != s[j]){
            j = border[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        border[i++] = j;
    }
}