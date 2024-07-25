class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {   
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    private:
        void mergeSort(vector<int> &arr, int left, int right) {
            if(left >= right) {
                return;
            }

            const int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }

        void merge(vector<int>& arr, int left, int mid, int right) {
            vector<int> sorted(right - left + 1);
            int k = 0; //sorted index;
            int i = left; //left index
            int j = mid + 1;//right index

            while(i <= mid && j <= right) {
                if(arr[i] < arr[j]) {
                    sorted[k++] = arr[i++];
                }
                else {
                    sorted[k++] = arr[j++];
                }
            }

            //put the possible remaining left part into the sorted array.
            while(i <= mid) {
                sorted[k++] = arr[i++];
            }

            //put the possible remaining right part into the sorted array.
            while(j <= right) {
                sorted[k++] = arr[j++];
            }

            copy(sorted.begin(), sorted.end(), arr.begin() + left);
        }
};