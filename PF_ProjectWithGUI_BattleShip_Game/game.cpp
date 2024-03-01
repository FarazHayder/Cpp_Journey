//============================================================================
// Name        : BattleShips
// Author      : Faraz Hayder
// Version     : 1.0
// Copyright   : (c) Reserved
// Description : Basic 2D game of Battleships.
//============================================================================

/*
Name: Faraz Hayder
*/

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
#include <unistd.h>
#include <fstream>
#include <time.h>

using namespace std;

//Function prototypes
void MouseMoved(int , int );
void GameDisplay(void);
void StartGame(void);
void NewGame(void);
void MouseClickedLeaderboard(int , int , int , int );
void MouseClickedNewGame(int , int , int , int );
void MouseClickedStartGame(int , int , int , int );
void OpponentsTurn(void);


//Some useful variables
int Replace1=0,Replace2=0,Replace3=0,Replace4=0,Replace5=0,Replace6=0,Replace7=0,Replace8=0,Replace9=0,Replace10=0;//,Rotate1=0;
int x=0,y=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0,x9=0,y9=0,x10=0,y10=0,x11=0,y11=0;
int error=0, Auto=0;

int turn=1;
int timer=1000;

int hit=0,miss=0,countx=0,county=0,countx1=0,county1=0; //User's turn variables
int opponenthit=0,opponentmiss=0,opponentcountx=0,opponentcounty=0,opponentcountx1=0,opponentcounty1=0; //Opponent's turn variables

int userscore=0,opponentscore=0;

//For User's turn:-
//Static:
//int tempx[2000]={0},tempy[2000]={0},tempx1[2000]={0},tempy1[2000]={0};
//DMA and pointers:
int* tempx=new int [2000];
int* tempy=new int [2000];
int* tempx1=new int [2000];
int* tempy1=new int [2000];

//For Opponent's turn:-
//Static:
//int tempx[2000]={0},tempy[2000]={0},tempx1[2000]={0},tempy1[2000]={0};
//DMA and pointers:
int* opponenttempx=new int [2000];
int* opponenttempy=new int [2000];
int* opponenttempx1=new int [2000];
int* opponenttempy1=new int [2000];

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//Draws object
int xI = 400, yI = 400;
void drawObject() {
	DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}

//Moves Object
bool flag = true;
void moveObject() {
	
	/*if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left ";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right ";
		xI += 10;
		if (xI > 900)
			flag = true;
	}*/
}

