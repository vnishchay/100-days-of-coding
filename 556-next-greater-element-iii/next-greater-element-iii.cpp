class Solution {
public:
    vector<int> next_permutation(vector<int>& arr) {
        int n = arr.size();
        int k = n - 2;
        // 1. Find the pivot
        while (k >= 0 && arr[k] >= arr[k + 1]) k--;
        if (k < 0) {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        // 2. Find smallest greater than pivot in suffix
        int l = n - 1;
        while (arr[l] <= arr[k]) l--;
        swap(arr[k], arr[l]);
        // 3. Reverse suffix
        reverse(arr.begin() + k + 1, arr.end());
        return arr;
    }
    int nextGreaterElement(int n) {
        vector<int> vv;
        int temp = n;
        while (temp > 0) {
            vv.push_back(temp % 10);
            temp /= 10;
        }
        reverse(vv.begin(), vv.end());
        vector<int> nn = next_permutation(vv);
        long long y = 0;
        for (int a : nn) y = y*10 + a;
        return (y > n && y <= INT_MAX) ? y : -1;
    }
};
