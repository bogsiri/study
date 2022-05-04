#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.

int count_win_in_lottos(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    int i, j;
    int count = 0;
    int array[6] = { 0, };
    for (i = 0; i < lottos_len; i++)
        for (j = 0; j < win_nums_len; j++)
        {
            if (lottos[i] == win_nums[j]) count++;
        }

    return count;
}

int RetScor(int input)
{
    if (6 == input) 
        return 1;
    else if(5 == input) 
        return 2;
    else if (4 == input)
        return 3;
    else if (3 == input)
        return 4;
    else if (2 == input)
        return 5;
    else
        return 0;
}
int *solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int i;
    int count_zero = 0;
    int count_match = 0;
    int min = 0, max = 0;
    for (i = 0; i < lottos_len; i++) {
        if (lottos[i] == 0) count_zero++;

    }
    count_match = count_win_in_lottos(lottos, lottos_len, win_nums, win_nums_len);

    int *answer = (int *)malloc(sizeof(int) * 2);
    if (NULL == answer) return (int*) - 1;

    if (count_zero == 6) {
        *answer = 1;
        *(answer + 1) = 6;
        return answer;
    }
    if (count_match == 6) {
        *answer = 1;
        *(answer + 1) = 1;        
    }
    
    max = count_match + count_zero;
    min = count_match;
    
    *answer = RetScor(max);
    *(answer + 1) = RetScor(min);

    return answer;

}
void level1() {
    int lottos[6] = { 44,1,0,0,31,25 };
    int win_nums[6] = { 31,10,45,1,6,19 };

    int array[2] = { 0, };

    int *result = array;
    result = solution(lottos, sizeof(lottos) / sizeof(int), win_nums, sizeof(win_nums) / sizeof(int));

    return 0;
}


int level1_solution2(const char *s) {
    int answer = 0;
    int count_s = 0;
    int count_i = 0;
    while (s[count_s]) count_s++;
    if (count_s <= 1 | count_s >= 50) return -1;

    char *ss = (char *)malloc(sizeof(char *) * count_s);
    memset(ss, 0, sizeof(ss) * count_s);    
      
    count_s = 0;

    while (s[count_s])
    {
        if (s[count_s] == 0x31) {
            ss[count_i] = 0x31;
            count_s++;
        }
        else if (s[count_s] == 0x32) {
            ss[count_i] = 0x32;
            count_s++;
        }
        else if (s[count_s] == 0x33) {
            ss[count_i] = 0x33;
            count_s++;
        }
        else if (s[count_s] == 0x34) {
            ss[count_i] = 0x34;
            count_s++;
        }
        else if (s[count_s] == 0x35) {
            ss[count_i] = 0x35;
            count_s++;
        }
        else if (s[count_s] == 0x36) {
            ss[count_i] = 0x36;
            count_s++;
        }
        else if (s[count_s] == 0x37) {
            ss[count_i] = 0x37;
            count_s++;
        }
        else if (ss[count_s] == 0x38) {
            ss[count_i] = 0x38;
            count_s++;
        }
        else if (s[count_s] == 0x39) {
            ss[count_i] = 0x39;
            count_s++;
        }
        else if (s[count_s] == 0x30) {
            ss[count_i] = 0x30;
            count_s++;
        }
        else if (s[count_s] == 'z') {
            ss[count_i] = 0x30;
            count_s += 4;
        }
        else if (s[count_s] == 'o') {
            ss[count_i] = 0x31;
            count_s += 3;
        }
        else if (s[count_s] == 't') {
            if (s[count_s + 1] == 'w')
            {
                ss[count_i] = 0x32;
                count_s += 3;
            }
            else {
                ss[count_i] = 0x33;
                count_s += 5;
            }            
        }
        else if (s[count_s] == 'f') {
            if (s[count_s + 1] == 'o')
            {
                ss[count_i] = 0x34;
                count_s += 4;
            }
            else {
                ss[count_i] = 0x35;
                count_s += 4;
            }
        }
        else if (s[count_s] == 's') {
            if (s[count_s + 1] == 'i')
            {
                ss[count_i] = 0x36;
                count_s += 3;
            }
            else {
                ss[count_i] = 0x37;
                count_s += 5;
            }
        }
        else if (s[count_s] == 'e') {
            ss[count_i] = 0x38;
            count_s += 5;
        }
        else if (s[count_s] == 'n') {
            ss[count_i] = 0x39;
            count_s += 4;
        }

        count_i++;
        
    }
    

    return answer;
}

int main(void) {
    //level1();    
    level1_solution2("one4seveneight123123");


}
