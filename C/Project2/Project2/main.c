#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.

int count_win_in_lottos(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    unsigned int i, j;
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
    unsigned int i;
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

    
}
int level1_solution2(const char *s) {
    int answer = 0;
    int count_s = 0;
    int count_i = 0;
    while (s[count_s]) count_s++;
    if ((count_s <= 1) | (count_s >= 50)) return -1;

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

void bubble_sort(char list[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        // 0 ~ (i-1)까지 반복
        for (j = 0; j < i; j++) {
            // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
            if (list[j] < list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    printf("%s", list);
}
void sobak(int n) {
    int y = 0;
    int x = 0;
    x = n / 2;
    y = n % 2;

    int i = 0;


    char *answer = (char *)malloc(sizeof(char) * n);
    if(NULL != answer)
        memset(answer, 0, sizeof(char) * n + 2);

    for (i = 0; i <= x+1; i = i + 2) {
        answer[i] = '1';
        answer[i + 1] = '2';
    }
    if (0 != y) {
        answer[i] = '1';
    }
    printf("%s", answer);
}
void change_int_str(char s[])
{
    int f_bool = 0;
    if (s[0] == '+') {
        f_bool = atoi(s);
    }
    else {
        f_bool = -(atoi(s + 1));
    }
}
void minsqar(void)
{
    int answer = 0;
    int index;
    int cur_LB = 0, cur_RB = 0;
    int last_LB = 0, last_RB = 0;
    int sizes[4][2] = { {60, 50},{30, 70},{60, 30},{80, 40} };
    
    last_LB = sizes[0][0];
    last_RB = sizes[0][1];
    for (index = 0; index < 4; index++)
    {
        if (sizes[index][0] > sizes[index][1])
        {
            cur_LB = sizes[index][0];
            cur_RB = sizes[index][1];
        }
        else {
            cur_LB = sizes[index][1];
            cur_RB = sizes[index][0];

        }
        if (cur_LB > last_LB) last_LB = cur_LB;
        if (cur_RB > last_RB) last_RB = cur_RB;
    }
    printf("\n%d %d\n", last_LB, last_RB);

}
void square() {
    int w = 8;
    int h = 12;
    int answer = 0;
    while (1)
    {
        if (w == 1 || h == 1 | w == 0 | h == 0)
            break;
        if (w > h) {
            answer += h * h;
            w = w - h;
        }
        else if (w < h) {
            answer += w * w;
            h = h - w;
        }
        else {
            answer += w * w - w;
            w = 0;
            h = 0;
        }        
    }
}

void buble_U(int data[], int COUNT) {
    int temp;
    int i, j;
    for (i = 0; i < COUNT - 1; i++)
    {
        for (j = 0; j < COUNT - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
void buble_D(int data[], int COUNT) {
    int temp;
    int i, j;
    for (i = 0; i < COUNT - 1; i++)
    {
        for (j = 0; j < COUNT - 1 - i; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
void test() {
    
    char *s = "try hello world";

    int count = 0;
    while (s[count]) count++;

    char *answer = (char *)malloc(count);
    if (NULL == answer) return "";

    memset(answer, 0, count);
    answer = s;
    int incount = 0;
    int j;
    for (int i = 0; i < count; i++) {
        incount = 0;
        if (answer[i] == 0x20) {
            i++;
            for (j = i; j < count; j++) {
                if (answer[i] == NULL || answer[i] == 0x20) break;
                if (incount % 2 == 0)
                    printf("%c", answer[j] - 0x20);
                incount++;
            }
        }
        else {
            if (i % 2 == 0)
                printf("%c", answer[i] - 0x20);
            else
                printf("%c", answer[i]);
        }
    }

    printf("%s", *answer);



    
}
void main(void) {
    // level1();    
    // level1_solution2("one4seveneight123123");
    char s[] = { "Zbcdefg" };
    bubble_sort(s, 7);
    sobak(7);
    change_int_str("1234");        
    minsqar();

    //id_list();
    square();
    test(); 




}
