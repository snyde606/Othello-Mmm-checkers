// Look at me. I am the captain now
// Captains don't take naps

#include "player.hpp"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    this->mmmBoard = Board();
    this->side = side;
    this->opponentSide = BLACK;
    if(side == BLACK)
		this->opponentSide = WHITE;

}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    
    this->mmmBoard.doMove(opponentsMove, opponentSide);
    
    vector<Move>* avMoves = mmmBoard.availableMoves(this->side);
    
    int bestWorst = -1000000;
    Move* bestMove = nullptr;
    for(int i = 0; i < avMoves->size(); i++){
		Board* copyB = mmmBoard.copy();
		copyB->doMove(&(avMoves->at(i)), side);
		int worst = 100000;
		vector<Move>* enemAvMoves = copyB->availableMoves(opponentSide);
		for(int j = 0; j < enemAvMoves->size(); j++){
			Board* copyB2 = copyB->copy();
			copyB2->doMove(&(enemAvMoves->at(j)), opponentSide);
			int trying = copyB2->getScore(side);
			if(trying < worst)
				worst = trying;
		}
		if(bestWorst < worst){
			bestWorst = worst;
			bestMove = &(avMoves->at(i));
		}
	}
	
	this->mmmBoard.doMove(bestMove, side);
    
    return bestMove;
}
