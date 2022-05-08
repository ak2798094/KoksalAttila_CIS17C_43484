/** 
 * @file:   main.cpp
 * @author: Attila Koksal
 * @date: Created on April 6, 2022, 7:30 PM
 * Purpose:  CPP Template 
 */

///System Libraries
///I/O Library
#include <iostream> 
///Iomanip Library
#include<iomanip>
///ValArray Library
#include <valarray>
///CMath Library
#include <cmath>
#include <iterator>
#include <map>
using namespace std;
///number of rows in the chess board
const int ROW=8; 
///number of columns in the chess board
const int COLUMN=8;
///display name for different pieces for board use
const string pieceNames[7]={"pwn","rok","bsh","kgh","qun","kng","____"};

///Piece represents all possible values of a spot on a board can be, in traditional board, its spot can be either red or yellow, or empty. Here we use X and O to represent yellow and empty
enum Piece{
    Pawn=0,
    Rook=1,
    Bishop=2,
    Knight=3,
    Queen=4,
    King=5,
    Empty=6
};

///@class 
///@brief the player that on a space/square (can be none if empty)
enum Color{
    WHITE,
    BLACK,
    NONE
};

///a space on the board
class Space{ 
    Piece value;
    Color color;
    
public:
    ///@brief get which player is this space on the board
    ///@return the color user requested
    Color getColor();
    
    ///@brief get which piece is this space on the board
    ///@return the piece at that location
    Piece getValue();
 
    ///@brief set what piece is on this space
    void setValue(Piece,Color);
    
};

struct Coordinate{
    ///a x/row coordinate
    int x;
    ///a y/column coordinate
    int y;
    ///compares to coordinates
    bool operator==(const Coordinate& other)const{
        return (x==other.x&&y==other.y);
    }
};

///@class a super class that be inherited on any game including the previews project one if desired
class Game{
private:
    ///player1's name
    string player1="";
    ///player2's name
    string player2="";
public:
    ///declare the winner of the game
    ///@brief display who the winner is
    ///@param winner 0 is player 1 won, 1 if player 2 won 
    void announceWinner(int winner){
        string winnerName="";
        if(winner==0){
            ///set winner name
            winnerName=player1;
        }
        else{
            ///set winner name
            winnerName=player2;
        }
        ///declare winner
        cout<<"Congratulations, the winner is "<<winnerName<<endl;
    }
    
    ///@brief set player name
    ///@param playerNumber 0 for player 1, 1 for player2
    ///@param name the name to set to
    void setPlayerName(int playerNumber,string name){
        if(playerNumber==0){
            player1=name;
        }
        else if(playerNumber==1){
            player2=name;
        }
    }
    
    ///@brief get player name
    ///@param playerNumber 0 for player 1, 1 for player 2
    ///@return name of the string
    string getPlayerName(int playerNumber){
        if(playerNumber==0){
            return player1;
        }
        else if(playerNumber==1){
            return player2;
        }
        else{
            return "Player Name";
        }
    }
    ///@brief find out which item is larger 
    ///@tparam T is template param
    ///@returns 0 if first parameter is larger, 1 if second parameter is larger, -1 if tie
    template<typename T>
    int maxItem(T a,T b){
        if(a>b){
            return 0;
        }
        else if(b>a){
            return 1;
        }
        else{
            return -1;
        }
    }
    
    ///@brief menu for users to interact 
    ///@param input is number for which menu item to be called
    ///this function can be overwritten by subclasses if desired
    void menu(int input){ 
        if(input==0){
            cout<<"Welcome to this game. For information, please select one of the following options below: "<<endl;
            cout<<"'M 1': Display Game Creator Information"<<endl;
            cout<<"'M 2': Display Players"<<endl;
        }
        else if(input==1){
            cout<<"The game was developed by Attila Koksal for the CSC-17A final project."<<endl;
        }
        else if(input==2){
            cout<<"The players of this game are: "<<endl;
            cout<<"Player 1: "<<player1<<endl;
            cout<<"Player 2: "<<player2<<endl;
        }
        else{
            cout<<"Sorry, incorrect input."<<endl;
        }
    }
};

