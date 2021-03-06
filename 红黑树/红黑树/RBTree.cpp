#include<utility>
#include<iostream>
using namespace std;
enum COLOR {
	BLACK,
	RED
};
//节点存放<K, V>数据
template<class K, class V>
struct RBNode {
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V> _value;
	//颜色
	COLOR _color;
	RBNode(const pair<K, V>& value = pair<K, V>())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template<class K, class V>
class RBTree {
public:
	typedef RBNode<K, V> Node;
	typedef Node* pNode;
	RBTree() {
		//构建空的红黑树
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}
	bool insert(const pair<K, V>& value) {
		//搜索树的插入
		if (_header->_parent == nullptr) {
			//空树，创建根节点
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		}
		//从根开始搜索
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur) {
			parent = cur;
			//按照key的值确定位置，key不能重复
			if (cur->_value.first == value.first)
				return false;
			else if (cur->_value.first > value.first)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (parent->_value.first > cur->_value.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//调整和更新(颜色)：连续的红色时需要调整
		while (cur != _header->_parent && cur->_parent->_color == RED) {
			//cur, p, u, g
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent) {
				pNode uncle = gfather->_right;
				// uncle存在且为红
				if (uncle && uncle->_color == RED) {
					//修改颜色
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else {
					//如果存在双旋的场景，可以先进行一次单旋，使它变成单旋的场景
					if (cur == parent->_right) {
						RotateL(parent);
						swap(cur, parent);
					}
					//右旋
					RotateR(gfather);
					//修改颜色
					parent->_color = BLACK;
					gfather->_color = RED;
					//停止调整
					break;
				}
			}
			else {
				pNode uncle = gfather->_left;
				// uncle存在且为红
				if (uncle && uncle->_color == RED) {
					//修改颜色
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					//继续向上更新
					cur = gfather;
				}
				else {
					//如果存在双旋的场景，可以先进行一次单旋，使它变成单旋的场景
					if (cur == parent->_left) {
						RotateR(parent);
						swap(cur, parent);
					}
					//右旋
					RotateL(gfather);
					//修改颜色
					parent->_color = BLACK;
					gfather->_color = RED;
					//停止调整
					break;
				}
			}
		}
		//根的颜色始终是黑的
		_header->_color = BLACK;
		//更新header->left, _header->_right
		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	pNode leftMost() {
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr) {
			cur = cur->_left;
		}
		return cur;
	}

	pNode rightMost() {
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr) {
			cur = cur->_right;
		}
		return cur;
	}

	void RotateR(pNode parent) {
		pNode subL = parent->_left;
		pNode subLR = subL->_right;
		//1
		subL->_right = parent;
		//2
		parent->_left = subLR;
		//3
		if (subLR)
			subLR->_parent = parent;
		//4, 5
		if (parent != _header->_parent) {
			//subL <---> parent->parent;
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = gParent;
			subL->_parent = gParent;
		}
		else {
			//更新根节点
			_header->_parent = subL;
			subL->_parent = nullptr;
		}
		//6
		parent->_parent = subL;
	}

	void RotateL(pNode parent) {
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent != _header->_parent) {
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subR;
			else
				gParent->_right = subR;
			subR->_parent = gParent;
		}
		else {
			_header->_parent = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;
	}

	void inOrder() {
		_inOrder(_header->_parent);
		cout << endl;
	}

	void _inOrder(pNode root) {
		if (root) {
			_inOrder(root->_left);
			cout << " ( " << root->_value.first << "--->" << root->_value.second << " ) ";
			_inOrder(root->_right);
		}
	}

private:
	pNode _header;
};

void testRBTree() {
	RBTree<int, int> rbt;
	rbt.insert(make_pair(1, 1));
	rbt.insert(make_pair(10, 1));
	rbt.insert(make_pair(-1, 1));
	rbt.insert(make_pair(-2, 1));
	rbt.insert(make_pair(100, 1));
	rbt.insert(make_pair(19, 1));
	rbt.insert(make_pair(21, 1));
	rbt.inOrder();
}

int main() {
	testRBTree();
	return 0;
}