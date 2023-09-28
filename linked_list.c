#include<stdio.h>

struct linked_list
{
    int val;
    struct linked_list *next;
};

struct linked_list* addTwoNumbers(struct linked_list* l1, struct linked_list* l2){
    // get how many step in l1
    int l1_step = 0;
    struct linked_list *temp1;
    temp1 = l1;
    while(1){
        if(temp1->next == NULL){
            break;
        }
        temp1 =temp1->next;
        l1_step++;
    }
    // get how many step in l2
    int l2_step = 0;
    struct linked_list *temp2;
    temp2 = l2;
    while(1){
        if(temp2->next == NULL){
            break;
        }
        temp2 =temp2->next;
        l2_step++;
    }
    // get value that is represented by l1
    int val_l1 = 0;
    struct linked_list *temp1_;
    temp1_ = l1;
    for(int i = 0; i<= l1_step; i++){
        int val = temp1_->val;
        val_l1 += (val * pow(10, i));
        temp1_ = temp1_->next;
    }
    // get value that is represented by l2
    int val_l2 = 0;
    struct linked_list *temp2_;
    temp2_ = l2;
    for(int i = 0; i<= l2_step; i++){
        int val = temp2_->val;
        val_l2 += (val * pow(10, i));
        temp2_ = temp2_->next;
    }

    int sum = val_l1  + val_l2 + 2; // val_l1 and val_l2 is 1 decreased
    // get the number of digits in sum
    int number = sum;
    int size_sum = 0;
    while (number > 0) {
        // int digit = number % 10; // Get the rightmost digit
        number /= 10; // Remove the rightmost digit
        size_sum++;
    }
   // printf("sum : %d , digit : %d", sum, size_sum);
   /*struct linked_list *return_list = malloc(sizeof(struct linked_list));
    for(int i = 0; i<=size_sum; i++){
        return_list->val = sum % 10;
        return_list->next = malloc(sizeof(struct linked_list));
        return_list = return_list->next;
        sum /= 10;
    }*/

    // arrange the returned linked list
    struct linked_list* return_list = NULL;
    struct linked_list* current = NULL;
    struct linked_list* previous = NULL;

    for (int i = 0; i <= size_sum; i++) {
        // Create a new node for the current digit
        current = malloc(sizeof(struct linked_list));
        current->val = sum % 10;
        current->next = NULL;

        if (return_list == NULL) {
            // If it's the first node, set it as the head of the list
            return_list = current;
        } else {
            // Link the previous node to the current node
            previous->next = current;
        }

        // Update the previous node for the next iteration
        previous = current;

        // Move to the next digit of the number
        sum /= 10;
    }
    return return_list;

}
int main(){
    // create l1
    struct linked_list *l1 = malloc(sizeof(struct linked_list));
    l1->val = 2;
    l1->next = malloc(sizeof(struct linked_list));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct linked_list));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;
    
    // create l2
    struct linked_list *l2 = malloc(sizeof(struct linked_list));
    l2->val = 5;
    l2->next = malloc(sizeof(struct linked_list));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct linked_list));
    l2->next->next->val = 4;
    l2->next->next->next = malloc(sizeof(struct linked_list));
    l2->next->next->next->val = 9;
    l2->next->next->next->next = NULL;

    int step = 0;
    struct linked_list *result;
    result = addTwoNumbers(l1, l2);
    // int x1 =  result->val;
    // int x2 = result->next->val;
    // int x3 = result->next->next->val;
    // int x4 = result->next->next->next->val;
    // printf("digits %d %d %d %d\n", x1,x2,x3,x4);

    int sum_nums = 0;
    while(1){
        if(result->next == NULL){
            break;
        }
        int val = result->val;
        sum_nums += (val * pow(10, step));
        result =result->next;
        step++;
    }
    printf("sum : %d", sum_nums);

    free(l1->next->next);
    free(l1->next);
    free(l1);
    free(l2->next->next);
    free(l2->next);
    free(l2);

    return 0;
}