class Solution {
public:
    //recursion simulation using stack
    int calculate(string s) {
        stack<int> st;
        int result = 0, num = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop(); // sign before '('
                result += st.top(); st.pop(); // result before '('
            }
        }

        result += sign * num;
        return result;
    }
};
