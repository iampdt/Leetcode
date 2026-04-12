class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
     vector<int> ans(n,0);

    for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                {
                if(matrix[i][j] == 1) {ans[i]+=1; ans[j]+=1;}
                }
        }

        for(int i=0;i<ans.size();i++) ans[i]/=2;

        return ans;
        
    }
};