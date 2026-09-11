class Solution {
public:
    typedef pair<int , ListNode*> in;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< in , vector<in> ,greater<in> > pq;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!= NULL) 
                pq.push({lists[i]->val , lists[i]});
        }
        ListNode* dummy = new ListNode(100);
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            ListNode* node = x.second;
            temp->next = node;
            temp = temp->next;

            if(node->next != NULL){
                pq.push({node->next->val , node->next});
            }
        }
        return dummy->next;
    }
};