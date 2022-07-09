int expandtoBothSidesFrom_i(string s, int b, int e){
        while(b>=0 and e<s.size() and s[b]==s[e]){
            b--;//move left towards start
            e++;//move towards end
        }
        return e-b+1;
    }
    
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        //s and e are start and end of substr
        int st=0,e=0;//current substr of len 0;
        for(int i=0;i<n;i++){
            //for odd length substr
            int l1=expandtoBothSidesFrom_i(s,i,i);
            //for even length substr
            int l2=expandtoBothSidesFrom_i(s,i,i+1);
            int l=max(l1,l2);
            //update s and e
            if(l>e-st){
                st=i-(l-1)/2;
                e=i+l/2;
            }
        }
        return s.substr(st,e+1);
    }