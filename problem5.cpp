

#include <iostream>
#include  <Queue>
using namespace std;
template<class T>
//making tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

template <class T>
class Solution {
public:
    bool isSameTree(TreeNode <T>* p, TreeNode <T>* q) {


    // p and q are both null
    if (p == NULL && q == NULL) return true;
    // one of p and q is null
    if (q == NULL || p == NULL) return false;
        return ((p->val == p->val)&&(isSameTree(p->right, q->right) &&
           isSameTree(p->left, q->left)));

    }
};


int main() {

    TreeNode<int> * root_p = new TreeNode <int>();
    TreeNode<int> * root_q = new TreeNode <int>();

    ///bulding trees to test
    cout<<"Test case1:"<<endl;
    ////////////////////////////////////////
    root_p->val=1;
    root_p->left = new TreeNode<int>(2);
    root_p->right = new TreeNode<int>(3);

    ///////////////
    root_q->val=1;
    root_q->left = new TreeNode<int>(2);
    root_q->right = new TreeNode<int>(3);
///////////////////

Solution<int> s ;
if(s.isSameTree(root_p,root_q))
{
    cout<<"They are the same tree"<<endl;
}
else
{
    cout<<"They are not the same tree"<<endl;

}
////////////////////////
    TreeNode<int> * root2_p = new TreeNode <int>();
    TreeNode<int> * root2_q = new TreeNode <int>();

///////////////////
    cout<<"Test case2:"<<endl;
    ////////////////////////////////////////
    root2_p->val=1;
    root2_p->left = new TreeNode<int>(2);

    ///////////////
    root2_q->val=1;
    root2_q->right = new TreeNode<int>(2);
///////////////////

    if(s.isSameTree(root2_p,root2_q))
    {
        cout<<"They are the same tree"<<endl;
    }
    else
    {
        cout<<"They are not the same tree"<<endl;

    }
////////////////////////
    TreeNode<int> * root3_p = new TreeNode <int>();
    TreeNode<int> * root3_q = new TreeNode <int>();

///////////////////
    cout<<"Test case3:"<<endl;
    ////////////////////////////////////////
    root3_p->val=1;
    root3_p->left = new TreeNode<int>(2);
    root3_p->right = new TreeNode<int>(1);


    ///////////////
    root3_q->val=1;
    root3_p->left = new TreeNode<int>(1);
    root3_q->right = new TreeNode<int>(2);
///////////////////

    if(s.isSameTree(root3_p,root3_q))
    {
        cout<<"They are the same tree"<<endl;
    }
    else
    {
        cout<<"They are not the same tree"<<endl;

    }


    return 0;
}
