class Solution {
public:
    string reorganizeString(string str) {
        std::vector<int> hash(26, 0);
        for (int i = 0; i < str.length(); i++) {
            hash[str[i] - 'a']++;
        }

        int max = 0, letter = 0;
        for (int i = 0; i < hash.size(); i++) {
            if (hash[i] > max) {
                max = hash[i];
                letter = i;
            }
        }

        if (max > (str.length() + 1) / 2) {
            return "";
        }

        string res(str.length(), ' ');

        // Fill all even places with majority character
        int idx = 0;
        while (hash[letter]-- > 0) {
            res[idx] = static_cast<char>(letter + 'a');
            idx += 2;
        }

        // Fill the remaining characters
        for (int i = 0; i < hash.size(); i++) {
            while (hash[i]-- > 0) {
                if (idx >= res.length()) {
                    idx = 1;
                }

                res[idx] = static_cast<char>(i + 'a');
                idx += 2;
            }
        }

        return res;
    }
};