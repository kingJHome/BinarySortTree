#include <stdlib.h>
#include "bstTree.h"

//删除结点
void deleteNode(BSTree t,BSTree del){

}

//搜索结点
void searchNode(BSTree t,int key,BSTree *parent,BSTree *del){
	*parent = NULL;
	*del = t;

	while( *del && !EQ((*del)->data,key) ){
		*parent = *del;
		if( LT((*del)->data,key) ){
			*del = (*del)->rchild;
		}else{
			*del = (*del)->lchild;
		}
	}
}

BSTree searchBST(BSTree t,int key){
	if(!t || EQ(t->data,key) || !t->lchild&&!t->rchild){
		return t;
	}else if( LT(t->data,key) ){
		return searchBST(t->rchild,key);
	}else{
		return searchBST(t->lchild,key);
	}
}

void insertBST(BSTree *t,int key){
	if( *t == NULL ){
		BSTree newNode = (BSTree)malloc(sizeof(bstNode));
		if( newNode ){
			newNode->data = key;
			newNode->lchild = newNode->rchild = NULL;
			*t = newNode;
		}
	}else{
		BSTree temp = *t;

		if( EQ(temp->data, key) ){
			return;
		}else if( LT(temp->data,key) ){
			insertBST(&(temp->rchild),key);
		}else if( GT(temp->data,key) ){
			insertBST(&(temp->lchild),key);
		}
	}
}

void deleteBST(BSTree t,int key){
	if( t ){//被删除结点在树中
		BSTree parent,delNode;
		searchNode();
	}
}
