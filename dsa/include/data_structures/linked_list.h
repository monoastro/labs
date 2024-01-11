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
    singlyLinkedList() : m_head(nullptr) {}

    void insert_beg(float data)
	{
        Node* new_node = new Node(data);
        new_node->m_next = m_head;
        m_head = new_node;
    }

    void insert_end(float data)
	{
		Node* new_node = new Node(data);
		if (!m_head) {
			m_head = new_node;
			return;
		}
		Node* current = m_head;
		while (current->m_next) current = current->m_next;
		current->m_next = new_node;
	}

    void insert_spec(float data, unsigned position)
	{
        Node* new_node = new Node(data);
        if (position == 0)
		{
            new_node->m_next = m_head;
            m_head = new_node;
            return;
        }

        Node* current = m_head;
        for (unsigned i = 1; i < position && current; ++i) current = current->m_next;
        if (!current)
		{
            std::cerr << "Invalid position.\n";
			delete new_node;
            return;
        }
        new_node->m_next = current->m_next;
        current->m_next = new_node;
    }

    void delete_beg()
	{
        if (m_head)
		{
            Node* temp = m_head;
            m_head = m_head->m_next;
            delete temp;
			return;
        }
		std::cerr << "List is empty.\n";
    }

    void delete_end()
	{
        if (!m_head)
		{
			std::cerr << "List is empty.\n";
            return;
        }
        if (!m_head->m_next)
		{
            delete m_head;
            m_head = nullptr;
            return;
        }
        Node* current = m_head;
        while (current->m_next->m_next) current = current->m_next;
        delete current->m_next;
        current->m_next = nullptr;
    }

    void delete_spec(unsigned position)
	{
        if (position == 0)
		{
            delete_beg();
            return;
        }
        Node* current = m_head;
        for (unsigned i = 1; i < position && current; ++i) current = current->m_next;
        if (!current || !current->m_next)
		{
            std::cerr << "Invalid position." << std::endl;
            return;
        }
        Node* temp = current->m_next;
        current->m_next = current->m_next->m_next;
        delete temp;
    }

    void display()
	{
        Node* current = m_head;
		if (!current)
		{
			std::cout << "List is empty.\n";
			return;
		}
		std::cout<<"The data in the list is: \n";
        while (current)
		{
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

	void search(float data)
	{
		unsigned position = 0;
		Node *current = m_head;
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
        Node* current = m_head;
        while (current)
		{
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_head;
};

class linkedStack
{
public:
    linkedStack() : m_top(nullptr) {}

    void push(float data)
    {
        Node* new_node = new Node(data);
        new_node->m_next = m_top;
        m_top = new_node;
    }

    void pop()
    {
        if (m_top)
        {
            Node* temp = m_top;
            m_top = m_top->m_next;
            delete temp;
        }
        else
        {
            std::cerr << "Stack is empty. Cannot pop.\n";
        }
    }

    void display()
    {
        Node* current = m_top;
        if (!current)
        {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "The data in the stack is: \n";
        while (current)
        {
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

    ~linkedStack()
    {
        Node* current = m_top;
        while (current)
        {
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_top;
};

class linkedQueue
{
public:
    linkedQueue() : m_front(nullptr), m_rear(nullptr) {}

    void enqueue(float data)
    {
        Node* new_node = new Node(data);
        if (!m_front)
        {
            m_front = new_node;
            m_rear = new_node;
        }
        else
        {
            m_rear->m_next = new_node;
            m_rear = new_node;
        }
    }

    void dequeue()
    {
        if (m_front)
        {
            Node* temp = m_front;
            m_front = m_front->m_next;
            delete temp;

            if (!m_front) // If the queue becomes empty after dequeue
            {
                m_rear = nullptr;
            }
        }
        else
        {
            std::cerr << "linkedQueue is empty. Cannot dequeue.\n";
        }
    }

    void display()
    {
        Node* current = m_front;
        if (!current)
        {
            std::cout << "linkedQueue is empty.\n";
            return;
        }
        std::cout << "The data in the queue is: \n";
        while (current)
        {
            std::cout << current->m_data << " ";
            current = current->m_next;
        }
        std::cout << "\n";
    }

    ~linkedQueue()
    {
        Node* current = m_front;
        while (current)
        {
            Node* next = current->m_next;
            delete current;
            current = next;
        }
    }

private:
    Node* m_front;
    Node* m_rear;
};
