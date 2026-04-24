class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count_L = 0;
        int count_R = 0;
        for(int i=0;i<moves.size();i++) 
        {
            if(moves[i] == 'L') count_L++;
            else if(moves[i] == 'R') count_R++;
        }

        int rem = moves.length() - count_L - count_R;
        if(count_R >= count_L) return (count_R + rem - count_L);
        else return (count_L + rem - count_R);
    }
};