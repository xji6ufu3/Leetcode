class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0, len1 = nums1.size(), len2 = nums2.size();
        while(i < len1 && j < len2){
            int id1 = nums1[i][0], id2 = nums2[j][0];
            if(id1 == id2){
                ans.push_back({id1, nums1[i++][1] + nums2[j++][1]});
            }
            else if(id1 < id2){
                ans.push_back(nums1[i++]);
            } else {
                ans.push_back(nums2[j++]);
            }
        }
        while(i < len1) ans.push_back(nums1[i++]);
        while(j < len2) ans.push_back(nums2[j++]);

        return ans;
    }
};