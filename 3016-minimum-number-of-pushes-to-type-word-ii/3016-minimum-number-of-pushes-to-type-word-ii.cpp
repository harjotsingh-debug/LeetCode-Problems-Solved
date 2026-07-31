class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        vector<int>arr(8,0);
        for(auto &it :word){
            mpp[it]++;
        }
        int n=mpp.size();
        vector<int>freq;
        for(auto &it:mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());

        int total=0;
        for(int i=0;i<n;i++){
            int ind=i%8;
            arr[ind]++;
            total+=arr[ind]*freq[i];
        }
        return total;
    }
};