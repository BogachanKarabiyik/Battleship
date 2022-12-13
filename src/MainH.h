#pragma once

class map {
private:

public:
	char show[100] = {};
	int real[100] = {};
	char show_player[100] = {};
	int real_player[100] = {};

	// Display the map
	void display(std::string first_message, std::string second_message, std::string third_message, int ship_number) {
		system("CLS");
		std::cout << "\n      A B C D E F G H I J  \n";
		std::cout << "    |---------------------|\n";
		std::cout << "  1 |";
		for (int i = 0; i < 100; i++) {
			if (i % 10 == 0 && i != 0) {
				if ((i / 10) + 1 == 10) {
					std::cout << " |\n " << (i / 10) + 1 << " |";
				}
				else {
					std::cout << " |\n  " << (i / 10) + 1 << " |";
				}
			}
			if (ship_number == 1) {
				if (real[i] == 1) {
					if (show[i] != 'X') {
						show[i] = 'C';
					}
				}
			}
			else if (ship_number == 2) {
				if (real[i] == 2) {
					if (show[i] != 'X') {
						show[i] = 'B';
					}
				}
			}
			else if (ship_number == 3) {
				if (real[i] == 3) {
					if (show[i] != 'X') {
						show[i] = 'R';
					}
				}
			}
			else if (ship_number == 4) {
				if (real[i] == 4) {
					if (show[i] != 'X') {
						show[i] = 'S';
					}
				}
			}
			else if (ship_number == 5) {
				if (real[i] == 5) {
					if (show[i] != 'X') {
						show[i] = 'D';
					}
				}
			}
			std::cout << ' ' << show[i];
		}
		std::cout << " |\n";
		std::cout << "    |---------------------|";
		std::cout << "\n" << first_message;
		std::cout << "\n" << second_message;
		std::cout << "\nType C, B, R, S, D to see the ship";
		std::cout << "\n" << third_message;
		std::cout << "\n  > ";
	}

	// Display VS CPU map
	void display_cpu(std::string first_message, std::string second_message, std::string third_message) {
		system("CLS");
		std::cout << "\n            - CPU -                                - Captain John Connor -\n";
		std::cout << "      A B C D E F G H I J                            A B C D E F G H I J\n";
		std::cout << "    |---------------------|                        |---------------------|\n";
		std::cout << "  1 |";
		for (int i = 0; i < 100; i++) {
			if (real_player[i] == 1 && show_player[i] == ' ') {
				show_player[i] = 'C';
			}
			else if (real_player[i] == 2 && show_player[i] == ' ') {
				show_player[i] = 'B';
			}
			else if (real_player[i] == 3 && show_player[i] == ' ') {
				show_player[i] = 'R';
			}
			else if (real_player[i] == 4 && show_player[i] == ' ') {
				show_player[i] = 'S';
			}
			else if (real_player[i] == 5 && show_player[i] == ' ') {
				show_player[i] = 'D';
			}
			if (i % 10 == 0 && i != 0) {
				if ((i / 10) + 1 == 10) {
					std::cout << " |" << "                      " << (i / 10) << " |";
					for (int x = 0; x < 10; x++) {
						std::cout << ' ' << show_player[x + (i - 10)];
					}
					std::cout << " |\n " << (i / 10) + 1 << " |";
				}
				else {
					std::cout << " |" << "                      " << (i / 10) << " |";
					for (int x = 0; x < 10; x++) {
						std::cout << ' ' << show_player[x + (i - 10)];
					}
					std::cout << " |\n  " << (i / 10) + 1 << " |";
				}
			}

			std::cout << ' ' << show[i];

		}
		std::cout << " |                     10 |";
		for (int x = 90; x < 100; x++) {
			std::cout << ' ' << show_player[x];
		}
		std::cout << " |\n    |---------------------|                        |---------------------|";
		std::cout << "\n" << first_message;
		std::cout << "\n" << second_message;
		std::cout << "\n" << third_message;
		std::cout << "\n                           > ";
	}


}map;

class ships {
private:

public:
	// ship[ship-length] = {position numbers}
	int carrier[5] = {};
	int battleship[4] = {};
	int cruiser[3] = {};
	int submarine[3] = {};
	int destroyer[2] = {};

	int carrier_player[5] = {};
	int battleship_player[4] = {};
	int cruiser_player[3] = {};
	int submarine_player[3] = {};
	int destroyer_player[2] = {};

