#include <iostream>
#include "rooms.h"
#include "objects.h"
using namespace std;

void draw_room(Rooms load_room)
{
	system("cls");
	cout << load_room.ascii_data << "\n";
	cout << load_room.story_data << "\n";
}
void draw_object(Object load_object)
{
	system("cls");
	cout << load_object.ascii_data << "\n";
	cout << load_object.story_data << "\n";
}
