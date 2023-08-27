#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct DATA
{
	string phonenumber;
	string name;
	string address;
	int id = 0;
};
class stack
{
	struct node
	{
		DATA data;
		node* next = NULL;
	};
	node* top;
	int size;
public:
	stack()
	{
		top = NULL;
		size = 0;
		push("Civil police ", "122", "6-Octuber");
		push("Ambulance", "123", "6-Octuber");
		push("Al-Kilawi Market", "01063848222", "7th District");
		push("Dar Al Fouad Hospital", "16370 ", "First 6th of October");
		push("Dr.Ahmed Maher Pharmacy", "02 36991515", "1st District");
		push("Cairo Bank", "16990", "Al Motamayez District");
		push("Mall of Egypt", "02 36120084", "El Wahat Road");
		push("KFC", "01146291120", "El Motamayez District");
		push("ACU", "02 38333078", "4th Industrial Zone");
	}
	bool isempty()
	{
		return top == NULL;
	}
	void push(string n, string p, string a)
	{
		node* newnode = new node;
		newnode->data.address = a;
		newnode->data.phonenumber = p;
		newnode->data.name = n;
		newnode->next = top;
		top = newnode;
		size++;
	}
	void display()
	{
		node* curr = top;
		while (curr != NULL)
		{
			cout << "[ Name : " << curr->data.name << " ]" << endl;
			cout << "[ PhoneNumber : " << curr->data.phonenumber << " ]" << endl;
			cout << "[ Address : " << curr->data.address << " ]" << endl;
			cout << endl << endl;
			curr = curr->next;
		}
	}
};
class linkedlist
{
	struct node
	{
		DATA data;
		node* next = NULL;
		node* prev = NULL;
	};
	node* head = NULL;
	node* tail = NULL;
	int lenght = 0;
public:
	bool isempty()
	{
		return head == NULL;
	}
	//Amr naser
	void inseartfirst(string n, string p, string a)
	{
		node* newnode = new node;
		newnode->data.address = a;
		newnode->data.phonenumber = p;
		newnode->data.name = n;
		newnode->data.id = rand() % 30 % 20;
		if (isempty())
		{
			head = tail = newnode;
		
		}
		else
		{
			newnode->next = head;
			newnode->prev = NULL;
			head->prev = newnode;
			head = newnode;
		}
		lenght++;
	}
	//Amr nasser
	void inseartlast(string n, string p, string a)
	{
		node* newnode = new node;
		newnode->data.address = a;
		newnode->data.phonenumber = p;
		newnode->data.name = n;
		newnode->data.id = rand() % 30 % 20;
		if (isempty())
		{
			head = tail = newnode;
			newnode->next = newnode->prev = NULL;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = tail;
			tail->next = newnode;
			tail = newnode;
		}
		lenght++;
	}
	//Omar elmallah
	void print()
	{
		node* curr = head;
		if (lenght == 0)
		{
			cout << "It's Empty\n";
		}
		else
		{
			while (curr != NULL)
			{
				cout << "[ Name : " << curr->data.name << " ]" << endl;
				cout << "[ PhoneNumber : " << curr->data.phonenumber << " ]" << endl;
				cout << "[ Address : " << curr->data.address << " ]" << endl;
				cout << "[ ID : " << curr->data.id << " ]" << endl;
				cout << endl << endl;
				curr = curr->next;
			}
		}
	}
	//Omar essam
	void search(string DATA)
	{
		node* search;
		search = head;
		while (search != NULL)
		{
			if (search->data.name == DATA || search->data.phonenumber == DATA || search->data.address == DATA)
			{
				cout << "[ Name : " << search->data.name << " ]" << endl;
				cout << "[ PhoneNumber : " << search->data.phonenumber << " ]" << endl;
				cout << "[ Address : " << search->data.address << " ]" << endl;
				cout << "[ ID : " << search->data.id << " ]" << endl;
				cout << endl << endl;
				return;
			}
			search = search->next;
		}
		cout << "This information doesn't exist " << endl;
	}
	//Omar essam
	void modify(string DATA1, string change)
	{
		node* search;
		search = head;
		while (search != NULL)
		{
			if (search->data.name == DATA1)
			{
				search->data.name = change;
				cout << "[ Name : " << search->data.name << " ]" << endl;
				cout << "[ PhoneNumber : " << search->data.phonenumber << " ]" << endl;
				cout << "[ Address : " << search->data.address << " ]" << endl;
				cout << "[ ID : " << search->data.id << " ]" << endl;
				cout << endl << endl;
				return;
			}
			else if (search->data.phonenumber == DATA1)
			{
				search->data.phonenumber = change;
				cout << "[ Name : " << search->data.name << " ]" << endl;
				cout << "[ PhoneNumber : " << search->data.phonenumber << " ]" << endl;
				cout << "[ Address : " << search->data.address << " ]" << endl;
				cout << "[ ID : " << search->data.id << " ]" << endl;
				cout << endl << endl;
				return;
			}
			else if (search->data.address == DATA1)
			{
				search->data.address = change;
				cout << "[ Name : " << search->data.name << " ]" << endl;
				cout << "[ PhoneNumber : " << search->data.phonenumber << " ]" << endl;
				cout << "[ Address : " << search->data.address << " ]" << endl;
				cout << "[ ID : " << search->data.id << " ]" << endl;
				cout << endl << endl;
				return;
			}
			search = search->next;
		}
		cout << "This information doesn't exist " << endl;
	}
	//Momtaz
	void Delete(string DATA1)
	{
		if (isempty())
		{
			cout << "It's already empty " << endl;
			return;
		}
		if (head->data.name == DATA1 || head->data.phonenumber == DATA1 || head->data.address == DATA1)
		{
			node* cur = head;
			head = head->next;
			head->prev = NULL;
			delete cur;
			lenght--;
		}
		else if (tail->data.name == DATA1 || tail->data.phonenumber == DATA1 || tail->data.address == DATA1)
		{
			node* temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
			lenght--;
		}
		else
		{
			node* cur;
			cur= head->next;
			while (cur->next!=NULL)
			{
				if (cur->data.name == DATA1 || cur->data.phonenumber == DATA1 || cur->data.address == DATA1) 
				{
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					break;
					delete cur;
				}
				cur = cur->next;
			}
		}
	}
	//Momtaz
	void sort()
	{
		int temp;
		node* cur = head;
		node* cur2 = NULL;
		while (cur != NULL)
		{
			cur2 = cur->next;
			while (cur2 != NULL)
			{
				if (cur->data.id > cur2->data.id)
				{
					temp = cur->data.id;
					cur->data.id = cur2->data.id;
					cur2->data.id = temp;
				}
				cur2 = cur2->next;
			}
			cur = cur->next;
		}
	}
	/*void inseartatpos(int pos, string n, string p, string a)
	{
		if (pos == 0)
		{
			inseartfirst(n, p, a);
		}
		else if (pos == lenght)
		{
			inseartlast(n, p, a);
		}
		else
		{
			node* curr = head;
			for (int i = 1; i < pos; i++)
			{
				curr = curr->next;
			}
			node* newnode = new node;
			newnode->data.address = a;
			newnode->data.phonenumber = p;
			newnode->data.name = n;
			newnode->next = curr->next;
			newnode->prev = curr;
			curr->next = newnode;
			curr->next->prev = newnode;
			lenght++;
		}
	}*/
	linkedlist()
	{
		inseartlast("Civil police", "122", "6-Octuber");
		inseartlast("Ambulance", "123", "6-Octuber");
		inseartlast("Al-Kilawi Market", "01063848222", "7th District");
		inseartlast("Dar Al Fouad Hospital", "16370 ", "First 6th of October");
		inseartlast("Dr.Ahmed Maher Pharmacy", "02 36991515", "1st District");
		inseartlast("Cairo Bank", "16990", "Al Motamayez District");
		inseartlast("Mall of Egypt", "02 36120084", "El Wahat Road");
		inseartlast("KFC", "01146291120", "El Motamayez District");
		inseartlast("ACU", "02 38333078", "4th Industrial Zone");
		sort();
	}
	~linkedlist() {}
};
//BoDy
class enterface
{
public:
	enterface()
	{
		cout << "\n";
		cout << "\n";
		cout << "*****************************************************\n\n";
		cout << "If you want to view all information, press 1." << endl;
		cout << "If you want to search for a specific something, press 2." << endl;
		cout << "If you would like to add information, press 3." << endl;
		cout << "If you want to edit information, press 4." << endl;
		cout << "If you want to delete information, press 5." << endl;
		cout << "If you want to exit the application, press ctrl+z. \n" << endl;
		cout << "*****************************************************\n\n";
	}
	void input()
	{
		linkedlist l;
		string n;
		while (getline(cin, n))
		{
			cout << "Please Enter Choice (1-6)\n";
			if (n == "1")
			{
				system("cls");
				cout << "\n";
				l.print();
				cout << "*****************************************************\n\n";
				cout << "If you want to view all information, press 1." << endl;
				cout << "If you want to search for a specific something, press 2." << endl;
				cout << "If you would like to add information, press 3." << endl;
				cout << "If you want to edit information, press 4." << endl;
				cout << "If you want to delete information, press 5." << endl;
				cout << "If you want to exit the application, press ctrl+z. \n" << endl;
				cout << "*****************************************************\n\n";
			}
			else if (n == "2")
			{
				system("cls");
				string data2;
				cout << "Enter the data that you want to searct about \n";
				getline(cin, data2);
				l.search(data2);
				cout << "\n";
				cout << "\n";
				cout << "*****************************************************\n";
				cout << "If you want to view all information, press 1." << endl;
				cout << "If you want to search for a specific something, press 2." << endl;
				cout << "If you would like to add information, press 3." << endl;
				cout << "If you want to edit information, press 4." << endl;
				cout << "If you want to delete information, press 5." << endl;
				cout << "If you want to exit the application, press ctrl+z. \n" << endl;
				cout << "*****************************************************\n\n";
			}
			else if (n == "3")
			{
				system("cls");
				string choose;
				cout << "Press 1 To add new contact from the top of the list" << endl << endl;
				cout << "OR Press 2 To add new contact from the undermost of the list" << endl << endl;
				cin >> choose;
				if (choose == "1")
				{
					string N, P, A;
					cout << "Enter name : ";
					cin.ignore();
					getline(cin, N);
					cout << "Enter phone number : ";
					cin >> P;
					cout << "Enter address : ";
					cin.ignore();
					getline(cin, A);
					l.inseartfirst(N, P, A);

				}
				else if (choose == "2")
				{
					string N, P, A;
					cout << "Enter name : ";
					cin.ignore();
					getline(cin, N);
					cout << "Enter phone number : ";
					cin >> P;
					cout << "Enter address : ";
					cin.ignore();
					getline(cin, A);
					l.inseartlast(N, P, A);
				}
				system("cls");
				cout << "\n";
				cout << "\n";
				cout << "*****************************************************\n\n";
				cout << "If you want to view all information, press 1." << endl;
				cout << "If you want to search for a specific something, press 2." << endl;
				cout << "If you would like to add information, press 3." << endl;
				cout << "If you want to edit information, press 4." << endl;
				cout << "If you want to delete information, press 5." << endl;
				cout << "If you want to exit the application, press ctrl+z. \n" << endl;
				cout << "*****************************************************\n\n";
			}
			else if (n == "4")
			{
				system("cls");
				string data2, change2;
				cout << "Enter the old data and new data\n";
				getline(cin, data2);
				getline(cin, change2);
				l.modify(data2, change2);
				cout << "\n";
				cout << "\n";
				cout << "*****************************************************\n\n";
				cout << "If you want to view all information, press 1." << endl;
				cout << "If you want to search for a specific something, press 2." << endl;
				cout << "If you would like to add information, press 3." << endl;
				cout << "If you want to edit information, press 4." << endl;
				cout << "If you want to delete information, press 5." << endl;
				cout << "If you want to exit the application, press ctrl+z. \n" << endl;
				cout << "*****************************************************\n\n";;
			}
			else if (n == "5")
			{
				system("cls");
				string data2;
				cout << "Enter the data that you want to delete\n";
				getline(cin, data2);
				l.Delete(data2);
				system("cls");
				cout << "\n";
				cout << "*****************************************************\n\n";
				cout << "If you want to view all information, press 1." << endl;
				cout << "If you want to search for a specific something, press 2." << endl;
				cout << "If you would like to add information, press 3." << endl;
				cout << "If you want to edit information, press 4." << endl;
				cout << "If you want to delete information, press 5." << endl;
				cout << "If you want to exit the application, press ctrl+z. \n" << endl;
				cout << "*****************************************************\n\n";
			}
			else
			{
				cout << "Out of range \n";
			}
		}
	}
};
int main()
{
	enterface i1;
	i1.input();
	return 0;
}