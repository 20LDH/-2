#include "user_management.h"

People s2;
int idline = 0;
int passline = 0;

void get_infor(People* s) {
    FILE* fp;
    if (fopen_s(&fp, "info.txt", "a+") != 0) {
        perror("파일 열기 실패");
        exit(1);
    }
    fprintf(fp, "%s %s %s\n", s->ID, s->password, s->name);
    fclose(fp);
    printf("회원가입이 완료되었습니다.\n");
}

int infor_ID(char* ID) {
    char line[1000] = "NULL";
    char sid[SIZE] = "NULL", spassword[SIZE] = "NULL", sname[SIZE] = "NULL";
    FILE* fp;
    if (fopen_s(&fp, "info.txt", "rt") != 0) {
        printf("file open error\n");
        exit(1);
    }
    while (fscanf_s(fp, "%s %s %s ", sid, spassword, sname, SIZE, SIZE, SIZE) != EOF) {
        idline++;
        if (strcmp(sid, ID) == 0) {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int infor_password(char* password, char* ID) {
    char line[1000] = "NULL";
    char sid[SIZE] = "NULL", spassword[SIZE] = "NULL", sname[SIZE] = "NULL";
    FILE* fp;
    if (fopen_s(&fp, "info.txt", "rt") != 0) {
        printf("file open error\n");
        exit(1);
    }
    while (fscanf_s(fp, "%s %s %s", sid, spassword, sname, SIZE, SIZE, SIZE) != EOF) {
        passline++;
        if (idline == passline && strcmp(spassword, password) == 0) {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

void sign_up() {
    char str[SIZE];
    FILE* fp;

    if (fopen_s(&fp, "info.txt", "a") != 0) {
        perror("파일 열기 실패");
        exit(1);
    }

    puts("아이디:");
    scanf_s("%s", str, SIZE);

    if (infor_ID(str) == 1) {
        strcpy_s(s2.ID, SIZE, str);
        puts("사용이 가능한 아이디입니다");
        puts("비밀번호:");
        scanf_s("%s", s2.password, SIZE);
        puts("이름:");
        scanf_s("%s", s2.name, SIZE);
        get_infor(&s2);
        system("cls");
    }
    else {
        printf("이미 있는 아이디입니다.\n");
        printf("다시 입력해주세요.\n");
        sign_up();
    }

    fclose(fp);
}

void login() {
    People a;
    int x, y;
    for (int i = 0; i < 5; i++) {
        printf("아이디:");
        scanf_s("%s", a.ID, SIZE);
        printf("비밀번호: ");
        scanf_s("%s", a.password, SIZE);
        x = infor_ID(a.ID);
        y = infor_password(a.password, a.ID);
        if (x == 0 && y == 0) {
            printf("로그인 성공\n");
            return;
        }
        else if (x == 1) {
            printf("아이디가 없거나 틀렸습니다. 다시 입력해주세요. \n");
            idline = 0;
            passline = 0;
        }
        else if (x == 0 && y == 1) {
            printf("비밀번호가 틀렸습니다. 다시 입력해주세요.\n");
            idline = 0;
            passline = 0;
        }
        else if (x == 1 && y == 1) {
            printf("가입이 되어 있지 않습니다.\n");
        }
    }
    printf("다섯 번 이상 틀려서 프로그램이 종료됩니다\n");
}
