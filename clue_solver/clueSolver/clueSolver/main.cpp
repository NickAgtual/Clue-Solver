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
    std::vector<std::vector<int>> inHand;
    std::vector<std::vector<int>> notInHand;
    std::vector<std::vector<int>> checkVals;
    std::vector<int> solution;
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

std::vector<int> getIndeces(std::vector<int> vector) {
    std::vector<int> indexVector;
    for (int ii = 0; ii < vector.size(); ii++) {
        if (vector[ii] == 0) {
            indexVector.push_back(ii);
        }
    }
    return indexVector;
}

void initialHand(gameData &game) {
    int tempKey;
    std::cout << "Enter the key values for the cards in your hand delimited by a space" << std::endl;
    std::cin >> tempKey;
    for (int ii = 0; ii < game.playerObjects[0].numCards; ii++) {
        game.inHand[0][tempKey] = 1;
    }
    
    std::vector<int> tempIndex;
    tempIndex = getIndeces(game.inHand[0]);
    for (int ii = 0; ii < tempIndex.size(); ii++) {
        game.notInHand[0][ii] = 1;
    }
}

int main(int argc, const char * argv[]) {
    
    struct gameData game;
    
    std::cout << "Enter the number of players including yourself:" << std::endl;
    std::cin >> game.numPlayers;
    
    // Initializing vectors of vectors in structure with zeros (21, numPlayers)
    game.inHand.resize(game.totalCards, std::vector<int>(game.numPlayers, 0));
    game.notInHand.resize(game.totalCards, std::vector<int>(game.numPlayers, 0));
    game.checkVals.resize(game.totalCards, std::vector<int>(game.numPlayers, 0));
    // Initializing solution vector with zeros (21, 1)
    game.solution.resize(game.totalCards, 0);
    
    // Instnatiating player objects
    instantiateObjects(game);
    
    // Assigning names to player objects
    assignNames(game);
    
    /*
     Calclating the number of cards each player has and assigning the extra cards
     based on user input
     */
    extraCard(game);
    
    // Entering card data for intial hand
    initialHand(game);

}

