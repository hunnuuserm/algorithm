//https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
//leetcode438.找到字符串中所有字母异位词

//本题注意两个点：
//1.判断条件可能不太好想，多想想。
//2.这里只用了一个hash数组，比特课件上用了两个hash数组，
//  一个hash数组和两个hash数组的判断条件肯定不同，但两种方法本质一样。
//3.这里用一个hash数组时，更新结果后要出窗口，稍微注意。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hash[128]={0};
        for(auto&e: p)
        {
            hash[e]++;
        }
        int ns=s.size(),np=p.size(),left=0,right=0,count=0;
        while(right<ns)
        {
            hash[s[right]]--;//进窗口
            count++;//进窗口
            while(hash[s[right]]<0)//判断
            {
                hash[s[left++]]++;//出窗口
                count--;
            }
            if(count==np)
            {
                ret.push_back(left);//更新结果
                hash[s[left++]]++;//出窗口
                count--;
            }
            right++;
        }
        return ret;
    }
};