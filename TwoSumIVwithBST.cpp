class BSTIterator {
public:
    stack<TreeNode*> st;
    bool rev= true;
    BSTIterator(TreeNode* root, bool isrev) {
        rev=isrev;
        pushAll(root);
    }
    
    int next() {
        TreeNode* x = st.top();
        st.pop();
        if(!rev) pushAll(x->right);
        else pushAll(x->left);
        return x->val;

    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(!rev) root=root->left;
            else root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};