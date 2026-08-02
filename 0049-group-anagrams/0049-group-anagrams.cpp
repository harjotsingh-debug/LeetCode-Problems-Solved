class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>>mpp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mpp[s].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto [k,v]:mpp){
            vector<string>temp;
            for(auto it:v){
                temp.push_back(strs[it]);
            }
            ans.push_back(temp);
        }
        return ans;
    

    }
};