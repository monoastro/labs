#include <iostream>

#define MAX_SIZE 5

class linearQ
{
	public:
		linearQ() : m_rear(-1)
		{
		}
		
		void enqueue(int obj)
		{
			if(m_rear == MAX_SIZE - 1)
			{
				std::cout<<"linearQ is full\n";
				return;
			}
			m_mem[++m_rear] = obj;
		}

		void dequeue()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}

			for(int i = 0; i < m_rear; i++)
			{
				m_mem[i] = m_mem[i+1];
			}

			m_rear--;
		}

		void display()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The elements of the linearQ are:\n";
			for(int i = 0; i<m_rear+1; i++)
			{
				std::cout<<m_mem[i]<<"\n";
			}
		}
		
		void total_elements()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return;
			}
			std::cout<<"The total number of elements of the linearQ is "<<m_rear+1<<"\n";
		}

		int peek()
		{
			if(-1 == m_rear)
			{
				std::cout<<"linearQ is empty\n";
				return -1;
			}

			return m_mem[0];
		}

	private:
		int m_mem[MAX_SIZE];
		int m_rear;

};


