class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int num1Size = num1.size(), num2Size = num2.size();
        vector<int> cnt(num1Size + num2Size, 0);

        for(int i = num1Size-1; i >= 0; --i){
            for(int j = num2Size-1; j >= 0; --j){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int sum = cnt[i+j+1] + mul;
                cnt[i+j+1] = sum%10;
                cnt[i+j] += sum/10;
            }
        }
        string ans;
        for (int num : cnt) {
            if (!(ans.empty() && num == 0))
                ans += to_string(num);
        }
        return ans.empty() ? "0" : ans;
    }
};