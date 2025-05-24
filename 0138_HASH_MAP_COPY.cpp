/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * t  = head;
        unordered_map<Node*, Node*> mp;

        Node * prev = NULL;
        Node * first = NULL;
        while(t){
            Node * w = new Node(t->val);
            if(!first){
                first = w;
            }
            if(prev){
                prev->next = w;
            }
            mp[t] = w;
            prev = w;
            t = t->next;
        }

        t = head;
        Node * x = first;
        
        while(t){
            Node * w = mp[t->random];
            x->random = w;
            t = t->next;
            x = x->next;
        }

        return first;

    }
};