	void place() {

		// <rand>
		std::random_device rd;
		std::default_random_engine rng(rd());

		for (int ship_amount = 0; ship_amount < 5; ship_amount++) {

			// ship[ship-length] = {position numbers}
			int current_ship[5] = {};
			int current_ship_length = 5;

			if (ship_amount == 0) {
				current_ship_length = 5;
			}
			else if (ship_amount == 1) {
				current_ship_length = 4;
			}
			else if (ship_amount == 2) {
				current_ship_length = 3;
			}
			else if (ship_amount == 3) {
				current_ship_length = 3;
			}
			else {
				current_ship_length = 2;
			}

			// cslmo: Current Ship Length Minus One
			int cslmo = current_ship_length - 1;

			// ship position
			std::uniform_int_distribution<> dist1(0, 99);
			int number = dist1(rng);

			// verticality(direction of the ship): 1 = up, 2 = right, 3 = down, 4 = left
			std::uniform_int_distribution<> dist2(1, 4);
			int verticality = dist2(rng);

			// number check
			for (int i = 0; i < 100; i++) {
				if (map.real[i]) {
					if (number == i) {
						number = dist1(rng);
						i = 0;
					}
				}
			}

			// verticality check
			for (int x = 0; x < 100; x++) {

				current_ship[0] = number;

				// get the first digit of the rear
				int rightCheck = (number + cslmo) / 10;
				int leftCheck = (number - cslmo) / 10;
				int numberCheck = number / 10;

				while ((leftCheck != numberCheck && verticality == 4) || (rightCheck != numberCheck && verticality == 2) || (number - (cslmo * 10) < 0 && verticality == 1) || (number + cslmo > 99 && verticality == 2) || (number + (cslmo * 10) > 99 && verticality == 3) || (number - cslmo < 0 && verticality == 4)) {
					verticality = dist2(rng);
				}
				if (verticality == 1) {
					current_ship[1] = number - 10;
					current_ship[2] = number - 20;
					current_ship[3] = number - 30;
					current_ship[4] = number - 40;
				}
				else if (verticality == 2) {
					current_ship[1] = number + 1;
					current_ship[2] = number + 2;
					current_ship[3] = number + 3;
					current_ship[4] = number + 4;
				}
				else if (verticality == 3) {
					current_ship[1] = number + 10;
					current_ship[2] = number + 20;
					current_ship[3] = number + 30;
					current_ship[4] = number + 40;
				}
				else {
					current_ship[1] = number - 1;
					current_ship[2] = number - 2;
					current_ship[3] = number - 3;
					current_ship[4] = number - 4;
				}

				// Final check
				if (map.real[x]) {
					for (int y = 0; y < current_ship_length; y++) {
						if (current_ship[y] == x) {
							number = dist1(rng);
							x = 0;
						}
					}
				}
			}
			// Set the ship on the map
			for (int i = 0; i < current_ship_length; i++) {
				map.real[current_ship[i]] = ship_amount + 1;

				// Give the ships their position
				if (ship_amount == 0) {
					carrier[i] = current_ship[i];
				}
				else if (ship_amount == 1) {
					battleship[i] = current_ship[i];
				}
				else if (ship_amount == 2) {
					cruiser[i] = current_ship[i];
				}
				else if (ship_amount == 3) {
					submarine[i] = current_ship[i];
				}
				else {
					destroyer[i] = current_ship[i];
				}
			}
		}
	}

}ships;

class display {
private:

public:
	void title_screen(std::string error_msg) {
		system("CLS");
		std::cout << "\n      - BATTLESHIP ORIGINS -\n\n";
		std::cout << "\n             Campaign\n";
		std::cout << "\n              VS CPU\n";
		std::cout << "\n               Quit\n\n";
		std::cout << "\033[32m\n Type 'campaign' for story mode";
		std::cout << " or\n 'cpu' to play against the computer.\033[0m\n";
		std::cout << error_msg;
		std::cout << "\n  > ";
	}

	void difficulty(std::string error_msg) {
		system("CLS");
		std::cout << "\n   - PLEASE TYPE A DIFFICULTY -\n\n\n";
		std::cout << "               Easy\n\n";
		std::cout << "              Normal\n\n";
		std::cout << "               Hard\n";
		std::cout << error_msg;
		std::cout << "\n  > ";
	}

