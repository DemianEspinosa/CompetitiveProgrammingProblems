#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int hour, mint, seg;

string dt;

int main(){
	char ch;
	string time;
	cin >> time;
	stringstream ss(time);
	ss >> hour >> ch >> mint >> ch >> seg >> dt;
	if(dt == "PM" && hour != 12)
		hour += 12;
	if(hour == 12 && dt == "AM")
		hour = 0;
	if(hour < 10)
		printf("0");
	printf("%d:", hour);
	if(mint < 10)
		printf("0");
	printf("%d:", mint);
	if(seg < 10)
		printf("0");
	printf("%d", seg);
}

