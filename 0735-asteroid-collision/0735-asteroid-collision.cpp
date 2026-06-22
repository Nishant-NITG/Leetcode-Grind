class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int curr : asteroids) {

            bool alive = true;

            while(alive &&
                  !st.empty() &&
                  st.top() > 0 &&
                  curr < 0) {

                if(abs(st.top()) < abs(curr)) {

                    st.pop();
                }

                else if(abs(st.top()) == abs(curr)) {

                    st.pop();
                    alive = false;
                }

                else {

                    alive = false;
                }
            }

            if(alive)
                st.push(curr);
        }

        vector<int> ans(st.size());

        for(int i = st.size()-1; i >= 0; i--) {

            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};