#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef enum
{
    Rock,
    Paper,
    Scissor,
    Invalid
} input_choices_t;

typedef enum
{
    Win,
    Lose,
    Draw
} player_state_t;


void recive_num_of_Rounds(int &n)
{
    cout << "Enter Number Of Rounds: ";
    cin >> n;
    cout << endl;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

input_choices_t computer_choice()
{
    input_choices_t computer_state = (input_choices_t)RandomNumber(0, 2);
    return computer_state;
}

bool validate_string(string str)
{
    if (str.length() > 1)
    {
        return false;
    }
    return true;
}

input_choices_t recive_player_choise()
{
    string player_choise;
    bool IsValid;
    input_choices_t return_val;

    cout << "Enter (R/r) For Rock (P/p) For Paper (S/s) For Scissor : ";

    getline(cin, player_choise);
    IsValid = validate_string(player_choise);
    if (!IsValid)
    {
        return Invalid;
    }

    if (player_choise == "r" || player_choise == "R")
    {
        return_val = Rock;
    }
    else if (player_choise == "p" || player_choise == "P")
    {
        return_val = Paper;
    }
    else if (player_choise == "s" || player_choise == "S")
    {
        return_val = Scissor;
    }
    else
        return_val = Invalid;

    return return_val;
}

player_state_t checking(input_choices_t player_ch, input_choices_t pc_ch)
{
    if (player_ch == pc_ch)
        return Draw;
    if ((player_ch == Rock && pc_ch == Scissor) ||
        (player_ch == Scissor && pc_ch == Paper) ||
        (player_ch == Paper && pc_ch == Rock))
    {
        return Win;
    }
    return Lose;
}

void printing_round_state(player_state_t pl_s)
{
    if (pl_s == Win)
    {
        cout << "\033[42m";
        cout << "You Won" << endl;
        cout << "\033[2J";
        cout << "\033[H";
    }
    else if (pl_s == Lose)
    {
        cout << "Computer Win" << endl;
        cout << "\033[41m";
        cout << "\033[2J";
        cout << "\033[H";
    }
    else
    {
        cout << "Draw" << endl;
        cout << "\033[43m";
        cout << "\033[2J";
        cout << "\033[H";
    }
}

void start_Game()
{
    int number_of_rounds;
    int player_wins = 0, computer_wins = 0, draws = 0;
    bool again = true;
    while (again)
    {
    recive_num_of_Rounds(number_of_rounds);
    player_state_t player_s;
    for (int i = 0; i < number_of_rounds; i++)
    {
        input_choices_t com_ch, player_ch;
        com_ch = computer_choice();

        player_ch = recive_player_choise();
        while (player_ch == Invalid)
        {
            player_ch = recive_player_choise();
        }
        player_s = checking(player_ch, com_ch);
        switch (player_s)
        {
        case Win:
            player_wins++;
            break;
        case Lose:
            computer_wins++;
            break;
        case Draw:
            draws++;
            break;
        }
        cout << "Computer choice: "
             << ((com_ch == 0) ? "Rock" : (com_ch == 1 ? "Paper" : "Scissor"))
             << endl;
        cout << "--------------------------------------------------------------" << endl;
        printing_round_state(player_s);
    }
    cout << "=============(Final RESULT)==============" << endl;
    cout << "You Wins (" << player_wins << ") time(s)" << endl;
    cout << "Pc Wins (" << computer_wins << ") time(s)" << endl;
    cout << "Number Of Draw (" << draws << ") time(s)" << endl;
    cout << "=========================================" << endl;

    
        cout << "Wanna Play Again :)?  (Yes = 1) (No = 0)" << endl;
        cin >> again;
        
    }
}

int main()
{
    srand((unsigned)time(NULL));

    start_Game();
    return 0;
}