class Solution {
public:
int maxi=-1e9;
int n=0;
    bool ispossible(vector<int>& piles,int h,int m){
            long long count=0;
            for(int i=0;i<n;i++){
                if(h>=piles[i]) count++;
                if(piles[i]>h) count+=(piles[i]+h-1)/h;
            }
            return count<=m;
    }   
    int minEatingSpeed(vector<int>& piles, int h) {        
        n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int l=1,r=maxi;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(ispossible(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};