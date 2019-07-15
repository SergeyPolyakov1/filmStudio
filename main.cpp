#include<iostream>
#include"ListMovieInfo.h"



using namespace std;

void main()
{
	

	MovieInfo mi = {"mk1","dresd",2000,80,100};
	MovieInfo mi2 = { "mk2","dresd",2000,90,80 };
	MovieInfo mi3 = { "mk3","dred",2002,80,130 };
	MovieInfo mi4 = { "mk4","drefd",2003,80,70 };
	
	

	ListMovieInfo *list = new ListMovieInfo;
	int choice = 0;
	add(&list, mi);
	add(&list, mi2);
	add(&list, mi3);
	add(&list, mi4);

	while (choice != 11)
	{
		menu();
		cout << "Enter choice\n";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
		{
			MovieInfo temp;
			cout << "Enter movie title\n";
			cin >> temp.movieTitle;
			cout << "Enter directors name \n";
			cin >> temp.directorsName;
			cout << "Enter year Of Issue\n";
			cin >> temp.yearOfIssue;
			cout << "Enter duration In Minutes\n";
			cin >> temp.durationInMinutes;
			cout << "Enter number Of Rentals\n";
			cin >> temp.numberOfRentals;
			add(&list, temp);
			system("cls");
		}
			break;
		case 2:
		{
			char  nameMovie[20];
			cout << "Enter movie title\n";
			cin >> nameMovie;
			deleteCell(&list, nameMovie);
			system("cls");
		}
			break;
		case 3:
		{
			char nameMovie[20];
			cout << "Enter name movie\n";
			cin >> nameMovie;
			changeInfo(&list, nameMovie);
			system("cls");
		}
			break;

		case 4:
		{
			print(list);
			system("pause");
			system("cls");
		}
			break;
		case 5:
		{
			printMovieMoreThanAnHour(list);
			system("pause");
			system("cls");
		}
			break;
		case 6:
		{
			int year;
			cout << "Enter year\n";
			cin >> year;
			printLaterThanEnterYear(list, year);
			system("pause");
			system("cls");
		}
			break;
		case 7:
			{
				ListMovieInfo *res = Sort(list);
				print(res);
				cout << "list is sorted\n";
				system("pause");
				system("cls");
			}
				break;
		case 8:
		{
			cout << "print Movie one Directors\n";
			char name[20] ;
			cout << "Enter name directors\n";
			cin >> name;
			printMovieDirectors(list, name);
			system("pause");
			system("cls");
		}
			break;
		case 9:
		{
			char file[20];
			cout << "Enter file name for save\n";
			cin >> file;
			save(&list, file);
		}
			break;
		case 10:
		{
			char filename[20];
			cout << "Enter file for load\n";
			cin >> filename;
			list = load(filename);
		}
			break;
		case 11:
			choice = 11;
			break;
			
		default:
			cout << "incorrect choice!\n";
			break;
		}
		
	}

	system("pause");
}