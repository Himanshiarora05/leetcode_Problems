class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        // Create new nodes
        Node* temp = head;
        while (temp != NULL) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        // Connect next and random
        temp = head;
        while (temp != NULL) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};