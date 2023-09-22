class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        return getValidMoves(positions[0], positions[1], pieces);
    }
};