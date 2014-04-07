//Coded By Ex094
//http://www.procurity.wordpress.com
//http://www.hackcommunity.com/User-Ex094

#include <iostream>
#include <fstream>
#include <vector>
#include "md5.h"
#include <map>
#include <limits>

#ifdef _WIN32
#include "clearscreenw.h"

#elif _WIN64
#include "clearscreenw.h"

#elif __APPLE__
#include "clearscreenl.h"

#elif __linux
#include "clearscreenl.h"

#elif __unix
#include "clearscreenl.h"

#elif __posix
#include "clearscreenwl.h"

#endif

//Important Storage Array and Checking Variables
std::string dload = "Unloaded", hload = "Unloaded", chash = "";

char dname[32];
int choice; //To store user's choice at menu

//Initalize functions for use
void get_hash(std::string cHash);
void crack_hash(std::string hash);
bool check_dict(char filename[35]);
void pause();

void menu () {

    std::cout << "                          HACKCOMMUNITY OFFICIAL TOOL " << std::endl;

    std::cout << "  \n";

    std::cout << "                      Welcome to T0rn - Hash Cracking Tool \n";

    std::cout << "  \n";

    std::cout << "1) Link Dictionary " << "[" << dload << "]" << std::endl;

    std::cout << "2) Load Hash to be Cracked " << " [" << hload << "]" << std::endl;

    std::cout << "3) Crack Hash" << std::endl;

    std::cout << "4) Exit" << std::endl;

    std::cout << "Chose your operation:" << std::endl;

    std::cin >> choice;

	ClearScreen();

    switch(choice) {
        case 1:
            std::cout << "Enter Dictionary Location (E.g. Text.txt): \n";
            std::cin >> dname;

            if(check_dict(dname))
                dload = "Loaded!";
            else {dload = "Unloaded"; std::cout << "Dictionary file does not exist!\n";}

			pause();
			ClearScreen();

			menu();
			break;

        case 2:
		    ClearScreen();

            std::cout << "Enter your MD5 Hash to Crack: " << std::endl;
            std::cin >> chash;


			get_hash(chash);

			pause();
			ClearScreen();

			menu();
			break;

		case 3:
		    crack_hash(chash);

			pause();
			ClearScreen();

			menu();
			break;

        case 4:
            exit(EXIT_SUCCESS);

		default:
		    std::cout << "Invalid Choice....";

			pause();
			ClearScreen();

			menu();
			break;
    }

	choice = 0;

}

int count_file(char filename[15]) {

    //Total Lines/Items
    int num = 0;

    //Load File
    std::ifstream f(filename);
    std::string line;

    //Count the items and increment by one on each item found
    for (int i = 0; std::getline(f, line); ++i) {num++;};

    //Return the total lines
    return num;
}

//Function to check if the dictionary file
//exists or not
bool check_dict(char filename[35]) {

    std::ifstream f;
    f.open(filename);

    if(!f) {

        return false;
    }

    else {

        return true;
    }

}


//Function to check if the hash is already
//cracked and present inside the db
void verifyHash(std::string hash) {

    int count = count_file("pass.txt");

	std::map <std::string, std::string> hashbase;

	std::ifstream upass ("pass.txt");

	char pload[35];

	MD5 md5;

	char y[32];

	bool con;

	for(int i = 0; i < count; i++) {

		upass >> pload;

		if(md5.digestString(pload) == hash) {

                hload = "Unloaded";
                std::cout << "Your cracked hash is: " << pload << std::endl;
                break;
		}

		con = false; //Condition  to check if matching fails
	}

	if(!con) {

        chash = hash;
	}
}


//Function to get a Valid MD5 hash from user
void get_hash(std::string cHash) {

    if (cHash.length() == 32) {

        //Put record function here
        hload = "Loaded!";
    }

    else {

        std::cout << "A valid Hash Was not entered!" << std::endl;
    }

	verifyHash(cHash);

}


//Adds the cracked hash to the db list
void addToRecord(std::string cPass) {

    std::ofstream ansf;

    ansf.open("pass.txt", std::ios::app); //Create file if not found

    ansf << cPass << std::endl; //Write the password at the eof

}

//Cracks the given hash by converting
//each dict item to it's equivalent
//hash and then comparing it to the
//original one
void crack_hash(std::string hash) {

	MD5 md5;

	char y[32];

	int words = 0;

	int count = count_file(dname);


	if (hload == "Loaded!" && dload == "Loaded!") {

            std::ifstream dict (dname);

            if(check_dict(dname)) {

                    char test[25];

                    std::cout << "Cracking..." << std::endl;

                    for(int i = 0; i < count; i++) {

                            dict >> test;

                            words += 1;

                            if(md5.digestString(test) == hash) {

                                    std::cout << "Your cracked string is: " << test << std::endl;

                                    std::cout << "Words handled: " << words << std::endl;

                                    addToRecord(test);

                                    break;

                            }
                    }

            } else {

                std::cout << "Dictionary Location not found!" << std::endl;
            }

	} else {

		std::cout << "Either your Dictionary or your Hash is not loaded!" << std::endl;
	}

}

//Pause function
void pause() {

	std::cout << "Press Any Key to Continue...";

	std::cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n'); // Clear stream
	std::cin.get();

}


int main()
{
	menu();
}
