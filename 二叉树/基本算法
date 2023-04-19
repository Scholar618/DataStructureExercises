#include <iostream>
#include <queue>
#include<math.h>
using namespace std;
typedef char ElemType;

//节点类型
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	ElemType data;
}BTNode;

//创建二叉树节点(初始化)
BTNode* CreatTreeNode(ElemType x) {
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

//创建二叉树
BTNode* CreatBinaryTree() {
	//创建节点
	BTNode* A = CreatTreeNode('A');
	BTNode* B = CreatTreeNode('B');
	BTNode* C = CreatTreeNode('C');
	BTNode* D = CreatTreeNode('D');
	BTNode* E = CreatTreeNode('E');
	BTNode* F = CreatTreeNode('F');
	BTNode* G = CreatTreeNode('G');
	A->left = B;
	B->left = D;
	D->right = G;
	A->right = C;
	C->left = E;
	C->right = F;
	return A;
}

//前序遍历
void PreOrder(BTNode* node) {
	if (node == nullptr) {
		//cout << NULL << " ";
		return;
	}
	cout << node->data << " ";
	PreOrder(node->left);
	PreOrder(node->right);
}



//中序遍历
void MidOrder(BTNode* node) {
	if (node == nullptr) {
		return;
	}
	MidOrder(node->left);
	cout << node->data << " ";
	MidOrder(node->right);
}


//后序遍历
void PostOrder(BTNode* node) {
	if (node == nullptr) {
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	cout << node->data << " ";
}


//层次遍历
void LevOrder(BTNode* node) {
	if (node == nullptr) {
		return;
	}
	queue<BTNode*> q;
	q.push(node);
	while (!q.empty()) {
		int N = q.size();
		for (int i = 0; i < N; i++) {
			BTNode* cur = q.front();
			q.pop();
			cout << cur->data << " ";
			if (cur->left != nullptr) {
				q.push(cur->left);
			}
			if (cur->right != nullptr) {
				q.push(cur->right);
			}
		}
	}
}

//叶子结点
int LeafNode(BTNode* node) {
	if (node == nullptr) {
		return 0;
	}
	if (node->left == nullptr && node->right == nullptr) {
		return 1;
	}
	return LeafNode(node->left) + LeafNode(node->right);
}

//深度
int Depth(BTNode* node) {
	if (node == nullptr) {
		return 0;
	}
	return 1 + max(Depth(node->left), Depth(node->right));

}

int main() {
	BTNode* Node;
	Node = CreatBinaryTree();

	cout << "前序遍历：";
	PreOrder(Node);
	cout << endl;

	cout << "中序遍历：";
	MidOrder(Node);
	cout << endl;

	cout << "后序遍历：";
	PostOrder(Node);
	cout << endl;

	cout << "叶子结点：";
	cout << LeafNode(Node);
	cout << endl;

	cout << "深度：";
	cout << Depth(Node);
	cout << endl;

	return 0;

}
