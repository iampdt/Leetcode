class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        int n = words.size();
        int steps_forward = 0;
        int steps_backward = 0;
        int i = startIndex;
        int j = startIndex;
        while(words[i%n] != target) 
        {
            steps_forward++; 
             i++;
             if(steps_forward >= n) return -1;
        
        }
        while(words[(n+j)%n]!= target) {steps_backward++; j--; if(steps_backward >= n) return -1;}

        return steps_backward > steps_forward ? steps_forward : steps_backward;

        
    }
};