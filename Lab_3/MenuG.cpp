#include "Header.h"

menu _menu;
void create_menu() {
	strcpy(_menu.up, "\n"
		"                                                      _________________________________\n"
		"                                                      \\  ___________________________  / \n");
	strcpy(_menu.wall, "                                                       ||                           || \n");
	strcpy(_menu.wallBottom, "                                                       ||___________________________||\n"
		"                                                       ||___________________________||\n");
	strcpy(_menu.bottom, "                                                       ||___________________________||\n"
		"                                                      /_______________________________\\ \n");
	_menu.text[0] = "                                                       ||         Задание 1         ||\n";
	_menu.text[1] = "                                                       ||         Задание 2         ||\n";
	_menu.text[2] = "                                                       ||         Задание 3         ||\n";
	_menu.text[3] = "                                                       ||         Задание 4         ||\n";
	_menu.text[4] = "                                                       ||           Выход           ||\n";

	_menu.active_text[0] = "                                                       ||       > Задание 1 <       ||\n";
	_menu.active_text[1] = "                                                       ||       > Задание 2 <       ||\n";
	_menu.active_text[2] = "                                                       ||       > Задание 3 <       ||\n";
	_menu.active_text[3] = "                                                       ||       > Задание 4 <       ||\n";
	_menu.active_text[4] = "                                                       ||         > Выход <         ||\n";

	_menu.versions[0] = "                                                       ||    Версия через матрицы   ||\n";
	_menu.versions[1] = "                                                       ||    Версия через списки    ||\n";

	_menu.active_versions[0] = "                                                       ||  > Версия через матрицы < ||\n";
	_menu.active_versions[1] = "                                                       ||  > Версия через списки <  ||\n";

	_menu.versions2[0] = "                                                       ||   Отождествление вершин   ||\n";
	_menu.versions2[1] = "                                                       ||      Стягивание ребра     ||\n";
	_menu.versions2[2] = "                                                       ||    Расщепление вершины    ||\n";

	_menu.active_versions2[0] = "                                                       || > Отождествление вершин < ||\n";
	_menu.active_versions2[1] = "                                                       ||   > Стягивание ребра <    ||\n";
	_menu.active_versions2[2] = "                                                       ||  > Расщепление вершины <  ||\n";

	_menu.versions3[0] = "                                                       ||        Объединение        ||\n";
	_menu.versions3[1] = "                                                       ||        Пересечение        ||\n";
	_menu.versions3[2] = "                                                       ||      Кольцевая сумма      ||\n";

	_menu.active_versions3[0] = "                                                       ||      > Объединение <      ||\n";
	_menu.active_versions3[1] = "                                                       ||      > Пересечение <      ||\n";
	_menu.active_versions3[2] = "                                                       ||    > Кольцевая сумма <    ||\n";
}

void mainMenuPos(int i) {
	int k = 0;
	int max = 4;
	system("cls");
	printf("%s", _menu.up);
	printf("%s", _menu.wall);
	do {
		if (k == i) {
			printf("%s", _menu.active_text[i]);
		}
		else {
			printf("%s", _menu.text[k]);

		}
		printf("%s", _menu.wallBottom);
		printf("%s", _menu.wall);
		k++;
	} while (k < max);
	if (k == i) {
		printf("%s", _menu.active_text[k]);
	}
	else {
		printf("%s", _menu.text[k]);
	}
	printf("%s", _menu.bottom);
	return;
}

void Version2G(int i) {
	int k = 0;
	int max = 2;
	system("cls");
	printf("%s", _menu.up);
	printf("%s", _menu.wall);
	do {
		if (k == i) {
			printf("%s", _menu.active_versions2[i]);
		}
		else {
			printf("%s", _menu.versions2[k]);

		}
		printf("%s", _menu.wallBottom);
		printf("%s", _menu.wall);
		k++;
	} while (k < max);
	if (k == i) {
		printf("%s", _menu.active_versions2[k]);
	}
	else {
		printf("%s", _menu.versions2[k]);
	}
	printf("%s", _menu.bottom);
	return;
}

void mainMenu() {
	Menu = 0;
	system("cls");
	mainMenuPos(Menu);
	char cur;
	do {
		cur = _getch();
		if (cur == 80) {
			Menu++;
			switch (Menu) {
			case 5:
				Menu = 0;
				mainMenuPos(Menu);
				break;
			default:
				mainMenuPos(Menu);
			}
		}
		if (cur == 72) {
			Menu--;
			switch (Menu) {
			case -1:
				Menu = 4;
				mainMenuPos(Menu);
				break;
			default:
				mainMenuPos(Menu);
			}
		}

	} while (cur != 13);
}

int versions2Menu() {
	char cur;
	int isf = 0;
	Version2G(isf);
	do {
		cur = _getch();
		if (cur == 80) {
			isf++;
			switch (isf) {
			case 3:
				isf = 0;
				Version2G(isf);
				break;
			default:
				Version2G(isf);
				break;
			}
		}
		if (cur == 72) {
			isf--;
			switch (isf) {
			case -1:
				isf = 2;
				Version2G(isf);
				break;
			default:
				Version2G(isf);
				break;
			}
		}
		if (cur == 27) {
			return 0;
		}
	} while (cur != 13);
	return (isf);
}

void versionsMenuG(int isf) {
	int k = 0;
	system("cls");
	printf("%s", _menu.up);
	printf("%s", _menu.wall);
	if (isf == 0) {
		printf("%s", _menu.active_versions[k]);
		printf("%s", _menu.wallBottom);
		printf("%s", _menu.wall);
		printf("%s", _menu.versions[k + 1]);
	}
	else {
		printf("%s", _menu.versions[k]);
		printf("%s", _menu.wallBottom);
		printf("%s", _menu.wall);
		printf("%s", _menu.active_versions[k + 1]);
	}
	printf("%s", _menu.bottom);
	return;
}
void Version3G(int i) {
	int k = 0;
	int max = 2;
	system("cls");
	printf("%s", _menu.up);
	printf("%s", _menu.wall);
	do {
		if (k == i) {
			printf("%s", _menu.active_versions3[i]);
		}
		else {
			printf("%s", _menu.versions3[k]);

		}
		printf("%s", _menu.wallBottom);
		printf("%s", _menu.wall);
		k++;
	} while (k < max);
	if (k == i) {
		printf("%s", _menu.active_versions3[k]);
	}
	else {
		printf("%s", _menu.versions3[k]);
	}
	printf("%s", _menu.bottom);
	return;
}

int versions3Menu() {
	char cur;
	int isf = 0;
	Version3G(isf);
	do {
		cur = _getch();
		if (cur == 80) {
			isf++;
			switch (isf) {
			case 3:
				isf = 0;
				Version3G(isf);
				break;
			default:
				Version3G(isf);
				break;
			}
		}
		if (cur == 72) {
			isf--;
			switch (isf) {
			case -1:
				isf = 2;
				Version3G(isf);
				break;
			default:
				Version3G(isf);
				break;
			}
		}
		if (cur == 27) {
			return 0;
		}
	} while (cur != 13);
	return (isf);
}