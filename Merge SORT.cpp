    void mergeSort(int ss, int se, vector<int>& nums) {
        if(ss>=se) return; 
        int mid = (ss+se) >> 1;
        mergeSort(ss, mid, nums);
        mergeSort(mid+1, se, nums);
        int l=ss, r=mid+1;
        vector<int> sorted;
        
        while(l<=mid || r<=se) {
            if(l>mid) sorted.push_back(nums[r++]);
            else if(r>se || nums[l]<nums[r]) sorted.push_back(nums[l++]);
            else sorted.push_back(nums[r++]);
        }
        for(int i=ss; i<=se; i++) 
            nums[i]=sorted[i-ss];
    }

    ll inv_count(int arr[], int start, int end) {
        if(start>=end) return 0;
        int mid = (start+end)>>1;
        ll left_cnt = inv_count(arr, start, mid);
        ll right_cnt = inv_count(arr, mid+1, end);
        int leftIdx=start, rightIdx=mid+1;
        ll cur_cnt = 0;
        vector<int> sorted;
        
        while(leftIdx<=mid || rightIdx<=end) {
            if(leftIdx>mid) {
                sorted.push_back(arr[rightIdx++]);
            }
            else if(rightIdx>end || arr[leftIdx] <= arr[rightIdx]) {
                sorted.push_back(arr[leftIdx++]);
            }
            else {
                cur_cnt += mid-leftIdx+1;
                sorted.push_back(arr[rightIdx++]);
            }
        }
        for(int i=start; i<=end; i++) {
            arr[i] = sorted[i-start];
        }
        return left_cnt+cur_cnt+right_cnt;
    }
