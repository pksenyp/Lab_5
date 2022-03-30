#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include "flat.h"
#include "flat.cpp"
#include "realtor.h"
#include "realtor.cpp"

using namespace std;

int main()
{
	realtor my_flats(50);
    my_flats.read_from_file("file.txt");

    Flat f(5, 310, 300, 2, 35, 60, "Moscow City");
    my_flats += f;

	cout << my_flats;
    my_flats.menu();
    my_flats.tasks();

    my_flats.write_to_file("file2.txt");
    system("pause");
}
