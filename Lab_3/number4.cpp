#include "Header.h"
int** e;
int** a2;
int descartes_multiples_puta_madre(int** b, int n, int m) {
	e = (int**)calloc(m * n, sizeof(int*));
	for (int i = 0; i < m * n; i++) {
		e[i] = (int*)calloc(m * n, sizeof(int));
	}
	int j = 0;
	for (int i = 0; i < n * m; i++) {
		for (j; j < n * m; j++) {
			if ((i / m == j / m) && (b[i % m][j % m] == 1))
				e[i][j] = 1;
			else {
				if ((a2[i / m][j / m] == 1) && (i % m == j % m))
					e[i][j] = 1;
				else
					e[i][j] = 0;
			}
			e[j][i] = e[i][j];
		}
		j = j - n * m + i + 1;
	}

	return n * m;
}

void number4() {
	int** d, b, c, i, n, m, j;
	printf("¬едите количество вершин дл€ первой матрицы ");
	scanf("%d", &n);
	a2 = (int**)malloc(n * sizeof(*a2));
	j = 1;
	for (i = 0; i < n; i++) {
		a2[i] = (int*)malloc(n * sizeof(**a2));
	}
	for (i = 0; i < n; i++) {
		a2[i][i] = 0;
		for (j; j < n; j++) {
			a2[i][j] = rand() % 2;
			a2[j][i] = a2[i][j];
		}
		j = j - n + i + 1;
	}

	for (i = 0; i < n; i++) {
		a2[i][i] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf(" ¬едите количество вершин дл€ второй матрицы ");
	scanf("%d", &m);
	d = (int**)malloc(m * sizeof(int*));
	j = 1;
	for (i = 0; i < m; i++) {
		d[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < m; i++) {
		d[i][i] = 0;
		for (j; j < m; j++) {
			d[i][j] = rand() % 2;
			d[j][i] = d[i][j];
		}
		j = j - m + i + 1;
	}

	for (i = 0; i < m; i++) {
		d[i][i] = 0;
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int l = descartes_multiples_puta_madre(d, n, m);
	for (i = 0; i < l; i++) {
		for (j = 0; j < l; j++) {
			printf("%d ", e[i][j]);
		}
		printf("\n");
	}
}