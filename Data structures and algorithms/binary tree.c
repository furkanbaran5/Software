#include <stdio.h>
#include <stdlib.h>

struct tree {
	
	int data;
	struct tree *leftNode;
	struct tree *rightNode;
	
};

void ekle(struct tree **bt, int data);
void printInOrder(struct tree *bt);
struct tree *findMinValue(struct tree *root);
struct tree* deleteNoede(struct tree *root, int key);
int main() {
	
	//int bt[6] =  {8, 3, 10, 1, 6, 4};
	//binarySearchWithArray(bt, 21);
	
	struct tree *bt = NULL;
	ekle(&bt, 9);
	ekle(&bt, 5);
	ekle(&bt, 14);
	ekle(&bt, 3);
	ekle(&bt, 6);
	ekle(&bt, 1);
	ekle(&bt, 2);
	ekle(&bt, 57);
	ekle(&bt, 8);
	ekle(&bt, 11);
	ekle(&bt, 10);
	ekle(&bt, 13);
	deleteNoede(bt, 9);
	printf("%d\n", bt->data);
	printPreOrder(bt);
	//binarySearch(bt, 8);
	//struct tree* a = findMinValue(bt->rightNode);
	//printf("%d", a->data);
	
	
	free(bt);
	return 0;	
}


void ekle(struct tree **bt, int data){
	
	if(*bt == NULL) {
		
		*bt = malloc(sizeof(struct tree));
		(*bt)->leftNode = NULL;
		(*bt)->rightNode = NULL;
		
		if(bt == NULL) {
			printf("Bellek ayrýlamdi\n");
			return;
		}
		
		(*bt)->data = data;
		return;
	}
	if(data < (*bt)->data)
		ekle(&(*bt)->leftNode, data);
	else
		ekle(&(*bt)->rightNode, data);
	
}

void printInOrder(struct tree *bt) {
	
	if(bt == NULL) {
		return;
	}	
	printInOrder(bt->leftNode);
	printf("data:%d\n", (bt)->data);
	printInOrder(bt->rightNode); 
}

void printPreOrder(struct tree *bt) {
	
	if(bt == NULL) {
		return;
	}
	printf("data:%d\n", (bt)->data);
	printPreOrder(bt->leftNode);
	printPreOrder(bt->rightNode); 
}

void printPostOrder(struct tree *bt) {
	
	if(bt == NULL) {
		return;
	}
	printInOrder(bt->leftNode);
	printInOrder(bt->rightNode);
	printf("data:%d\n", (bt)->data);
}

int binarySearch(struct tree *tree, int value) {
	
	if(tree == NULL) {
		printf("Bulunamadi.\n");
		return -1;
	}
	
	if(value > tree->data){
		binarySearch(tree->rightNode, value);	
	}
	else if(value < tree->data) {
		binarySearch(tree->leftNode, value);	
	}
	else{
		printf("Bulundu.\n");
		return value;	
	}
	
}

int binarySearchWithArray(int dizi[], int value) {
	
	int i = 0;
	while(dizi[i] != value && i < 6) {
		//saða bak
		if(dizi[i] < value) {
			i = 2*i+2;
		}
		//sola bak
		else if(dizi[i] > value) {
			i = 2*i+1;
		}

	}
	if(i>=6) {
		printf("Bulunamadi.\n");
		return -1;
	}
	else {
		printf("Bulundu.\n");
		return i;
	}
}

struct tree *findMinValue(struct tree *root) {
	
	if(root == NULL)
		return NULL;
	
	while(root->leftNode != NULL)
		root = root->leftNode;
	
	return root;
	
}

struct tree* deleteNoede(struct tree *root, int key) {
	
	if(root == NULL){
		return NULL;
	}
	
	if(key < root->data){
		root->leftNode = deleteNoede(root->leftNode, key);
	}
	else if(key > root->data) {
		root->rightNode = deleteNoede(root->rightNode, key);
	}
	else {
		
		if(root->leftNode == NULL) {
			struct tree *tmp = root->rightNode;
			free(root);
			return tmp;
		}
		else if(root->rightNode == NULL) {
			struct tree *tmp = root->leftNode;
			free(root);
			return tmp;
		}
		
		struct tree *tmp = findMinValue(root->rightNode);
		root->data = tmp->data;
		root->rightNode = deleteNoede(root->rightNode, tmp->data);
		
		
	}
	return root;
}





