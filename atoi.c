#include<stdio.h>

int myAtoi(char * s){
    long long int result = 0;
    int length_inp = strlen(s);
    int *arr = malloc(sizeof(int));
    int positive_sign = 1; // 1 for positive and 0 for negative
    int num_index = 0;
    for(int i = 0; i< length_inp; i++){
        char c = s[i];
        if(c != ' '){
            if (c >= '0' && c <= '9') {
                arr = realloc(arr,(num_index + 1) * sizeof(int));
                int digit = c - '0';
                arr[num_index] = digit;
                num_index++;
                
            }
            else if(c == '-'){
                positive_sign = -1;
            }// if the string starts with a letter
            else{
                result = 0;
                break;
            }
        }
    }
    for(int k = num_index; k >0; k--){
        result += arr[num_index - k] * (int)pow(10,k -1);
    }
    free(arr); // free the arr
    result *= positive_sign; // add sign
    // check other conditions [-2^31, 2^31 - 1] range for number
    if(result < -2147483648LL){ // this loop is not working
        result = -2147483648LL;
        printf("Here\n");
    }
    if(result > ((int)pow(2,31) - 1)){
        result =(int) pow(2,31) - 1;
    }
    return result;
}

int main(int argc, char **argv){

    char num[10] = "-91283472332";
    int number =  myAtoi(num);
    printf("%d", number);
    printf("\n%d",(int) pow(-2,31));
    return 0;
}