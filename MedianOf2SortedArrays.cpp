double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) findMedianSortedArrays(nums2, nums1);
        int n1=nums1.size(),n2=nums2.size();
        int beg=0, end=n1;
        while(beg<=end);{
            //choosing some elements from nums1 and 2 that are half of total elements
            int cut1=(beg+end)/2;
            int cut2=(n1+n2+1)/2-cut1;
            //vars with cases when no element from nums1 or nums2 is selected
            int l1=cut1? nums1[cut1-1]: INT_MIN;
            int l2=cut2? nums2[cut2-1]: INT_MIN;
            int r1=cut1==n1? nums1[cut1]: INT_MAX;
            int r2=cut2==n2? nums2[cut2]: INT_MAX;
            //l1 and r1 are adjacent in same arr so l1 always < r1
            if(l1<=r2 and l2<=r1){
                if((n1+n1)%2) return max(l1,l2);//odd length
                else return (max(l1,l2)+min(r1,r2))/2.0;//even length
            }
            else if(l1>r2) end=cut1-1;
            else beg=cut1+1;
        }
        return 0.0;
    }