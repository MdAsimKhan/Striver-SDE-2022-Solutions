class Node{
    public:
        int sm, lg, sz, sum;
        Node(int sm, int lg, int sz, int sum){
            this->sm=sm;
            this->lg=lg;
            this->sz=sz;
            this->sum=sum;
        }
};

class Solution {
public:
    Node solver(TreeNode* root){
        if(!root) return Node(INT_MIN,INT_MAX,0,0);
        auto lt=solver(root->left);
        auto rt=solver(root->right);
        //condition for BST
        if(lt.lg < root->val < rt.sm){
            int Sum=rt.sum+lt.sum;
            return Node(min(lt.sm, root->val), max(rt.lg, root->val), lt.sz+rt.sz+1, Sum);
        }
        //condition fails
        return Node(INT_MIN, INT_MAX, max(lt.sz,rt.sz), 0);
    }
    
    int maxSumBST(TreeNode* root) {
        return solver(root).sum;
    }
};