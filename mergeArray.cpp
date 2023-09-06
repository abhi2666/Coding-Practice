class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = m;
        vector<int>interm;
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                interm.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                interm.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m)
        {
            interm.push_back(nums1[i]);
            i++;
        }
        while(j < n)
        {
            interm.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        for(auto i : interm)
        {
            nums1.push_back(interm);
        }
    }
};