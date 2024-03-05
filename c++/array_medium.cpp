#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& mat)
    {
        vector<int> ans;

        int top = 0;
        int left = 0;
        int bottom = mat.size() - 1;
        int right = mat[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(mat[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {

        vector<vector<int>> ans(rows * cols, vector<int>(2));
        int i = 0;
        ans[i++] = {rStart, cStart};
        int len = 0;
        int d = 0;
        int direction[] = {0, 1, 0, -1, 0};
        while (i < rows * cols)
        {
            if (d == 0 || d == 2)
            {
                len++;
            }
            for (int k = 0; k < len; k++)
            {
                rStart += direction[d];
                cStart += direction[d + 1];
                if (rStart < rows && rStart >= 0 && cStart < cols && cStart >= 0)
                {
                    ans[i++] = {rStart, cStart};
                }
            }
            if (d < 3)
            {
                d++;
            }
            else
            {
                d = 0;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    void setZeroes(vector<vector<int>>& mat)
    {
        set<int> s1;
        set<int> s2;

        for (int r = 0; r < mat.size(); r++)
        {
            for (int c = 0; c < mat[0].size(); c++)
            {
                if (mat[r][c] == 0)
                {
                    s1.insert(r);
                    s2.insert(c);
                }
            }
        }

        for (auto i : s1)
        {
            for (int c = 0; c < mat[0].size(); c++)
            {
                mat[i][c] = 0;
            }
        }
        for (auto j : s2)
        {

            for (int r = 0; r < mat.size(); r++)
            {
                mat[r][j] = 0;
            }
        }
    }
};

class Solution
{
public:
    vector<int> searchRange(vector<int>& arr, int tar)
    {
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
            {
                ans[0] = mid;
                high = mid - 1;
            }
            else if (arr[mid] > tar)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        low = 0;
        high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == tar)
            {
                ans[1] = mid;
                low = mid + 1;
            }
            else if (arr[mid] > tar)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

class Solution
{
public:
    bool canJump(vector<int>& arr)
    {
        int tar = arr.size() - 1;

        for (int i = tar - 1; i >= 0; i--)
        {
            if (i + arr[i] >= tar)
            {
                tar = i;
            }
        }
        if (tar == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        reverse(nums.begin(), nums.end() - k - 1);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        vector<vector<string>> ans;
        map<string, vector<string>> m;
        for (auto& i : str)
        {
            string num;
            vector<int> count(26);
            for (const auto& j : i)
            {
                count[j]++;
            }
            for (auto i = 0; i < 26; i++)
            {
                num += string(count[i], i + 'a');
            }

            if (m.find(num) != m.end())
            {
                auto it = m.find(num);
                it->second.push_back(i);
            }
            else
            {
                m[num] = {i};
            }
        }
        for (const auto& i : m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> m;
        for (const auto& i : nums)
        {
            m[i]++;
        }
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
        vector<int> ans;
        for (auto i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& v, int k)
    {
        unordered_map<int, int> m;
        for (const auto& i : v)
        {
            m[i]++;
        }
        vector<vector<int>> ans(v.size());
        for (const auto& i : m)
        {
            ans[i.second - 1].push_back(i.first);
        }
        vector<int> ans2;
        for (auto i = ans.size() - 1; ans2.size() != k; i--)
        {
            if (!ans[i].empty())
            {
                ans2.insert(ans2.end(), ans[i].begin(), ans[i].end());
            }
        }
        return ans2;
    }
};
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int ROW = board.size();
        int COL = board[0].size();
        int r = 0;
        int c = 0;

        while (r < ROW)
        {
            map<char, bool> m;

            // Check for duplicates in columns
            for (int i = 0; i < COL; i++)
            {
                if (board[r][i] != '.')
                {
                    if (m.find(board[r][i]) != m.end())
                    {
                        return false;
                    }
                    else
                    {
                        m[board[r][i]] = true;
                    }
                }
            }

            // Check for duplicates in rows
            for (int i = 0; i < ROW; i++)
            {
                if (board[r][i] != '.')
                {
                    if (m.find(board[i][c]) != m.end())
                    {
                        return false;
                    }
                    else
                    {
                        m[board[i][c]] = true;
                    }
                }
            }

            // Check for duplicates in subgrid
            int sub_ROW = r - (r % int(sqrt(ROW)));
            int sub_COL = c - (c % int(sqrt(COL)));

            for (int i = sub_ROW; i < sub_ROW + int(sqrt(ROW)); i++)
            {
                for (int j = sub_COL; j < sub_COL + int(sqrt(COL)); j++)
                {
                    if (board[r][i] != '.')
                    {
                        if (m.find(board[i][j]) != m.end())
                        {
                            return false;
                        }
                        else
                        {
                            m[board[i][j]] = true;
                        }
                    }
                }
            }

            if (c <= COL - 2)
            {
                c++;
            }
            else
            {
                r++;
                c = 0;
            }
        }

        return true;
    }
};

class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string>& strs)
    {
        // write your code here
        string ans;
        for (const auto& i : strs)
        {
            ans += (to_string(i.size()) + ";" + i);
        }
        return ans;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string& str)
    {
        // write your code here
        vector<string> ans;
        int i = 0;
        while (i < str.size())
        {
            int j = i + 1;
            int n = (str[i] - '0');
            while (str[j] != ';')
            {
                j++;
            }
            int length = stoi(str.substr(i, j - i));
            string s = str.substr(j + 1, length);
            ans.push_back(s);
            i = j + 1 + length;
        }
        return ans;
    }
};
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> m(nums.begin(), nums.end());

        int count;
        int max_count = 0;

        for (const auto& i : m)
        {
            if (m.count(i - 1) == 0)
            {
                count = 1;
                while (m.count(i + count))
                {
                    count++;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};
class Solution
{
public:
    vector<int> twoSum(vector<int>& arr, int tar)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            if (m.find(arr[i]) == m.end())
            {
                m[arr[i]] = i;
            }
            else
            {
                auto a = m.find(tar - arr[i]);
                if (a != m.end() && a->first + arr[i] == tar)
                {
                    return {m[tar - arr[i]], i};
                }
            }
        }

        return {};
    }
};
class Solution
{
public:
    bool isValidSudoku(vector<vector<int>>& b)
    {
        int r = b.size();
        int c = b[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                unordered_map<int, bool> row;
                unordered_map<int, bool> col;
                unordered_map<int, bool> sub;

                for (int x = 0; x < r; x++)
                {
                    if (b[x][j] != 0)
                    {
                        auto it = row.find(b[x][j]);
                        if (it != row.end())
                        {
                            return false;
                        }
                        else
                        {
                            row[b[x][j]] = true;
                        }
                    }
                }
                for (int x = 0; x < c; x++)
                {
                    if (b[i][x] != 0)
                    {
                        auto it = col.find(b[i][x]);
                        if (it != col.end())
                        {
                            return false;
                        }
                        else
                        {
                            col[b[i][x]] = true;
                        }
                    }
                }
                int sub_row = i - (i % int(sqrt(r)));
                int sub_col = j - (j % int(sqrt(c)));

                for (int x = sub_row; x < sub_row + 3; x++)
                {
                    for (int y = sub_col; y < sub_col + 3; y++)
                    {
                        if (b[x][y] != 0)
                        {
                            auto it = sub.find(b[x][y]);
                            if (it != sub.end())
                            {
                                return false;
                            }
                            else
                            {
                                sub[b[x][y]] = true;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isValidSudoku(vector<vector<int>>& b)
    {
        int r = b.size();
        int c = b[0].size();
        bool hash_row[9][9] = {false};
        bool hash_col[9][9] = {false};
        unordered_map<vector<int>, vector<char>> sub({});

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (b[i][j] == '.')
                {
                    continue;
                }
                int in = b[i][j] - '0' - 1;
                vector<int> locale = {i / 3, j / 3};

                if (sub.find(locale) != sub.end())
                {
                    char tar = b[i][j];
                    if (find(sub[locale].begin(), sub[locale].end(), tar) != sub[locale].end())
                    {
                        return false;
                    }
                }
                if (hash_col[j][in] || hash_row[i][in])
                {
                    return false;
                }
                else
                {
                    sub[locale].push_back(b[i][j]);
                    hash_col[j][in] = true;
                    hash_row[i][in] = true;
                }
            }
        }
        return true;
    }
};
class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> m(nums.begin(), nums.end());
        int ans = 0;

        for (auto& i : m)
        {
            int len = i;

            if (!m.count(i - 1))
            {

                int count = 1;
                while (m.count(len + 1))
                {
                    count++;
                    len++;
                }
                ans = max(count, ans);
            }
        }

        return ans;
    }
};
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> set;

        while (r < s.size())
        {
            while (set.count(s[r]))
            {
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);
            r++;
            ans = max(ans, r - l);
        }

        return ans;
    }
};
class Solution
{
public:
    int maxProfit(vector<int>& p)
    {
        bool flag = false;
        int b = 0;
        int s = 0;
        int max = 0;
        for (auto i = 0; i < p.size() - 1; i++)
        {
            if (p[i] < p[i + 1] && !flag)
            {
                b = p[i];
                flag = true;
            }
            else if (p[i] > p[i + 1] && flag)
            {
                s = p[i];
                flag = false;
                max += s - b;
            }
        }
        if (flag && p.back() > b)
        {
            max += p.back() - b;
        }
        return max;
    }
};

class Solution
{
public:
    int subarraySum(vector<int>& v, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map;

        for (const auto& i : v)
        {
            sum += i;
            int diff = sum - k;
            if (sum == k) count++;

            auto it = map.find(diff);

            if (it != map.end())
                count += it->second;
            map[sum]++;
        }

        return count;
    }
};
class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> st;
        int count = 0;
        int max = 0;
        for (char c : s)
        {
            if (c == ']')
                count++;
            else
                count--;
            max = std::max(max, count);
        }

        return (max+1) / 2;
    }
};
