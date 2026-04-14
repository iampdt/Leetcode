class Solution {
public:
    string nextGreaterElement(string n) {
        vector<int> arr;
        for(int i=0;i<n.length();i++) arr.push_back(n[i]-'0');

        int j = arr.size() - 2;
        while (j >= 0 && arr[j] >= arr[j + 1]) j--;
        if (j < 0) return "";
        int k = arr.size() - 1;
        while (arr[j] >= arr[k]) k--;
        swap(arr[k], arr[j]);

       sort(arr.begin() + j + 1, arr.end());
        string num="";

        for (int i = 0; i < arr.size(); i++) {
           num += to_string(arr[i]); }

        return num;
    }
    int getMinSwaps(string num, int k) {
      string temp=nextGreaterElement(num);
      for(int i=1;i<k;i++)
      {
          temp = nextGreaterElement(temp);
      }

      int swaps = 0;
      int n = num.length();
       for (int i = n - 1; i >= 0; i--) {
        if (num[i] == temp[i]) continue;

        int j = i;
        while (j >= 0 && num[j] != temp[i]) j--;

        while (j < i) {
            swap(num[j], num[j + 1]);
            swaps++;
            j++;
        }
    }
    return swaps;
        
    }
};