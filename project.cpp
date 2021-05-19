#include<iostream>
using namespace std;

// Functions used in program;
void showMenu();
void patientList();
void search();
void printPatient(int i);
void addRecord();
void deleteRecord();
void editPatient();

//Array used in program;
const int size = 50;
int id[size], age[size], diseaseId[size], room[size];
char sex[size], arr[size];
int  counter = 0;

int main() {
	showMenu();
}


void showMenu() {
	int input;
	cout << endl << endl;
	cout << "Menu:" << endl;
	cout << "---------------------" << endl;
	cout << "1: Add New Record" << endl;
	cout << "2: Search Record" << endl;
	cout << "3: Edit Patient Record" << endl;
	cout << "4: List Patient Record " << endl;
	cout << "5: Delete Patient Record " << endl;
	cout << "0: Quit" << endl;
	cout << "----------------------" << endl;
	cout << "What do you want to do? ";
	cin >> input;
	cout << endl << endl;

	switch (input) {
	case 0:
		exit(0);

	case 1:
		addRecord();
		break;

	case 2:
		search();
		break;

	case 3:
		editPatient();
		break;

	case 4:
		patientList();
		break;

	case 5:
		deleteRecord();
		break;

	default:
		cout << "Incorrect input. Please enter again." << endl;
		break;
	}
	showMenu();
}

void patientList() {
	cout << "List of patient record:" << endl;
	cout << "-----------------------" << endl;
	int i = 0;
	while (i < counter) {
		printPatient(i);
		i++;
	}
}

void search() {
	int input;
	cout << "Input patient Id: ";
	cin >> input;

	for (int i = 0; i <= size - 1; i++) {
		if (input == id[i]) {
			printPatient(i);
			return;
		}
	}
	cout << "No record found" << endl;
}


void printPatient(int i) {
	cout << "Id: " << id[i] << endl;
	cout << "Age: " << age[i] << endl;
	cout << "specialist room number: " << room[i] << endl;
	cout << "Disease Id: " << diseaseId[i] << endl;
	cout << "Sex: " << sex[i] << endl;
	cout << endl << endl;
}

void addRecord() {
	char input;
	cout << "Enter O for O.P.D and E for emergency " << endl;
	cout << "Choose between O.P.D and Emergency Service: ";// Enter O for O.P.D and E for Emergency
	cin >> input;

	if (input == ('O' || 'o') || ('e' || 'E')) {
		cout << "Id: ";
		cin >> id[counter];
		cout << "Enter Age: ";
		cin >> age[counter];

		while ((age[counter] <= 0) || (age[counter] > 100)) {
			cout << "Enter age correctly: ";
			cin >> age[counter];
		}

		cout << "Enter Disease ID: ";
		cin >> diseaseId[counter];
		cout << "Enter Specialist room number: ";
		cin >> room[counter];
		while (room[counter] > 205 || room[counter] < 201) {
			cout << "Enter room between 201 to 205: ";
			cin >> room[counter];
		}

		cout << "Enter Gender (f for female and m for male) : ";
		cin >> sex[counter];

		while (!(sex[counter] == 'm' || sex[counter] == 'M' || sex[counter] == 'f' || sex[counter] == 'F')) {
			cout << "Enter Gender correctly: ";
			cin >> sex[counter];
		}
	}
	cout << "Id: " << id[counter] << endl;
	cout << "Disease Id: " << diseaseId[counter] << endl;
	cout << "sex: " << sex[counter] << endl;
	cout << "Age: " << age[counter] << endl;
	cout << "Room: " << room[counter] << endl;
	counter++;
}

void deleteRecord() {
	int input;
	cout << "Input patient Id you want to delete: ";
	cin >> input;

	for (int i = 0; i <= size - 1; i++) {
		if (input == id[i]) {
			id[i] = 0;
			age[i] = 0;
			sex[i] = 0;
			diseaseId[i] = 0;
			room[i] = 0;
			return;
		}
	}
}

void editPatient() {
	int input;
	cout << "Enter Id of Patient you want to edit: ";
	cin >> input;

	for (int i = 0; i <= size - 1; i++) {
		if (input == id[i]) {
			cout << "Enter Id: ";
			cin >> id[i];
			cout << "Age: ";
			cin >> age[i];
			cout << "Disease Id: ";
			cin >> diseaseId[i];
			cout << "Sex: ";
			cin >> sex[i];
			cout << "Room of specialist: ";
			cin >> room[i];
			printPatient(i);
		}
	}
}