//Function to display and control all the things in the LEADERBOARD window
void GameDisplayLeaderboard()/**/{
		glClearColor(0.627/*Red Component*/, 0.125,	//148.0/255/*Green Component*/,
			0.941/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	DrawRectangle(817,700,175,70, colors[BLACK]);
	DrawString(843,730,"Leaderboard", colors[WHITE]);
	
	DrawRoundRect(117,700,175,70, colors[BLACK],15);
	DrawString(143,730,"Main Menu", colors[WHITE]); 
	
	DrawString(143,630,"1.", colors[BLACK]);
	DrawString(143,567,"2.", colors[BLACK]);
	DrawString(143,504,"3.", colors[BLACK]);
	DrawString(143,441,"4.", colors[BLACK]);
	DrawString(143,378,"5.", colors[BLACK]);
	DrawString(143,315,"6.", colors[BLACK]);
	DrawString(143,252,"7.", colors[BLACK]);
	DrawString(143,189,"8.", colors[BLACK]);
	DrawString(143,126,"9.", colors[BLACK]);
	DrawString(143,63,"10.", colors[BLACK]);

	//File Handling
	ofstream foutHighscores("Highscores.txt");
	int score=100;
	string names[10]={"ab","cd","ef","gh","ij","kl","mn","op","qr","st"};
  	int scores[10]={10,9,8,7,6,5,4,3,2,1};
	for (int i = 0 ; i < 10 ; i++){
      	foutHighscores << names[i] << " " << scores[i]<<endl;
    	}
	foutHighscores.close();

	ifstream finHighscores("Highscores.txt");
	string text1="";
	while(getline(finHighscores, text1)){
		for (int i = 0 ; i < 10 ; i++){
			switch (i)
			{
			case 0:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 1:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 2:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 3:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 4:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 5:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 6:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 7:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 8:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			case 9:
				DrawString(243,630-(63*i),text1,colors[BLACK]);
				break;
			}
		}
	}
	finHighscores.close();

	glutSwapBuffers(); // do not modify this line..

}

//Function to display STARTGAME window
void Leaderboard (){
	
	int width = 1845, height = 840; // i have set my window size to be 1845 x 840

	InitRandomizer(); // seed the random number generator...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMouseFunc(MouseClickedLeaderboard); // Mouse
	
	glutDisplayFunc(GameDisplayLeaderboard);

	glutPostRedisplay();

}

//Function used for mouse inside LEADERBOARD
void MouseClickedLeaderboard(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		
			switch (x)  
			{
			case  117 ... 292 : //Leaderboard Button
				switch (y)
				{
				case  70 ... 140 :
					//GameDisplay();
					exit(1);
					break;
				}
				break;
			
			default:
				break;
			
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
//Function used for mouse use in MENU
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		
			switch (x)  
			{
			case  424 ... 599 : //Leaderboard Button
				
				switch (y)
				{
				case  246 ... 316 :
					Leaderboard();
					break;
				}
				break;
			
			default:
				break;
			}

			switch (x)  
			{
			case  424 ... 599 : //New Game Button
				
				switch (y)
				{
				case  346 ... 416 :
					NewGame();
					break;
				}
				break;
			
			default:
				break;
			}

			switch (x)  
			{
			case  424 ... 599 : //Balance Button
				
				switch (y)
				{
				case  446 ... 516 :
					//Balance();
					break;
				}
				break;
			
			default:
				break;
			}
		

			switch (x)  
			{
			case  424 ... 599 : //Options Button
				
				switch (y)
				{
				case  546 ... 616 :
					//Options();
					break;
				}
				break;
			
			default:
				break;
			}

			switch (x)  
			{
			case  424 ... 599 : //Exit Game Button
				
				switch (y)
				{
				case  646 ... 716 :
					exit(0);
					break;
				}
				break;
			
			default:
				break;
			}
	} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

//Displays Menu Screen
void Menu() {
	
	DrawString(450,700,"Main Menu", colors[BLACK]);
	DrawRoundRect(444-20,550-26,135+40,30+40, colors[BLACK],15);
	DrawString(450,550,"Leaderboard", colors[WHITE]); 
	DrawRoundRect(444-20,450-26,135+40,30+40, colors[BLACK],15);
	DrawString(455,450,"New Game", colors[WHITE]); 
	DrawRoundRect(444-20,350-26,135+40,30+40, colors[BLACK],15);
	DrawString(470,350,"Balance", colors[WHITE]); 
	DrawRoundRect(444-20,250-26,135+40,30+40, colors[BLACK],15);
	DrawString(470,250,"Options", colors[WHITE]); 
	DrawRoundRect(444-20,150-26,135+40,30+40, colors[BLACK],15);
	DrawString(455,150,"Exit Game", colors[WHITE]); 

	glutPostRedisplay();

}

//Function to display MENU window
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(0.627/*Red Component*/, 0.125,	//148.0/255/*Green Component*/,
				0.941/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	Menu();
	
	glutSwapBuffers(); // do not modify this line..

}

//Function to display and control all the things in the NEWGAME window
void GameDisplayNewGame()/**/{
		glClearColor(0.6902/*Red Component*/, 0.8784,	//148.0/255/*Green Component*/,
			 0.902/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	//Printing Grid
	int t=70; 
	for (int i=0; i<50; i++){
		for (int j=0; j<50; j++){
			DrawSquare(i*t,j*70,70,colors[WHITE]);
		}
	}

	//Displaying Battle Grid
	DrawString(30,730,"A",colors[CUSTOM1]);
	DrawString(30,660,"B",colors[CUSTOM1]);
	DrawString(30,590,"C",colors[CUSTOM1]);
	DrawString(30,520,"D",colors[CUSTOM1]);
	DrawString(30,450,"E",colors[CUSTOM1]);
	DrawString(30,380,"F",colors[CUSTOM1]);
	DrawString(30,310,"G",colors[CUSTOM1]);
	DrawString(30,240,"H",colors[CUSTOM1]);
	DrawString(30,170,"I",colors[CUSTOM1]);
	DrawString(30,100,"J",colors[CUSTOM1]);

	DrawString(100,800,"1",colors[CUSTOM1]);
	DrawString(170,800,"2",colors[CUSTOM1]);
	DrawString(240,800,"3",colors[CUSTOM1]);
	DrawString(310,800,"4",colors[CUSTOM1]);
	DrawString(380,800,"5",colors[CUSTOM1]);
	DrawString(450,800,"6",colors[CUSTOM1]);
	DrawString(520,800,"7",colors[CUSTOM1]);
	DrawString(590,800,"8",colors[CUSTOM1]);
	DrawString(660,800,"9",colors[CUSTOM1]);
	DrawString(730,800,"10",colors[CUSTOM1]);

	DrawLine(67,70,67,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(771,70,771,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(65,67,774,67,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(65,771,774,771,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple

	//Displaying Battleships
	for (int i=0; i<4; i++){
		DrawSquare(1330+(i*70),700,70,colors[CUSTOM1]);
	}
	for (int i=0; i<3; i++){
		DrawSquare(1400+(i*70),560,70,colors[CUSTOM1]);
	}
	for (int i=0; i<3; i++){
		DrawSquare(1120+(i*70),560,70,colors[CUSTOM1]);
	}
	for (int i=0; i<2; i++){
		DrawSquare(1050+(i*70),420,70,colors[CUSTOM1]);
	}
	for (int i=0; i<2; i++){
		DrawSquare(1260+(i*70),420,70,colors[CUSTOM1]);
	}
	for (int i=0; i<2; i++){
		DrawSquare(1470+(i*70),420,70,colors[CUSTOM1]);
	}
	for (int i=0; i<1; i++){
		DrawSquare(1120+(i*70),280,70,colors[CUSTOM1]);
	}
	for (int i=0; i<1; i++){
		DrawSquare(1260+(i*70),280,70,colors[CUSTOM1]);
	}
	for (int i=0; i<1; i++){
		DrawSquare(1400+(i*70),280,70,colors[CUSTOM1]);
	}
	for (int i=0; i<1; i++){
		DrawSquare(1540+(i*70),280,70,colors[CUSTOM1]);
	}
	
	//Placing Battleships
	if (Replace1==1){
		for (int i=0; i<4; i++){
					DrawSquare(1330+(i*70),700,70,colors[WHITE]);
				}
	}//Test //cout<<"Replace1 = "<<Replace1<<endl;
	if (Replace1==2){
		for (int i=0; i<4; i++){
					DrawSquare(1330+(i*70),700,70,colors[WHITE]);
				}
		for (int i=0; i<4; i++){
					DrawSquare(x2-(i*70),770-y2,70,colors[CUSTOM1]);
				}
	}
	//For Orientation
	/*if (Rotate1==2){
		for (int i=0; i<4; i++){
					DrawSquare(1330+(i*70),700,70,colors[WHITE]);
				}
		for (int i=0; i<4; i++){
					DrawSquare(x2,y2+(i*70),70,colors[CUSTOM1]);
				}
	}*/
	if (Replace2==1){
		for (int i=0; i<3; i++){
					DrawSquare(1400+(i*70),560,70,colors[WHITE]);
				}
	}
	if (Replace2==2){
		for (int i=0; i<3; i++){
					DrawSquare(1400+(i*70),560,70,colors[WHITE]);
				}
		for (int i=0; i<3; i++){
					DrawSquare(x3-(i*70),770-y3,70,colors[CUSTOM1]);
				}		
	}
	if (Replace3==1){
		for (int i=0; i<3; i++){
					DrawSquare(1120+(i*70),560,70,colors[WHITE]);
				}
	}
	if (Replace3==2){
		for (int i=0; i<3; i++){
					DrawSquare(1120+(i*70),560,70,colors[WHITE]);
				}
		for (int i=0; i<3; i++){
					DrawSquare(x4-(i*70),770-y4,70,colors[CUSTOM1]);
				}		
	}
	if (Replace4==1){
		for (int i=0; i<2; i++){
					DrawSquare(1050+(i*70),420,70,colors[WHITE]);
				}
	}
	if (Replace4==2){
		for (int i=0; i<2; i++){
					DrawSquare(1050+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(x5-(i*70),770-y5,70,colors[CUSTOM1]);
				}		
	}
	if (Replace5==1){
		for (int i=0; i<2; i++){
					DrawSquare(1260+(i*70),420,70,colors[WHITE]);
				}	
	}
	if (Replace5==2){
		for (int i=0; i<2; i++){
					DrawSquare(1260+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(x6-(i*70),770-y6,70,colors[CUSTOM1]);
				}		
	}
	if (Replace6==1){
		for (int i=0; i<2; i++){
					DrawSquare(1470+(i*70),420,70,colors[WHITE]);
				}	
	}
	if (Replace6==2){
		for (int i=0; i<2; i++){
					DrawSquare(1470+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(x7-(i*70),770-y7,70,colors[CUSTOM1]);
				}		
	}
	if (Replace7==1){
		for (int i=0; i<1; i++){
					DrawSquare(1120+(i*70),280,70,colors[WHITE]);
				}	
	}
	if (Replace7==2){
		for (int i=0; i<1; i++){
					DrawSquare(1120+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(x8-(i*70),770-y8,70,colors[CUSTOM1]);
				}		
	}
	if (Replace8==1){
		for (int i=0; i<1; i++){
					DrawSquare(1260+(i*70),280,70,colors[WHITE]);
				}	
	}
	if (Replace8==2){
		for (int i=0; i<1; i++){
					DrawSquare(1260+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(x9-(i*70),770-y9,70,colors[CUSTOM1]);
				}		
	}
	if (Replace9==1){
		for (int i=0; i<1; i++){
					DrawSquare(1400+(i*70),280,70,colors[WHITE]);
				}
	}
	if (Replace9==2){
		for (int i=0; i<1; i++){
					DrawSquare(1400+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(x10-(i*70),770-y10,70,colors[CUSTOM1]);
				}		
	}
	if (Replace10==1){
		for (int i=0; i<1; i++){
					DrawSquare(1540+(i*70),280,70,colors[WHITE]);
				}	
	}
	if (Replace10==2){
		for (int i=0; i<1; i++){
					DrawSquare(1540+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(x11-(i*70),770-y11,70,colors[CUSTOM1]);
				}		
	}

	//Error Displaying
	if (error==1){
		DrawString(770,455,"INVALID COORDINATES",colors[RED]);
	}

	//Auto Placement of Battleships
	DrawRoundRect(820,70,110,70,colors[CUSTOM1],15);
	DrawString(840,100,"AUTO",colors[WHITE]);
	
	if (Auto==1){
		Replace1=2; Replace2=2; Replace3=2; Replace4=2; Replace5=2; Replace6=2; Replace7=2; Replace8=2; Replace9=2; Replace10=2;
		for (int i=1; i<=10; i++){
			for (int j=1; j<=10; j++){
				DrawSquare((i*70),(j*70),70,colors[WHITE]);
			}
		}
		for (int i=0; i<4; i++){
					DrawSquare(1330+(i*70),700,70,colors[WHITE]);
				}
		for (int i=0; i<4; i++){
					DrawSquare(420-(i*70),630,70,colors[CUSTOM1]); x2=420; y2=140;
				}
		for (int i=0; i<3; i++){
					DrawSquare(1400+(i*70),560,70,colors[WHITE]);
				}
		for (int i=0; i<3; i++){
					DrawSquare(210-(i*70),210,70,colors[CUSTOM1]); x3=210; y3=560;
				}		
		for (int i=0; i<3; i++){
					DrawSquare(1120+(i*70),560,70,colors[WHITE]);
				}
		for (int i=0; i<3; i++){
					DrawSquare(490-(i*70),280,70,colors[CUSTOM1]); x4=490; y4=490;
				}		
		for (int i=0; i<2; i++){
					DrawSquare(1050+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(630-(i*70),560,70,colors[CUSTOM1]); x5=630; y5=210;
				}		
		for (int i=0; i<2; i++){
					DrawSquare(1260+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(630-(i*70),420,70,colors[CUSTOM1]); x6=630; y6=350;
				}		
		for (int i=0; i<2; i++){
					DrawSquare(1470+(i*70),420,70,colors[WHITE]);
				}
		for (int i=0; i<2; i++){
					DrawSquare(140-(i*70),490,70,colors[CUSTOM1]); x7=140; y7=280;
				}		
		for (int i=0; i<1; i++){
					DrawSquare(1120+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(700-(i*70),70,70,colors[CUSTOM1]); x8=700; y8=700;
				}		
		for (int i=0; i<1; i++){
					DrawSquare(1260+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(70-(i*70),700,70,colors[CUSTOM1]); x9=70; y9=70;
				}		
		for (int i=0; i<1; i++){
					DrawSquare(1400+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(350-(i*70),140,70,colors[CUSTOM1]); x10=350; y10=630;
				}		
		for (int i=0; i<1; i++){
					DrawSquare(1540+(i*70),280,70,colors[WHITE]);
				}
		for (int i=0; i<1; i++){
					DrawSquare(350-(i*70),420,70,colors[CUSTOM1]); x11=350; y11=350;
				}
	}

	//Displaying START GAME BUTTON
	if (Replace1==2 && Replace2==2 && Replace3==2 && Replace4==2 && Replace5==2 && Replace6==2 && Replace7==2 && Replace8==2 && Replace9==2 && Replace10==2)
	{
		DrawRoundRect(1590,70,180,70,colors[CUSTOM1],15);
		DrawString(1605,100,"START GAME",colors[WHITE]);
	}

	glutSwapBuffers(); // do not modify this line..

}

//Function to display NEWGAME window
void NewGame(){
	
	int width = 1845, height = 840; // i have set my window size to be 1845 x 840

	InitRandomizer(); // seed the random number generator...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMouseFunc(MouseClickedNewGame); // Mouse

	glutDisplayFunc(GameDisplayNewGame);

	glutPostRedisplay();
}

//Function used for mouse starting a NEWGAME
void MouseClickedNewGame(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
			switch (x)  
				{
				case  820 ... 930 : //AUTO BUTTON
					switch (y)
						{
						case  700 ... 770 :
						Auto=1;
						break;
					}
				break;
			}

			switch (x)  
				{
				case  1590 ... 1770 : //START GAME BUTTON
					switch (y)
						{
						case  700 ... 770 :
						StartGame();
						break;
					}
				break;
			}
			/*if (x>(x2+70) || x<x2+(70*4)){
			if (y>y2-140 || y<(y2+70)){*/



		if (Replace1==0){
			switch (x)  
				{
				case  1330 ... 1610 : //Battleship-4.1 //Battleship-(of length)4.(number)1
					switch (y)
						{
						case  70 ... 140 :
						Replace1=1;
						break;
					}
				break;
			}
		}
		if (Replace1==1){
			switch (x)
				{
				case 280 ... 770: //70 ... 770 (Total Grid) //280 (Since length is 4 and we are placing battleships facing towards left)
					switch (y)
						{
						case 70 ... 770:
						x2=((x/70)*70);
						y2=((y/70)*70);
						Replace1=2;
						//Rotate1=1; //for orientation
						error=0;
						break;
					}
				break;

				case 70 ... 279:
					error=1;
				break;
			}
		}
		//For changing orientation
		/*if (Rotate1==1){
			if (x>x2-70 && x<x2+70){ //x>x2-(70*3) && x<x2+70
				if (y2+70 && y>y2){
					Rotate1=2;
				}
			}
			if (x>x2-140 && x<x2+70){
				if (y<y2+70 && y>y2){
					Rotate1=2;
				}
			}
			if (x>x2-210 && x<x2+70){
				if (y<y2+70 && y>y2){ //y<y2 && y>y2-70
					Rotate1=2;
				}
			}
		}*/
		if (Replace2==0){
			switch (x)  
				{
				case  1400 ... 1610 : //Battleship-3.1
					switch (y)
						{
						case  210 ... 280 :
						Replace2=1;
						break;
					}
				break;
			}
		}
		if (Replace2==1){
			switch (x)
				{
				case 210 ... 770: //210 (Since length is 3)
					switch (y)
						{
						case 70 ... 770:
						x3=((x/70)*70);
						y3=((y/70)*70);
						Replace2=2;
						error=0;
						break;
					}
				break;

				case 70 ... 209:
					error=1;
				break;
			}
		}
		if (Replace3==0){
			switch (x)  
				{
				case  1120 ... 1330 : //Battleship-3.2
					switch (y)
						{
						case  210 ... 280 :
						Replace3=1;
						break;
					}
				break;
			}
		}
		if (Replace3==1){
			switch (x)
				{
				case 210 ... 770: //210 (Since length is 3)
					switch (y)
						{
						case 70 ... 770:
						x4=((x/70)*70);
						y4=((y/70)*70);
						Replace3=2;
						error=0;
						break;
					}
				break;

				case 70 ... 209:
					error=1;
				break;
			}
		}
		if (Replace4==0){
			switch (x)  
				{
				case  1050 ... 1190 : //Battleship-2.1
					switch (y)
						{
						case  350 ... 420 :
						Replace4=1;
						break;
					}
				break;
			}
		}
		if (Replace4==1){
			switch (x)
				{
				case 140 ... 770: //140 (Since length is 2)
					switch (y)
						{
						case 70 ... 770:
						x5=((x/70)*70);
						y5=((y/70)*70);
						Replace4=2;
						error=0;
						break;
					}
				break;

				case 70 ... 139:
					error=1;
				break;
			}
		}
		if (Replace5==0){
			switch (x)  
				{
				case  1260 ... 1400 : //Battleship-2.2
					switch (y)
						{
						case  350 ... 420 :
						Replace5=1;
						break;
					}
				break;

				case 70 ... 139:
					error=1;
				break;
			}
		}
		if (Replace5==1){
			switch (x)
				{
				case 140 ... 770: //140 (Since length is 2)
					switch (y)
						{
						case 70 ... 770:
						x6=((x/70)*70);
						y6=((y/70)*70);
						Replace5=2;
						error=0;
						break;
					}
				break;

				case 70 ... 139:
					error=1;
				break;
			}
		}
		if (Replace6==0){
			switch (x)  
				{
				case  1470 ... 1610 : //Battleship-2.3
					switch (y)
						{
						case  350 ... 420 :
						Replace6=1;
						break;
					}
				break;
			}
		}
		if (Replace6==1){
			switch (x)
				{
				case 140 ... 770: //140 (Since length is 2)
					switch (y)
						{
						case 70 ... 770:
						x7=((x/70)*70);
						y7=((y/70)*70);
						Replace6=2;
						error=0;
						break;
					}
				break;

				case 70 ... 139:
					error=1;
				break;
			}
		}
		if (Replace7==0){
			switch (x)  
				{
				case  1120 ... 1190 : //Battleship-1.1
					switch (y)
						{
						case  490 ... 560 :
						Replace7=1;
						break;
					}
				break;
			}
		}
		if (Replace7==1){
			switch (x)
				{
				case 70 ... 770:
					switch (y)
						{
						case 70 ... 770:
						x8=((x/70)*70);
						y8=((y/70)*70);
						Replace7=2;
						error=0;
						break;
					}
				break;
			}
		}
		if (Replace8==0){
			switch (x)  
				{
				case  1260 ... 1330 : //Battleship-1.2
					switch (y)
						{
						case  490 ... 560 :
						Replace8=1;
						break;
					}
				break;
			}
		}
		if (Replace8==1){
			switch (x)
				{
				case 70 ... 770:
					switch (y)
						{
						case 70 ... 770:
						x9=((x/70)*70);
						y9=((y/70)*70);
						Replace8=2;
						error=0;
						break;
					}
				break;
			}
		}
		if (Replace9==0){
			switch (x)  
				{
				case  1400 ... 1470 : //Battleship-1.3
					switch (y)
						{
						case  490 ... 560 :
						Replace9=1;
						break;
					}
				break;
			}
		}
		if (Replace9==1){
			switch (x)
				{
				case 70 ... 770:
					switch (y)
						{
						case 70 ... 770:
						x10=((x/70)*70);
						y10=((y/70)*70);
						Replace9=2;
						error=0;
						break;
					}
				break;
			}
		}if (Replace10==0){
			switch (x)  
				{
				case  1540 ... 1610 : //Battleship-1.4
					switch (y)
						{
						case  490 ... 560 :
						Replace10=1;
						break;
					}
				break;
			}
		}
		if (Replace10==1){
			switch (x)
				{
				case 70 ... 770:
					switch (y)
						{
						case 70 ... 770:
						x11=((x/70)*70);
						y11=((y/70)*70);
						Replace10=2;
						error=0;
						break;
					}
				break;
			}
		}


		

	/*}
}*/
}
/*else {
	error=1;
}*/


		
			


	/*else*/ if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

//Function to display and control all the things in the STARTGAME window
void GameDisplayStartGame()/**/{
	glClearColor(0.6902/*Red Component*/, 0.8784,	//148.0/255/*Green Component*/,
			 	0.902/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	//Printing Grid
	int t=70;
	for (int i=0; i<50; i++){
		for (int j=0; j<50; j++){
			DrawSquare(i*t,j*70,70,colors[WHITE]);
		}
	}

	//Displaying User Battle Grid
	DrawString(30,730,"A",colors[CUSTOM1]);
	DrawString(30,660,"B",colors[CUSTOM1]);
	DrawString(30,590,"C",colors[CUSTOM1]);
	DrawString(30,520,"D",colors[CUSTOM1]);
	DrawString(30,450,"E",colors[CUSTOM1]);
	DrawString(30,380,"F",colors[CUSTOM1]);
	DrawString(30,310,"G",colors[CUSTOM1]);
	DrawString(30,240,"H",colors[CUSTOM1]);
	DrawString(30,170,"I",colors[CUSTOM1]);
	DrawString(30,100,"J",colors[CUSTOM1]);

	DrawLine(70,70,70,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(770,70,770,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(70,70,770,70,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(70,770,770,770,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple

	//Displaying Opponent's Battle Grid
	DrawString(1780,730,"A",colors[CUSTOM1]);
	DrawString(1780,660,"B",colors[CUSTOM1]);
	DrawString(1780,590,"C",colors[CUSTOM1]);
	DrawString(1780,520,"D",colors[CUSTOM1]);
	DrawString(1780,450,"E",colors[CUSTOM1]);
	DrawString(1780,380,"F",colors[CUSTOM1]);
	DrawString(1780,310,"G",colors[CUSTOM1]);
	DrawString(1780,240,"H",colors[CUSTOM1]);
	DrawString(1780,170,"I",colors[CUSTOM1]);
	DrawString(1780,100,"J",colors[CUSTOM1]);

	DrawLine(1050,70,1050,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(1750,70,1750,770,5,colors[CUSTOM1]); //Vertical line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(1050,70,1750,70,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple
	DrawLine(1050,770,1750,770,5,colors[CUSTOM1]); //Horizontal line //CUSTOM1: added by me in util.h, to create custom shade of purple
	
	//displaying User Battleships
	for (int i=0; i<4; i++){
				DrawSquare(x2-(i*70),770-y2,70,colors[CUSTOM1]);
			}
	for (int i=0; i<3; i++){
				DrawSquare(x3-(i*70),770-y3,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<3; i++){
				DrawSquare(x4-(i*70),770-y4,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<2; i++){
				DrawSquare(x5-(i*70),770-y5,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<2; i++){
				DrawSquare(x6-(i*70),770-y6,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<2; i++){
				DrawSquare(x7-(i*70),770-y7,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<1; i++){
				DrawSquare(x8-(i*70),770-y8,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<1; i++){
				DrawSquare(x9-(i*70),770-y9,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<1; i++){
				DrawSquare(x10-(i*70),770-y10,70,colors[CUSTOM1]);
			}		
	for (int i=0; i<1; i++){
				DrawSquare(x11-(i*70),770-y11,70,colors[CUSTOM1]);
			}

	//Displaying User Score
	DrawString(700,820,"Points:",colors[BLACK]);
	DrawString(757,795,"0",colors[RED]);

	//Displaying Arsenal Button
	DrawRoundRect(265,795,105,45,colors[BLACK],15);
	DrawString(280,810,"Arsenal",colors[MEDIUM_VIOLET_RED]);

	//Displaying Opponent Score
	DrawString(1680,820,"Points:",colors[BLACK]);
	DrawString(1740,795,"0",colors[RED]);

	//Player's Turn
	if (hit==1){
		for (int i=1; i<=countx; i++){
			DrawString(tempx[i]+30,770-tempy[i]+30,"X",colors[RED]);
		}
	}
	if (miss==1){
		for (int i=1; i<=countx1; i++){
			DrawString(tempx1[i]+30,770-tempy1[i]+30,"B",colors[VIOLET]);
		}
	}
	//Timer
	if (turn==1){
		if (timer>0){
			timer=timer-1;
			DrawString(840,420,"Timer: ",colors[MEDIUM_VIOLET_RED]);
			if (timer>900 && timer <=1000){
				DrawString(910,420,"10",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>800 && timer <=900){
				DrawString(910,420,"9",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>700 && timer <=800){
				DrawString(910,420,"8",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>600 && timer <=700){
				DrawString(910,420,"7",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>500 && timer <=600){
				DrawString(910,420,"6",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>400 && timer <=500){
				DrawString(910,420,"5",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>300 && timer <=400){
				DrawString(910,420,"4",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>200 && timer <=300){
				DrawString(910,420,"3",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>100 && timer <=200){
				DrawString(910,420,"2",colors[MEDIUM_VIOLET_RED]);
			}
			if (timer>1 && timer <=100){
				DrawString(910,420,"1",colors[MEDIUM_VIOLET_RED]);
			}
		}
		else {
				turn=2;
				timer=1000;
			}
	}
	
	//Opponent's Turn
	if (turn==2){
		timer=1000;
		DrawString(820,420,"Computer's Turn",colors[MEDIUM_VIOLET_RED]);
	}
	if (opponenthit==1){
		for (int i=1; i<=opponentcountx; i++){
			DrawString(opponenttempx[i]+30,770-opponenttempy[i]+30,"X",colors[RED]);
		}
	}
	if (opponentmiss==1){
		for (int i=1; i<=opponentcountx1; i++){
			DrawString(opponenttempx1[i]+30,770-opponenttempy1[i]+30,"B",colors[VIOLET]);
		}
	}
	if (turn==2){
		OpponentsTurn ();
	}

	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..
}

//Function used for mouse after the STARTofGAME
void MouseClickedStartGame(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
			if (turn==1){
				switch (x)
				{
				case 1050 ... 1120: //For 1
					switch (y)
					{
					case 70 ... 140: //For A
						turn=1;
						hit=1;
						timer=1000;
						countx=countx+1;
						county=county+1;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 700 ... 770: //For J
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					
					break;
				case 1121 ... 1190: //For 2
					switch (y)
					{
					case 140 ... 210: //For B
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1191 ... 1260: //For 3
					switch (y)
					{
					case 140 ... 210: //For B
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 420 ... 490: //For F
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 630 ... 700: //For I
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;	
					}
					break;
				case 1261 ... 1330: //For 4
					switch (y)
					{
					case 140 ... 210: //For B
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 280 ... 350: //For D
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;		
					case 420 ... 490: //For F
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 630 ... 700: //For I
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1331 ... 1400: //For 5
					switch (y)
					{
					case 280 ... 350: //For D
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1401 ... 1470: //For 6
					switch (y)
					{
					case 280 ... 350: //For D
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1471 ... 1540: //For 7
					switch (y)
					{
					case 280 ... 350: //For D
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1541 ... 1610: //For 8
					switch (y)
					{
					case 560 ... 630: //For H
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1611 ... 1680: //For 9
					switch (y)
					{
					case 560 ... 630: //For H
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 70 ... 140: //For A
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;
					}
					break;
				case 1681 ... 1750: //For 10
					switch (y)
					{
					case 560 ... 630: //For H
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 70 ... 140: //For A
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 280 ... 350: //For D
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					case 700 ... 770: //For J
						turn=1;
						hit=1;
						timer=1000;
						countx++;
						county++;
						tempx[countx]=((x/70)*70);
						tempy[county]=((y/70)*70);
						userscore+=60;
						break;
					default:
					turn=2;
					miss=1;
					countx1++;
					county1++;
					tempx1[countx1]=((x/70)*70);
					tempy1[county1]=((y/70)*70);
					break;		
					}
					break;
				}
			}
			if (turn==2){
				switch(x)
				{
				case 70 ... 770: //For entire user grid x-coordinates
					switch (y)
					{
					case 70 ... 770: //For entire user grid y-coordinates
						if (x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x3-140) && x<(x3+70) && y>(y3) && y<y3+70){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x4-140) && x<(x4+70) && y>(y4) && y<(y4+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x5-70) && x<(x5+70) && y>(y5) && y<(y5+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x6-70) && x<(x6+70) && y>(y6) && y<(y6+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x7-70) && x<(x7+70) && y>(y7) && y<(y7+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x8) && x<(x8+70) && y>(y8) && y<(y8+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x9) && x<(x9+70) && y>(y9) && y<(y9+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x10) && x<(x10+70) && y>(y10) && y<(y10+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x11) && x<(x11+70) && y>(y11) && y<(y11+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						/*if((x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70) && (x>(x3-210) && x<(x3+70) && y>(y3) && y<y3+70) && (x>(x4-210) && x<(x4+70) && y>(y4) && y<y4+70) && (x>(x5-210) && x<(x5+70) && y>(y5) && y<y5+70) && (x>(x6-210) && x<(x6+70) && y>(y6) && y<y6+70) && (x>(x7-210) && x<(x7+70) && y>(y7) && y<y7+70) && (x>(x8-210) && x<(x8+70) && y>(y8) && y<y8+70) && (x>(x9-210) && x<(x9+70) && y>(y9) && y<y9+70) && (x>(x10-210) && x<(x10+70) && y>(y10) && y<y10+70) && (x>(x11-210) && x<(x11+70) && y>(y11) && y<y11+70)) {
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}*/
						//if(!(x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70) && !(x>(x3-210) && x<(x3+70) && y>(y3) && y<y3+70) && !(x>(x4-210) && x<(x4+70) && y>(y4) && y<y4+70) && !(x>(x5-210) && x<(x5+70) && y>(y5) && y<y5+70) && !(x>(x6-210) && x<(x6+70) && y>(y6) && y<y6+70) && !(x>(x7-210) && x<(x7+70) && y>(y7) && y<y7+70) && !(x>(x8-210) && x<(x8+70) && y>(y8) && y<y8+70) && !(x>(x9-210) && x<(x9+70) && y>(y9) && y<y9+70) && !(x>(x10-210) && x<(x10+70) && y>(y10) && y<y10+70) && !(x>(x11-210) && x<(x11+70) && y>(y11) && y<y11+70)) {
						else {
							turn=1;
							opponentmiss=1;
							opponentcountx1++;
							opponentcounty1++;
							opponenttempx1[opponentcountx1]=((x/70)*70);
							opponenttempy1[opponentcounty1]=((y/70)*70);
							break;
						}
					}
				}
			}
	} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

void OpponentsTurn(){
			if (turn==2){
				srand(time(0));
				x=(rand()%770);
				if (x<70){
					x+=70;
				}
				switch(x)
				{
				case 70 ... 770: //For entire user grid x-coordinates
					y=(rand()%770);
					if (y<70){
						y+=70;
					}
					switch (y)
					{
					case 70 ... 770: //For entire user grid y-coordinates
						/*if (test[0]==)*/
						if((x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70) && (x>(x3-210) && x<(x3+70) && y>(y3) && y<y3+70) && (x>(x4-210) && x<(x4+70) && y>(y4) && y<y4+70) && (x>(x5-210) && x<(x5+70) && y>(y5) && y<y5+70) && (x>(x6-210) && x<(x6+70) && y>(y6) && y<y6+70) && (x>(x7-210) && x<(x7+70) && y>(y7) && y<y7+70) && (x>(x8-210) && x<(x8+70) && y>(y8) && y<y8+70) && (x>(x9-210) && x<(x9+70) && y>(y9) && y<y9+70) && (x>(x10-210) && x<(x10+70) && y>(y10) && y<y10+70) && (x>(x11-210) && x<(x11+70) && y>(y11) && y<y11+70)) {
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if(!(x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70) && !(x>(x3-210) && x<(x3+70) && y>(y3) && y<y3+70) && !(x>(x4-210) && x<(x4+70) && y>(y4) && y<y4+70) && !(x>(x5-210) && x<(x5+70) && y>(y5) && y<y5+70) && !(x>(x6-210) && x<(x6+70) && y>(y6) && y<y6+70) && !(x>(x7-210) && x<(x7+70) && y>(y7) && y<y7+70) && !(x>(x8-210) && x<(x8+70) && y>(y8) && y<y8+70) && !(x>(x9-210) && x<(x9+70) && y>(y9) && y<y9+70) && !(x>(x10-210) && x<(x10+70) && y>(y10) && y<y10+70) && !(x>(x11-210) && x<(x11+70) && y>(y11) && y<y11+70)) {
							turn=1;
							opponentmiss=1;
							opponentcountx1++;
							opponentcounty1++;
							opponenttempx1[opponentcountx1]=((x/70)*70);
							opponenttempy1[opponentcounty1]=((y/70)*70);
							break;
						}
					}
				}
			}
}

//Function to display STARTGAME window
void StartGame(){
	
	int width = 1845, height = 840; // i have set my window size to be 1845 x 840

	InitRandomizer(); // seed the random number generator...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMouseFunc(MouseClickedStartGame); // Mouse

	glutDisplayFunc(GameDisplayStartGame);
		
	glutPostRedisplay();
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveObject();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*These functions are called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * These functions have two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << 840-y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	cout << x << " " << 840-y << endl;
	glutPostRedisplay();
}

/*
 * Main Canvas drawing function.
 */
/*
 * Our gateway main function
 */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 1020 x 840

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	glutPostRedisplay();
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */

/*
 * Some (extra) attempts to check coordinates
 */

//Error handling functions to check coordinates
//bool coordinatescheck1(){
/*void coordinatescheck1(){	
	if (Replace2==2){
	
	if (x>=(x3-210) && x<=(x3+140) && (y>=y3-140) && (y<=y3+70)){
		//error=1;
		return false;
	}
}
if (Replace3==2){
	
	if (x>=(x4-210) && x<=(x4+140) && (y>=y4-140) && (y<=y4+70)){
		//error=1;
		return false;
	}
}
if (Replace4==2){
	
	if (x>=(x5-140) && x<=(x5+140) && (y>=y5-140) && (y<=y5+70)){
		//error=1;
		return false;
	}
}
if (Replace5==2){
	
	if (x>=(x6-140) && x<=(x6+140) && (y>=y6-140) && (y<=y6+70)){
		error=1;
	}
}
if (Replace6==2){
	
	if (x>=(x7-140) && x<=(x7+140) && (y>=y7-140) && (y<=y7+70)){
		error=1;
	}
}
if (Replace7==2){
	
	if (x>=(x8-70) && x<=(x8+140) && (y>=y8-140) && (y<=y8+70)){
		error=1;
	}
}
if (Replace8==2){
	
	if (x>=(x9-70) && x<=(x9+140) && (y>=y9-140) && (y<=y9+70)){
		error=1;
	}
}
if (Replace9==2){
	
	if (x>=(x10-70) && x<=(x10+140) && (y>=y10-140) && (y<=y10+70)){
		error=1;
	}
}
if (Replace10==2){
	
	if (x>=(x11-70) && x<=(x11+140) && (y>=y11-140) && (y<=y11+70)){
		error=1;
	}
}
return true;
}
*/

/*
 * Some (extra) functions for help

//-> //drawObject(); //(l34:drawobject)Draws object which then using the next function (l41:moveobject) moves on the screen.

//-> //Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
*/
	/*DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);*/


/*	if youhave to change something specific in every condition:
						if (x>(x2-210) && x<(x2+70) && y>(y2) && y<y2+70){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x3-140) && x<(x3+70) && y>(y3) && y<y3+70){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x4-140) && x<(x4+70) && y>(y4) && y<(y4+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x5-70) && x<(x5+70) && y>(y5) && y<(y5+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x6-70) && x<(x6+70) && y>(y6) && y<(y6+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x7-70) && x<(x7+70) && y>(y7) && y<(y7+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x8) && x<(x8+70) && y>(y8) && y<(y8+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x9) && x<(x9+70) && y>(y9) && y<(y9+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x10) && x<(x10+70) && y>(y10) && y<(y10+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
						if (x>(x11) && x<(x11+70) && y>(y11) && y<(y11+70)){
							turn=2;
							opponenthit=1;
							opponentcountx++;
							opponentcounty++;
							opponenttempx[opponentcountx]=((x/70)*70);
							opponenttempy[opponentcounty]=((y/70)*70);
							opponentscore+=60;
							break;
						}
*/