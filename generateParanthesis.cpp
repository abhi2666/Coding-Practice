// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

/*
Approach --> we will have to find all the possible combinations and then
use them to find balaced pairs
To keep parantheiss balanced we will set 2 conditions
( cannot exceeds the value of n because we will have only 2*n size of
string.
) will only come if the count of ( is greater than count of )

just think when can we actually put ( and when can we put ).
*/

class Solution {
public:
    void generatePara(string temp, int open, int close, int n, vector<string>&ans){

        if(open == n && close == n){
            ans.push_back(temp);
            return;
        }

        // you can either pick ( or ) based on open and close value
        if(open < n)
        {
            generatePara(temp+'(', open+1, close, n, ans);
        }
        if(open > close){
            generatePara(temp+')', open, close+1, n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generatePara("", 0, 0, n, ans);
    }
};