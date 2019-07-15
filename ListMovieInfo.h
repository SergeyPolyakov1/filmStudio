#pragma once

struct MovieInfo
{
	char  movieTitle[20];
	char  directorsName[20];
	int yearOfIssue = 0;
	int durationInMinutes = 0;
	int numberOfRentals = 0;

};


struct ListMovieInfo
{
	MovieInfo mi;
	ListMovieInfo* next = nullptr;
};

void add(ListMovieInfo **begin, const MovieInfo &newMi);
void deleteCell(ListMovieInfo **begin, const char *movieTitle);
void changeInfo(ListMovieInfo ** begin, const char * movieTitle);
void titleMovieChange(char movieTitl[]);
void directorsNameChange(char directorsName[]);
void print(ListMovieInfo * begin);
void printMovieMoreThanAnHour(ListMovieInfo * begin);
void printLaterThanEnterYear(ListMovieInfo * begin, int year);
ListMovieInfo* Sort(ListMovieInfo * begin);
void printMovieDirectors(ListMovieInfo *begin,char*nameDirectors);
void save(ListMovieInfo **begin,char *file);
ListMovieInfo * load(char*file);
void menu();
