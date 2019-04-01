#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

void loadFriendInfo(int**& ID, int &users) {
	char buff[50];
	int k = 0;

	ifstream fin("C:\\Users\\Bilal Ahmed\\Desktop\\Programming Fundamentals\\FriendInfo\\friend_info.txt");
	if (fin.fail()) {
		cout << "Could not locate";
	}
	else {
		while (fin.getline(buff, 50)) {
			users++;
		}
		ID = new int*[users];
	}
	fin.close();

	ifstream openf("C:\\Users\\Bilal Ahmed\\Desktop\\Programming Fundamentals\\FriendInfo\\friend_info.txt");
	if (openf.fail()) {
		cout << "Could not locate";
	}
	else {
		while (openf.getline(buff, 50)) {
			int size = 2;
			for (int i = 0; buff[i] != '\0'; i++) {
				if (buff[i] == ',') {
					size++;
				}
			}
			int* Friends = new int[size];
			for (int i = 0, j = 0; buff[i] != '\0'; i++) {
				if (buff[i] != ',') {
					if (buff[i] == '-') {
						Friends[j++] = -1;
					}
					else if (Friends[j] != '-1') {
						Friends[j] = buff[i] - 48;
						j++;
					}
				}
				if (buff[i + 1] == '\0') {
					Friends[j] = -1;
				}
			}
			ID[k] = Friends;
			k++;
		}
	}
	openf.close(); 
}

void checkConsistency(int** ID, int users) {
	bool check = true;
	for (int i = 0; i < users; i++) {
		for (int j = 0; ID[i][j] != -1; j++) {
			int a = ID[i][j];
			for (int k = 0; ID[a][k] != -1; k++) {
				if (ID[a][k] == ID[i][j]) {
					check = false;
				}
			}
		}
	}
	if (check) {
		cout << "Is Consistent" << endl;
	}
	else {
		cout << "Not Consistent" << endl;

	}
}

void printFriendInfo(int**& ID, int users) {
	for (int i = 0; i < users; i++) {
		cout << i << "  :";
		for (int j = 0; ID[i][j] != -1; j++) {
			cout << " " << ID[i][j];
		}
		cout << endl;
	}
}

void addNewUser(int**& ID, int& users){
	int** temp = new int*[users++];
	for (int i = 0; i < users; i++) {
		temp[i] = ID[i];
	}
	temp[users] = new int[1];
	temp[users][0] = -1;
	delete[] ID;
	ID = temp;
	printFriendInfo(ID, users);
}

void addFriends(int**& ID, int& users, int n, int m) {
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; ID[n][i] != -1; i++) {
		count1++;
	}
	bool check = false;
	for (int i = 0; i < count1; i++) {
		if (ID[n][i] == m) {
			check = true;
		}
	}
	if (!check) {
		int* temp = new int[count1 + 1];
		for (int i = 0; i < count1; i++) {
			temp[i] = ID[n][i];
		}

		temp[count1] = m;
		temp[count1 + 1] = -1;
		delete ID[n];
		ID[n] = temp;
	}

	for (int i = 0; ID[m][i] != -1; i++) {
		count2++;
	}
	bool checkagain = false;
	for (int i = 0; i < count1; i++) {
		if (ID[m][i] == n) {
			checkagain = true;
		}
	}
	if (!checkagain) {
		int* buff = new int[count2 + 1];
		for (int i = 0; i < count2; i++) {
			buff[i] = ID[m][i];
		}
		buff[count2] = n;
		buff[count2 + 1] = -1;
		delete ID[m];
		ID[m] = buff;
	}
}

