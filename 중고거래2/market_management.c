#include "market_management.h"

void searchProduct() {
    char product[100];
    printf("검색할 상품명을 입력하세요: ");
    scanf_s("%s", product);

    printf("%s에 대한 검색 결과를 출력합니다.\n", product);
}
