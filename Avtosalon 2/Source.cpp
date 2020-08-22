#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Auto
{
    string name;
    int year;
    float capacity;
    int price;
	Auto* next = nullptr;
};

class AutoSalon
{
public:
	Auto* AddAuto(Auto* Head, int Number) {
		Number--;
		Auto* NewItem = new(Auto);
		cout << "Year of car production: ";
		cin >> NewItem->year;
		cout << "Name: ";
		cin >> NewItem->name;
		cout << "Price: ";
		cin >> NewItem->price;
		cout << "Engine capacity: ";
		cin >> NewItem->capacity;
		NewItem->next = nullptr;
		if (Head == nullptr)
		{
			Head = NewItem;
		}
		else {
			Auto* Current = Head;
			for (int i = 1; i < Number && Current->next != nullptr; i++)
			{
				Current = Current->next;
			}
			if (Number == 0) {

				NewItem->next = Head;
				Head = NewItem;
			}
			else {
				if (Current->next != nullptr)
				{
					NewItem->next = Current->next;
				}

				Current->next = NewItem;
			}
		}
		return Head;
	}
	void DeleteAutoYearLess2000(Auto* Head)
	{
		while (Head->year < 2000)
		{
			DeleteAutoYearLess2000(Head->next);
			delete Head;
			Head = Head->next;
		}
	}
	void Print(Auto* Head)
	{
		if (Head == nullptr)
		{
			cout << "List is empty!";
		}
		else
		{
			while (Head != nullptr)
			{
				cout << "Name: " << Head->name << "\nYear: " << Head->year << "\nEngine capacity: "
					<< Head->capacity << "\nPrice: " << Head->price << endl << endl;
				Head = Head->next;
			}
		}
	}
	bool FindYear(Auto* Head, int NumberItem)
	{
		Auto* linkk;
		linkk = Head;
		while (linkk != nullptr) {
			if (NumberItem == linkk->year)
			{
				return true;
			}
			else linkk = linkk->next;
		}
		return false;
	}
	void Show(Auto* Head)
	{
		cout << "Name: " << Head->name << "\nYear: " << Head->year << "\nEngine capacity: "
			<< Head->capacity << "\nPrice: " << Head->price << endl << "~~~" << endl;
	}
	void FindName(Auto* Head)
	{
		Auto* ptr = Head;
		string name = "";
		cout << "Input name auto: ";
		cin >> name;
		while (ptr != nullptr)
		{
			if (name == ptr->name)
			{
				Show(ptr);
				return;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		cout << "No such name was found" << endl;
	}
	void FindYear(Auto* Head) {
		Auto* ptr;
		ptr = Head;
		int NumberItem = 0;
		cout << "Input auto year: ";
		cin >> NumberItem;
		while (ptr != NULL)
		{
			if (NumberItem == ptr->year)
			{
				Show(ptr);
				return;
			}
			else ptr = ptr->next;
		}
		cout << "No such year was found" << endl;
	}
	void FindPrice(Auto* Head) {
		Auto* ptr;
		ptr = Head;
		int NumberItem = 0;
		cout << "Input price: ";
		cin >> NumberItem;
		while (ptr != NULL)
		{
			if (NumberItem == ptr->price)
			{
				Show(ptr);
				return;
			}
			else ptr = ptr->next;
		}
		cout << "No such price was found" << endl;
	}
	void Delete(Auto* Head)
	{
		if (Head != NULL)
		{
			Delete(Head->next);
			delete Head;
		}
	}
};


int main()
{
	AutoSalon tr;
	Auto* Head = nullptr;
	int n = 1, d;
	do {

		cout << "1 - Add auto info to DB" << endl;
		cout << "2 - Show DB" << endl;
		cout << "3 - Show info about auto for year" << endl;
		cout << "4 - Show info about auto for name" << endl;
		cout << "5 - Exit!" << endl;
		cout << "Please select: ";
		cin >> d;
		switch (d)
		{
		case 1:
		{
			Head = tr.AddAuto(Head, n);
			n++;
		}break;
		case 2:
		{
			tr.Print(Head);
		}break;
		case 3:
		{
			tr.FindYear(Head);
		}break;
		case 4:
		{
			tr.FindName(Head);
		}break;
		case 5:
		{
			cout << "Goodbye" << endl;
			tr.Delete(Head);
			exit(0);
		}break;

		default:
			cout << "Error" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (d != 5);

	return 0;
}