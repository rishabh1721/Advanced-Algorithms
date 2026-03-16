#include<stack>
#include<climits>

using namespace std;

class SpecialStack {
  public:

    stack<long long> st;
    long long mini;

    SpecialStack() {
        mini = LLONG_MAX;
    }

    void push(int x) {

        if(st.empty()){
            mini = x;
            st.push(x);
        }
        else if(x >= mini){
            st.push(x);
        }
        else{
            st.push(2LL * x - mini);
            mini = x;
        }
    }

    void pop() {

        if(st.empty()) return;

        long long n = st.top();
        st.pop();

        if(n < mini){
            mini = 2LL * mini - n;
        }

        if(st.empty()) {
            mini = LLONG_MAX;
        }
    }

    int peek() {

        if(st.empty()) return -1;

        long long n = st.top();

        if(n < mini)
            return mini;
        else
            return n;
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {

        if(st.empty()) return -1;

        return mini;
    }
};