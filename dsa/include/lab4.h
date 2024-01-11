#include "linked_list.h"

void lab4()
{
	singlyLinkedList list;
	float data;
	unsigned position;

	while(1) 
	{
		unsigned choice = 0; 
		std::cout<<"\nDisplay Menu\n(0) to insert at beginning,\n(1) to insert at position,\n(2) to delete from the end,\n(3) to display the list,\n(4) to search for data in the list\n(5) to exit the program\n";
		std::cin>>choice; 

		switch(choice)
		{ 
			case 0:
				std::cout<<"\nEnter data to insert\n";
				std::cin>>data;
				list.insert_beg(data);
				break; 
			case 1:
				std::cout<<"Enter position insert\n";
				std::cin>>position;
				std::cout<<"Enter data to insert\n";
				std::cin>>data;
				list.insert_spec(data, position);
				break; 
			case 2:
				list.delete_end();
				break; 
			case 3:
				list.display();
				break; 
			case 4:
				std::cout<<"Enter the data to search\n";
				std::cin>>data;
				list.search(data);
				break;
			case 5:
				std::cout<<"\nProgram ended successfully\n"; 
				exit(1);
				break; 
		} 
	}
}
