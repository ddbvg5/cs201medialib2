#include "Functions.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include "Movie.h"
#include "Song.h"
#include "Book.h"

//set totals to zero
int total = 0;
int bookTotal = 0;
int movieTotal = 0;
int songTotal = 0;

//counter for #
int counter = 1;

int incrementList(string media, ostream& outErr, vector<Media>& m, vector<Book> books, vector<Movie> movies, vector<Song> songs) {
	string tempString;
	vector<string> row;
	
	//create new string stream
	stringstream inSS(media);
	row.clear();

	//filter row into components
	while (getline(inSS, tempString, ',')) {
		row.push_back(tempString);
	}
	//push components into media if no errors
	try {
		if (row[0][0] != 'M' && row[0][0] != 'S' && row[0][0] != 'B') {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the type" << endl;
			throw runtime_error(row[0][0] + " is a type that is ");
			return -1;
		}
		if ((row[3].find_first_not_of("0123456789") != string::npos) || stoi(row[3]) < 1 || stoi(row[3]) > 10) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the rating" << endl;
			throw runtime_error(row[3] + " is a rating that is ");
			return -1;
		}
		if ((row[5]).find_first_not_of("0123456789") != string::npos) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the length" << endl;
			throw runtime_error(row[5] + " is a length that is ");
			return -1;
		}
		if (((row[6]).find_first_not_of("0123456789") != string::npos) || (stoi(row[6]) < 1500) || (stoi(row[6]) > 2023)) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the year" << endl;
			throw runtime_error(row[6] + " is a year that is ");
			return -1;
		}
		
		//increments totals
		switch (row[0][0]) {
		case 'M':
		{
			vector<string> totalStars;
			for (int i = 7; i < row.size(); i++) {
				totalStars.push_back(row[i]);
			}
			Movie movie(row[0][0], row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]), totalStars);
			movies.push_back(movie);
			movieTotal++;
			break;
		}
		case 'B':
		{

			if (row[7].find_first_not_of("01234567890") != string::npos) {
				outErr << "ERROR: " << media << endl;
				outErr << "Previous record has an invalid stoi argument error" << endl;
				throw runtime_error(row[7] + " are total weeks that are ");
				return -1;
			}
			Book book(row[0][0], row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]), stoi(row[7]));
			books.push_back(book);
			bookTotal++;
			break;
		}
		case 'S':
		{
			if (row[7] != "0" && row[7] != "1") {
				outErr << "ERROR: " << media << endl;
				outErr << "Previous record has an error in boolean value" << endl;
				throw runtime_error(row[7] + " is a boolean value that is ");
				return -1;
			}
			Song song(row[0][0], row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]), stoi(row[7]));
			songs.push_back(song);
			songTotal++;
			break;
		}
		default:
			break;
		}
		total++;

		Media media(row[0][0], row[1], row[2], stoi(row[3]), row[4], stoi(row[5]), stoi(row[6]));
		m.push_back(media);
	}
	catch (runtime_error& excpt) {
		cout << "Error: " << excpt.what() << " not allowed" << endl;
	}
	return 1;
}

//the same thing as increment list except with a different vector length to increment
int addToList(string media, ostream& outErr, vector<Media>& m, vector<Book>& books, vector<Movie>& movies, vector<Song>& songs) {
	string tempString;
	vector<string> row;
	bool pushToList = true;

	//create new string stream
	stringstream inSS(media);
	row.clear();

	//filter row into components
	while (getline(inSS, tempString, ',')) {
		row.push_back(tempString);
	}
	//push components into media if no errors
		if (row[1][0] != 'M' && row[1][0] != 'S' && row[1][0] != 'B') {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the type" << endl;
			pushToList = false;
		}
		if ((row[4].find_first_not_of("0123456789") != string::npos) || stoi(row[4]) < 1 || stoi(row[4]) > 10) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the rating" << endl;
			pushToList = false;
		}
		if ((row[6]).find_first_not_of("0123456789") != string::npos) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the length" << endl;
			pushToList = false;
		}
		if (((row[7]).find_first_not_of("0123456789") != string::npos) || (stoi(row[7]) < 1500) || (stoi(row[7]) > 2023)) {
			outErr << "ERROR: " << media << endl;
			outErr << "There was an invalid value entered for the year" << endl;
			pushToList = false;
		}
		if (row[1][0] == 'S' && row[8] != "0" && row[8] != "1") {
			outErr << "ERROR: ";
			outErr << "Unable to process command. There was an invalid value entered for items: " << row[2] << endl;
			pushToList = false;
		}
		if (row[1][0] == 'B' && row[8].find_first_not_of("01234567890") != string::npos) {
			outErr << "ERROR: ";
			outErr << "Unable to process command. There was an invalid value entered for items: " << row[2] << endl;
			pushToList = false;
		}

		//increments totals
		if (pushToList) {
			switch (row[1][0]) {
			case 'M':
			{
				vector<string> totalStars;
				for (int i = 8; i < row.size(); i++) {
					totalStars.push_back(row[i]);
				}
				Movie movie(row[1][0], row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]), totalStars);
				movies.push_back(movie);
				movieTotal++;
				break;
			}
			case 'B':
			{
				Book book(row[1][0], row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]), stoi(row[8]));
				books.push_back(book);
				bookTotal++;
				break;
			}
			break;
			case 'S':
			{
				Song song(row[1][0], row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]), stoi(row[8]));
				songs.push_back(song);
				songTotal++;
				break;
			}
			default:
				break;
			}

			Media media(row[1][0], row[2], row[3], stoi(row[4]), row[5], stoi(row[6]), stoi(row[7]));
			m.push_back(media);
			total++;
			return 1;
		}
		else {
			return -1;
		}
}

