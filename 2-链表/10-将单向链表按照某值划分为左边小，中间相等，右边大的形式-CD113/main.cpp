# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

int pivot;

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d%d", &n, &pivot);
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


list_node * list_partition(list_node * head, int pivot)
{
    //////在下面完成代码
    list_node * list1 = nullptr, *list2 = nullptr, *list3 = nullptr;
    list_node * ptr = head;
    list_node * ptr1, *ptr2, *ptr3;
    while(ptr!=nullptr){
        list_node * temp = ptr;
        if(ptr->val < pivot){
            if(list1 == nullptr) {
                list1 = ptr;
                ptr1 = list1;
            }
            else{
                ptr1->next = ptr;
                ptr1 = ptr1->next;
            }
        }
        else if(ptr->val == pivot){
            if(list2 == nullptr){
                list2 = ptr;
                ptr2 = list2;
            }
            else{
                ptr2->next = ptr;
                ptr2 = ptr2->next;
            }
        }
        else{
            if(list3 == nullptr){
                list3 = ptr;
                ptr3 = list3;
            }
            else{
                ptr3->next = ptr;
                ptr3 = ptr3->next;
            }
        }
        ptr = ptr->next;
        temp->next = nullptr;
    }

    // 然后将list1 2 3接起来
    list_node *newhead = list1, *newptr = list1;
    // 拼接上list2
    if(newhead == nullptr){
        newhead = list2;
        newptr = list2;
    }
    else{
        while(newptr->next != nullptr){
            newptr = newptr->next;
        }
        newptr->next = list2;
    }
    // 拼接上list3
    if(newhead == nullptr){
        newhead = list3;
    }
    else{
        while(newptr->next != nullptr){
            newptr = newptr->next;
        }
        newptr->next = list3;
    }

    newptr = newhead;
    while(newptr != nullptr) {
        cout << newptr->val << " ";
        newptr = newptr->next;
    }
    return newhead;
}


int main ()
{
    list_node * head = input_list();
    list_partition(head, pivot);
    return 0;
}