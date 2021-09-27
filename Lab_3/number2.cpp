#include "Header.h"
int equation_matrix(int** a, int n, int b, int c) {
	int k=0;
	if(a[b][c]==0){
		k++;
	}
	for (int j=0;j<n;j++){
		if(a[c][j]==1){
			a[b][j] = 1;
			a[j][b] = a[b][j];
		}
	}
	if(k==1)
		a[b][b]=0;
	for (int i  = c; i < n - 1; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j] = a[i + 1][j];
	for (int i = 0; i < n; i++) 
		for (int j = c; j < n - 1; j++) 
			a[i][j] = a[i][j + 1]; 
	for(int i=0;i<n;i++)
		a[i]= (int*)realloc(a[i],(n-1)*sizeof(int));
	free(a[n-1]);
	n--;
	return n;
}

int pullin_matrix(int** a, int n, int b, int c) {
	if (a[b][c] == 0) {
		printf("\n   ”казанные вершины не соединены");
		return 0;
	}
	for (int j=0;j<n;j++){
		if(a[c][j]==1){
			a[b][j] = 1;
			a[j][b] = a[b][j];
		}
	}
	a[b][b]=0;
	for (int i  = c; i < n - 1; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j] = a[i + 1][j];
	for (int i = 0; i < n; i++) 
		for (int j = c; j < n - 1; j++) 
			a[i][j] = a[i][j + 1]; 
	for(int i=0;i<n;i++)
		realloc(a[i],(n-1)*sizeof(int));
	free(a[n-1]);
	n--;
	return n;
}

int split_matrix(int** a, int n, int c) {
	realloc(a, (n + 1) * sizeof(int));
	for (int i = 0; i < n; i++)
		realloc(a[i], (n + 1) * sizeof(int));
	a[n] = (int*)malloc((n + 1) * sizeof(int));
	for (int i = 0; i < n / 2; i++) {
		a[i][n] = a[i][c];
		a[i][c] = 0;
		a[n][i] = a[i][n];
	}
	for (int i = n / 2; i < (n + 1); i++) {
		a[i][n] = 0;
		a[n][i] = a[i][n];
	}
	a[c][n] = 1;
	a[n][c] = a[c][n];
	n++;
	return n;
}

int** number2_create() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int** a, ** b, i, n, m, n1, m1, j;
	printf("\n   ¬ведите количество вершин: ");
	scanf("%d", &n);
	m = n;
	size = n;
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
	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return(a);



}

void number2_a(int **a) {
	int b, c, i, n, j;
	n = size;
	printf("   ¬ведите номера вершин дл€ отождествлени€: ");
	scanf("%d %d", &b, &c);
	n = equation_matrix(a, n, b, c);
	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
}

void number2_b(int **a) {
	int b, c, i, n, j;
	n = size;
	printf("   ¬ведите номера вершин дл€ ст€гивани€: ");
	scanf("%d %d", &b, &c);
	n = pullin_matrix(a, n, b, c);
	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
}

