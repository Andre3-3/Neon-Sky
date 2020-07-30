#include <iostream>
#include <string>
#include <algorithm>
#include <array>  
#include <vector>
#include <sstream>
#include "objects.h"
#include "rooms.h"
#include "renderer.h"
#include "player.h"
#include "commands.h"



int test;
string command = "";
string option = "";
bool start = false;

using namespace std;

void start_menu()
{
	insert_room_data();
	insert_object_data();
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
	input_container.output_command = "";
	input_container.output_argument = "";
	input_container.output_argument2 = "";
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
		else if (result.size() == 2)
		{
			input_container.output_command = result[0];
			input_container.output_argument = result[1];
		}
		else if (result.size() == 3)
		{
			input_container.output_command = result[0];
			input_container.output_argument = result[1];
			input_container.output_argument2 = result[2];
		}
	}
	return "";
}

int main()
{
	string input_text;
	start_menu();
	input_container.output_command = "";
	input_container.output_argument = "";
	input_container.output_argument2 = "";
	while (true)
	{
		
		getline(cin, input_text);
		get_arguments(input_text);
		input(input_container.output_command , input_container.output_argument, input_container.output_argument2);
	}

	return 0;
}