///@class this class simulates the game board using multiple functions
class Board:public Game{
    ///the board
    Space board[ROW][COLUMN];
    ///The color's turn that is in effect
    Color turn=WHITE;
    ///Checks if check has occurred
    bool check=false;
    ///Number of turns of total game played so far
    int numberOfTurns=0;
    ///Tracks if it's castleable for all four locations
    bool castleAble[2][2]={{true,true},{true,true}};
public:
    ///Tracks the winner
    int winner=-1;
    //initializes the game board
    void initializeBoard();
    //returns a specific space on the board
    Space* getSpace(Coordinate);
    //moves a piece according to the player's decision
    void movePiece(Color);
    //prints the game board
    void printBoard();
    //sets a piece with a designated coordinate, piece type, and color on the game board
    void setPiece(Coordinate,Piece,Color);
    //adds space coordinates that a piece can move to in a direction
    void searchAndAdd(Coordinate[],int &,Coordinate,int,int,bool);
    //finds the attack squares of all the pieces on the board of the same color
    void findAttackSquares(Coordinate[],int &,Color);
    //checks if one of the two colors in the game is in check
    bool isUnderCheck(Color);
    //gets the movable locations where a piece can move
    void getMovableLocations(Coordinate[],int &,Coordinate,Color);
    //gets all the movable locations where a piece can move
    void getAllMovableLocations(Coordinate[],int &,Color);
    //displays the winning player's status to the screen
    void displayWinningStatus();
    ///@brief check if the move that is made is an attempt to castle
    ///@param from coordpiece moved from
    ///@param toY y coordinate to move to 
    ///@return true if ttrying to castle
    bool castleAttempt(Coordinate from,int toY){
        Piece movingPiece=getSpace(from)->getValue();
        if(movingPiece!=King){
            return false;
        }
        else if(movingPiece==King){
            if(from.y!=4){
                return false;
            }
            else if(toY==6||toY==2){
                return true;
            }
        }
        return true;
    }
  	///@brief announces the winner of the game
  	///@param winner the player who is victorious at the end of the game
    void announceWinner(int winner){
        string winnerName="";
        string player1=getPlayerName(0);
        string player2=getPlayerName(1);
        string color="";
        
        if(winner==0){
            winnerName=player1;
            color="WHITE";
        }
        else{
            winnerName=player2;
            color="BLACK";
        }
        cout<<"Congratulations! The winner is "<<winnerName<<", who is playing the color "<<color<<"."<<endl;
    }
  	///@brief increases the number of turns
    void increaseNumberOfTurns(){
        numberOfTurns++;
    }
  	///@brief displays a game menu on the screen
  	///@param input gets an input from the user depending on the user's desire
    void menu(int input){
        string player1=getPlayerName(0);
        string player2=getPlayerName(1);
        if(input==0){
            cout<<"Welcome to this game. For information, please select one of the following options below: "<<endl;
            cout<<"'M 1': Display Game Creator Information"<<endl;
            cout<<"'M 2': Display Players"<<endl;
            cout<<"'M 3': Display Current Winning Player Lead Status"<<endl;
            cout<<"'M 4': Display Current Number of Turns"<<endl;
            cout<<"'M 5': Display Board"<<endl;
            cout<<"'M 6': Display Castle Instruction"<<endl;
        }
        else if(input==1){
            cout<<"The game was developed by Attila Koksal for the CSC-17A final project."<<endl;
        }
        else if(input==2){
            cout<<"The players of this game are: "<<endl;
            cout<<"Player 1: "<<player1<<endl;
            cout<<"Player 2: "<<player2<<endl;
        }
        else if(input==3){
            displayWinningStatus();
        }
        else if(input==4){
            cout<<"Current Number of Turns: "<<numberOfTurns<<endl;
        }
        else if(input==5){
            printBoard();
        }
        else if(input==6){
            cout<<"Castle Instructions: "<<endl;
            cout<<"Short Castle: Move WHITE King to G 1 OR Move BLACK King to G 8 when allowed to castle"<<endl;
            cout<<"Long Castle: Move WHITE King to C 1 OR Move BLACK King to C 8 when allowed to castle"<<endl;
        }
        else{
            cout<<"Sorry, incorrect input."<<endl;
        }
    }
};

