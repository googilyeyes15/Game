#include <iostream>
#include <stdlib.h>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

int rpsls(int);

void forge(int&,int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
void inventory(int&,int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
void attack(int&damN, int&Phealth, int&damP, int&heal, int&coins, int&Phealth1, int floor, string name);
void boss(int&damN, int&Phealth, int&damP, int&heal, int&coins, int&Phealth1, int floor, string name);

int main()

{
    // strings//
    string incorrect = R"( 
  ___                                            _   
 |_ _| _ __    ___  ___   _ __  _ __  ___   ___ | |_ 
  | | | '_ \  / __|/ _ \ | '__|| '__|/ _ \ / __|| __|
  | | | | | || (__| (_) || |   | |  |  __/| (__ | |_ 
 |___||_| |_| \___|\___/ |_|   |_|   \___| \___| \__|
                                                     
            ___                       _              
           |_ _| _ __   _ __   _   _ | |_            
            | | | '_ \ | '_ \ | | | || __|           
            | | | | | || |_) || |_| || |_            
           |___||_| |_|| .__/  \__,_| \__|           
                       |_|                           
  )";
    string classes =  R"( 
_________________________________________________
|    Warrior    |     Ranger    |    Assassin   |
|     ____      |               |               |
|     |  |      |    |\         |       __      |
|      ||       |    |\\        |       ||      |
|   ___||___    |    | \\       |      _||_     |
|  |________|   |    |  \\      |      |  |     |   
|     |  |      |    |   \\     |      |  |     |
|     |  |      |    |    ()    |      |  |     |
|     |  |      |    |   //     |      \  /     |
|     |  |      |    |  //      |       \/      |
|     |  |      |    | //       |               |
|     \  /      |    |//        |               |
|      \/       |    |/         |               |
|_______________|_______________|_______________|
|Stats :        |Stats :        |Stats :        |
|Health:120     |Health:100     |Health:70      |
|Speed :70      |Speed :100     |Speed :120     |
|Damage:33      |Damage:25      |Damage:37      |
|_______________|_______________|_______________|
  )";
    string welcome =R"(
 __        __         _                                     
 \ \      / /   ___  | |   ___    ___    _ __ ___     ___   
  \ \ /\ / /   / _ \ | |  / __|  / _ \  | '_ ` _ \   / _ \  
   \ V  V /   |  __/ | | | (__  | (_) | | | | | | | |  __/  
    \_/\_/     \___| |_|  \___|  \___/  |_| |_| |_|  \___|  
                                                            
            _               _     _                         
           | |_    ___     | |_  | |__     ___              
           | __|  / _ \    | __| | '_ \   / _ \             
           | |_  | (_) |   | |_  | | | | |  __/             
            \__|  \___/     \__| |_| |_|  \___|             
                                                            
                    _                                       
              ___  | |__     ___   __      __               
             / __| | '_ \   / _ \  \ \ /\ / /               
             \__ \ | | | | | (_) |  \ V  V /                
             |___/ |_| |_|  \___/    \_/\_/ 
             )";
    string closed_door = R"( 
 ______________
|\ ___________ /|
| |  _ _ _ _  | |
| | | | | | | | |
| | |-+-+-+-| | |
| | |-+-+-+-| | |
| | |_|_|_|_| | |
| |     ___   | |
| |    /__/   | |
| |   [%==] ()| |
| |         ||| |
| |         ()| |
| |           | |
| |           | |
| |           | |
|_|___________|_|
  )";
    string open_door = R"( 
 ______________
|\ ___________ /|
| |  /|,| |   | |
| | |,x,| |   | |
| | |,x,' |   | |
| | |,x   ,   | |
| | |/    |   | |
| |    /] ,   | |
| |   [/ ()   | |
| |       |   | |
| |       |   | |
| |       |   | |
| |      ,'   | |
| |   ,'      | |
|_|,'_________|_|
  )";
    string pchest = R"(
                            |                   |
                            |                   |
       !                    |                   |
      .-.                   |                   |
    __|=|__                 |     __________    |
   (_/`-`\_)                |    /\____;;___\   |
   //\___/\\                |   | /         /   |
   <>/   \<>                |   `.----------\   |
    \|_._|/                 |    |\          \  |
     <_I_>                  |    | |---------|  |
      |||                   |    \ |    ))   |  |
     /_|_\                  |     \|_________|  |
     )";
    string pforge =  R"(
                            |                      |
                            |                      |
       !                    |                      |
      .-.                   |     .-------..___    |
    __|=|__                 |     '-._     :_.-'   |
   (_/`-`\_)                |      .- ) _ ( --.    |
   //\___/\\                |     :  (_____)  ;.   |
   <>/   \<>                |    /'-.._____.-' |   |
    \|_._|/                 |    |   |     \   |   |
     <_I_>                  |    \   |     /   \   |
      |||                   |    |   \     )_.-'   |
     /_|_\                  |    '-._/__..-'       |
     )";
    string monster1 =  R"(
                                |      ,--.   ,---.    |
                                |     /    \-|     \   |
       !                        |         (o o)      (/|
      .-.                       |         /'v'     ,-' |
    __|=|__                     | ,------/ >< \---'    |
   (_/`-`\_)                    |/)     ;  --  :       |
   //\___/\\                    |   ,---| ---- |--.    |
   <>/   \<>                    | (|  ,-| ---- |-. |)  |
    \|_._|/                     |     \  \ -- /  /     |
     <_I_>                      |     ;   \  /  :      |
      |||                       |    /   / \/ \  \     |
     /_|_\                      |   /)           (\    |
     )";
    string monster2 =  R"(
                                |                   |
                                |                   |
       !                        |                   |
      .-.                       |                   |
    __|=|__                     |                   |
   (_/`-`\_)                    |,     .            |
   //\___/\\                    |(\,;,/)            |
   <>/   \<>                    | (o o)\//,         |
    \|_._|/                     |  \ /     \,       |
     <_I_>                      |  `+'(  (   \    ) |
      |||                       |     //  \   |_./  |
     /_|_\                      |    '~' '~----'    |
     )";
    string monster3 =  R"(
                                |                         |
                                |                         |
       !                        | _________         .    .|
      .-.                       |(..       \_    ,  |\  /||
    __|=|__                     | \       O  \  /|  \ \/ /|
   (_/`-`\_)                    |  \______    \/ |   \  / |
   //\___/\\                    |     vvvv\    \ |   /  | |
   <>/   \<>                    |     \^^^^  ==   \_/   | |
    \|_._|/                     |      `\_   ===    \.  | |
     <_I_>                      |      / /\_   \ /      | |
      |||                       |      |/   \_  \|      / |
     /_|_\                      |             \________/  |
     )";
string Fail =  R"(
     _        _                     _                     
    / \    __| |__   __ ___  _ __  | |_  _   _  _ __  ___ 
   / _ \  / _` |\ \ / // _ \| '_ \ | __|| | | || '__|/ _ \
  / ___ \| (_| | \ V /|  __/| | | || |_ | |_| || |  |  __/
 /_/   \_\\__,_|  \_/  \___||_| |_| \__| \__,_||_|   \___|
             _____       _  _            _                
            |  ___|__ _ (_)| |  ___   __| |               
            | |_  / _` || || | / _ \ / _` |               
            |  _|| (_| || || ||  __/| (_| |               
            |_|   \__,_||_||_| \___| \__,_|  
)";
int game;
do{
    char rps;
	char a;
	system("clear");
	std::cout << "\033[1;34m" <<welcome; //I changed to color!
	cout << endl << endl;
	cout << "\033[0m";
	cout << "Enter anything to start game" << endl;
//rpsls*************************************************************************
	cout << "Press m to play the rock paper scissor lizard spock" << endl;
	cin >> rps;
	if (rps == 'm')
	{
	    int x;
	    int exit;
	    int instu;
	    system("clear"); 
	    cout << "What beats what?"<< endl;
	    cout << "ROCK > Scissors & Lizard" << endl;
	    cout << "PAPER > Rock & Spock" << endl;
	    cout << "SCISSORS > Paper & Lizard" << endl;
	    cout << "LIZARD > Paper & Spock" << endl;
	    cout << "SPOCK > Rock & Scissors" << endl;
	    cout << endl << endl;
	    cout << "What would you like to chose?"<< endl;
	    cout << "Rock is 1"<< endl;
	    cout << "Paper is 2"<< endl;
	    cout << "Scissor is 3"<< endl;
	    cout << "Lizard is 4"<< endl;
	    cout << "Spock is 5"<< endl;
	    cin >> x;
	    while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5)
	    {
	        system("clear");
	        std::cout << incorrect;
	        std::chrono::seconds dura(3);
	        std::this_thread::sleep_for( dura );
	        system("clear");
	        cin.clear();
	        cin.ignore(1, '\n');
	        system("clear");
	        cout << "What beats what?"<< endl;
	        cout << "ROCK > Scissors & Lizard" << endl;
	        cout << "PAPER > Rock & Spock" << endl;
	        cout << "SCISSORS > Paper & Lizard" << endl;
	        cout << "LIZARD > Paper & Spock" << endl;
	        cout << "SPOCK > Rock & Scissors" << endl << endl; 
	        cout << "What would you like to chose?"<< endl;
	        cout << "Rock is 1"<< endl;
	        cout << "Paper is 2"<< endl;
	        cout << "Scissor is 3"<< endl;
	        cout << "Lizard is 4"<< endl;
	        cout << "Spock is 5"<< endl;
	        cin >> x;
	    }
//rock outptus******************************************************************
	    if (rpsls(x) ==1)
	    {
	        cout << "You win Computer chose Scissors" <<endl;
	        cout<< "Enter anything to continue"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==2)
	    {
	        cout << "You win Computer chose Lizard" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==3)
	    {
	        cout << "It was a tie Computer chose Rock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==4)
	    {
	        cout << "You lose Computer chose Paper" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear"); 
	    }
	    if (rpsls(x) ==5)
	    {
	        cout << "You lose Computer chose Spock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
//paper outputs*****************************************************************
	    if (rpsls(x) ==6)
	    {
	       cout << "You win Computer chose Rock" <<endl;
	       cout<< "Enter anything to continue to main game"<<endl;
	       cin>> exit;
	       system("clear");
	        
	    }
	    if (rpsls(x) ==7)
	    {
	        cout << "You win Computer chose Spock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==8)
	    {
	        cout << "It was a tie Computer chose Paper" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==9)
	    {
	        cout << "You lose Computer chose Scissors" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==10)
	    {
	        cout << "You lose Computer chose Lizard" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
//Scissors outputs**************************************************************
	    if (rpsls(x) ==11)
	    {
	        cout << "You win Computer chose Paper" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==12)
	    {
	        cout << "You win Computer chose Lizard" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==13)
	    {
	        cout << "It was a tie Computer chose Scissors" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==14)
	    {
	        cout << "You lose Computer chose Rock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==15)
	    {
	        cout << "You lose Computer chose Spock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
//Lizard outputs****************************************************************
	    if (rpsls(x) ==16)
	    {
	        cout << "You win Computer chose Paper" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==17)
	    {
	        cout << "You win Computer chose Spock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==18)
	    {
	        cout << "It was a tie Computer chose Lizard" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==19)
	    {
	        cout << "You lose Computer chose Rock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==20)
	    {
	        cout << "You lose Computer chose Scissors" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
//spock outputs*****************************************************************
	    if (rpsls(x) ==21)
	    {
	        cout << "You win Computer chose Rock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==22)
	    {
	        cout << "You win Computer chose Scissors" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	     if (rpsls(x) ==23)
	    {
	        cout << "It was a tie Computer chose Spock" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==24)
	    {
	        cout << "You lose Computer chose Paper" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	    if (rpsls(x) ==25)
	    {
	        cout << "You lose Computer chose Lizard" <<endl;
	        cout<< "Enter anything to continue to main game"<<endl;
	        cin>> exit;
	        system("clear");
	    }
	}
	cin.clear();
    cin.ignore(1, '\n');
	system("clear"); 
	string name; 
	cout << "Enter your first name: "; 
	cin >> name; 
	system("clear");
	
	cout << "Hello " << name << endl;
	char b;
	int armor;
	int weapon;
	int Phealth;
	int Phealth1;
	int speed;
	int damN;
	int heal;
	int damP;
	cout << "Choose your class" << endl; 
	cout << "Enter 'w'Warrior, 'r'Ranger, or 'a'Assassin to continue" << endl;
	std::cout << classes<< endl;
	cin >> b;
	while (b != 'w' && b != 'r' && b !='a')
	{
	    system("clear");
	    std::cout << incorrect;
	    std::chrono::seconds dura( 3);
	    std::this_thread::sleep_for( dura );
	    system("clear");
	    cout << "Choose your class" << endl; 
	    cout << "Enter 'w'Warrior, 'r'Ranger, or 'a'Assassin to continue" << endl;
	    std::cout << classes<< endl;
	    cin >> b;
	}
  	system("clear");
  	switch(b) 
  	{
  	    case 'w' :
  	    weapon=1;
  	    armor=1;
        cout << name <<" the Warrior" << endl;
        std::cout << R"( 
_________________
|    Warrior    |
|     ____      |
|     |  |      |
|      ||       |
|   ___||___    |
|  |________|   |
|     |  |      |
|     |  |      |
|     |  |      |
|     |  |      |
|     |  |      |
|     \  /      |
|      \/       |
|_______________|
|Health:120     |
|Speed :70      |
|Damage:33      |
|_______________|
)" << endl;
        break;
        case 'r' :
        weapon=6;
        armor=6;
        cout << name <<" the Ranger" << endl;
        std::cout << R"( 
_________________
|     Ranger    |
|               |
|    |\         |
|    |\\        |
|    | \\       |
|    |  \\      |  
|    |   \\     |
|    |    ()    |
|    |   //     |
|    |  //      |
|    | //       |
|    |//        |
|    |/         |
|_______________|
|Health:100     |
|Speed :100     |
|Damage:25      |
|_______________|
)" << endl;
        break;
        case 'a' :
        weapon=11;
        armor=11;
        cout << name <<" the Assassin" << endl;
        std::cout << R"( 
_________________
|    Assassin   |
|               |
|       __      |
|       ||      |
|      _||_     |
|      |  |     |   
|      |  |     |
|      |  |     |
|      \  /     |
|       \/      |
|               |
|               |
|               |
|_______________|
|Health:70      |
|Speed :120     |
|Damage:37      |
|_______________|
)" << endl;
        break;
        default :
        std::cout << incorrect<< endl;
  	}
  	char c;
  	int potion1;
  	int potion2;
  	int price1;
  	int price2;
  	int price3;
  	int price4;
  	int coins=0;
  	cout << "Enter anything to continue" << endl;
  	cin >> c;
  	potion1=1;
  	potion2=1;
  	if(c==c)
  	{
      system("clear");
  	}
  	cout << "Your current Inventory is" << endl;
  	char T;
  	inventory(weapon, armor, potion1, potion2, price1, price2, price3, price4, coins, damN, Phealth, Phealth1, heal, damP);
  	cout << endl <<endl;
  	cout << "would you like a tutorial Yes 'Y' or No 'N'" <<endl;
  	cin >> T;
  	if (T=='Y'||T=='y')
  	{
  	    cout << "This is your inventory^ it will change based on what you upgrade later on!" << endl;
  	    cout << "All of your stats will be based on this menu" << endl;
  	    cout << "Your damage is based on the rarity of your weapon(Sword, Bow, Dagger)and will increase as you upgred it" << endl;
  	    cout << "Heavy attacks have a chance to miss!" << endl;
  	    cout << "Your Health is based on the rarity of your armor and will be diffrent for each class but will increase as you upgrade" << endl;
  	    cout << "Since you only have a common health potion it will restore %10 of you max health and you can use it 2 time per battle"<< endl;
  	    cout << "With your damage potion being common you will do 25 damage to the monster but you may only use it once per battle" << endl;
  	    cout << "I dont recomend useing the potions more than your suposed to" << endl;
  	    cout << "Enter anything to contiue."<< endl;
  	    cin >> c;
  	}
  	else
  	{
  	
  	}
  	int z;
  	z=1;
  	while (z<2)
  	{
  	    system("clear");
  	    z=z+1;
  	    std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|      \_,!,_/                            |
|   `.,'     `.,'                         |
|    /         \                          |
| -- :         : --                       |
|    \         /                          |
|   ,'`._   _.'`.                         |
|      / `!` \                            |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
)";
        std::chrono::milliseconds dura( 500);
        std::this_thread::sleep_for( dura );
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|         \_,!,_/                         |
|      `.,'     `.,'                      |
|       /         \                       |
|    -- :         : --                    |
|       \         /                       |
|      ,'`._   _.'`.                      |
|         / `!` \                         |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
 )";
        std::this_thread::sleep_for( dura ); 
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|           \_,!,_/                       |
|        `.,'     `.,'                    |
|         /         \                     |
|      -- :         : --                  |
|         \         /                     |
|        ,'`._   _.'`.                    |
|           / `!` \                       |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
 )";
        std::this_thread::sleep_for( dura );
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|              \_,!,_/                    |
|           `.,'     `.,'                 |
|            /         \                  |
|         -- :         : --               |
|            \         /                  |
|           ,'`._   _.'`.                 |
|              / `!` \                    |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
 )";
        std::this_thread::sleep_for( dura ); 
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|           \_,!,_/                       |
|        `.,'     `.,'                    |
|         /         \                     |
|      -- :         : --                  |
|         \         /                     |
|        ,'`._   _.'`.                    |
|           / `!` \                       |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
 )";
        std::this_thread::sleep_for( dura ); 
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|         \_,!,_/                         |
|      `.,'     `.,'                      |
|       /         \                       |
|    -- :         : --                    |
|       \         /                       |
|      ,'`._   _.'`.                      |
|         / `!` \                         |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
 )";
        std::this_thread::sleep_for( dura ); 
        system("clear");
        std::cout << R"(
  _______________________________________
 /                                       \
/                                         \
|      \_,!,_/                            |
|   `.,'     `.,'                         |
|    /         \                          |
| -- :         : --                       |
|    \         /                          |
|   ,'`._   _.'`.                         |
|      / `!` \                            |
|   _   _   _                 _   _   _   |
|  | |_| |_| |   _   _   _   | |_| |_| |  |
|   \   _   /   | |_| |_| |   \   _   /   |
|    | | | |     \       /     | | | |    |
|    | |_| |______|     |______| |_| |    |
|    |              ___              |    |
|    |  _    _    (     )    _    _  |    |
|    | | |  |_|  (       )  |_|  | | |    |
|    | |_|       |       |       |_| |    |
|   /            |_______|            \   |
|  |___________________________________|  |
\      TAMUCC Center For Instruction      /
 \_______________________________________/
         )";
  	}
  	char d;
  	cout << endl << "Enter anything to start your adventure" << endl;
  	cin >> d;
  	system("clear");
  	int floor = 0,randRoom;
  	char temp;
  	while (floor <3)
    {
        for (int room = 1; room <= 5; room++)
        {
            if (Phealth<1)
            {
                cout << Fail;
                return 0;
            }
            randRoom = 1 + rand() % 7;  // 1/7 chance of chest room
            cout << closed_door;
            std::chrono::milliseconds milsec500( 500);
            std::this_thread::sleep_for( milsec500 );
            system("clear");
            cout << open_door;
            std::this_thread::sleep_for( milsec500 );
            if (randRoom == 7)
            {
                std::chrono::seconds hold( 2);
                system("clear");
                cout << pchest;
                int coin =  (rand() % 21) + 40;
                cout << "the chest had \033[0;33m" << coin << "\033[0m coins\n You now have \033[0;33m" << coins + coin << " \033[0mcoins " << endl;
                coins = coins + coin;
                std::this_thread::sleep_for( hold );
                system("clear");
            }
            else
            {
                std::chrono::seconds hold( 2);
                system("clear");
                attack(damN, Phealth, damP, heal, coins, Phealth1, floor, name);
                std::this_thread::sleep_for( hold );
                system("clear");
            }
        }
        system("clear");
        forge(weapon, armor, potion1, potion2, price1, price2, price3, price4, coins, damN, Phealth, Phealth1, heal, damP);
        system("clear");
        boss(damN, Phealth, damP, heal, coins, Phealth1, floor, name);
        floor=floor+1;
    }
    system("clear");
    std::cout << R"(
        __   __                  _   _                     
        \ \ / /___   _   _      | | | |  __ _ __   __ ___  
         \ V // _ \ | | | |     | |_| | / _` |\ \ / // _ \ 
          | || (_) || |_| |     |  _  || (_| | \ V /|  __/ 
          |_| \___/  \__,_|     |_| |_| \__,_|  \_/  \___| 
               ____   _                          _         
              / ___| | |  __ _  _   _   ___   __| |        
              \___ \ | | / _` || | | | / _ \ / _` |        
               ___) || || (_| || |_| ||  __/| (_| |        
              |____/ |_| \__,_| \__, | \___| \__,_|        
            _____  _            |___/ ____     ___         
           |_   _|| |__    ___       / ___|   |_ _|        
             | |  | '_ \  / _ \     | |        | |         
             | |  | | | ||  __/     | |___  _  | |         
             |_|  |_| |_| \___|      \____|(_)|___|        
 )";
 cout << "would you like to play again yes(1) or no (2)" << endl;
        cin >> game;
        }while(game==1);
	return 0;
}
    
    void boss(int&damN, int&Phealth, int&damP, int&heal, int&coins, int&Phealth1, int floor, string name)
    {
        string attackName1,attackName2;
    // monster strings
string Nene = R"(
                            |              _,._         |
                            |  .||,       /_ _\\        |
                            | \.`',/      |'L'| |       |
                            | = ,. =      | -,| L       |
                            | / || \    ,-'\"/,'`.      |
                            |   ||     ,'   `,,. `.     |
                            |   ,|____,' , ,;' \| |     |
                            |  (3|\    _/|/'   _| |     |
                            |   ||/,-''  | >-'' _,\\    |
       !                    |   ||'      ==\ ,-'  ,'    |
      .-.                   |   ||       |  V \ ,|      |
    __|=|__                 |   ||       |    |` |      |
   (_/`-`\_)                |   ||       |    |   \     |
   //\___/\\                |   ||       |    \    \    |
   <>/   \<>                |   ||       |     |    \   |
    \|_._|/                 |   ||       |      \_,-'   |
     <_I_>                  |   ||       |___,,--")_\   |
      |||                   |   ||         |_|   ccc/   |
     /_|_\                  |   ||        ccc/          |)";
string GrimR = R"(
                            | ____,                 |
                            |/.---|                 |
                            |`    |     ___         |
                            |    (=\.  /-. \        |
                            |     |\/\_|**| |       |
                            |     |_\ |;--| ;       |
       !                    |     | / \|  |_/\      |
      .-.                   |     | )/\/      \     |
    __|=|__                 |     | ( '|  \   |     |
   (_/`-`\_)                |     |    \_ /   \     |
   //\___/\\                |     |    /  \_.--\    |
   <>/   \<>                |     \    |    (|\`    |
    \|_._|/                 |      |   |     \      |
     <_I_>                  |      |   |      '.    |
      |||                   |      |  /         \   |
     /_|_\                  |      \  \.__.__.-._)  |)";
string Fairy = R"(
                            |   _   vvvvvvvvv   _   |
                            |  ( `-._\...../_.-' )  |
       !                    |   \   ((('_')))   /   |
      .-.                   |    )   ))) (((   (    |
    __|=|__                 |   (   ((( v )))   )   |
   (_/`-`\_)                |    )`--' )X( `-._(    |
   //\___/\\                |   /   _./   \._   \   |
   <>/   \<>                |  /  .' /     \ `.  \  |
    \|_._|/                 | (__/  /       \  \__) |
     <_I_>                  |      /         \      |
      |||                   |     /           \     |
     /_|_\                  |    WwWwWwWwWwWwWwW    |)";
    
    // monster picking code
    string monster_picked;
    int size = 3;
    string monster[size];
    monster[0] = Nene;
    monster[1] = Fairy;
    monster[2] = GrimR;
    
    if (floor==0)
    {
        monster_picked = monster[0];
        attackName1 = "Flaming Tornado";
        attackName2  = "Arcane Blast";
    }
    else if  (floor==1)
    {
        monster_picked = monster[1];
        attackName1 = "Fairy Dust";
        attackName2 = "Fairy knifes";
    }
    else if (floor==2)
    {
        monster_picked = monster[2];
        attackName1 = "Scythe Slash";
        attackName2 = "Reaper Rashing";
    }
    // end of monster picking code
    
    string incorrect = R"( 
  ___                                            _   
 |_ _| _ __    ___  ___   _ __  _ __  ___   ___ | |_ 
  | | | '_ \  / __|/ _ \ | '__|| '__|/ _ \ / __|| __|
  | | | | | || (__| (_) || |   | |  |  __/| (__ | |_ 
 |___||_| |_| \___|\___/ |_|   |_|   \___| \___| \__|
                                                     
            ___                       _              
           |_ _| _ __   _ __   _   _ | |_            
            | | | '_ \ | '_ \ | | | || __|           
            | | | | | || |_) || |_| || |_            
           |___||_| |_|| .__/  \__,_| \__|           
                       |_|                           
  )";
  
  
    int damQ = damN*0.75;
    int damH = damN*1.25;
    int attack1 = 35;
    int attack2 = 50;
    int xspeed = 100;
    int yspeed = 90;
    int Mhealth1=150;
    int use1=0;
    int use2=0;
    
    int x =  (rand() % 2) + 1;
    int y =  (rand() % 4) + 1;
    std::chrono::seconds dura( 3);
    if (floor==1)
    Mhealth1=225;
    else if (floor==2)
    Mhealth1=337;
    
    
    if(xspeed>yspeed)
    {
        cout << "you attack first" << endl;
        do
        {
            int z;
            cout << monster_picked;
            cout <<"\n";
            cout << "You have " << Phealth << "hp the monster has "  << Mhealth1  << "hp" << endl;
            cout << "Would you like to attack or use a potion?" << endl;
            
            cout << "1:Quick attack\t" << damQ << "\n2:Normal attack\t" << damN << endl;
            cout << "3:Heavy attack\t" << damH << "\n4:Damage potion\t" << damP<< endl;
            cout << "5:Health potion\t" << heal << endl;
            cin >> z;
            while (z!=1&&z!=2&&z!=3&&z!=4&&z!=5)
            {
                system("clear");
                std::cout << incorrect;
                std::chrono::seconds dura(3);
                std::this_thread::sleep_for( dura );
                system("clear");
                cin.clear();
                cin.ignore(1, '\n');
                cout << monster_picked;
                cout << "\b\bYou have " << Phealth << "hp the moster has "  << Mhealth1  << "hp" << endl;
                cout << "Would you like to attack or use a potion?" << endl;
                cout << "1:Quick attack\n" << "2:Normal attack" << endl;
                cout << "3:Heavy attack\n" << "4:Damage potion" << endl;
                cout << "5:Health potion" << endl;
                cin >> z;
            }
            switch(z)
            {
                case 1:
                
                cout << "You did " << damQ << " damage to him!" << endl;
                Mhealth1 = Mhealth1 - damQ;
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by  "<< attackName1 << " for " << attack1 << " damage" << endl;
                    Phealth = Phealth - attack1;
                }
                else 
                {
                    cout<< "You got hit by " << attackName2 << " for " << attack2 << " health" << endl;
                    Phealth = Phealth - attack2;
                }
                
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 2:
                    cout << "You did " << damN << " damage to him!" << endl;
                    Mhealth1 = Mhealth1 - damN;
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by " << attackName1 << " for " << attack1 << " damage" << endl;
                    Phealth = Phealth - attack1;
                }
                else 
                {
                    cout<< "You got hit by " << attackName2 << " for " << attack2 << " health" << endl;
                    Phealth = Phealth - attack2;
                }
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 3:
                y =  (rand() % 4) + 1;
                if (y==1)
                {
                    cout << "You did " << damH << " damage to him!" << endl;
                    Mhealth1 = Mhealth1 - damH;
                }
                else 
                {
                    cout << "you missed" << endl;
                }
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by " << attackName1 <<  " for " << attack1 << " damage" << endl;
                    Phealth = Phealth - attack1;
                }
                else 
                {
                    cout<< "You got hit by " << attackName2 << " for " << attack2 << " health" << endl;
                    Phealth = Phealth - attack2;
                }
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 4:
                if (use2!=1)
                {
                    cout << "Your damage potion did " << damP << " damage to all monsters" << endl;
                    Mhealth1=Mhealth1-damP;
                    use2++;
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                else
                {
                    cout << "You can only use damage potions 1 time per battle" << endl;
                    srand(time(0));
                    x =  (rand() % 2) + 1;
                    if (x == 1 )
                    {
                        cout << "In your confusion you got hit by "<< attackName1 << " for " << attack1 << " damage" << endl;
                        Phealth = Phealth - attack1;
                    }
                    else 
                    {
                        cout << "In your confusion you got hit by " << attackName2 << " for " << attack2 << " health" << endl;
                        Phealth = Phealth - attack2;
                    }
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                break;
                case 5:
                if (use1!=2)
                {
                    cout << "You healed for " << heal << endl;
                    Phealth=Phealth+heal;
                    use1++;
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                else
                {
                    cout << "You can only use health potions 2 times per battle" << endl;
                    srand(time(0));
                    x =  (rand() % 2) + 1;
                    if (x == 1 )
                    {
                        cout << "In your confusion you got hit by " << attackName1 <<  " for " << attack1 << " damage" << endl;
                        Phealth = Phealth - attack1;
                    }
                    else 
                    {
                        cout << "In your confusion you got hit by " << attackName2 << " for " << attack2 << " health" << endl;
                        Phealth = Phealth - attack2;
                    }
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }   
                break;
            }
            
        }while (Phealth > 0 && Mhealth1 > 0);
        
        if (Phealth < 1)
        {
            cout << name << " has been slayed in the C.I."<< endl;
            cout << "When will we get a worthy contestant?" << endl;
        }
        if (Mhealth1 < 1)
        {
            srand(time(0));
            int coin =  (rand() % 25) + 30;
            cout << "You have slayed the Boss in this room contiue on your journey young slayer!" << endl;
            cout << "The Boss Dropped \033[0;33m" << coin << "\033[0m coins\n You now have \033[0;33m" << coins + coin << " \033[0mcoins " << endl;
            coins = coins + coin;
        }
    }
    }
   
    
    
    void attack(int&damN, int&Phealth, int&damP, int&heal, int&coins, int&Phealth1, int floor, string name)
    {
        // monster strings
   string roach = R"(
                                |      ,--.   ,---.    |
                                |     /    \-|     \   |
       !                        |         (o o)      (/|
      .-.                       |         /'v'     ,-' |
    __|=|__                     | ,------/ >< \---'    |
   (_/`-`\_)                    |/)     ;  --  :       |
   //\___/\\                    |   ,---| ---- |--.    |
   <>/   \<>                    | (|  ,-| ---- |-. |)  |
    \|_._|/                     |     \  \ -- /  /     |
     <_I_>                      |     ;   \  /  :      |
      |||                       |    /   / \/ \  \     |
     /_|_\                      |   /)           (\    |)";
     
     string rat =  R"(
                                |                   |
                                |                   |
       !                        |                   |
      .-.                       |                   |
    __|=|__                     |                   |
   (_/`-`\_)                    |,     .            |
   //\___/\\                    |(\,;,/)            |
   <>/   \<>                    | (o o)\//,         |
    \|_._|/                     |  \ /     \,       |
     <_I_>                      |  `+'(  (   \    ) |
      |||                       |     //  \   |_./  |
     /_|_\                      |    '~' '~----'    |)";
     
     string shark = R"(
                                |                         |
                                |                         |
       !                        | _________         .    .|
      .-.                       |(..       \_    ,  |\  /||
    __|=|__                     | \       O  \  /|  \ \/ /|
   (_/`-`\_)                    |  \______    \/ |   \  / |
   //\___/\\                    |     vvvv\    \ |   /  | |
   <>/   \<>                    |     \^^^^  ==   \_/   | |
    \|_._|/                     |      `\_   ===    \.  | |
     <_I_>                      |      / /\_   \ /      | |
      |||                       |      |/   \_  \|      / |
     /_|_\                      |             \________/  |)";
    
    // monster picking code
    string monster_picked;
    int size = 3;
    string monster[size];
    monster[0] = rat;
    monster[1] = roach;
    monster[2] = shark;
    string MattackName1,MattackName2;
    srand(time(0));
     int mon =  (rand() % 3) + 0;
     
     
    if (mon ==0)
    {
        monster_picked = monster[0];
        MattackName1 = "Screech";
        MattackName2 = "Nibble";
    }
    else if  (mon ==1)
    {
        monster_picked = monster[1];
        MattackName1 = "Critter Crawl";
        MattackName2 = "Roach Stinch";
    }
    else if (mon==2)
    {
        monster_picked = monster[2];
        MattackName1 = "Shark Fin";
        MattackName2 = "Chomp";
    }
    // end of monster picking code
    
string incorrect = R"( 
  ___                                            _   
 |_ _| _ __    ___  ___   _ __  _ __  ___   ___ | |_ 
  | | | '_ \  / __|/ _ \ | '__|| '__|/ _ \ / __|| __|
  | | | | | || (__| (_) || |   | |  |  __/| (__ | |_ 
 |___||_| |_| \___|\___/ |_|   |_|   \___| \___| \__|
                                                     
            ___                       _              
           |_ _| _ __   _ __   _   _ | |_            
            | | | '_ \ | '_ \ | | | || __|           
            | | | | | || |_) || |_| || |_            
           |___||_| |_|| .__/  \__,_| \__|           
                       |_|                           
  )";
string RoomC = R"( 
              ____                                        
             |  _ \  ___    ___   _ __ ___                
             | |_) |/ _ \  / _ \ | '_ ` _ \               
             |  _ <| (_) || (_) || | | | | |              
             |_| \_\\___/  \___/ |_| |_| |_|              
   ____                          _        _             _ 
  / ___| ___   _ __ ___   _ __  | |  ___ | |_  ___   __| |
 | |    / _ \ | '_ ` _ \ | '_ \ | | / _ \| __|/ _ \ / _` |
 | |___| (_) || | | | | || |_) || ||  __/| |_|  __/| (_| |
  \____|\___/ |_| |_| |_|| .__/ |_| \___| \__|\___| \__,_|)";
    int damQ = damN*0.75;
    int damH = damN*1.25;
    int spit = damN*0.50;
    int scratch = damN*0.75;
    int Mhealth1 = Phealth1*0.75;
    int xspeed = 100;
    int yspeed = 90;
    int use1=0;
    int use2=0;
    
    int x =  (rand() % 2) + 1;
    int y =  (rand() % 4) + 1;
    std::chrono::seconds dura( 3);
    if(floor==2)
    {
        Mhealth1=Mhealth1+50;
    }
    else if(floor==3)
    {
        Mhealth1=Mhealth1+100;
    }
    
    if(xspeed>yspeed)
    {
        cout << "\b\byou attack first" << endl;
        do
        {
            int z;
            
            cout << monster_picked << endl;
            cout << "You have " << Phealth << "hp the monster has "  << Mhealth1  << "hp" << endl;
            cout << "Would you like to attack or use a potion?" << endl;
            
            cout << "1:Quick attack\t" << damQ << "\n2:Normal attack\t" << damN << endl;
            cout << "3:Heavy attack\t" << damH << "\n4:Damage potion\t" << damP<< endl;
            cout << "5:Health potion\t" << heal << endl;
            cin >> z;
            while (z!=1&&z!=2&&z!=3&&z!=4&&z!=5&&z!=1023)
            {
                system("clear");
                std::cout << incorrect;
                std::chrono::seconds dura( 3);
                std::this_thread::sleep_for( dura );
                system("clear");
                cin.clear();
                cin.ignore(1, '\n');
                cout << monster_picked << endl;
                cout << "You have " << Phealth << "hp the monster has "  << Mhealth1  << "hp" << endl;
                cout << "Would you like to attack or use a potion?" << endl;
                cout << "1:Quick attack\t" << damQ << "\n2:Normal attack\t" << damN << endl;
                cout << "3:Heavy attack\t" << damH << "\n4:Damage potion\t" << damP<< endl;
                cout << "5:Health potion\t" << heal << endl;
                cin >> z;
            }
            switch(z)
            {
                case 1:
                
                cout << "You did " << damQ << " damage to him!" << endl;
                Mhealth1 = Mhealth1 - damQ;
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by " << MattackName1 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - spit;
                }
                else 
                {
                    cout << "You got hit by " << MattackName2 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - scratch;
                }
                
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 2:
                    cout << "You did " << damN << " damage to him!" << endl;
                    Mhealth1 = Mhealth1 - damN;
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by " << MattackName1 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - spit;
                }
                else 
                {
                    cout << "You got hit by " << MattackName2 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - scratch;
                }
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 3:
                y =  (rand() % 4) + 1;
                if (y==1)
                {
                    cout << "You did " << damH << " damage to him!" << endl;
                    Mhealth1 = Mhealth1 - damH;
                }
                else 
                {
                    cout << "you missed" << endl;
                }
                srand(time(0));
                x =  (rand() % 2) + 1;
                if (x == 1 )
                {
                    cout << "You got hit by " << MattackName1 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - spit;
                }
                else 
                {
                    cout << "You got hit by " << MattackName2 << " for " << spit << " damage" << endl;
                    Phealth = Phealth - scratch;
                }
                std::this_thread::sleep_for( dura );
                system("clear");
                break;
                case 4:
                if (use2!=1)
                {
                    cout << "Your damage potion did " << damP << " damage to all monsters" << endl;
                    Mhealth1=Mhealth1-damP;
                    use2++;
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                else
                {
                    cout << "You can only use damage potions 1 time per battle" << endl;
                    srand(time(0));
                    x =  (rand() % 2) + 1;
                    if (x == 1 )
                    {
                        cout << "You got hit by " << MattackName1 << " for " << spit << " damage in your confuseion" << endl;
                        Phealth = Phealth - spit;
                    }
                    else 
                    {
                        cout << "You got hit by " << MattackName2 << " for " << spit << " damage in your confuseion" << endl;
                        Phealth = Phealth - scratch;
                    }
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                break;
                case 5:
                if (use1!=2)
                {
                    cout << "You healed for " << heal << endl;
                    Phealth=Phealth+heal;
                    use1++;
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                else
                {
                    cout << "You can only use health potions 2 times per battle" << endl;
                    srand(time(0));
                    x =  (rand() % 2) + 1;
                    if (x == 1 )
                    {
                        cout << "You got hit by " << MattackName1 << " for " << spit << " damage in your confuseion" << endl;
                        Phealth = Phealth - spit;
                    }
                    else 
                    {
                        cout << "You got hit by " << MattackName2 << " for " << spit << " damage in your confuseion" << endl;
                        Phealth = Phealth - scratch;
                    }
                    std::this_thread::sleep_for( dura );
                    system("clear");
                }
                break;
                case 1023:
                Mhealth1=Mhealth1-Mhealth1;
                break;
            }
            
        }while (Phealth > 0 && Mhealth1 > 0);
        
        if (Phealth < 1)
        {
            cout << name << "has been slayed in the C.I."<< endl;
            cout << "When will we get a worthy contestant?" << endl;
        }
        if (Mhealth1 < 1)
        {
            system("clear");
            srand(time(0));
            int coin =  (rand() % 16) + 15;
            std::cout << RoomC;
            cout << endl << "This monster has dropped \033[0m" << coin << "\033[0m coins \nYou now have \033[0;33m" << coins + coin << " \033[0mcoins" << endl;
            coins = coins + coin;
        }

    }
}

    void forge(int& weapon, int& armor, int& potion1, int& potion2, int& price1, int& price2, int& price3, int& price4, int& coins, int& damN, int& Phealth, int& Phealth1, int& heal, int& damP)
    {
        string incorrect = R"( 
          ___                                            _   
         |_ _| _ __    ___  ___   _ __  _ __  ___   ___ | |_ 
          | | | '_ \  / __|/ _ \ | '__|| '__|/ _ \ / __|| __|
          | | | | | || (__| (_) || |   | |  |  __/| (__ | |_ 
         |___||_| |_| \___|\___/ |_|   |_|   \___| \___| \__|
                                                             
                    ___                       _              
                   |_ _| _ __   _ __   _   _ | |_            
                    | | | '_ \ | '_ \ | | | || __|           
                    | | | | | || |_) || |_| || |_            
                   |___||_| |_|| .__/  \__,_| \__|           
                               |_|                           
          )";
        int upgrade;
        int q;
        do
        {
            inventory(weapon, armor, potion1, potion2, price1, price2, price3, price4, coins, damN, Phealth, Phealth1, heal, damP);
            cout << "\033[0m";
            cout << endl;
            cout << "****************************************The Forge******************************************************************";
            cout << endl;
            cout << "1:Upgrage Weapon Cost: " << price1 << endl;
            cout << "2:Upgrade Armor Cost: " << price2 << endl;
            cout << "3:Upgrade Health Potion Cost: " << price3 << endl;
            cout << "4:Upgrade Damage Potion Cost: " << price4 << endl;
            cout << "5:Move To Next Room" << endl;
            cin >> upgrade;
            while (upgrade != 1 && upgrade != 2 && upgrade != 3 && upgrade != 4 && upgrade != 5)
            {
                system("clear");
                std::cout << incorrect;
                std::chrono::seconds dura(2);
                std::this_thread::sleep_for( dura );
                system("clear");
                cin.clear();
                cin.ignore(1, '\n');
                cout << "******************************************The Forge******************************************************************";
                cout << endl;
                cout << "1:Upgrage Weapon Cost: " << price2 << endl;
                cout << "2:Upgrade Armor Cost: " << price2 << endl;
                cout << "3:Upgrade Health Potion Cost: " << price3 << endl;
                cout << "4:Upgrade Damage Potion Cost: " << price4 << endl;
                cout << "5:Move To Next Room" << endl;
                cin >> upgrade;
            }
            switch (upgrade)
            {
                case 1:
                if(coins>price1)
                {
                    if(weapon==5||weapon==10||weapon==15)
                    {
                        cout << "your weapon is max level" << endl;
                    }
                    else
                    {
                        coins=coins-price1;
                        weapon++;
                    }
                }
                else
                cout << "Not enough coins" << endl;
                break;
                case 2:
                if(coins>price2)
                {
                    if(armor==5||armor==10||armor==15)
                    {
                        cout << "your armor is max level" << endl;
                    }
                    else
                    {
                        coins=coins-price2;
                        armor++;
                    }
                }
                else 
                cout << "Not enough coins" << endl;
                break;
                case 3:
                if(coins>price3)
                {
                    if(potion1==5)
                    {
                        cout << "your health potion is max level" << endl;
                    }
                    else
                    {
                        coins=coins-price3;
                        potion1++;
                    }
                }
                else 
                cout << "Not enough coins" << endl;
                break;
                case 4:
                if(coins>price4)
                {
                    if(potion2==5)
                    {
                        cout << "your damage potion is max level" << endl;
                    }
                    else
                    {
                        coins=coins-price4;
                        potion2++;
                    }
                }
                else
                cout << "Not enough coins" << endl;
                break;
                case 5:
                cout << "Good Luck Adventurer" << endl;
                break;
                default:
                cout << "Incorect imput \n Try again" << endl;
            }
            if (upgrade!=5)
            {
                inventory(weapon, armor, potion1, potion2, price1, price2, price3, price4, coins, damN, Phealth, Phealth1, heal, damP);
                cin.get();
            }
            std::chrono::seconds dura(4);
            std::this_thread::sleep_for( dura );
            system("clear");
        }
        while (upgrade!=5);
    }

    void inventory(int& weapon, int& armor, int& potion1, int& potion2, int& price1, int& price2, int& price3, int& price4, int& coins, int& damN, int& Phealth, int& Phealth1, int& heal, int& damP)
    {
        switch (weapon)
        {
            case 1:
            cout << "\033[0mcommon sword";
            price1=25;
            damN=33;
            break;
            case 2:
            cout << "\033[0;32muncommon sword";
            price1=50;
            damN=49;
            break;
            case 3:
            cout << "\033[0;34mrare sword";
            price1=75;
            damN=73;
            break;
            case 4:
            cout << "\033[0;35mepic sword";
            price1=100;
            damN=109;
            break;
            case 5:
            cout << "\033[0;33mlegendary sword";
            price1=0;
            damN=163;
            break;
            case 6:
            cout << "\033[0mcommon bow";
            price1=25;
            damN=25;
            break;
            case 7:
            cout << "\033[0;32muncommon bow";
            price1=50;
            damN=37;
            break;
            case 8:
            cout << "\033[0;34mrare bow";
            price1=75;
            damN=55;
            break;
            case 9:
            cout << "\033[0;35mepic bow";
            price1=100;
            damN=82;
            break;
            case 10:
            cout << "\033[0;33mlegendary bow";
            price1=0;
            damN=123;
            break;
            case 11:
            cout << "\033[0mcommon dagger";
            price1=25;
            damN=37;
            break;
            case 12:
            cout << "\033[0;32muncommon dagger";
            price1=50;
            damN=55;
            break;
            case 13:
            cout << "\033[0;34mrare dagger";
            price1=75;
            damN=82;
            break;
            case 14:
            cout << "\033[0;35mepic dagger";
            price1=100;
            damN=123;
            break;
            case 15:
            cout << "\033[0;33mlegendary dagger";
            price1=0;
            damN=184;
            break;
            default:
            cout << "what" << endl;
        }
        cout << endl;
        switch (armor)
        {
            case 1:
            cout << "\033[0mcommon armor";
            price2=25;
            Phealth=120;
            Phealth1=Phealth;
            break;
            case 2:
            cout << "\033[0;32muncommon armor";
            price2=50;
            Phealth=160;
            Phealth1=Phealth;
            break;
            case 3:
            cout << "\033[0;34mrare armor";
            price2=75;
            Phealth=220;
            Phealth1=Phealth;
            break;
            case 4:
            cout << "\033[0;35mepic armor";
            price2=100;
            Phealth=300;
            Phealth1=Phealth;
            break;
            case 5:
            cout << "\033[0;33mlegendary armor";
            price2=0;
            Phealth=400;
            Phealth1=Phealth;
            break;
            
            case 6:
            cout << "\033[0mcommon armor";
            price2=25;
            Phealth=100;
            Phealth1=Phealth;
            break;
            case 7:
            cout << "\033[0;32muncommon armor";
            price2=50;
            Phealth=130;
            Phealth1=Phealth;
            break;
            case 8:
            cout << "\033[0;34mrare armor";
            price2=75;
            Phealth=175;
            Phealth1=Phealth;
            break;
            case 9:
            cout << "\033[0;35mepic armor";
            price2=100;
            Phealth=235;
            Phealth1=Phealth;
            break;
            case 10:
            cout << "\033[0;33mlegendary armor";
            price2=0;
            Phealth=310;
            Phealth1=Phealth;
            break;
            case 11:
            cout << "\033[0mcommon armor";
            price2=25;
            Phealth=70;
            Phealth1=Phealth;
            break;
            case 12:
            cout << "\033[0;32muncommon armor";
            price2=50;
            Phealth=90;
            Phealth1=Phealth;
            break;
            case 13:
            cout << "\033[0;34mrare armor";
            price2=75;
            Phealth=120;
            Phealth1=Phealth;
            break;
            case 14:
            cout << "\033[0;35mepic armor";
            price2=100;
            Phealth=160;
            Phealth1=Phealth;
            break;
            case 15:
            cout << "\033[0;33mlegendary armor";
            price2=0;
            Phealth=220;
            Phealth1=Phealth;
            break;
            default:
            cout << "what" << endl;
        }
        cout << endl;
        switch (potion1)
        {
            case 1:
            cout << "\033[0mcommon health potion";
            price3=25;
            heal=Phealth*0.10;
            break;
            case 2:
            cout << "\033[0;32muncommon health potion";
            price3=50;
            heal=Phealth*0.25;
            break;
            case 3:
            cout << "\033[0;34mrare health  potion";
            price3=75;
            heal=Phealth*0.50;
            break;
            case 4:
            cout << "\033[0;35mepic health potion";
            price3=100;
            heal=Phealth*0.75;
            break;
            case 5:
            cout << "\033[0;33mlegendary health potion";
            price3=0;
            heal=Phealth;
            break;
            default:
            cout << "what" << endl;
        }
        cout << endl;
        switch (potion2)
        {
            case 1:
            cout << "\033[0mcommon damage potion";
            price4=25;
            damP=25;
            break;
            case 2:
            cout << "\033[0;32muncommon damage potion";
            price4=50;
            damP=50;
            break;
            case 3:
            cout << "\033[0;34mrare damage potion";
            price4=75;
            damP=75;
            break;
            case 4:
            cout << "\033[0;35mepic damage potion";
            price4=100;
            damP=100;
            break;
            case 5:
            cout << "\033[0;33mlegendary damage potion";
            price4=0;
            damP=125;
            break;
            default:
            cout << "what" << endl;
        }
        cout << "\033[0m";
        cout << endl;
        cout << "you have \033[0;33m" << coins << " \033[0mcoins";
    }
    
    
    // code for rock paper scissor lizard spock
    int rpsls(int num)
    {
        srand(time(0));
        int com =  (rand() % 5) + 1;
        //rock inputs
        if (num== 1 && com == 3)
        {
           return 1;
        }
        if (num== 1 && com == 4)
        {
            return 2;
        }
        if (num== 1 && com == 1)
        {
           return 3;
        }
        if (num== 1 && com == 2)
        {
            return 4;
        }
        if (num== 1 && com == 5)
        {
            return 5;
        }
        //paper inputs
        if (num== 2 && com == 1)
        {
           return 6;
        }
        if (num== 1 && com == 5)
        {
            return 7;
        }
        if (num== 2 && com == 2)
        {
            return 8;
        }
        if (num== 2 && com == 3)
        {
            return 9;
        }
        if (num== 1 && com == 4)
        {
            return 10;
        }
        //scissors inputs
        if (num== 3 && com == 2)
        {
            return 11;
        }
        if (num== 3 && com == 4)
        {
            return 12;
        }
        if (num== 3 && com == 3)
        {
           return 13;
        }
        if (num== 3 && com == 1)
        {
            return 14;
        }
        if (num== 3 && com == 5)
        {
            return 15;
        }
        //lizard inputs
        if (num== 4 && com == 2)
        {
            return 16;
        }
        if (num== 4 && com == 5)
        {
            return 17;
        }
        if (num== 4 && com == 4)
        {
            return 18;
        }
        if (num== 4 && com == 1)
        {
            return 19;
        }
        if (num== 4 && com == 3)
        {
            return 20;
        }
        //Spock inputs
        if (num== 5 && com == 1)
        {
            return 21;
        }
        if (num== 5 && com == 3)
        {
            return 22;
        }
        if (num== 5 && com == 5)
        {
            return 23;
        }
        if (num== 5 && com == 2)
        {
            return 24;
        }
        if (num== 5 && com == 4)
        {
            return 25;
        }
    }