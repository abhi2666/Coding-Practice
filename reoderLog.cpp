// make it generalised

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // extract all the log files into one vector
        map<string, string>lets; // letno and text with it
        string s;
        for(auto str : logs)
        {
            s = str;
            if(s[0] == 'l')
            {
                // it is a let string.....process it
                int i = 0;
                string first, last;
                while(s[i] != ' ')
                {
                    i++;
                }
                first = s.substr(0, i);
                last = s.substr(i+1, s.size());
                lets.insert({first, second});
            }
        }
        // sort(lets.begin(), lets.end());
        // now combine then sorted lets
        vector<string> result;
        for(auto it : lets)
        {
            s = it.first+' '+it.second;
            result.push_back(s);
        }
        // now put the digit ones as it is 
        for(auto str : logs)
        {
            if(str[0] == 'd')
            {
                // it is digit one
                result.push_back(str);
            }
        }

        return result;
    }
};