void removeUser(int**& ID, int& users, int x) {
	
	int** temp = new int*[users - 1];
	int j = 0;
	for (int i = 0;i <users; i++) {
		if (i != x){
			temp[j] = ID[i];
			j++;
		}
	}
	delete[]ID[x];
	delete[]ID;
	users=users-1;
	int count = 0;
	int z = 0;
	bool check = false;
	for (int i = 0; i < users; i++) {
		check = false;
		for (int j = 0; temp[i][j] != -1; j++) {
			if (temp[i][j] == x) {
				check = true;
			}
		}
		if (check) {
			count = 0;
			for (int j = 0; temp[i][j]!=-1; j++) {
				count++;
			}

			int* buff = new int[count];
			z = 0;
			for (int j = 0; temp[i][j]!=-1 ; j++) {
				if (temp[i][j] != x) {
					buff[z] = temp[i][j];
					z++;
				}
				
			}
			buff[count-1] = -1;
			delete[] temp[i];
			temp[i] = buff;
		}
	}
	for (int i = 0; i < users; i++) {
		for (int j = 0; temp[i][j] != -1; j++) {
			if (temp[i][j] > x) {
				temp[i][j] = temp[i][j] - 1;
			}
		}

	}
	ID = temp;
}

void removeFriend(int**& ID, int& users, int a, int b) {
	int count1 = 0;
	bool check = true;
	for (int i = 0; ID[a][i] != -1; i++) {
		count1++;
	}
	for (int i = 0; ID[a][i] != -1; i++) {
		if (ID[a][i] != b) {
			check = false;
		}
	}
	if (!check) {
		int* temp = new int[count1 - 1];
		for (int j = 0, k = 0; j < count1; k++) {
			if (ID[a][k] != b) {
				temp[j] = ID[a][k];
				j++;
			}
		}
		temp[count1] = -1;
		delete[] ID[a];
		ID[a] = temp;
	}
	
	int count2 = 0;
	bool checkagain = true;
	for (int i = 0; ID[b][i] != -1; i++) {
		count2++;
	}
	for (int i = 0; ID[b][i] != -1; i++) {
		if (ID[b][i] != a) {
			checkagain = false;
		}
	}
	if (!check) {
		int* buff = new int[count2 - 1];
		for (int j = 0, k = 0; j < count2; k++) {
			if (ID[b][k] != a) {
				buff[j] = ID[b][k];
				j++;
			}
		}
		buff[count2] = -1;
		delete[] ID[b];
		ID[b] = buff;
	}
	
}

void printMutualFriends(int**& ID, int& users, int f1, int f2) {
	cout << "Mutual friends are:";
	for (int i = 0; ID[f1][i] != -1; i++) {
		for (int j = 0; ID[f2][j] != -1; j++) {
			if (ID[f1][i] == ID[f2][j]) {
				cout << ID[f1][i] << " ";
			}
		}
	}
}

void printFriendsOfFriends(int**& ID, int& users, int u) {
	int* temp = new int[users + 1];
	int count = 0;
	int a = 0;
	cout << "Friends of Friends for " << u << " are:" << endl;
	for (int i = 0, k = 0; ID[u][i] != -1; i++) {
		cout << ID[u][i] << ":";
		temp[k] = ID[u][i];
		a = temp[k];
		k++;
		for (int j = 0; ID[a][j] != -1; j++) {
			if (ID[a][j] != u) {
				cout << ID[a][j] << " ";
			}
		}
		cout << endl;
	}
}

void mergeProfiles(int**& ID, int& users, int id1, int id2) {
	int* temp = new int[users + users];
	int count = 0;
	for (int i = 0; ID[id1][i] != -1; i++) {
		count++;
	}
	int* buff = new int[count];
	int a = 0, b = 0;
	for (int i = 0; ID[id1][i] != -1; i++) {
		buff[i] = ID[id1][i];
		buff[count] = -1;
		for (int j = 0, k = 0; ID[id2][j] != -1; j++) {
			if (ID[id1][i] != ID[id2][j]) {
				temp[k] = ID[id2][j];
				k++;
				a = k;
			}
		}
	}
	for (int i = a, j = 0; buff[j] != -1; i++) {
		temp[i] = buff[j];
		b = i + 1;
		j++;
	}
	temp[b] = -1;
	removeUser(ID, users, id2);
	delete[] ID[id1];
	ID[id1] = temp;
}

