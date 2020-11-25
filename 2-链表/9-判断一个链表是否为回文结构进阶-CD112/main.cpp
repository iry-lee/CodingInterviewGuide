# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

// CD107反转单向链表
list_node * reverse_list(list_node * head)
{
    //////在下面完成代码
    list_node * tail_node = nullptr;
    list_node * head_node = head;
    while(true){
        list_node * temp = head_node->next;
        head_node->next = tail_node;
        tail_node = head_node;
        if(temp == nullptr) break;
        else head_node = temp;
    }
    return head_node;
}

list_node * check(list_node * head)
{
    //////在下面完成代码
    // 进阶的要求是时间复杂度为O(n)，空间复杂度为O(1)
    list_node *ptr = head;
    int ct = 0;
    while(ptr != nullptr){
        ptr = ptr->next;
        ct++;
    }

    // 找到后半段链表
    ptr = head;
    for(int i = 0; i < ct/2; i++){
        ptr = ptr->next;
    }

    list_node * ptr2 = reverse_list(ptr);
    ptr = head;
    bool flag = true;
    while(ptr2!=nullptr){
        if(ptr->val != ptr2->val){
            flag = false;
            break;
        }
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }

    if(flag) cout << "true";
    else cout << "false";
    return head;
}


int main ()
{
    int L, R;
    list_node * head = input_list();
    check(head);
    return 0;
}