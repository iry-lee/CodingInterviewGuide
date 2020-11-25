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


list_node * check(list_node * head)
{
    //////在下面完成代码
    int ct = 0;
    vector<int> arr;
    list_node* ptr = head;
    while(ptr != nullptr){
        arr.push_back(ptr->val);
        ptr = ptr->next;
        ct++;
    }

    int i = (ct-1)/2, j = ct/2;
    bool flag = true;
    for(; i >= 0; i--, j++){
        if(arr[i] == arr[j]) continue;
        else{
            flag = false;
            break;
        }
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