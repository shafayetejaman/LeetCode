#include <bits/stdc++.h>
using namespace std;

// int fibonacci(int n)
// {
//     if (n == 1)
//         return 1;
//     if (n == 2)
//         return 2;

//     int n_1 = fibonacci(n - 1);
//     int n_2 = fibonacci(n - 2);
//     return n_1 + n_2;
// }
// class Solution
// {
// public:
//     bool isPowerOfTwo(int n)
//     {
//         return fun(n, 2);
//     }
//     bool fun(int n, int num)
//     {
//         if (num == n)
//             return true;

//         if (num > n)
//             return false;
//         return fun(n, num * num);
//     }
// };
// int sum(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     int sum_til = sum(n - 1);
//     sum_til *= n;
//     return sum_til;
// }

// int arraySum(vector<int> v)
// {
//     if (v.empty())
//         return 0;
//     int last = v[0];
//     last += arraySum({v.begin() + 1, v.end()});
//     return last;
// }

// int reverseNum(int n, int ans)
// {
//     if (n == 0)
//     {
//         return ans;
//     }
//     ans = ans * 10 + (n % 10);
//     return reverseNum(n / 10, ans);
// }

// int count0(int n, int count)
// {
//     if (n == 0)
//     {
//         return count;
//     }
//     if (n % 10 == 0)
//     {
//         return count0(n / 10, count + 1);
//     }
//     return count0(n / 10, count);
// }

// bool isSorted(vector<int>& v)
// {
//     if (v.size() == 1)
//         return true;

//     int last = v.back();
//     v.pop_back();
//     if (last < v.back())
//         return false;

//     return isSorted(v);
// }
// class Solution
// {
// public:
//     int search(vector<int>& nums, int target)
//     {
//         return fun(nums, 0, nums.size() - 1, target);
//     }
//     int fun(vector<int>& v, int l, int r, int tar)
//     {
//         if (l > r)
//         {
//             return -1;
//         }
//         int mid = l + (r - l) / 2;
//         if (v[mid] == tar)
//         {
//             return mid;
//         }
//         if (v[mid] > tar)
//         {
//             return fun(v, l, mid - 1, tar);
//         }
//         return fun(v, mid + 1, r, tar);

//     }
// };
// class Solution
// {
// public:
//     void reverseString(vector<char>& s)
//     {
//         fun(s, 0, s.size() - 1);
//     }
//     void fun(vector<char>& s, int l, int r)
//     {
//         if (l >= r)
//             return;

//         swap(s[l], s[r]);
//         fun(s, l + 1, r - 1);
//     }
// };

vector<int> fun(vector<int>& v, int tar)
{
    if (v.empty()) return {};

    vector<int> ans;

    if (v.back() == tar)
    {
        ans.push_back(v.size() - 1);
    }
    v.pop_back();
    vector<int> ans2 = fun(v, tar);

    ans.insert(ans.end(), ans2.begin(), ans2.end());
    return ans;
}

void pattern(int r, int c)
{
    if (r == 0) return;

    if (r > c)
    {
        pattern(r, c + 1);
        cout << "* ";
    }
    else
    {
        pattern(r - 1, 0);
        cout << endl;
    }
}

vector<int> v = {1, 6, 7, 2, 3, 4, 5, 10};

void bubbleSort(int r, int c)
{
    if (r == 0) return;

    if (r - 1 > c)
    {
        if (v[c] > v[c + 1])
        {
            swap(v[c], v[c + 1]);
        }
        bubbleSort(r, c + 1);
    }
    else
    {
        bubbleSort(r - 1, 0);
    }
}
int maximum(int r, int c)
{
    if (r == 0) return INT_MIN;
    int max = INT_MIN;
    if (r - 1 > c)
    {
        if (v[c] > v[c + 1])
        {
            max = v[c];
        }
        else
        {
            max = v[c + 1];
        }

        max = std::max(max, maximum(r, c + 1));
    }
    else
    {
        maximum(r - 1, 0);
    }
    return max;
}

