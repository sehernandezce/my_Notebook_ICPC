//Algorithm or Logic: Longest Increasing Subsequence
//Complexity: O(nlogn)
//The answer is correct. But it doesn't build the sequence correctly.
int lis (vector<int>& list){
    vector<int> subsequence;
    for(auto& ele: list){
        int pos = (int)(lower_bound(subsequence.begin(), subsequence.end(), ele) - subsequence.begin());
        if(pos == (int)subsequence.size()) subsequence.push_back(ele);
        else subsequence[pos] = ele;
    }
    //for(auto& ele: subsequence){cout << ele << " ";} cout << endl;
    return (int)subsequence.size();
}
