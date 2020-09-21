// Weekly 3 - Task 1.cpp //

#include <iostream>
#include <cstdlib>

int rand_num = 10;
int input_guess;
int count_guesses;
int score = 1010;
int highscore = 0;
int difficulty;
int players;
int retry;


int main()
{
    std::cout << "\t Guessing game!\n\n";

    //Number of players//

    std::cout << " How many players are playing?\n\t 1. One player \n\t 2. Two players \n Please pick an option by typing 1 or 2: ";
    std::cin >> players;
    std::cout << std::endl;

    //Difficulty select//
    std::cout << " Please select a difficulty level: \n\t 1. Easy (1-5) \n\t 2. Medium (1-10) \n\t 3. Hard (1-30) \n Please select a difficulty 1-3: ";
    std::cin >> difficulty;
    system("CLS");

    //Main game//

    do{
        std::cout << "\t Guessing game!\n\n";

        do {
            std::cout << " Guess a number between 1 and 10: ";
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

    return 0;
} 
