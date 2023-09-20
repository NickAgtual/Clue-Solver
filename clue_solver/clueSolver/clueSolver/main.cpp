#include <iostream>
#include <vector>
#include <string>


class Player {
    
    public:
        std::string name;
        int numCards;
};

struct gameData{
    int numPlayers;
    const int totalCards = 21;
    int extraCards;
    std::vector<std::string> names;
    std::vector<Player> playerObjects;
};

void instantiateObjects(gameData &game) {
    switch (game.numPlayers) {
        case 2:
            {
                Player player1;
                game.playerObjects.push_back(player1);
                Player player2;
                game.playerObjects.push_back(player2);
            }
            break;
        case 3:
            {
                Player player1;
                game.playerObjects.push_back(player1);
                Player player2;
                game.playerObjects.push_back(player2);
                Player player3;
                game.playerObjects.push_back(player3);
            }
            break;
        case 4:
            {
                Player player1;
                game.playerObjects.push_back(player1);
                Player player2;
                game.playerObjects.push_back(player2);
                Player player3;
                game.playerObjects.push_back(player3);
                Player player4;
                game.playerObjects.push_back(player4);
            }
            break;
        case 5:
            {
                Player player1;
                game.playerObjects.push_back(player1);
                Player player2;
                game.playerObjects.push_back(player2);
                Player player3;
                game.playerObjects.push_back(player3);
                Player player4;
                game.playerObjects.push_back(player4);
                Player player5;
                game.playerObjects.push_back(player5);
            }
            break;
        case 6:
            {
                Player player1;
                game.playerObjects.push_back(player1);
                Player player2;
                game.playerObjects.push_back(player2);
                Player player3;
                game.playerObjects.push_back(player3);
                Player player4;
                game.playerObjects.push_back(player4);
                Player player5;
                game.playerObjects.push_back(player5);
                Player player6;
                game.playerObjects.push_back(player6);
            }
            break;
    }
}

void assignNames(gameData &game) {
    std::cout << "Enter player names separated by a space" << std::endl;
    for (int ii = 0; ii < game.numPlayers; ii++) {
        std::string tempName;
        std::cin >> tempName;
        game.names.push_back(tempName);
        game.playerObjects[ii].name = game.names[ii];
    }
}

void extraCard(gameData &game) {
    // Number of extra cards
    int extra = game.totalCards % game.numPlayers;
    int cardDistribution = game.totalCards / game.numPlayers;
    std::string extraCardHolders;
    
    for (int ii = 0; ii < extra; ii++) {
        std::cout << "Enter the players' name with extra cards [" << extra << " player(s)]" << std::endl;
        std::cin >> extraCardHolders;
    }
     
    for (int ii = 0; ii < game.numPlayers; ii++) {
        game.playerObjects[ii].numCards = cardDistribution;
        if (game.playerObjects[ii].name == extraCardHolders) {
            game.playerObjects[ii].numCards ++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    struct gameData game;
    
    std::cout << "Enter the number of players including yourself:" << std::endl;
    std::cin >> game.numPlayers;
    
    instantiateObjects(game);
    
    assignNames(game);
    
    extraCard(game);

    
    for (int ii=0; ii < game.numPlayers; ii++) {
        std::cout << game.playerObjects[ii].numCards << " \t";
    }

}
