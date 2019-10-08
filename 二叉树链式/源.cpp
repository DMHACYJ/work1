
#include "BinaryTree.h"
#include<queue>
#include<stack>
#include<iostream>
#include<iomanip>
using namespace std;
BTNode* BinaryTreeCreate(BTDataType* a, int* pi) {
	if (a[*pi] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else return NULL;
}

void BinaryTreeDestory(BTNode** root) {
	BTNode* curRoot = *root;
	if (curRoot) {
		BinaryTreeDestory(&curRoot->_left);
		BinaryTreeDestory(&curRoot->_right);
		free(curRoot);
		*root = NULL;
	}
}
int BinaryTreeSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
//叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;
	//root为叶子节点
	if (root->_left == NULL && root->_right == NULL) return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//找到值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {	BTNode* ret;	if (root == NULL) return NULL;	if (x == root->_data) return root;	ret = BinaryTreeFind(root->_left, x);	if (ret) return ret;	ret = BinaryTreeFind(root->_right, x);	if (ret) return ret;	return NULL;}void BinaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else printf("# ");
}
void BinaryTreeInOrder(BTNode* root) {
	if (root) {
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else printf("# ");
}
void BinaryTreePostOrder(BTNode* root) {
	if (root) {
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else printf("# ");
}
// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	queue<BTNode*> q;
	//根节点入队
	if (root) q.push(root);
	while (q.empty() == 0) {
		BTNode* front = q.front();
		printf("%c ", front->_data);
		q.pop();
		if (front->_left) q.push(front->_left);
		if (front->_right) q.push(front->_right);
	}
	printf("\n");
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {
	queue<BTNode*> q;
	//根节点入队
	if (root) q.push(root);
	while (q.empty() == 0) {
		BTNode* front = q.front();
		q.pop();
		if (front) {
			q.push(front->_left);
			q.push(front->_right);
		}
		else break;
	}
	while(q.empty() == 0) {
		if (q.front()) {
			while (!q.empty()) q.pop();
			return 0;
		}
		q.pop();
	}
	return 1;
}
void BinaryTreePrevOrderNonR(BTNode* root) {
	if (root == NULL) return;
	stack<BTNode*> s;
	BTNode* p = root;
	while (!s.empty() || p) {
		//边遍历边打印，并存入栈中，后面借助根节点
		while (p) {
			cout << setw(4) << p->_data;
			s.push(p);
			p = p->_left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			p = p->_right;
		}
	}
	cout << endl;
}
void BinaryTreeInOrderNonR(BTNode* root) {
	if (root == NULL) return;
	stack<BTNode*> s;
	BTNode* p = root;
	while (!s.empty() || p) {
		//边遍历边打印，并存入栈中，后面借助根节点
		if(p) {
			s.push(p);
			p = p->_left;
		}
		if (!s.empty()) {
			p = s.top();
			s.pop();
			cout << setw(4) << p->_data;
			p = p->_right;
		}
	}
}
void BinaryTreePostOrderNonR(BTNode* root) {
	if (root == NULL) return;
	stack<BTNode*> s;
	//    当前访问节点  上一次访问节点
	BTNode* pcur, *pLastVist;

	pcur = root;
	pLastVist = NULL;
	while (pcur) {
		s.push(pcur);
		pcur = pcur->_left;
	}
	while (!s.empty()) {
		//pcur是空，已经遍历到左子树低端
		pcur = s.top();
		s.pop();
		//一个根节点被访问的前提是，无右子树或右子树已被访问过
		if (pcur->_right == NULL || pcur->_right == pLastVist) {
			cout << setw(4) << pcur->_data;
			//修改最近被访问的节点
			pLastVist = pcur;
		}
		//else if (pcur->_left == pLastVist) {//多左子树刚被访问过，则需先进入右子树（根节点需再次入栈）
		else {
			//根节点再次入栈
			s.push(pcur);
			//进入右子树，且可肯定右子树一定不为空
			pcur = pcur->_right;
			while (pcur) {
				s.push(pcur);
				pcur = pcur->_left;
			}
		}
	}
	cout << endl;
}

void testBTree1() {
	int i = 0;
	char a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	BTNode* root = BinaryTreeCreate(a, &i);
//	BinaryTreePrevOrder(root);
//	printf("\n");
//	i = BinaryTreeLeafSize(root);
//	BinaryTreeDestory(&root);
	BinaryTreeLevelOrder(root);
	BinaryTreeComplete(root);
}
int main() {
	testBTree1();
	system("pause");
	return 0;
}