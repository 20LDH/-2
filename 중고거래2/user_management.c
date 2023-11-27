#include "user_management.h"

People s2;
int idline = 0;
int passline = 0;

void get_infor(People* s) {
    FILE* fp;
    if (fopen_s(&fp, "info.txt", "a+") != 0) {
        perror("���� ���� ����");
        exit(1);
    }
    fprintf(fp, "%s %s %s\n", s->ID, s->password, s->name);
    fclose(fp);
    printf("ȸ�������� �Ϸ�Ǿ����ϴ�.\n");
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
        perror("���� ���� ����");
        exit(1);
    }

    puts("���̵�:");
    scanf_s("%s", str, SIZE);

    if (infor_ID(str) == 1) {
        strcpy_s(s2.ID, SIZE, str);
        puts("����� ������ ���̵��Դϴ�");
        puts("��й�ȣ:");
        scanf_s("%s", s2.password, SIZE);
        puts("�̸�:");
        scanf_s("%s", s2.name, SIZE);
        get_infor(&s2);
        system("cls");
    }
    else {
        printf("�̹� �ִ� ���̵��Դϴ�.\n");
        printf("�ٽ� �Է����ּ���.\n");
        sign_up();
    }

    fclose(fp);
}

void login() {
    People a;
    int x, y;
    for (int i = 0; i < 5; i++) {
        printf("���̵�:");
        scanf_s("%s", a.ID, SIZE);
        printf("��й�ȣ: ");
        scanf_s("%s", a.password, SIZE);
        x = infor_ID(a.ID);
        y = infor_password(a.password, a.ID);
        if (x == 0 && y == 0) {
            printf("�α��� ����\n");
            return;
        }
        else if (x == 1) {
            printf("���̵� ���ų� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���. \n");
            idline = 0;
            passline = 0;
        }
        else if (x == 0 && y == 1) {
            printf("��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.\n");
            idline = 0;
            passline = 0;
        }
        else if (x == 1 && y == 1) {
            printf("������ �Ǿ� ���� �ʽ��ϴ�.\n");
        }
    }
    printf("�ټ� �� �̻� Ʋ���� ���α׷��� ����˴ϴ�\n");
}
