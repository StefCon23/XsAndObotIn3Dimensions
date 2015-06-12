#include<stdio.h>
#include<allegro.h>
#include<stdlib.h>
#include<math.h>

BITMAP * backBuffer;


struct point
{
	float x;
	float y;
	float z;
};


//////~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



void sixShoot(float & r, float & g, float & b)
{
	// Colour 6 Shooter
	//   solid rand colours
	//   reproduces [respectively]:
	//      red				0
	//      green			1
	//      blue			2
	//      yellow/orange	3
	//      purple			4
	//      turkoise?		5
	int col;
	col = rand()%6;
	if(col==0)
	{
		r=rand()%256;
		g=0;
		b=0;
	}
	else if(col==1)
	{
		r=0;
		g=rand()%256;
		b=0;
	}
	else if(col==2)
	{
		r=0;
		g=0;
		b=rand()%256;
	}
	else if(col==3)
	{
		r=rand()%256;
		g=rand()%256;
		b=0;
	}
	else if(col==4)
	{
		r=rand()%256;
		g=0;
		b=rand()%256;
	}
	else if(col==5)
	{
		r=0;
		g=rand()%256;
		b=rand()%256;
	}
}

float archer(int xOrY, float centerP, float radius, float angle)
{

	int x;

	float radian=(angle*3.14159265)/180;
	
	float differ;
	differ = xOrY == 0 ? (radius * cos(radian)) : (radius * sin(radian));

	x = centerP + differ;

	return x;

}


void rotate(point realWorld, float angle, char axis, point & rotation)
{
	/*
		rotation function
	rotates realworld co-ordinates
	about defined axis (char)
	by angle

	stores transformation in point projection
	*/

	while(angle>=360)
	{
		angle -= 360;
	}

	float radian = (angle * 3.14159265) / 180;

	if(axis=='x')
	{
		rotation.x = realWorld.x;
		rotation.y = (realWorld.y * cos(radian)) + (realWorld.z * sin(radian));
		rotation.z = (realWorld.z * cos(radian)) - (realWorld.y * sin(radian));
	}
	else if(axis=='y')
	{
		rotation.x = (realWorld.x * cos(radian)) - (realWorld.z * sin(radian));
		rotation.y = realWorld.y;
		rotation.z = (realWorld.z * cos(radian)) + (realWorld.x * sin(radian));
	}
	else if(axis=='z')
	{
		rotation.x = (realWorld.x * cos(radian)) + (realWorld.y * sin(radian));
		rotation.y = (realWorld.y * cos(radian)) - (realWorld.x * sin(radian));
		rotation.z = realWorld.z;
	}
}

//void robotTurn(int squares[3][3][3], int turns[27])
//{
//	/*
//	defend
//	attack
//	aquire property
//	*/
//
//
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	////////wins
//	//	axiss
//	i=0;
//	while(i<3)
//	{
//		j=0;
//		while(j<3)
//		{
//
//			//x direct
//			if((squares[i][j][0]==squares[i][j][1])&&(squares[i][j][1]==squares[i][j][2]))
//			{
//				turns[j + (3 * i)] = squares[i][j][1];
//				//draw
//				if(squares[i][j][1] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[i][j][2].x, h/2 + gridPoints[i][j][2].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if(squares[i][j][1] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[i][j][2].x, h/2 + gridPoints[i][j][2].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//			//y direction
//			if((squares[i][0][j] == squares[i][1][j]) && (squares[i][1][j] == squares[i][2][j]))
//			{
//				turns[9 + j + (3 * i)] = squares[i][1][j];
//				//draw
//				if( squares[i][1][j] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[i][2][j].x, h/2 + gridPoints[i][2][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if( squares[i][1][j] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[i][2][j].x, h/2 + gridPoints[i][2][j].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//			//z direction
//			if((squares[0][i][j] == squares[1][i][j]) && (squares[1][i][j] == squares[2][i][j]))
//			{
//				turns[18 + (j * 3) + i] = squares[1][i][j];
//				//draw
//				if( squares[1][i][j] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[0][i][j].x, h/2 + gridPoints[0][i][j].y, w/2 + gridPoints[2][i][j].x, h/2 + gridPoints[2][i][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if( squares[1][i][j] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[0][i][j].x, h/2 + gridPoints[0][i][j].y, w/2 + gridPoints[2][i][j].x, h/2 + gridPoints[2][i][j].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//
//			j++;
//		}
//		i++;
//	}
//
//
//	//	single diagonal loop
//	j = 0;
//	while(j < 3)
//	{
//		i = 0;
//		while(i < 3)
//		{
//
//			//front & back
//			if((squares[j][0][0 + i] == squares[j][1][1]) && (squares[j][1][1] == squares[j][2][2 - i]))
//			{
//				turns[(27 + j) + (i / 2)] = squares[j][1][1];
//				//draw
//				if( squares[j][1][1] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[j][0][0 + i].x, h/2 + gridPoints[j][0][0 + i].y, w/2 + gridPoints[j][2][2 - i].x, h/2 + gridPoints[j][2][2 - i].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if( squares[j][1][1] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[j][0][0 + i].x, h/2 + gridPoints[j][0][0 + i].y, w/2 + gridPoints[j][2][2 - i].x, h/2 + gridPoints[j][2][2 - i].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//
//			//top & bottom
//			if((squares[i][j][0] == squares[1][j][1]) && (squares[1][j][1] == squares[2 - i][j][2]))
//			{
//				turns[(31 + j) + (i / 2)] = squares[1][j][1];
//				if(squares[1][j][1] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[2 - i][j][2].x, h/2 + gridPoints[2 - i][j][2].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if(squares[1][j][1] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[2 - i][j][2].x, h/2 + gridPoints[2 - i][j][2].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//
//			//left & right
//			if((squares[i][0][j] == squares[1][1][j]) && (squares[1][1][j] == squares[2 - i][2][j]))
//			{
//				turns[(35 + j) + (i / 2)] = squares[1][1][j];
//				if( squares[1][1][j] == 1)
//				{
//					line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[2 - i][2][j].x, h/2 + gridPoints[2 - i][2][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
//				}
//				else if( squares[1][1][j] == 2)
//				{
//					line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[2 - i][2][j].x, h/2 + gridPoints[2 - i][2][j].y, makecol(yCol.x, yCol.y, yCol.z));
//				}
//			}
//
//
//			i += 2;
//		}
//
//		j += 2;
//	}
//
//
//	//	supermid loop
//	int winCount = 0;
//	//if(squares[1][4] != 0)
//	//{
//		i = 0;
//		while(i < 2)
//		{
//			j = 0;
//			while(j < 3)
//			{
//				k = 0;
//				while(k < 3)
//				{
//
//					if((j==1)&&(k==1))
//					{
//						//	skips centre mid in front, middle and back layers
//						//	which is covered by the z direktion in axiss loops
//						k ++;
//					}
//					if((i==1)&&(j==0)&&(k==1))
//					{
//						//	skips top centre mid
//						//	covered by the y direktion in axiss loops
//						k ++;
//					}
//					if((i==0)&&(j==1)&&(k==0))
//					{
//						//	skips front centre mid
//						//	covered by the x direktion in axiss loops
//						k ++;
//					}
//					if((i==1)&&(j==1)&&(k==0))
//					{
//						i = 2;
//						j = 3;
//						k = 3;
//						break;
//					}
//
//					if((squares[j][i][k] == squares[1][1][1]) && (squares[1][1][1] == squares[2 - i][2 - j][2 - k]))
//					{
//						turns[39 + winCount] = squares[1][1][1];
//						//	turns[] at 39 to 
//						if( squares[1][1][1] == 1)
//						{
//							line(backBuffer, w/2 + gridPoints[j][i][k].x, h/2 + gridPoints[j][i][k].y, w/2 + gridPoints[2 - i][2 - j][2 - k].x, h/2 + gridPoints[2 - i][2 - j][2 - k].y, makecol(xCol.x, xCol.y, xCol.z)); 
//						}
//						else if( squares[1][1][1] == 2)
//						{
//							line(backBuffer, w/2 + gridPoints[j][i][k].x, h/2 + gridPoints[j][i][k].y, w/2 + gridPoints[2 - i][2 - j][2 - k].x, h/2 + gridPoints[2 - i][2 - j][2 - k].y, makecol(yCol.x, yCol.y, yCol.z));
//						}
//					}
//
//					winCount ++;
//
//					k ++;
//				}
//				j ++;
//			}
//			i ++;
//		}
//
//
//
//
//
//
//
//
//
//}
/*
void trinarise(int x, int y, int z, int outPut[], int decimal)
{
	int base = 3;
	//  turns i, j, k into decimal
	//    or decimal into i, j, k
	//  if either i, j, k or decimal
	//    is zero
	//  (does not convert 0)

	if(decimal == 0)
	{
		decimal = (x * pow((float)base, 2)) + (y * pow((float)base, 1)) + z;
	}
	else
	{
		/*
		int i = 3;
		//i = sizeof(outPut);
		//while(i >= 0)
		while(i >= 0)
		{
			if(decimal % pow((double)base, (double)i));

			i --;
		}
		/*
		/*

		if(decimal % 9 == 0)
		{

		}

		i = decimal % base;
		
		if(decimal % pow == 0)
		{
			i = 0;
			decimal -= ;
		}
		if(decimal % pow == 0)
		{
			i = 0;
		}
		decimal = (x * pow((float)base, 2)) + (y * pow((float)base, 1)) + z;
	}
	


}*/

