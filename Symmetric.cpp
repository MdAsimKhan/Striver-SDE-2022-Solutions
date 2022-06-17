bool isSymmetric(TreeNode* root) {
        return (!root || checker(root->left,root->right));
    }
    bool checker(TreeNode* cl, TreeNode* cr){
        if(!cl || !cr) return cr==cl;
        if(cl->val!=cr->val) return false;
        return (checker(cl->left,cr->right) && checker(cl->right,cr->left));
    }