string remove(string s, int idx)
{
    if (idx == s.size()) return {};

    if (s[idx] == 'a')
    {
        return remove(s, idx + 1);
    }

    return s[idx] + remove(s, idx + 1);
}
vector<string> subsequence(string& s, int idx, string ans)
{
    if (idx == s.size()) return {ans};

    vector<string> v;

    auto v1 = subsequence(s, idx + 1, ans);
    auto v2 = subsequence(s, idx + 1, ans + s[idx]);
    v.insert(v.end(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());

    return v;

}

vector<string> permutation(string& s, int idx, string ans)
{
    if (idx == s.size()) return {ans};

    vector<string> v;

    for (auto i = 0; i <= ans.size(); i++)
    {
        string left = ans.substr(0, i);
        string right = ans.substr(i);
        auto v1 = permutation(s, idx + 1, left + s[idx] + right);
        v.insert(v.end(), v1.begin(), v1.end());
    }

    return v;
}
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        return permutation(nums, 0, {});
    }
    vector<vector<int>> permutation(vector<int>& s, int idx, vector<int> ans)
    {
        if (idx == s.size()) return {ans};

        vector<vector<int>> v;

        for (auto i = 0; i <= ans.size(); i++)
        {
            vector<int> left(ans.begin(), ans.begin() + i);
            vector<int> right(ans.begin() + i, ans.end());
            vector<int> ans2(left.begin(), left.end());
            ans2.push_back(s[idx]);
            ans2.insert(ans2.end(), right.begin(), right.end());
            auto v1 = permutation(s, idx + 1, ans2);
            v.insert(v.end(), v1.begin(), v1.end());
        }

        return v;
    }
};

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        return permutation(nums, 0, {});

    }

    vector<vector<int>> permutation(vector<int>& s, int idx, vector<int> ans)
    {
        if (idx == s.size()) return {ans};

        vector<vector<int>> v;

        for (auto i = 0; i <= ans.size(); i++)
        {
            vector<int> left(ans.begin(), ans.begin() + i);
            vector<int> right(ans.begin() + i, ans.end());

            bool skip = false;
            for (int j = 0; j < left.size(); j++)
            {
                if (left[j] == s[idx])
                {
                    skip = true;
                    break;
                }
            }
            if (skip)
                continue;

            vector<int> ans2(left.begin(), left.end());
            ans2.push_back(s[idx]);
            ans2.insert(ans2.end(), right.begin(), right.end());

            auto v1 = permutation(s, idx + 1, ans2);
            v.insert(v.end(), v1.begin(), v1.end());
        }

        return v;
    }

};
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        fun(candidates, 0, target, ans, {});
        return ans;

    }
    void fun(vector<int>& v, int idx, int& target, vector<vector<int>>& ans, vector<int> s)
    {
        int sum = Solution::sum(s);
        if (sum == target)
        {
            ans.push_back(s);
            return;
        }
        if (sum > target) return;

        for (auto i = idx; i < v.size(); i++)
        {
            s.push_back(v[i]);
            fun(v, i, target, ans, s);
            s.pop_back();
        }
    }
    int sum(vector<int>& v)
    {
        int Sum = 0;
        for (const auto& i : v)
        {
            Sum += i;
        }
        return Sum;
    }
};
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        fun(candidates, 0, target, ans, {});
        return ans;

    }
    void fun(vector<int>& v, int idx, int& target, vector<vector<int>>& ans, vector<int> s)
    {
        int sum = Solution::sum(s);
        if (sum == target)
        {
            ans.push_back(s);
            return;
        }
        if (sum > target) return;

        for (auto i = idx; i < v.size(); i++)
        {
            s.push_back(v[i]);
            fun(v, i, target, ans, s);
            s.pop_back();
        }
    }
    int sum(vector<int>& v)
    {
        int Sum = 0;
        for (const auto& i : v)
        {
            Sum += i;
        }
        return Sum;
    }
};

