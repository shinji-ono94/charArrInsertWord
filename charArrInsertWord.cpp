#include <stdio.h>
#include <string.h>

int CharArrSeparate(char* result[],char* chararr, const char* key){
    int count = 0;
    char *ptr;

    // keyを区切りに文字列を分割
    // 1回目
    ptr = strtok(chararr, key);
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

int main(void){
    char org_word[100] = "WWWW@XXX@YY@Z.csv";
    char *ptr[10];

    CharArrSeparate(ptr,org_word, "@");

    return 0;
}



