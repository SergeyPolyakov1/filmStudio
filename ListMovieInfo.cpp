#include "ListMovieInfo.h"
#include<iostream>



using namespace std;

void add(ListMovieInfo ** begin, const MovieInfo &newMi)
{

	ListMovieInfo *newCell = new  ListMovieInfo;
	newCell->mi = newMi;
	newCell->next = (*begin)->next;
	(*begin)->next = newCell;
}

void deleteCell(ListMovieInfo ** begin, const char *movieTitle)
{
	if (*begin == nullptr)
	{
		cout << "List is clear!\n";
		return;
	}

	ListMovieInfo *temp = *begin;
	if (temp->mi.movieTitle == movieTitle)
	{
		*begin = temp->next;
		delete temp;
	}

	ListMovieInfo *temp1 = temp->next;

	while (temp1)
	{
		if (temp1->mi.movieTitle == movieTitle)
		{
			temp->next = temp1->next;
			delete temp1;
			return;
		}
		temp = temp1;
		temp1 = temp1->next;

	}
}

void changeInfo(ListMovieInfo ** begin, const char * movieTitle)
{
	ListMovieInfo * temp = *begin;
	int choice;
	while (temp)
	{
		if (strcmp(temp->mi.movieTitle, movieTitle) == 0)
		{
			cout << "What field do you want to change?\n"
				<< "1.Movie Title\n"
				<< "2.directors Name\n"
				<< "3.year Of Issue\n"
				<< "4.duration In Minutes\n"
				<< "5.numberOfRentals\n";
			cin >> choice;
			switch (choice)
			{
			case 1: cout << "Enter new Movie Title\n";
				titleMovieChange( temp->mi.movieTitle);
				return;
			case 2: cout << "Enter new directors Name\n";
				directorsNameChange(temp->mi.directorsName);
				return;
			case 3: cout << "Enter new year Of Issue\n";
				cin >> temp->mi.yearOfIssue;
				return;
			case 4: cout << "Enter new duration In Minutes\n";
				cin >> temp->mi.durationInMinutes;
				return;
			case 5: cout << "Enter new number Of Rentals\n";
				cin >> temp->mi.numberOfRentals;
				return;
			default:
				cout << "You Enter fail choice\n";
				break;
			}
			
		}
		temp = temp->next;
	}

	cout << "this movie is not in listed\n";
}

void titleMovieChange(char movieTitl[])
{
	int length = 0;
	cout << "Enter new title movie\n";
	cin >> movieTitl;
	for (int i = 0; i < 30; i++)
	{
		if (movieTitl[i] >= 'a' && movieTitl[i] <= 'z'
			|| movieTitl[i] >= 'A' && movieTitl[i] <= 'Z'
			|| movieTitl[i] >= '0' && movieTitl[i] <= '9')
			length++;
	}
	movieTitl[length] = '\0';
}

void directorsNameChange(char directorsName[])
{
	int length = 0;
	cout << "Enter new directors name\n";
	cin >> directorsName;
	for (int i = 0; i < 30; i++)
	{
		if (directorsName[i] >= 'a' && directorsName[i] <= 'z'
			|| directorsName[i] >= 'A' && directorsName[i] <= 'Z'
			|| directorsName[i] >= '0' && directorsName[i] <= '9')
			length++;
	}
	directorsName[length] = '\0';
}

void print(ListMovieInfo * begin)
{
	ListMovieInfo * temp = begin;

	while (temp)
	{
		
		cout << "movie title " << temp->mi.movieTitle << endl
			<< "directors name " << temp->mi.directorsName << endl
			<< "year Of Issue " << temp->mi.yearOfIssue << endl
			<< "duration In Minutes " << temp->mi.durationInMinutes << endl
			<< "numberOfRentals " << temp->mi.numberOfRentals << endl
			<< "_________________________________________________________\n";
		temp = temp->next;
	}

}

void printMovieMoreThanAnHour(ListMovieInfo * begin)
{
	ListMovieInfo * temp = begin;
	while (temp)
	{
		if (temp->mi.durationInMinutes > 60)
		{
			cout << "movie title " << temp->mi.movieTitle << endl
				<< "_________________________________________________________\n";
			temp = temp->next;
		}
		else
		temp = temp->next;
	}
}

void printLaterThanEnterYear(ListMovieInfo * begin,int year)
{
	ListMovieInfo * temp = begin;
	while (temp)
	{
		if (temp->mi.yearOfIssue > year)
		{
			cout << "movie title " << temp->mi.movieTitle << endl
				<< "_________________________________________________________\n";
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

ListMovieInfo* Sort(ListMovieInfo * begin)
{
	ListMovieInfo * sentinel = new ListMovieInfo;
	sentinel->next = nullptr;

	begin = begin->next;

	while (begin)
	{
		ListMovieInfo * nextCell = begin;
		begin = begin->next;
		ListMovieInfo * afterMe = sentinel;
		while (afterMe->next && (afterMe->next->mi.numberOfRentals < nextCell->mi.numberOfRentals))
		{
			afterMe = afterMe->next;
		}
		nextCell->next = afterMe->next;
		afterMe->next = nextCell;
	}

	return sentinel;
}

void printMovieDirectors(ListMovieInfo * begin, char * nameDirectors)
{
	ListMovieInfo * temp = begin;
	while (temp)
	{
		if (strcmp(temp->mi.directorsName, nameDirectors) ==0)
		{
			cout << "movie title " << temp->mi.movieTitle << endl
				<< "_________________________________________________________\n";
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
}

void save(ListMovieInfo ** begin ,char *file)
{
	FILE *fp;
	ListMovieInfo *temp = *begin;
	if ((fp = fopen(file, "ab")) == NULL)
	{
		printf("Open error.\n");
		return;
	}

	while (temp != NULL)
	{
		if (fwrite(&temp->mi, sizeof(struct MovieInfo), 1, fp) != 1)
			cout << "Error Save!\n";

		temp = temp->next;	
	}
	fclose(fp);
}
	

 ListMovieInfo * load(char * file)
	{
		FILE *fp;
		ListMovieInfo *loadList = new ListMovieInfo;
		


		if ((fp = fopen(file, "rb")) == NULL)
		{
			printf("open error.\n");
			exit(1);
		}	

		MovieInfo tmp ;
		
		
		while (!feof(fp))
		{

			if (fread(&tmp, sizeof(struct MovieInfo), 1, fp) != 1)
				cout << "Error LOAD!\n";
			add(&loadList, tmp);
		}
		
		fclose(fp);

		return loadList;
	}

 void menu()
 {
	 cout << "          MENU       \n"
		 << "*****************************\n"
		 << "1.add movie info\n"
		 << "2.delete movie info\n"
		 << "3.change movie info\n"
		 << "4.print\n"
		 << "5.print Movie More Than An Hour\n"
		 << "6.print Later Than Enter Year\n"
		 << "7.Sort\n"
		 << "8.print Movie Directors\n"
		 << "9.save\n"
		 << "10.load\n"
		 << "11.exit\n"
		 << "****************************\n";
 }