//main function
int main(int argc, char** argv) {
    
    map<string,string> pieceMove;
    
    pieceMove.insert(pair<string, string>("Pawn", "Can move once forward on captures or moves"));
    pieceMove.insert(pair<string, string>("Rook", "Can move horizontally or vertically any number of spaces but can't jump over pieces"));
    pieceMove.insert(pair<string, string>("Knight", "Moves in an L shape with a limit of two spaces and then one space but in any direction"));
    pieceMove.insert(pair<string, string>("Bishop", "Can move diagonally only for any number of spaces but can't jump over pieces"));
    pieceMove.insert(pair<string, string>("Queen", "Can move diagonally, horizontally, or vertically for any number of spaces but can't jump over pieces"));
    pieceMove.insert(pair<string, string>("King", "Can move one space any direction so long as that one space is not being attacked by an enemy piece"));
    
    map<string,string>::iterator itr;
    cout<<"Here is some useful information about what each piece in chess can do and cannot."<<endl;
    cout<<"\tPiece\tMovement"<<endl;
    
    for (itr = pieceMove.begin(); itr != pieceMove.end(); ++itr) {
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<endl;
    }
    cout<<endl;
    
    //creates a board from the Board class
    Board board;
    //initializes the board
    board.initializeBoard();
  	//prints the board
    board.printBoard();
  	//inserts a newline
    cout<<endl;
  	//creates a while loop in which it simulates the game between the two colors/players
  	//checks if either has emerged victorious and at the end of each turn increases the number of turns
    while(true){
        board.movePiece(WHITE);
        if(board.winner!=-1){
            board.announceWinner(board.winner);
            return 0;
        }
        board.movePiece(BLACK);
        if(board.winner!=-1){
            board.announceWinner(board.winner);
            return 0;
        }
        board.increaseNumberOfTurns();
    }
  	//inserts a newline
    cout<<endl;

}
///@brief initializes the game board
void Board::initializeBoard(){
    ///player1 name
    string player1="";
    ///player2 name
    string player2="";
    cout<<"Welcome to the amazing Chess game! You're in for a treat!"<<endl;
    cout<<"The chess pieces all capitalized are the WHITE pieces and the lowercase chess pieces are the BLACK pieces."<<endl;
    cout<<"Enter a player display name for the WHITE piece: ";
    cin>>player1;
    cout<<endl;
    cout<<"Enter a player display name for the BLACK piece: ";
    cin>>player2;
    cout<<endl;
    //sets player1 name
    setPlayerName(0,player1);
    //sets player2 name
    setPlayerName(1,player2);
    //creates two nested for loops (which loops through the entire board) in which it assigns all spaces on the game board to the piece value to Empty and the Color to NONE
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            Space defaultSpace;
            defaultSpace.setValue(Empty,NONE);
            board[i][j]=defaultSpace;
        }
    }
  	//initialize all the pieces on the board to default locations
    setPiece({0,0},Rook,WHITE);
    setPiece({0,1},Knight,WHITE);
    setPiece({0,2},Bishop,WHITE);
    setPiece({0,3},Queen,WHITE);
    setPiece({0,4},King,WHITE);
    setPiece({0,5},Bishop,WHITE);
    setPiece({0,6},Knight,WHITE);
    setPiece({0,7},Rook,WHITE);
    for(int i=0;i<COLUMN;i++){
        setPiece({1,i},Pawn,WHITE);
        setPiece({6,i},Pawn,BLACK);
        for(int j=2;j<=5;j++){  
            setPiece({j,i},Empty,NONE);
        }
    }
    setPiece({7,0},Rook,BLACK);
    setPiece({7,1},Knight,BLACK);
    setPiece({7,2},Bishop,BLACK);
    setPiece({7,3},Queen,BLACK);
    setPiece({7,4},King,BLACK);
    setPiece({7,5},Bishop,BLACK);
    setPiece({7,6},Knight,BLACK);
    setPiece({7,7},Rook,BLACK);
 
    
}
///@brief prints the game board
void Board::printBoard(){
    //formats the game board
    for(int i=ROW-1;i>=0;i--){
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<i+1<<" ";
        for(int j=0;j<COLUMN;j++){
            cout<<"|";
            cout<<setw(5);
            string pieceString=pieceNames[getSpace({i,j})->getValue()];
            if(getSpace({i,j})->getColor()==WHITE){
                for(auto& x:pieceString){
                    x=toupper(x);
                }
            }
            cout<<pieceString<<" ";
            
        }
        cout<<endl;
    }
    //prints the row of letters for the rows on the bottom of the board for better game display
    char letters[8]={'A','B','C','D','E','F','G','H'};
    cout<<endl<<"  ";
    for(int i=0;i<COLUMN;i++){
        cout<<setw(6);
        cout<<letters[i]<<" ";
    }
    cout<<endl;
}
///@brief sets a piece with a designated coordinate, piece type, and color on the game board
///@param coor takes in a coordinate
///@param pece takes in a piece
///@param clr takes in a color
void Board::setPiece(Coordinate coor,Piece pece,Color clr){
    getSpace(coor)->setValue(pece,clr);
}
///@brief gets the space of the given coordinate
///@param coor takes in a coordinate
///@return specific space on the board
Space* Board::getSpace(Coordinate coor){
    return &board[coor.x][coor.y];
}

//-------------SPACE-------------------------------
///@brief gets the value of the space on the board
///@return a piece value
Piece Space::getValue(){
    return value;
}
///@brief gets the color of the space on the board
///@return a color
Color Space::getColor(){
    return color;
}

