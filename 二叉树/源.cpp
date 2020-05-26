#include<iostream>
using namespace std;

template <typename T>
class binaryTreeNode {
public:
	T element;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;
	binaryTreeNode() { leftChild = NULL; rightChild = NULL; }
	binaryTreeNode(T x) : element(x){};
};

template <typename T>
class binaryTree {
private:
	binaryTreeNode<T>* mRoot;//树根
	int getSize(binaryTreeNode<T>* root);
	int getHeight(binaryTreeNode<T>* root);
	void preOrder(binaryTreeNode<T>* root);
	void inOrder(binaryTreeNode<T>* root);
	void postOrder(binaryTreeNode<T>* root);
	void distroy(binaryTreeNode<T>*& pNode);
	void Create(binaryTreeNode<T>*&);
	void copy(binaryTreeNode<T>*& b, binaryTreeNode<T> *root);
public:
	binaryTree() ;
	~binaryTree() ;
	void Create();//递归的创建二叉树的节点

	int getSize();//递归得到树的节点数目
	int getHeight();//递归得到树的高度

	//递归遍历
	void preOrder();//前序遍历
	void inOrder();//中序遍历
	void postOrder();//后序遍历
	
	void copy(binaryTree<T> B);//复制
	binaryTreeNode<T>* getroot();

	void clear();//清空
	bool isempty();//判空
};

template <typename T>
void binaryTree<T>::Create()//递归的创建二叉树的节点
{
	Create(mRoot);
}
template <typename T>
void binaryTree<T>::Create(binaryTreeNode<T>*& root)//递归的创建二叉树的节点
{
	T ch;
	cin >> ch;
	if (ch == '#')
	{
		root = NULL;
	}
	else
	{
		root = new binaryTreeNode<T>(ch);
		Create(root->leftChild);
		Create(root->rightChild);
	}
}

template <typename T>
void binaryTree<T>::preOrder()//前序遍历
{
	if (mRoot == NULL)
	{
		cout << "这是个空二叉树" << endl;
	}
	else
	{
		cout << "前序遍历：";
		preOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::preOrder(binaryTreeNode<T>* node)//前序遍历
{
	if (node)
	{
		cout << node->element << " ";
		preOrder(node->leftChild);
		preOrder(node->rightChild);
	}
}
template <typename T>
void binaryTree<T>::inOrder()//中序遍历
{
	if (mRoot == NULL)
	{
		cout << "这是个空二叉树" << endl;
	}
	else
	{
		cout << "中序遍历：";
		inOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::inOrder(binaryTreeNode<T>* node)//中序遍历
{
	if (node)
	{
		inOrder(node->leftChild);
		cout << node->element << " ";
		inOrder(node->rightChild);
	}
}
template <typename T>
void binaryTree<T>::postOrder()//后序遍历
{
	if (mRoot == NULL)
	{
		cout << "这是个空二叉树" << endl;
	}
	else
	{
		cout << "后序遍历：";
		postOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::postOrder(binaryTreeNode<T>* node)//后序遍历
{
	if (node)
	{
		postOrder(node->leftChild);
		postOrder(node->rightChild);
		cout << node->element << " ";
	}
}
template <typename T>
int binaryTree<T>::getHeight()
{
	return getHeight(mRoot);
}
template <typename T>
int binaryTree<T>::getHeight(binaryTreeNode<T>* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int left = getHeight(root->leftChild);
		int right = getHeight(root->rightChild);
		int height = left > right ? (left + 1) : (right + 1);
		return height;
	}
}
template <typename T>
int binaryTree<T>::getSize()
{
	return getSize(mRoot);
}
template <typename T>
int binaryTree<T>::getSize(binaryTreeNode<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return getSize(root->leftChild) + getSize(root->rightChild) + 1;
}
template <typename T>
binaryTree<T>::binaryTree()
{
	mRoot = NULL;
}
template <typename T>
binaryTree<T>::~binaryTree() 
{
	distroy(mRoot);
}
template <typename T>
void binaryTree<T>::distroy(binaryTreeNode<T>*& pNode)
{
	if (pNode)
	{
		distroy(pNode->leftChild);
		distroy(pNode->rightChild);
		delete pNode;
		pNode = NULL;
	}
}
template <typename T>
void binaryTree<T>::copy(binaryTree<T> B)
{
	copy(mRoot, B.getroot());
}
template <typename T>
void binaryTree<T>::copy(binaryTreeNode<T>*& b, binaryTreeNode<T> *root)
{
	if (root == NULL)
	{
		b = NULL;
		return;
	}
	else
	{
		//T val = root->element;
		b = new binaryTreeNode<T>(root->element);
		copy(b->leftChild, root->leftChild);
		copy(b->rightChild, root->rightChild);
	}
}
template <typename T>
binaryTreeNode<T>* binaryTree<T>::getroot()
{
	return mRoot;
}
template <typename T>
void binaryTree<T>::clear()
{
	mRoot = NULL;
}
template <typename T>
bool  binaryTree<T>::isempty()//判空
{
	if (mRoot == NULL)
		return true;
	else return false;
}
int main()
{
	binaryTree<char> A;
	A.Create();
	A.preOrder();
	A.inOrder();
	A.postOrder();
	cout << "该二叉树的深度为：" << A.getHeight() << endl;
	cout << "该二叉树的节点数为：" << A.getSize() << endl;
	cout << A.isempty() << endl;
	binaryTree<char> b;
	b.copy(A);
	b.preOrder();
	A.clear();
	A.inOrder();
	cout << A.isempty() << endl;
	system("pause");
	return 0;
}