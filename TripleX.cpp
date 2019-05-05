#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) 
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "Enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 2 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiple to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
    
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clear any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";

    return 0;
}