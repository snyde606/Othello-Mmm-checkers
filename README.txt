Jacob wrote doMove, getScore, initialized board

Lauren wrote availableMoves, optimized score weights to beat 
ConstantTimePlayer and BetterPlayer

We changed the score weights of different positions on the board 
(e.g. assigning very high point value to corners, very low value to places 
adjacent to corners) so that our bot would be more likely to make advantageous 
moves. We tried ambitious weighting of different tiles that did not turn 
out to be beneficial. 