#include <iostream>
using namespace std;
const int PERSONS = 10;
const int NAME_LENGHT = 20;
struct REGISTRY
{
	char firstname[NAME_LENGHT];
	char email[NAME_LENGHT];
	int age;
};
int Menu(void);
void PrintPerson(REGISTRY personregistry[PERSONS], int added_persons);
void AddPerson(REGISTRY personregistry[PERSONS], int *nbr);
int main(void)
{
	int added_persons = 0;
	while (true)
	{
		int selection = Menu();
		REGISTRY personregistry[PERSONS];
		int *nbr = &added_persons;
		switch (selection)
		{
		case 0:
			exit(0);
			break;
		case 1:
			if (added_persons == PERSONS)
			{
				cout << "Registry is full!\n";
			}
			else
			{
				AddPerson(personregistry,nbr);
				added_persons += 1;
			}
			break;
		case 2:
			cout << endl;
			PrintPerson(personregistry, added_persons);
			break;
		}
	}
}

int Menu(void)
{
	int input;
	cout << "Menu\n";
	cout << "0 Quit\n";
	cout << "1 Add new person\n";
	cout << "2 Show every person\n";
	cin >> input;
	return input;
}

void PrintPerson(REGISTRY personregistry[PERSONS], int added_persons)
{
	for (int i = 0; i < added_persons; i++)
	{
		cout << "Person " << i + 1 << ":" << endl;
		cout << "Name:  " << personregistry[i].firstname << endl;
		cout << "Email: " << personregistry[i].email << endl;
		cout << "Age:   " << personregistry[i].age << endl;
		cout << endl;
	}
}

void AddPerson(REGISTRY personregistry[PERSONS], int *nbr)
{
	for (int i = 0; i <= *nbr; i++)
	{
		if (i == *nbr)
		{
			cout << "Your firstname?: ";
			cin >> ws;
			cin.getline(personregistry[i].firstname, NAME_LENGHT);
			cout << "Your email?:     ";
			cin >> personregistry[i].email;
			cout << "Your age?:       ";
			cin >> personregistry[i].age;
		}
	}
}