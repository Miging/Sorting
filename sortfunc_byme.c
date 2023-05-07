//numbers.txt에 있는 값을 읽어 정렬하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20000

//학번,이름,주소를 저장하는 구조체
typedef struct Student {
    char id[9];
    char name[11];
    char address[101];
} Student;

//학번을 기준으로 선택정렬하는 함수
void select_sort_by_id(Student* s, int n) {
    int i, j, min;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(s[j].id, s[min].id) < 0) {
                min = j;
            }
        }
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}
void select_sort_by_name(Student* s, int n) {
    int i, j, min;
    Student temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(s[j].name, s[min].name) < 0) {
                min = j;
            }
        }
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}
// 스택 노드 구조체 정의
struct StackNode {
    int left;
    int right;
    struct StackNode* next;
};

// 스택에 노드 추가
void push(struct StackNode** top, int left, int right) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->left = left;
    newNode->right = right;
    newNode->next = *top;
    *top = newNode;
}

// 스택에서 노드 제거하고 반환
void pop(struct StackNode** top, int* left, int* right) {
    if (*top == NULL)
        return;
    struct StackNode* temp = *top;
    *left = temp->left;
    *right = temp->right;
    *top = temp->next;
    free(temp);
}

// 구조체 배열을 학번 순으로 정렬하는 비재귀적인 퀵 정렬 함수
void quickSort_id(Student students[], int size) {
    // 스택 초기화
    struct StackNode* stack = NULL;
    int left, right;

    // 처음으로 스택에 전체 배열의 인덱스를 저장
    push(&stack, 0, size - 1);

    // 스택이 빌 때까지 반복
    while (stack != NULL) {
        // 스택에서 두 개의 인덱스를 가져옴
        pop(&stack, &left, &right);

        // 분할 위치를 찾기 위해 피벗을 선택
        int i = left, j = right;
        char pivot[9] = students[left].id; // 피벗은 부분 배열의 첫 번째 요소로 선택

        while (i <= j) {
            // 피벗보다 큰 학번을 찾을 때까지 오른쪽으로 이동
            while (strcmp(students[i].id, pivot) < 0)
                i++;

            // 피벗보다 작은 학번을 찾을 때까지 왼쪽으로 이동
            while (strcmp(students[j].id, pivot) > 0)
                j--;

            // 현재 요소들의 위치를 교환
            if (i <= j) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
                i++;
                j--;
            }
        }

        // 왼쪽 부분 배열을 정렬하기 위해 스택에 인덱스 저장
        if (left < j) {
            push(&stack, left, j);
        }
        if (i < right) {
            push(&stack, i, right);
        }
    }
}

int isSortedByStudentID(const Student* students, int numStudents) {
    for (int i = 1; i < numStudents; i++) {
        if (strcmp(students[i].id, students[i - 1].id) < 0) {
            return 0;  // 올바른 순서가 아님
        }
    }
    return 1;  // 올바른 순서임
}

int isSortedByStudentName(const Student* students, int numStudents) {
    for (int i = 1; i < numStudents; i++) {
        if (strcmp(students[i].name, students[i - 1].name) < 0) {
            return 0;  // 올바른 순서가 아님
        }
    }
    return 1;  // 올바른 순서임
}


int main(void) {
    //파일 읽기
    FILE* fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("파일을 읽을 수 없습니다.\n");
        return 0;
    }
    clock_t start, end;
    //파일을 읽어 구조체 배열에 저장
    Student* s = (Student*)malloc(sizeof(Student) * MAX);
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%s %s %s", s[i].id, s[i].name, s[i].address);
        i++;
    }


    start = clock();
    //select_sort_by_name(s, 20000);
    //select_sort_by_id(s, 20000);
    quickSort_id(s, 20000);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (isSortedByStudentName(s, MAX) == 0&&isSortedByStudentID(s,MAX)==0) {
        printf("정렬이 잘 안되었습니다.");
    }



    printf("c언어 선택정렬 이름 기준 정렬 : %.3f초", cpu_time_used);
    //구조체 배열 출력
    for (int j = 0; j < 20000; j++) {
        printf("%s %s %s\n", s[j].id, s[j].name, s[j].address);
    }
}