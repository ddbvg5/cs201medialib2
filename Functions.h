#pragma once

#include <vector>
#include <fstream>
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Song.h"

//PRE:Files are open in main and accessible
//POST: Reads data from csv and loads object into vector
//Also produces error report of any records with errors
int readMediaList(istream& i, ostream& outErr, vector<Media>& m, vector<Book> &b, vector<Movie>& mo, vector<Song>& s);

//PRE: assumes media list is loaded with valid values, the input file
//mediaCommands has been opened and is valid, and the first
//character in the input stream has been verified& read(A, M, B, S)
//POST : Each of these functions will check to see if there is additional
//input in the record following the A, M, B, S characters(a comma
//	followed by an integer) It will validate this additional input(the
//		number is numeric and between the values of 1 and 10 inclusive).
//	Errors will be printed to the error file.
//	• If a rating is present, print the list for ratings greater than or equal
//	to the value provided
//	• If a rating is not present, it will print all entries in the list.
//	• If something other than A, M, B, S, N or Q is entered, the input line
//	should error
void printAllMedia(string command, ostream& out, ostream& outErr, vector<Media>& m);

void printMovieList(string command, ostream& out, ostream& outErr, vector<Media>& m);
void printBookList(string command, ostream& out, ostream& outErr, vector<Media>& m);
void printSongList(string command, ostream& out, ostream& outErr, vector<Media>& m);


//PRE: static array is initialized to 0
//POST : Prints the total count of movies, books and songs in your
//library.
void printTotals(ostream& out);


//PRE: assumes media list is loaded with valid values and the first
//character in the input stream has been read(N)
//POST : It will read the input string and separate all values(as reading
//	from csv file) into a vector<string> row.
//	Row[0] = empty(the N has been read and a comma is in the buffer)
//	Row[1][1] = media type(character, verify M, S, B)
//	Row[2] = title(string, no verification)
//	Row[3] = name(string, no verification)
//	Row[4] = rating(integer, verify numeric & between 1 - 10 inclusive)
//	Row[5] = genre(string, no verification)
//	Row[6] = length(integer, verify numeric)
//	Row[7] = year(integer, verify numeric & between 1500 - 2023 inclusive)
void addNewMedia(string inCommands, ostream& out, ostream& outErr, vector<Media>& m, vector<Book>& b, vector<Movie>& mo, vector<Song>& s);


//PRE: assumes media list is loaded with valid values and the first
//character in the input stream has been read(L)
//POST : It will read the input string and separate values(as reading
//	from csv file) into a vector<string> row.
//	Row[0] = empty(the L has been read and a comma is in the buffer)
//	Row[1] = title(string, no verification)
void listMovieStars(string inCommands, ostream& out, ostream& outErr, vector<Movie*>& m);

//PRE: assumes media list is loaded with valid values and the first
//character in the input stream has been read(K)
//POST : It will read the input string and separate values(as reading
//	from csv file) into a vector<string> row.
//	Row[0] = empty(the L has been read and a comma is in the buffer)
//	Row[1] = key name(string, no verification)
//	If the key name is found in the list, print to report file a header & list
//	the type of media, title, year and rating
//	If the keyname is not found, print a message to the error file
void listKeyName(string inCommands, ostream& out, ostream& outErr, vector<Media>& m);