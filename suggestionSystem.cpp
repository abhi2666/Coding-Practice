/*
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
*/

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        // we need top 3 lexographical strings
        // for each character entered return 3 strings at max
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        string search;
        for (char ch : searchWord)
        {
            vector<string> suggests;
            search += ch;
            // for each character deduce a string
            int k = 3;
            for (auto str : products)
            {
                // if string matches
                if (str.substr(0, search.length()) == search)
                {
                    suggests.push_back(str);
                    k--;
                }
                if(k == 0) break;
            }
            result.push_back(suggests);
        }
        return result;
    }
};