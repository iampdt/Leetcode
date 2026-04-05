class Solution {
public:
    bool judgeCircle(string moves) {

        int h = 0;
        int v =0;

        for(int i=0;i<moves.length();i++)
        {
            if(moves[i] == 'R') h++;
            else if(moves[i] == 'L' ) h--;
            else if(moves[i] == 'U') v++;
            else v--; 
        }

        return  h ==0 && v ==0 ? true : false;
        
    }
};