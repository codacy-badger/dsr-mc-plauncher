#include <stdio.h>
#include <stdlib.h>
void menu(void); // 输出菜单函数
int in(); // 获取输入函数
int choose(int x); // 选择执行函数

int main(void) {
	printf("------------------- DSR科技客户端 -------------------\n");
	printf("-------------------- V40.18111.1 --------------------\n");
	menu();
	int flag;
	do {
		int input = 0;
		input = in();
		flag = choose(input);
		if (!flag) {  // choose函数返回0 (运行客户端 / 选择0) 则退出程序
			return 0;
		}
	} while (flag == -2);
	return 0;
}

// 获取输入
int in() {
	char x;
	x = getchar();
	int k = (int)x;  // 转换ASCII
	if (k != 49 && k != 50 && k != 48) {  // 若输入的不是有功能的数字
		if (k == 10) {
			return -1;  // 若为回车
		}
		else {
			return -2;  // 若为错误输入
		}
	}
	else {
		return k;  // 若输入的是有功能的数字
	}
}

// 选择执行
int choose(int x) {
	switch (x) {
	case -1:  // 回车
		system("start DSR_LAUNCH.BAT");
		return 0;  // 退出程序
		break;
	case 49:  // 1
		menu();
		break;
	case 50:  // 2
		menu();
		break;
	case 48:     // 0
		return 0;  // 退出程序
	case -2:     // WRONG
		printf("输入不正确，请重新输入：");
		getchar();  // 吸收多余回车
		return -2;
		break;
	}
	return -2;
}

// 输出选项
void menu(void) {
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("\n");
	printf("----------- 1.     安装字体\n");
	printf("----------- 2.     打开发布页面查找更新\n");
	printf("----------- Enter. 打开客户端\n");
	printf("----------- 0.     退出\n");
	printf("\n");
	printf("-----------------------------------------------------\n");
	printf("\n");
	printf("请选择操作：");
	return;
}