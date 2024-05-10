#pragma once
#include "Media.h"

class Song : public Media {
public:
	bool getTop40();
	void setTop40(bool t);

	Song();
	Song(char t, string ti, string k, int r, string g, int l, int y, int top);

private:
	bool top40;
};