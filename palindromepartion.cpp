class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>res;
        vector<string>temp;
        func(s,0,temp,res);
        return res;

    }
    void func(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        for (int end = start + 1; end <= s.length(); ++end) {
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
                func(s, end, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};