int readMediaList(istream& i, ostream& outErr, vector<Media>& m, vector<Book>& b, vector<Movie>& mo, vector<Song>& s) {
	string mediaString;

	//read through media list file
	while (getline(i, mediaString)) {

		if (mediaString == "Q") {
			return 1;
		}

		incrementList(mediaString, outErr, m, b, mo, s);
		
	}
	return 1;
}

void printAllMedia(string command, ostream& out, ostream& outErr, vector<Media>& m) {

	//checks for rating
	if (command.length() > 1 && (command.substr(2).find_first_not_of("0123456789") == string::npos)) {
		if (stoi(command.substr(2)) > 0 && stoi(command.substr(2)) < 11) {
			
			out << "+++++++++++++++++++++++++" << endl;
			out << "YOUR MEDIA LIST" << endl << endl;
			out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "TYPE" << endl;
			counter = 1;
			for (auto media : m) {
				if (media.getRating() >= stoi(command.substr(2))) {
					out << counter << " " << media.getTitle() << "\t\t" 
						<< media.getYearReleased() << "\t" << media.getRating() << "\t" << media.getType() << endl;
				}
				counter++;
			}
		}
		else {
			outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
		}
	}

	//prints without checking for rating
	else if (command.length() == 1) {
		out << "+++++++++++++++++++++++++" << endl;
		out << "YOUR MEDIA LIST" << endl << endl;
		out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "TYPE" << endl;

		counter = 1;
		for (auto media : m) {
			out << counter << " " << media.getTitle() << "\t\t" 
				<< media.getYearReleased() << "\t" << media.getRating() << "\t" << media.getType() << endl;
			counter++;
		}
	}
	else {
		outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
	}
}

void printBookList(string command, ostream& out, ostream& outErr, vector<Media>& m) {
	
	//checks for rating
	if (command.length() > 1 && (command.substr(2).find_first_not_of("0123456789") == string::npos)) {
		if (stoi(command.substr(2)) > 0 && stoi(command.substr(2)) < 11) {
			
			out << "+++++++++++++++++++++++++" << endl;
			out << "YOUR BOOK LIST" << endl << endl;
			out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "WKS ON NYT" << endl;
			counter = 1;
			for (auto media : m) {
				if (media.getRating() >= stoi(command.substr(2)) && media.getType() == 'B') {
					out << counter << " " << media.getTitle() << "\t\t" << media.getYearReleased() << "\t" 
						<< media.getRating() << "\t" << endl;
				}
				counter++;
			}
		}
		else {
			outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
		}
	}

	//prints without checking for rating
	else if (command.length() == 1) {
		out << "+++++++++++++++++++++++++" << endl;
		out << "YOUR BOOK LIST" << endl << endl;
		out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "WKS ON NYT" << endl;
		counter = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m.at(i).getType() == 'B') {
				out << counter << " " << m.at(i).getTitle() << "\t\t" << m.at(i).getYearReleased() << "\t" 
					<< m.at(i).getRating() << "\t" << endl;
			}
			counter++;
		}
	}
	else {
		outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
	}
}

