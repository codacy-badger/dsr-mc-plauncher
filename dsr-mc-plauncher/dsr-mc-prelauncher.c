#include <stdio.h>
#include <stdlib.h>
void menu(void); // ����˵�����
int in(); // ��ȡ���뺯��
int choose(int x); // ѡ��ִ�к���

int main(void) {
	printf("------------------- DSR�Ƽ��ͻ��� -------------------\n");
	printf("-------------------- V40.18111.1 --------------------\n");
	menu();
	int flag;
	do {
		int input = 0;
		input = in();
		flag = choose(input);
		if (!flag) {  // choose��������0 (���пͻ��� / ѡ��0) ���˳�����
			return 0;
		}
	} while (flag == -2);
	return 0;
}

// ��ȡ����
int in() {
	char x;
	x = getchar();
	int k = (int)x;  // ת��ASCII
	if (k != 49 && k != 50 && k != 48) {  // ������Ĳ����й��ܵ�����
		if (k == 10) {
			return -1;  // ��Ϊ�س�
		}
		else {
			return -2;  // ��Ϊ��������
		}
	}
	else {
		return k;  // ����������й��ܵ�����
	}
}

// ѡ��ִ��
int choose(int x) {
	switch (x) {
	case -1:  // �س�
		system("start DSR_LAUNCH.BAT");
		return 0;  // �˳�����
		break;
	case 49:  // 1
		menu();
		break;
	case 50:  // 2
		menu();
		break;
	case 48:     // 0
		return 0;  // �˳�����
	case -2:     // WRONG
		printf("���벻��ȷ�����������룺");
		getchar();  // ���ն���س�
		return -2;
		break;
	}
	return -2;
}

// ���ѡ��
void menu(void) {
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("\n");
	printf("----------- 1.     ��װ����\n");
	printf("----------- 2.     �򿪷���ҳ����Ҹ���\n");
	printf("----------- Enter. �򿪿ͻ���\n");
	printf("----------- 0.     �˳�\n");
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("\n");
	printf("��ѡ�������");
	return;
}