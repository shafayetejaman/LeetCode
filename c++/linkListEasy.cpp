#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *ptr = head;
        if (ptr == nullptr)
        {
            return head;
        }
        while (ptr->next != nullptr)
        {
            ListNode *temp = ptr->next;
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
                delete temp;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *ptr = node;
        ListNode *temp = nullptr;
        ListNode *temp2 = nullptr;

        while (ptr->next != nullptr)
        {
            ptr->val = ptr->next->val;
            ptr = ptr->next;
            if (ptr->next->next == nullptr)
            {
                temp = ptr->next;
                temp2 = ptr;
            }
        }
        temp2->next = nullptr;
        delete temp;
    }
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *newHead = nullptr;
        ListNode *temp;
        while (head != nullptr)
        {
            if (head->val != val)
            {
                ListNode *newNode = new ListNode(head->val);
                if (newHead == nullptr)
                {
                    newHead = newNode;
                    temp = newHead;
                }
                else
                {
                    temp->next = newNode;
                    temp = temp->next;
                }
            }
            head = head->next;
        }
        return newHead;
    }
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *newList = nullptr;
        ListNode *curr = head;
        ListNode *tail = nullptr;

        while (curr != nullptr)
        {
            append(newList, curr->val, tail);
            curr = curr->next;
        }
        if (head != nullptr)
            reverse(head, nullptr, head);
        curr = head;
        while (curr != nullptr)
        {
            if (curr->val != newList->val)
            {
                return false;
            }
            newList = newList->next;
            curr = curr->next;
        }
        return true;
    }
    void append(ListNode *&head, int val, ListNode *&tail)
    {
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void reverse(ListNode *&head, ListNode *prev, ListNode *curr)
    {
        if (curr->next == nullptr)
        {
            head = curr;
            head->next = prev;
            return;
        }
        reverse(head, curr, curr->next);
        curr->next = prev;
    }
};
class Solution
{
public:
    bool isHappy(int n)
    {
        long long slow = n, fast = n;
        do
        {
            slow = sum(slow);
            fast = sum(sum(fast));

        } while (slow != fast);
        if (slow == 1)
        {
            return true;
        }
        return false;
    }
    long long sum(long long n)
    {
        long long sum = 0;

        string arr = to_string(n);

        for (const auto &i : arr)
        {
            sum += pow((i - '0'), 2);
        }
        return sum;
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
    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = this->mid(head);
        reverse(mid, nullptr, mid);
        while (mid != nullptr && head != nullptr)
        {
            if (mid->val != head->val)
            {
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;
    }
    ListNode *mid(ListNode *slow)
    {
        bool flag = true;
        ListNode *fast = slow;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if (flag)
            {
                flag = false;
                continue;
            }
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;

        return mid;
    }
    void reverse(ListNode *&head, ListNode *prev, ListNode *curr)
    {
        if (curr == nullptr)
        {
            head = prev;
            return;
        }
        reverse(head, curr, curr->next);
        curr->next = prev;
    }
};