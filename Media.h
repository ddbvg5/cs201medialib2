#pragma once
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Media {
public:
	//Constructors
	Media();
	Media(char ty, string ti, string k, int r, string g, int l, int y);

	//GETTERS
	char getType();
	string getTitle();
	string getKeyName();
	int getRating();
	string getGenre();
	int getLength();
	int getYearReleased();

	//SETTERS
	void setType(char t);
	void setTitle(string t);
	void setKeyName(string k);
	void setRating(int r);
	void setGenre(string g);
	void setLength(int l);
	void setYearReleased(int y);

protected:
	char type;
	string title;
	string keyName;
	int rating;
	string genre;
	int length;
	int yearReleased;
};