#include <iostream>
#include "avlTree.h"

using namespace std;

void avlTree::avlInsert(int myData)
{
	bstInsertRoot(root, myData);
}

void avlTree::bstDeleteFind(avlNode * n, int myData)
{
	if (n->data == myData) {
		//cout << "data found" << endl;
		struct avlNode *c = bstFindLeftMost(n->left);
		if (c != NULL) {
			n->data = c->data;
			n = c;
			if (n->left != NULL) {
				if (n == n->parent->right) {
					n->parent->right = n->left;
					n->left->parent = n->parent;

				}
				else {
					n->parent->left = n->left;
					n->left->parent = n->parent;
				}
				
				avlDeleteControl(n->left);
				free(n);
			}
			else {
				avlDeleteControl(n);
				if (n == n->parent->right) {
					n->parent->right = NULL;

				}
				else {
					n->parent->left = NULL;
				}
				free(n);
			}
		}
		else {
			if (n->right != NULL) {
				if (n->parent != NULL) {
					if (n == n->parent->right) {
						n->parent->right = n->right;
						n->right->parent = n->parent;
						avlDeleteControl(n->right);
						free(n);
					}
					else {
						n->parent->left = n->right;
						n->right->parent = n->parent;
						avlDeleteControl(n->right);
						free(n);
					}
				}
				else {
					n->right->parent = NULL;
					root=n->right;
					free(n);
				}
				
			}
			else {
				if (n->parent != NULL) {
					avlDeleteControl(n);
					if (n == n->parent->right) {
						n->parent->right = NULL;

					}
					else {
						n->parent->left = NULL;
					}
					free(n);

				}
				else {
					root = NULL;
					free(n);

				}
				
			}
			
			
		}
	}else if(n->data > myData && n->left != NULL) {
		bstDeleteFind(n->left, myData);	
	}
	else if (n->data < myData && n->right != NULL) {
		bstDeleteFind(n->right, myData);	
	}
}

avlNode * avlTree::bstFindLeftMost(avlNode * n)
{
	if (n != NULL) {
		if (n->right != NULL) {
			return bstFindLeftMost(n->right);
		}
		else {
			return n;
		}
	}
	return NULL;
}
avlNode * avlTree::sibling(avlNode * n)
{
	if (n != NULL && n->parent != NULL) {
		if (n->parent->left == n) {
			return n->parent->right;
		}
		else return n->parent->left;
	}
	else
		return NULL;
}

void avlTree::avlDeleteControl(avlNode * n)
{
	if (n->parent != NULL) {
		struct avlNode *p = n->parent;
		struct avlNode *s = sibling(n);
		if (n == p->right) {
			p->balCntrl++;
			//cout << n->data << "'s parent balance number is " << p->balCntrl << endl;
			if (p->balCntrl == 2) {
				//cout << n->data << "'s sibling is " << s->data<< "-"<< s->balCntrl << endl;
				if (sibling(n)->balCntrl == 0) {
					//cout << "sdasdasd";
					p->balCntrl = 1;
					s->balCntrl = -1;
					rotate_right(p);
				}
				else if (sibling(n)->balCntrl > 0) {
					p->balCntrl = 0;
					s->balCntrl = 0;
					rotate_right(p);
					avlDeleteControl(s);
				}
				else {
					p->balCntrl = 0;
					s->balCntrl = 0;
					rotate_left(s);
					rotate_right(p);
					avlDeleteControl(s->parent);

				}
				 //avlInsertControl(n->parent);

				/*if (n->parent == NULL) {
				root = n;
				}*/
			}
			else if (n->parent->balCntrl == 0) {
				avlDeleteControl(n->parent);
			}
		}
		else {
			p->balCntrl--;
			//cout << n->data << "'s parent balance number is " << n->parent->balCntrl << endl;
			if (p->balCntrl == -2) {
				if (sibling(n)->balCntrl == 0) {
					p->balCntrl = -1;
					s->balCntrl = 1;
					rotate_left(p);
				}
				else if (sibling(n)->balCntrl < 0) {
					p->balCntrl = 0;
					s->balCntrl = 0;
					rotate_left(p);
					avlDeleteControl(s);
				}
				else {
					p->balCntrl = 0;
					s->balCntrl = 0;
					rotate_right(s);
					rotate_left(p);
					avlDeleteControl(s->parent);

				}
				/*if (n->parent == NULL) {
				root = n;
				}*/
			}
			else if (p->balCntrl == 0) {
				avlDeleteControl(p);
			}
		}
	}
}

void avlTree::avlDelete(int myData)
{

	bstDeleteFind(root, myData);
}

void avlTree::bstInsertRoot(avlNode * n, int myData)
{
	if (n == NULL) {
		//cout << "jkladsdl";
		avlNode* pointer = new avlNode;
		pointer->data = myData;
		pointer->left = NULL;
		pointer->parent = NULL;
		pointer->right = NULL;
		pointer->balCntrl = 0;
		root = pointer;
	}
	else {
		bstInsert(n, myData);
	}

}

void avlTree::bstInsert(avlNode * n, int myData)
{
	if (myData <= n->data) {
		if (n->left != NULL) {
			bstInsert(n->left, myData);
		}
		else {
			avlNode* pointer = new avlNode;
			pointer->data = myData;
			pointer->left = NULL;
			pointer->parent = n;
			pointer->right = NULL;
			pointer->balCntrl = 0;
			n->left = pointer;
			avlInsertControl(n->left);
		}
	}
	else {
		if (n->right != NULL) {
			bstInsert(n->right, myData);
		}
		else {
			avlNode* pointer = new avlNode;
			pointer->data = myData;
			pointer->left = NULL;
			pointer->parent = n;
			pointer->right = NULL;
			pointer->balCntrl = 0;
			n->right = pointer;
			avlInsertControl(n->right);
		}
	}
	
}

