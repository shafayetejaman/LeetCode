#include <bits/stdc++.h>
using namespace std;

int main()
{


    return 0;
}

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x == 1 || x == 2 || x == 3)
            return 1;
        int mid;
        int l = 4;
        int r = x / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return r;
    }
};
class Solution
{
public:
    char nextGreatestLetter(vector<char>& lett, char tar)
    {
        int l = 0;
        int r = lett.size() - 1;
        char ans = lett[0];
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (lett[mid] > tar)
            {
                ans = lett[mid];
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for (const auto& i : matrix)
        {
            if (i.back() < target) continue;
            if (i.front() > target) break;
            if (binary_search(i.begin(), i.end(), target)) return true;
        }
        return false;
    }
};

class Solution
{
public:
    int minEatingSpeed(vector<int>& p, int h)
    {
        int r = *max_element(p.begin(), p.end());
        int l = 1;
        int result;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            double x = fun(p, mid);
            if (x <= h)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }

    double fun(vector<int>& p, int k)
    {
        double h = 0;
        for (auto& i : p)
        {
            h += ceil(double(i) / double(k));
        }
        return h;
    }

};

class Solution
{
public:
    int findMin(vector<int>& v)
    {
        int l = 0;
        int r = v.size() - 1;
        int min = INT_MAX;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            min = std::min(min, v[m]);

            if (v[l] <= v[r])
            {
                if (v[m] <= min)
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                if (v[m] >= v[l])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return min;
    }
};

class TimeMap
{
    map<string, vector<pair<int, string>>> m;
public:
    TimeMap()
    {

    }

    void set(string key, string value, int time)
    {
        m[key].push_back({time, value});
    }

    string get(string key, int time)
    {
        if (!m.count(key))
            return "";

        vector<pair<int, string>>& v = m[key];
        if (time > v.back().first) return v.back().second;

        auto it = upper_bound(v.begin(), v.end(), make_pair(time, ""), [](const pair<int, string>& a,const pair<int, string>& b) {return a.first < b.first;});

        if (it != v.end() and it->first == time) return it->second;
        if (it != v.begin()) return prev(it)->second;
        return "";
    }
};