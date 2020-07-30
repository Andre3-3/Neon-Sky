using namespace std;

bool in_array(const std::string& value, const std::vector<string>& array)
{
	return std::find(array.begin(), array.end(), value) != array.end();
}

void input(string command, string option, string option2)
{
	if (command != "")
	{
		if (in_array(command, commands))
		{
			if (command == "help")
			{
				cout << help.ascii_data << "\n" << help.story_data << "\n\n";
				cout << "These are the commands you can use";
				for (int i = 0; i < size(commands); i++)
				{
					cout << ", ";
					cout << commands[i];
				}
				cout << ".";
				cout << "\n";
				if (in_array(option, commands))
				{
					if (option == "inventory")
					{
						cout << "Lists all the items you have in your inventory.\n";
					}
					else if (option == "look")
					{
						cout << "Tells you about the room or if followed by an object tells you about the object.\n";
					}
					else if (option == "move")
					{
						cout << "Lets you move movable objects, used by typing move and then the object you want to move.\n";
					}
					else if (option == "enter")
					{
						cout << "Allows you to enter a door or room.\n";
					}
					else if (option == "use")
					{
						cout << "Lets you use a useable item.\n";
					}
					else if (option == "take")
					{
						cout << "Lets you take a item\n";
					}
					else if (option == "help")
					{
						cout << "Gives you this information if help is followed by a command gives you information about that command.\n";
					}
				}
				else if (option != "")
				{
					cout << "Thats not a command I can help you with.\n";
				}
			}
			else if (command.find("inventory") != string::npos)
			{
				if (size(player.inventory) > 0)
				{
					cout << "Your inventory contains";
					for (int i = 0; i < size(player.inventory); i++)
					{
						cout << ", ";
						cout << player.inventory[i].name;
					}
					cout << ".";
					cout << "\n";
				}
				else
				{
					cout << "You don't have anything in your inventory.\n";
				}
			}

			else if (command.find("look") != string::npos)
			{
				bool found_object = false;
				if (option != "")
				{

					for (int i = 0; current_room.objects.size() > i; i++)
					{
						if (current_room.objects[i].name == option)
						{
							draw_object(current_room.objects[i]);
							found_object = true;
						}
					}
					if (!found_object)
					{
						cout << "Looks like that isn't in the room.\n";
					}
				}
				else if (option == "")
				{
					draw_room(current_room);
				}
			}


			else if (command.find("move") != string::npos)
			{
				command = "";
			}

			else if (command.find("enter") != string::npos)
			{
				command = "";
			}

			else if (command.find("take") != string::npos)
			{
				bool found_object = false;
				if (option != "")
				{

					for (int i = 0; current_room.objects.size() > i; i++)
					{
						if (current_room.objects[i].name == option)
						{
							found_object = true;
							if (current_room.objects[i].is_takeable == true)
							{
								cout << "You took the " << current_room.objects[i].name << ".\n";
								player.inventory.push_back(current_room.objects[i]);
								current_room.objects.erase(current_room.objects.begin() + i);

							}
							else
							{
								cout << "You can't take the " << current_room.objects[i].name << ".\n";
							}

						}
					}
					if (!found_object)
					{
						cout << "Looks like that isn't in the room.\n";
					}
				}
				else if (option == "")
				{
					cout << "Enter take followed by an object you want to take.\n";
				}
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

