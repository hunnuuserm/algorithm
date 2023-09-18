//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//牛客JZ31 栈的压入、弹出序列
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        stack<int> st;
        int p1=0;
        int p2=0;
        st.push(pushV[p1++]);
        while(p2!=popV.size())
        {
            if(st.empty()||(st.top()!=popV[p2]&&p1!=pushV.size()))
            {
                st.push(pushV[p1++]);
            }
            else if(st.top()==popV[p2])
            {
                st.pop();
                p2++;
            }
            else if(st.top()!=popV[p2])
            {
                return false;
            }    
        }
        return true;
     
    }
};