int robotTurn(int squares[3][3][3], int playAs1forX)
{
	/*
	defend
	attack
	aquire property
	*/

	/*
	keep property definite and
	consistent among all moves
	7 - super mid
	7 - corners
	5 - single mids
	4 - edges
	*/

	int i = 0;
	int j = 0;
	int k = 0;

	/*
	move represents what
	the computer does
	
	x's - 1
	o's - 2

	1 - defend
	2 - attack
	0 - aquire property
	*/
	int move = 1;

	while(move < 3)
	{
		//	axis
		i=0;
		while(i<3)
		{
			j=0;
			while(j<3)
			{

				//x direct
				if(squares[i][j][0] == squares[i][j][1])
				{
					if((squares[i][j][0] == move) && 
						(squares[i][j][2] == 0))
					{
						squares[i][j][2] = playAs1forX;
					}
				}
				if(squares[i][j][0] == squares[i][j][2])
				{
					if((squares[i][j][0] == move) && 
						(squares[i][j][1] == 0))
					{
						squares[i][j][1] = playAs1forX;
					}
				}
				if(squares[i][j][1] == squares[i][j][2])
				{
					if((squares[i][j][1] == move) && 
						(squares[i][j][0] == 0))
					{
						squares[i][j][0] = playAs1forX;
					}
				}
				//y direction
				if(squares[i][0][j] == squares[i][1][j])
				{
					if((squares[i][0][j] == move) && 
						(squares[i][2][j] == 0))
					{
						squares[i][2][j] = playAs1forX;
					}
				}
				if(squares[i][0][j] == squares[i][2][j])
				{
					if((squares[i][0][j] == move) && 
						(squares[i][1][j] == 0))
					{
						squares[i][1][j] = playAs1forX;
					}
				}
				if(squares[i][1][j] == squares[i][2][j])
				{
					if((squares[i][1][j] == move) && 
						(squares[i][0][j] == 0))
					{
						squares[i][0][j] = playAs1forX;
					}
				}
				//z direction
				if(squares[0][i][j] == squares[1][i][j])
				{
					if((squares[0][i][j] == move) && 
						(squares[2][i][j] == 0))
					{
						squares[2][i][j] = playAs1forX;
					}
				}
				if(squares[0][i][j] == squares[2][i][j])
				{
					if((squares[0][i][j] == move) && 
						(squares[1][i][j] == 0))
					{
						squares[1][i][j] = playAs1forX;
					}
				}
				if(squares[1][i][j] == squares[2][i][j])
				{
					if((squares[1][i][j] == move) && 
						(squares[0][i][j] == 0))
					{
						squares[0][i][j] = playAs1forX;
					}
				}

				j++;
			}
			i++;
		}


		//	single diagonal loop
		j = 0;
		while(j < 3)
		{
			i = 0;
			while(i < 3)
			{

				//front & back
				if((squares[j][0][0 + i] == squares[j][1][1]) && (squares[j][1][1] == squares[j][2][2 - i]))
				{
				
				}

				//top & bottom
				if((squares[i][j][0] == squares[1][j][1]) && (squares[1][j][1] == squares[2 - i][j][2]))
				{
				
				}

				//left & right
				if((squares[i][0][j] == squares[1][1][j]) && (squares[1][1][j] == squares[2 - i][2][j]))
				{
				
				}


				i += 2;
			}

			j += 2;
		}


		//	supermid loop

		//  super mid loop attempt 2
		//	    2013-04-15
		k = 0;
		while(k < 3)
		{
			j = 0;
			while(j < 3)
			{
				i = 0;
				while(i < 3)
				{
					//  has to skip:
					//  x, y, z directions
					//  single middle bits
					//      ^ same diff
					if((i == 1) && (j == 1) && (k == 0))
					{
						//  single mid front
						i ++;
					}
					if((i == 1) && (j == 0) && (k == 1))
					{
						//  single mid top
						i ++;
					}

					if((squares[i][j][k] == squares[1][1][1]) && (squares[1][1][1] == squares[2 - i][2 - j][2 - k]))
					{
						if( squares[1][1][1] == 1)
						{
							
						}
						else if( squares[1][1][1] == 2)
						{
							
						}
					}

					
					if((i == 2) && (j == 0) && (k == 1))
					{
						//  top right corner
						//  last run, break now
						i = 2;
						j = 2;
						k = 2;
						//  breaks the loop
					}


					i ++;
				}
				j ++;
			}
			k ++;
		}

			if(move == 1)
			{
				move ++;
			}
			else if(move == 2)
			{
				move = 0;
			}
			else if(move == 0)
			{
				move = 3;
			}
		}




		return move;
		///idea is to return a digit representing a 2-0-1
		// style co ordinate, to be decoded after the function
		// and serve as the move


}




