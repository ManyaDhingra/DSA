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
    void insertTail(Node* &head, Node* &tail , int a){
        Node* temp = new Node(a);
        if (head == NULL){
            tail = temp;
            head = temp;
            return ; 
        }
        else{
            tail -> next = temp;
            tail = temp;
        }

    }
public:
    Node* copyRandomList(Node* head) {
        //original list
        // next pointer copy 
        Node* cHead = NULL;
        Node* cTail = NULL;
        Node* temp = head;

        while(temp != NULL){
            insertTail(cHead, cTail, temp -> val);
            temp = temp -> next;
        }

        // mapping for the list
        // random pointer copy
        unordered_map<Node* , Node*> oldNew;

        Node* originalNode = head;
        Node* cNode = cHead;

        while(originalNode != NULL && cNode != NULL){
            oldNew[originalNode] = cNode;
            originalNode = originalNode -> next;
            cNode = cNode ->next;
        
        }

        originalNode = head;
        cNode = cHead;

        while(originalNode != NULL){
            cNode -> random = oldNew[originalNode -> random];
            originalNode = originalNode -> next;
            cNode = cNode ->next;  
        }

        return cHead;
        
    }
};