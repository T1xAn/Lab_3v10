#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale>
#include <time.h>
struct menu {
	char up[200];
	char bottom[200];
	const char* text[5];
	const char* active_text[5];
	const char* versions[2];
	const char* active_versions[2];
	const char* versions2[3];
	const char* active_versions2[3];
	const char* versions3[3];
	const char* active_versions3[3];
	const char* number4[3];
	const char* active_number4[3];
	char wall[200];
	char wallBottom[200];

};

struct node {
	int numb;
	node* next;
};
struct graf {
	node** nodes;
	int size;
};

//menu
extern int Menu;
extern menu _menu;
extern int size;
void create_menu();
void mainMenuPos(int i);
void mainMenu();
void select();
void versionsMenuG(int isf);
void versionsMenu();
void Version2G(int i);
int versions2Menu();
void number3Menu();
int versions3Menu();
void Version3G(int i);
//number1
graf* sozdat(int versh);
node* sozdatnode(int index);
void addgran(graf* grafon, int from, int to);
void number1_1();
void number1_2();

//nuber2
int equation_matrix(int** a, int n, int b, int c);
int pullin_matrix(int** a, int n, int b, int c);
int split_matrix(int** a, int n, int c);
int** number2_create();
void number2_a(int** a);
void number2_b(int** a);
void number2_v(int** a);

void number_2_List();
int equation_list(graf* grafon, int versh, int b, int c);
int pullin_list(graf* grafon, int versh, int b, int c);
int split_list(graf* grafon, int versh, int b);
graf* num2_list_create();
void number2_a_list(graf* grafon);
void number2_b_list(graf* grafon);
void number2_v_list(graf* grafon);

// Num3 

int unite(int** b, int n, int m);
int cross(int** b, int n, int m);
int short_circuit(int** b, int n, int m);
void number3_create(int inside_menu);

//Num 4
void number4();
int descartes_multiples_puta_madre(int** b, int n, int m);