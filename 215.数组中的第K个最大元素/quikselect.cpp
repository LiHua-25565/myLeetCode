class Solution {
    void quickselect(vector<int>& nums, int l, int r, int target) {
        if (r - l <= 16) {
            sort(nums.begin() + l, nums.begin() + r);
            return;
        }

        // 三数取中，防止有序数组退化
        int mid = l + (r - l) / 2;
        int a = nums[l], b = nums[mid], c = nums[r - 1];
        int pivot;
        if ((a <= b && b <= c) || (c <= b && b <= a)) pivot = b;
        else if ((b <= a && a <= c) || (c <= a && a <= b)) pivot = a;
        else pivot = c;

        // 荷兰国旗三路分区
        int lt = l, i = l, gt = r - 1;
        while (i <= gt) {
            if (nums[i] < pivot)      swap(nums[lt++], nums[i++]);
            else if (nums[i] > pivot) swap(nums[i], nums[gt--]);
            else                      ++i;
        }
        // [l, lt)  < pivot
        // [lt, gt] == pivot
        // (gt, r)  > pivot

        if (target < lt)          quickselect(nums, l, lt, target);
        else if (target > gt)     quickselect(nums, gt + 1, r, target);
        // 否则 target 落在 [lt, gt] 内，nums[target] == pivot，已完成
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;                       // 升序第 k 大的下标
        quickselect(nums, 0, n, target);
        return nums[target];
    }
};