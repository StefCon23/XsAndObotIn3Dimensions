//#include<stdio.h>
//#include<allegro.h>
//#include<stdlib.h>
//#include<math.h>
//
//BITMAP * backBuffer;
//
//
//struct point
//{
//	float x;
//	float y;
//	float z;
//};
//
//
////////~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//void sixShoot(float & r, float & g, float & b)
//{
//	// Colour 6 Shooter
//	//   solid rand colours
//	//   reproduces [respectively]:
//	//      red				0
//	//      green			1
//	//      blue			2
//	//      yellow/orange	3
//	//      purple			4
//	//      turkoise?		5
//	int col;
//	col = rand()%6;
//	if(col==0)
//	{
//		r=rand()%256;
//		g=0;
//		b=0;
//	}
//	else if(col==1)
//	{
//		r=0;
//		g=rand()%256;
//		b=0;
//	}
//	else if(col==2)
//	{
//		r=0;
//		g=0;
//		b=rand()%256;
//	}
//	else if(col==3)
//	{
//		r=rand()%256;
//		g=rand()%256;
//		b=0;
//	}
//	else if(col==4)
//	{
//		r=rand()%256;
//		g=0;
//		b=rand()%256;
//	}
//	else if(col==5)
//	{
//		r=0;
//		g=rand()%256;
//		b=rand()%256;
//	}
//}
//
//float archer(int xOrY, float centerP, float radius, float angle)
//{
//
//	int x;
//
//	float radian=(angle*3.14159265)/180;
//	
//	float differ;
//	differ = xOrY == 0 ? (radius * cos(radian)) : (radius * sin(radian));
//
//	x = centerP + differ;
//
//	return x;
//
//}
//
//
//void rotate(point realWorld, float angle, char axis, point & rotation)
//{
//	/*
//		rotation function
//	rotates realworld co-ordinates
//	about defined axis (char)
//	by angle
//
//	stores transformation in point projection
//	*/
//
//	while(angle>=360)
//	{
//		angle -= 360;
//	}
//
//	float radian = (angle * 3.14159265) / 180;
//
//	if(axis=='x')
//	{
//		rotation.x = realWorld.x;
//		rotation.y = (realWorld.y * cos(radian)) + (realWorld.z * sin(radian));
//		rotation.z = (realWorld.z * cos(radian)) - (realWorld.y * sin(radian));
//	}
//	else if(axis=='y')
//	{
//		rotation.x = (realWorld.x * cos(radian)) - (realWorld.z * sin(radian));
//		rotation.y = realWorld.y;
//		rotation.z = (realWorld.z * cos(radian)) + (realWorld.x * sin(radian));
//	}
//	else if(axis=='z')
//	{
//		rotation.x = (realWorld.x * cos(radian)) + (realWorld.y * sin(radian));
//		rotation.y = (realWorld.y * cos(radian)) - (realWorld.x * sin(radian));
//		rotation.z = realWorld.z;
//	}
//}
//
//void robotTurn(int squares[3][9])
//{
//	/*
//	defence
//	attack
//	aquire property
//	*/
//
//
//
//
//}
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
//void main()
//{
//	if(allegro_init() != 0)
//	{
//		return;
//	}
//	set_color_depth(desktop_color_depth());
//	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 500, 500, 0, 0) != 0)
//	{
//		return;
//	}
//	backBuffer = create_bitmap(500, 500);
//
////////~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//	//	screen height and width
//	int w = 500;
//	int h = 500;
//	//	tickers
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	point t = {0, 0, 0};
//
//	point colour = {0, 0, 0};
//
//	point angle = {0, 0, 0};
//	float speed = 0.2;
//
//	//	selector
//	bool select = false;
//	int selectI, selectJ;
//	int selectRad = (w / 5) / 3;
//	point selectCol = {0, 255, 0};
//	bool click = false;
//
//	//point gridMid = {0, 0, 0};
//
//	float box = w / 5;
//
//	//	xs and os, grid and squares
//	point gridCoors[4][16];
//	point gridPoints[3][9];
//	//setup original values
//	point gridCoorsO[4][16];
//	point gridPointsO[3][9];
//	//	x or o state
//	// 0 for clear
//	// 1 for x
//	// 2 for o
//	int gridValues[3][9];
//	//	score
//	int xWins = 0;
//	int oWins = 0;
//	int wins[49];
//	i = 0;
//	while(i < 49)
//	{
//		wins[i] = 0;
//		i ++;
//	}
//	
//	//init gridcoors
//	i=0;
//	t.z = box - w/2;
//	while(i<4)
//	{
//		j=0;
//		t.y = box - h/2;
//		t.x = box - w/2;
//		while(j<4)
//		{
//			gridCoors[i][j].x = t.x;
//			gridCoors[i][j].y = t.y;
//			gridCoors[i][j].z = t.z;
//
//			gridCoors[i][j+4].x = t.x;
//			gridCoors[i][j+4].y = t.y + box;
//			gridCoors[i][j+4].z = t.z;
//
//			gridCoors[i][j+8].x = t.x;
//			gridCoors[i][j+8].y = t.y + (2 * box);
//			gridCoors[i][j+8].z = t.z;
//
//			gridCoors[i][j+12].x = t.x;
//			gridCoors[i][j+12].y = t.y + (3 * box);
//			gridCoors[i][j+12].z = t.z;
//
//			//	copy values
//			gridCoorsO[i][j].x = t.x;
//			gridCoorsO[i][j].y = t.y;
//			gridCoorsO[i][j].z = t.z;
//
//			gridCoorsO[i][j+4].x = t.x;
//			gridCoorsO[i][j+4].y = t.y + box;
//			gridCoorsO[i][j+4].z = t.z;
//
//			gridCoorsO[i][j+8].x = t.x;
//			gridCoorsO[i][j+8].y = t.y + (2 * box);
//			gridCoorsO[i][j+8].z = t.z;
//
//			gridCoorsO[i][j+12].x = t.x;
//			gridCoorsO[i][j+12].y = t.y + (3 * box);
//			gridCoorsO[i][j+12].z = t.z;
//
//
//			t.x += box;
//			j++;
//		}
//		t.z += box;
//		i++;
//	}
//	//init gridpoints
//	i=0;
//	t.z = box + box/2 - w/2;
//	while(i<3)
//	{
//		j=0;
//		t.y = box + box/2 - h/2;
//		t.x = box + box/2 - w/2;
//		while(j<3)
//		{
//			gridPoints[i][j].x = t.x;
//			gridPoints[i][j].y = t.y;
//			gridPoints[i][j].z = t.z;
//
//			gridPoints[i][j+3].x = t.x;
//			gridPoints[i][j+3].y = t.y + box;
//			gridPoints[i][j+3].z = t.z;
//
//			gridPoints[i][j+6].x = t.x;
//			gridPoints[i][j+6].y = t.y + (2 * box);
//			gridPoints[i][j+6].z = t.z;
//
//			//	copy values to original
//			gridPointsO[i][j].x = t.x;
//			gridPointsO[i][j].y = t.y;
//			gridPointsO[i][j].z = t.z;
//
//			gridPointsO[i][j+3].x = t.x;
//			gridPointsO[i][j+3].y = t.y + box;
//			gridPointsO[i][j+3].z = t.z;
//
//			gridPointsO[i][j+6].x = t.x;
//			gridPointsO[i][j+6].y = t.y + (2 * box);
//			gridPointsO[i][j+6].z = t.z;
//
//			t.x += box;
//			j++;
//		}
//		t.z += box;
//		i++;
//	}
//	//init gridvals
//	i = 0;
//	while(i<3)
//	{
//		j=0;
//		while(j<9)
//		{
//			gridValues[i][j]=0;
//			j++;
//		}
//		i++;
//	}
//
//	float buttonX, buttonY, buttonRadius;
//	bool trippinBalls = false;
//
//	float mx3 = 0;
//	float my3 = 0;
//
//	bool game = false;
//	bool humanMove = false;
//	bool robotMove = false;
//	int gameTurns[27];
//	i=0;
//	while(i<27)
//	{
//		gameTurns[i]=0;
//		i++;
//	}
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//	install_mouse();
//	install_keyboard();
//
//	bool done = false;
//	while (! done)
//	{
//		if (key[KEY_ESC])
//		{
//			done = true;
//			break;
//		}
//		clear_to_color(backBuffer, makecol(0, 0, 0));
//
//
////////~~~~~~~~~~~~~~~~~~~~CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//		/*
//		//Button Template
//		buttonX = 45;
//		buttonY = 40;
//		buttonRadius = 25;
//		//copy-paste from here, (use same floats through code to avoid find replaces)--> to be confirmed
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		//   y co-ordinates vary in textprint lines
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 5), makecol(150, 150, 150), "2 Line");
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 5), makecol(150, 150, 150), "Button Title");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) )
//		{
//			if(mouse_b&1)
//			{
//				//while mouse is still within button
//				while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) )
//				{
//
//					//code
//
//				}
//			}
//		}*/
//
//
//
//		//	cursor
//		sixShoot(colour.x, colour.y, colour.z);
//		line(backBuffer, mouse_x, mouse_y, mouse_x, mouse_y + 17, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, mouse_x, mouse_y, mouse_x + 11, mouse_y + 11, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, mouse_x, mouse_y + 17, mouse_x + 11, mouse_y + 11, makecol(colour.x, colour.y, colour.z));
//
//		////	grid
//		//line(backBuffer, gridCoors[][].x, gridCoors[][].y, gridCoors[][].x, gridCoors[][].y, makecol(colour.x, colour.y, colour.z));
//		colour.x = 0;
//		colour.y = 255;
//		colour.z = 0;
//		//	x axis
//		line(backBuffer, w/2 + gridCoors[1][4].x, h/2 + gridCoors[1][4].y, w/2 + gridCoors[1][7].x, h/2 + gridCoors[1][7].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[1][8].x, h/2 + gridCoors[1][8].y, w/2 + gridCoors[1][11].x, h/2 + gridCoors[1][11].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[2][4].x, h/2 + gridCoors[2][4].y, w/2 + gridCoors[2][7].x, h/2 + gridCoors[2][7].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[2][8].x, h/2 + gridCoors[2][8].y, w/2 + gridCoors[2][11].x, h/2 + gridCoors[2][11].y, makecol(colour.x, colour.y, colour.z));
//		//	y axis
//		line(backBuffer, w/2 + gridCoors[1][1].x, h/2 + gridCoors[1][1].y, w/2 + gridCoors[1][13].x, h/2 + gridCoors[1][13].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[1][2].x, h/2 + gridCoors[1][2].y, w/2 + gridCoors[1][14].x, h/2 + gridCoors[1][14].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[2][1].x, h/2 + gridCoors[2][1].y, w/2 + gridCoors[2][13].x, h/2 + gridCoors[2][13].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[2][2].x, h/2 + gridCoors[2][2].y, w/2 + gridCoors[2][14].x, h/2 + gridCoors[2][14].y, makecol(colour.x, colour.y, colour.z));
//		//	z axis
//		line(backBuffer, w/2 + gridCoors[0][5].x, h/2 + gridCoors[0][5].y, w/2 + gridCoors[3][5].x, h/2 + gridCoors[3][5].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[0][6].x, h/2 + gridCoors[0][6].y, w/2 + gridCoors[3][6].x, h/2 + gridCoors[3][6].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[0][9].x, h/2 + gridCoors[0][9].y, w/2 + gridCoors[3][9].x, h/2 + gridCoors[3][9].y, makecol(colour.x, colour.y, colour.z));
//		line(backBuffer, w/2 + gridCoors[0][10].x, h/2 + gridCoors[0][10].y, w/2 + gridCoors[3][10].x, h/2 + gridCoors[3][10].y, makecol(colour.x, colour.y, colour.z));
//
//
//		//	xs & os AND grid dots
//		i = 0;
//		while(i < 3)
//		{
//			j = 0;
//			while(j < 9)
//			{
//				if(gridValues[i][j] == 1)
//				{
//					colour.x = 255;
//					colour.y = 0;
//					colour.z = 0;
//					line(backBuffer, w/2 + gridPoints[i][j].x - box/5, h/2 + gridPoints[i][j].y - box/5, w/2 + gridPoints[i][j].x + box/5, h/2 + gridPoints[i][j].y + box/5, makecol(colour.x, colour.y, colour.z));
//					line(backBuffer, w/2 + gridPoints[i][j].x - box/5, h/2 + gridPoints[i][j].y + box/5, w/2 + gridPoints[i][j].x + box/5, h/2 + gridPoints[i][j].y - box/5, makecol(colour.x, colour.y, colour.z));
//				}
//				else if(gridValues[i][j] == 2)
//				{
//					colour.x = 0;
//					colour.y = 255;
//					colour.z = 255;
//					circle(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, box/5, makecol(colour.x, colour.y, colour.z));
//				}
//				else
//				{
//					colour.x = 0;
//					colour.y = 255;
//					colour.z = 0;
//					putpixel(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, makecol(colour.x, colour.y, colour.z));
//				}
//				j ++;
//			}
//			i ++;
//		}
//
//
//		//	wins
//		// x win
//		textprintf(backBuffer, font, w/2 - 50, h - 30, makecol(255, 0, 0), "x wins", xWins);
//		textprintf(backBuffer, font, w/2 - 50, h - 15, makecol(255, 0, 0), "  %d ", xWins);
//		// o wins
//		textprintf(backBuffer, font, w/2 + 50, h - 30, makecol(0, 255, 255), "o wins", oWins);
//		textprintf(backBuffer, font, w/2 + 50, h - 15, makecol(0, 255, 255), "  %d ", oWins);
//
//
//		////////wins
//		j = 0;
//
//		i = 0;
//		while(i < 3)
//		{
//			j = 0;
//			while(j < 3)
//			{
//				//x direction
//				if((gridValues[i][j * 3] == gridValues[i][(j * 3) + 1]) && (gridValues[i][(j * 3) + 2] == gridValues[i][(j * 3) + 1]))
//				{
//					wins[j + (3 * i)] = gridValues[i][(j * 3) + 1];
//					//draw
//					if( gridValues[i][(j * 3) + 1] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[i][j * 3].x, h/2 + gridPoints[i][j * 3].y, w/2 + gridPoints[i][(j * 3) + 2].x, h/2 + gridPoints[i][(j * 3) + 2].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[i][(j * 3) + 1] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[i][j * 3].x, h/2 + gridPoints[i][j * 3].y, w/2 + gridPoints[i][(j * 3) + 2].x, h/2 + gridPoints[i][(j * 3) + 2].y, makecol(0, 255, 255));
//					}
//
//				}
//				//y direction
//				if((gridValues[i][j] == gridValues[i][j + 3]) && (gridValues[i][j + 6] == gridValues[i][j + 3]))
//				{
//					wins[9 + j + (3 * i)] = gridValues[i][j + 3];
//					//draw
//					if( gridValues[i][j + 3] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, w/2 + gridPoints[i][j + 6].x, h/2 + gridPoints[i][j + 6].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[i][j + 3] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, w/2 + gridPoints[i][j + 6].x, h/2 + gridPoints[i][j + 6].y, makecol(0, 255, 255));
//					}
//				}
//				//z direction
//				if((gridValues[0][(j * 3) + i] == gridValues[1][(j * 3) + i]) && (gridValues[2][(j * 3) + i] == gridValues[1][(j * 3) + i]))
//				{
//					wins[18 + (j * 3) + i] = gridValues[1][(j * 3) + i];
//					//draw
//					if( gridValues[i][(j * 3) + i] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[0][(j * 3) + i].x, h/2 + gridPoints[0][(j * 3) + i].y, w/2 + gridPoints[2][(j * 3) + i].x, h/2 + gridPoints[2][(j * 3) + i].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[i][(j * 3) + i] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[0][(j * 3) + i].x, h/2 + gridPoints[0][(j * 3) + i].y, w/2 + gridPoints[2][(j * 3) + i].x, h/2 + gridPoints[2][(j * 3) + i].y, makecol(0, 255, 255));
//					}
//				}
//			
//				j ++;
//			}
//			i ++;
//		}
//
//
//		//	single diagonal loop
//		j = 0;
//		while(j < 3)
//		{
//			i = 0;
//			while(i < 3)
//			{
//
//				//front & back
//				if((gridValues[j][0 + i] == gridValues[j][4]) && (gridValues[j][8 - i] == gridValues[j][4]))
//				{
//					wins[(27 + j) + (i / 2)] = gridValues[j][4];
//					//draw
//					if( gridValues[j][4] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[j][0 + i].x, h/2 + gridPoints[j][0 + i].y, w/2 + gridPoints[j][8 - i].x, h/2 + gridPoints[j][8 - i].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[j][4] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[j][0 + i].x, h/2 + gridPoints[j][0 + i].y, w/2 + gridPoints[j][8 - i].x, h/2 + gridPoints[j][8 - i].y, makecol(0, 255, 255));
//					}
//				}
//
//				//top & bottom
//				if((gridValues[i][0 + (j * 3)] == gridValues[1][1 + (j * 3)]) && (gridValues[2 - i][2 + (j * 3)] == gridValues[1][1 + (j * 3)]))
//				{
//					wins[(31 + j) + (i / 2)] = gridValues[1][1 + (j * 3)];
//					if( gridValues[1][1 + (j * 3)] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[i][0 + (j * 3)].x, h/2 + gridPoints[i][0 + (j * 3)].y, w/2 + gridPoints[2 - i][2 + (j * 3)].x, h/2 + gridPoints[2 - i][2 + (j * 3)].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[1][1 + (j * 3)] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[i][0 + (j * 3)].x, h/2 + gridPoints[i][0 + (j * 3)].y, w/2 + gridPoints[2 - i][2 + (j * 3)].x, h/2 + gridPoints[2 - i][2 + (j * 3)].y, makecol(0, 255, 255));
//					}
//				}
//
//				//left & right
//				if((gridValues[i][0 + j] == gridValues[1][3 + j]) && (gridValues[2 - i][6 + j] == gridValues[1][3 + j]))
//				{
//					wins[(35 + j) + (i / 2)] = gridValues[1][3 + j];
//					if( gridValues[1][3 + j] == 1)
//					{
//						line(backBuffer, w/2 + gridPoints[i][0 + j].x, h/2 + gridPoints[i][0 + j].y, w/2 + gridPoints[2 - i][6 + j].x, h/2 + gridPoints[2 - i][6 + j].y, makecol(255, 0, 0)); 
//					}
//					else if( gridValues[1][3 + j] == 2)
//					{
//						line(backBuffer, w/2 + gridPoints[i][0 + j].x, h/2 + gridPoints[i][0 + j].y, w/2 + gridPoints[2 - i][6 + j].x, h/2 + gridPoints[2 - i][6 + j].y, makecol(0, 255, 255));
//					}
//				}
//
//
//				i += 2;
//			}
//
//			j += 2;
//		}
//
//
//		//	supermid loop
//		int winCount = 0;
//		//if(gridValues[1][4] != 0)
//		//{
//			i = 0;
//			while(i < 2)
//			{
//				j = 0;
//				while(j < 9)
//				{
//					//	break and skip
//					if(j == 4)
//					{
//						j = 5;
//					}
//					if(i == 1)
//					{
//						if( j == 1 )
//						{
//							j = 2;
//						}
//						if( j > 2)
//						{
//							/*i = 2;
//							j = 9;*/
//							break;
//						}
//					}
//
//					if((gridValues[i][j] == gridValues[1][4]) && (gridValues[2 - i][8 - j] == gridValues[1][4]))
//					{
//						wins[39 + winCount] = gridValues[1][4];
//						if( gridValues[1][4] == 1)
//						{
//							line(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, w/2 + gridPoints[2 - i][8 - j].x, h/2 + gridPoints[2 - i][8 - j].y, makecol(255, 0, 0)); 
//						}
//						else if( gridValues[1][4] == 2)
//						{
//							line(backBuffer, w/2 + gridPoints[i][j].x, h/2 + gridPoints[i][j].y, w/2 + gridPoints[2 - i][8 - j].x, h/2 + gridPoints[2 - i][8 - j].y, makecol(0, 255, 255));
//						}
//					}
//
//					winCount ++;
//
//					j ++;
//				}
//
//				i ++;
//			}
//		//}
//
//
//		i = 0;
//		xWins = 0;
//		oWins = 0;
//		while(i<49)
//		{
//			if(wins[i]==1)
//			{
//				xWins ++;
//			}
//			else if(wins[i]==2)
//			{
//				oWins ++;
//			}
//			i++;
//		}
//
//		/*
//		//	axis lines
//		// x axis
//		sixShoot(colour.x, colour.y, colour.z);
//		line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[0][3].x), h/2 + (gridCoors[0][3].y - 50), makecol(colour.x, colour.y, colour.z));
//		textprintf(backBuffer, font, w/2 + (gridCoors[0][2].x), h/2 + (gridCoors[0][0].y - 50), makecol(colour.x, colour.y, colour.z), "x");
//		// y axis
//		sixShoot(colour.x, colour.y, colour.z);
//		line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[0][12].x - 50), h/2 + (gridCoors[0][12].y), makecol(colour.x, colour.y, colour.z));
//		textprintf(backBuffer, font, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][8].y), makecol(colour.x, colour.y, colour.z), "y");
//		// z axis
//		sixShoot(colour.x, colour.y, colour.z);
//		line(backBuffer, w/2 + (gridCoors[0][0].x - 50), h/2 + (gridCoors[0][0].y - 50), w/2 + (gridCoors[3][0].x - 50), h/2 + (gridCoors[3][0].y - 50), makecol(colour.x, colour.y, colour.z));
//		textprintf(backBuffer, font, w/2 + (gridCoors[2][0].x - 50), h/2 + (gridCoors[2][0].y - 50), makecol(colour.x, colour.y, colour.z), "z");
//		*/
//
//
//		
//
//		//	rotation
//		if(key[KEY_1_PAD])
//		{
//			angle.x -= speed;
//		}
//		if(key[KEY_2_PAD])
//		{
//			angle.x = 0;
//		}
//		if(key[KEY_3_PAD])
//		{
//			angle.x += speed;
//		}
//
//		if(key[KEY_4_PAD])
//		{
//			angle.y -= speed;
//		}
//		if(key[KEY_5_PAD])
//		{
//			angle.y = 0;
//		}
//		if(key[KEY_6_PAD])
//		{
//			angle.y += speed;
//		}
//
//		if(key[KEY_7_PAD])
//		{
//			angle.z -= speed;
//		}
//		if(key[KEY_8_PAD])
//		{
//			angle.z = 0;
//		}
//		if(key[KEY_9_PAD])
//		{
//			angle.z += speed;
//		}
//
//		if(key[KEY_0_PAD])
//		{
//			angle.x = 0;
//			angle.y = 0;
//			angle.z = 0;
//		}
//
//		while(angle.x < 0)
//		{
//			angle.x += 360;
//		}
//		while(angle.x > 360)
//		{
//			angle.x -= 360;
//		}
//		while(angle.y < 0)
//		{
//			angle.y += 360;
//		}
//		while(angle.y > 360)
//		{
//			angle.y -= 360;
//		}
//		while(angle.z < 0)
//		{
//			angle.z += 360;
//		}
//		while(angle.z > 360)
//		{
//			angle.z -= 360;
//		}
//
//
//		//	proper rotation of points
//		i = 0;
//		while(i < 4)
//		{
//			j = 0;
//			while(j < 16)
//			{
//				if(trippinBalls == false)
//				{
//					gridCoors[i][j] = gridCoorsO[i][j];
//				}
//				rotate(gridCoors[i][j], angle.x, 'x', gridCoors[i][j]);
//				rotate(gridCoors[i][j], angle.y, 'y', gridCoors[i][j]);
//				rotate(gridCoors[i][j], angle.z, 'z', gridCoors[i][j]);
//				j ++;
//			}
//			i ++;
//		}
//		i = 0;
//		while(i < 3)
//		{
//			j = 0;
//			while(j < 9)
//			{
//				if(trippinBalls == false)
//				{
//					gridPoints[i][j] = gridPointsO[i][j];
//				}
//				rotate(gridPoints[i][j], angle.x, 'x', gridPoints[i][j]);
//				rotate(gridPoints[i][j], angle.y, 'y', gridPoints[i][j]);
//				rotate(gridPoints[i][j], angle.z, 'z', gridPoints[i][j]);
//				j ++;
//			}
//			i ++;
//		}
//
//
//		//clicking
//		if(mouse_b&1)
//		{
//			//rotation
//			if(!click)
//			{
//
//				click = true;
//
//				mx3 = mouse_x;
//				my3 = mouse_y;
//
//
//			}
//
//
//			//	selecting
//			float mx = mouse_x;
//			float my = mouse_y;
//
//			i = 0;
//			while(i<3)
//			{
//				j = 0;
//				while(j < 9)
//				{
//					if(gridValues[i][j] == 0)
//					{
//						//float gridRad = (3*box)/8;
//						float gridRad = 25;
//						if(((mx < w/2 + gridPoints[i][j].x + gridRad) && (mx > w/2 + gridPoints[i][j].x - gridRad))
//							&& ((my < h/2 + gridPoints[i][j].y + gridRad) && (my > h/2 + gridPoints[i][j].y - gridRad)))
//						{
//							select = true;
//							selectI = i;
//							selectJ = j;
//						}
//					}
//					j ++;
//				}
//				i ++;
//			}
//
//			if(click)
//			{
//				float mx1 = mouse_x;
//				float my1 = mouse_y;
//				if(mx3 < mx1)
//				{
//					angle.y += (mx1 - mx3) / (1 / speed);
//				}
//				else if(mx1 < mx3)
//				{
//					angle.y -= (mx3 - mx1) / (1 / speed);
//				}
//				if(my3 < my1)
//				{
//					angle.x -= (my1 - my3) / (1 / speed);
//				}
//				else if(my1 < my3)
//				{
//					angle.x += (my3 - my1) / (1 / speed);
//				}
//				mx3 = mx1;
//				my3 = my1;
//			}
//		}
//
//		if(!mouse_b&1)
//		{
//
//			click = false;
//
//		}
//
//
//		//	selector
//		if(select == true)
//		{
//			//	select ring
//			circle(backBuffer, w/2 + gridPoints[selectI][selectJ].x, h/2 + gridPoints[selectI][selectJ].y, selectRad, makecol(selectCol.x, selectCol.y, selectCol.z));
//			circle(backBuffer, w/2 + gridPoints[selectI][selectJ].x, h/2 + gridPoints[selectI][selectJ].y, selectRad - 5, makecol(selectCol.x, selectCol.y, selectCol.z));
//			selectCol.y = rand()%256;
//			selectRad --;
//			if(selectRad < box / 4)
//			{
//				selectRad = (box) / 3;
//			}
//			//	gameplay
//			if(game)
//			{
//				i = 0;
//				while( i < 27 )
//				{
//					if(gameTurns[i] == 0)
//					{
//						j = i;
//						i = 27;
//					}
//					i ++;
//				}
//
//				if(j%2 == 0)
//				{
//					if(key[KEY_X])
//					{
//						gridValues[selectI][selectJ] = 1;
//						select = false;
//						gameTurns[j] = 1;
//					}
//				}
//				else
//				{
//					if((key[KEY_O])||(key[KEY_Z]))
//					{
//						gridValues[selectI][selectJ] = 2;
//						select = false;
//						gameTurns[j] = 2;
//					}
//				}
//
//
//			}
//			else
//			{
//				if(key[KEY_X])
//				{
//					gridValues[selectI][selectJ] = 1;
//					select = false;
//				}
//				else if((key[KEY_O])||(key[KEY_Z]))
//				{
//					gridValues[selectI][selectJ] = 2;
//					select = false;
//				}
//				else if(key[KEY_C])
//				{
//					gridValues[selectI][selectJ] = 0;
//					select = false;
//				}
//			}
//		}
//
//
//		//	game
//		if(game)
//		{
//			int k = 0;
//			i = 0;
//			while( i < 27 )
//			{
//				if(gameTurns[i] == 0)
//				{
//					j = i;
//					i = 27;
//				}
//				else
//				{
//					k ++;
//				}
//				i ++;
//			}
//			if(k < 27)
//			{
//				if(j%2 == 0)
//				{
//					//humanmove
//					rect(backBuffer,  w/2 - 60, h - 40, w/2, h, makecol(0, 255, 0));
//				}
//				else
//				{
//					//robotmove
//					rect(backBuffer,  w/2 + 40, h - 40, w/2 + 100, h, makecol(0, 255, 0));
//					// robot function
//				}
//			}
//			else
//			{
//				//game over
//			}
//		}
//
//
//
//
//		////	buttons
//		//exit
//		buttonX = 15;
//		buttonY = 15;
//		buttonRadius = 10;
//		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(255, 100, 100));
//		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(255, 100, 100));
//		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(255, 100, 100), "X");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				done = true;
//				break;
//			}
//		}
//		//game on
//		buttonX = 45;
//		buttonY = 15;
//		buttonRadius = 10;
//		point colour3 = {0, 255, 0};
//		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour3.x, colour3.y, colour3.z));
//		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour3.x, colour3.y, colour3.z), "G");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1)
//				{
//					if(game == false)
//					{
//
//						game = true;
//						i = 0;
//						while(i < 3)
//						{
//							j = 0;
//							while(j < 9)
//							{
//								gridValues[i][j] = 0;
//								j ++;
//							}
//							i ++;
//						}
//
//					}
//				}
//		}
//		//reset game
//		buttonX = 75;
//		buttonY = 15;
//		buttonRadius = 10;
//		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(255, 100, 100));
//		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(0, 150, 255));
//		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(0, 150, 255), "R");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				i = 0;
//				while(i < 3)
//				{
//					j = 0;
//					while(j < 9)
//					{
//						gridValues[i][j] = 0;
//						j ++;
//					}
//					i ++;
//				}
//			}
//		}
//		
//		//trippin balls
//		buttonX = 15;
//		buttonY = 45;
//		buttonRadius = 10;
//		point colour2 = {0, 150, 150};
//	//	bool tripPick = true;
//		rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour2.x, colour2.y, colour2.z));
//		textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour2.x, colour2.y, colour2.z), "*");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//
//		//		if(tripPick == true)
//		//		{
//					colour2.x = 0;
//					colour2.y = rand()%255;
//					colour2.z = rand()%255;
//
//					rect(backBuffer, (buttonX - buttonRadius), (buttonY - buttonRadius), (buttonX + buttonRadius), (buttonY + buttonRadius), makecol(colour2.x, colour2.y, colour2.z));
//					textprintf(backBuffer, font, (buttonX - 3), (buttonY - 3), makecol(colour2.x, colour2.y, colour2.z), "*");
//					if(mouse_b&1){
//						if(trippinBalls == true)
//						{
//							trippinBalls = false;
//						}
//						else if(trippinBalls == false)
//						{
//							trippinBalls = true;
//						}
//					}
//		//			tripPick = false;
//		//		}
//		}
//		
//
//		//speed
//		buttonX = 20;
//		buttonY = h - 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "++");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed += 0.0001;
//			}
//		}
//		buttonX = 40;
//		buttonY = h - 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "00");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 0.1;
//			}
//		}
//		buttonX = 60;
//		buttonY = h - 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 3), (buttonY - 3), makecol(150, 150, 150), "--");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed -= 0.0001;
//			}
//		}
//
//		//	info
//		textprintf(backBuffer, font, 15, h - 45, makecol(150, 150, 150), "speed = %0.2f", speed);
//		textprintf(backBuffer, font, 15, h - 60, makecol(150, 150, 150), "x axis = %0.2f", angle.x);
//		textprintf(backBuffer, font, 15, h - 75, makecol(150, 150, 150), "y axis = %0.2f", angle.y);
//		textprintf(backBuffer, font, 15, h - 90, makecol(150, 150, 150), "z axis = %0.2f", angle.z);
//
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//		blit(backBuffer, screen, 0, 0, 0, 0, 500, 500);
//	}
//}
//END_OF_MAIN()