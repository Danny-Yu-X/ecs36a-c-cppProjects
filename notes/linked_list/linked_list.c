#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "node.h"

LinkedList create_empty_list(){
    LinkedList ll; // ={ NULL, NULL, 0}
    ll.head = NULL;
    ll.rail = NULL;
    ll.len = 0;
    return ll;
}

LinkedList create_list_from_array(int* values, int len){
    LinkedList ll = create_empty_list();
    for(int i=0; i<len; ++i){
        append(&ll, values[i]);
    }
    return ll;
}

void delete_list(LinkedList* ll){
    if(is_empty(ll)){
        return;
    }else{
        LinkedList rest = {ll->head, ll->tail, ll->len-1};
        delete_list(&rest);
        free(ll->head);
        ll->len-=1;
        if(ll->len==0){
            ll->head ==NULL;
            ll->tail==NULL;
        }
    }
    ll->len=0;
    ll->head=NULL;
    ll->tial=NULL;
}
void delete_list(LinkedList* ll){
    while(!is_empty(ll)){
        pop_front(ll);
    }
}
void delete_list_iterative(LinkedList* ll){
    Node* prev ==NULL;
    Node* cur = ll->head;
    while(cur!=Null){
        prev=cur;
        cur= cur->next;
        free(prev);
    }
}

void append(LinkedList* ll, int value){
    /*
        1. Create new node with value and next of NULL
        2. if list is empty
            2.1 set head and tail to new node
        3.itherwise
            3.1 set tail's next to new node
            3.2 set tail to point to new node
        4. increment len
    */
   Node* new_node = create_node(value, NULL);

   if(isempty(ll)){
    ll->head = new_node;
   }else{
    ll->tail->next = new_node;
   }
   ll->tail = new_node;
   ll->len += 1;
}

void prepend(LinkedList* ll, int value){
    /*
    1. if list is empty
        1.1 append value to end
    else
        2.1 make new node with value whose next is head
        2.2 set head to new node
        2.3 increment length
    */
   if(is_empty(ll)){
    append(ll, value);
   }else{
    Node* new_node = create_node(value, ll->head);
    ll->head = new_node;
    ll->len+=1;
   }
}

void insert(LinkedList* ll, int value, int pos){
    /*
        if insert pos is 0, prepend
        if pos is len, append
        otherwise
            let prev be node at pos -1 
            set new_node next to be prev next
            set prev next to be new_node
    */

    if(pos==0){
        prepend(ll, value);
    }else if(pos == ll->len){
        append(ll, value);
    }else{
        Node* prev = get_node_at(ll, pos-1);
        Node* new_node = create_node(value, prev->next);
        prev->next = new_node;
        ll->len +=1;
    }
}

int pop_front(LinkedList* ll){
    Node* old_head = ll->head;
    int return_val = ll->head->value;
    ll->head = ll->head->next;
    free(old_head);
    ll->len-=1;
    if(ll->len == 0){
        ll->tail==NULL;
    }
    return return_val;
}

int pop_back(LinkedList* ll){
    if(ll->len==1){
        return pop_front(ll);
    }else{
        Node* new_tail = get_node_at(ll, len-2);
        int return_val = ll->tail->value;
        free(ll->tail);
        ll->tail==new_tail;
        ll->len -= 1;
        return return_val;
    }
}

int pop(LinkedList* ll, int position){
    if(position==0){
        return pop_front(ll);
    }else if(position == ll->len-1){
        return pop_back(ll);
    }else{
        Node* prev = get_node_at(ll, position-1);
        Node* to_remove = prev->next;
        int return_val = to_remove->value
        prev->next = to_remove->next;
        free(to_remove);
        ll->len-=1;
        return return_val;
    }
}


bool is_empty(LinkedList* ll){
    return ll->head == NULL;
}


Node* get_node_at(LinkedList* ll, int pos){
    if(pos == 0){
        return ll->head;
    }else{
        LinkedList rest = {ll->head->next, ll->tail, ll->len-1};
        return get_node_at(rest, pos - 1);
    }
}

Node* get_node_at_iterative(LinkedList* ll, int pos){
    Node* cur = ll->head;
    for(int i = 0; i<pos; ++i){
        cur = cur->next;
    }
    return cur;
}
// bool remove(LinkedList* ll, int value){
//     int i =0;
//     Node* cur = ll->head; 
//     while(ll->head1!=NULL){
//         if(cur->value==value){
//             pop(ll,i);
//             return true;
//         }else{
//             ++i
//         }
//     }
//     return false;
// }

// bool remove(LinkedList* ll, int value){
//     if(is_empty(ll)){
//         return false;
//     }else if(ll->head->value == value){
//         pop_front(ll);
//         return true;
//     }else{
//         LinkedList rest = {ll->head->next, ll->tail, ll->len-1};
//         bool found = remove(&rest, value);
//         return found;
//     }
// }//is wrong

bool remove_iterative(LinkedList* ll, int value){
    Node* cur = ll->head;
    Node*prev = NULL;
    while(cur != NULL){
        if(cur->value==value){
            if(cur == ll->head){
                pop_front(ll);
                return true;
            }else{
                prev->next= cur->next;
                free(cur);
                ll->len-1;
                if(cur==ll->tail = prev){
                    ll->tail=prev;
                }
                return true;
            }
        }
        prev=cur;
        cur=cur->next;
    }
    return false;
}
void print_list(LinkedList* ll){
    if(is_empty(ll)){
        return;
    }else{
        printf("%d ", ll->head->value);
        LinkedList rest = {ll->head->next, ll->tail, ll->len-1};
        print_list(&rest);
    }
}
void print_list_iterative(LinkedList* ll){
    Node* cur = ll->head;
    while(cur!=NULL){
        printf("%d ", cur->value);
        cur = cur->next;
    }
}
void swap_values(LinkedList* ll, int pos1, int pos2){
    Node* first = get_node_at(ll, pos1);
    Node* second = get_node_at(ll, pos2);
    int temp = first->value;
    first->value=second->value;
    second->value=temp;
}

void swap_values_better(LinkedList* ll, int pos1, int pos2){
    Node* first = NULL;
    Node* second = NULL;
    Node* cur = ll->head;
    int small_index = pos1 < pos2 ? pos1 : pos2;
    int big_index = pos1 > pos2 ? pos1 : pos2;

    for(int i=0; i<big_index;++i){
        if(i==small_index){
            first = cur;
        }
        cur = cur->next;
    }
    second = cur;


    int temp = first->value;
    first->value=second->value;
    second->value=temp;
}