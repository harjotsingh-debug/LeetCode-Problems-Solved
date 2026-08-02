class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=-1e9;
        while(l<r){
            int mini=0;
            int nr=0,nl=0;
            if(height[l]<height[r]){
                mini=height[l];
                nr=r;
                nl=l;
                l++;
            }
            else{
                mini=height[r];
                 nr=r;
                nl=l;
                r--;
            }
            int wid=r-l+1;
            ans=max(ans,mini*wid);
        }
        return ans;
    }
};