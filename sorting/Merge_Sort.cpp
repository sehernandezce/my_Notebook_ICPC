// Algorithm: Merge Sort
// Complexity: NlogN

vector<ll> lef(N,0), rig(N,0);
void mrg(vector<ll>& vec, int l, int mid, int r){    
    int indL = 0, indR = 0, indVec = l, lenL = mid - l + 1, lenR = r - mid;
    
    for(int i = 0; i < lenL; i++) lef[i] = vec[l+i];
    for(int i = 0; i < lenR; i++) rig[i] = vec[mid+i+1];

    while(indL < lenL && indR < lenR){
        if(lef[indL] <= rig[indR]){
            vec[indVec] = lef[indL];
            indL++;
        }
        else{
            vec[indVec] = rig[indR];
            indR++;
        }
        indVec++;
    }

    while(indL < lenL){
        vec[indVec] = lef[indL];
        indL++;
        indVec++;
    }

    while(indR < lenR){
        vec[indVec] = rig[indR];
        indR++;
        indVec++;
    }
}

void myMergeSort(vector<ll>& vec, int l, int r){
    if(l >= r) return; 
    int mid = l + ((r-l)>>1);
    myMergeSort(vec, l, mid);
    myMergeSort(vec, mid+1, r);
    mrg(vec, l, mid, r);
}
