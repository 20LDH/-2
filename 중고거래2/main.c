#include "user_management.h"
#include "market_management.h"

int main() {
    int search;

    while (1) {
        system("cls");

        printf("중고거래 프로그램\n");
        printf("1. 회원가입\n");
        printf("2. 로그인\n");
        printf("3. 상품 검색\n");
        printf("4. 프로그램 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &search);

        switch (search) {
        case 1:
            printf("회원가입 기능이 실행됩니다.\n");
            sign_up();
            break;
        case 2:
            printf("로그인 기능이 실행됩니다.\n");
            login();
            break;
        case 3:
            printf("상품 검색 기능이 실행됩니다.\n");
            searchProduct();
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("유효하지 않은 선택입니다. 다시 시도하세요.\n");
            break;
        }

        printf("다시 선택해주세요");
        getchar();
        getchar();
    }

    return 0;
}
