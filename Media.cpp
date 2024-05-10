#include "Media.h"
#include <iostream>

using namespace std;

Media::Media() {
	type = 'U';
	title = "";
	keyName = "";
	rating = 0;
	genre = "";
	length = 0;
	yearReleased = 0;
}

Media::Media(char ty, string ti, string k, int r, string g, int l, int y) {
	type = ty;
	title = ti;
	keyName = k;
	rating = r;
	genre = g;
	length = l;
	yearReleased = y;
}

char Media::getType() {
	return type;
}

string Media::getTitle() {
	return title;
}

string Media::getKeyName() {
	return keyName;
}

int Media::getRating() {
	return rating;
}

string Media::getGenre() {
	return genre;
}

int Media::getLength() {
	return length;
}

int Media::getYearReleased() {
	return yearReleased;
}

void Media::setType(char t) {
	type = t;
}

void Media::setTitle(string t) {
	title = t;
}

void Media::setKeyName(string k) {
	keyName = k;
}

void Media::setRating(int r) {
	rating = r;
}

void Media::setGenre(string g) {
	genre = g;
}

void Media::setLength(int l) {
	length = l;
}

void Media::setYearReleased(int y) {
	yearReleased = y;
}