class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return findMedianSortedArrays(b, a);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while(low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = (mid1 - 1 >= 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? b[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1) {
                if(n % 2 == 1) return max(l1, l2);
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
};
