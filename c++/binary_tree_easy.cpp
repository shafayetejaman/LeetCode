#include <bits/stdc++.h>

using namespace std;

int main()
{

    return 0;
}
// template <typename T>
// class TreeNode
// {
// public:
//     T data;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

void print(TreeNode* ptr, vector<int>& v)
{
    if (ptr == nullptr)
    {
        return;
    }
    print(ptr->left, v);
    print(ptr->right, v);
    v.push_back(ptr->val);
}
vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here
    vector<int> v;
    print(root, v);
    return v;
}

vector<int> getLevelOrder(BinaryTreeNode<int>* root)
{
    //  Write your code here.
    if (root == nullptr)
    {
        return {};
    }
    vector<int> v;
    queue<BinaryTreeNode<int>*> que;
    que.push(root);
    while (!que.empty())
    {
        BinaryTreeNode<int>* curr = que.front();
        que.pop();

        v.push_back(curr->val);

        if (curr->left)
        {
            que.push(curr->left);
        }
        if (curr->right)
        {
            que.push(curr->right);
        }
    }
    return v;
}
long long left_sum(BinaryTreeNode<int>* ptr)
{
    if (ptr == nullptr)
        return 0;
    long long sum = 0;
    if (ptr->left)
        sum = ptr->left->data;

    sum += left_sum(ptr->left);
    sum += left_sum(ptr->right);
    return sum;
}

long long leftSum(BinaryTreeNode<int>* root)
{
    return left_sum(root);
}

// void level(TreeNode<int> *root, int searchedValue, int count, int &v)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     if (root->val == searchedValue)
//     {
//         v = count;
//         return;
//     }
//     level(root->left, searchedValue, count + 1, v);
//     level(root->right, searchedValue, count + 1, v);
// }
// int nodeLevel(TreeNode<int> *root, int searchedValue)
// {
//     // Write your code here.
//     int v = 0;
//     level(root, searchedValue, 1, v);
//     return v;
// }

// vector<int> getLeftView(TreeNode<int> *root)
// {
//     //    Write your code here
//     if (!root)
//     {
//         return {};
//     }
//     vector<int> v;
//     queue<pair<TreeNode<int> *, int>> que;
//     v.push_back(root->data);
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
//             v.push_back({curr->data});
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
//     return v;
// }

bool isNodePresent(BinaryTreeNode<int>* curr, int x)
{
    // Write your code here

    if (curr == nullptr)
    {
        return false;
    }
    if (curr->data == x)
    {
        return true;
    }
    bool v1 = isNodePresent(curr->right, x);
    bool v2 = isNodePresent(curr->left, x);
    return v1 || v2;
}

bool isSpecialBinaryTree(BinaryTreeNode<int>* curr)
{
    if (curr == nullptr)
    {
        return false;
    }
    if (!curr->left && !curr->right)
    {
        return true;
    }
    bool v1 = isSpecialBinaryTree(curr->right);
    bool v2 = isSpecialBinaryTree(curr->left);
    return v1 && v2;
}

class Solution
{
public:
    bool isUnivalTree(TreeNode* root)
    {
        int val = root->val;
        return isUT(root, val);
    }
    bool isUT(TreeNode* curr, int val)
    {
        if (curr == nullptr)
        {
            return true;
        }
        if (curr->val != val)
        {
            return false;
        }
        bool v1 = isUT(curr->right, int val);
        bool v2 = isUT(curr->left, int val);
        return v1 && v2;
    }
};
class Solution
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1, v2;
        count(root1, v1);
        count(root2, v2);
        if (v1.size() != v2.size())
        {
            return false;
        }
        for (auto i = 0; i < v1.size(); i++)
        {
            if (v2[i] != v1[i])
            {
                return false;
            }
        }
        return true;
    }
    void count(TreeNode* curr, vector<int>& v)
    {
        if (curr == nullptr)
        {
            return;
        }
        if (!curr->left && !curr->right)
        {
            return v.push_back(curr->val);
        }
        count(curr->right, v);
        count(curr->left, v);
    }
};
class Solution
{
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2)
    {

        return count(root1, root2);
    }

    bool count(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && root2 || root1 && !root2)
        {
            return false;
        }
        else if (!root1 && !root2)
        {
            return true;
        }
        if (root1->val != root2->val)
        {
            return false;
        }
        bool left = count(root1->left, root2->left);
        bool right = count(root1->right, root2->right);
        return left && right;
    }
};
class Solution
{
public:
    int findTilt(TreeNode* root)
    {
        vector<int> v;
        v = dif(root, v);
        int v = 0;
        for (const auto& i : v)
        {
            v += i;
        }
        return v;
    }
    void dif(TreeNode* curr, vector<int>& v)
    {
        if (curr == nullptr)
        {
            return;
        }
        int left = sum(curr->left);
        int right = sum(curr->right);

        v.push_back(abs(left - right));

        dif(curr->left, v);
        dif(curr->right, v);
    }

