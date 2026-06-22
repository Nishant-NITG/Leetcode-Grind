class MinStack {

    stack<pair<int,int>> st;

public:

    MinStack() {

    }

    void push(int val) {

        if(st.empty()) {
            st.push({val,val});
        }
        else {
            int currMin = min(val, st.top().second);
            st.push({val,currMin});
        }
    }

    void pop() {

        st.pop();
    }

    int top() {

        return st.top().first;
    }

    int getMin() {

        return st.top().second;
    }
};