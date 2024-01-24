#pragma once
#include <iostream>

class Node
{
public:
    int m_key;
    Node* m_leftSon;
    Node* m_rightSon;

    Node(int key = 0) : m_key(key), m_leftSon(nullptr), m_rightSon(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree() : m_root(nullptr) {}
    ~BinaryTree() { destroy_tree(m_root); }

	bool search(int key) { return search(m_root, key); }
    void Delete(int key) { Delete(m_root, key); }
    void inorder_print() { inorder_print(m_root); }
    void postorder_print() { postorder_print(m_root); }
    void preorder_print() { preorder_print(m_root); }

	void insert(int key) 
	{
		if(search(key)) 
		{
			std::cout<<"Duplicate data "<<key<<"\n";
			return;
		}
		insert(m_root, key); 
	}

private:
    void insert(Node*& node, int m_key)
	{
        if (!node)
		{ 
			node = new Node(m_key);
			return;
		}

		if (m_key < node->m_key) { insert(node->m_leftSon, m_key); }
		else { insert(node->m_rightSon, m_key); }
    }
    bool search(Node* node, int m_key)
	{
        if (!node) return false;
        if (m_key == node->m_key) return true;

		else if (m_key < node->m_key) return search(node->m_leftSon, m_key);
		else return search(node->m_rightSon, m_key);
    }

	void preorder_print(Node* node)
	{
		if (!node) return;

		std::cout << node->m_key << " ";
		preorder_print(node->m_leftSon);
		preorder_print(node->m_rightSon);
	}
    void inorder_print(Node* node)
	{
        if (!node) return;

		inorder_print(node->m_leftSon);
		std::cout << node->m_key << " ";
		inorder_print(node->m_rightSon);
    }
    void postorder_print(Node* node)
	{
        if (!node) return;

		postorder_print(node->m_leftSon);
		postorder_print(node->m_rightSon);
		std::cout << node->m_key << " ";
    }

    void destroy_tree(Node*& node)
	{
        if (!node) return;

		destroy_tree(node->m_leftSon);
		destroy_tree(node->m_rightSon);
		delete node;
		node = nullptr;
    }

	Node* findMin(Node *node)
	{
		while(!(node->m_leftSon)) node = node->m_leftSon;
		return node;
	}

	Node* Delete(Node *node, int key)
	{
		//base cases
		if(!node)
		{
			std::cout<<"Tree is empty\n";
			return node;
		}
		else if(key < node->m_key)
		{
			node->m_leftSon = Delete(node->m_leftSon, key);
		}
		else if(key > node->m_key)
		{
			node->m_rightSon = Delete(node->m_rightSon, key);
		}
		else
		{
			if(!(node->m_leftSon) && !(node->m_rightSon))
			{
				delete node;
				node = nullptr;
				return nullptr;
			}

			if (!(node->m_leftSon))
			{
				Node *tem = node->m_rightSon;
				delete node;
				return tem;
			}

			if (!(node->m_rightSon))
			{
				Node *tem = node->m_leftSon;
				delete node;
				return tem;
			}

			//if both are non null traverse to the right and find the lowest val of the right tree
			Node* temp = findMin(node->m_rightSon);
			node->m_key = temp->m_key;
			node->m_rightSon = Delete(node->m_rightSon, temp->m_key);

		}
		return node;
	}

    Node* m_root;
};
