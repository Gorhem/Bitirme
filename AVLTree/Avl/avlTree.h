#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
struct avlNode {
	int data;
	avlNode *left;
	avlNode *right;
	avlNode *parent;
	int balCntrl;

};


class avlTree {
	struct avlNode* root;
public:
	avlTree() {
		root = NULL;
	}
	void avlInsert(int myData);
	void bstDeleteFind(avlNode * n, int myData);
	avlNode * bstFindLeftMost(avlNode * n);
	avlNode * sibling(avlNode * n);
	void avlDeleteControl(avlNode* n);
	void avlDelete(int myData);
	void bstInsertRoot(avlNode * n, int myData);
	void bstInsert(avlNode * n, int myData);
	void avlInsertControl(avlNode* n);
	void rotate_left(avlNode * n);
	void rotate_right(avlNode * n);
	void replace_node(avlNode * oldn, avlNode * newn);
	void bst_print_dot_null(int key, int nullcount, FILE* stream);
	void bst_print_dot_aux(avlNode* node, FILE* stream);
	void bst_print_dot(avlNode* node, FILE* stream);
	void to_bst_print_dot(FILE* stream);
	void tobstsearch(int data);
	bool bstsearch(avlNode*n, int data);
};




#endif
