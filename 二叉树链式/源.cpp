
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
//Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;
	//rootΪҶ�ӽڵ�
	if (root->_left == NULL && root->_right == NULL) return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
//��K��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL) return 0;
	if (k == 1) return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
//�ҵ�ֵΪx�Ľڵ�
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
// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root) {
	queue<BTNode*> q;
	//���ڵ����
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
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root) {
	queue<BTNode*> q;
	//���ڵ����
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
		//�߱����ߴ�ӡ��������ջ�У�����������ڵ�
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
		//�߱����ߴ�ӡ��������ջ�У�����������ڵ�
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
	//    ��ǰ���ʽڵ�  ��һ�η��ʽڵ�
	BTNode* pcur, *pLastVist;

	pcur = root;
	pLastVist = NULL;
	while (pcur) {
		s.push(pcur);
		pcur = pcur->_left;
	}
	while (!s.empty()) {
		//pcur�ǿգ��Ѿ��������������Ͷ�
		pcur = s.top();
		s.pop();
		//һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�
		if (pcur->_right == NULL || pcur->_right == pLastVist) {
			cout << setw(4) << pcur->_data;
			//�޸���������ʵĽڵ�
			pLastVist = pcur;
		}
		//else if (pcur->_left == pLastVist) {//���������ձ����ʹ��������Ƚ��������������ڵ����ٴ���ջ��
		else {
			//���ڵ��ٴ���ջ
			s.push(pcur);
			//�������������ҿɿ϶�������һ����Ϊ��
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