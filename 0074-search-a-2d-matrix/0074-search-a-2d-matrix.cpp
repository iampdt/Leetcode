class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size() * matrix[0].size();
        int low = 0;
        int high = n - 1;

        while(low < high)
        {
            int mid = low + (high - low)/2;
            int row = mid / matrix[0].size();
            int col = mid % matrix[0].size();

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid;
        }
        if(matrix[low/matrix[0].size()][low%matrix[0].size()] == target) return true;
        return false;
    }
};