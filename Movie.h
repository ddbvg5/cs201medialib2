#pragma once
#include "Media.h"

class Movie : public Media {

public:
	vector<string> getStars();
	void setStars(vector<string> s);

	Movie();
	Movie(char t, string ti, string k, int r, string g, int l, int y, vector<string> s);

	char getType();
	string getTitle();

private:
	vector<string> stars;
};