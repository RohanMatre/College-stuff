#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:
    ListNode *doubleList(ListNode *head)
    {
        vector<int> numList;

        ListNode *temp = head;

        while (temp != nullptr)
        {
            numList.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> numList2;

        int rem = 0;

        for (int i = numList.size() - 1; i >= 0; i--)
        {
            int val = numList[i];
            val = val * 2;

            val += rem;

            string p = to_string(val);

            if (p.length() == 2)
            {
                numList2.push_back(p[1] - '0');
                rem = p[0] - '0';
            }
            else
            {
                numList2.push_back(p[0] - '0');
                rem = 0;
            }
        }

        if (rem > 0)
            numList2.push_back(rem);

        reverse(numList2.begin(), numList2.end());

        ListNode *prevNode = new ListNode();
        ListNode *tm = prevNode;

        for (int i = 0; i < numList2.size(); i++)
        {
            int valt = numList2[i];
            ListNode *nw = new ListNode();
            nw->val = valt;
            prevNode->next = nw;
            prevNode = nw;
        }

        return tm->next;
    }
};

int main()
{
    Solution solution;

    // Example usage:
    ListNode *head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    ListNode *result = solution.doubleList(head);

    // Print the result
    ListNode *temp = result;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
