//https://leetcode.cn/problems/evaluate-reverse-polish-notation/
//leetcode150.逆波兰表达式求值

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int left=0;
        int right=0;
        for(auto&e:tokens)
        {
            if(e=="+"||e=="-"||e=="*"||e=="/")
            {
                right=st.top();
                st.pop();
                left=st.top();
                st.pop();
                switch(e[0])
                {
                case '+':
                    st.push(left+right);
                    break;
                case '-':
                    st.push(left-right);
                    break;
                case '*':
                    st.push(left*right);
                    break;
                case '/':
                    st.push(left/right);
                    break;
                }
            }
            else
            {
                st.push(stoi(e));
            }
        }
        return st.top();
    }
};