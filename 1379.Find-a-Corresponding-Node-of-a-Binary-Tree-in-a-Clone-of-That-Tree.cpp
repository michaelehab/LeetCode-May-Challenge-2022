/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned) return NULL;
        if(cloned->val == target->val) return cloned;
        TreeNode * l = getTargetCopy(original, cloned->left, target);
        if(l) return l;
        TreeNode * r = getTargetCopy(original, cloned->right, target);
        return r;
    }
};