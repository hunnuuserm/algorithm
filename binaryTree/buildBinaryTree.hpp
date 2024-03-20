//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//二叉树的遍历与创建

#include <iostream>
using namespace std;

struct node
{
    node(){}
    node(int val)
    :_val(val),
    _left(nullptr),
    _right(nullptr)
    {

    }
    char _val;
    node* _left;
    node* _right;
};

node*buildTree(string& s,int& index)
{
    node* head = new node(s[index++]);
    if(head->_val == '#') 
    {
        return head;
    }

    head->_left = buildTree(s,index);
    head->_right = buildTree(s,index);
    return head;
}

void inOrder(node* head)
{
    if(head == nullptr) return;
    inOrder(head->_left);
    if(head->_val!= '#')
    {
        cout<<head->_val<<" ";
    }
    inOrder(head->_right);
}


int main() {
    string s;
    while(getline(cin,s))
    {
        int index = 0;
        node* head = buildTree(s,index);
        inOrder(head);
    }
}
// 64 位输出请用 printf("%lld")