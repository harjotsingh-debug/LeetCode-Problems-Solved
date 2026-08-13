class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0;
        int total=0;
        int current=0;
        for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            current+=gas[i]-cost[i];
            if(current<0){
                start=i+1;
                current=0;
            }
        }
        if(total<0) return -1;
        return start;
    }
};