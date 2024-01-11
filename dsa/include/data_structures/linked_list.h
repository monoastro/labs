#include <iostream>

struct Node
{
    float m_data;
    Node* m_next;

    Node(float data = 0) : m_data(data), m_next(nullptr) {}
};

class singlyLinkedList
{
public:
    singlyLinkedList() : m_first(nullptr) {}

    void insert_beg(float data)
	{
        Node* new_node = new Node(data);
        new_node->m_next = m_first;
        m_first = new_node;
    }

    void insert_spec(float data, unsigned position)
	{
        Node* new_node = new Node(data);
        if (position == 0)
		{
            new_node->m_next = m_first;
            m_first = new_node;
            return;
        }

        Node* current = m_first;
        for (unsigned i = 0; i < position && current; ++i)
		{
            current = current->m_next;
        }
        if (!current)
		{
            std::cerr << "Invalid position.\n";
            return;
        }
        new_node->m_next = current->m_next;
        current->m_next = new_node;
    }


    void delete_end()
	{
        if (!m_first)
		{
            return;
        }
        if (!m_first->m_next)
		{
            delete m_first;
            m_first = nullptr;
            return;
        }
        Node* current = m_first;
        while (current->m_next->m_next)
		{
            current = current->m_next;
        }
        delete current->m_next;
        current->m_next = nullptr;
    }


    void display()
	{
        Node* current = m_first;
		//if(!current->m_next) std::cout<<"List is empty\n";
		std::cout<<"The data in the list is: \n";
        while (current)
		{
            std::cout << current->m_data << "\n";
            current = current->m_next;
        }
        std::cout << "\n";
    }

	void search(int data)
	{
		unsigned position = 0;
		Node *current = m_first;
		while (current)
		{
			if(current->m_data == data) 
			{
				std::cout<<"Data was found at position "<<position<<"\n";
				return;
			}
			position++;
			current = current->m_next;
		}
		std::cout<<"Data is not in the list.\n";
	}

    ~singlyLinkedList()
	{
        Node* current = m_first;
        while (current)
		{
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

	//unticked
    void insert_end(float data)
	{
        Node* new_node = new Node(data);
        if (!m_first) {
            m_first = new_node;
            return;
        }
        Node* current = m_first;
        while (current->m_next) {
            current = current->m_next;
        }
        current->m_next = new_node;
    }

    void delete_beg()
	{
        if (m_first)
		{
            Node* temp = m_first;
            m_first = m_first->m_next;
            delete temp;
        }
    }

    void delete_spec(unsigned position)
	{
        if (position == 1)
		{
            delete_beg();
            return;
        }
        Node* current = m_first;
        for (unsigned i = 1; i < position - 1 && current; ++i)
		{
            current = current->m_next;
        }
        if (!current || !current->m_next)
		{
            std::cerr << "Invalid position." << std::endl;
            return;
        }
        Node* temp = current->m_next;
        current->m_next = current->m_next->m_next;
        delete temp;
    }
private:
    Node* m_first;
};
