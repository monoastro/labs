#include <iostream>
#define MAX_SIZE 5

class circularQ
{
	public:
		circularQ() : m_rear(MAX_SIZE - 1), m_front(MAX_SIZE - 1), m_counter(0)
		{
		}
		
		bool empty()
		{
			//return m_rear == m_front;
			return m_counter == 0;
		}

		bool full()
		{
			//the queue only grows to MAX_SIZE - 1 under this implementation
			//return (m_rear + 1) % MAX_SIZE == m_front;
		
			//to distinguish between empty and full, I'm using a counter 
			return m_counter == MAX_SIZE;
		}

		void enqueue(int obj)
		{
			if(full())
			{
				std::cout<<"circularQ is full\n";
				return;
			}

			m_rear = (m_rear + 1) % MAX_SIZE;
			m_mem[m_rear] = obj;
			m_counter++;
		}

		void dequeue()
		{
			if(empty())
			{
				std::cout<<"circularQ is empty\n";
				return;
			}

			m_front = (m_front + 1) % MAX_SIZE;
			m_counter--;
		}

		/*
		void display()
		{
			if(empty())
			{
				std::cout<<"circularQ is empty\n";
				return;
			}
			std::cout<<"The elements of the circularQ are:\n";

			int i = (m_front + 1)%MAX_SIZE;
			while((m_rear+1)%MAX_SIZE != i)
			{
				std::cout<<m_mem[i]<<"\n";
				i = (i + 1) % MAX_SIZE;
			}
			std::cout<<"\n";
		}
		*/

		//displaying based on the counter; counter meta is broken
		void display()
		{
			if(empty())
			{
				std::cout<<"circularQ is empty\n";
				return;
			}
			std::cout<<"The elements of the circularQ are:\n";

			int i = (m_front + 1)%MAX_SIZE;
			unsigned local_counter = 0;
			while(local_counter != m_counter)
			{
				std::cout<<m_mem[i]<<"\n";
				i = (i + 1) % MAX_SIZE;
				local_counter++;
			}
		}
		
		void total_elements()
		{
			if(-1 == m_rear)
			{
				std::cout<<"circularQ is empty\n";
				return;
			}

			std::cout<<"The total number of elements of the circularQ is "<<m_counter<<"\n";
		}

	private:
		int m_mem[MAX_SIZE];
		int m_rear;
		int m_front;
		unsigned m_counter;
};
