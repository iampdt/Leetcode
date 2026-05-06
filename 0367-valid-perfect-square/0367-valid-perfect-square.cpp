class Solution {
public:
    bool isPerfectSquare(int num) {

        int low = 1;
        int high = num/2 + 1;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(1LL*mid*mid < 1LL*num) low = mid + 1;
            else high = mid;
        }
        cout<<low;
        return (1LL*low*low == 1LL*num);
        
    }
};