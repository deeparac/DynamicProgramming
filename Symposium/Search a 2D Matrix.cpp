class Solution {
public:
    /*
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        if (matrix.size() == 0) {
            return 0;
        }
        if (matrix[0].size() == 0) {
            return 0;
        }

        // from bottom left to top right
        int n = matrix.size();
        int m = matrix[0].size();
        int x = n - 1;
        int y = 0;
        int count = 0;

        while (x >= 0 && y < m) {
            if (matrix[x][y] < target) {
                y++;
            } else if (matrix[x][y] > target) {
                x--;
            } else {
                count++;
                x--;
                y++;
            }
        }
        return count;
    }
};