//////~~~~~~~~~~~~~~~~~~~~/FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



void main()
{
	if(allegro_init() != 0)
	{
		return;
	}
	set_color_depth(desktop_color_depth());
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 500, 0, 0) != 0)
	{
		return;
	}
	backBuffer = create_bitmap(500, 500);

//////~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


	//	screen height and width
	int w = 500;
	int h = 500;
	//	tickers
	int i = 0;
	int j = 0;
	int k = 0;
	point t = {0, 0, 0};

	point colour = {0, 0, 0};

	point xCol = {255, 0, 0};
	point yCol = {0, 255, 255};

	point angle = {0, 0, 0};
	float speed = 0.3;

	//	selector
	bool select = false;
	int selectI, selectJ, selectK;
	int selectRad = (w / 5) / 3;
	point selectCol = {0, 255, 0};
	bool click = false;

	//point gridMid = {0, 0, 0};

	float box = w / 5;

	//	xs and os, grid and squares
	point gridCoors[4][4][4];
	point gridPoints[3][3][3];
	//setup original values
	point gridCoorsO[4][4][4];
	point gridPointsO[3][3][3];
	//	x or o state
	// 0 for clear
	// 1 for x
	// 2 for o
	int gridValues[3][3][3];
	//	score
	int xWins = 0;
	int oWins = 0;
	int wins[49];
	i = 0;
	while(i < 49)
	{
		wins[i] = 0;
		i ++;
	}
	
	//init gridcoors
	i=0;
	t.z = box - w/2;
	while(i<4)
	{
		j=0;
		t.y = box - h/2;
		while(j<4)
		{
			k=0;
			t.x = box - w/2;
			while(k<4)
			{
				gridCoors[i][j][k].x = t.x;
				gridCoors[i][j][k].y = t.y;
				gridCoors[i][j][k].z = t.z;

				//	copy values
				gridCoorsO[i][j][k].x = t.x;
				gridCoorsO[i][j][k].y = t.y;
				gridCoorsO[i][j][k].z = t.z;

				t.x += box;
				k++;
			}
			t.y += box;
			j++;
		}
		t.z += box;
		i++;
	}
	//init gridpoints
	i=0;
	t.z = box + box/2 - w/2;
	while(i<3)
	{
		j=0;
		t.y = box + box/2 - h/2;
		while(j<3)
		{
			k=0;
			t.x = box + box/2 - w/2;
			while(k<3)
			{
				gridPoints[i][j][k].x = t.x;
				gridPoints[i][j][k].y = t.y;
				gridPoints[i][j][k].z = t.z;

				//	copy values to original
				gridPointsO[i][j][k].x = t.x;
				gridPointsO[i][j][k].y = t.y;
				gridPointsO[i][j][k].z = t.z;

				t.x += box;
				k++;
			}
			t.y += box;
			j++;
		}
		t.z += box;
		i++;
	}
	//init gridvals
	i = 0;
	while(i<3)
	{
		j=0;
		while(j<3)
		{
			k=0;
			while(k<3)
			{
				gridValues[i][j][k]=0;
				k++;
			}
			j++;
		}
		i++;
	}

	float buttonX, buttonY, buttonRadius;
	bool trippinBalls = false;

	float mx3 = 0;
	float my3 = 0;

	bool game = false;
	bool humanMove = false;
	bool robotMove = false;
	int gameTurns[27];
	i=0;
	while(i<27)
	{
		gameTurns[i]=0;
		i++;
	}

	int playAs = 0;
	bool botGame = false;

	int jerchoI = 4, jerchoJ = 4, jerchoK = 4;


