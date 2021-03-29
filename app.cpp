#include <iostream>
#include <fstream>

using namespace std;

struct add_diary{
	string title;
	string notes;
};

void read_diary(){
	string myText;
	ifstream readed("database.txt");
	printf("\tTITLE\t \tDIARY\n");
	while (getline (readed, myText)) {
		printf("\t%s\n", myText.c_str());
	}
	readed.close();
}
void create_diary(string name, string diary){
	ofstream fileappend("database.txt", ios::app);
	string myinput;
	myinput = name + "\t\t" + diary + "\n";
	fileappend << myinput;
	fileappend.close();
}

int main()
{
	struct add_diary create;
	char choose[10], aggre[10];
	puts("----------Welcome to diary management system----------");
	puts("|1. Create new diary");
	puts("|2. Show data diary");
	puts("------------------------------------------------------");
	printf("Enter your command: ");
	scanf("%s", choose);
	if(*choose == '1'){
		puts("> What the title do you creating a diary");
		printf("Answer: ");
		cin >> create.title;
		puts("> Input the data your diary");
		printf("Answer: ");
		cin >> create.notes;
		printf("Are you sure ? (Y/N) ");
		scanf("%s", &aggre);
		if(*aggre == 'Y' || *aggre == 'y'){
			create_diary(create.title, create.notes);
			puts("----------Successfuly create new diary----------");
			system("cls & app");
		}
	};
	if(*choose == '2'){
		read_diary();
	}
	else{
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
