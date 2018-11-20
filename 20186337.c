#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

typedef struct personalStatement {
	char name[16];
	struct birth {
		char year[8];
		char month[4];
		char day[4];
	} myBirth;
	char sex[4];
	char phone[16];
}PersonalStatement;
PersonalStatement *inputStatPtr();
void printPerStat(PersonalStatement **ptrArr, int n);

int main() {
	int n;
	printf("입력할 명세서의 개수를 입력하시오: ");
	scanf("%d", &n);
	PersonalStatement **structPtrArr;
	structPtrArr = (PersonalStatement**)malloc(sizeof(PersonalStatement*)*n);
	printf("이름,생년,생월,생일,성별,전화번호는 스페이스로 구분하여 입력하시오.\n\n");
	for (int i = 0; i < n; i++) {
		printf("개별명세 입력%d: ", i + 1);
		structPtrArr[i] = inputStatPtr();
	}

	printf("\n");
	printPerStat(structPtrArr, n);          //기본 출력


	PersonalStatement *temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (strcmp(structPtrArr[j]->name, structPtrArr[j + 1]->name) < 0) {
				temp = structPtrArr[j];
				structPtrArr[j] = structPtrArr[j + 1];
				structPtrArr[j + 1] = temp;
			}
		}
	}
	printPerStat(structPtrArr, n);          //이름정렬 후 출력


	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if ((atoi(structPtrArr[j]->myBirth.year) * 10000 + atoi(structPtrArr[j]->myBirth.month) * 100 + atoi(structPtrArr[j]->myBirth.day)) < (atoi(structPtrArr[j + 1]->myBirth.year) * 10000 + atoi(structPtrArr[j + 1]->myBirth.month) * 100 + atoi(structPtrArr[j + 1]->myBirth.day))) {
				temp = structPtrArr[j];
				structPtrArr[j] = structPtrArr[j + 1];
				structPtrArr[j + 1] = temp;
			}
		}
	}
	printPerStat(structPtrArr, n);          //나이정렬 후 출력
	free(structPtrArr);
}

PersonalStatement* inputStatPtr() {
	PersonalStatement *statePtr = (PersonalStatement*)malloc(sizeof(PersonalStatement));

	scanf("%s", (statePtr->name));
	scanf("%s", (statePtr->myBirth.year));
	scanf("%s", (statePtr->myBirth.month));
	scanf("%s", (statePtr->myBirth.day));
	scanf("%s", (statePtr->sex));
	scanf("%s", (statePtr->phone));
	return statePtr;
}


void printPerStat(PersonalStatement **ptrArr, int n) {
	printf("이름\t생년월일\t성별\t번호\n");
	for (int i = 0; i < n; i++) {
		printf("%s\t", ptrArr[i]->name);
		printf("%s/%s/%s\t", ptrArr[i]->myBirth.year, ptrArr[i]->myBirth.month, ptrArr[i]->myBirth.day);
		printf("%s\t", ptrArr[i]->sex);
		printf("%s\n", ptrArr[i]->phone);
	}
	printf("\n");
}
