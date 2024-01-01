#include <iostream>

struct Node
{
	unsigned m_data;
	Node *m_next;
};

class LinkedList
{
	public:
		LinkedList() 
		{
		}
		
		void addNode(unsigned data)
		{
			if((nodes + m_counter)->m_next != nullptr) 
			{
				""
				return;
			}
			(nodes + m_counter)->m_data = data;
			(nodes + m_counter)->m_next = new Node;
			m_counter++;
			(nodes + m_counter)->m_next = nullptr;
		}
			
	private:
		Node *nodes;
		unsigned m_counter = 0;
};
