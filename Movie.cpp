#include "Movie.h"
#include <iostream>

Movie::Movie() {
	type = 'M';
	title = "";
	keyName = "";
	rating = -1;
	genre = "";
	length = -1;
	yearReleased = -1;
	stars = {};
}

Movie::Movie(char t, string ti, string k, int r, string g, int l, int y, vector<string> s) {
	type = t;
	title = ti;
	keyName = k;
	rating = r;
	genre = g;
	length = l;
	yearReleased = y;
	stars= s;
}

vector<string> Movie::getStars() {
	return stars;
}

void Movie::setStars(vector<string> s) {
	stars = s;
}

char Movie::getType() {
	return type;
}

string Movie::getTitle() {
	return title;
}