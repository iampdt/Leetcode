class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res;
        int n = digits.size();
        int carry = 0;
        int sum = digits[n-1] + 1;
        carry = sum/10;
        for(int i=n-2;i>=0;i--)
        {
             res.push_back(sum%10);
             sum = digits[i] + carry;
             carry = sum / 10;
        }
        while(sum > 0)
        {
            res.push_back(sum%10);
            sum = sum/10;
        }
        cout<<sum<<endl;
        reverse(res.begin(),res.end());
        return res;
    }
};