#include <bits/stdc++.h>

using namespace std;

int main()
{


    return 0;
}
class Solution
{
public:
    int maxProfit(vector<int>& v)
    {
        int profit = 0;
        int l = 0;
        int r = 1;
        while (r < v.size())
        {
            if (v[l] > v[r])
            {
                l = r;
            }
            else
            {
                profit = max(profit, (v[r] - v[l]));
            }
            r++;
        }
        return profit;
    }
};

class Solution
{
public:
    unordered_map<char, int> map;
    int characterReplacement(string s, int k)
    {
        int r = 0;
        int l = 0;
        int ans = 0;
        while (r < s.size())
        {
            map[s[r]]++;
            while (((r - l + 1) - max_char()) > k)
            {
                if (map[s[l]] <= 1)
                    map.erase(s[l++]);
                else
                    map[s[l++]]--;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
    int max_char()
    {
        int m = 0;
        for (const auto& i : map)
        {
            m = max(m, i.second);
        }
        return m;
    }
};

class Solution
{
public:
    bool checkInclusion(string& s1, string& s2)
    {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> c1;
        unordered_map<char, int> c2;

        for (auto& i : s1)
        {
            c1[i]++;
        }
        for (auto i = 0; i < s1.size(); i++)
        {
            c2[s2[i]]++;
        }
        if (c1 == c2) return true;
        
        int l = 0;
        int r = s1.size();

        while (r < s2.size())
        {
            if (--c2[s2[l]] == 0) c2.erase(s2[l]);
            l++;
            c2[s2[r++]]++;
            
            if (c1 == c2) return true;
        }

        return false;
    }
};