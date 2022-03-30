#ifndef FLAT_H
#define FLAT_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Flat // class declaration
{
	private: // closed part of the class
		int rooms;
		int total;
		int living;
		int balconies;
		int floor;
		int storeys;
		string district;
	public: // open (interface) part
		Flat() : rooms(0), total(0), living(0), balconies(0), floor(0), storeys(0), district("") {};
        Flat(int, int, int, int, int, int, string);

		string get_district();
		int get_rooms();
		int get_total();
		int get_living();
		int get_balconies();
		int get_floor();
		int get_storeys();

		bool operator ==(Flat another);
        friend ostream& operator<<(ostream& stream, const Flat& aflat);
        friend istream& operator>>(istream& stream, Flat& aflat);
        friend ofstream& operator<<(ofstream& stream, const Flat& aflat);
        friend ifstream& operator>>(ifstream& stream, Flat& aflat);
};

#endif // FLAT_H
