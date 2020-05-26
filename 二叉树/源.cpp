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
	binaryTreeNode<T>* mRoot;//����
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
	void Create();//�ݹ�Ĵ����������Ľڵ�

	int getSize();//�ݹ�õ����Ľڵ���Ŀ
	int getHeight();//�ݹ�õ����ĸ߶�

	//�ݹ����
	void preOrder();//ǰ�����
	void inOrder();//�������
	void postOrder();//�������
	
	void copy(binaryTree<T> B);//����
	binaryTreeNode<T>* getroot();

	void clear();//���
	bool isempty();//�п�
};

template <typename T>
void binaryTree<T>::Create()//�ݹ�Ĵ����������Ľڵ�
{
	Create(mRoot);
}
template <typename T>
void binaryTree<T>::Create(binaryTreeNode<T>*& root)//�ݹ�Ĵ����������Ľڵ�
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
void binaryTree<T>::preOrder()//ǰ�����
{
	if (mRoot == NULL)
	{
		cout << "���Ǹ��ն�����" << endl;
	}
	else
	{
		cout << "ǰ�������";
		preOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::preOrder(binaryTreeNode<T>* node)//ǰ�����
{
	if (node)
	{
		cout << node->element << " ";
		preOrder(node->leftChild);
		preOrder(node->rightChild);
	}
}
template <typename T>
void binaryTree<T>::inOrder()//�������
{
	if (mRoot == NULL)
	{
		cout << "���Ǹ��ն�����" << endl;
	}
	else
	{
		cout << "���������";
		inOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::inOrder(binaryTreeNode<T>* node)//�������
{
	if (node)
	{
		inOrder(node->leftChild);
		cout << node->element << " ";
		inOrder(node->rightChild);
	}
}
template <typename T>
void binaryTree<T>::postOrder()//�������
{
	if (mRoot == NULL)
	{
		cout << "���Ǹ��ն�����" << endl;
	}
	else
	{
		cout << "���������";
		postOrder(mRoot);
		cout << endl;
	}
}
template <typename T>
void binaryTree<T>::postOrder(binaryTreeNode<T>* node)//�������
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
bool  binaryTree<T>::isempty()//�п�
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
	cout << "�ö����������Ϊ��" << A.getHeight() << endl;
	cout << "�ö������Ľڵ���Ϊ��" << A.getSize() << endl;
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