void number2_v(int** a) {
	int b, c, i, n, j;
	n = size;
	printf("   ¬ыберите номера дл€ расщеплени€: ");
	scanf("%d", &c);
	n = split_matrix(a, n, c);
	for (i = 0; i < n; i++) {
		printf("   ");
		for (j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
}

//////// List part

int equation_list(graf* grafon, int versh, int b, int c) {

	node* temp_c = grafon->nodes[c];
	node* temp_b = grafon->nodes[b];
	while (temp_c) {
		temp_b = grafon->nodes[b];
		while (temp_b->next) {
			if (temp_b->numb == temp_c->numb)
				break;
			temp_b = temp_b->next;
		}
		if (temp_b->numb != temp_c->numb) {
			node* temp = sozdatnode(temp_c->numb);
			temp_b->next = temp;
		}
		temp_c = temp_c->next;
	}

	temp_b = grafon->nodes[b];
	node* temp_b_prev = NULL;
	while (temp_b) {
		if (temp_b->numb == c) {
			if (temp_b_prev == NULL)
				grafon->nodes[b] = temp_b->next;
			else {
				if (temp_b->next == NULL)
					temp_b_prev->next = NULL;
				else
					temp_b_prev->next = temp_b->next;
			}
			free(temp_b);
			break;
		}
		temp_b_prev = temp_b;
		temp_b = temp_b->next;
	}

	for (int i = c; i < versh - 1; i++)
		grafon->nodes[i] = grafon->nodes[i + 1];
	realloc(grafon->nodes, (versh - 1) * sizeof(node));
	versh--;
	grafon->size--;

	node* temp = NULL;
	for (int i = 0; i < versh; i++) {
		temp = grafon->nodes[i];
		while (temp) {
			if (temp->numb == c)
				temp->numb = b;
			if (temp->numb >= c)
				temp->numb--;
			temp = temp->next;
		}
	}
	return versh;
}

int pullin_list(graf* grafon, int versh, int b, int c) {

	node* temp_b = grafon->nodes[b];
	while (temp_b) {
		if (temp_b->numb == c)
			break;
		temp_b = temp_b->next;
	}
	if (temp_b == NULL) {
		printf("\n   ”казанные вершины не соединены \n");
		system("pause");
		return versh;
	}

	node* temp_c = grafon->nodes[c];
	while (temp_c) {
		temp_b = grafon->nodes[b];
		while (temp_b->next) {
			if ((temp_b->numb == temp_c->numb) || (temp_c->numb == b))
				break;
			temp_b = temp_b->next;
		}
		if ((temp_b->numb != temp_c->numb) && (temp_c->numb != b)) {
			node* temp = sozdatnode(temp_c->numb);
			temp_b->next = temp;
		}
		temp_c = temp_c->next;
	}

	temp_b = grafon->nodes[b];
	node* temp_b_prev = NULL;
	while (temp_b) {
		if (temp_b->numb == c) {
			if (temp_b_prev == NULL)
				grafon->nodes[b] = temp_b->next;
			else {
				if (temp_b->next == NULL)
					temp_b_prev->next = NULL;
				else
					temp_b_prev->next = temp_b->next;
			}
			free(temp_b);
			break;
		}
		temp_b_prev = temp_b;
		temp_b = temp_b->next;

	}

	for (int i = c; i < versh - 1; i++)
		grafon->nodes[i] = grafon->nodes[i + 1];
	realloc(grafon->nodes, (versh - 1) * sizeof(node));
	versh--;
	grafon->size--;

	node* temp = NULL;
	for (int i = 0; i < versh; i++) {
		temp = grafon->nodes[i];
		while (temp) {
			if (temp->numb == c)
				temp->numb = b;
			if(temp->numb>=c)
				temp->numb--;
			temp = temp->next;
		}
	}

	return versh;
}


int split_list(graf* grafon, int versh, int b) {
	realloc(grafon->nodes, (versh + 1) * sizeof(node));
	node* temp_b = grafon->nodes[b];
	node* temp_b_prev = NULL;
	node* temp;
	grafon->nodes[versh] = sozdatnode(b);
	int i = 0;
	while (temp_b->next) {
		if ((i % 2) == 1) {
			temp_b_prev->next = temp_b->next;
			temp_b->next = grafon->nodes[versh];
			grafon->nodes[versh] = temp_b;
			temp_b = temp_b_prev->next;
		}
		else {
			temp_b_prev = temp_b;
			temp_b = temp_b->next;
		}
		i++;
	}
	if ((i % 2) == 1) {
		temp_b_prev->next = NULL;
		temp_b->next = grafon->nodes[versh];
		grafon->nodes[versh] = temp_b;
	}
	temp_b = sozdatnode(versh);
	temp_b->next = grafon->nodes[b];
	grafon->nodes[b] = temp_b;
	grafon->size++;
	versh++;
	return versh;
}

graf* num2_list_create() {
	int** a, ** b, i, n, m, n1, m1, j;
	printf("\n   ¬ведите количество вершин: ");
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
	return grafon;
}

void number2_a_list(graf* grafon) {
	int b, c, i, n;
	printf("   ¬ведите номера вершин дл€ отождествлени€: ");
	scanf("%d %d", &b, &c);
	n = grafon->size;
	n = equation_list(grafon, n, b, c);
	node* temp = NULL;
	for (i = 0; i < n; i++) {
		temp = grafon->nodes[i];
		printf("%d", i);
		while (temp) {
			printf("->%d", temp->numb);
			temp = temp->next;
		}
		printf("\n");
	}
}

void number2_b_list(graf* grafon) {
	int b, c, i, n;
	printf("   ¬ведите номера вершин дл€ ст€гивани€: ");
	scanf("%d %d", &b, &c);
	n = grafon->size;
	n=pullin_list(grafon, n, b, c);
	//n = split_list(grafon, n, b);
	node* temp = NULL;
	for (i = 0; i < n; i++) {
		temp = grafon->nodes[i];
		printf("%d", i);
		while (temp) {
			printf("->%d", temp->numb);
			temp = temp->next;
		}
		printf("\n");
	}
}

void number2_v_list(graf* grafon) {
	int b, c, i, n;
	printf("   ¬ыберите номера дл€ расщеплени€: ");
	scanf("%d %d", &b, &c);
	n = grafon->size;
	n = split_list(grafon, n, b);
	node* temp = NULL;
	for (i = 0; i < n; i++) {
		temp = grafon->nodes[i];
		printf("%d", i);
		while (temp) {
			printf("->%d", temp->numb);
			temp = temp->next;
		}
		printf("\n");
	}
}