#ifdef LINKED_LIST_H
    #define LINKED_LIST_H
    #include "node.h"
    #include <stdbool.h>

    typedef struct LinkedList_struct{
        Node* head;
        Node* tail;
        int len;
    }LinkedList;
    
    LinkedList create_empty_list();
    LinkedList create_list_from_array(int* values, int len);
    void delete_list(LinkedList* ll);

    void append(LinkedList* ll, int value);
    void prepend(LinkedList* ll, int value);
    void insert(LinkedList* ll, int value, int pos);

   
    int pop(LinkedList* ll, int position);
    int pop_front(LinkedList* ll);
    int pop_back(LinkedList* ll);
    bool remove(LinkedList* ll, int value);
    void print_list(LinkedList* ll);
    void swap_values(LinkedList* ll, int pos1, int pos2);

    bool is_empty(LinkedList* ll);
    Node* get_node_at(LinkedList* ll, int pos);
    

#endif