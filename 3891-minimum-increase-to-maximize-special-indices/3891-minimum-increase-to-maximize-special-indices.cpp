class Solution {
public:
    long long minIncrease(vector<int>& nums) {

        int n = nums.size();
        if(n<3) return 0;
        long long operations =0;
        if(n & 1)
        {
            for(int i=1;i<n;i+=2)
                {
                    int curr = nums[i];
                    int prev = nums[i-1];
                    int next = nums[i+1];

                    if(curr > prev && curr > next) continue;
                    else if(curr > prev && curr <= next) operations+= abs(nums[i]-nums[i+1]) + 1;
                    else if(curr <= prev && curr > next) operations+= abs(nums[i]-nums[i-1]) + 1;
                    else operations += max(abs(nums[i] - nums[i-1]), abs(nums[i] - nums[i+1])) + 1;
                }
        }
        else 
        {
            int k = (n-2)/2;
            vector<long long> odds(k,0);
            vector<long long> even(k,0);

            for(int i=0;i<k;i++)
                {   int idx = 2*i+2;
                    int curr = nums[idx];
                    int prev = nums[idx-1];
                    int next = nums[idx+1];

                    if(curr > prev && curr > next) continue;
                    else if(curr > prev && curr <= next) even[i] = abs(nums[idx]-nums[idx+1]) + 1;
                    else if(curr <= prev && curr > next) even[i] = abs(nums[idx]-nums[idx-1]) + 1;
                    else even[i] = max(abs(nums[idx] - nums[idx-1]), abs(nums[idx] - nums[idx+1])) + 1;
                }
            for(int i=0;i<k;i++)
                { 
                    int idx = 2*i+1;
                    int curr = nums[idx];
                    int prev = nums[idx-1];
                    int next = nums[idx+1];

                    if(curr > prev && curr > next) continue;
                    else if(curr > prev && curr <= next) odds[i] = abs(nums[idx]-nums[idx+1]) + 1;
                    else if(curr <= prev && curr > next) odds[i] = abs(nums[idx]-nums[idx-1]) + 1;
                    else odds[i] = max(abs(nums[idx] - nums[idx-1]), abs(nums[idx] - nums[idx+1])) + 1;
                }
            vector<long long> pre(k+1,0);
            vector<long long> suff(k+1,0);

            for(int i=0;i<k;i++) pre[i+1] = pre[i] + odds[i];
            for(int i=k-1;i>=0;i--) suff[i] = suff[i+1] + even[i];
            long long minop = -1;
            for(int i=0;i<=k;i++)
                {
                    long long curr_op = pre[i] + suff[i];
                    if(minop == -1 || curr_op < minop) minop = curr_op;
                }
            operations = minop;
            
        }

        return operations;
        
    }
};