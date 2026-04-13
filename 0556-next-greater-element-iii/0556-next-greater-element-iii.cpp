class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> arr;
        while (n > 0) {
            int rem = n % 10;
            arr.push_back(rem);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());

        int j = arr.size() - 2;
        while (j >= 0 && arr[j] >= arr[j + 1]) j--;
        if (j < 0) return -1;
        int k = arr.size() - 1;
        while (arr[j] >= arr[k]) k--;
        swap(arr[k], arr[j]);

       reverse(arr.begin() + j + 1, arr.end());
        long long num = 0;

        for (int i = 0; i < arr.size(); i++) {
            num = num * 10 + arr[i];
        }
        return num > INT_MAX ? -1 : int(num);
    }
};