void avlTree::avlInsertControl(avlNode * n)
{
	if (n->parent != NULL) {
		struct avlNode *p = n->parent;
		if (n == p->right) {
			p->balCntrl--;
			//cout << n->data << "'s parent balance number is " << p->balCntrl << endl;
			if (p->balCntrl == -2) {
				if (n->balCntrl > 0) {
					rotate_right(n);
					rotate_left(p);
					if (n->parent->balCntrl < 0) {
						p->balCntrl = 1;
						n->balCntrl = 0;
					}
					else if(n->parent->balCntrl > 0) {
						p->balCntrl = 0;
						n->balCntrl = -1;
					}
					else {
						p->balCntrl = 0;
						n->balCntrl = 0;
					}
					n->parent->balCntrl = 0;
				}
				else {
					rotate_left(p);
					p->balCntrl = 0;
					n->balCntrl = 0;
					
				}
				
				/*if (n->parent == NULL) {
					root = n;
				}*/
			}
			else if (n->parent->balCntrl == -1) {
				avlInsertControl(n->parent);
			}
		}
		else {
			p->balCntrl++;
			//cout << n->data << "'s parent balance number is " << n->parent->balCntrl << endl;
			if (p->balCntrl == 2) {
				if (n->balCntrl < 0) {
					rotate_left(n);
					rotate_right(p);
					if (n->parent->balCntrl < 0) {
						p->balCntrl = 0;
						n->balCntrl = 1;
					}
					else if (n->parent->balCntrl > 0) {
						p->balCntrl = -1;
						n->balCntrl = 0;
					}
					else {
						p->balCntrl = 0;
						n->balCntrl = 0;
					}
					n->parent->balCntrl = 0;
				}
				else {
					rotate_right(p);
					p->balCntrl = 0;
					n->balCntrl = 0;
				}
				
				/*if (n->parent == NULL) {
					root = n;
				}*/
			}
			else if (p->balCntrl == 1) {
				avlInsertControl(p);
			}
		}
	}
}

void avlTree::rotate_left(avlNode * n)
{
	avlNode* r = n->right;
	replace_node(n, r);
	n->right = r->left;
	if (r->left != NULL)
	{
		r->left->parent = n;
	}
	r->left = n;
	n->parent = r;
}

void avlTree::rotate_right(avlNode * n)
{
	avlNode* L = n->left;
	replace_node(n, L);
	n->left = L->right;
	if (L->right != NULL)
	{
		L->right->parent = n;
	}
	L->right = n;
	n->parent = L;
}

void avlTree::replace_node(avlNode * oldn, avlNode * newn)
{
	if (oldn->parent == NULL)
	{
		root = newn;
	}
	else
	{
		if (oldn == oldn->parent->left)
			oldn->parent->left = newn;
		else
			oldn->parent->right = newn;
	}
	if (newn != NULL)
	{
		newn->parent = oldn->parent;
	}
}
void avlTree::bst_print_dot_null(int key, int nullcount, FILE * stream)
{
	fprintf(stream, "    null%d [shape=point];\n", nullcount);
	fprintf(stream, "    %d -> null%d;\n", key, nullcount);
}

void avlTree::bst_print_dot_aux(avlNode * node, FILE * stream)
{
	static int nullcount = 0;
	/*if (node->color == 'b') {
		fprintf(stream, "    %d [style=filled,fillcolor = gray];\n", node->data);
	}
	else {
		fprintf(stream, "    %d [style=filled,fillcolor = red];\n", node->data);
	}*/

	if (node->left != NULL)
	{
		fprintf(stream, "    %d -> %d;\n", node->data, node->left->data);

		bst_print_dot_aux(node->left, stream);
	}
	else
		bst_print_dot_null(node->data, nullcount++, stream);

	if (node->right != NULL)
	{
		fprintf(stream, "    %d -> %d;\n", node->data, node->right->data);
		bst_print_dot_aux(node->right, stream);
	}
	else
		bst_print_dot_null(node->data, nullcount++, stream);
}

void avlTree::bst_print_dot(avlNode * node, FILE * stream)
{
	fprintf(stream, "digraph BST {\n");
	fprintf(stream, "    node [fontname=\"Arial\"];\n");

	if (node == NULL)
		fprintf(stream, "\n");
	else if (node->right == NULL  && !node->left == NULL)
		fprintf(stream, "    %d;\n", node->data);
	else
		bst_print_dot_aux(node, stream);

	fprintf(stream, "}\n");
}

void avlTree::to_bst_print_dot(FILE * stream)
{
	bst_print_dot(root, stream);
}

void avlTree::tobstsearch(int myData)
{
	if (bstsearch(root, myData)) {
		//cout << myData << " found." << endl;
	}
	else {
		//cout << myData << " not found." << endl;
	}
}

bool avlTree::bstsearch(avlNode * n, int myData)
{
	
	if (myData == n->data) {
		return true;
	}else if(myData <= n->data){
		if (n->left != NULL) {
			return bstsearch(n->left, myData);
		}
		
	}
	else {
		if (n->right != NULL) {
			return bstsearch(n->right, myData);
		}
	}
	return false;
}
