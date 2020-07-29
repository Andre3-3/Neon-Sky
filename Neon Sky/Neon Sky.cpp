#include <iostream>
#include <string>
#include <algorithm>
#include <array>  
#include <vector>
#include <sstream>
#include "objects.h"
#include "rooms.h"
#include "renderer.h"
Rooms current_room;
#include "commands.h"



int test;
string command = "";
string option = "";
bool start = false;


using namespace std;

Commands commands;

void start_menu()
{
	insert_room_data();
	cout << welcome.ascii_data << "\n\n";
	cout << welcome.story_data << "\n";
	while (!start)
	{
		cin >> command;
		if (command == "start")
		{
			start = true;
			
			draw_room(start_room);
			current_room = start_room;
		}
		else if (command == "resume" or command == "continue")
		{
			cout << "looks like i havent programed that yet\n";
		}
		else
		{
			cout << "I didn't understand that. Type start to start a new game or resume to continue where you left off.\n";
		}
	}
}

string get_arguments(string input)
{
	cout << input;
	if (input != "")
	{
		vector<string> result;
		istringstream iss(input);
		for (std::string s; iss >> s;)
		{
			result.push_back(s);
		}
		if (result.size() == 1)
		{
			input_container.output_command = result[0];
		}
		else if (result.size() > 1)
		{
			input_container.output_argument = result[1];
		}
		cout << result.size();
	}
	return "";
}

int main()
{
	string input_text;
	start_menu();
	input_container.output_command = "";
	input_container.output_argument = "";
	while (true)
	{
		
		getline(cin, input_text);
		cout << input_text;
		get_arguments(input_text);
		commands.input(input_container.output_command , input_container.output_argument);
	}

	return 0;
}

