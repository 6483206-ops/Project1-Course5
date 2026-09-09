// Project1 Course5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWiner { User = 1, PC = 2, NoWiner = 3 };
enChoice UserChoice, PcChoice;
enWiner Winer;
int  Player1Counter = 0, ComputerCounter = 0, DrawCounter = 0;

int ReadPositiveNum(string message) {
	int num;
	do {
		cout << message << endl;
		cin >> num;
	} while (num <= 0);
	return num;
}

void PrintChoice(enChoice Choice) {
	switch (Choice) {
	case Stone:
		cout << "Stone" << endl; break;
	case Paper:
		cout << "Paper" << endl; break;
	case Scissors:
		cout << "Scissors" << endl; break;
	}
}

int AskTheNumOfRound() {
	int n;
	do {
		n = ReadPositiveNum("How Many Rounds 1 to 10 ? ");
	} while (n > 10 || n < 1);
	return n;
}

enChoice ReadUserChoice() {
	cout << endl;
	int n;
	do {
		n = ReadPositiveNum("Your choice: [1]Stone, [2]Peaper, [3]Scissors ? ");
	} while (n > 3 || n < 1);
	UserChoice = enChoice(n);
	return UserChoice;
}

enChoice RandomChoice() {

	int from = 1, to = 2;
	PcChoice = enChoice(rand() % (to - from + 1) + from);
	return PcChoice;

}

void StartTheRound(int RoundNum) {
	cout << endl;
	cout << "Round [" << RoundNum << "] begins:\n" << endl;
	UserChoice = ReadUserChoice();
	PcChoice = RandomChoice();
}

enWiner TheWiner() {
	if (UserChoice == enChoice::Stone && PcChoice == enChoice::Stone || UserChoice == enChoice::Paper && PC == enChoice::Paper || UserChoice == enChoice::Scissors && PcChoice == enChoice::Scissors)
		Winer = enWiner::NoWiner;
	else if (PcChoice == enChoice::Stone && UserChoice == enChoice::Scissors || PcChoice == enChoice::Paper && UserChoice == enChoice::Stone || PcChoice == enChoice::Scissors && UserChoice == enChoice::Paper)
		Winer = enWiner::PC;
	else if (UserChoice == enChoice::Stone && PcChoice == enChoice::Scissors || UserChoice == enChoice::Paper && PcChoice == enChoice::Stone || UserChoice == enChoice::Scissors && PcChoice == enChoice::Paper)
		Winer = enWiner::User;

	return Winer;
}

void PrintTheResultOfTheRound(int RoundNum) {
	cout << endl;
	cout << "________________________Round [" << RoundNum << "]________________________" << endl;
	cout << endl;
	cout << "Player1  Choice: "; PrintChoice(UserChoice);
	cout << "Computer Choice: "; PrintChoice(PcChoice);
	cout << "Round Winner   : ";
	enWiner Winer = TheWiner();
	if (Winer == enWiner::NoWiner) {
		cout << "[No Winer]" << endl;
		system("color 60");
		DrawCounter++;
	}
	else if (Winer == enWiner::PC) {
		cout << "[Computer]" << endl;
		system("color 40");
		ComputerCounter++;
	}
	else if (Winer == enWiner::User) {
		cout << "[Player1]" << endl;
		system("color 2F");
		Player1Counter++;
	}
	cout << endl;
	cout << "________________________________________________________" << endl;
	cout << "\n\n";
}

void EndTheGame(int RoundCounter) {
	cout << "\n\n";
	cout << "\t\t\t\t\t\t\t\t";
	cout << "_______________________________________________________________________________________" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "                                  +++ G a m e   O v e r +++                            " << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "_______________________________________________________________________________________" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	cout << "______________________________________ { Game Results } _______________________________" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t" << "Game Rounds        : " << RoundCounter << endl;
	cout << "\t\t\t\t\t\t\t\t" << "Player won times   : " << Player1Counter << endl;
	cout << "\t\t\t\t\t\t\t\t" << "Computer won times : " << ComputerCounter << endl;
	cout << "\t\t\t\t\t\t\t\t" << "Draw Times         : " << DrawCounter << endl;
	cout << "\t\t\t\t\t\t\t\t" << "Final Winner       : ";
	if (Player1Counter > ComputerCounter) {
		cout << "Player1" << endl;
		system("color 2F");
	}
	else if (Player1Counter < ComputerCounter) {
		cout << "Computer" << endl;
		system("color 40");
	}
	else {
		cout << "No Winner" << endl;
		system("color 60");
	}
	cout << "\t\t\t\t\t\t\t\t" << "_______________________________________________________________________________________" << endl;
	cout << endl;

}

bool reStartTheGame() {
	char s;
	do {
		cout << "Do you want to play again? Y/N?  ";
		cin >> s;
		if (s == 'Y')
			return  true;
		else if (s == 'N')
			return false;
	} while (s != 'N' && s != 'Y');
}

void StartTheGame() {
	bool R;
	do {
		int NumOfRounds = AskTheNumOfRound();
		for (int Round = 1; Round <= NumOfRounds; Round++) {
			StartTheRound(Round);
			PrintTheResultOfTheRound(Round);
		}
		EndTheGame(NumOfRounds);
		R = reStartTheGame();
		if (R) {
			system("cls");
		}
	} while (R);
}
int main()
{
	srand((unsigned)time(NULL));
	StartTheGame();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
