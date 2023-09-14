/*
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
*/
class Solution
{
public:
    void dfs(string item, unordered_map<string, vector<string>> &mp, unordered_set<string> &st)
    {
        // check if the neighbor is already visited
        if (st.count(item) > 0) {
            return;
        }

        // mark the neighbor as visited
        st.insert(item);

        // recurse on all the neighbors
        for (auto neighbour : mp[item]) {
            dfs(neighbour, mp, st);
        }
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        // create a adjaceny list to store data in form of a directed graph
        unordered_map<string, vector<string>> mp;
        unordered_set<string> st; // will store the visited elements

        for (auto it : tickets) {
            mp[it[0]].push_back(it[1]);
        }

        // from "jkf" we will call for DFS
        dfs("JFK", mp, st);

        // sort the result vector before returning it
        vector<string> res;
        for (auto it : st) {
            res.push_back(it);
        }
        sort(res.begin(), res.end());

        return res;
    }
};
