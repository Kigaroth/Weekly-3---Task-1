// Weekly 3 - Task 1.cpp //

#include <iostream>
#include <cstdlib>
#include <ctime>

int rand_num_test = 10;
int rand_num;
int input_guess;
int input_guess2;
int count_guesses;
int score = 1010;
int highscore = 0;
int difficulty;
int players;
int retry;
int player_two_number;



int main()
{
    std::cout << "\t Guessing game!\n\n";

    //Number of players//

    std::cout << " How many players are playing?\n\t 1. One player \n\t 2. Two players \n Please pick an option by typing 1 or 2: ";
    std::cin >> players;
    std::cout << std::endl;

    system("CLS");

    //One player game//

    if (players == 1) {
        do {
            std::cout << "\t Guessing game!\n\n";
            std::cout << " Please select a difficulty level: \n\t 1. Easy (1-5) \n\t 2. Medium (1-10) \n\t 3. Hard (1-30) \n\t 4. Very hard (1-50) \n Please select a difficulty 1-4: ";
            std::cin >> difficulty;
            std::srand(static_cast<unsigned int>(std::time(nullptr)));

            if (difficulty == 1) {              
                rand_num = std::rand() % 5 + 1;
            }
            else if (difficulty == 2) {
                rand_num = std::rand() % 10 + 1;
            }
            else if (difficulty == 3) {
                rand_num = std::rand() % 30 + 1;
            }
            else if (difficulty == 4) {
                rand_num = std::rand() % 50 + 1;
            }

            system("CLS");
            std::cout << "\t Guessing game!\n\n";

            do {
                std::cout << " Guess a number: ";
                std::cin >> input_guess;
                count_guesses++;
                score -= 10;

                if (input_guess < rand_num) {
                    std::cout << " That's too low! Try again!" << std::endl;
                }
                else if (input_guess > rand_num) {
                    std::cout << " That's too high! Try again!" << std::endl;
                }
                else if (input_guess == rand_num) {
                    std::cout << std::endl;
                    std::cout << "\t That's correct! Congratulations!" << std::endl;
                    std::cout << "\t You guessed the number in: " << count_guesses << " guesses. Well done!" << std::endl << std::endl;
                    std::cout << "\t Your score is: " << score << " points out of 1000." << std::endl;

                    if (score > highscore) {
                        highscore = score;
                        std::cout << "\t Congratulations, you've got the new highscore!" << std::endl << std::endl;
                        std::cout << "\t The highscore is now: " << highscore << " points out of 1000.";
                    }
                    else if (score == highscore) {
                        highscore = score;
                        std::cout << "\t Congratulations, you've matched the highscore!" << std::endl << std::endl;
                        std::cout << "\t The highscore is now: " << highscore << " points out of 1000.";
                    }
                    else {
                        std::cout << "\t Sorry, you didn't beat the highscore. Try again!" << std::endl << std::endl;
                        std::cout << "\t The current highscore is: " << highscore << " points out of 1000.";
                    }

                }
            } while (input_guess != rand_num);

            std::cout << std::endl;
            std::cout << "\n Try again?\n\t1. Yes\n\t2. No\n Please pick an option by typing 1 or 2: ";
            std::cin >> retry;
            count_guesses = 0;
            score = 1010;
            system("CLS");

        } while (retry != 2);

        if (retry == 2) {
            system("CLS");
            std::cout << " Thank you for playing! :)";
        }
    }

    //Two player game//

    if (players == 2) {
        do {
            std::cout << "\t Guessing game!\n\n";
            do {
                std::cout << "\n Player two, please input a number that you want player one to guess (Min number 1, Max number 30): ";
                std::cin >> player_two_number;
                if (player_two_number == 0 || player_two_number > 30) {
                    std::cout << " That number is invalid. Try again!";
                }
            } while (player_two_number == 0 || player_two_number > 30);

            system("CLS");
            std::cout << "\t Guessing game!\n\n";

            do {
                std::cout << " Player one, Guess a number: ";
                std::cin >> input_guess2;
                count_guesses++;
                score -= 10;

                if (input_guess2 < player_two_number) {
                    std::cout << " That's too low! Try again!" << std::endl;
                }
                else if (input_guess2 > player_two_number) {
                    std::cout << " That's too high! Try again!" << std::endl;
                }
                else if (input_guess2 == player_two_number) {
                    std::cout << std::endl;
                    std::cout << "\t That's correct! The number player two made you guess was " << player_two_number << "Congratulations!" << std::endl;
                    std::cout << "\t Player one guessed the number in: " << count_guesses << " guesses. Well done!" << std::endl << std::endl;
                    std::cout << "\t Your score is: " << score << " points out of 1000." << std::endl;

                    if (score > highscore) {
                        highscore = score;
                        std::cout << "\t Congratulations, you've got the new highscore!" << std::endl << std::endl;
                        std::cout << "\t The highscore is now: " << highscore << " points out of 1000.";
                    }
                    else if (score == highscore) {
                        highscore = score;
                        std::cout << "\t Congratulations, you've matched the highscore!" << std::endl << std::endl;
                        std::cout << "\t The highscore is now: " << highscore << " points out of 1000.";
                    }
                    else {
                        std::cout << "\t Sorry, you didn't beat the highscore. Try again!" << std::endl << std::endl;
                        std::cout << "\t The current highscore is: " << highscore << " points out of 1000.";
                    }

                }
            } while (input_guess2 != player_two_number);

            std::cout << std::endl;
            std::cout << "\n Try again?\n\t1. Yes\n\t2. No\n Please pick an option by typing 1 or 2: ";
            std::cin >> retry;
            count_guesses = 0;
            score = 1010;
            system("CLS");

        } while (retry != 2);

        if (retry == 2) {
            system("CLS");
            std::cout << " Thank you for playing! :)";
        }
    }

    return 0;
} 
