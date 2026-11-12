class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            int curr = asteroids[i];
            bool alive = true;

            while(!st.empty() && curr < 0 && st.top() > 0) {

                if(st.top() < abs(curr)) {
                    st.pop();
                }
                else if(st.top() == abs(curr)) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if(alive) st.push(curr);
        }

        vector<int> arr;

        while(!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }

        reverse(arr.begin(), arr.end());

        return arr;
    }
};