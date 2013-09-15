# include <iostream>
# include "nmea_write.h"
# include <string>
# include <vector>
# include <fstream>
# include <sstream>

using namespace std;

int main(){
	char ch;
	nmea_write v;
	vector<string> myvector;
	string global = "0"; //For unkonwn values
	
	int parity = 0;
	myvector = v.push_string("$GPGGA,",myvector);
	
	//Time
	string utc;
	cout << "Please enter the time: " << endl;
	cin >> utc;
	myvector = v.push_string(utc, myvector);
	myvector = v.push_string(",", myvector);
	cin.ignore();
	
	//Latitude
	string lat;
	cout << "Please enter Latitude: " << endl;
	cin >> lat;
	myvector = v.push_string (lat, myvector);
	myvector = v.push_string(",", myvector);
	cin.ignore();

	//North, South
	string dir;
	int intlat;
	intlat = v.string_to_int(lat);
	dir = intlat > 0?'N':'S';
	myvector = v.push_string(dir, myvector);
	myvector = v.push_string(",", myvector);

	////Longitude
	string lon;
	cout << "Please enter Longitude: " << endl;
	cin >> lon;
	myvector = v.push_string (lon, myvector);
	myvector = v.push_string(",", myvector);
	cin.ignore();

	//East, West
	int intlon;
	intlon = v.string_to_int(lon);
	dir = intlon > 0?'E':'W';
	myvector = v.push_string(dir, myvector);
	myvector = v.push_string(",", myvector);

	//Quality
	myvector = v.push_string(global, myvector);
	myvector = v.push_string(",", myvector);
	
	//Number of satellite the range is 4-10
	myvector = v.push_string("10", myvector);
	myvector = v.push_string(",", myvector);
	
	//HDOP
	myvector = v.push_string(global, myvector);
	myvector = v.push_string(",", myvector);
	
	//MSL
	myvector = v.push_string(global, myvector);
	myvector = v.push_string(",", myvector);
	
	//Adding 'M'
	myvector = v.push_string("M", myvector);
	myvector = v.push_string(",", myvector);
	
	//time in seconds since last DGPS update
	myvector = v.push_string(global, myvector);
	myvector = v.push_string(",", myvector);
	
	//DGPS station ID number
	myvector = v.push_string(global, myvector);
	myvector = v.push_string(",", myvector);

	vector<char *> nmeachar;
	nmeachar = v.vstring_to_char(myvector);

	parity = v.Exclusive_OR(nmeachar);

	string sparity;
	sparity = v.int_to_string (parity);
	myvector = v.push_string("*",myvector);
	myvector = v.push_string(sparity,myvector);

	fstream nmea;
	nmea = v.set_file( myvector);

	cin.ignore();
	cin.get(ch);

	return 0;
}
