
using namespace std;

struct Input_container
{
	string output_command;
	string output_argument;
};
Input_container input_container;

class Commands
{
private:
	vector<string> commands = { "help", "inventory", "items", "look", "move", "enter", "use", "take" };

	bool in_array(const std::string& value, const std::vector<string>& array)
	{
		return std::find(array.begin(), array.end(), value) != array.end();
	}

public:
	void input(string command, string option)
	{
		if (command != "")
		{
			if (in_array(command, commands))
			{
				cout << command;
				if (command == "help")
				{
					cout << help.ascii_data << "\n" << help.story_data << "\n\n";
					cout << "These are the commands you can use type help again to exit this menu.";
					for (int i = 0; i < size(commands); i++)
					{
						cout << ", ";
						cout << commands[i];
					}
					cout << ".";
					cout << "\n";
					bool help_bool = true;
					while (help_bool)
					{
						string command_help;
						cin >> command_help;
						if (command_help == "inventory")
						{
							cout << "Lists all the items you have in your inventory.\n";
						}
						else if (command_help == "items")
						{
							cout << "Lists all the items you have in your inventory.\n";
						}
						else if (command_help == "look")
						{
							cout << "Tells you about the room or if followed by an object tels you about the object.\n";
						}
						else if (command_help == "move")
						{
							cout << "Lets you move movable objects, used by typing move and then the object you want to move.\n";
						}
						else if (command_help == "enter")
						{
							cout << "Allows you to enter a door or room.\n";
						}
						else if (command_help == "use")
						{
							cout << "Lets you use a useable item.\n";
						}
						else if (command_help == "take")
						{
							cout << "Lets you take a item\n";
						}
						else if (command_help == "help")
						{
							cout << "I hope that helped.\n";
							help_bool = false;
						}
						else
						{
							cout << "Thats not a command I can help you with.\n";
						}
					}
					command = "";
				}

				if (command.find("inventory") != string::npos)
				{
					command = "";
				}

				if (command.find("items") != string::npos)
				{
					command = "";
				}

				if (command.find("look") != string::npos)
				{
					bool found_object = false;
					for (int i = 0; current_room.objects.size() > i; i++)
					{
						if (option != "") {
							if (current_room.objects[i].name == option)
							{
								draw_object(current_room.objects[i]);
								found_object = true;
							}
						}
					}
					if (found_object == false)
					{
						draw_room(current_room);
					}
					found_object = false;

				}

				if (command.find("move") != string::npos)
				{
					command = "";
				}

				if (command.find("enter") != string::npos)
				{
					command = "";
				}
			}
			else
			{
				cout << "I dont understand that command, try help.";
				cout << "\n";
				command = "";
			}
		}
	}
};

