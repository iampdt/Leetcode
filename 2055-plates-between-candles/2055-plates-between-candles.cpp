
class Solution {
public:
 vector<int> platesBetweenCandles( string s,  vector< vector<int>>& queries) {
   vector<int> candles;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '|') {
                candles.push_back(i);
            }
        }
        
      vector<int> answer;
        
        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            auto it_left =  lower_bound(candles.begin(), candles.end(), left);
        
            auto it_right =  upper_bound(candles.begin(), candles.end(), right);
            if (it_left == candles.end() || it_right == candles.begin()) {
                answer.push_back(0);
                continue;
            }
            --it_right;
            if (it_left >= it_right) {
                answer.push_back(0);
            } else {
                int left_idx = *it_left;
                int right_idx = *it_right;
                int num_candles =  distance(it_left, it_right) + 1;
                int total_distance = (right_idx - left_idx + 1);
                answer.push_back(total_distance - num_candles);
            }
        }
        
        return answer;
    }
};