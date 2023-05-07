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
int compareByStudentID(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    return strcmp(studentA->id, studentB->id);
}

int compareByStudentName(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    return strcmp(studentA->name, studentB->name);
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
    qsort(s, MAX, sizeof(Student), compareByStudentName);
    //qsort(s, MAX, sizeof(Student), compareByStudentID);
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;


    if (isSortedByStudentName(s, MAX)==0) {
        printf("정렬이 잘 안되었습니다.");
    }

    //if (isSortedByStudentID(s, MAX) == 0) {
    //    printf("정렬이 잘 안되었습니다.");
    //}

    printf("c언어 이름기준 정렬 : %.3f초", cpu_time_used);
    ////구조체 배열 출력
    //for (int j = 0; j < 20000; j++) {
    //    printf("%s %s %s\n", s[j].id, s[j].name, s[j].address);
    //}
}