	void story() {
		system("CLS");
		std::cout << "\n 18 November 1939;\n";
		std::cout << "\n  Congratulations.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Congratulations.";
		std::cout << "\n  Captain John Connor, you've been chosen for a mission.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Congratulations.";
		std::cout << "\n  Captain John Connor, you've been chosen for a mission.";
		std::cout << "\n  For immediate deployment, report to the headquarters.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Congratulations.";
		std::cout << "\n  Captain John Connor, you've been chosen for a mission.";
		std::cout << "\n  For immediate deployment, report to the headquarters.";
		std::cout << "\n  A battleship and it's crew will be under your command.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Congratulations.";
		std::cout << "\n  Captain John Connor, you've been chosen for a mission.";
		std::cout << "\n  For immediate deployment, report to the headquarters.";
		std::cout << "\n  A battleship and it's crew will be under your command.";
		std::cout << "\n  Sincerely, Admiral Frank L. Smith\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.";
		std::cout << "\n   Our route is as follows:\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.";
		std::cout << "\n   Our route is as follows:";
		std::cout << "\n   Firstly we should cross the Atlantic Ocean to the Strait of Gibraltar.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.";
		std::cout << "\n   Our route is as follows:";
		std::cout << "\n   Firstly we should cross the Atlantic Ocean to the Strait of Gibraltar.";
		std::cout << "\n   Then, we shall naviage through the Mediterranean Sea into the Sea of Marmara.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.";
		std::cout << "\n   Our route is as follows:";
		std::cout << "\n   Firstly we should cross the Atlantic Ocean to the Strait of Gibraltar.";
		std::cout << "\n   Then, we shall naviage through the Mediterranean Sea into the Sea of Marmara,";
		std::cout << "\n   where we can pass the Bosphorus into the Black Sea.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  20 November 1939;\n";
		std::cout << "\n   We have set sail for the country of Georgia.";
		std::cout << "\n   Estimated date of arrival: 9 October 1939.";
		std::cout << "\n   Our route is as follows:";
		std::cout << "\n   Firstly we should cross the Atlantic Ocean to the Strait of Gibraltar.";
		std::cout << "\n   Then, we shall naviage through the Mediterranean Sea into the Sea of Marmara,";
		std::cout << "\n   where we can pass the Bosphorus into the Black Sea.";
		std::cout << "\n   From there, we are to sail around Turkey and dock at the Georgian town of Anaklia.\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  1 October 1939;\n";
		std::cout << "\n   We've passed the Strait of Gibraltar,\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  1 October 1939;\n";
		std::cout << "\n   We've passed the Strait of Gibraltar,";
		std::cout << "\n   but the Mediterranean is teeming with enemy ships;\n\n\033[32m   ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n             - CAPTAIN'S LOGBOOK - \n\n";
		std::cout << "\n  1 October 1939;\n";
		std::cout << "\n   We've passed the Strait of Gibraltar,";
		std::cout << "\n   but the Mediterranean is teeming with enemy ships;";
		std::cout << "\n   if we can quickly sink a few of them, we'll be able to safely cross to the Black Sea.\n\n\033[32m   ";
		system("pause");
		std::cout << "\033[0m";
	}

	void story2() {
		system("CLS");
		std::cout << "\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.";
		std::cout << "\n  We have recieved your report.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.";
		std::cout << "\n  We have recieved your report.";
		std::cout << "\n  Your approch into enemy territory wasn't very covert.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.";
		std::cout << "\n  We have recieved your report.";
		std::cout << "\n  Your approch into enemy territory wasn't very covert.";
		std::cout << "\n  However, you have deftly stolen the enemy intelligence.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.";
		std::cout << "\n  We have recieved your report.";
		std::cout << "\n  Your approch into enemy territory wasn't very covert.";
		std::cout << "\n  However, you have deftly stolen the enemy intelligence.";
		std::cout << "\n  Thank you for all of your efforts.\n\n\033[32m  ";
		system("pause");
		system("CLS");
		std::cout << "\033[0m\n 18 November 1939;\n";
		std::cout << "\n  Hello Captain.";
		std::cout << "\n  We have recieved your report.";
		std::cout << "\n  Your approch into enemy territory wasn't very covert.";
		std::cout << "\n  However, you have deftly stolen the enemy intelligence.";
		std::cout << "\n  Thank you for all of your efforts.";
		std::cout << "\n  Sincerely, Admiral Frank L. Smith\n\n\033[32m  ";
		system("pause");
		std::cout << "\033[0m";
		system("CLS");
	}
}display;

class game {
private:

	std::string error_msg = "";
	std::string player_input = "";
	int player_hit = 100;
	int total_hits[17] = {};
	int ship_number = 0;

