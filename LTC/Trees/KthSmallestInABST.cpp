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

    void FindAndReturnKthSmallestElement( TreeNode* root, int k, int &count, int &retVal )
    {
        if( !root )
        {
            return;    
        }
        
        FindAndReturnKthSmallestElement( root->left, k, count, retVal );
        
        if( retVal != INT_MIN )
        {
            return;
        }
        
        if( ++count == k )
        {
            retVal = root->val;
            return;
        }
        
        FindAndReturnKthSmallestElement( root->right, k, count, retVal );
    }

    int kthSmallest(TreeNode* root, int k)
    {
        int retVal = INT_MIN;
        int count  = 0;
        
        FindAndReturnKthSmallestElement( root, k, count, retVal );
        
        return retVal;
    }
};
