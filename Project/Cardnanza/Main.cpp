/*
CSI 2372 Fall 2015
David Delisle-Lalancette 7822733
Namchi Nguyen
*/

#include <fstream>

#include "Table.h"

Table * initializeTableFromStream(istream & in, CardFactory * cardFactory);
void persistTable(ostream & out, const Table* table);
bool isStreamNotOpenOrEmpty(ifstream & in);
string getPlayerName(int playerNumber);

/*
Checks if there is a saved state and initializes accordingly.
Performs main loop. Upon terminating main loop, persists state if necessary.
*/
int main()
{
	ifstream fileIn("save.txt");
	istream & in = fileIn;
	
	//Initialize
	Table * table = nullptr;
	CardFactory * pCardFactory = CardFactory::getFactory();


	if (isStreamNotOpenOrEmpty(fileIn))
	{
		string firstPlayerName = getPlayerName(1);
		string secondPlayerName = getPlayerName(2);

		table = new Table(firstPlayerName, secondPlayerName, pCardFactory);
	}
	else
	{		table = initializeTableFromStream(in, pCardFactory);
		fileIn.close();
	}

	bool pause = false;
	bool gameEnded = false;

	//Main Loop
	while (!pause && !gameEnded)
	{
		string winner;
		gameEnded = table->win(winner);
		
		if (!gameEnded)
		{
			pause = table->playOneRound(cout, cin);
		}
		else
		{
			cout << "Winner is: " << winner << endl;
		}
	}
	//Main loop end

	if (!gameEnded)
	{
		ofstream fileOut("save.txt");
		ofstream & out = fileOut;

		persistTable(out, table);
		fileOut.close();
	}

	delete table;
	delete pCardFactory;

	cout << "enter any character to quit";
	char done;
	cin >> done;

	return 0;
}

//Helper functions

Table * initializeTableFromStream(istream & in, CardFactory * cardFactory)
{
	return new Table(in, cardFactory);
}

void persistTable(ostream & out, const Table * table)
{
	table->print(out);
}

bool isStreamNotOpenOrEmpty(ifstream & in)
{
	return !in || ((in.peek()) == ifstream::traits_type::eof());
}

string getPlayerName(int playerNumber)
{
	string name;
	cout << "Please enter player " << playerNumber << "'s name:" << endl;
	cin >> name;
	return name;
}




