#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include "MainH.h"

int main() {

	// goto for restart
game_start:

	// Increase font size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// Fill in the map
	for (int i = 0; i < 100; i++) {
		map.show[i] = { ' ' };
		map.real[i] = { 0 };
		map.show_player[i] = { ' ' };
		map.real_player[i] = { 0 };
	}

	// Randomly place down ships
	ships.place();

	// Game loop
	while (true) {

		std::string error_msg = "";
		std::string player_input = "";

		// Title screen loop
		while (true) {
			display.title_screen(error_msg);
			std::getline(std::cin, player_input);

			if (player_input == "campaign" || player_input == "Campaign" || player_input == "1") {
				error_msg = "";
				game.mode = "campaign";
				break;
			}
			else if (player_input == "cpu" || player_input == "Cpu" || player_input == "2") {
				error_msg = "";
				game.mode = "cpu";
				break;
			}
			else if (player_input == "quit" || player_input == "Quit" || player_input == "3") {
				return 0;
			}
			else {
				error_msg = "\033[31m        I don't understand\033[0m";
			}
		}

		if (game.mode == "campaign") {
			// Difficulty loop
			while (true) {
				display.difficulty(error_msg);
				std::getline(std::cin, player_input);

				if (player_input == "easy" || player_input == "Easy" || player_input == "1") {
					error_msg = "";
					game.cannon_balls = 52;
					break;
				}
				else if (player_input == "normal" || player_input == "Normal" || player_input == "2") {
					error_msg = "";
					game.cannon_balls = 42;
					break;
				}
				else if (player_input == "hard" || player_input == "Hard" || player_input == "3") {
					error_msg = "";
					game.cannon_balls = 32;
					break;
				}
				else {
					error_msg = "\033[31m        I don't understand\033[0m";
				}
			}

			// Campaign loop
			while (true) {
				display.story();
				if (!game.battle()) {

					goto game_start;
				}
				display.story2();
				goto game_start;
			}
		}
		else if (game.mode == "cpu") {
			if (!game.battle_cpu()) {
				system("CLS");
				map.display_cpu("", "\033[31m                  Abandon ship! All of our ships are sinking!\033[0m", "");
				system("pause");
				goto game_start;
			}
			else {
				system("CLS");
				map.display_cpu("", "\033[32m                       All the enemy ships are defeated.\033[0m", "");
				system("pause");
				goto game_start;
			}
		}
	}

	return 0;
}