class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> ans;

        for(string& foo : folder){
            bool isSub = false;
            string prefix = foo;
            while(!prefix.empty()){
                size_t pos = prefix.find_last_of('/');
                if(pos == string::npos) break;
                prefix = prefix.substr(0, pos);
                if(folderSet.count(prefix)){
                    isSub = true;
                    break;
                }
            }
            if(!isSub){
                ans.push_back(foo);
            }
        }

        return ans;
    }
};