
#include "Header.h"
int Menu;
int** a1;
graf* grafon;
int size;
void select() {
	switch (Menu) {
	case 0:
		system("cls");
		versionsMenu();
		break; 
	case 1:
		system("cls");
		versionsMenu();
		system("pause");
		break;
	case 2:
		system("cls");
		number3Menu();
		system("pause");
		break;
	case 3:
		system("cls");
		number4();
		system("pause");
		break;
	case 4:
		exit(0);
	}
}

void versionsMenu() {
	char cur;
	int isf = 0;
	versionsMenuG(isf);
	do {
		cur = _getch();
		if (cur == 80) {
			isf++;
			switch (isf) {
			case 2:
				isf = 0;
				versionsMenuG(isf);
				break;
			default:
				versionsMenuG(isf);
				break;
			}
		}
		if (cur == 72) {
			isf--;
			switch (isf) {
			case -1:
				isf = 2;
				versionsMenuG(isf);
				break;
			default:
				versionsMenuG(isf);
				break;
			}
		}
		if (cur == 27) {
			return;
		}
	} while (cur != 13);

	switch (Menu) {
	case 0:
		switch (isf)
		{
		case 0:
			system("cls");
			number1_1();
			system("pause");
			return;
		case 1:
			system("cls");
			number1_2();
			system("pause");
			return;
		default:
			break;
		}
	case 1:
		if (isf == 0) {
			int inside_menu = versions2Menu();
			switch (inside_menu) {
			case 0:
				system("cls");
				a1 = number2_create();
				number2_a(a1);
				
				break;
			case 1:
				system("cls");
				a1 = number2_create();
				number2_b(a1);
				
				break;
			case 2:
				system("cls");
				a1 = number2_create();
				number2_v(a1);
				
				break;
			}
			break;
		}
		else {

			int inside_menu = versions2Menu();
			switch (inside_menu) {
			case 0:
				system("cls");
				grafon = num2_list_create();
				number2_a_list(grafon);
				break;
			case 1:
				system("cls");
				grafon = num2_list_create();
				number2_b_list(grafon);
				break;
			case 2:
				system("cls");
				grafon = num2_list_create();
				number2_v_list(grafon);
				break;
			}
			break;
		}

	}
}


void number3Menu() {
int inside_menu = versions3Menu();
system("cls");
number3_create(inside_menu);
 }
void main() {
	setlocale(LC_ALL, "Russian");

	do {
		create_menu();
		mainMenu();
		select();
	} while (1);
}
