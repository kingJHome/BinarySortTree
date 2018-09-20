#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstTree.h"

//删除结点
void deleteNode(BSTree del,BSTree parent){
	if( parent ){//删除结点不为根结点
		int direction = 0;//判断删除结点是父结点的左孩子还是右孩子
		
		if( GT(del->data,parent->data) ){
			direction = 1;
		}

		if(del->lchild && del->rchild){//被删除结点的左右子树都存在
			BSTree prev = del,
				   move = del->lchild;

			for( ; move && move->rchild; prev = move,move = move->rchild);
			del->data = move->data;
			if( move->lchild ){
				prev->rchild = move->lchild;
			}else{
				prev->rchild = NULL;
			}
			del = move;
		}else if(!del->lchild && del->rchild){//被删除结点右子树存在
			if( direction ){
				parent->rchild = del->rchild;
			}else{
				parent->lchild = del->rchild;
			}
		}else if(del->lchild && !del->rchild){//被删除结点左子树存在
			if( direction ){
				parent->rchild = del->lchild;
			}else{
				parent->lchild = del->lchild;
			}
		}
	}else{//删除结点为根结点
		BSTree prev = del,
			   lch = del->lchild;
		
		for( ; lch && lch->rchild; prev = lch,lch = lch->rchild);
		del->data = lch->data;
		if( lch->lchild ){
			if( prev == del ){
				del->lchild = lch->lchild;
			}else{
				prev->rchild = lch->lchild;
			}
		}else{
			if( prev == del ){
				del->lchild = NULL;
			}else{
				prev->rchild = NULL;
			}
		}
		del = lch;
	}
	del->lchild = del->rchild = NULL;
	free(del);
}

BSTree searchBST(BSTree t,int key){
	if(!t || EQ(t->data,key)){
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

void deleteBST(BSTree t,BSTree parent,int key){
	if( t ){
		if( EQ(t->data,key) ){
			deleteNode(t,parent);
		}else if( LT(t->data,key) ){
			deleteBST(t->rchild,t,key);
		}else if( GT(t->data,key) ){
			deleteBST(t->lchild,t,key);
		}
	}
}

void CreateBST(BSTree *t){
	FILE *fp = fopen("searchtree.txt","r");

	if( fp ){
		char *reads = NULL,
			 seperator[] = " ",
			 *sepestr = NULL;
		size_t rebuf = 0,getbuf = 0;

		getbuf = getline(&reads, &rebuf, fp);
		if(getbuf != -1){
			fclose(fp);

			//读取关键字
			sepestr = strtok(reads,seperator);
			while( sepestr ){
				int key = atoi(sepestr);
				insertBST(t, key);
				sepestr = strtok(NULL,seperator);
			}
		}
	}
}
