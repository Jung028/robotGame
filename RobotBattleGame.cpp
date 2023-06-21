#include <iostream>
#include <cstdlib>
#include <ctime>
#include "robot.h"

int main() {
    srand(time(nullptr));

    do {
        Robot player1;
        Robot player2;

        printArena(player1, player2);

        // Game loop
        while (player1.getHealth() > 0 && player2.getHealth() > 0) {
            // Player 1's turn
            int player1Choice;
            std::cout << "Player 1, choose your action (1-4, 0 to exit): ";
            std::cin >> player1Choice;

            switch (player1Choice) {
                case 0:
                    std::cout << "Exiting the game..." << std::endl;
                    return 0;
                case 1:
                    player1.powerUp();
                    break;
                case 2:
                    player1.speedUp(player2);
                    break;
                case 3:
                    player1.attack(player2);
                    break;
                case 4:
                    player1.superAttack(player2);
                    break;
                default:
                    std::cout << "Invalid choice! Please try again." << std::endl;
                    continue;
            }

            printArena(player1, player2);

            // Check if Player 2 is defeated
            if (player2.getHealth() <= 0) {
                std::cout << "Player 1 wins!" << std::endl;
                player1.setScoreA(player1.getScoreA() + 1);
                break;
            }

            // Player 2's turn
            int player2Choice;
            std::cout << "Player 2, choose your action (1-4, 0 to exit): ";
            std::cin >> player2Choice;

            switch (player2Choice) {
                case 0:
                    std::cout << "Exiting the game..." << std::endl;
                    return 0;
                case 1:
                    player2.powerUp();
                    break;
                case 2:
                    player2.speedUp(player1);
                    break;
                case 3:
                    player2.attack(player1);
                    break;
                case 4:
                    player2.superAttack(player1);
                    break;
                default:
                    std::cout << "Invalid choice! Please try again." << std::endl;
                    continue;
            }

            printArena(player1, player2);

            // Check if Player 1 is defeated
            if (player1.getHealth() <= 0) {
                std::cout << "Player 2 wins!" << std::endl;
                player2.setScoreB(player2.getScoreB() + 1);
                break;
            }
        }
    } while (playAgain());

    return 0;
}
