class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // cur: ORs ending at previous index, next: ORs ending at current
        unordered_set<int> cur, next, result;

        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : cur)
                next.insert(x | num);
            cur = next;
            result.insert(cur.begin(), cur.end());
        }

        return result.size();
    }
};
