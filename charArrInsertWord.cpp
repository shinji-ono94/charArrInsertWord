#include <stdio.h>
#include <string.h>
#include <array>

int CharSeparate(char* result[],char* str, const char* key){
    int count = 0;
    char *ptr;

    // keyを区切りに文字列を分割
    // 1回目
    ptr = strtok(str, key);
    result[count] = ptr;
    printf("%s\n", result[0]);
    count++;

    //2回目以降
    while(ptr != NULL){
        ptr = strtok(NULL, key);
        result[count] = ptr;
        //printf("%s\n", ptr);
        count++;
    }

    return 0;
}

int CharArrMerge(char *result, char *chararr[], int chararr_num,char const* insert_str,int insert_num,char const* merge_str){
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
    return 0;
}

int CharArrInsertWord(char *result, char* str, char const* insert_str,int insert_num,const char* key){
    int count = 0;
    char *ptr;

    // keyを区切りに文字列を分割
    // 1回目
    ptr = strtok(str, key);
    strcat(result, ptr);
    count++;

    //2回目以降
    while(ptr != NULL){
        if(count == insert_num){
            strcat(result, insert_str);
            strcat(result, key);
        }
        ptr = strtok(NULL, key);
        strcat(result, ptr);
        if(ptr != NULL) strcat(result, key);
        //printf("%s\n", ptr);
        count++;
    }

    return 0;
}

int main(void){
    char org_word[] = "WWWW@XXX@YY@Z.csv";
    char *result;

    int retvl = CharArrInsertWord(result, org_word, "FLOW1", 2, "@");

    return 0;
}



