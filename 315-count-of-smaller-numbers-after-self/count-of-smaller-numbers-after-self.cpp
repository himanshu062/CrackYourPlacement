struct Item {
    int num;
    int index;
    Item(int num = 0, int index = 0) : num(num), index(index) {}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        vector<Item> items(n);

        for (int i = 0; i < n; ++i)
            items[i] = Item(nums[i], i);

        mergeSort(items, 0, n - 1, ans);
        return ans;
    }

private:
    void mergeSort(vector<Item>& items, int l, int r, vector<int>& ans) {
        if (l >= r)
            return;

        const int m = (l + r) / 2;
        mergeSort(items, l, m, ans);
        mergeSort(items, m + 1, r, ans);
        merge(items, l, m, r, ans);
    }

    void merge(vector<Item>& items, int l, int m, int r, vector<int>& ans) {
        vector<Item> sorted(r - l + 1);
        int k = 0;     
        int i = l;     
        int j = m + 1; 
        int rightCount = 0;
        while (i <= m && j <= r)
            if (items[i].num > items[j].num) {
                ++rightCount;
                sorted[k++] = items[j++];
            } else {
                ans[items[i].index] += rightCount;
                sorted[k++] = items[i++];
            }
        while (i <= m) {
            ans[items[i].index] += rightCount;
            sorted[k++] = items[i++];
        }
        while (j <= r)
            sorted[k++] = items[j++];
        copy(sorted.begin(), sorted.end(), items.begin() + l);
    }
};