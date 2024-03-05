#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode* h = head;
                while (h != slow)
                {
                    h = h->next;
                    slow = slow->next;
                }
                return h;
            }
        }
        return NULL;
    }
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head != nullptr)
            reverse(head, nullptr, head);
        return head;
    }
    void reverse(ListNode*& head, ListNode* prev, ListNode* curr)
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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* first = head;
        ListNode* temp = head;
        ListNode* last = head;

        int count = 1;
        while (count != k)
        {
            count++;
            first = first->next;
        }
        int size = 0;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        size = size - k;

        while (last != nullptr && size != 0)
        {
            last = last->next;
            size--;
        }
        swap(last->val, first->val);
        return head;
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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* head2 = head;
        ListNode* newHead = nullptr;
        ListNode* temp;
        int sum = 0;
        while (head2 != nullptr)
        {
            if (head2->val == 0 && head2 != head)
            {
                ListNode* newNode = new ListNode(sum);
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
                sum = 0;
            }
            sum += head2->val;
            head2 = head2->next;
        }
        return newHead;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        ListNode* ans;
        if (list1->val < list2->val)
        {
            ListNode* newNode = new ListNode(list1->val);
            ans = newNode;
            list1 = list1->next;
        }
        else
        {
            ListNode* newNode = new ListNode(list2->val);
            ans = newNode;
            list2 = list2->next;
        }
        ListNode* curr = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                ListNode* newNode = new ListNode(list1->val);
                curr->next = newNode;
                curr = curr->next;
                list1 = list1->next;
            }
            else
            {
                ListNode* newNode = new ListNode(list2->val);
                curr->next = newNode;
                curr = curr->next;
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {

            ListNode* newNode = new ListNode(list1->val);
            curr->next = newNode;
            curr = curr->next;
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            ListNode* newNode = new ListNode(list2->val);
            curr->next = newNode;
            curr = curr->next;
            list2 = list2->next;
        }
        return ans;
    }
};

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        return merge_sort(head);
    }
    ListNode* merge_sort(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* midElement = mid(head);

        ListNode* right = merge_sort(midElement);

        ListNode* left = merge_sort(head);

        return merge(left, right);
    }
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        ListNode* ans;
        if (list1->val < list2->val)
        {
            ListNode* newNode = list1;
            list1 = list1->next;
            ans = newNode;
            ans->next = nullptr;
        }
        else
        {
            ListNode* newNode = list2;
            list2 = list2->next;
            ans = newNode;
            ans->next = nullptr;
        }
        ListNode* curr = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                ListNode* newNode = list1;
                list1 = list1->next;
                curr->next = newNode;
                curr = curr->next;
                curr->next = nullptr;
            }
            else
            {
                ListNode* newNode = list2;
                list2 = list2->next;
                curr->next = newNode;
                curr = curr->next;
                curr->next = nullptr;
            }
        }
        while (list1 != nullptr)
        {

            ListNode* newNode = list1;
            list1 = list1->next;
            curr->next = newNode;
            curr = curr->next;
            curr->next = nullptr;
        }
        while (list2 != nullptr)
        {
            ListNode* newNode = list2;
            list2 = list2->next;
            curr->next = newNode;
            curr = curr->next;
            curr->next = nullptr;
        }
        return ans;
    }
    ListNode* mid(ListNode* slow)
    {
        bool flag = true;
        ListNode* fast = slow;
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
        ListNode* mid = slow->next;
        slow->next = nullptr;

        return mid;
    }
};
class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == right)
        {
            return head;
        }
        ListNode* prev = head;
        ListNode* prevPrev = nullptr;
        ListNode* next = head;
        while (--left)
        {
            prevPrev = prev;
            prev = prev->next;
        }
        while (--right)
        {
            next = next->next;
        }
        if (prevPrev != nullptr)
        {
            prevPrev->next = nullptr;
        }
        ListNode* r_head = prev;
        ListNode* r_tail = next;
        ListNode* lastNext = next->next;
        r_tail->next = nullptr;
        reverse(r_head, nullptr, r_head, r_tail);
        r_tail->next = lastNext;

        if (prevPrev == nullptr)
        {
            return r_head;
        }
        else
        {
            prevPrev->next = r_head;
            return head;
        }
    }

    void reverse(ListNode*& head, ListNode* prev, ListNode* curr, ListNode*& tail)
    {
        if (curr == nullptr)
        {
            tail = head;
            head = prev;
            return;
        }
        reverse(head, curr, curr->next, tail);
        curr->next = prev;
    }
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* mid = this->mid(head);
        this->reverse(mid, nullptr, mid);

        ListNode* h1 = head;
        ListNode* h2 = mid;

        while (h1 != nullptr && h2 != nullptr)
        {
            ListNode* temp = h1->next;
            h1->next = h2;
            h1 = temp;

            ListNode* temp2 = h2->next;
            h2->next = h1;
            h2 = temp2;
        }

        if (h1 != nullptr)
            h1->next = nullptr;
    }
    ListNode* mid(ListNode* slow)
    {
        bool flag = true;
        ListNode* fast = slow;
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
        ListNode* mid = slow->next;

        return mid;
    }
    void reverse(ListNode*& head, ListNode* prev, ListNode* curr)
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

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1)
        {
            return head;
        }
        bool flag = true;
        ListNode* curr = head;
        ListNode* r_head = head;
        ListNode* prev = nullptr;
        ListNode* ans = nullptr;
        while (curr != nullptr)
        {
            int index = k;

            while (--index)
            {
                curr = curr->next;
                if (curr == nullptr)
                {
                    return ans;
                }
            }
            ListNode* r_next = curr->next;

            curr->next = nullptr;
            reverse(r_head, nullptr, r_head, curr);
            curr->next = r_next;

            if (prev != nullptr)
            {
                prev->next = r_head;
            }
            if (flag)
            {
                flag = false;
                ans = r_head;
            }
            prev = curr;
            r_head = curr->next;
            curr = r_head;
        }
        return ans;
    }

    void reverse(ListNode*& head, ListNode* prev, ListNode* curr, ListNode*& tail)
    {
        if (curr == nullptr)
        {
            tail = head;
            head = prev;
            return;
        }
        reverse(head, curr, curr->next, tail);
        curr->next = prev;
    }
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (k == 0 || head == nullptr)
        {
            return head;
        }
        k = k % size(head);
        ListNode* lastPrev = head;
        if (lastPrev->next == nullptr)
        {
            return head;
        }

        while (k--)
        {
            while (lastPrev->next->next != nullptr)
            {
                lastPrev = lastPrev->next;
            }
            ListNode* last = lastPrev->next;
            lastPrev->next = nullptr;
            last->next = head;
            head = last;
            lastPrev = head;
        }
        return head;
    }
    int size(ListNode* head)
    {
        int count = 0;
        while (head != nullptr)
        {
            head = head->next;
            count++;
        }
        return count;
    }
};
class node
{
public:
    int data;
    node* next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class MyLinkedList
{

public:
    node* head;
    node* tail;

    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    int size()
    {
        int count = 0;
        node* ptr = this->head;
        while (ptr != nullptr)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }

    int get(int index)
    {
        node* temp = this->head;
        while (temp != nullptr)
        {
            if (index-- == 0)
            {
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        node* newNode = new node(val);
        newNode->next = this->head;
        this->head = newNode;
        if (tail == nullptr)
            this->tail = this->head;
    }

    void addAtTail(int val)
    {
        node* newNode = new node(val);
        if (this->tail == nullptr)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index > this->size())
        {
            return;
        }
        else if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else if (index == this->size())
        {
            addAtTail(val);
            return;
        }
        node* newNode = new node(val);
        node* ptr = this->head;
        node* prev = nullptr;

        while (ptr != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        if (ptr == nullptr)
            return;
        prev->next = newNode;
        newNode->next = ptr;
    }

    void deleteAtIndex(int index)
    {
        if (this->head == nullptr || index >= this->size() || index < 0)
        {
            return;
        }
        node* ptr = this->head;
        node* prev = nullptr;
        if (index == 0)
        {
            this->head = ptr->next;
            delete ptr;
            if (this->head == nullptr)
                this->tail = this->head;
            return;
        }

        while (ptr != nullptr && index > 0)
        {
            prev = ptr;
            ptr = ptr->next;
            index--;
        }
        prev->next = ptr->next;
        if (prev->next == nullptr)
            this->tail = prev;
        delete ptr;
    }
};

// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;
        Node* ptr = head;

        while (ptr)
        {
            m[ptr] = new Node(ptr->val);

            ptr = ptr->next;
        }
        for (auto& i : m)
        {
            if (i.first->next)
            {
                auto itn = m.find(i.first->next);
                if (itn != m.end())
                    i.second->next = itn->second;
            }
            if (i.first->random)
            {
                auto itr = m.find(i.first->random);
                if (itr != m.end())
                    i.second->random = itr->second;
            }
        }
        return m[head];
    }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l3;
        ListNode* head;
        bool flag = true;

        int c = 0;

        while (l1 and l2)
        {
            c += l1->val + l2->val;

            ListNode* temp = new ListNode(c % 10);
            c /= 10;

            if (flag)
            {
                flag = false;
                head = temp;
                l3 = temp;
            }
            else
            {
                l3->next = temp;
                l3 = l3->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l2)
        {
            c += l2->val;

            ListNode* temp = new ListNode(c % 10);
            c /= 10;

            l3->next = temp;
            l2 = l2->next;
            l3 = l3->next;
        }
        while (l1)
        {
            c += l1->val;

            ListNode* temp = new ListNode(c % 10);
            c /= 10;

            l3->next = temp;
            l1 = l1->next;
            l3 = l3->next;
        }

        if (c > 0) l3->next = new ListNode(c);

        return head;
    }
};

class LRUCache
{
    unordered_map<int, int> m;
    list<int> l;
    int cap;
public:
    LRUCache(int cap)
    {
        this->cap = cap;
    }

    int get(int key)
    {
        if (m.count(key))
        {
            
            return m[key];
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (this->cap <= m.size())
        {
            m.erase(l.front());
            l.erase(l.begin());
        }
        if (!m.count(key)) l.push_back(key);
        else
        {
            if (l.back() != key)
            {
                auto it = l.begin();
                while (*it != key)
                {
                    it = next(it);
                }
                l.erase(it);
                l.push_back(key);
            }
        }

        m[key] = value;
    }
};