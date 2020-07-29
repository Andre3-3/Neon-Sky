using namespace std;
struct Rooms;
struct Object
{
	string name;
	string ascii_data;
	string story_data;
	bool is_door = false;
	bool is_takeable = false;
	bool is_useable = false;
	shared_ptr<Rooms> door_destination;
};

