#include <stdio.h>
#include <string.h>
#include <array>

int CharSeparate(char* result[],char* str, const char* key){
    int count = 0;
    char *ptr;

    // keyを区切りに文字列を分割
    // 1回目
    ptr = strtok(str, key);
    result[0] = ptr;
    printf("%s\n", ptr);
    count++;

    //2回目以降
    while(ptr != NULL){
        ptr = strtok(NULL, key);
        result[count] = ptr;
        printf("%s\n", ptr);
        count++;
    }

    return 0;
}

char* CharArrMerge(char* chararr[], int chararr_num,const char* insert_str,int insert_num,const char* merge_str){
    char* result;
    for(size_t i = 0; i < chararr_num; ++i){
        if(i == insert_num){
            strcat(result, insert_str);
            strcat(result, merge_str);
        }
        if(i == chararr_num){
            strcat(result, chararr[i]);
            break;
        }
        strcat(result, chararr[i]);
        strcat(result, merge_str);
    }
    return result;
}

int main(void){
    char org_word[100] = "WWWW@XXX@YY@Z.csv";
    char *ptr[4];

    CharSeparate(ptr,org_word, "@");

    char* result = CharArrMerge(ptr, 4,"FLOW1", 2, "@");

    printf("%s\n", result);

    return 0;
}



