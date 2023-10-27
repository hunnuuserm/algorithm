//https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
//leetcode30.串联所有单词的子串

/*解题思路:
1.把vector<string>& words中的每一个元素看做一个单词，题目就变成了从s中找words的
由所有单词构成的异位词的子串，就可以像'leetcode438.找到字符串中所有字母异位词'那样做了；
2.但由于这里的每一个元素不是字母，而是words[i]，即每一个元素都是字符串，所以本题不能像leetcode438那样用hash数组映射，
本题要用unordered_map(普通的容器map也行，但这里没必要用map，用unordered_map即可)来建立映射关系；
3.串联子串的第一个单词不一定是从s[0]开始的,也有可能是从s[1]开始的，也有可能是从s[2]开始的......，也有可能是从s[words[0].size()-1]开始的，
所以这里的滑动窗口要执行words[0].size()次，最外面的 while(loopi<loop)循环就是这个原因；
4.因为每一个元素的大小是words[0].size()，所以这里的left和right移动的步长是words[0].size()。*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string,int> m;
        int len=words[0].size(),kind=words.size(),n=s.size();
        int left=0,right=0,count=0;
        int loop=len,loopi=0;
        while(loopi<loop)//滑动窗口要执行words[0].size()次
        {
            left=right=0+loopi;
            count=0;
            for(auto&e:words)  m[e]=0;
            for(auto&e:words)  m[e]++;
            while(right<n)
            {
                m[s.substr(right,len)]--;//进窗口
                count++;//维护count，维护个数（进窗口和出窗口的时候都要维护count）
                while(m[s.substr(right,len)]<0)//判断
                {
                    m[s.substr(left,len)]++;
                    left+=len;//出窗口
                    count--;
                }
                if(count==kind)
                {
                    ret.push_back(left);//更新结果
                    /*从这开始，往下三行的出窗口写不写都可以，即使在这里不写，后面进行right++之后，
                    一定也会进行出窗口操作，所以这里下面三行的出窗口写了也能通过，不写也能通过*/
                    // m[s.substr(left,len)]++;  
                    // left+=len;//出窗口
                    // count--;//维护count，维护个数
                }
                right+=len;
            }
            loopi++;
        }
        return ret;
    }
};