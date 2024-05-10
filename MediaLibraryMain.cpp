#include <iostream>
#include "Media.h"
#include "Song.h"
#include "Book.h"
#include "Movie.h"
#include "Functions.h"


using namespace std;

int main() {
	fstream mediaCommands, mediaList; 
	fstream reportOutput, errorOutput;
	vector<Media> mediaItems;
	vector<Song> songItems;
	vector<Movie> movieItems;
	vector<Book> bookItems;
	string command;
	vector<Movie*> movieItemList;

	//opening files
	mediaCommands.open("mediaCommandsNew.txt");
	mediaList.open("mediaList.txt");
	reportOutput.open("reports.txt");
	errorOutput.open("error.txt");

	//check if files are open
	if (!mediaCommands.is_open()) {
		cout << "Error: mediaCommands.txt unable to be opened" << endl;
	}
	if (!mediaList.is_open()) {
		cout << "Error: mediaList.txt unable to be opened" << endl;
	}
	if (!reportOutput.is_open()) {
		cout << "Error: reports.txt unable to be opened" << endl;
	}
	if (!errorOutput.is_open()) {
		cout << "Error: error.txt unable to be opened" << endl;
	}
	
	errorOutput << "ERROR LIST" << endl;

	//generate list
	readMediaList(mediaList, errorOutput, mediaItems, bookItems, movieItems, songItems);

	//reads through media commands file and generates output based on first character
	getline(mediaCommands, command);
	while (!mediaCommands.eof() && command.at(0) != 'Q') {
		switch (command.at(0)) {
		case 'A':
			printAllMedia(command, reportOutput, errorOutput, mediaItems);
			break;
		case 'M':
			printMovieList(command, reportOutput, errorOutput, mediaItems);
			break;
		case 'S':
			printSongList(command, reportOutput, errorOutput, mediaItems);
			break;
		case 'B':
			printBookList(command, reportOutput, errorOutput, mediaItems);
			break;
		case 'T':
			printTotals(reportOutput);
			break;
		case 'N':
			addNewMedia(command, reportOutput, errorOutput, mediaItems, bookItems, movieItems, songItems);
			break;
		case 'K':
			listKeyName(command, reportOutput, errorOutput, mediaItems);
			break;
		case 'L':
			for (auto media : movieItems) {
				Movie* newMedia = new Movie();
				*newMedia = media;
				movieItemList.push_back(newMedia);
			}
			listMovieStars(command, reportOutput, errorOutput, movieItemList);
			break;
		case 'Q':
			break;
		default:
			errorOutput << "The command: " << command.at(0) << " is invalid" << endl;
			break;
		}
		getline(mediaCommands, command);
	}

	//program exits when Q is inputted which eradicates the need for case Q but this is the result
	reportOutput << "Quitting program" << endl;

	//closes files
	reportOutput.close();
	mediaCommands.close();
	mediaList.close();
	errorOutput.close();

	return 0;
}