    int sum(TreeNode* curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        int sum1 = curr->val;

        sum1 += sum(curr->left);
        sum1 += sum(curr->right);
        return sum;
    }
};
class Solution
{
public:
    int findTilt(TreeNode* root)
    {
        int v = 0;
        dif(root, v);

        return v;
    }
    int dif(TreeNode* curr, int& v)
    {
        if (curr == nullptr)
        {
            return 0;
        }
        int left = dif(curr->left, v);
        int right = dif(curr->right, v);

        v += abs(left - right);
        int sum = curr->val + left + right;
        return sum;
    }
};
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root)
            return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root || (!root->left && !root->right))
        {
            return root;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode* curr = que.front();
            que.pop();

            swap(curr->right, curr->left);

            if (curr->left)
                que.push(curr->left);

            if (curr->right)
                que.push(curr->right);
        }
        return root;
    }
};
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        return max_hight(root, 0);
    }
    int max_hight(TreeNode* curr, int count)
    {
        if (curr == nullptr)
        {
            return count;
        }
        int left = max_hight(curr->left, count + 1);
        int right = max_hight(curr->right, count + 1);
        return max(left, right);
    }
};

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int dep = 1;
        while (!st.empty())
        {
            TreeNode* curr = st.top()->first;
            int currHight = st.top()->second;
            st.pop();

            dep = max(dep, currHight);
            if (curr->left)
            {
                st.push({curr->left, currHight + 1});
            }
            if (curr->right)
            {
                st.push({curr->right, currHight + 1});
            }
        }
        return dep;
    }
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution
{
public:
    int max_hight(TreeNode* root, int& max)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = max_hight(root->left, max);
        int right = max_hight(root->right, max);
        max = std::max(left + right, max);
        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        // Write Your Code Here.
        int max = 0;
        if (!root)
        {
            return 0;
        }
        max_hight(root, max);

        return max;
    }
};
class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;

        return (abs(hight(root->left) - hight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
    int hight(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left = hight(root->left);
        int right = hight(root->right);

        return std::max(left, right) + 1;
    }
};
class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {

        return hight(root).first;
    }
    pair<bool, int> hight(TreeNode* root)
    {
        if (!root)
        {
            return {true, 0};
        }

        pair<bool, int> left = hight(root->left);
        pair<bool, int> right = hight(root->right);
        bool dif = abs(left.second - right.second) <= 1;

        return {(left.first && right.first && dif), max(left.second, right.second) + 1};
    }
};

class Solution
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root)
        {
            return false;
        }
        if (root->val == subRoot->val)
        {
            if (same(root, subRoot))
                return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }

    bool same(TreeNode* a, TreeNode* b)
    {
        if (!a && !b)
        {
            return true;
        }
        else if (!a || !b)
        {
            return false;
        }
        if (a->val != b->val)
            return false;

        bool left = same(a->left, b->left);
        bool right = same(a->right, b->right);
        return left && right;
    }
};
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }

        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            if (curr->right)
            {
                st.push(curr->right);
            }
            if (curr->left)
            {
                st.push(curr->left);
            }
        }
        return ans;
    }
};
class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return fun(nums, 0, nums.size() - 1);
    }
    TreeNode* fun(vector<int>& v, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode* newNode = new TreeNode(v[mid]);

        TreeNode* left = fun(v, l, mid - 1);
        TreeNode* right = fun(v, mid + 1, r);
        newNode->left = left;
        newNode->right = right;
        return newNode;
    }
};
class Solution
{
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (!root)
            return 0;
        int sum = 0;
        if (root->val >= low && root->val <= high)
            sum += root->val;

        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};

