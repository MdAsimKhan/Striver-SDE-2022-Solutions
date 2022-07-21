int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int sz=q.size();
            int f=0,l=0;
            long min_ind=q.front().second;//int val in q
            for(int i=0;i<sz;i++){
                long cur_ind=q.front().second - min_ind;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) f=cur_ind;
                if(i==sz-1) l=cur_ind;
                if(node->left) q.push({node->left, 2*cur_ind+1});
                if(node->right) q.push({node->right, 2*cur_ind+2});
            }
            ans=max(ans,l-f+1);
        }
        return ans;
    }