void saveFriendInfo (int** ID, int users) {
	ofstream fout("C:\\Users\\Bilal Ahmed\\Desktop\\Programming Fundamentals\\FriendInfo\\friend_info.txt");
	for (int i = 0; i < users; i++) {
		for (int j = 0; ID[i][j] != -1; j++) {
			fout << ID[i][j] << ",";
		}
		fout << -1;
		fout << endl;
	}
	fout.close();
}

void clearAll(int**& ID, int& users) {
	for (int i = 0; i < users; i++) {
		delete[] ID[i];
	}
	delete[] ID;
}

void options(int**& ID, int& users) {
	system("cls");
	printFriendInfo(ID, users);
}

int main() {
	int **ID = new int*[10];
	int users = 0;
	loadFriendInfo(ID, users);
	//options(ID, users);
	printFriendInfo(ID, users);
	cout << endl << endl;

	int key = 0;
	int n = 0;
	int m = 0;
	int r = 0;
	int a = 0;
	int b = 0;
	int f1 = 0;
	int f2 = 0;
	int u = 0;
	int id1 = 0;
	int id2 = 0;

	cout << "Press 0 to check consistency" << endl;
	cout << "Press 1 to Add User" << endl;
	cout << "Press 2 to Add Friend" << endl;
	cout << "Press 3 to Remove User" << endl;
	cout << "Press 4 to Remove Friends" << endl;
	cout << "Press 5 to Print Mutual Friends" << endl;
	cout << "Press 6 to Print Friends of friends" << endl;
	cout << "Press 7 to merge 2 profiles" << endl;
	cout << "Press 8 to Save data" << endl;
	cout << "Press 9 to Clear data" << endl;

	key = _getch();
	switch (key) {

	case '0':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		checkConsistency(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '1':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		addNewUser(ID, users);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '2':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Enter User 1:";
		cin >> n;
		cout << "Enter User 2:";
		cin >> m;
		cout << endl << endl;
		addFriends(ID, users, n, m);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '3':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Enter User you want to remove:";
		cin >> r;
		cout << endl << endl;
		removeUser(ID, users, r);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '4':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Enter friend 1:";
		cin >> a;
		cout << "Enter friend 2:";
		cin >> b;
		removeFriend(ID, users, a, b);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '5':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Enter friend 1:";
		cin >> f1;
		cout << "Enter friend 2:";
		cin >> f2;
		printMutualFriends(ID, users, f1, f2);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		system("pause");
		break;

	case '6':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl;
		cout << "Enter a User:";
		cin >> u;
		printFriendsOfFriends(ID, users, u);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '7':
		system("cls");
		printFriendInfo(ID, users);
		cout << endl;
		cout << "Enter ID for profile 1:";
		cin >> id1;
		cout << "Enter ID for profile 2:";
		cin >> id2;
		mergeProfiles(ID, users, id1, id2);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '8':
		system("cls");
		printFriendInfo(ID, users);
		saveFriendInfo(ID, users);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;

	case '9':
		system("cls");
		printFriendInfo(ID, users);
		clearAll(ID, users);
		cout << endl;
		printFriendInfo(ID, users);
		cout << endl << endl;
		cout << "Press 0 to check consistency" << endl;
		cout << "Press 1 to Add User" << endl;
		cout << "Press 2 to Add Friend" << endl;
		cout << "Press 3 to Remove User" << endl;
		cout << "Press 4 to Remove Friends" << endl;
		cout << "Press 5 to Print Mutual Friends" << endl;
		cout << "Press 6 to Print Friends of friends" << endl;
		cout << "Press 7 to merge 2 profiles" << endl;
		cout << "Press 8 to Save data" << endl;
		cout << "Press 9 to Clear data" << endl;
		break;
	}
	system("pause");
}
	