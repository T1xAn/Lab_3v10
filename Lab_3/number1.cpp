#include "Header.h"

graf* sozdat(int versh) {
	graf* grafon = (graf*)malloc(sizeof(graf));
	grafon->size = versh;
	grafon->nodes = (node**)malloc(versh * sizeof(node*));
	for (int i = 0; i < versh; i++) {
		grafon->nodes[i] = NULL;
	}
	return grafon;
}
node* sozdatnode(int index) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->numb = index;
	newnode->next = NULL;
	return newnode;
}
void addgran(graf* grafon, int from, int to) {
	node* newnode = sozdatnode(from);
	newnode->next = grafon->nodes[to];
	grafon->nodes[to] = newnode;

	newnode = sozdatnode(to);
	newnode->next = grafon->nodes[from];
	grafon->nodes[from] = newnode;
}

void number1_1() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int** a, ** b, i, n, m, n1, m1, j;
	printf("\n   Введите количество вершин: ");
	scanf("%d", &n);
	m = n;
	a = (int**)malloc(n * sizeof(int*));
	j = 1;
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		a[i][i] = 0;
		for (j; j < m; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
		j = j - m + i + 1;
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		a[i][i] = 0;
	}
	for (i = 0; i < m; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void number1_2() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int** a, ** b, i, n, m, n1, m1, j;
	printf("\n   Введите количество вершин: ");
	scanf("%d", &n);
	m = n;
	a = (int**)malloc(n * sizeof(int*));
	j = 1;
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		a[i][i] = 0;
		for (j; j < m; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
		j = j - m + i + 1;
	}

	for (i = 0; i < n; i++) {
		a[i][i] = 0;
	}
	for (i = 0; i < m; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	graf* grafon = sozdat(n);
	j = 1;
	for (i = 0; i < n; i++) {
		for (j; j < m; j++) {
			if (a[i][j] == 1) {
				addgran(grafon, i, j);
			}
		}
		j = j - m + i + 1;
	}
	for (i = 0; i < m; i++) {
		node* temp = grafon->nodes[i];
		printf(" %d", i);
		while (temp) {
			printf("->%d", temp->numb);
			temp = temp->next;
		}
		printf("\n");
	}

}