//////~~~~~~~~~~~~~~~~~~~~/VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	install_mouse();
	install_keyboard();

	bool done = false;
	while (! done)
	{
		if (key[KEY_ESC])
		{
			done = true;
			break;
		}
		clear_to_color(backBuffer, makecol(0, 0, 0));


//////~~~~~~~~~~~~~~~~~~~~CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/*
		//Button Template
		buttonX = 45;
		buttonY = 40;
		buttonRadius = 25;
		//copy-paste from here, (use same floats through code to avoid find replaces)--> to be confirmed
		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
		//   y co-ordinates vary in textprint lines
		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 5), makecol(150, 150, 150), "2 Line");
		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 5), makecol(150, 150, 150), "Button Title");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) )
		{
			if(mouse_b&1)
			{
				//while mouse is still within button
				while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) )
				{

					//code

				}
			}
		}*/

		
		//  current cell
		if(select)
		{
			jerchoI = selectI;
			jerchoJ = selectJ;
			jerchoK = selectK;
		}
		//textprintf(backBuffer, font, (3 * w) / 4, h/2, makecol(255, 255, 255), "[ %d ][ %d ][ %d ]", jerchoI, jerchoJ, jerchoK);

		//	cursor
		sixShoot(colour.x, colour.y, colour.z);
		line(backBuffer, mouse_x, mouse_y, mouse_x, mouse_y + 17, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, mouse_x, mouse_y, mouse_x + 11, mouse_y + 11, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, mouse_x, mouse_y + 17, mouse_x + 11, mouse_y + 11, makecol(colour.x, colour.y, colour.z));

		////	grid
		//line(backBuffer, gridCoors[][].x, gridCoors[][].y, gridCoors[][].x, gridCoors[][].y, makecol(colour.x, colour.y, colour.z));
		colour.x = 0;
		colour.y = 255;
		colour.z = 0;
		if(trippinBalls)
		{
			colour.x = rand() % 256;
			colour.y = rand() % 256;
			colour.z = rand() % 256;
		}
		/*
		debug info:
		2 different coloured dots
		on each end of the grid lines
		one colour on the 0 points
		different colour on the max points
		*/
		//	red, early points
		point col1 = {255, 0, 0};
		//	blue, late points
		point col2 = {0, 0, 255};

		//	x axis
		line(backBuffer, w/2 + gridCoors[1][1][0].x, h/2 + gridCoors[1][1][0].y, w/2 + gridCoors[1][1][3].x, h/2 + gridCoors[1][1][3].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[1][2][0].x, h/2 + gridCoors[1][2][0].y, w/2 + gridCoors[1][2][3].x, h/2 + gridCoors[1][2][3].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[2][1][0].x, h/2 + gridCoors[2][1][0].y, w/2 + gridCoors[2][1][3].x, h/2 + gridCoors[2][1][3].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[2][2][0].x, h/2 + gridCoors[2][2][0].y, w/2 + gridCoors[2][2][3].x, h/2 + gridCoors[2][2][3].y, makecol(colour.x, colour.y, colour.z));
		//	debug dots
		//		earlys
		putpixel(backBuffer, w/2 + gridCoors[1][1][0].x, h/2 + gridCoors[1][1][0].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[1][2][0].x, h/2 + gridCoors[1][2][0].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[2][1][0].x, h/2 + gridCoors[2][1][0].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[2][2][0].x, h/2 + gridCoors[2][2][0].y, makecol(col1.x, col1.y, col1.z));
		//		lates
		putpixel(backBuffer, w/2 + gridCoors[1][1][3].x, h/2 + gridCoors[1][1][3].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[1][2][3].x, h/2 + gridCoors[1][2][3].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[2][1][3].x, h/2 + gridCoors[2][1][3].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[2][2][3].x, h/2 + gridCoors[2][2][3].y, makecol(col2.x, col2.y, col2.z));

		if(trippinBalls)
		{
			colour.x = rand() % 256;
			colour.y = rand() % 256;
			colour.z = rand() % 256;
		}
		//	y axis
		line(backBuffer, w/2 + gridCoors[1][0][1].x, h/2 + gridCoors[1][0][1].y, w/2 + gridCoors[1][3][1].x, h/2 + gridCoors[1][3][1].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[1][0][2].x, h/2 + gridCoors[1][0][2].y, w/2 + gridCoors[1][3][2].x, h/2 + gridCoors[1][3][2].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[2][0][1].x, h/2 + gridCoors[2][0][1].y, w/2 + gridCoors[2][3][1].x, h/2 + gridCoors[2][3][1].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[2][0][2].x, h/2 + gridCoors[2][0][2].y, w/2 + gridCoors[2][3][2].x, h/2 + gridCoors[2][3][2].y, makecol(colour.x, colour.y, colour.z));
		//	debug dots
		//		earlys
		putpixel(backBuffer, w/2 + gridCoors[1][0][1].x, h/2 + gridCoors[1][0][1].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[1][0][2].x, h/2 + gridCoors[1][0][2].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[2][0][1].x, h/2 + gridCoors[2][0][1].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[2][0][2].x, h/2 + gridCoors[2][0][2].y, makecol(col1.x, col1.y, col1.z));
		//		lates
		putpixel(backBuffer, w/2 + gridCoors[1][3][1].x, h/2 + gridCoors[1][3][1].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[1][3][2].x, h/2 + gridCoors[1][3][2].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[2][3][1].x, h/2 + gridCoors[2][3][1].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[2][3][2].x, h/2 + gridCoors[2][3][2].y, makecol(col2.x, col2.y, col2.z));
		
		if(trippinBalls)
		{
			colour.x = rand() % 256;
			colour.y = rand() % 256;
			colour.z = rand() % 256;
		}
		//	z axis
		line(backBuffer, w/2 + gridCoors[0][1][1].x, h/2 + gridCoors[0][1][1].y, w/2 + gridCoors[3][1][1].x, h/2 + gridCoors[3][1][1].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[0][1][2].x, h/2 + gridCoors[0][1][2].y, w/2 + gridCoors[3][1][2].x, h/2 + gridCoors[3][1][2].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[0][2][1].x, h/2 + gridCoors[0][2][1].y, w/2 + gridCoors[3][2][1].x, h/2 + gridCoors[3][2][1].y, makecol(colour.x, colour.y, colour.z));
		line(backBuffer, w/2 + gridCoors[0][2][2].x, h/2 + gridCoors[0][2][2].y, w/2 + gridCoors[3][2][2].x, h/2 + gridCoors[3][2][2].y, makecol(colour.x, colour.y, colour.z));
		//	debug dots
		//		earlys
		putpixel(backBuffer, w/2 + gridCoors[0][1][1].x, h/2 + gridCoors[0][1][1].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[0][1][2].x, h/2 + gridCoors[0][1][2].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[0][2][1].x, h/2 + gridCoors[0][2][1].y, makecol(col1.x, col1.y, col1.z));
		putpixel(backBuffer, w/2 + gridCoors[0][2][2].x, h/2 + gridCoors[0][2][2].y, makecol(col1.x, col1.y, col1.z));
		//		lates
		putpixel(backBuffer, w/2 + gridCoors[3][1][1].x, h/2 + gridCoors[3][1][1].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[3][1][2].x, h/2 + gridCoors[3][1][2].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[3][2][1].x, h/2 + gridCoors[3][2][1].y, makecol(col2.x, col2.y, col2.z));
		putpixel(backBuffer, w/2 + gridCoors[3][2][2].x, h/2 + gridCoors[3][2][2].y, makecol(col2.x, col2.y, col2.z));


		xCol.x = 255;
		xCol.y = 0;
		xCol.z = 0;

		yCol.x = 0;
		yCol.y = 255;
		yCol.z = 255;
		
		if(trippinBalls)
		{
			sixShoot(xCol.x, xCol.x, xCol.x);
			sixShoot(yCol.y, yCol.y, yCol.z);
		}

		
		//	xs & os AND grid dots
		i = 0;
		while(i < 3)
		{
			j = 0;
			while(j < 3)
			{
				k = 0;
				while(k < 3)
				{
					if(gridValues[i][j][k] == 1)
					{
						line(backBuffer, w/2 + gridPoints[i][j][k].x - box/5, h/2 + gridPoints[i][j][k].y - box/5, w/2 + gridPoints[i][j][k].x + box/5, h/2 + gridPoints[i][j][k].y + box/5, makecol(xCol.x, xCol.y, xCol.z));
						line(backBuffer, w/2 + gridPoints[i][j][k].x - box/5, h/2 + gridPoints[i][j][k].y + box/5, w/2 + gridPoints[i][j][k].x + box/5, h/2 + gridPoints[i][j][k].y - box/5, makecol(xCol.x, xCol.y, xCol.z));
					}
					else if(gridValues[i][j][k] == 2)
					{
						circle(backBuffer, w/2 + gridPoints[i][j][k].x, h/2 + gridPoints[i][j][k].y, box/5, makecol(yCol.x, yCol.y, yCol.z));
					}
					else
					{
						colour.x = 0;
						colour.y = 255;
						colour.z = 0;
						putpixel(backBuffer, w/2 + gridPoints[i][j][k].x, h/2 + gridPoints[i][j][k].y, makecol(colour.x, colour.y, colour.z));
					}
					k ++;
				}
				j ++;
			}
			i ++;
		}


		//	wins
		// x win
		textprintf(backBuffer, font, w/2 - 50, h - 30, makecol(xCol.x, xCol.y, xCol.z), "x wins", xWins);
		textprintf(backBuffer, font, w/2 - 50, h - 15, makecol(xCol.x, xCol.y, xCol.z), "  %d ", xWins);
		// o wins
		textprintf(backBuffer, font, w/2 + 50, h - 30, makecol(yCol.x, yCol.y, yCol.z), "o wins", oWins);
		textprintf(backBuffer, font, w/2 + 50, h - 15, makecol(yCol.x, yCol.y, yCol.z), "  %d ", oWins);




		i=0;
		while(i<3)
		{
			j=0;
			while(j<3)
			{
				k=0;
				while(k<3)
				{
					/////////
					k++;
				}
				j++;
			}
			i++;
		}



		////////wins

		//	axiss
		i=0;
		while(i<3)
		{
			j=0;
			while(j<3)
			{

				//x direct
				if((gridValues[i][j][0]==gridValues[i][j][1])&&(gridValues[i][j][1]==gridValues[i][j][2]))
				{
					wins[j + (3 * i)] = gridValues[i][j][1];
					//draw
					if(gridValues[i][j][1] == 1)
					{
						line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[i][j][2].x, h/2 + gridPoints[i][j][2].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if(gridValues[i][j][1] == 2)
					{
						line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[i][j][2].x, h/2 + gridPoints[i][j][2].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}
				//y direction
				if((gridValues[i][0][j] == gridValues[i][1][j]) && (gridValues[i][1][j] == gridValues[i][2][j]))
				{
					wins[9 + j + (3 * i)] = gridValues[i][1][j];
					//draw
					if( gridValues[i][1][j] == 1)
					{
						line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[i][2][j].x, h/2 + gridPoints[i][2][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if( gridValues[i][1][j] == 2)
					{
						line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[i][2][j].x, h/2 + gridPoints[i][2][j].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}
				//z direction
				if((gridValues[0][i][j] == gridValues[1][i][j]) && (gridValues[1][i][j] == gridValues[2][i][j]))
				{
					wins[18 + (j * 3) + i] = gridValues[1][i][j];
					//draw
					if( gridValues[1][i][j] == 1)
					{
						line(backBuffer, w/2 + gridPoints[0][i][j].x, h/2 + gridPoints[0][i][j].y, w/2 + gridPoints[2][i][j].x, h/2 + gridPoints[2][i][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if( gridValues[1][i][j] == 2)
					{
						line(backBuffer, w/2 + gridPoints[0][i][j].x, h/2 + gridPoints[0][i][j].y, w/2 + gridPoints[2][i][j].x, h/2 + gridPoints[2][i][j].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}

				j++;
			}
			i++;
		}


		//	single diagonal loop
		j = 0;
		while(j < 3)
		{
			i = 0;
			while(i < 3)
			{

				//front & back
				if((gridValues[j][0][0 + i] == gridValues[j][1][1]) && (gridValues[j][1][1] == gridValues[j][2][2 - i]))
				{
					wins[(27 + j) + (i / 2)] = gridValues[j][1][1];
					//draw
					if( gridValues[j][1][1] == 1)
					{
						line(backBuffer, w/2 + gridPoints[j][0][0 + i].x, h/2 + gridPoints[j][0][0 + i].y, w/2 + gridPoints[j][2][2 - i].x, h/2 + gridPoints[j][2][2 - i].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if( gridValues[j][1][1] == 2)
					{
						line(backBuffer, w/2 + gridPoints[j][0][0 + i].x, h/2 + gridPoints[j][0][0 + i].y, w/2 + gridPoints[j][2][2 - i].x, h/2 + gridPoints[j][2][2 - i].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}

				//top & bottom
				if((gridValues[i][j][0] == gridValues[1][j][1]) && (gridValues[1][j][1] == gridValues[2 - i][j][2]))
				{
					wins[(31 + j) + (i / 2)] = gridValues[1][j][1];
					if(gridValues[1][j][1] == 1)
					{
						line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[2 - i][j][2].x, h/2 + gridPoints[2 - i][j][2].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if(gridValues[1][j][1] == 2)
					{
						line(backBuffer, w/2 + gridPoints[i][j][0].x, h/2 + gridPoints[i][j][0].y, w/2 + gridPoints[2 - i][j][2].x, h/2 + gridPoints[2 - i][j][2].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}

				//left & right
				if((gridValues[i][0][j] == gridValues[1][1][j]) && (gridValues[1][1][j] == gridValues[2 - i][2][j]))
				{
					wins[(35 + j) + (i / 2)] = gridValues[1][1][j];
					if( gridValues[1][1][j] == 1)
					{
						line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[2 - i][2][j].x, h/2 + gridPoints[2 - i][2][j].y, makecol(xCol.x, xCol.y, xCol.z)); 
					}
					else if( gridValues[1][1][j] == 2)
					{
						line(backBuffer, w/2 + gridPoints[i][0][j].x, h/2 + gridPoints[i][0][j].y, w/2 + gridPoints[2 - i][2][j].x, h/2 + gridPoints[2 - i][2][j].y, makecol(yCol.x, yCol.y, yCol.z));
					}
				}


				i += 2;
			}

			j += 2;
		}


		//	supermid loop
		int winCount = 0;

		//  super mid loop attempt 2
		//	    2013-04-15
		k = 0;
		while(k < 3)
		{
			j = 0;
			while(j < 3)
			{
				i = 0;
				while(i < 3)
				{
					//  has to skip:
					//  x, y, z directions
					//  single middle bits
					//      ^ same diff
					if((i == 1) && (j == 1) && (k == 0))
					{
						//  single mid front
						i ++;
					}
					if((i == 1) && (j == 0) && (k == 1))
					{
						//  single mid top
						i ++;
					}

					if((gridValues[i][j][k] == gridValues[1][1][1]) && (gridValues[1][1][1] == gridValues[2 - i][2 - j][2 - k]))
					{
						wins[39 + winCount] = gridValues[1][1][1];
						winCount ++;
						if( gridValues[1][1][1] == 1)
						{
							line(backBuffer, w/2 + gridPoints[i][j][k].x, h/2 + gridPoints[i][j][k].y, w/2 + gridPoints[2 - i][2 - j][2 - k].x, h/2 + gridPoints[2 - i][2 - j][2 - k].y, makecol(xCol.x, xCol.y, xCol.z)); 
						}
						else if( gridValues[1][1][1] == 2)
						{
							line(backBuffer, w/2 + gridPoints[i][j][k].x, h/2 + gridPoints[i][j][k].y, w/2 + gridPoints[2 - i][2 - j][2 - k].x, h/2 + gridPoints[2 - i][2 - j][2 - k].y, makecol(yCol.x, yCol.y, yCol.z));
						}
					}

					
					if((i == 2) && (j == 0) && (k == 1))
					{
						//  top right corner
						//  last run, break now
						i = 2;
						j = 2;
						k = 2;
						//  breaks the loop
					}


					i ++;
				}
				j ++;
			}
			k ++;
		}



		i = 0;
		xWins = 0;
		oWins = 0;
		while(i<49)
		{
			if(wins[i]==1)
			{
				xWins ++;
			}
			else if(wins[i]==2)
			{
				oWins ++;
			}
			i++;
		}

		//
		////	axis lines
		//// x axis
		//sixShoot(colour.x, colour.y, colour.z);
		//line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[0][3].x), h/2 + (gridCoors[0][3].y - 50), makecol(colour.x, colour.y, colour.z));
		//textprintf(backBuffer, font, w/2 + (gridCoors[0][2].x), h/2 + (gridCoors[0][0].y - 50), makecol(colour.x, colour.y, colour.z), "x");
		//// y axis
		//sixShoot(colour.x, colour.y, colour.z);
		//line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[0][12].x - 50), h/2 + (gridCoors[0][12].y), makecol(colour.x, colour.y, colour.z));
		//textprintf(backBuffer, font, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][8].y), makecol(colour.x, colour.y, colour.z), "y");
		//// z axis
		//sixShoot(colour.x, colour.y, colour.z);
		//line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[3][0].x - 50), h/2 + (gridCoors[3][0].y - 50), makecol(colour.x, colour.y, colour.z));
		//textprintf(backBuffer, font, w/2 + (gridCoors[2][0].x - 50), h/2 + (gridCoors[2][0].y - 50), makecol(colour.x, colour.y, colour.z), "z");
		//


		

		//	rotation
		if(key[KEY_1_PAD])
		{
			angle.x -= speed;
		}
		if(key[KEY_2_PAD])
		{
			angle.x = 0;
		}
		if(key[KEY_3_PAD])
		{
			angle.x += speed;
		}

		if(key[KEY_4_PAD])
		{
			angle.y -= speed;
		}
		if(key[KEY_5_PAD])
		{
			angle.y = 0;
		}
		if(key[KEY_6_PAD])
		{
			angle.y += speed;
		}

		if(key[KEY_7_PAD])
		{
			angle.z -= speed;
		}
		if(key[KEY_8_PAD])
		{
			angle.z = 0;
		}
		if(key[KEY_9_PAD])
		{
			angle.z += speed;
		}

		if(key[KEY_0_PAD])
		{
			angle.x = 0;
			angle.y = 0;
			angle.z = 0;
		}

		while(angle.x < 0)
		{
			angle.x += 360;
		}
		while(angle.x > 360)
		{
			angle.x -= 360;
		}
		while(angle.y < 0)
		{
			angle.y += 360;
		}
		while(angle.y > 360)
		{
			angle.y -= 360;
		}
		while(angle.z < 0)
		{
			angle.z += 360;
		}
		while(angle.z > 360)
		{
			angle.z -= 360;
		}


		//	proper rotation of points
		i = 0;
		while(i < 4)
		{
			j = 0;
			while(j < 4)
			{
				k = 0;
				while(k < 4)
					{
					if(trippinBalls == false)
					{
						gridCoors[i][j][k] = gridCoorsO[i][j][k];
					}
					rotate(gridCoors[i][j][k], angle.x, 'x', gridCoors[i][j][k]);
					rotate(gridCoors[i][j][k], angle.y, 'y', gridCoors[i][j][k]);
					rotate(gridCoors[i][j][k], angle.z, 'z', gridCoors[i][j][k]);
					k ++;
				}
				j ++;
			}
			i ++;
		}
		i = 0;
		while(i < 3)
		{
			j = 0;
			while(j < 3)
			{
				k = 0;
				while(k < 3)
				{
					if(trippinBalls == false)
					{
						gridPoints[i][j][k] = gridPointsO[i][j][k];
					}
					rotate(gridPoints[i][j][k], angle.x, 'x', gridPoints[i][j][k]);
					rotate(gridPoints[i][j][k], angle.y, 'y', gridPoints[i][j][k]);
					rotate(gridPoints[i][j][k], angle.z, 'z', gridPoints[i][j][k]);
					k ++;
				}
				j ++;
			}
			i ++;
		}


		//clicking
		if(mouse_b&1)
		{
			//rotation
			if(!click)
			{

				click = true;

				mx3 = mouse_x;
				my3 = mouse_y;


			}


			//	selecting
			float mx = mouse_x;
			float my = mouse_y;

			i = 0;
			while(i<3)
			{
				j = 0;
				while(j < 3)
				{
					k = 0;
					while(k < 3)
					{
						if(gridValues[i][j][k] == 0)
						{
							//float gridRad = (3*box)/8;
							float gridRad = 25;
							if(((mx < w/2 + gridPoints[i][j][k].x + gridRad) && (mx > w/2 + gridPoints[i][j][k].x - gridRad))
								&& ((my < h/2 + gridPoints[i][j][k].y + gridRad) && (my > h/2 + gridPoints[i][j][k].y - gridRad)))
							{
								select = true;
								selectI = i;
								selectJ = j;
								selectK = k;
							}
						}
						k ++;
					}
					j ++;
				}
				i ++;
			}

			if(click)
			{
				float mx1 = mouse_x;
				float my1 = mouse_y;
				if(mx3 < mx1)
				{
					angle.y += (mx1 - mx3) / (1 / speed);
				}
				else if(mx1 < mx3)
				{
					angle.y -= (mx3 - mx1) / (1 / speed);
				}
				if(my3 < my1)
				{
					angle.x -= (my1 - my3) / (1 / speed);
				}
				else if(my1 < my3)
				{
					angle.x += (my3 - my1) / (1 / speed);
				}
				mx3 = mx1;
				my3 = my1;
			}
		}

		if(!mouse_b&1)
		{

			click = false;

		}


		//	selector
		if(select == true)
		{
			//	select ring
			circle(backBuffer, w/2 + gridPoints[selectI][selectJ][selectK].x, h/2 + gridPoints[selectI][selectJ][selectK].y, selectRad, makecol(selectCol.x, selectCol.y, selectCol.z));
			circle(backBuffer, w/2 + gridPoints[selectI][selectJ][selectK].x, h/2 + gridPoints[selectI][selectJ][selectK].y, selectRad - 5, makecol(selectCol.x, selectCol.y, selectCol.z));
			selectCol.x = 0;
			if(trippinBalls)
			{
				selectCol.x = rand()%256;
			}
			selectCol.y = rand()%256;
			selectRad --;
			//if(selectRad < box / 4)
			if(selectRad < box / 9)
			{
				selectRad = (box) / 3;
			}
			//	gameplay
			if(game)
			{
				i = 0;
				while( i < 27 )
				{
					if(gameTurns[i] == 0)
					{
						j = i;
						i = 27;
					}
					i ++;
				}

				if(j%2 == 0)
				{
					if(key[KEY_X])
					{
						gridValues[selectI][selectJ][selectK] = 1;
						select = false;
						gameTurns[j] = 1;
					}
				}
				else
				{
					if((key[KEY_O])||(key[KEY_Z]))
					{
						gridValues[selectI][selectJ][selectK] = 2;
						select = false;
						gameTurns[j] = 2;
					}
				}


			}
			else
			{
				if(key[KEY_X])
				{
					gridValues[selectI][selectJ][selectK] = 1;
					select = false;
				}
				else if((key[KEY_O])||(key[KEY_Z]))
				{
					gridValues[selectI][selectJ][selectK] = 2;
					select = false;
				}
				else if(key[KEY_C])
				{
					gridValues[selectI][selectJ][selectK] = 0;
					select = false;
				}
			}
		}


		//	game
		if(game)
		{
			bool found = false;
			int k = 0;
			i = 0;
			while( i < 27 )
			{
				if(gameTurns[i] == 0)
				{
					j = i;
					i = 27;
					found = true;
				}
				else
				{
					k ++;
				}
				i ++;
			}
			if(k < 27)
			{
				if(j%2 == 0)
				{
					rect(backBuffer,  w/2 - 60, h - 40, w/2, h, makecol(xCol.x, xCol.y, xCol.z));
					if(playAs==0)
					{
						//humanmove
					}
					else
					{
						//robt funct
						///to be written
						//dsgo
						i = 0;
						while( i < 27 )
						{
							if(gameTurns[i] == 0)
							{
								j = i;
								i = 27;
							}
							i ++;
						}

						if(playAs==1)
						{
							gameTurns[j] = 1;
						}
						if(playAs==0)
						{
							gameTurns[j] = 2;
						}
					}
				}
				else
				{
					rect(backBuffer,  w/2 + 40, h - 40, w/2 + 100, h, makecol(yCol.x, yCol.y, yCol.z));
					// robot function
					if(playAs==1)
					{
						//humanmove
					}
					else
					{
						//robt funct
						//robt funct
						///to be written
						//dsgo
						i = 0;
						while( i < 27 )
						{
							if(gameTurns[i] == 0)
							{
								j = i;
								i = 27;
							}
							i ++;
						}

						if(playAs==1)
						{
							gameTurns[j] = 1;
						}
						if(playAs==0)
						{
							gameTurns[j] = 2;
						}
					}
				}
			}
			else
			{
				//game over
			}


			rect(backBuffer, w/2, -1, w + 1, h / 6, makecol(colour.x, colour.y, colour.z));
			if(playAs==0)
			{
				rect(backBuffer, w/2 + 20 - 10, 40 - 10, w/2 + 20 + 10, 40 + 10, makecol(colour.x, colour.y, colour.z));
			}
			else if(playAs==1)
			{
				rect(backBuffer, w/2 + 60 - 10, 40 - 10, w/2 + 60 + 10, 40 + 10, makecol(colour.x, colour.y, colour.z));
			}
			if(botGame==false)
			{
				rect(backBuffer, w/2 + 170 - 10, 40 - 10, w/2 + 170 + 10, 40 + 10, makecol(colour.x, colour.y, colour.z));
			}
			else if(botGame==true)
			{
				rect(backBuffer, w/2 + 210 - 10, 40 - 10, w/2 + 210 + 10, 40 + 10, makecol(colour.x, colour.y, colour.z));
			}

			if(j==0)
			{
				textprintf(backBuffer, font, w/2 + 20, 5, makecol(colour.x, colour.y, colour.z), "play as");
				buttonX = w/2 + 20;
				buttonY = 40;
				buttonRadius = 8;
				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
					buttonX + buttonRadius, buttonY + buttonRadius, makecol(xCol.x, xCol.y, xCol.z));
				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(xCol.x, xCol.y, xCol.z), -1, "X");
				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
					if(mouse_b&1){
						//while mouse is still within button
						while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
							&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
								playAs = 0;
						}
					}
				}
				buttonX = w/2 + 60;
				buttonY = 40;
				buttonRadius = 8;
				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
					buttonX + buttonRadius, buttonY + buttonRadius, makecol(yCol.x, yCol.y, yCol.z));
				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(yCol.x, yCol.y, yCol.z), -1, "Y");
				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
					if(mouse_b&1){
						//while mouse is still within button
						while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
							&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
								playAs = 1;
						}
					}
				}

				textprintf(backBuffer, font, w/2 + 150, 5, makecol(colour.x, colour.y, colour.z), "play against");
				buttonX = w/2 + 170;
				buttonY = 40;
				buttonRadius = 8;
				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
					buttonX + buttonRadius, buttonY + buttonRadius, makecol(xCol.x, xCol.x, xCol.z));
				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(xCol.x, xCol.x, xCol.z), -1, ":)");
				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
					if(mouse_b&1){
						//while mouse is still within button
						while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
							&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
								botGame = false;
						}
					}
				}
				buttonX = w/2 + 210;
				buttonY = 40;
				buttonRadius = 8;
				rect(backBuffer, buttonX - buttonRadius, buttonY - buttonRadius, 
					buttonX + buttonRadius, buttonY + buttonRadius, makecol(yCol.y, yCol.x, yCol.z));
				textprintf_centre_ex(backBuffer, font, buttonX, buttonY, makecol(yCol.y, yCol.x, yCol.z), -1, "%c", 64);
				if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
					if(mouse_b&1){
						//while mouse is still within button
						while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
							&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
								botGame = true;
						}
					}
				}

			}

			if(found==false)
			{
				if(mouse_b&1)
				{
					game = false;
				}
			}

		}




		////	buttons
		//exit
		buttonX = 15;
		buttonY = 15;
		buttonRadius = 10;
		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(255, 100, 100));
		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(255, 100, 100));
		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(255, 100, 100), "X");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
			if(mouse_b&1){
				done = true;
				break;
			}
		}
		//game on
		buttonX = 45;
		buttonY = 15;
		buttonRadius = 10;
		point colour3 = {0, 255, 0};
		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour3.x, colour3.y, colour3.z));
		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour3.x, colour3.y, colour3.z), "G");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
				if(mouse_b&1)
				{
					if(game == false)
					{

						game = true;
						i = 0;
						while(i < 3)
						{
							j = 0;
							while(j < 3)
							{
								k = 0;
								while(k < 3)
								{
									gridValues[i][j][k] = 0;
									k ++;
								}
								j ++;
							}
							i ++;
						}

						i = 0;
						while(i < 27)
						{
							gameTurns[i] = 0;
							i ++;
						}

					}
				}
		}
		//reset game
		buttonX = 75;
		buttonY = 15;
		buttonRadius = 10;
		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(255, 100, 100));
		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(0, 150, 255));
		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(0, 150, 255), "R");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
			if(mouse_b&1){
				i = 0;
				while(i < 3)
				{
					j = 0;
					while(j < 3)
					{
						k = 0;
						while(k < 3)
						{
							gridValues[i][j][k] = 0;
							k ++;
						}
						j ++;
					}
					i ++;
				}
				angle.x = 0;
				angle.y = 0;
				angle.z = 0;
				select = false;
				game = false;
				trippinBalls = false;

			}
		}
		
		//trippin balls
		buttonX = 15;
		buttonY = 45;
		buttonRadius = 10;
		point colour2 = {0, 150, 150};
	//	bool tripPick = true;
		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour2.x, colour2.y, colour2.z));
		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour2.x, colour2.y, colour2.z), "*");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){

		//		if(tripPick == true)
		//		{
					colour2.x = 0;
					colour2.y = rand()%255;
					colour2.z = rand()%255;

					rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour2.x, colour2.y, colour2.z));
					textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour2.x, colour2.y, colour2.z), "*");
					if(mouse_b&1){
						if(trippinBalls == true)
						{
							trippinBalls = false;
						}
						else if(trippinBalls == false)
						{
							trippinBalls = true;
						}
					}
		//			tripPick = false;
		//		}
		}
		

		//speed
		buttonX = 20;
		buttonY = h - 20;
		buttonRadius = 10;
		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "++");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
			if(mouse_b&1){
				speed += 0.0001;
			}
		}
		buttonX = 40;
		buttonY = h - 20;
		buttonRadius = 10;
		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "00");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
			if(mouse_b&1){
				speed = 0.1;
			}
		}
		buttonX = 60;
		buttonY = h - 20;
		buttonRadius = 10;
		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "--");
		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
			if(mouse_b&1){
				speed -= 0.0001;
			}
		}

		//	info
		textprintf(backBuffer, font, 15, h - 45, makecol(150, 150, 150), "speed = %0.2f", speed);
		textprintf(backBuffer, font, 15, h - 60, makecol(150, 150, 150), "x axis = %0.2f", angle.x);
		textprintf(backBuffer, font, 15, h - 75, makecol(150, 150, 150), "y axis = %0.2f", angle.y);
		textprintf(backBuffer, font, 15, h - 90, makecol(150, 150, 150), "z axis = %0.2f", angle.z);

		
		

//////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


		blit(backBuffer, screen, 0, 0, 0, 0, 500, 500);
	}
}
END_OF_MAIN()