void printMovieList(string command, ostream& out, ostream& outErr, vector<Media>& m) {

	//checks for rating
	if (command.length() > 1 && (command.substr(2).find_first_not_of("0123456789") == string::npos)) {
		if (stoi(command.substr(2)) > 0 && stoi(command.substr(2)) < 11) {
			out << "+++++++++++++++++++++++++" << endl;
			out << "YOUR MOVIE LIST" << endl << endl;
			out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "STARS" << endl;
			counter = 1;
			for (auto media : m) {
				if (media.getRating() >= stoi(command.substr(2)) && media.getType() == 'M') {
					out << counter << " " << media.getTitle() << "\t\t" << media.getYearReleased() << "\t" << media.getRating() << endl;
				}
				counter++;
			}
		}
		else {
			outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
		}
	}

	//prints without checking for rating
	else if (command.length() == 1)
	{
		out << "+++++++++++++++++++++++++" << endl;
		out << "YOUR MOVIE LIST" << endl << endl;
		out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "STARS" << endl;
		counter = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m.at(i).getType() == 'M') {
				out << counter << " " << m.at(i).getTitle() << "\t\t" << m.at(i).getYearReleased() << "\t" << m.at(i).getRating() << endl;
			}
			counter++;
		}
	}
	else {
		outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
	}
}

void printSongList(string command, ostream& out, ostream& outErr, vector<Media>& m) {
	
	//checks for rating
	if (command.length() > 1 && (command.substr(2).find_first_not_of("0123456789") == string::npos)) {
		if (stoi(command.substr(2)) > 0 && stoi(command.substr(2)) < 11) {
			out << "+++++++++++++++++++++++++" << endl;
			out << "YOUR SONG LIST" << endl << endl;
			out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING" << endl;
			counter = 1;
			for (auto media : m) {
				if (media.getRating() >= stoi(command.substr(2)) && media.getType() == 'S') {
					out << counter << " " << media.getTitle() << "\t\t" << media.getYearReleased() << "\t" << media.getRating() << endl;
				}
				counter++;
			}
		}
		else {
			outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
		}
	}

	//prints without checking for rating
	else if (command.length() == 1){
		out << "+++++++++++++++++++++++++" << endl;
		out << "YOUR SONG LIST" << endl << endl;
		out << "#\t" << "TITLE\t\t\t" << "YEAR\t" << "RATING\t" << "TOP 40" << endl;
		counter = 1;
		for (int i = 0; i < m.size(); i++) {
			if (m.at(i).getType() == 'S') {
				out << counter << " " << m.at(i).getTitle() << "\t\t" << m.at(i).getYearReleased() << "\t" << m.at(i).getRating() << endl;
			}
			counter++;
		}
	}
	else {
		outErr << "Unable to process command. The rating of: " << command.substr(2) << " is invalid" << endl;
	}
}

void printTotals(ostream& out) {
	out << "+++++++++++++++++++++++++" << endl;
	out << "YOUR MEDIA LIBRARY" << endl;
	out << "#\t" << "TYPE" << endl;
	out << movieTotal << "\tMovies" << endl;
	out << bookTotal << "\tBooks" << endl;
	out << songTotal << "\tSongs" << endl;
	out << total << "\tItems" << endl;
}

void addNewMedia(string command, ostream& out, ostream& outErr, vector<Media>& m, vector<Book>& b, vector<Movie>& mo, vector<Song>& s) {
	out << "adding media..." << endl;
	int confirmation = addToList(command, outErr, m, b, mo, s);
	if (confirmation == 1) {
		out << m.back().getTitle() << " was added to your list" << endl << endl;
	}
}

void listMovieStars(string inCommands, ostream& out, ostream& outErr, vector<Movie*>& m) {
	bool movieStarsFound = false;
	cout << "here now" << endl;
	for (auto media : m) {
		if (media->getType() == 'M' && media->getTitle() == inCommands.substr(5)) {
			movieStarsFound = true;
			out << "***********************" << endl;
			out << "THE STARS OF THE MOVIE" << media->getTitle() << "ARE:" << endl;
			for (auto star : media->getStars()) {
				out << star << endl;
			}
		}
	}
	
	if (!movieStarsFound) {
		outErr << "Unable to process command. The movie: '" << inCommands.substr(5) 
			<< "' is not found in your list" << endl;
	}

	for (auto media : m) {
		delete media;
		media = nullptr;
	}
}

void listKeyName(string inCommands, ostream& out, ostream& outErr, vector<Media>& m) {
	bool keyNameFound = false;
	vector<Media> keyMedias;
	for (auto media : m) {
		if (media.getKeyName() == inCommands.substr(2)) {
			keyNameFound = true;
			keyMedias.push_back(media);
		}
	}

	if (!keyNameFound) {
		outErr << "Unable to process command. The key name: " << inCommands.substr(2)
			<< " is not a key name in any media in your list" << endl;
	}
	else {
		out << "**********************" << endl;
		out << inCommands.substr(2) << " appears in the following media items(s) :" << endl;
		out << "TYPE\t" << "TITLE\t\t" << "RATING" << endl;
		for (auto media : keyMedias) {
			out << media.getType() << "\t" << media.getTitle() << "\t\t" << media.getRating() << endl;
		}
	}

}