///@brief sets the value of a specific piece of a color
///@param pece takes in a piece
///@param clr takes in a color
void Space::setValue(Piece pece,Color clr){
    value = pece;
    color = clr;

}
///@brief moves a specific piece on the board for a color
///@param myColor takes in a color
void Board::movePiece(Color myColor){
    //checks if a check is in existence in the game currently
  	if(check){
      	///checks to see if a move done by a player on the board results in check mate
        bool foundMove=false;
        ///creates a coordinate array that holds all the movable positions on the board which is 64 (8*8)
      	Coordinate allMovable[64];
        ///creates a size and initializes it to zero
      	int size=0;
        getAllMovableLocations(allMovable,size,myColor);
        for(int i=0;i<size;i++){
            Piece tempPiece=getSpace(allMovable[i])->getValue();
            Color tempColor=getSpace(allMovable[i])->getColor();
            setPiece(allMovable[i],Pawn,myColor);

            if(!isUnderCheck(myColor)){
                foundMove=true;
            }
            setPiece(allMovable[i],tempPiece,tempColor);
        }
      	//if a check mate is found
        if(!foundMove){
            if(myColor==WHITE){//if the color is WHITE, then WHITE is the winner
                winner=1;
            }
            else{//if the color is BLACK, then BLACK is the winner
                winner=0;
            }
            return;//return
        }
    }
    ///stores info on whether user is attempting to castle
    bool isCastleAttempt=false;
    ///true if user input is acceptable and should not input again
    bool valid=false;
    ///to store user input for column
    char letter;
    ///the space element where user moved a piece from
    Space* startSpace=new Space();
    ///the space element where user moved a piece to end
    Space* endSpace=new Space();
    ///create a start coordinate
    Coordinate start;
    ///create a end coordinate
    Coordinate end;
    ///create a piece called startPiece
    Piece startPiece;
    ///create a color called enemyColor to store the opposing color
    Color enemyColor;
    if(myColor==WHITE){//if the current color is WHITE, then the enemy color is BLACK
        enemyColor=BLACK;
    }
    else{//if the current color is BLACK, then the enemy color is WHITE
        enemyColor=WHITE;
    }
    while(!valid){//while valid is true
        cout<<endl;
      	///creates a string to hold the color
        string colorString="";
        if(myColor==WHITE){//if current color is WHITE, set colorString to "WHITE"
            colorString="WHITE";
        }
        else if(myColor==BLACK){//if current color is BLACK, set colorString to "BLACK"
            colorString="BLACK";
        }
        cout<<"Player "<<colorString<<", enter which piece to move (enter row and column with space in between i.e (E 2))";
        cout<<"[Or enter 'M 0' for menu display]";
        cin>>letter;//get moving from column
        cin>>start.x;//get moving from row
        if(letter=='m'||letter=='M'){// if user entered m, call menu
            menu(start.x);//pass in menu option
            continue;
        }
        start.x--;//reduce the number to match array index
        start.y=tolower(letter)-'a';//get column number to be moved from
        
        cout<<"Player "<<colorString<<", enter where to move to (enter row and column with space in between i.e (E 3))";
        cin>>letter;//get input column to move to
        cin>>end.x;//get moving to row
        end.x--;//reduce the number to match array index
        end.y=tolower(letter)-'a';//get column number to be moved to
        
        isCastleAttempt=castleAttempt(start,end.y);//check if user is trying to castle
        
        startSpace=getSpace(start);//get space of moving square
        endSpace=getSpace(end);//get space of the target square
        startPiece=startSpace->getValue();//get piece type of the moving piece
        
        if(endSpace->getColor()==myColor){//if the moving target location is already moving player's color, that move is not allowed
            cout<<"how can you move there if there is already a piece there of yours";
            continue;
        }
        if(startSpace->getColor()!=myColor){//if the moving piece is not moving player's color, that move is not allowed
            cout<<"Sorry you can only move your piece"<<endl;
            continue;
        }
        ///array to load in all movable spaces of a piece
        Coordinate ableToMove[64];
        int size=0;
        getMovableLocations(ableToMove,size,start,myColor);//load movable locations into array for a piece
        
        if(myColor==WHITE){
            if(castleAble[0][0]==true){//if white can long castle
                if(getSpace({0,3})->getValue()==Empty&&getSpace({0,2})->getValue()==Empty&&getSpace({0,1})->getValue()==Empty&&getSpace({0,0})->getValue()==Rook){
                    ableToMove[size]={0,2};//user can move to row 0 column 2 by king if wants to castle left
                    size++;
                }
            }
            if(castleAble[0][1]==true){//if white can short  castle
                if(getSpace({0,5})->getValue()==Empty&&getSpace({0,6})->getValue()==Empty&&getSpace({0,7})->getValue()==Rook){
                    ableToMove[size]={0,6};//user can move to row 0 column 6 by king if wants to castle right
                    size++;
                }
            }
        }
        else if(myColor==BLACK){//if user is playing black
            if(castleAble[1][0]==true){//if black can long castle
                if(getSpace({7,3})->getValue()==Empty&&getSpace({7,2})->getValue()==Empty&&getSpace({7,1})->getValue()==Empty&&getSpace({7,0})->getValue()==Rook){
                    ableToMove[size]={7,2};//user can move to row 8 column 2 by king if wants to castle left
                    size++;
                }
            }
            if(castleAble[1][1]==true){//if black can short castle
                if(getSpace({7,5})->getValue()==Empty&&getSpace({7,6})->getValue()==Empty&&getSpace({7,7})->getValue()==Rook){
                    //user can move to row 8 column 7 by king if wants to castle right
                  	ableToMove[size]={7,6};
                    size++;//increase array size
                }
            }
        }
        //----------------------check if valid move
        //end.x end.y
        Piece replacedPiece;//save target location piece info in case a reset is needed
        Color replacedColor;//save target location color info in case a reset is needed
        ///tracks if the location user wants to move to is a location that user can move to
      	bool found=false;
        
        for(int i=0;i<size;i++){
            if(ableToMove[i].x==end.x&&ableToMove[i].y==end.y){// the location that user wants to move to is in the list of where user can move to
                found=true;
                break;
            }
        }
        if(found){
            replacedPiece=endSpace->getValue();//get piece of the space to be moved to
            replacedColor=endSpace->getColor();//get color of the space to be moved to
            endSpace->setValue(startPiece,myColor);//move piece
            startSpace->setValue(Empty,NONE);//move piece
            if(isCastleAttempt){
                if(end.y==6){//castle is to the right
                    getSpace({start.x,7})->setValue(Empty,NONE);//perform the castle
                    getSpace({start.x,5})->setValue(Rook,myColor);//perform the castle
                }
                else if(end.y==2){//castle is to the left
                    getSpace({start.x,0})->setValue(Empty,NONE);//perform the castle
                    getSpace({start.x,3})->setValue(Rook,myColor);//perform the castle
                }
            }
            valid=true;//can stop looping
        }
        else{
            cout<<"Sorry you cannot move to that location."<<endl;
            continue;//restart the function, make new move
        }
        if(check&&isUnderCheck(myColor)){
            startSpace->setValue(startPiece,myColor);//space to be moved from 
            endSpace->setValue(replacedPiece,replacedColor);//space to be moved to
            if(isCastleAttempt){//current move is trying to castle 
                if(end.y==6){//castling right side
                    getSpace({start.x,5})->setValue(Empty,NONE);//move back the castle
                    getSpace({start.x,7})->setValue(Rook,myColor);//move back the castle
                }
                else if(end.y==2){//castling left sid e
                    getSpace({start.x,3})->setValue(Empty,NONE);//move back the castle
                    getSpace({start.x,0})->setValue(Rook,myColor);//move back the castle
                }
            }
            cout<<"You cannot do that while under check."<<endl;
            valid=false;
            continue;//restart the funciton
        }
        if(isUnderCheck(myColor)){//player playing is under check
            startSpace->setValue(startPiece,myColor);//the space to be moved from
            endSpace->setValue(replacedPiece,replacedColor);//the space to be moved to
            if(isCastleAttempt){//was trying to castle
                if(end.y==6){//castle was right side
                    getSpace({start.x,5})->setValue(Empty,NONE);//move back the castle
                    getSpace({start.x,7})->setValue(Rook,myColor);//move back the castle
                }
                else if(end.y==2){//castle was left side
                    getSpace({start.x,3})->setValue(Empty,NONE);//move back the castle
                    getSpace({start.x,0})->setValue(Rook,myColor);//move back the castle
                }
            }
            cout<<"You cannot do that, that move causes a check from the opponent."<<endl;
            valid=false;//restart the function
            continue;//restart
        }
        if(valid){
            if(startPiece==King){// if moving piece is a king
                if(myColor==WHITE){// if checking color si white
                    castleAble[0][0]=false;//king moved so no castleing allowed on that side
                    castleAble[0][1]=false;//king moved so no castleing allowed on that side
                }
                else if(myColor==BLACK){//if checking color is black
                    castleAble[1][0]=false;//king moved so no castleing allowed on that side
                    castleAble[1][1]=false;//king moved so no castleing allowed on that side
                }
            }
            else if(startPiece==Rook){//if the piece moving is a rook
                if(start.y==7){// if left size of board
                    if(myColor==WHITE){// if it is white color
                        castleAble[0][1]=false;//rook moved so no castleing allowed on that side
                    }
                    else if(myColor==BLACK){// if it is black color
                        castleAble[1][1]=false;//rook moved so no castleing allowed on that side
                    }
                }
                else if(start.y==0){// if left size of board
                    if(myColor==WHITE){// if it is white color
                        castleAble[0][0]=false;//rook moved so no castleing allowed on that side
                    }
                    else if(myColor==BLACK){// if it is black color
                        castleAble[1][0]=false;//rook moved so no castleing allowed on that side
                    }
                }
            }
        }
        check=isUnderCheck(enemyColor);//check if enemy is under check
        Board::printBoard();//print board
        if(check){
            cout<<"CHECK!"<<endl;//display message to tell user that he is under check
        }
    }
}
///@brief goes through the board in one direction, and adds spaces to array that is on the path until incounter a piece
///@param arr is the array to add spaces to
///@param size is the array size
///@param startCoord the coord to start from
///@param xd the x offset for direction to move to
///@param yd the y offset for direction to move to
///@param attackable is the bool that tracks if we should add our ally piece when encountered
void Board::searchAndAdd(Coordinate arr[],int &size,Coordinate startCoord,int xd,int yd,bool attackable){
    ///a "pointer" that goes through the board
    Coordinate currentCoord=startCoord;
    ///get the color of the piece being checked
    Color playerColor=getSpace(startCoord)->getColor();
    currentCoord.x+=xd;//x move to first offset
    currentCoord.y+=yd;//y move to first offset
    while(currentCoord.x<ROW&&currentCoord.y<COLUMN&&currentCoord.x>=0&&currentCoord.y>=0){// if in bound
        if(getSpace(currentCoord)->getValue()==Empty){//empty space
            arr[size]=currentCoord;//add current coord to array of pieces attacked
            size++;//increase array size
        }
        else if(getSpace(currentCoord)->getColor()!=playerColor&&getSpace(currentCoord)->getColor()!=NONE){//enemy
            arr[size]=currentCoord;//add current coord to array of pieces attacked
            size++;//increase array size
            break;//stop the loop
        }
        else if(getSpace(currentCoord)->getColor()==playerColor){// if the piece is ally color
            if(attackable){// if under attack mode, ally piece counts
                arr[size]=currentCoord;//add current coord to attacking spaces array
                size++;//increase array size
            }
            break;//stop checking next one because we cannot pass thorugh our own piece
        }
        currentCoord.x+=xd;//move to next coord
        currentCoord.y+=yd;//move to next coord
    }
}
///@param find all squares that is a color is attacking
///@param ableToMove array to hold all squares that a color is attacking
///@param size is size of the array
///@param myColor is the color that is being evaluated
void Board::findAttackSquares(Coordinate ableToMove[],int &size,Color myColor){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            Coordinate currentCoord={i,j};//current viewing coord
            Piece currentPiece=getSpace(currentCoord)->getValue();//current viewing piece type
            Space* currentSpace=getSpace(currentCoord);//current viewing space
            if(getSpace(currentCoord)->getColor()!=myColor){// if the space being checked is not the color concerned skip the space
                continue;
            }
            
            if(currentPiece==Pawn){// if the piece being checked is a pawn

                int offset;
                if(currentSpace->getColor()==WHITE){//if viewing black white, front is one row up
                    offset=1;
                }
                else if(currentSpace->getColor()==BLACK){//if viewing black pawn, front is one row down
                    offset=-1;
                }
                if((currentCoord.y-1)>0){
                  	// add the current viewing coord to movable array
                    ableToMove[size]={currentCoord.x+offset,currentCoord.y-1};
                    size++;//increase array size 
                }
                if(currentCoord.y+1<COLUMN){
                  	// add the current viewing coord to movable array
                    ableToMove[size]={currentCoord.x+offset,currentCoord.y+1};
                    size++;//increase array size
                }
            }
            else if(currentPiece==Rook){// if the piece being checked is a rook
                searchAndAdd(ableToMove,size,currentCoord,1,0,true); // up
                searchAndAdd(ableToMove,size,currentCoord,0,1,true); // right
                searchAndAdd(ableToMove,size,currentCoord,0,-1,true); // left
                searchAndAdd(ableToMove,size,currentCoord,-1,0,true); // down
            }
            else if(currentPiece==Bishop){// if the piece being checked is a bishop
                searchAndAdd(ableToMove,size,currentCoord,1,1,true); // up right
                searchAndAdd(ableToMove,size,currentCoord,-1,-1,true); // bottom left
                searchAndAdd(ableToMove,size,currentCoord,1,-1,true); // up left
                searchAndAdd(ableToMove,size,currentCoord,-1,1,true); // bottom right
            }
            else if(currentPiece==Knight){// if the piece being checked is a knight
                int availablePos[][2]={{1,2},{2,1},{-2,1},{-2,-1},{-1,2},{2,-1},{-1,-2},{1,-2}};//positional offsets for the knight
                for(int i=0;i<8;i++){
                    Coordinate usedToCheck={currentCoord.x+availablePos[i][0],currentCoord.y+availablePos[i][1]};//space that is being checked
                    if(usedToCheck.x<ROW&&usedToCheck.y<COLUMN&&usedToCheck.x>=0&&usedToCheck.y>=0){//check for out of bounds
                        if(getSpace(usedToCheck)->getColor()!=NONE){
                            ableToMove[size]=usedToCheck;//add currently checking space into the movable space array
                            size++;//increase array size
                        }
                    }
                }
            }
            else if(currentPiece==Queen){// if the piece being checked is a queen
                searchAndAdd(ableToMove,size,currentCoord,1,0,true); // up
                searchAndAdd(ableToMove,size,currentCoord,0,1,true); // right
                searchAndAdd(ableToMove,size,currentCoord,0,-1,true); // left
                searchAndAdd(ableToMove,size,currentCoord,-1,0,true); // down
                searchAndAdd(ableToMove,size,currentCoord,1,1,true); // up right
                searchAndAdd(ableToMove,size,currentCoord,-1,-1,true); // bottom left
                searchAndAdd(ableToMove,size,currentCoord,1,-1,true); // up left
                searchAndAdd(ableToMove,size,currentCoord,-1,1,true); // bottom right
            }
            else if(currentPiece==King){// if the piece being checked is a king
                int availablePos[][2]={{1,1},{1,0},{-1,0},{-1,-1},{1,-1},{-1,1},{0,1},{0,-1}};///positional offsets for king to move (i.e. 1,1 means one row up and one column right)
                for(int i=0;i<8;i++){
                  	///coordinate that is being checked
                    Coordinate usedToCheck={currentCoord.x+availablePos[i][0],currentCoord.y+availablePos[i][1]};
                  	
                    if(usedToCheck.x<ROW&&usedToCheck.y<COLUMN&&usedToCheck.x>=0&&usedToCheck.y>=0){// if not out of bound
                      	//if the piece is enemy piece or empty
                        if(getSpace(usedToCheck)->getColor()!=myColor){
                            //add the space found into array of movable spaces
                          	ableToMove[size]=usedToCheck;
                            size++;//size of array
                        }
                    }
                }
            }
            }
        }
}
///@brief check if a color is being checked
///@param testColor that color that is being verified of check status
///@return true if test color is being checked
bool Board::isUnderCheck(Color testColor){
    Color enemyColor;//get enemy color
    if(testColor==WHITE){
        enemyColor=BLACK;
    }
    else{
        enemyColor=WHITE;
    }
    ///coordinate to hold location of the king
    Coordinate myKing;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            if(getSpace({i,j})->getValue()==King&&getSpace({i,j})->getColor()==testColor){// if a king found of the color
                myKing={i,j};//location of the king
                break;//since the king is found, stop looping
            }
        }
    }
    ///holds all spaces that is being attacked
    Coordinate attackMoves[64];
    int attackMoveSize=0;//size of array
    findAttackSquares(attackMoves,attackMoveSize,enemyColor);//gets all spaces that is under attack from enemy pieces
    for(int i=0;i<attackMoveSize;i++){
        if(attackMoves[i]==myKing){//if king is under attack
            return true;
            break;
        }
    }
    return false;
}
///@brief loads into param array all spaces that a color can move to
///@param ableToMove array to store all spaces that a color can move to
///@param size tracks array size
///@param myColor tracks the color that is being observed
void Board::getAllMovableLocations(Coordinate ableToMove[],int& size,Color myColor){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            if(getSpace({i,j})->getColor()!=myColor){//if the piece is not the color that is being checking, ignore
                continue;
            }
            //get all space that a piece can move to, and load it into the able to move array
            getMovableLocations(ableToMove,size,{i,j},myColor);// load all position that this piece can move to
        }
    }
}