int main()
{
    string s = "abc";


    print(permutation(s, 0, ""));
    return 0;
}

class Solution
{
public:
    vector<int> dp;
    int climbStairs(int n)
    {
        dp.resize(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return fun(n);
    }
    int fun(int n)
    {
        if (n < 2) return dp[n];
        if (dp[n] != -1) return dp[n];
        return dp[n] = fun(n - 1) + fun(n - 2);
    }
};


class Solution
{
public:

    int minCostClimbingStairs(vector<int>& v)
    {
        int n = v.size();
        int next, nextOfNext;

        nextOfNext = v.back();
        next = min(v[n - 2] + v.back(), v[n - 2]);

        for (auto i = n - 3; i >= 0; i--)
        {
            int temp = min(v[i] + nextOfNext, v[i] + next);
            nextOfNext = next;
            next = temp;
        }

        return min(next, nextOfNext);
    }

};

class Solution
{
public:
    bool isSubsetSum(vector<int>& v, int sum)
    {
        vector<vector<bool>> dp(v.size() + 1, vector<bool>(sum + 1));
        int n = v.size();

        for (auto i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (auto i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - v[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[v.size()][sum];
    }
};



class Solution
{
public:
    bool canPartition(vector<int>& v)
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<vector<bool>> dp(v.size() + 1, vector<bool>(sum + 1));
        int n = v.size();

        for (auto i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (auto i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - v[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[v.size()][sum];
    }

};

class Solution
{

public:
    int minDifference(int v[], int n)
    {
        int sum = accumulate(v, v + n, 0);

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        for (auto i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        for (auto i = 1; i <= sum; i++)
        {
            dp[0][i] = false;
        }

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= sum; j++)
            {
                if (v[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - v[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int ans = INT_MAX;

        for (auto i = 0; i < sum; i++)
        {
            if (!dp[n][i]) continue;
            int p1 = i;
            int p2 = sum - i;
            ans = min(ans, abs(p1 - p2));
        }
        return ans;
    }
};

int findWays(vector<int>& v, int sum)
{
    vector<vector<long long>> dp(v.size() + 1, vector<long long>(sum + 1));
    int n = v.size();

    dp[0][0] = 1;
    for (auto i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 0; j <= sum; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[v.size()][sum];
}

class Solution
{
public:
    int sum;
    int findTargetSumWays(vector<int>& v, int tar)
    {
        sum = accumulate(v.begin(), v.end(), 0);
        vector<vector<int>> dp(v.size() + 1, vector<int>(sum * 2 + 1, INT_MAX));

        return fun(dp, v, 0, 0, tar);

    }
    int fun(vector<vector<int>>& dp, vector<int>& v, int i, int s, int tar)
    {
        if (i >= v.size())
        {
            if (s >= 0)
                return dp[i][s] = s == tar;
            else
                return dp[i][s + sum] = s == tar;

        }
        int left = fun(dp, v, i + 1, s + v[i], tar);
        int right = fun(dp, v, i + 1, s - v[i], tar);

        if (s >= 0)
            return dp[i][s] = left + right;
        else
            return dp[i][s + sum] = left + right;

    }
};

class Solution
{
public:
    int dp[1000 + 1][1000 + 1];
    Solution() { memset(dp, -1, sizeof(dp)); }

    int knapSack(int n, int w, int val[], int wt[])
    {
        if (n == 0 or w == 0) return 0;

        if (dp[n][w] != -1) return dp[n][w];

        if (wt[n - 1] <= w)
        {
            return dp[n][w] = max(knapSack(n, w - wt[n - 1], val, wt) + val[n - 1], knapSack(n - 1, w, val, wt));
        }
        else
        {
            return dp[n][w] = knapSack(n - 1, w, val, wt);
        }

    }

};

class Solution
{
public:
    int dp[1000 + 1][1000 + 1];
    Solution() { memset(dp, -1, sizeof(dp)); }

    int knapSack(int n, int w, int val[], int wt[])
    {
        if (n == 0 or w == 0) return 0;

        if (dp[n][w] != -1) return dp[n][w];

        if (wt[n - 1] <= w)
        {
            return dp[n][w] = max(knapSack(n, w - wt[n - 1], val, wt) + val[n - 1], knapSack(n - 1, w, val, wt));
        }
        else
        {
            return dp[n][w] = knapSack(n - 1, w, val, wt);
        }

    }

};


class Solution
{
    int dp[int(1e3 + 1)][int(1e3 + 1)];
public:
    long long int count(int coins[], int N, int sum)
    {
        memset(dp, -1, sizeof(dp));
        return fun(coins, N - 2, sum, coins[N - 1]);
    }
    long long fun(int c[], int n, int sum, int s)
    {
        if (s == sum) return 1;
        if (s > sum or n < 0) return 0;
        if (dp[n][s] != -1) return dp[n][s];

        return dp[n][s] = fun(c, n - 1, sum, s) + fun(c, n, sum, s + c[n]);
    }
};
class Solution
{
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int sum)
    {
        dp.resize(coins.size() + 1, vector<int>(sum + 1));
        int ans = fun(coins, coins.size() - 1, sum, 0);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
    int fun(vector<int>& c, int n, int sum, int s)
    {
        if (s == sum) return 1;
        if (s > sum or n < 0) return INT_MAX - 1;
        if (dp[n][s] != -1) return dp[n][s];

        return dp[n][s] = min(fun(c, n - 1, sum, s), fun(c, n, sum, s + c[n]) + 1);
    }
};
class Solution
{
public:
    int longestCommonSubsequence(string t1, string t2)
    {
        int n = t1.size();
        int m = t2.size();

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        for (auto i = 1; i <= n; i++)
        {
            for (auto j = 1; j <= m; j++)
            {
                if (t1[i - 1] == t2[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

string findLCS(int n, int m, string& t1, string& t2)
{

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (t1[i - 1] == t2[j - 1])
            {
                dp[i][j] += dp[i - 1][j - 1] + 1;

            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    string ans;

    while (i != 0 and j != 0)
    {
        if (t1[i - 1] == t2[j - 1])
        {
            ans += t1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;

}

int longestCommonSubstr(string t1, string t2, int n, int m)
{

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (auto i = 1; i <= n; i++)
    {
        for (auto j = 1; j <= m; j++)
        {
            if (t1[i - 1] == t2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    int m = 0;
    for (auto& i : dp)
    {
        for (auto& j : i)
        {
            m = max(j, m);
        }
    }
    return m;

};

class Solution
{
public:

    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto i = 1; i <= m; i++)
        {
            for (auto j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }
        return x.size() + y.size() - dp[m][n];
    }
};

class Solution
{
public:
    string shortestCommonSupersequence(string x, string y)
    {
        int m = x.size();
        int n = y.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto i = 1; i <= m; i++)
        {
            for (auto j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }

        string s;
        int i = m;
        int j = n;

        while (i > 0 and j > 0)
        {
            if (x[i - 1] == y[j - 1])
            {
                s.push_back(x[i - 1]);
                i--; j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    s.push_back(x[i - 1]);
                    i--;
                }
                else
                {
                    s.push_back(x[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0)
        {
            s.push_back(x[i - 1]);
            i--;
        }
        while (j > 0)
        {
            s.push_back(y[j - 1]);
            j--;
        }
        reverse(s.begin(), s.end());

        return s;

    }
};


int minOperations(string x, string y)
{
    int m = x.size();
    int n = y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto i = 1; i <= m; i++)
    {
        for (auto j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }
    return (m - dp[m][n]) + (n - dp[m][n]);
    

}

class Solution
{
public:
    int longestPalinSubseq(string& x)
    {
        string y = x;
        reverse(y.begin(), y.end());

        int m = x.size();
        int n = y.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto i = 1; i <= m; i++)
        {
            for (auto j = 1; j <= n; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        

        return dp[m][n];
    }
};