#ifndef REALTOR_H
#define REALTOR_H

#include <string>
#include <fstream>
#include "flat.h"
using namespace std;

class realtor
{
	private:
		int max_num_flats; // maximum number of apartments in the base (capacity)
		int num_flats; // the current number of apartments in the database
		Flat *flats; // array of flat class objects
	public:
		realtor(unsigned int max_nb); // constructor of the realtor class
		~realtor(); // destructor of the realtor class

		void operator +=(const Flat &aflats);
        void operator -=(const Flat &aflats);
        friend ostream& operator<<(ostream& stream, const realtor& arealtor);

		void read_from_file(string filename); // enter data from a file
		void write_to_file(string filename); // write the data to a file
		void display_all(); // to display on the screen
		void menu();
		void tasks();
};

#endif
