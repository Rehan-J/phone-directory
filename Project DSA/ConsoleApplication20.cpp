#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<math.h>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"STACK.h"
#include"linklist.h"
#include"queue.h"
#include"bst.h"
#include"waqt.h"
#include <time.h>   
#include <stdio.h>
#include<windows.h>

using namespace std;


class mobile_directory
{
  private:
	string name;
	string number;
	singlelink_list <string> l;
	singlelink_list <string> Sec_l;
	node bye;
	Queue f;
	tree t;
	stack <string> a;
	string alpha;
	int count=0;
	int count1 = 0;
	waqt w;
	bool flag = false;

  public:
	void setinfo()
	{
		system("CLS");
		system("Color 05");
		cout << "Enter details" << endl;
		cin.ignore();
		cout << "ENTER NAME:";
		getline(cin,name,'\n');
		cout << endl;
		cout << "ENTER NUMBER:";
		getline( cin,number);
		cout << endl;

	}

	string getname()
	{
		return name;
	}
	string getnum()
	{
		return number;
	}

	void create_new_contact()
	{
		system("CLS");
		system("Color 05");
		setinfo();
		l.insert_beig(name, number);
		t.make_tree(name,number);
		count++;
		
		cout <<endl<<" New Contact Created!" << endl;

		cout << "\nSave As Favourite?(Y/N)";
		char op;
		cin >> op;
		if (op == 'Y' || op == 'y')
		{
			node *ABC = Sec_l.insert_beig(name, number);
			
			f.Insert(ABC);
		}
	}
	
	void display_favourite_c()
	{
		system("CLS");
		system("Color 05");
		if (flag) {

			cout << "No contacts in Favourites" << endl;
			
		}
		else {
			while (!f.IsEmpty())
			{
				f.Remove();
			}
		}
	}
	

	void displaycontacts()
	{
		
		system("Color 05");
		cout << "Total cotacts are " << count << endl;
		cout << "NAME:" << "\t     " << "NUMBER" << endl;
		t.show();
		//t.search();
	}
	void makecall()
	{
		system("CLS");
		system("Color 05");
		string n;
		int opt;
		cout << endl << "How do you want to call? ";
		cout << "\n1.By name\n2.By nmber\n";
		cin >> opt;
		string st;
		switch (opt)
		{
		case 1:
			cin.ignore();
			cout << "Enter Name: "; getline(cin, n);

			st = t.search(n, opt);
			a.Push(st);
			/*count1++;*/
			break;
		case 2:
			cin.ignore();
			cout << "Enter Number: ";
			getline(cin, n);
			//search_by_number()
			/*alpha = t.search(n, opt);
			a.Push(alpha);
			count1++;*/
			st = l.call_by_number(n);
			a.Push(st);

			break;
		default:
			break;
		}

	}

	void search() {
		system("CLS");
		system("Color 05");
		string s1;
		cout << "Enter name or Number to search: ";
		cin >> s1;
		l.search(s1);



	}

	void recents_contacted() {
		system("CLS");
		system("Color 05");
		cout << endl << "     Recently contacted list" << endl << endl;
		string b = "";
		cout << "NAME:" << "\t     " << "NUMBER" << endl;
		while (!a.isEmpty()) {

			a.Pop(b);
			cout << b << endl;
		}

	}
	
	void update() {

		system("CLS");
		system("Color 05");
		cout << endl;
		cout << "Enter contact name to modify: ";
		cin.ignore();
		string s, s1, s2;
		getline(cin, s);

		cin.ignore();
		cout << "Enter new name: " << endl;
		getline(cin, s1);

		cin.ignore();
		cout << "Enter new number: " << endl;
		getline(cin, s2);
		t.modify_func(s,s1,s2);
		l.modify(s,s1,s2);
		cout << endl << "Conatct Modified!" << endl;
	

	}

	void delete_contact(){
		system("CLS");
		system("Color 05");
		string s;
		cout << "Enter contact name to delete: " << endl;
		cin >> s;
		t.delete_contact(s);
		l.delete_it(s);
		cout << "The information of contact " << s << " has been deleted successfully!" << endl << endl;
		count--;

	}
	
	void  del_link()
	{
		system("CLS");
		system("Color 05");
		flag = true;
		t.delete_all();
		l.delete_all();
		count = 0;
	}

};



int main()
{
	
	int ch;
	char op;
	mobile_directory m;
	while (1) {
		
		system("Color 05");
		cout << "----------------------Phone Directory---------------------------------" << endl << endl;
		cout <<endl<<endl<< "Please select an option: ";
		cout << endl << "1.Create New Contact" << endl;
		cout << "2.Modify a Contact" << endl;
		cout << "3.Delete a Contact" << endl;
		cout << "4.Display All Contacts" << endl;
		cout << "5.Make a Call" << endl;
		cout << "6.Display Recently Contatcted List" << endl;
		cout << "7. Search Contact" << endl;
		cout << "8. To Display favourite Contact:" << endl;
		cout << "9. To Delete All contacts" << endl;
		cout << "10. Exit" << endl << endl;
		cout<<"Enter Your Option: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			do {
				m.create_new_contact();
				cout << "Do you want to create another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 2:
			do {
				m.update();
				cout << "Do you want to modify another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 3:
			do {
				m.delete_contact();
				cout << "Do you want to delete another contact?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 4:
			system("CLS");
			m.displaycontacts();
			break;
		case 5:
			do {
				m.makecall();
				cout << "Do you want to make another call?(Y/N) : ";
				cin >> op;
			} while (op == 'y');
			break;
		case 6:
			m.recents_contacted();
			break;
		case 7:
			m.search();
			break;
		case 8:
			m.display_favourite_c();
			break;
		case 9:
			m.del_link();
			
			break;
		case 10:
			cout << "              Made by:" << endl;
			cout << "    MUHAMMAD SHERAZ      (01-134202-047)" << endl;
			cout << "    HAIDER AKBAR ZUBAIRI (01-134202-085)" << endl;
			cout << "    REHAN JAMIL SATTI    (01-134202-059)" << endl;
			exit(0);
			break;
		default:
			break;
		}





	}
	
	

	_getch();
	return 0;
}