	void player_input_check() {
		for (int i = 1; i < 11; i++) {
			if (player_input == "a" + std::to_string(i) || player_input == "A" + std::to_string(i) || player_input == std::to_string(i) + "a" || player_input == std::to_string(i) + "A") {
				if (player_input[0] == 'a' || player_input[0] == 'A') {
					player_hit = (((int)player_input[1] - 49) * 10);
					if (player_input[2] == '0') {
						player_hit = 90;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10);
					if (player_input[1] == '0') {
						player_hit = 90;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "b" + std::to_string(i) || player_input == "B" + std::to_string(i) || player_input == std::to_string(i) + "b" || player_input == std::to_string(i) + "B") {
				if (player_input[0] == 'b' || player_input[0] == 'B') {
					player_hit = (((int)player_input[1] - 49) * 10) + 1;
					if (player_input[2] == '0') {
						player_hit = 91;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 1;
					if (player_input[1] == '0') {
						player_hit = 91;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "c" + std::to_string(i) || player_input == "C" + std::to_string(i) || player_input == std::to_string(i) + "c" || player_input == std::to_string(i) + "C") {
				if (player_input[0] == 'c' || player_input[0] == 'C') {
					player_hit = (((int)player_input[1] - 49) * 10) + 2;
					if (player_input[2] == '0') {
						player_hit = 92;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 2;
					if (player_input[1] == '0') {
						player_hit = 92;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "d" + std::to_string(i) || player_input == "D" + std::to_string(i) || player_input == std::to_string(i) + "d" || player_input == std::to_string(i) + "D") {
				if (player_input[0] == 'd' || player_input[0] == 'D') {
					player_hit = (((int)player_input[1] - 49) * 10) + 3;
					if (player_input[2] == '0') {
						player_hit = 93;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 3;
					if (player_input[1] == '0') {
						player_hit = 93;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "e" + std::to_string(i) || player_input == "E" + std::to_string(i) || player_input == std::to_string(i) + "e" || player_input == std::to_string(i) + "E") {
				if (player_input[0] == 'e' || player_input[0] == 'E') {
					player_hit = (((int)player_input[1] - 49) * 10) + 4;
					if (player_input[2] == '0') {
						player_hit = 94;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 4;
					if (player_input[1] == '0') {
						player_hit = 94;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "f" + std::to_string(i) || player_input == "F" + std::to_string(i) || player_input == std::to_string(i) + "f" || player_input == std::to_string(i) + "F") {
				if (player_input[0] == 'f' || player_input[0] == 'F') {
					player_hit = (((int)player_input[1] - 49) * 10) + 5;
					if (player_input[2] == '0') {
						player_hit = 95;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 5;
					if (player_input[1] == '0') {
						player_hit = 95;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "g" + std::to_string(i) || player_input == "G" + std::to_string(i) || player_input == std::to_string(i) + "g" || player_input == std::to_string(i) + "G") {
				if (player_input[0] == 'g' || player_input[0] == 'G') {
					player_hit = (((int)player_input[1] - 49) * 10) + 6;
					if (player_input[2] == '0') {
						player_hit = 96;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 6;
					if (player_input[1] == '0') {
						player_hit = 96;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "h" + std::to_string(i) || player_input == "H" + std::to_string(i) || player_input == std::to_string(i) + "h" || player_input == std::to_string(i) + "H") {
				if (player_input[0] == 'h' || player_input[0] == 'H') {
					player_hit = (((int)player_input[1] - 49) * 10) + 7;
					if (player_input[2] == '0') {
						player_hit = 97;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 7;
					if (player_input[1] == '0') {
						player_hit = 97;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "i" + std::to_string(i) || player_input == "I" + std::to_string(i) || player_input == std::to_string(i) + "i" || player_input == std::to_string(i) + "I") {
				if (player_input[0] == 'i' || player_input[0] == 'I') {
					player_hit = (((int)player_input[1] - 49) * 10) + 8;
					if (player_input[2] == '0') {
						player_hit = 98;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 8;
					if (player_input[1] == '0') {
						player_hit = 98;
					}
				}
				error_msg = "";
				i = 12;
			}
			else if (player_input == "j" + std::to_string(i) || player_input == "J" + std::to_string(i) || player_input == std::to_string(i) + "j" || player_input == std::to_string(i) + "J") {
				if (player_input[0] == 'j' || player_input[0] == 'J') {
					player_hit = (((int)player_input[1] - 49) * 10) + 9;
					if (player_input[2] == '0') {
						player_hit = 99;
					}
				}
				else {
					player_hit = (((int)player_input[0] - 49) * 10) + 9;
					if (player_input[1] == '0') {
						player_hit = 99;
					}
				}
				error_msg = "";
				i = 12;
			}
			else {
				player_hit = 100;
			}
		}
	}

public:
	int cannon_balls = 0;
	std::string mode = "";

	bool battle() {

		ship_number = 0;
		player_hit = 100;
		player_input = "";
		error_msg = "";

		for (int x = 0; x < 17; x++) {
			total_hits[x] = { 0 };
		}

		while (true) {

			map.display("      Cannonballs left: " + std::to_string(cannon_balls), "\033[32m    Please type a coordinate\033[0m", error_msg, ship_number);
			std::getline(std::cin, player_input);

			ship_number = 0;

			if (player_input == "C" || player_input == "c") {
				error_msg = "\033[32m    We've spotted them Captain\033[0m";
				ship_number = 1;
			}
			else if (player_input == "B" || player_input == "b") {
				error_msg = "\033[32m    We've spotted them Captain\033[0m";
				ship_number = 2;
			}
			else if (player_input == "R" || player_input == "r") {
				error_msg = "\033[32m    We've spotted them Captain\033[0m";
				ship_number = 3;
			}
			else if (player_input == "S" || player_input == "s") {
				error_msg = "\033[32m    We've spotted them Captain\033[0m";
				ship_number = 4;
			}
			else if (player_input == "D" || player_input == "d") {
				error_msg = "\033[32m    We've spotted them Captain\033[0m";
				ship_number = 5;
			}

			player_input_check();

			if (player_hit != 100) {

				if (map.real[player_hit] != 0 && (map.show[player_hit] != 'X' && map.show[player_hit] != 'O')) {
					cannon_balls--;
					error_msg = "\033[32m           - Hit! -\033[0m";
					if (map.real[player_hit] != 'X') {
						for (int x = 0; x < 17; x++) {
							if (total_hits[x] == 0) {
								total_hits[x] = 1;
								x = 17;
							}
						}
					}
					map.show[player_hit] = 'X';
				}
				else if (map.real[player_hit] == 0 && (map.show[player_hit] != 'X' && map.show[player_hit] != 'O')) {
					cannon_balls--;
					error_msg = "\033[31m          - Missed! -\033[0m";
					map.show[player_hit] = 'O';
				}
				else {
					error_msg = "\033[31m I've already hit that position\033[0m";
				}
			}
			else {
				if (ship_number == 0) {
					error_msg = "\033[31m       I don't understand\033[0m";
				}
			}

			if (total_hits[16] == 1) {
				map.display("", "\033[32m        We won captain! \033[0m", "", ship_number);
				system("pause");
				return true;
			}
			else if (cannon_balls <= 0) {
				map.display("", "\033[31mWe are out of cannonballs captain! \033[0m", "", ship_number);
				system("pause");
				return false;
			}
		}
	}

	bool battle_cpu() {

		std::random_device rd;
		std::default_random_engine rng(rd());

		player_hit = 100;
		player_input = "";
		error_msg = "";

		// To be used by CPU AI
		int cpu_number = 0;
		bool cpu_hit = false;
		int cpu_max_shot = 5;
		int cpu_shot = 0;
		int cpu_try = 0;
		int cpu_total_hits = 0;
		int cpu_verticality = 0;

		for (int x = 0; x < 17; x++) {
			total_hits[x] = { 0 };
		}

		// Player places down their ships
		for (int ship_amount = 0; ship_amount < 5; ship_amount++) {

			// ship[ship-length] = {position numbers}
			int current_ship[5] = {};
			int current_ship_length = 5;
			std::string current_ship_name = "";
			char current_ship_letter = ' ';

			if (ship_amount == 0) {
				current_ship_length = 5;
				current_ship_name = "Carrier";
				current_ship_letter = 'C';
			}
			else if (ship_amount == 1) {
				current_ship_length = 4;
				current_ship_name = "Battleship";
				current_ship_letter = 'B';
			}
			else if (ship_amount == 2) {
				current_ship_length = 3;
				current_ship_name = "Cruiser";
				current_ship_letter = 'R';
			}
			else if (ship_amount == 3) {
				current_ship_length = 3;
				current_ship_name = "Submarine";
				current_ship_letter = 'S';
			}
			else {
				current_ship_length = 2;
				current_ship_name = "Destroyer";
				current_ship_letter = 'D';
			}

			while (true) {

				// goto for restart
			reset:

				map.display_cpu("                      Please place down your " + current_ship_name + "(" + std::to_string(current_ship_length) + ")", "\033[32m                              Type a coordinate \033[0m", error_msg);
				std::getline(std::cin, player_input);

				player_input_check();

				if (player_hit != 100) {

					if (map.real_player[player_hit] == 0 && map.show_player[player_hit] == ' ') {
						error_msg = "";

						map.show_player[player_hit] = current_ship_letter;

						while (true)
						{
							// verticality(direction of the ship): 1 = up, 2 = right, 3 = down, 4 = left
							int verticality = 0;
							map.display_cpu("                          Please choose a direction.", "\033[32m                  Type a direction: Left, Right, Up or Down.\033[0m", error_msg);
							std::getline(std::cin, player_input);

							if (player_input == "left" || player_input == "Left" || player_input == "1") {
								verticality = 4;
							}
							else if (player_input == "right" || player_input == "Right" || player_input == "2") {
								verticality = 2;
							}
							else if (player_input == "up" || player_input == "Up" || player_input == "3") {
								verticality = 1;
							}
							else if (player_input == "down" || player_input == "Down" || player_input == "4") {
								verticality = 3;
							}
							else {
								error_msg = "\033[31m                              I don't understand\033[0m";
							}

							if (verticality != 0) {
								// cslmo: Current Ship Length Minus One
								int cslmo = current_ship_length - 1;

								// ship position
								int number = player_hit;

								// verticality check
								for (int x = 0; x < 100; x++) {

									current_ship[0] = number;

									// get the first digit of the rear
									int rightCheck = (number + cslmo) / 10;
									int leftCheck = (number - cslmo) / 10;
									int numberCheck = number / 10;

									if ((leftCheck != numberCheck && verticality == 4) || (rightCheck != numberCheck && verticality == 2) || (number - (cslmo * 10) < 0 && verticality == 1) || (number + cslmo > 99 && verticality == 2) || (number + (cslmo * 10) > 99 && verticality == 3) || (number - cslmo < 0 && verticality == 4)) {
										error_msg = "\033[31m                          That doesn't fit Captain!\033[0m";
										x = 0;
										map.show_player[player_hit] = ' ';
										goto reset;
									}

									if (verticality == 1) {
										current_ship[1] = number - 10;
										current_ship[2] = number - 20;
										current_ship[3] = number - 30;
										current_ship[4] = number - 40;
									}
									else if (verticality == 2) {
										current_ship[1] = number + 1;
										current_ship[2] = number + 2;
										current_ship[3] = number + 3;
										current_ship[4] = number + 4;
									}
									else if (verticality == 3) {
										current_ship[1] = number + 10;
										current_ship[2] = number + 20;
										current_ship[3] = number + 30;
										current_ship[4] = number + 40;
									}
									else {
										current_ship[1] = number - 1;
										current_ship[2] = number - 2;
										current_ship[3] = number - 3;
										current_ship[4] = number - 4;
									}

									// Final check
									if (map.real_player[x]) {
										for (int y = 0; y < current_ship_length; y++) {
											if (current_ship[y] == x) {
												error_msg = "\033[31m                              That doesn't fit captain!\033[0m";
												x = 0;
												map.show_player[player_hit] = ' ';
												goto reset;
											}
										}
									}
								}
								// Set the ship on the map
								for (int i = 0; i < current_ship_length; i++) {
									map.real_player[current_ship[i]] = ship_amount + 1;

									// Give the ships their position
									if (ship_amount == 0) {
										ships.carrier_player[i] = current_ship[i];
									}
									else if (ship_amount == 1) {
										ships.battleship_player[i] = current_ship[i];
									}
									else if (ship_amount == 2) {
										ships.cruiser_player[i] = current_ship[i];
									}
									else if (ship_amount == 3) {
										ships.submarine_player[i] = current_ship[i];
									}
									else {
										ships.destroyer_player[i] = current_ship[i];
									}
								}
								error_msg = "";
								break;
							}
						}
					}
					else {
						error_msg = "\033[31m                      I've already chosen that position.\033[0m";
						goto reset;
					}
				}
				else {
					error_msg = "\033[31m                              I don't understand\033[0m";
					goto reset;
				}

				break;
			}
		}

		error_msg = "\033[32m";
		map.display_cpu("                            The computer is ready.", "                            Let the battle begin!", error_msg);
		system("pause");
		std::cout << "\033[0m";
		error_msg = "";

		// Main loop
		while (true) {

			// Player loop
			while (true) {
				map.display_cpu("\033[32m                           Please type a coordinate.\033[0m", "", error_msg);
				std::getline(std::cin, player_input);
				player_input_check();
				if (player_hit != 100) {

					if (map.real[player_hit] != 0 && (map.show[player_hit] != 'X' && map.show[player_hit] != 'O')) {
						error_msg = "\033[32m                                   - Hit! -\033[0m";
						if (map.real[player_hit] != 'X') {
							for (int x = 0; x < 17; x++) {
								if (total_hits[x] == 0) {
									total_hits[x] = 1;
									x = 17;
								}
							}
						}
						map.show[player_hit] = 'X';
						break;
					}
					else if (map.real[player_hit] == 0 && (map.show[player_hit] != 'X' && map.show[player_hit] != 'O')) {
						error_msg = "\033[31m                                  - Missed! -\033[0m";
						map.show[player_hit] = 'O';
						break;
					}
					else {
						error_msg = "\033[31m                        I've already hit that position\033[0m";
					}
				}
				else {
					error_msg = "\033[31m                              I don't understand\033[0m";
				}

				if (total_hits[16] == 1) {
					return true;
				}

			}

			map.display_cpu("", error_msg, "");
			system("pause");
			map.display_cpu("", "\033[31m                             They enemy is firing!\033[0m", "");
			system("pause");

			// CPU AI

			bool cpu_guard1 = false;
			bool cpu_guard2 = false;
			bool cpu_guard3 = false;
			bool cpu_guard4 = false;
			int empty_spot_arr[100] = {};
			int empty_spot = 0;

			if (cpu_hit) {
				if (cpu_shot <= cpu_max_shot && !cpu_try && cpu_shot > 1) {
					std::cout << "\n  Lockdown\n";
					system("pause");
					if (cpu_verticality == 1) {
						cpu_number -= 10;
					}
					else if (cpu_verticality == 2) {
						cpu_number += 1;
					}
					else if (cpu_verticality == 3) {
						cpu_number += 10;
					}
					else {
						cpu_number -= 1;
					}
					if (map.show_player[cpu_number] == 'X' || map.show_player[cpu_number] == 'O' || cpu_number < 0 || cpu_number > 99) {
						for (int i = 0; i < 100; i++) {
							if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
								empty_spot_arr[empty_spot] = i;
								empty_spot++;
							}
						}

						empty_spot -= 1;
						std::uniform_int_distribution<> dist5(0, empty_spot);
						cpu_number = dist5(rng);
						cpu_number = empty_spot_arr[cpu_number];
						cpu_hit = false;
						cpu_try = 0;
						cpu_shot = 0;
					}
				}
				else if (!cpu_try && cpu_shot <= cpu_max_shot) {
					std::uniform_int_distribution<> dist2(1, 4);
					while (true) {
						std::cout << "\n  Second hit\n";
						system("pause");
						cpu_verticality = dist2(rng);
						if (cpu_verticality == 1) {
							if (map.show_player[cpu_number - 10] != 'X' && map.show_player[cpu_number - 10] != 'O' && cpu_number - 10 >= 0 && cpu_number - 10 <= 99) {
								cpu_number -= 10;
								break;
							}
							else {
								cpu_guard1 = true;
							}
						}
						else if (cpu_verticality == 2) {
							if (map.show_player[cpu_number + 1] != 'X' && map.show_player[cpu_number + 1] != 'O' && cpu_number + 1 >= 0 && cpu_number + 1 <= 99) {
								cpu_number += 1;
								break;
							}
							else {
								cpu_guard2 = true;
							}
						}
						else if (cpu_verticality == 3) {
							if (map.show_player[cpu_number + 10] != 'X' && map.show_player[cpu_number + 10] != 'O' && cpu_number + 10 >= 0 && cpu_number + 10 <= 99) {
								cpu_number += 10;
								break;
							}
							else {
								cpu_guard3 = true;
							}
						}
						else {
							if (map.show_player[cpu_number - 1] != 'X' && map.show_player[cpu_number - 1] != 'O' && cpu_number - 1 >= 0 && cpu_number - 1 <= 99) {
								cpu_number -= 1;
								break;
							}
							else {
								cpu_guard4 = true;
							}
						}

						if (cpu_guard1 && cpu_guard2 && cpu_guard3 && cpu_guard4) {
							for (int i = 0; i < 100; i++) {
								if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
									empty_spot_arr[empty_spot] = i;
									empty_spot++;
								}
							}

							empty_spot -= 1;
							std::uniform_int_distribution<> dist1(0, empty_spot);
							cpu_number = dist1(rng);
							cpu_number = empty_spot_arr[cpu_number];
							cpu_hit = false;
							cpu_try = 0;
							cpu_shot = 0;
							break;
						}
					}
				}
				else if (cpu_try && cpu_shot <= cpu_max_shot) {

					std::cout << "\n  Trying to lockdown\n";
					system("pause");

					if (cpu_verticality == 1) {
						cpu_number += 10;
					}
					else if (cpu_verticality == 2) {
						cpu_number -= 1;
					}
					else if (cpu_verticality == 3) {
						cpu_number -= 10;
					}
					else {
						cpu_number += 1;
					}
					std::uniform_int_distribution<> dist3(2, 4);
					std::uniform_int_distribution<> dist4(1, 3);
					while (true) {
						if (cpu_verticality == 1) {
							cpu_verticality = dist3(rng);
						}
						else if (cpu_verticality == 2) {
							cpu_verticality = dist4(rng);
							if (cpu_verticality == 1) {
								cpu_verticality = 1;
							}
							else if (cpu_verticality == 2) {
								cpu_verticality = 3;
							}
							else {
								cpu_verticality = 4;
							}
						}
						else if (cpu_verticality == 3) {
							cpu_verticality = dist4(rng);
							if (cpu_verticality == 1) {
								cpu_verticality = 1;
							}
							else if (cpu_verticality == 2) {
								cpu_verticality = 2;
							}
							else {
								cpu_verticality = 4;
							}
						}
						else {
							cpu_verticality = dist4(rng);
						}

						if (cpu_verticality == 1) {
							if (map.show_player[cpu_number - 10] != 'X' && map.show_player[cpu_number - 10] != 'O' && cpu_number - 10 >= 0 && cpu_number - 10 <= 99) {
								cpu_number -= 10;
								break;
							}
							else {
								cpu_guard1 = true;
							}
						}
						else if (cpu_verticality == 2) {
							if (map.show_player[cpu_number + 1] != 'X' && map.show_player[cpu_number + 1] != 'O' && cpu_number + 1 >= 0 && cpu_number + 1 <= 99) {
								cpu_number += 1;
								break;
							}
							else {
								cpu_guard2 = true;
							}
						}
						else if (cpu_verticality == 3) {
							if (map.show_player[cpu_number + 10] != 'X' && map.show_player[cpu_number + 10] != 'O' && cpu_number + 10 >= 0 && cpu_number + 10 <= 99) {
								cpu_number += 10;
								break;
							}
							else {
								cpu_guard3 = true;
							}
						}
						else {
							if (map.show_player[cpu_number - 1] != 'X' && map.show_player[cpu_number - 1] != 'O' && cpu_number - 1 >= 0 && cpu_number - 1 <= 99) {
								cpu_number -= 1;
								break;
							}
							else {
								cpu_guard4 = true;
							}
						}

						if (cpu_guard1 && cpu_guard2 && cpu_guard3 && cpu_guard4) {
							for (int i = 0; i < 100; i++) {
								if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
									empty_spot_arr[empty_spot] = i;
									empty_spot++;
								}
							}

							empty_spot -= 1;
							std::uniform_int_distribution<> dist1(0, empty_spot);
							cpu_number = dist1(rng);
							cpu_number = empty_spot_arr[cpu_number];
							cpu_hit = false;
							cpu_try = 0;
							cpu_shot = 0;
							break;
						}
					}
				}
				else {
					std::cout << "\n  3 checks failed, shooting randomly\n";
					system("pause");
					cpu_hit = false;
					cpu_try = 0;
					cpu_shot = 0;
					for (int i = 0; i < 100; i++) {
						if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
							empty_spot_arr[empty_spot] = i;
							empty_spot++;
						}
					}

					empty_spot -= 1;
					std::uniform_int_distribution<> dist1(0, empty_spot);
					cpu_number = dist1(rng);
					cpu_number = empty_spot_arr[cpu_number];
				}
			}
			else {
				std::cout << "\n  Shooting randomly\n";
				system("pause");
				for (int i = 0; i < 100; i++) {
					if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
						empty_spot_arr[empty_spot] = i;
						empty_spot++;
					}
				}

				empty_spot -= 1;
				std::uniform_int_distribution<> dist1(0, empty_spot);
				cpu_number = dist1(rng);
				cpu_number = empty_spot_arr[cpu_number];

			}

			if (map.show_player[cpu_number] == 'X' || map.show_player[cpu_number] == 'O' || cpu_number < 0 || cpu_number > 99) {
				std::cout << "\n  Everything failed, shooting randomly\n";
				system("pause");
				for (int i = 0; i < 100; i++) {
					if (map.show_player[i] != 'X' && map.show_player[i] != 'O') {
						empty_spot_arr[empty_spot] = i;
						empty_spot++;
					}
				}

				empty_spot -= 1;
				std::uniform_int_distribution<> dist1(0, empty_spot);
				cpu_number = dist1(rng);
				cpu_number = empty_spot_arr[cpu_number];
			}

			if (map.real_player[cpu_number] != 0) {
				if (cpu_try) {
					cpu_try = 0;
				}
				error_msg = "\033[31m                              We are hit Captain!\033[0m";
				map.show_player[cpu_number] = 'X';
				cpu_hit = true;
				cpu_shot++;
				if (cpu_shot == 5) {
					cpu_max_shot = 4;
				}
				else if (cpu_shot == 4 && cpu_max_shot == 4) {
					cpu_max_shot = 3;
				}
				cpu_total_hits++;
			}
			else {
				error_msg = "\033[32m                              They Missed Captain!\033[0m";
				map.show_player[cpu_number] = 'O';

				if (cpu_hit) {
					cpu_try++;
				}
			}

			if (cpu_total_hits == 17) {
				return false;
			}
		}
	}
}game;