/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& temp){
        if(root==NULL) return;
        inorder(root->left,temp);
        temp.push_back(root);
        inorder(root->right,temp);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int sum=0;
        // If the current node's value is within the range, add it to the sum
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // If the current node's value is greater than `low`, explore the left subtree
        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        // If the current node's value is less than `high`, explore the right subtree
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};