#ifdef NODE_H
    #define NODE_H

    typedef struct Node_struct{
        int value;
        struct Node_struct* next;
    }Node;

    Node* create_node(int value)
#endif