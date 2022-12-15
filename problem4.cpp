
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

class Solution {
public:
    bool is_mirror(TreeNode *root1, TreeNode* root2) {
        if(root1 == NULL && root2==NULL)
            return 1;
        if(root1 == NULL || root2==NULL)
            return 0;
        return (root1->val == root2->val) && is_mirror(root1->left,root2->right)
        && is_mirror(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root,root);
    }
};

int main()
{

    TreeNode *root1 = new TreeNode(1);

    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    Solution s1;
    if (s1.isSymmetric(root1)) cout << "Symmetric"<<endl;
    else cout << "Not symmetric"<<endl;


    TreeNode *root2 = new TreeNode(5);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(3);

    Solution s2;
    if (s2.isSymmetric(root2)) cout << "Symmetric"<<endl;
    else cout << "Not symmetric"<<endl;


    return 0;
}

