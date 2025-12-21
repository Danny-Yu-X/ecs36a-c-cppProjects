#include "linked_list.h"

int main(){
    int values[] = {1, 2, 10, 25};
    int len = 4;
    LinkedList good_name = create_list_from_array(values, len);
    print_list(&good_name);
    delete_list(&good_name);
    return 0;
}