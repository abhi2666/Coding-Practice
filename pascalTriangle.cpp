// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
        
//         // first and the last element of each vector will be 1
//         vector<vector<int>>ans;
//         ans.push_back({1});
//         ans.push_back({1, 1});
//         numsRows -= 2;

//         while(numRows--){
//             vector<int>inter;
//             inter.push_back(1);
//             for(int i = 1; i < vect.back().size(); i++){
//                 int val = vect.back()[i-1] + vect.back()[i];
//                 inter.push_back(val);
//             }
//             inter.push_back(1);
//             ans.push_back(inter);
//         }
//         return vect;
//     }
// };

class Solution{
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);

        for(int i = 0; i < numRows; i++){
            ans[i].resize(i+1, 1); // ith row with size i+1 all initialized to 1
            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j-1]+ ans[i - 1][j]
            } 
        }
    }
};