class Solution
{
public:
    vector<int> v;
    bool findTarget(TreeNode* root, int k)
    {
        if (!root->left && !root->right)
            return false;

        find_helper(root);
        return twoSum(v, k);
    }
    void find_helper(TreeNode* root)
    {
        if (!root)
            return;
        v.push_back(root->val);
        find_helper(root->left);
        find_helper(root->right);
    }
    bool twoSum(vector<int>& arr, int tar)
    {
        int i = 0;
        int j = arr.size() - 1;
        int val;

        while (i <= j)
        {
            val = arr[i] + arr[j];
            if (val == tar)
            {
                return true;
            }
            if (val > tar)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};
class Solution
{
public:
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* nextPtr;
    TreeNode* prevPtr;

    bool findTarget(TreeNode* root, int k)
    {
        push_all_left(root);
        push_all_right(root);
        int i = next();
        int j = prev();
        while (!st1.empty() && !st2.empty())
        {
            if (nextPtr == prevPtr)
            {
                return false;
            }
            int sum = i + j;
            if (sum == k)
            {
                return true;
            }
            if (sum > k)
            {
                j = prev();
            }
            else
            {
                i = next();
            }
        }
        return false;
    }

    int next()
    {
        TreeNode* temp = st1.top();
        st1.pop();
        push_all_left(temp->right);
        nextPtr = temp;
        return temp->val;
    }

    int prev()
    {
        TreeNode* temp = st2.top();
        st2.pop();
        push_all_right(temp->left);
        prevPtr = temp;
        return temp->val;
    }

    void push_all_left(TreeNode* root)
    {
        while (root)
        {
            st1.push(root);
            root = root->left;
        }
    }

    void push_all_right(TreeNode* root)
    {
        while (root)
        {
            st2.push(root);
            root = root->right;
        }
    }
};
class Solution
{
public:
    vector<int> v;
    int getMinimumDifference(TreeNode* root)
    {
        int ans = INT_MAX;
        fun(root);
        for (auto i = 0; i < v.size() - 1; i++)
        {
            ans = min(ans, abs(v[i] - v[i + 1]));
        }
        return ans;
    }
    void fun(TreeNode* root)
    {
        if (!root)
            return;
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
};

class Solution
{
public:
    void fun(TreeNode* root, TreeNode*& pre, int& ans)
    {
        if (!root)
            return;

        fun(root->left, pre, ans);
        if (pre)
        {
            ans = min(ans, root->val - pre->val);
        }
        pre = root;
        fun(root->right, pre, ans);
    }

    int getMinimumDifference(TreeNode* root)
    {
        TreeNode* pre = nullptr;
        int ans = INT_MAX;
        fun(root, pre, ans);
        return ans;
    }
};
class Solution
{
public:
    stack<TreeNode*> st;

    int getMinimumDifference(TreeNode* root)
    {
        push_all_left(root);

        int i = next();
        int j = next();
        int ans = j - i;

        while (j != INT_MAX)
        {
            ans = min(ans, j - i);
            i = j;
            j = next();
        }

        return ans;
    }

    int next()
    {
        if (st.empty())
            return INT_MAX;
        TreeNode* temp = st.top();
        st.pop();
        push_all_left(temp->right);
        return temp->val;
    }

    void push_all_left(TreeNode* root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
};
class Solution
{
public:
    TreeNode* newTree = nullptr;
    TreeNode* curr = nullptr;
    TreeNode* increasingBST(TreeNode* root)
    {
        fun(root);
        curr->right = nullptr;
        curr->left = nullptr;
        return newTree;
    }
    void fun(TreeNode* root)
    {
        if (!root)
            return;
        fun(root->left);
        if (!newTree)
        {
            newTree = root;
            curr = root;
        }
        else
        {
            curr->right = root;
            curr->left = nullptr;
            curr = curr->right;
        }
        fun(root->right);
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
// TreeNode<int> *insertionInBST(TreeNode<int> *root, int val)
// {

//     if (!root)
//     {
//         return new TreeNode<int>(val);
//     }
//     if (root->val < val)
//     {
//         root->right = insertionInBST(root->right, val);
//     }
//     else
//     {
//         root->left = insertionInBST(root->left, val);
//     }
//     return root;
// }


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        auto root2 = copy(root);
        reverse(root2);
        return is_same(root, root2);
    }
    bool is_same(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 and !root2) return true;
        if ((root1 and !root2) or (!root1 and root2)) return false;
        if (root1->val != root2->val) return false;

        return is_same(root1->left, root2->left) and is_same(root1->right, root2->right);
    }

    TreeNode* copy(TreeNode* root)
    {
        if (!root) return nullptr;

        TreeNode* newNode = new TreeNode(root->val);
        newNode->left = copy(root->left);
        newNode->right = copy(root->right);

        return newNode;
    }
    TreeNode* reverse(TreeNode* root)
    {
        if (!root) return nullptr;

        TreeNode* temp = root->left;
        root->left = reverse(root->right);
        root->right = reverse(temp);

        return root;
    }
};

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root or (!root->left and !root->right)) return true;
        if (!root->left or !root->right) return false;
        return is_same(root->left, root->right);
    }
    bool is_same(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 and !root2) return true;
        if ((root1 and !root2) or (!root1 and root2)) return false;
        if (root1->val != root2->val) return false;

        return is_same(root1->left, root2->right) and is_same(root1->right, root2->left);
    }

};

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root or (!root->left and !root->right)) return true;
        if (!root->left or !root->right) return false;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root->left);
        st2.push(root->right);

        while (!st1.empty() and !st2.empty())
        {
            TreeNode* left = st1.top();
            TreeNode* right = st2.top();

            st1.pop();
            st2.pop();

            if (left->val != right->val) return false;

            if (left->left) st1.push(left->left);
            if (right->right) st2.push(right->right);

            if (right->left) st1.push(right->left);
            if (left->right) st2.push(left->right);
        }

        return st1.empty() and st2.empty();
    }

};

class Solution
{
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root) return false;

        if (!root->left and !root->right and targetSum - root->val == 0) return true;
        
        return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
    }
};