#include <stdio.h>
#include <stdlib.h>
#include "bstTree.h"

void visitBST(BSTree t);

int main(int argc,char *argv[]){
	if( argc == 2 ){
		int delnum = atoi(argv[1]);
		BSTree header = NULL;

		CreateBST(&header);
		visitBST(header);
		printf("\n");
		deleteBST(header,NULL,delnum);
		visitBST(header);
		printf("\n");
	}

	return 0;
}

void visitBST(BSTree t){
	if( t ){
		printf("%-5d", t->data);
		visitBST(t->lchild);
		visitBST(t->rchild);
	}
}
