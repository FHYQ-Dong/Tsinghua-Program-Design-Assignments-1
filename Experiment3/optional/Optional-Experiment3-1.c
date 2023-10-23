#include<stdio.h>
#include<stdlib.h>

#include"./include/PhoneNum.h" // 定义存储电话号码的数据结构的头文件
#include"./include/Map.h" // 仿照C++的map实现的头文件 (使用了开源项目: https://github.com/smithAchang/map)

char opt, buf; // i: 加入一个, s: 查找一个, q: 退出, l: 列出所有
char Name[100]; // 姓名
int N, cnt; // 电话号码数量
ll PhoneNumber; // 电话号码
map_int_t PhoneNumMap; // 电话号码映射表

int main() {
    map_init(&PhoneNumMap);
    printf("> Please input the number of phone numbers:\n");
    scanf("%d", &N);

    PhoneNumObj *PhoneNumList = (PhoneNumObj*)malloc(sizeof(PhoneNumObj) * (N + 1)); // 创建电话号码列表

    printf("> Please choose a option (i: insert, s: search, q:quit, l:list):\n");
    while(scanf("%c%c", &buf, &opt)) { // 读取操作
        if(opt == 'q') return 0;

        // insert
        if(opt == 'i') {
            if(cnt == N) {
                printf("The phone number list is full\n");
                goto end;
            }
            else {
                ++cnt;
                memset(Name, '\0', sizeof(Name));
                memset(&PhoneNumList[cnt].Name, 0, sizeof(Name));
                printf("Please input the name:\n"); scanf("%s", Name);
                printf("Please input the phone number:\n"); scanf("%lld", &PhoneNumber);

                PhoneNumList[cnt].oPhoneNum = oPhoneNum;
                PhoneNumList[cnt].iPhoneNum = iPhoneNum;
                PhoneNumList[cnt].iPhoneNum(PhoneNumber, &PhoneNumList[cnt]);
                for(int i = 0; i < strlen(Name); ++i) PhoneNumList[cnt].Name[i] = Name[i];

                map_set(&PhoneNumMap, Name, cnt);

                printf("Insert successfully\n");
                goto end;
            }
        }

        // search
        else if(opt == 's') {
            printf("Please input the name:\n");
            scanf("%s", Name);

            if(map_get(&PhoneNumMap, Name) == NULL) {
                printf("Not found\n");
            }
            else {
                int index = *(int*)map_get(&PhoneNumMap, Name);
                printf("--------------------\n");
                printf("Name\tPhone Number\n");
                printf("%s\t%lld\n", PhoneNumList[index].Name, PhoneNumList[index].oPhoneNum(&PhoneNumList[index]));
            }

            goto end;
        }

        // list
        else if(opt == 'l') {
            printf("--------------------\n");
            printf("Name\tPhone Number\n");
            for(int i=1; i<=cnt; ++i) {
                printf("%s\t%lld\n", PhoneNumList[i].Name, PhoneNumList[i].oPhoneNum(&PhoneNumList[i]));
            }
            goto end;
        }

        // Invalid operation
        else {
            printf("Invalid operation\n");
            goto end;
        }

end:
        printf("\n> Please choose a option (i: insert, s: search, q:quit, l:list):\n");
    }

    return 0;
}