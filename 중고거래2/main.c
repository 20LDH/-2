#include "user_management.h"
#include "market_management.h"

int main() {
    int search;

    while (1) {
        system("cls");

        printf("�߰�ŷ� ���α׷�\n");
        printf("1. ȸ������\n");
        printf("2. �α���\n");
        printf("3. ��ǰ �˻�\n");
        printf("4. ���α׷� ����\n");
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &search);

        switch (search) {
        case 1:
            printf("ȸ������ ����� ����˴ϴ�.\n");
            sign_up();
            break;
        case 2:
            printf("�α��� ����� ����˴ϴ�.\n");
            login();
            break;
        case 3:
            printf("��ǰ �˻� ����� ����˴ϴ�.\n");
            searchProduct();
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("��ȿ���� ���� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }

        printf("�ٽ� �������ּ���");
        getchar();
        getchar();
    }

    return 0;
}
