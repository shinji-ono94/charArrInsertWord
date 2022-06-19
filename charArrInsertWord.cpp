#include <stdio.h>
#include <string.h>
#include <array>

// TODO:エラー解消しなかった原因を考える。
// int CharSeparate(char* result[],char* str, const char* key){
//     int count = 0;
//     char *ptr;

//     // keyを区切りに文字列を分割
//     // 1回目
//     ptr = strtok(str, key);
//     result[count] = ptr;
//     printf("%s\n", result[0]);
//     count++;

//     //2回目以降
//     while(ptr != NULL){
//         ptr = strtok(NULL, key);
//         result[count] = ptr;
//         //printf("%s\n", ptr);
//         count++;
//     }

//     return 0;
// }

// int CharArrMerge(char *result, char *chararr[], int chararr_num,char const* insert_str,int insert_num,char const* merge_str){
//     for(size_t i = 0; i < chararr_num; ++i){
//         if(i == insert_num){
//             strcat(result, insert_str);
//             strcat(result, merge_str);
//         }
//         if(i == chararr_num){
//             strcat(result, chararr[i]);
//             break;
//         }
//         strcat(result, chararr[i]);
//         strcat(result, merge_str);
//     }
//     return 0;
// }

int CharArrInsertWord(char *result, char* str, char const* insert_str,int insert_num,const char* key){
    int count = 0;
    char *ptr;

    //文字列がkeyを含まなければエラー
    char *find = strstr(str, key);
    if(find == NULL) return -1;

    // keyを区切りに文字列を分割
    // 1回目
    ptr = strtok(str, key);
    printf("ptr %s count %d\n", ptr,count);
    strcat(result, ptr);
    count++;

    //2回目以降
    while(ptr != NULL){
        if(count == insert_num){
            strcat(result, key);
            strcat(result, insert_str);
        }
        ptr = strtok(NULL, key);
        if(ptr != NULL){
            strcat(result, key);
            strcat(result, ptr);
        }
        printf("ptr %s count %d\n", ptr,count);
        count++;
    }

    return 0;
}

int main(void){
    char org_word[] = "WWWW@XXX@YY@Z.csv";
    char result[100];

    int retvl = CharArrInsertWord(result, org_word, "FLOW1", 3, "@");

    printf("result %s",result);

    return 0;
}



