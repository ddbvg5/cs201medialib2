#include "Song.h"
#include <iostream>

Song::Song(){
	type = 'S';
	title = "";
	keyName = "";
	rating = -1;
	genre = "";
	length = -1;
	yearReleased = -1;
	top40 = false;
}

Song::Song(char t, string ti, string k, int r, string g, int l, int y, int top) {
	type = t;
	title = ti;
	keyName = k;
	rating = r;
	genre = g;
	length = l;
	yearReleased = y;
	top40 = top;
}

bool Song::getTop40() {
	return top40;
}

void Song::setTop40(bool t) {
	top40 = t;
}