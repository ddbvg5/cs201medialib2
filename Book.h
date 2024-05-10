#pragma once
#include "Media.h"

class Book : public Media {
public: 
	int getWeeks();
	void setWeeks(int w);

	Book();
	Book(char t, string ti, string k, int r, string g, int l, int y, int w);


private:
	int weeksNYT;
};