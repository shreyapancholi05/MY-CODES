class Solution {
public:
    int f(vector<string>& strs, int i, int m, int n, vector<vector<vector<int>>> &table) {
        if (i == strs.size())
            return 0;

        if (table[i][m][n] != -1)
            return table[i][m][n];

        int c0 = count(strs[i].begin(), strs[i].end(), '0');
        int c1 = strs[i].size() - c0;

        int skip = f(strs, i + 1, m, n, table);
        int pick = 0;
        if (c0 <= m && c1 <= n) {
            pick = 1 + f(strs, i + 1, m - c0, n - c1, table);
        }

        return table[i][m][n] = max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> table(sz, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return f(strs, 0, m, n, table);
    }
};
