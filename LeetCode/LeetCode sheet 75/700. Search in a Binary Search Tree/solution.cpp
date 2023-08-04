

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // Step 1: Check if the current node is null
        if (root == nullptr)
            return nullptr;

        // Step 2: If the current node's value matches 'val', return the current node
        if (root->val == val)
            return root;

        // Step 3: If the current node's value is greater than 'val', search in the left subtree
        else if (root->val > val)
            return searchBST(root->left, val);

        // Step 4: If the current node's value is less than 'val', search in the right subtree
        else
            return searchBST(root->right, val);
    }
};