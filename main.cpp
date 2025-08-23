#include <iostream>
#include <ctime>

//Function protoypes
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char opponent); //Opponent is Computer or Player 2
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1;
    char player2;
    char choice;
    bool running = true;
    int mode;

    std::cout << "===Tic-Tac-Toe===\n";
    std::cout << "1. Single Player\n";
    std::cout << "2. 2 Player\n";
    std::cout << "Which mode do you want to play?: ";
    std::cin >> mode;

    if(mode == 1){ //Single Player Mode
        std::cout << "Would you like to be X or O?: ";
        std::cin >> choice;

        player1 = choice;
        
        switch(toupper(choice)){
            case 'X':
                player2 = 'O';
                break;
            case 'O':
                player2 = 'X';
                break;
            default:
                std::cout << "Invalid choice.";
                return 0;
        }

        drawBoard(spaces); //Display the blank slate

        while(running){
            playerMove(spaces, player1);
            drawBoard(spaces); //Redraw board with updated moves

            if(checkWinner(spaces, player1, player2) || checkTie(spaces)){
                running = false;
                break;
            }

            computerMove(spaces, player2);
            drawBoard(spaces); //Redraw board with updated moves

            if(checkWinner(spaces, player1, player2) || checkTie(spaces)){
                running = false;
                break;
            }
        }
    }
    else if(mode == 2){ //2 Player Mode
        //Just default for now
        player1 = 'X';
        player2 = 'O';

        drawBoard(spaces); //Display the blank slate

        while(running){
            std::cout << "Player 1 (" << player1 << ")\n";
            playerMove(spaces, player1);
            drawBoard(spaces); //Redraw board with updated moves

            if(checkWinner(spaces, player1, player2) || checkTie(spaces)){
                running = false;
                break;
            }

            std::cout << "Player 2 (" << player2 << ")\n";
            playerMove(spaces, player2);
            drawBoard(spaces); //Redraw board with updated moves

            if(checkWinner(spaces, player1, player2) || checkTie(spaces)){
                running = false;
                break;
            }
        }
    }
    else{
        std::cout << "Invalid mode.\n";
    }

    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  \n";
    std::cout << "     |     |     \n";
    std::cout << '\n';
}

void playerMove(char *spaces, char player){
    int number;
    do{
        std::cout << "Select 1-9: ";
        std::cin >> number;
        number--; //Since we start at 0, we need to decrement the player's choice for computer to appropriately assign the marker

        if(number >= 0 && number < 9 && spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
        else{
            std::cout << "Invalid move.";
        }

    }while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char opponent){ //NEED TO CHANGE OUTPUTS
    //Rows
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    //Columns
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    //Diagonals
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? std::cout << "You Win!\n" : std::cout << "Computer Wins!\n";
    }
    else{
        return false; //Nobody wins (i.e. Tie game)
    }
    return true;
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    
    std::cout << "Tie Game!\n";
    return true;
}