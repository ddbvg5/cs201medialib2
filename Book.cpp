#include "Book.h"
#include <iostream>

Book::Book() {
	type = 'B';
	title = "";
	keyName = "";
	rating = -1;
	genre = "";
	length = -1;
	yearReleased = -1;
	weeksNYT = 0;
}

Book::Book(char t, string ti, string k, int r, string g, int l, int y, int w) {
	type = t;
	title = ti;
	keyName = k;
	rating = r;
	genre = g;
	length = l;
	yearReleased = y;
	weeksNYT = w;
}

int Book::getWeeks() {
	return weeksNYT;
}

void Book::setWeeks(int w) {
	weeksNYT = w;
}