#include <bits/stdc++.h>

using namespace std;

int main()
{


    return 0;
}





class Solution
{
public:
    vector<int> targetIndices(vector<int>& v, int& tar)
    {
        sort(v.begin(), v.end());

        int idx = fun(v, 0, v.size() - 1, tar);
        if (idx >= 0 && idx < v.size() && v[idx] == tar)
        {
            int st = idx;
            int end = idx;
            while (st >= 0 && v[st] == v[idx])
            {
                st--;
            }
            while (end < v.size() && v[end] == v[idx])
            {
                end++;
            }

            st++;
            end--;
            vector<int> ans;
            for (auto i = st; i <= end; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        return {};
    }
    int fun(vector<int>& v, int l, int r, int tar)
    {
        if (l > r)
        {
            return r;
        }
        int mid = l + (r - l) / 2;
        if (v[mid] == tar)
        {
            return mid;
        }
        if (v[mid] > tar)
        {
            return fun(v, l, mid - 1, tar);
        }
        return fun(v, mid + 1, r, tar);

    }
};
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& v)
    {
        sort(v.begin(), v.end());
        int n = v.size();
        set<vector<int>> ans;
        for (auto i = 0; i < n - 2; i++)
        {
            for (auto j = i + 1; j < n - 1; j++)
            {
                for (auto k = j + 1; k < n; k++)
                {
                    if (v[i] + v[j] + v[k] == 0 && i != j && i != k && j != k)
                    {
                        ans.insert({v[i], v[j], v[k]});
                    }
                }
            }
        }

        return {ans.begin(), ans.end()};
    }
};

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& v)
    {
        if (v.size() < 3)
        {
            return {};
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            while (i > 0 && i < v.size() && v[i] == v[i - 1])
            {
                i++;
            }

            int j = i + 1;
            int k = v.size() - 1;

            while (j < k)
            {
                int sum = v[i] + v[j] + v[k];

                if (sum == 0)
                {
                    ans.push_back({v[i], v[j], v[k]});

                    while (j < k && v[j] == v[j + 1])
                    {
                        j++;
                    }

                    while (j < k && v[k] == v[k - 1])
                    {
                        k--;
                    }

                    j++;
                    k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};
class Solution
{
public:
    int maxArea(vector<int>& v)
    {
        int ans = INT_MIN;
        int l = 0;
        int r = v.size() - 1;
        while (l < r)
        {
            int area = min(v[l], v[r]) * (r - l);
            ans = max(ans, area);
            if (v[l] > v[r])
            {
                r--;
            }
            else if (v[l] < v[r])
            {
                l++;
            }
            else
            {
                if (v[l + 1] < v[r - 1])
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    bool isSubsequence(string& s, string& t)
    {
        if (s.empty()) return true;

        if (t.empty()) return false;
        int st = 0;
        for (auto i = 0; i < s.size(); i++)
        {
            bool flag = true;
            for (auto j = st; j < t.size(); j++)
            {
                if (s[i] == t[j])
                {
                    st = j + 1;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return false;
            }
        }
        return true;
    }
};
class Solution
{
public:
    bool isSubsequence(string& s, string& t)
    {
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};

class Solution
{
public:
    bool validPalindrome(string& s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r])
            {
                if (isPalindrome(s.substr(l, r - l)) || isPalindrome(s.substr(l + 1, r - l))) return true;

                else return false;

            }

            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            if (s[l] != s[r]) return false;

            l++;
            r--;
        }
        return true;
    }
};


class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& v, int target)
    {
        if (v.size() < 4)
        {
            return {};
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        for (int h = 0; h < v.size() - 3; h++)
        {
            while (h > 0 && h < v.size() - 3 && v[h] == v[h - 1])
            {
                h++;
            }
            for (int i = h + 1; i < v.size() - 2; i++)
            {
                while (i > h + 1 && i < v.size() - 2 && v[i] == v[i - 1])
                {
                    i++;
                }

                int j = i + 1;
                int k = v.size() - 1;

                while (j < k)
                {
                    long long sum = (long long)v[i] + (long long)v[j] + (long long)v[k] + (long long)v[h];

                    if (sum == target)
                    {
                        ans.push_back({v[i], v[j], v[k], v[h]});

                        while (j < k && v[j] == v[j + 1])
                        {
                            j++;
                        }

                        while (j < k && v[k] == v[k - 1])
                        {
                            k--;
                        }

                        j++;
                        k--;
                    }
                    else if (sum > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution
{
public:
    vector<vector<int>> generate(int row)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (row == 1) return ans;
        int i = 2;
        while (i <= row)
        {
            int l = -1;
            int r = 0;
            int j = 0;

            vector<int> v(i);

            while (r <= ans.back().size())
            {
                if (l == -1 || r == ans.back().size())
                {
                    v[j] = 1;
                }
                else
                {
                    v[j] = ans.back()[l] + ans.back()[r];
                }
                l++; r++; j++;
            }
            ans.push_back(v);
            i++;
        }
        return ans;
    }
};
class Solution
{
public:
    int mid;
    int maximumCount(vector<int>& v)
    {
        int idx = fun(v, 0, v.size() - 1, 0);

        int st = idx;
        int end = idx;
        while (st >= 0 && v[st] >= 0)
        {
            st--;
        }
        while (end < v.size() && v[end] <= 0)
        {
            end++;
        }

        return max(int(st + 1), int(v.size() - end));


    }
    int fun(vector<int>& v, int l, int r, int tar)
    {
        if (l > r)
        {
            return mid;
        }
        this->mid = l + (r - l) / 2;
        if (v[mid] == tar)
        {
            return mid;
        }
        if (v[mid] > tar)
        {
            return fun(v, l, mid - 1, tar);
        }
        return fun(v, mid + 1, r, tar);

    }
};

class Solution
{
public:
    int removeElement(vector<int>& v, int val)
    {
        int i = 0;
        int j = v.size() - 1;
        while (i <= j)
        {
            while (i <= j && v[j] == val) j--;
            while (i <= j && v[i] != val) i++;
            if (i < j)
            {
                swap(v[i], v[j]);
            }
        }
        return i;
    }
};
class Solution
{
public:
    string mergeAlternately(string& w1, string& w2)
    {
        string ans;
        int i = 0, j = 0;
        while (i < w1.size() && j < w2.size())
        {
            ans.push_back(w1[i++]);
            ans.push_back(w2[j++]);
        }
        while (i < w1.size())
        {
            ans.push_back(w1[i++]);
        }
        while (j < w2.size())
        {
            ans.push_back(w2[j++]);
        }
        return ans;
    }
};

class Solution
{
public:
    void moveZeroes(vector<int>& v)
    {
        int l = 0;

        while (l < v.size() - 1)
        {
            int r = l + 1;
            while (v[l] == 0 && r < v.size())
            {
                swap(v[l], v[r]);
                r++;
            }
            l++;
        }
    }
};


class Solution
{
public:
    void merge(vector<int>& left, int& m, vector<int>& right, int& n)
    {
        int i = left.size() - 1;
        int j = m - 1;
        int k = n - 1;

        while (j >= 0 && k >= 0)
        {
            if (left[j] > right[k])
            {
                left[i--] = left[j--];
            }
            else
            {
                left[i--] = right[k--];

            }
        }
        while (k >= 0)
        {
            left[i--] = right[k--];
        }
        while (j >= 0)
        {
            left[i--] = left[j--];
        }
    }
};
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& v)
    {
        int i = 0;
        vector<int> ans;
        while (i < v.size())
        {
            if (v[i] > 0) break;
            i++;
        }

        int j = i;
        int k = i - 1;

        while (k >= 0 && j < v.size())
        {
            if (v[j] < abs(v[k]))
            {
                ans.push_back(pow(v[j++], 2));
            }
            else
            {
                ans.push_back(pow(v[k--], 2));
            }

        }
        while (k >= 0)
        {
            ans.push_back(pow(v[k--], 2));
        }
        while (j < v.size())
        {
            ans.push_back(pow(v[j++], 2));
        }
        return ans;
    }
};

class Solution
{
public:
    int dp[40];
    Solution() { memset(dp, -1, sizeof(dp)); }
    int tribonacci(int n)
    {
        if (n <= 0) return 0;
        if (n == 1 or n == 2) return 1;

        if (dp[n] != -1) return dp[n];

        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);

    }
};