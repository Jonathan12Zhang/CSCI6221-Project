#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class student {
private:
	string firstname, lastname, ID;
	//vector<student> studentArray[];

public:
	student() {
		firstname = "";
		lastname = "";
		ID = "";
	}
	student(string firstname, string lastname, string ID) {
		this->firstname = firstname;
		this->lastname = lastname;
		this->ID = ID;
	}
	void setFirstName(string name) {
		this->firstname = name;
	}
	void setLastName(string name) {
		this->lastname = name;
	}
	void setID(string ID) {
		this->ID = ID;
	}
	string getFirstName() {
		return this->firstname;
	}
	string getLastName() {
		return this->lastname;
	}
	string display() {
		return firstname + " " + lastname + " " + ID;
	}
	string getID() {
		return this->ID;
	}

};


void printMatches(string str, regex reg) {
	smatch matches;
	while (regex_search(str, matches, reg)) {
		cout << matches.str() << "\n";
		str = matches.suffix().str();
		cout << "\n" << endl;
	}
}




int main() {

	student s = student();
	string userInput;
	vector<student> studentArray;

	while (true) {
		cout << "insert or show students? type i / s" << endl;
		cin >> userInput;
		//cout << typeid(studentArray.size()).name() << endl;
		if (userInput.compare("i") == 0) {
			cout << "inserting student" << endl;

			cout << "\n" << "firstname" << endl;
			cin >> userInput;
			s.setFirstName(userInput);

			cout << "lastname" << endl;
			cin >> userInput;
			s.setLastName(userInput);

			cout << "ID" << endl;
			cin >> userInput;
			s.setID(userInput);

			if (studentArray.size() >= 1) {
				for (unsigned int i = 0; i < studentArray.size(); i++) {
					if (studentArray[i].getID().compare(userInput) == 0) {
						cout << "duplicated student!!! index of " << i << "\n" << endl;
						break;
					}
					else if ((i + 1) == studentArray.size()) {
						studentArray.push_back(s);
						break;
					}
				}
			}
			else {
				studentArray.push_back(s);
			}
		}

		if (userInput.compare("s") == 0) {
			for (student& s : studentArray) {
				cout << s.display() << "\n" << endl;
			}
		}

		if (userInput.compare("find") == 0) {
			cout << "what is the ID?" << endl;
			cin >> userInput;
			regex reg("\\b(" + userInput + ")" + "([^ ]*)");
			for (student& s : studentArray) {
				printMatches(s.getID(), reg);
			}
		}

		if (userInput.compare("remove") == 0) {
			cout << "what is the ID" << endl;
			cin >> userInput;
			for (unsigned int i = 0; i < studentArray.size(); i++) {
				if (studentArray[i].getID().compare(userInput) == 0) {
					studentArray.erase(studentArray.begin() + i);
					cout << "student removed!!! index of " << i << "\n" << endl;
					break;
				}
			}
		}

		if (userInput.compare("list") == 0) {
			smatch matche;
			string firstName;
			string lastName;
			vector<student> student;


			cout << "\n" << "what is the firstname" << endl;
			cin >> userInput;
			regex reg1("\\b(" + userInput + ")" + "([^ ]*)");
			cout << "what is the lastname" << endl;
			cin >> userInput;
			regex reg2("\\b(" + userInput + ")" + "([^ ]*)");
			cout << "matching firstname, lastname, or both?" << endl;
			cin >> userInput;

			if (userInput.compare("both") == 0) {
				for (auto s : studentArray) {
					firstName = s.getFirstName();
					lastName = s.getLastName();
					if (regex_search(firstName, matche, reg1) && regex_search(lastName, matche, reg2)) {
						student.push_back(s);
					}
				}

				for (auto s : student) {
					cout << s.display() << "\n" << endl;
				}
			}
			else if (userInput.compare("firstname") == 0) {
				for (auto s : studentArray) {
					firstName = s.getFirstName();
					lastName = s.getLastName();
					if (regex_search(firstName, matche, reg1)) {
						student.push_back(s);
					}
				}

				for (auto s : student) {
					cout << s.display() << "\n" << endl;
				}
			}
			else if (userInput.compare("lastname") == 0) {
				for (auto s : studentArray) {
					firstName = s.getFirstName();
					lastName = s.getLastName();
					if (regex_search(lastName, matche, reg2)) {
						student.push_back(s);
					}
				}

				for (auto s : student) {
					cout << s.display() << "\n" << endl;
				}
			}
			student.clear();
		}
	}
	return 0;
}

