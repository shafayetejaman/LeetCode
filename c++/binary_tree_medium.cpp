#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> v;
        queue<pair<TreeNode *, int>> que;
        v.push_back({});
        que.push({root, 1});
        int prevLevel = 1;
        while (!que.empty())
        {
            TreeNode *curr = que.front().first;
            int level = que.front().second;
            que.pop();

            if (prevLevel < level)
            {
                prevLevel = level;
                v.push_back({curr->val});
            }
            else
            {
                v.back().push_back(curr->val);
            }

            if (curr->left)
            {
                que.push({curr->left, level + 1});
            }
            if (curr->right)
            {
                que.push({curr->right, level + 1});
            }
        }
        return v;
    }
};
// template <typename T>

// class TreeNode
// {
// public:
//     T val;
//     TreeNode<T> *left;
//     TreeNode<T> *right;
//     TreeNode(T val)
//     {
//         this->val = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// vector<int> reverseLevelOrder(TreeNode<int> *root)
// {
//     if (!root)
//     {
//         return {};
//     }
//     vector<vector<int>> v;
//     queue<pair<TreeNode<int> *, int>> que;
//     v.push_back({});
//     que.push({root, 1});
//     int prevLevel = 1;
//     while (!que.empty())
//     {
//         TreeNode<int> *curr = que.front().first;
//         int level = que.front().second;
//         que.pop();

//         if (prevLevel < level)
//         {
//             prevLevel = level;
//             v.push_back({curr->val});
//         }
//         else
//         {
//             v.back().push_back(curr->val);
//         }

//         if (curr->left)
//         {
//             que.push({curr->left, level + 1});
//         }
//         if (curr->right)
//         {
//             que.push({curr->right, level + 1});
//         }
//     }
//     reverse(v.begin(), v.end());
//     for (auto &i : v)
//     {
//         reverse(i.begin(), i.end());
//     }

//     vector<int> result;
//     for (const auto &level : v)
//     {
//         for (const auto &num : level)
//         {
//             result.push_back(num);
//         }
//     }
//     return result;
// }
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> v;
        queue<pair<TreeNode *, int>> que;

        que.push({root, 1});
        int prevLevel = 0;
        while (!que.empty())
        {
            TreeNode *curr = que.front().first;
            int level = que.front().second;
            que.pop();

            if (prevLevel < level)
            {
                prevLevel = level;
                v.push_back({curr->val});
            }
            else
            {
                v.back().push_back(curr->val);
            }

            if (curr->left)
            {
                que.push({curr->left, level + 1});
            }
            if (curr->right)
            {
                que.push({curr->right, level + 1});
            }
        }
        vector<int> ans;
        for (const auto &i : v)
        {
            ans.push_back(i.back());
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        fun(root, 0, v);
        return v;
    }
    void fun(TreeNode *root, int level, vector<int> &v)
    {
        if (!root)
        {
            return;
        }
        if (level == v.size())
        {
            v.push_back(root->val);
        }
        fun(root->right, level + 1, v);
        fun(root->left, level + 1, v);
    }
};

class Solution
{
public:
    int count = 0;
    int goodNodes(TreeNode *root)
    {
        fun(root, root->val);
        return count;
    }
    void fun(TreeNode *root, int max)
    {
        if (!root)
            return;

        int curr_max = std::max(max, root->val);
        if (root->val >= max)
            count++;

        fun(root->left, curr_max);
        fun(root->right, curr_max);
    }
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root->left && !root->right)
            return true;
        return fun(root, LONG_MIN, LONG_MAX);
    }

    bool fun(TreeNode *root, long min, long max)
    {
        if (!root)
            return true;

        if (!(root->val > min && root->val < max))
        {
            return false;
        }

        return fun(root->left, min, root->val) && fun(root->right, root->val, max);
    }
};
class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        push_all(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        push_all(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
    void push_all(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};