///@brief add all space the piece can move to to a array
///@param abletoMoveResult an array to hold spaces that can be moved to 
///@param resultsize array size
///@param start is the coordinate of the space that is being evaluated
///@param myColor is the color of the piece being evaluated
void Board::getMovableLocations(Coordinate ableToMoveResult[],int &resultSize,Coordinate start,Color myColor){
    ///array to record all spaces the piece can move to
    Coordinate ableToMove[64];
    ///array size
    int size=0;
    ///the piece that is being moved
    Piece startPiece=getSpace(start)->getValue();
    ///a space where a piece is moved from
    Space* startSpace=getSpace(start);
    if(startPiece==Pawn){//if user player is trying to move a pawn
        //row off set for different color pawn
        int offset;
        if(startSpace->getColor()==WHITE){// if white pawn, ahead is one row up
            offset=1;
        }
        else if(startSpace->getColor()==BLACK){//if black pawn, ahead is one row down
            offset=-1;
        }
        // if the space ahead of the pawn is empty
        if(getSpace({start.x+offset,start.y})->getValue()==Empty){
            //if the space can be moved to, add it to array
            ableToMove[size]={start.x+offset,start.y};
            size++;//increase array size
        }
        if((start.y-1)>0){
            // if it is enemy color, and is on one block on diagonal
            if(getSpace({start.x+offset,start.y-1})->getColor()!=myColor&&getSpace({start.x+offset,start.y-1})->getColor()!=NONE){
                //if the space can be moved to, add it to array
              	ableToMove[size]={start.x+offset,start.y-1};
                size++;//increase array size
            }
        }
        if(start.y+1<COLUMN){
         		// if it is enemy color, and is on one block on diagonal
          	if(getSpace({start.x+offset,start.y+1})->getColor()!=myColor&&getSpace({start.x+offset,start.y+1})->getColor()!=NONE){
                    //if the space can be moved to, add it to array
                    ableToMove[size]={start.x+offset,start.y+1};
                    size++;//increase array size
            }
        }
        Coordinate firstCheck={start.x+offset,start.y};///< the space before the pawn
        Coordinate secondCheck={start.x+(offset*2),start.y}; ///< two space ahead of the pawn
        if(getSpace(firstCheck)->getValue()==Empty&&getSpace(secondCheck)->getValue()==Empty){
            if((getSpace(start)->getColor()==WHITE&&start.x==1)||(getSpace(start)->getColor()==BLACK&&start.x==6)){
              	//if the space can be moved to, add it to array
                ableToMove[size]=secondCheck;
                size++;//increase array size
            }
        }
    }
    else if(startPiece==Rook){//if user player is trying to move a rook
        searchAndAdd(ableToMove,size,start,1,0,false); // up
        searchAndAdd(ableToMove,size,start,0,1,false); // right
        searchAndAdd(ableToMove,size,start,0,-1,false); // left
        searchAndAdd(ableToMove,size,start,-1,0,false); // down
    }
    else if(startPiece==Bishop){//if user player is trying to move a bishop
        searchAndAdd(ableToMove,size,start,1,1,false); // up right
        searchAndAdd(ableToMove,size,start,-1,-1,false); // bottom left
        searchAndAdd(ableToMove,size,start,1,-1,false); // up left
        searchAndAdd(ableToMove,size,start,-1,1,false); // bottom right
    }
    else if(startPiece==Knight){//if user player is trying to move a Knight
        int availablePos[][2]={{1,2},{2,1},{-2,1},{-2,-1},{-1,2},{2,-1},{-1,-2},{1,-2}};
        for(int i=0;i<8;i++){
            /// coordinate that we are checking if a king can move to
            Coordinate usedToCheck={start.x+availablePos[i][0],start.y+availablePos[i][1]};
            if(usedToCheck.x<ROW&&usedToCheck.y<COLUMN&&usedToCheck.x>=0&&usedToCheck.y>=0){
              
                if(getSpace(usedToCheck)->getColor()!=myColor){
                    //if the space can be moved to, add it to array
                    ableToMove[size]=usedToCheck;
                    size++;//increase array size
                }
            }
        }
    }
    else if(startPiece==Queen){
        searchAndAdd(ableToMove,size,start,1,0,false); // up
        searchAndAdd(ableToMove,size,start,0,1,false); // right
        searchAndAdd(ableToMove,size,start,0,-1,false); // left
        searchAndAdd(ableToMove,size,start,-1,0,false); // down
        searchAndAdd(ableToMove,size,start,1,1,false); // up right
        searchAndAdd(ableToMove,size,start,-1,-1,false); // bottom left
        searchAndAdd(ableToMove,size,start,1,-1,false); // up left
        searchAndAdd(ableToMove,size,start,-1,1,false); // bottom right
    }
    else if(startPiece==King){// if user is trying to move a king
        int availablePos[][2]={{1,1},{1,0},{-1,0},{-1,-1},{1,-1},{-1,1},{0,1},{0,-1}}; ///< all the offsetes where a king can move to(i.e 1,1 means one row up and one column right)
        for(int i=0;i<8;i++){
            /// coordinate that we are checking if a king can move to
            Coordinate usedToCheck={start.x+availablePos[i][0],start.y+availablePos[i][1]};
            if(usedToCheck.x<ROW&&usedToCheck.y<COLUMN&&usedToCheck.x>=0&&usedToCheck.y>=0){
                if(getSpace(usedToCheck)->getColor()!=myColor){
                    //if the space can be moved to, add it to array
                    ableToMove[size]=usedToCheck; 
                    size++;
                }
            }
        }
      	///stores all squares that enemy are attacking
        Coordinate attackAble[64];
      	///stores the size of the array
        int attackSize=0;
      	///holds enemy color
        Color enemyColor;
        
        if(myColor==WHITE){//get enemy colors
            enemyColor=BLACK;
        }
        else{
            enemyColor=WHITE;
        }
        findAttackSquares(attackAble,attackSize,enemyColor);//add all enemy attacking spaces into the array
        /*
        for(int i=0;i<attackSize;i++){
            cout<<attackAble[i].x+1<<":"<<attackAble[i].y+1<<endl;
        }
        */
        for(int i=0;i<size;i++){
            for(int j=0;j<attackSize;j++){
                if(ableToMove[i]==attackAble[j]){// for all space that a kind can move to, if it is in the attack range of an enemy, remove that moveable space from the list
                    ableToMove[i]=ableToMove[size-1];
                    size--;
                    i--;
                }
            }
        }
    }
    for(int i=0;i<size;i++){
        ableToMoveResult[resultSize]=ableToMove[i];// add able to move temp array to able to move input array passed in this function
        resultSize++;//increase size
    }
}
///@brief displays who is winning and by how much
/// it is based on how many pieces each player have on the board
void Board::displayWinningStatus(){
    int scoreValues[]={1,5,3,3,9,0}; ///score value for each piece, ordered by its index number in enum
    /// records score for player one and two
    int playerScores[2]={0,0};
    /// holds name of players, can be accessed by player index, 0 for player1 1 for player2
    string playerNames[2]={getPlayerName(0),getPlayerName(1)};
   
    for(int i=0;i<ROW;i++){// loop through the board and calculate how many piece is on the board
        for(int j=0;j<COLUMN;j++){
            ///the piece that is currently being viewed
            Piece currentPiece=getSpace({i,j})->getValue();
            ///the color that is currently being viewed
            Color currentColor=getSpace({i,j})->getColor();
          
            if(currentColor==WHITE&&currentPiece!=Empty){//count score for white
              playerScores[0]+=scoreValues[currentPiece];
            }
            else if(currentColor==BLACK&&currentPiece!=Empty){//count score for black
                playerScores[1]+=scoreValues[currentPiece];
            }
        }
    }
    ///stores 0 if player1 is winning, 1 if player2 is winning, -1 if tie
    int winningPlayerNumber=maxItem(playerScores[0],playerScores[1]);
    if(winningPlayerNumber==-1){
        cout<<"Based on the pieces currently on the board, the game is in a tie position."<<endl;
        return;
    }
    ///scores the score difference between players
    int scoreDifference=abs(playerScores[0]-playerScores[1]);
    cout<<"Current winning player is "<<playerNames[winningPlayerNumber]<<endl;
    cout<<"Score difference is "<<scoreDifference<<" points (based on number of pieces still on the board)"<<endl;
}