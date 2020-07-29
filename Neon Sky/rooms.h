using namespace std;

struct Rooms
{
	string ascii_data;
	string story_data;
    vector<Object> objects;
};
Rooms welcome;
Rooms help;
Rooms start_room;

//vector<Rooms> rooms = {welcome, help,};

void insert_room_data()
{
	welcome.ascii_data = R"(
 ________   _______   ________  ________           ________  ___  __        ___    ___ 
|\   ___  \|\  ___ \ |\   __  \|\   ___  \        |\   ____\|\  \|\  \     |\  \  /  /|
\ \  \\ \  \ \   __/|\ \  \|\  \ \  \\ \  \       \ \  \___|\ \  \/  /|_   \ \  \/  / /
 \ \  \\ \  \ \  \_|/_\ \  \\\  \ \  \\ \  \       \ \_____  \ \   ___  \   \ \    / / 
  \ \  \\ \  \ \  \_|\ \ \  \\\  \ \  \\ \  \       \|____|\  \ \  \\ \  \   \/  /  /  
   \ \__\\ \__\ \_______\ \_______\ \__\\ \__\        ____\_\  \ \__\\ \__\__/  / /    
    \|__| \|__|\|_______|\|_______|\|__| \|__|       |\_________\|__| \|__|\___/ /     
                                                     \|_________|         \|___|/      )";

	welcome.story_data = "Welcome to Neon Sky type start to begin or resume or continue to resume a saved game.";

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	help.ascii_data = R"(
 ___  __   _______   ___       ________   
|\  \|\  \|\  ___ \ |\  \     |\   __  \  
\ \  \\\  \ \   __/|\ \  \    \ \  \|\  \ 
 \ \   __  \ \  \_|/_\ \  \    \ \   ____\
  \ \  \ \  \ \  \_|\ \ \  \____\ \  \___|
   \ \__\ \__\ \_______\ \_______\ \__\   
    \|__|\|__|\|_______|\|_______|\|__|   
                                          )";

	help.story_data = "Enter a help followed by a command to learn more about it.";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    start_room.ascii_data = R"(
             ,----------------,              ,---------,
        ,-----------------------,          ,"        ,"|
      ,"                      ,"|        ,"        ,"  |
     +-----------------------+  |      ,"        ,"    |
     |  .-----------------.  |  |     +---------+      |
     |  |                 |  |  |     | -==----'|      |
     |  |  Error!         |  |  |     |         |      |
     |  |  Corrupted      |  |  |/----|`---=    |      |
     |  |  C:\>_          |  |  |   ,/|==== ooo |      ;
     |  |                 |  |  |  // |(((( [33]|    ,"
     |  `-----------------'  |," .;'| |((((     |  ,"
     +-----------------------+  ;;  | |         |,"
        /_)______________(_/  //'   | +---------+
   ___________________________/___  `,
  /  oooooooooooooooo  .o.  oooo /,   \,"-----------
 / ==ooooooooooooooo==.o.  ooo= //   ,`\--{)B     ,"
/_==__==========__==_ooo__ooo=_/'   /___________,"
`-----------------------------')";

    start_room.story_data = "A computer sits in a small room your not sure how you got here.\n There is a small table with some disks and some blue pills scattered around.\n A single metal door is the only way out.";
    Object computer;
    Object pills;
    Object disks;
    Object metal_door;
    computer.name = "disks";
    computer.story_data = "Error! Corrupted, glows on the screen the computer doesnt respond to your input.";
    pills.name = "pills";
    pills.ascii_data = R"(

                         ______________
                        [______________]
                         {============}
                       .-'  ,.--.     '-.
                      / --. /8888\ ,.--. \
                     / 8888\\8888///8888\ \
                     |--------------------|
                     |                    |
                     |      |\ | \  /     |
                     |      | \|  \/      |
                     |  ___  _    _   _   |
                     |   |  /_\  |_) (_   |
                     |   | /   \ |_) \_)  |
    ,.--.   ,.--.    |____________________|
   //8888\ //8888\   |  \\8888/ \\8888/   |
   \\8888/ \\8888/   |   `'--'   `'--'    |
    `'--'   `'--'    '--------------------')";
    pills.story_data = "The pills are a light blue color with small text reading di-methal-cindoxl.";
    start_room.objects.push_back(computer);
    start_room.objects.push_back(pills);
    start_room.objects.push_back(disks);
}