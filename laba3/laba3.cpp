#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

struct node {
	int numb;
	node *next;
};
struct graf {
	node **nodes;
	int size;
};
int** a,**e, **z;
graf *sozdat(int versh){
	graf *grafon = (graf*) malloc(sizeof(graf));
	grafon->size = versh;
	grafon->nodes = (node**)malloc(versh*sizeof(node*));
	for(int i=0;i<versh;i++){
		grafon->nodes[i]=NULL;
	}
	return grafon;
}
node *sozdatnode(int index){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->numb=index;
	newnode->next=NULL;
	return newnode;
}
void addgran(graf *grafon,int from,int to){
	node *newnode = sozdatnode(from);
	newnode->next = grafon->nodes[to];
	grafon->nodes[to]=newnode;

	newnode = sozdatnode(to);
	newnode->next = grafon->nodes[from];
	grafon->nodes[from]=newnode;
}
int equation_matrix(int **a, int n, int b, int c){
	for (int j=0;j<n;j++){
		if(a[c][j]==1){
			a[b][j] = 1;
			a[j][b] = a[b][j];
		}
	}
	if(a[b][c]==0)
		a[b][b]=0;
	a[b][c] = 0;
	a[c][b] = 0;
	for (int i  = c; i < n - 1; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j] = a[i + 1][j];
	for (int i = 0; i < n; i++) 
		for (int j = c; j < n - 1; j++) 
			a[i][j] = a[i][j + 1]; 
	for(int i=0;i<n-1;i++)
		a[i]= (int*)realloc(a[i],(n-1)*sizeof(int));
	free(a[n-1]);
	n--;
	return n;
}
int pullin_matrix(int **a, int n, int b, int c){
	if(a[b][c]==0){
		printf("Указанные вершины не соединены");
		return 0;
	}
	for (int j=0;j<n;j++){
		if(a[c][j]==1){
			a[b][j] = 1;
			a[j][b] = a[b][j];
		}
	}
	a[b][b] = 0;
	a[b][c] = 0;
	a[c][b] = 0;
	for (int i  = c; i < n - 1; i++) 
		for (int j = 0; j < n; j++) 
			a[i][j] = a[i + 1][j];
	for (int i = 0; i < n; i++) 
		for (int j = c; j < n - 1; j++) 
			a[i][j] = a[i][j + 1]; 
	for(int i=0;i<n-1;i++)
		realloc(a[i],(n-1)*sizeof(int));
	free(a[n-1]);
	n--;
	return n;
}
int split_matrix(int **a, int n, int c){
	realloc(a,(n+1)*sizeof(int));
	for(int i=0;i<n;i++)
		realloc(a[i],(n+1)*sizeof(int)); 
	a[n] = (int*)malloc((n+1) * sizeof(int));
	for (int i=0; i<n/2;i++){
		a[i][n] = a[i][c];
		a[i][c] = 0;
		a[n][i] = a[i][n];
	}
	for (int i=n/2; i<(n+1);i++){
		a[i][n]=0;
		a[n][i] = a[i][n];
	}
	a[c][n]=1;
	a[n][c]=a[c][n];
	n++;
	return n;
}
int equation_list(graf *grafon, int versh, int b, int c){

	node *temp_c = grafon->nodes[c];
	node *temp_b = grafon->nodes[b];
	while (temp_c) {
		temp_b = grafon->nodes[b];
		while (temp_b->next) {
			if (temp_b->numb == temp_c->numb)
				break;
			temp_b = temp_b->next;
		}
		if (temp_b->numb != temp_c->numb){
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

	for(int i=c;i<versh-1;i++)
		grafon->nodes[i]=grafon->nodes[i+1];
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
int pullin_list(graf *grafon, int versh, int b, int c){

	node *temp_b = grafon->nodes[b];
	while(temp_b){
		if(temp_b->numb==c)
			break;
		temp_b=temp_b->next;
	}
	if (temp_b==NULL){
		printf("Указанные вершины не соединены\n");
		system("pause");
		return versh;
	}

	node* temp_c = grafon->nodes[c];
	while(temp_c){
		temp_b = grafon->nodes[b];
		while(temp_b->next){
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

	for (int i = c; i < versh-1; i++)
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
int split_list(graf* grafon, int versh, int b){
	realloc(grafon->nodes, (versh + 1) * sizeof(node));
	node* temp_b = grafon->nodes[b];
	node* temp_b_prev = NULL;
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
int unite(int** b, int n, int m) {
	if (m > n) {
		a=(int**)realloc(a, m * sizeof(*a));
		for (int i=n; i < m; i++)
			a[i] = (int*)calloc(m,sizeof(**a));
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
			a[i] = (int*)realloc(a[i],m*sizeof(**a));
		for (int i = m; i < n; i++)
			free(a[i]);
		n = m;
	}
	else
		m = n;
	int j = 0;
	for (int i = 0; i < m; i++) {
		for (j; j < m; j++) {
			if ((a[i][j] != 1)||(b[i][j] != 1)) {
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
		for (int j=0 ; j < m; j++) {
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
int descartes_multiples_puta_madre(int** b, int n, int m) {
	z = (int**)calloc(m * n, sizeof(int*));
	for (int i = 0; i < m*n; i++) {
		z[i] = (int*)calloc(m * n, sizeof(int));
	}
	int j = 0;
	for (int i = 0; i < n * m; i++) {
		for (j; j < n * m; j++) {
			if (((i / m == j / m) && (b[i % m][j % m] == 1)) || ((a[i / m][j / m] == 1) && (i % m == j % m)))
				z[i][j] = 1;
			else
				z[i][j] = 0;
			z[j][i] = z[i][j];																						//ʕ✿ᵔﻌ•̀ʔ♡				
		}
		j = j - n*m + i + 1;
	}
	return n*m;
}
int **descartes_multiples_puta_madre_zalupers(int **first_matrix, int **second_matrix, int first_size, int second_size){
	int **result_matrix = (int**)calloc(first_size * second_size, sizeof(int*));
	for (int i = 0; i < first_size * second_size; i++) {
		result_matrix[i] = (int*)calloc(first_size * second_size, sizeof(int));
	}
	for (int i = 0; i < first_size; i++)  //строки первой матрицы
		for (int k = 0; k < second_size; k++) //строки второй матрицы
			for (int j = 0; j < first_size; j++) //столбцы первой матрицы
				for (int l = 0; l < second_size; l++)  //столбцы второй матрицы
				{
					if (((i == j) && (second_matrix[k][l] == 1)) || ((k == l) && (first_matrix[i][j] == 1)))  //в случае наличия соединения в одном из графов
					{																					//построение нового соединения в новом графе
						result_matrix[(i+1) * (k+1)-1][(j + 1)* (l + 1)-1] = 1;
						result_matrix[(j + 1) * (l + 1)-1][(i + 1) * (k + 1)-1] = result_matrix[(i + 1) * (k + 1) - 1][(j + 1) * (l + 1) - 1];//декартового произведения
					}
				}	
	return result_matrix;
}
int main(void) {
srand(time(0));
setlocale (LC_ALL, "Russian");
int **d, b,c, i, n, m, j;
//////////////////////////////////////////////////////////////////////////////////
printf("Введите количество вершин для первой матрицы ");
scanf("%d",&n);
a = (int**)malloc(n * sizeof(*a));
j=1;
for (i = 0; i<n; i++){
	a[i] = (int*)malloc(n * sizeof(**a));
}
for (i = 0; i<n; i++){
	a[i][i]=0;
	for (j; j<n; j++){
		  a[i][j]=rand()%2;
		  a[j][i]=a[i][j];
	}
	j=j-n+i+1;
}

for (i=0;i<n;i++){
	a[i][i]=0;
}

for (i=0;i<n;i++){
	for (j=0;j<n;j++){
		printf("%d ",a[i][j]);
	}
	printf("\n");
}
printf("\n");

//////////////////////////////////////////////////////////////////////////////////
printf("Введите количество вершин для второй матрицы ");
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
int **e = descartes_multiples_puta_madre_zalupers(a, d, n, m);
for (i = 0; i < n*m; i++) {
	for (j = 0; j < n * m; j++) {
		printf("%d ", e[i][j]);
	}
	printf("\n");
}
printf("\n");
int l = descartes_multiples_puta_madre(d, n, m);
for (i = 0; i < l; i++) {
	for (j = 0; j < l; j++) {
		printf("%d ", z[i][j]);
	}
	printf("\n");
}
system("pause");
}