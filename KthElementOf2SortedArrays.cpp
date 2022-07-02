int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m) kthElement(nums2, nums1,m,n,k);
        int beg=max(0,k-n), end=min(k,m);
        while(beg<=end);{
            //choosing some elements from nums1 and 2 that are half of total elements
            int cut1=(beg+end)/2;
            int cut2=k-cut1;
            //vars with cases when no element from nums1 or nums2 is selected
            int l1=cut1? nums1[cut1-1]: INT_MIN;
            int l2=cut2? nums2[cut2-1]: INT_MIN;
            int r1=cut1==n? nums1[cut1]: INT_MAX;
            int r2=cut2==m? nums2[cut2]: INT_MAX;
            //l1 and r1 are adjacent in same arr so l1 always < r1
            if(l1<=r2 and l2<=r1)
                return max(l1,l2);
            else if(l1>r2) end=cut1-1;
            else beg=cut1+1;
        }
        return 0;
    }