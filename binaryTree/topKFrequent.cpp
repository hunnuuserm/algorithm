//https://leetcode.cn/problems/top-k-frequent-words/
//leetcode692.前K个高频单词

/*说明:sort底层是快排，是不稳定排序，所以要用自己写的仿函数；
       stable_sort底层一般是归并排序，是稳定排序。*/

//方法一:
class Solution {
public:
    struct Compare
    {
        //public:
        template<class T>
        bool operator()(const T& x,const T& y)
        {
            return x.second>y.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m1;
        for(auto&e:words)
        {
            m1[e]++;
        }
        vector<pair<string,int>> v(m1.begin(),m1.end());
        stable_sort(v.begin(),v.end(),Compare());
        vector<string> ret;
        int i=0;
        while(k--)
        {
            ret.push_back(v[i++].first);
        }
        return ret;
    }
};


//方法二:
class Solution {
public:
   struct Compare
    {
        //public:
        template<class T>
        bool operator()(const T& x,const T& y)
        {
            return (x.second>y.second)||(x.second==y.second&&x.first<y.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m1;
        for(auto&e:words)
        {
            m1[e]++;
        }
        vector<pair<string,int>> v(m1.begin(),m1.end());
        sort(v.begin(),v.end(),Compare());
        vector<string> ret;
        int i=0;
        while(k--)
        {
            ret.push_back(v[i++].first);
        }
        return ret;
    }
};


//方法三:
class Solution {
public:
    struct Compare
    {
        //public:
        template<class T>
        bool operator()(const T& x,const T& y) const
        {
            return (x.second>y.second)||(x.second==y.second&&x.first<y.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m1;
        for(auto& e:words)
        {
            m1[e]++;
        }
        multiset<pair<string,int>,Compare> s(m1.begin(),m1.end());
        vector<string> ret;
        multiset<pair<string,int>,Compare>::iterator it =s.begin();
        while(k--)
        {
            ret.push_back((*it).first);
            it++;
        }
        return ret;
    }
};