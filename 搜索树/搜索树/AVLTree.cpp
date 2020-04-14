

template<class T>
struct AVLNode {
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;
	//Æ½ºâÒò×Ó
	int _bf;

	AVLNode(const T& value = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class T> 
class AVLTree {
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;
private:
	pNode _root;
};