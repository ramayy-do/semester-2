// create by   : Rama Adhi Saputra
// Location    : Purwodadi, Central Java, Indonesia
// github      : ramayy-do
// Program     : Binary Tree
// last update : 2025-7-13

// program traversal inorder 

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;

    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};


int main() {
    ListNode* head = new ListNode(7);
    head->prev = new ListNode(5); 
    head->next = new ListNode(12);
    head->prev->prev = new ListNode(3); 
    head->prev->next = new ListNode(6); 
    head->prev->prev->prev = new ListNode(1); 
    head->prev->prev->next = new ListNode(4);
    head->next->prev = new ListNode(9);

    cout << "Struktur Tree:" << endl;
    cout<< "root                : "<< head->val << endl; //7
    cout<< "root child (left)   : "<< head->prev->val << endl; //5
    cout<< "root child (right)  : "<< head->next->val << endl; //12
    cout<< "'5'  child (left)   : "<< head->prev->prev->val << endl; //3
    cout<< "'5'  child (right)  : "<< head->prev->next->val << endl; //6
    cout<< "'3'  child (left)   : "<< head->prev->prev->prev->val << endl; //1
    cout<< "'3'  child (right)  : "<< head->prev->prev->next->val << endl; //4
    cout<< "'12' child (left)   : "<< head->next->prev->val << endl; //9
    
    // tampilan dari binary tree traversal inorder
    // cout yg diharapkan: 1 3 4 5 6 7 9 12
    cout << "-----------------------------------------" <<endl;
    cout<< "binary tree traversal inorder : "<< endl;
    cout<< head->prev->prev->prev->val; //1
    cout<< ", "<< head->prev->prev->val; //3
    cout<< ", "<< head->prev->prev->next->val; //4
    cout<< ", "<< head->prev->val; //5
    cout<< ", "<< head->prev->next->val; //6
    cout<< ", "<< head->val; //7
    cout<< ", "<< head->next->prev->val; //9
    cout<< ", "<< head->next->val; //12
    cout<< endl;
    
    // tampilan dari binary tree traversal postorder
    // cout yg diharapkan: 1 4 3 6 5 9 12 7
    cout << "-----------------------------------------" <<endl;
    cout<< "binary tree traversal postorder : "<< endl;
    cout<< head->prev->prev->prev->val; //1
    cout<< ", "<< head->prev->prev->next->val; //4
    cout<< ", "<< head->prev->prev->val; //3
    cout<< ", "<< head->prev->next->val; //6
    cout<< ", "<< head->prev->val; //5
    cout<< ", "<< head->next->prev->val; //9
    cout<< ", "<< head->next->val; //12
    cout<< ", "<<head->val; //7
    cout<< endl;

    // tampilan dari binary tree traversal postorder
    // cout yg diharapkan: 7 5 3 1 4 6 12 9
    cout << "-----------------------------------------" <<endl;
    cout<< "binary tree traversal preorder : "<< endl;
    cout<< head->val; //7
    cout<< ", "<< head->prev->val; //5
    cout<< ", "<< head->prev->prev->val; //3
    cout<< ", "<< head->prev->prev->prev->val; //1
    cout<< ", "<< head->prev->prev->next->val; //4
    cout<< ", "<< head->prev->next->val; //6
    cout<< ", "<< head->next->val; //12
    cout<< ", "<< head->next->prev->val; //9
    cout<< endl;

    return 0;
}
