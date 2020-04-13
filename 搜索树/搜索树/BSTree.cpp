#include<iostream>
using namespace std;
template<class T>
struct BSTNode {
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _value;

	BSTNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_value(value)
	{}
};

template<class T>
class BSTree{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	pNode find(const T& value) {
		pNode cur = _root;
		while (cur) {
			if (cur->_value == value)
				return cur;
			else if (cur->_value > value)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return cur;
	}

	bool insert(const T& value) {
		//空树
		if (_root == nullptr) {
			_root = new Node(value);
			return true;
		}
		//搜索
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur) {
			parent = cur;
			if (cur->_value == value)
				return false;
			else if (cur->_value > value)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(value);
		//判断节点的位置
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	void inOrder(pNode root) {
		if (_root) {
			inOrder(root->_left);
			cout << root->_value << " ";
			inOrder(root->_right);
		}
		cout << endl;
	}

	void inOrder() {
		inOrder(_root);
	}

	bool erase(const T& value) {
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur) {
			if (cur->_value == value)
				break;
			else if (cur->_value > value) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				parent = cur;
				cur = cur->_right;
			}
		}
		//判断节点是否存在
		if (cur == nullptr)
			return false;
		//cur -> left == nullptr: 1.cur为叶子节点，2.只有右子树的非叶子节点
		if (cur->_left == nullptr) {
			if (cur != _root) {
				//更新父节点和孩子节点的链接
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else
				_root = cur->_right;
			delete cur;
			cur = nullptr;
		}
		else if (cur->_right == nullptr) {
			if (cur != _root) {
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left
			}
			else
				_root = cur->_left;
			delete cur;
			cur = nullptr;
		}
		else {
			//左右孩子都存在
			//1.找左子树的最右节点/右子树的最左节点
			pNode pNext = cur->_left;
			pNode parent = cur;
			while (pNext->_right) {
				parent = pNext;
				pNext = pNext->_right;
			}
			//交换值
			cur->_value = pNext->_value;
			if (parent->_left == pNext)
				parent->_left = pNext->_left;
			else
				parent->_right = pNext->_left;
			//删除找到的节点
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}
 private:
	pNode _root = nullptr;
};

void testBSTree() {
	BSTree<int> bst;
	cout << bst.insert(5) << endl;
	cout << bst.insert(3) << endl;
	cout << bst.insert(1) << endl;
	cout << bst.insert(0) << endl;
	cout << bst.insert(2) << endl;
	cout << bst.insert(7) << endl;
	cout << bst.insert(6) << endl;
	cout << bst.insert(8) << endl;
	cout << bst.insert(9) << endl;

	bst.inOrder();
	bst.erase(0);// 12356789
	bst.inOrder();
	bst.erase(8);// 1235679
	bst.inOrder();
	bst.erase(3);// 125679
	bst.inOrder();
	bst.erase(5);// 12679
	bst.inOrder();
	bst.erase(2);// 1679
	bst.inOrder();
}
int main() {
	testBSTree();
	return 0;
}