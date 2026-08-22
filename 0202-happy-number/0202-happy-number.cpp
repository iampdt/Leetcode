class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> s;

        while(n > 0)
        {
          int temp = n;
          int sum = 0;
           while(temp > 0)
           {
             sum += (temp % 10) * (temp%10);
             temp/=10;
           }
           if(sum == 1) return true;
           else 
           {
             if(s.find(sum) != s.end()) return false;
             s.insert(sum);
             n = sum;
           }
        }
        for(auto it: s) cout<<it<<" ";
      return true;
    }
};