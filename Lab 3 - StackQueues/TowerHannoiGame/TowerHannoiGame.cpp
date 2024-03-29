// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

// TODO you will need to uncomment the line below
#include <StackQueues.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame();
	~TowersOfHannoiGame();

	virtual bool IsGameEnded();

	virtual void PrintTowers();
	virtual bool canMove(int diskId, int fromId, int toId);
	virtual bool makeMove(int diskId, int fromId, int toId);
	void writeOutput();
	
private:
	bool m_GameEnded;

	static const int POLE_COUNT = 3;
	static const int DISK_COUNT = 4;

	ArrayBasedStack* m_poles[POLE_COUNT];
	
	int m_disk_pos[DISK_COUNT];
	ArrayBasedQueue* m_moves;
};

TowersOfHannoiGame::TowersOfHannoiGame() 
{
	// Initialize variables
	m_GameEnded = false;

	m_moves = new ArrayBasedQueue();

	// Set each pole to a stack
	for (int i = 0; i < POLE_COUNT; i++) {
		m_poles[i] = new ArrayBasedStack();
	}

	// Push all the disks to the first pole's stack
	for (int i = DISK_COUNT; i > 0; i--) {
		m_poles[0]->push(i);

		m_disk_pos[0] = 0;
	}
}

TowersOfHannoiGame::~TowersOfHannoiGame() 
{
	// Delete the moves queue and all the pole stacks

	delete m_moves;
	for (int i = 0; i < POLE_COUNT; i++) {
		delete m_poles[i];
	}
}

bool TowersOfHannoiGame::IsGameEnded()
{
	return m_GameEnded;
}

bool TowersOfHannoiGame::canMove(int diskId, int fromId, int toId) 
{
	// Check to make sure the initial pole is valid
	if (fromId > POLE_COUNT || fromId < 1) {
		cout << endl << "Please enter a valid from pole!" << endl;

		return false;
	}

	// Check to make sure the final pole is valid
	if (toId > POLE_COUNT || toId < 1) {
		cout << endl << "Please enter a valid to pole!" << endl;

		return false;
	}

	// If the initial pole has no disks on it, it's an invalid move 
	if (m_poles[fromId - 1]->isEmpty()) {
		cout << endl << "This pole has no disks on it!" << endl;

		return false;
	}

	// If the first disk on the pole isn't our target one, then it's either not on the pole or it's under another disk
	if (m_poles[fromId - 1]->peek() != diskId) {
		cout << endl << "This disk isn't on this pole or it is under another" << endl;

		return false;
	}

	// Make sure the disk isn't being placed on a smaller one
	if (!m_poles[toId - 1]->isEmpty() && m_poles[toId - 1]->peek() < diskId) {
		cout << "This disk cannot be placed on a smaller disk!" << endl;

		return false;
	}

	return true;
}


bool TowersOfHannoiGame::makeMove(int diskId, int fromId, int toId) 
{
	if (!this->canMove(diskId, fromId, toId)) {
		return false;
	}

	// Remove the disk from the initial pole, and push it to the new one.
	m_poles[fromId - 1]->pop();
	m_poles[toId - 1]->push(diskId);

	// Record the disk's new position. This is used in printing the towers.
	m_disk_pos[diskId - 1] = toId - 1;

	// Log the move and output a successful action to the console
	m_moves->enQueue(std::to_string(diskId) + ',' + std::to_string(fromId) + ',' + std::to_string(toId));

	cout << endl << "Disk " << diskId << " From " << fromId << " To " << toId;

	this->PrintTowers();

	// Loop through all the stacks (poles, but not the first); if the number of elements equals the disk count then we win.
	//     Based on the move conditions we don't have to check to make sure the disk are in the right order, etc.
	for (int pole = 1; pole < POLE_COUNT; pole++) {
		if (m_poles[pole]->length() == DISK_COUNT) {
			m_GameEnded = true;

			cout << "Congratulations! You won in " << std::to_string(m_moves->length()) + " moves!" << endl;
		}
	}
}


// TODO: Make pretty
void TowersOfHannoiGame::PrintTowers()
{
	cout << endl;

	for (int i = 0; i < POLE_COUNT; i++) 
	{
		cout << "Pole " << (i + 1) << "| " << m_poles[i]->toString() << endl;
	}

	cout << endl;
}

void TowersOfHannoiGame::writeOutput() 
{
	// Remove a previous output file (assume it exists)
	std::remove("moves_output.txt");

	// Create a new file 
	std::ofstream out_file;
	out_file.open("moves_output.txt");

	//Remove all queued strings from the queue to the output file
	while (!m_moves->isEmpty())
	{
		out_file <<  m_moves->peekFront() << endl;

		m_moves->deQueue();
	}

	// Close it!
	out_file.close();

	cout << "Moves saved in moves_output.txt!" << endl;
}

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	game.PrintTowers();

	bool receivedEndToken = false;

	while (!receivedEndToken && !game.IsGameEnded())
	{
		std::string inputLine;

		cout << "Enter Move <disk>,<from pole>,<to pole>: " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str());
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				game.makeMove(diskId, fromId, toId);
			}
		}
	}

	game.writeOutput();

    return 0;
}

