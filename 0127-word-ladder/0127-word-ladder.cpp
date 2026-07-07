class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(!st.count(endWord)){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.first==endWord) return it.second;

            for(int i=0;i<it.first.size();i++){
                char original=it.first[i];
                for(int ch='a';ch<='z';ch++){
                    it.first[i]=ch;
                    if(st.count(it.first)){
                        q.push({it.first,it.second+1});
                        st.erase(it.first);
                    }
                }
                   it.first[i]=original;
            }
         
        }
        return 0;
    }
};