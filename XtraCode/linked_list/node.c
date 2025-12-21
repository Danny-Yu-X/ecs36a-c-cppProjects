#include <stdlib.h>
#include "node.h"

Node* create_node(int value){
    Node* new_node = (Node*)malloc(1*sizeof(Node));
    new_node ->value = value;
    new_node->next = NULL;
    return new_node;
}