#include "flat.h"
#include <iostream>
using namespace std;

Flat::Flat(int rms, int ttl, int lvg, int blc, int flr, int srs, string dst)
{
    rooms = rms;
    total = ttl;
    living = lvg;
    balconies = blc;
    floor = flr;
    storeys = srs;
    district = dst;
}

// Getters
string Flat::get_district()
{
	return district;
}
int Flat::get_rooms()
{
	return rooms;
}
int Flat::get_total()
{
	return total;
}
int Flat::get_living()
{
	return living;
}
int Flat::get_balconies()
{
	return balconies;
}
int Flat::get_floor()
{
	return floor;
}
int Flat::get_storeys()
{
	return storeys;
}

bool Flat::operator ==(Flat another)
{
    if (rooms != another.rooms) return false;
    if (total != another.total) return false;
    if (living != another.living) return false;
    if (balconies != another.balconies) return false;
    if (floor != another.floor) return false;
    if (storeys != another.storeys) return false;
    if (district != another.district) return false;
	return true;
}

ostream& operator<<(ostream& stream, const Flat& aflat)
{
    stream << " Number of rooms - " << aflat.rooms << endl;
    stream << " Total area - " << aflat.total << endl;
    stream << " Living area - " << aflat.living << endl;
    stream << " Number of balconies - " << aflat.balconies << endl;
    stream << " Floor - " << aflat.floor << endl;
    stream << " Floor of the house - " << aflat.storeys << endl;
	stream << " District - " << aflat.district << endl;
    return stream;
}
istream& operator>>(istream& stream, Flat& aflat)
{
    stream >> aflat.rooms;
	stream >> aflat.total;
	stream >> aflat.living;
	stream >> aflat.balconies;
    stream >> aflat.floor;
    stream >> aflat.storeys;
	getline(stream, aflat.district);
    stream.get();
    return stream;
}
ofstream& operator<<(ofstream& stream, const Flat& aflat)
{
    stream << aflat.rooms << endl;
    stream << aflat.total << endl;
    stream << aflat.living << endl;
    stream << aflat.balconies << endl;
    stream << aflat.floor << endl;
    stream << aflat.storeys << endl;
    stream << aflat.district << endl;
    return stream;
}
ifstream& operator>>(ifstream& stream, Flat& aflat)
{
    stream >> aflat.rooms;
    stream >> aflat.total;
	stream >> aflat.living;
	stream >> aflat.balconies;
	stream >> aflat.floor;
    stream >> aflat.storeys;
	getline(stream, aflat.district);
    stream.get();
    return stream;
}
