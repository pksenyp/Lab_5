#include <iostream>
#include <cstdlib>
#include "realtor.h"
using namespace std;

realtor::realtor(unsigned int max_nb)
{
		max_num_flats = max_nb;
		flats = new Flat[max_num_flats];
		num_flats = 0;
		cout <<"\nClass constructor called realtor:";
		cout <<"\nSelected objects - "<< max_num_flats;
		cout<<"\nFlats loaded - "<<num_flats<<endl;
}

realtor::~realtor()
{
		max_num_flats = 0;
		delete[] flats;
		num_flats = 0;
		cout<<"\nClass destructor called realtor:";
		cout <<"\nThe allocated memory is freed";
}

void realtor::operator+=(const Flat &aflat)
{
    if (num_flats < max_num_flats)
    {
        flats[num_flats] = aflat;
        num_flats++;
    }
}
void realtor::operator-=(const Flat &aflat)
{
    if (num_flats < 0)
        return;
    int index = -1;
    for (int i = 0; i < num_flats; i++)
        if (flats[i] == aflat)
            index = i;
    if (index == -1)
        return;
    if (index != num_flats - 1)
        flats[index] = flats[num_flats - 1];
    num_flats--;
}
ostream& operator<<(ostream& stream, const realtor& arealtor)
{
    stream << "\n\nThe list of all flats:\n";
    for (int i = 0; i < arealtor.num_flats; i++)
    {
        stream << "===================== Flat number: " << i+1 << " ======================== \n";
        stream << arealtor.flats[i] << endl;
    }
    return stream;
}

void realtor::read_from_file(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		cout<<"\n\nFile was not find!"<<endl;
		system("pause");
		exit(1);
	}
	int N;
	infile>> N;
	infile.get();
	for (int i = 0; i< N; i++)
	{
		Flat new_flat;
        infile >> new_flat;
        this->operator+=(new_flat);
	}

	infile.close();
	cout <<"\nData from the file is loaded."<<filename<<":";
	cout <<"\nNumber of loaded flats - "<< num_flats;
}

void realtor::write_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename.c_str());
	outfile<<num_flats<<endl;
	for (int i = 0; i<num_flats; i++)
		outfile << flats[i];
	outfile.close();
	cout<<"\nData is written to the file."<<filename<<":";
	cout <<"\nNumber of written flats - "<< num_flats;
}

void realtor::menu()
{
	cout << "\n-----------------------------------------------------------------------" << endl;
	cout << "\nTasks: \n" << endl;
	cout << "\n1 - Calculate the total area of apartments, located in the specified" << endl;
	cout << "\n   district (the name of the district is entered from the keyboard).\n" << endl;
	cout << "\n2 - Display data about all apartments, located on the last floor" << endl;
	cout << "\n   of multi-storey building (5 and more floors).\n" << endl;
	cout << "\nTo finish the program enter: -1" << endl;
	cout << "\nTo repeat the menu call, enter: 0" << endl;
	cout << "\n-----------------------------------------------------------------------" << endl;
}

void realtor::tasks()
{
    int  n;
	string str;
		do
			{
				cout << "\n-----------------------------------------------------------------------" << endl;
				cout << "\nEnter task number: \n" << endl;
				cout << "-----------------------------------------------------------------------\n" << endl;
				cin >> n;
				cout << "-----------------------------------------------------------------------" << endl;
				switch (n)
				{
				case 0: menu();
					break;
				case 1:
                {
					int k = 0;
					cout << "\nEnter district - ";
					cin.get();
					getline(cin, str);
					bool found = false;
					for (int i = 0; i < num_flats; i++)
					{
						if (flats[i].get_district() == str)
						{
							found = true;
							k = flats[i].get_total() + k;
						}
					}
					cout << "The total area of apartments in the given area: \n" << k << endl;
					if (!found)
						cout << "There are no apartments in the given area!\n" << endl;
					break;
				}
				case 2:
                {
					bool found = false;
					for (int i = 0; i < num_flats; i++)
					{
						if ((flats[i].get_floor() == flats[i].get_storeys()) && (flats[i].get_floor() >= 5))
						{
							found = true;
							cout << "\nNumber of rooms: " << flats[i].get_rooms() << endl;
							cout << "Total area: " << flats[i].get_total() << endl;
							cout << "Living area: " << flats[i].get_living() << endl;
							cout << "Number of balconies/loggia: " << flats[i].get_balconies() << endl;
							cout << "Floor: " << flats[i].get_floor() << endl;
							cout << "Floor of the house: " << flats[i].get_storeys() << endl;
							cout << "Area: " << flats[i].get_district() << endl;
							cout << "-----------------------------------------------------------------------\n" << endl;
						}
					}
					if (!found)
						cout << "The apartment, located on the top floor of a multi-storey building was NOT found!\n" << endl;
                	break;
				}
				default:
					cout << "\nThere are no tasks under the given number!\n" << endl;
				}
			} while (n != -1);
			cout << "\nThe end.\n" << endl;
}

