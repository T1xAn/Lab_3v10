#include "Header.h"
int** a;

int unite(int** b, int n, int m) {
	if (m > n) {
		a = (int**)realloc(a, m * sizeof(*a));
		for (int i = n; i < m; i++)
			a[i] = (int*)calloc(m, sizeof(**a));
		n = m;
	}
	
	int j = 0;
	for (int i = 0; i < m; i++) {
		for (j; j < m; j++) {
			if (b[i][j] == 1) {
				a[i][j] = 1;
				a[j][i] = a[i][j];
			}
			else {
				if (a[i][j] != 1)
					a[i][j] = 0;
				a[j][i] = a[i][j];
			}
		}
		j = j - m + i + 1;
	}
	return n;
}

int cross(int** b, int n, int m) {
	if (n > m) {
		for (int i = 0; i < m; i++)
			a[i] = (int*)realloc(a[i], m * sizeof(**a));
		for (int i = m; i < n; i++)
			free(a[i]);
		n = m;
	}
	else
		m = n;
	int j = 0;
	for (int i = 0; i < m; i++) {
		for (j; j < m; j++) {
			if ((a[i][j] != 1) || (b[i][j] != 1)) {
				a[i][j] = 0;
				a[j][i] = a[i][j];
			}
		}
		j = j - m + i + 1;
	}
	return n;
}

int short_circuit(int** b, int n, int m) {
	if (n > m) {
		for (int i = 0; i < m; i++)
			a[i] = (int*)realloc(a[i], m * sizeof(**a));
		for (int i = m; i < n; i++)
			free(a[i]);
		n = m;
	}
	else
		m = n;
	int j = 0;
	for (int i = 0; i < m; i++) {
		for (j; j < m; j++) {
			if (((b[i][j] == 1) && (a[i][j] != 1)) || ((b[i][j] != 1) && (a[i][j] == 1))) {
				a[i][j] = 1;
				a[j][i] = a[i][j];
			}
			else {
				a[i][j] = 0;
				a[j][i] = a[i][j];
			}
		}
		j = j - m + i + 1;
	}
	int k;
	for (int i = 0; i < m; i++) {
		k = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1)
				k++;
		}
		if (k == 0) {
			for (int q = i; q < m - 1; q++)
				for (int r = 0; r < m; r++)
					a[q][r] = a[q + 1][r];

			for (int q = 0; q < m; q++)
				for (int r = i; r < m - 1; r++)
					a[q][r] = a[q][r + 1];

			for (int q = 0; q < m; q++)
				a[q] = (int*)realloc(a[q], (m - 1) * sizeof(int));
			free(a[m - 1]);
			m--;
			i--;
		}
	}
	return m;
}

void number3_create(int inside_menu) {
	int** d, b, c, i, n, m, j;
	printf("\n   ¬ведите количество вершин дл€ первой матрицы: ");
	scanf("%d", &n);
	a = (int**)malloc(n * sizeof(*a));
	j = 1;
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(**a));
	}
	for (i = 0; i < n; i++) {
		a[i][i] = 0;
		for (j; j < n; j++) {
			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];
		}
		j = j - n + i + 1;
	}

	for (i = 0; i < n; i++) {
		a[i][i] = 0;
	}

	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("   ¬едите количество вершин дл€ второй матрицы: ");
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
		printf("   ");
		for (j = 0; j < m; j++) {
			printf("%2d", d[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	switch (inside_menu) {
	case 0:
		n = unite(d, n, m);
	
		break;
	case 1:
		n = cross(d, n, m);
	
		break;
	case 2:
		n = short_circuit(d, n, m);
		
		break;
	}
	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
}