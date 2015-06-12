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
//void sixShoot(int & r, int & g, int & b)
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
//	if(col==0){
//		r=rand()%256;
//		g=0;
//		b=0;}
//	else if(col==1){
//		r=0;
//		g=rand()%256;
//		b=0;}
//	else if(col==2){
//		r=0;
//		g=0;
//		b=rand()%256;}
//	else if(col==3){
//		r=rand()%256;
//		g=rand()%256;
//		b=0;}
//	else if(col==4){
//		r=rand()%256;
//		g=0;
//		b=rand()%256;}
//	else if(col==5){
//		r=0;
//		g=rand()%256;
//		b=rand()%256;}
//}
//
//
///*
//void droreos()
//{
//
//}
//*/
//
//void update()
//{
//	blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
//}
//
//void circleMixer(float x, float y, float radius, float frequency, float innerRadius, int r, int g, int b)
//{
//	//limited colour function
//	if(r!=0){r=rand()%255+1;}
//	if(g!=0){g=rand()%255+1;}
//	if(b!=0){b=rand()%255+1;}
//	//circle filler
//	while(radius>innerRadius){
//		circle(backBuffer, x, y, radius, makecol(r, g, b));
//		if(r!=0){r=rand()%255+1;}
//		if(g!=0){g=rand()%255+1;}
//		if(b!=0){b=rand()%255+1;}
//		radius-=frequency;
//		update();
//	}
//}
//
//float archer(int xOrY, float centerP, float radius, float angle){
//
//	int x;
//
//	float radian=(angle*3.14159265)/180;
//	
//	float differ;
//	differ = xOrY == 0 ? (radius * cos(radian)) : (radius * sin(radian));
//
//	//if(
//	x = centerP + differ;
//
//	return x;
//
//}
//
//void proj3d(point realworld, point origin, point & projection)
//{
///*
//		Here's a very general answer. Say the camera's at (Xc, Yc, Zc) 
//		and the point you want to project is P = (X, Y, Z).
//		The distance from the camera to the 2D plane onto which you are projecting is F 
//		(so the equation of the plane is Z-Zc=F). 
//		The 2D coordinates of P projected onto the plane are (X', Y').
//
//		Then, very simply:
//
//		X' = ((X - Xc) * (F/Z)) + Xc
//
//		Y' = ((Y - Yc) * (F/Z)) + Yc
//
//		If your camera is the origin, then this simplifies to:
//
//		X' = X * (F/Z)
//
//		Y' = Y * (F/Z)
//
//		http://stackoverflow.com/questions/724219/how-to-convert-a-3d-point-into-2d-perspective-projection
//*/
//
//	//float f = realworld.z - origin.z;
//	
//	float f;
//	if(realworld.z > origin.z)
//	{
//		f = realworld.z - origin.z;
//	}
//	else if(realworld.z < origin.z)
//	{
//		f = origin.z - realworld.z;
//	}
//	else
//	{
//		f = realworld.z - origin.z;
//	}
//
//
//	projection.x = ((realworld.x - origin.x) * (f / realworld.z)) + origin.x;
//	projection.y = ((realworld.y - origin.y) * (f / realworld.z)) + origin.y;
//	/*
//	projection.x = ((realworld.x - origin.x) * (realworld.z)) + origin.x;
//	projection.y = ((realworld.y - origin.y) * (realworld.z)) + origin.y;
//	*/
//}
//
//void rotate(point realworld, float angle, char axis, point & projection)
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
//
//	float radian = (angle * 3.14159265) / 180;
//
//	
//	if(axis=='x')
//	{
//		projection.x = realworld.x;
//		projection.y = (realworld.y * cos(radian)) + (realworld.z * sin(radian));
//		projection.z = (realworld.z * cos(radian)) - (realworld.y * sin(radian));
//	}
//	else if(axis=='y')
//	{
//		projection.x = (realworld.x * cos(radian)) - (realworld.z * sin(radian));
//		projection.y = realworld.y;
//		projection.z = (realworld.z * cos(radian)) + (realworld.x * sin(radian));
//	}
//	else if(axis=='z')
//	{
//		projection.x = (realworld.x * cos(radian)) + (realworld.y * sin(radian));
//		projection.y = (realworld.y * cos(radian)) - (realworld.x * sin(radian));
//		projection.z = realworld.z;
//	}
//	
//}
//
//
//
//void projNew(point realworld, point origin, point & projection)
//{
//	//http://www.dreamincode.net/forums/topic/239174-3d-perspective-projection/
//
//	projection.x = ( (origin.z * (realworld.x - origin.x)) / (origin.z + realworld.z) ) + origin.x;
//	projection.y = ( (origin.z * (realworld.y - origin.y)) / (origin.z + realworld.z) ) + origin.y;
//
//
//}
//
//void projNew2(point realworld, point origin, point & projection)
//{
//	projection.x = realworld.x / realworld.z;
//	projection.y = realworld.y / realworld.z;
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
//	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
//	{
//		return;
//	}
//	backBuffer = create_bitmap(640, 480);
//
////////~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//	point camera = {0, 0, 50};
//
//	point angle = {0, 0, 0};
//
//	point modelMid = {0, 0, 0};
//
//	int w = 640, h = 480;
//
//
//	float speed = 0.25;
//
//	int draw = 2;
//
//	point cube[8];
//	point cuber[8];
//
//	point grid[4][16];
//	point gridr[4][16];
//
//	float buttonX;
//	float buttonY;
//	float buttonRadius;
//
//	int i, j;
//	int kay = 4;
//	int level = 0;
//	bool pick = false;
//
//	point bits[3][9];
//	int oreos[3][9];
//	i = 0;
//	while(i<3)
//	{
//		j = 0;
//		while(j<9)
//		{
//			oreos[i][j] = 0;
//			j++;
//		}
//		i++;
//	}
//
//	int xWin = 0;
//	int oWin = 0;
//
//	int wins[43];
//	i = 0;
//	while(i<43)
//	{
//		wins[i] = 0;
//		i++;
//	}
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
//		//cursor
//		circle(backBuffer, mouse_x, mouse_y, 5, makecol(255, 255, 255));
//		if(mouse_b&1)
//		{
//			int r = rand()%255;
//			int g = rand()%255;
//			int b = rand()%255;
//			circle(backBuffer, mouse_x, mouse_y, 1, makecol(r, g, b));
//			circle(backBuffer, mouse_x, mouse_y, 2, makecol(r, g, b));
//			//circle(backBuffer, mouse_x, mouse_y, 3, makecol(r, g, b));
//			circle(backBuffer, mouse_x, mouse_y, 4, makecol(r, g, b));
//			//circle(backBuffer, mouse_x, mouse_y, 5, makecol(r, g, b));
//		}
//
//		////buttons
//
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
//
//		//angle
//		textprintf(backBuffer, font, 560, 397, makecol(150, 150, 150), "angle");
//		textprintf(backBuffer, font, 600, 417, makecol(150, 150, 150), "%0.0f", angle.x);
//		textprintf(backBuffer, font, 600, 437, makecol(150, 150, 150), "%0.0f", angle.y);
//		textprintf(backBuffer, font, 600, 457, makecol(150, 150, 150), "%0.0f", angle.z);
//		buttonX = 580;
//		buttonY = 420;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.x += speed;
//				while(angle.x>360)
//				{
//					angle.x-=360;
//				}
//			}
//		}
//		buttonX = 560;
//		buttonY = 420;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.x -= speed;
//				while(angle.x<0)
//				{
//					angle.x+=360;
//				}
//			}
//		}
//		buttonX = 580;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.y += speed;
//				while(angle.y>360)
//				{
//					angle.y-=360;
//				}
//			}
//		}
//		buttonX = 560;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.y -= speed;
//				while(angle.y<0)
//				{
//					angle.y+=360;
//				}
//			}
//		}
//		buttonX = 580;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.z += speed;
//				while(angle.z>360)
//				{
//					angle.z-=360;
//				}
//			}
//		}
//		buttonX = 560;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.z -= speed;
//				while(angle.z<0)
//				{
//					angle.z+=360;
//				}
//			}
//		}
//		buttonX = 540;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "0");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.x = 0;
//				angle.y = 0;
//				angle.z = 0;
//			}
//		}
//
//		//speed
//		buttonX = 20;
//		buttonY = 420;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), ">");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 0.1;
//			}
//		}
//		buttonX = 20;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), ">>");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 1;
//			}
//		}
//		buttonX = 20;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), ">>>");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 3;
//			}
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
//		//info text
//		//y = 175;
//
//		textprintf(backBuffer, font, 540, 125, makecol(150, 150, 150), "bits[%d][%d]", level, kay);
//
//
//		textprintf(backBuffer, font, 140, 10, makecol(255, 0, 0), "x rows");
//		textprintf(backBuffer, font, 140, 20, makecol(255, 0, 0), "%d", xWin);
//
//		textprintf(backBuffer, font, 200, 10, makecol(0, 255, 255), "y rows");
//		textprintf(backBuffer, font, 200, 20, makecol(0, 255, 255), "%d", oWin);
//
//
//		//game selection circle proper
//		textprintf(backBuffer, font, 540, 275, makecol(150, 150, 150), "selector");
//		textprintf(backBuffer, font, 600, 217, makecol(150, 150, 150), "%d", kay + 1);
//		textprintf(backBuffer, font, 600, 237, makecol(150, 150, 150), "%0.0f", camera.y);
//		textprintf(backBuffer, font, 600, 257, makecol(150, 150, 150), "%d", level + 1);
//		buttonX = 580;
//		buttonY = 220;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==1)||(kay==2))
//				{
//					kay = 0;
//				}
//				else if((kay==4)||(kay==5))
//				{
//					kay = 3;
//				}
//				else if((kay==7)||(kay==8))
//				{
//					kay = 6;
//				}
//			}
//		}
//		buttonX = 560;
//		buttonY = 220;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==0)||(kay==2))
//				{
//					kay = 1;
//				}
//				else if((kay==3)||(kay==5))
//				{
//					kay = 4;
//				}
//				else if((kay==6)||(kay==8))
//				{
//					kay = 7;
//				}
//			}
//		}
//		buttonX = 540;
//		buttonY = 220;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==0)||(kay==1))
//				{
//					kay = 2;
//				}
//				else if((kay==3)||(kay==4))
//				{
//					kay = 5;
//				}
//				else if((kay==6)||(kay==7))
//				{
//					kay = 8;
//				}
//			}
//		}
//		buttonX = 580;
//		buttonY = 240;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==3)||(kay==6))
//				{
//					kay = 0;
//				}
//				else if((kay==4)||(kay==7))
//				{
//					kay = 1;
//				}
//				else if((kay==5)||(kay==8))
//				{
//					kay = 2;
//				}
//			}
//		}
//		buttonX = 560;
//		buttonY = 240;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==0)||(kay==6))
//				{
//					kay = 3;
//				}
//				else if((kay==1)||(kay==7))
//				{
//					kay = 4;
//				}
//				else if((kay==2)||(kay==8))
//				{
//					kay = 5;
//				}
//			}
//		}
//		buttonX = 540;
//		buttonY = 240;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				if((kay==0)||(kay==3))
//				{
//					kay = 6;
//				}
//				else if((kay==1)||(kay==4))
//				{
//					kay = 7;
//				}
//				else if((kay==2)||(kay==5))
//				{
//					kay = 8;
//				}
//			}
//		}
//		buttonX = 580;
//		buttonY = 260;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				level = 0;
//			}
//		}
//		buttonX = 560;
//		buttonY = 260;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				level = 1;
//			}
//		}
//		buttonX = 540;
//		buttonY = 260;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				pick=true;
//				level = 2;
//			}
//		}
//		buttonX = 580;
//		buttonY = 295;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "o");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				oreos[level][kay] = 2;
//				pick = false;
//			}
//		}
//		buttonX = 560;
//		buttonY = 295;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				oreos[level][kay] = 0;
//				pick = false;
//			}
//		}
//		buttonX = 540;
//		buttonY = 295;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				oreos[level][kay] = 1;
//				pick = false;
//			}
//		}
//		//reset button
//		buttonX = 540;
//		buttonY = 200;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "0");
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "reset game");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				i = 0;
//				while(i<3)
//				{
//					j = 0;
//					while(j<9)
//					{
//						oreos[i][j] = 0;
//						j++;
//					}
//					i++;
//				}
//			}
//		}
//		/*
//		buttonX = 540;
//		buttonY = 40;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "0");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				i = 0;
//				while(i<3)
//				{
//					j = 0;
//					while(j<9)
//					{
//						oreos[i][j] = 0;
//						j++;
//					}
//					i++;
//				}
//			}
//		}
//		*/
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//		if(draw==0)
//		{
//			cube[0].x = modelMid.x - 25;
//			cube[0].y = modelMid.y - 25;
//			cube[0].z = modelMid.z - 25;
//
//			cube[1].x = modelMid.x - 25;
//			cube[1].y = modelMid.y - 25;
//			cube[1].z = modelMid.z + 25;
//
//			cube[2].x = modelMid.x + 25;
//			cube[2].y = modelMid.y - 25;
//			cube[2].z = modelMid.z + 25;
//
//			cube[3].x = modelMid.x + 25;
//			cube[3].y = modelMid.y - 25;
//			cube[3].z = modelMid.z - 25;
//
//
//
//			cube[4].x = modelMid.x - 25;
//			cube[4].y = modelMid.y + 25;
//			cube[4].z = modelMid.z - 25;
//
//			cube[5].x = modelMid.x - 25;
//			cube[5].y = modelMid.y + 25;
//			cube[5].z = modelMid.z + 25;
//
//			cube[6].x = modelMid.x + 25;
//			cube[6].y = modelMid.y + 25;
//			cube[6].z = modelMid.z + 25;
//
//			cube[7].x = modelMid.x + 25;
//			cube[7].y = modelMid.y + 25;
//			cube[7].z = modelMid.z - 25;
//		
//
//			i = 0;
//			while(i<8)
//			{
//				cuber[i] = cube[i];
//				i ++;
//			}
//
//			//int j = rand()%3;
//			i = 0;
//			while(i<8)
//			{
//				/*
//				if(j==0)
//				{
//					rotate(cube[i], angle.x, 'x', cuber[i]);
//				}
//				else if(j==1)
//				{
//					rotate(cube[i], angle.y, 'y', cuber[i]);
//				}
//				else if(j==2)
//				{
//					rotate(cube[i], angle.z, 'z', cuber[i]);
//				}
//				*/
//				rotate(cuber[i], angle.x, 'x', cuber[i]);
//				rotate(cuber[i], angle.y, 'y', cuber[i]);
//				rotate(cuber[i], angle.z, 'z', cuber[i]);
//				i++;
//			}
//
//			i = 0;
//			while(i<8)
//			{
//				//projNew(cuber[i], camera, cuber[i]);
//				i++;
//			}
//
//			line(backBuffer, w/2 + cuber[0].x, h/2 + cuber[0].y, w/2 + cuber[1].x, h/2 + cuber[1].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[1].x, h/2 + cuber[1].y, w/2 + cuber[2].x, h/2 + cuber[2].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[2].x, h/2 + cuber[2].y, w/2 + cuber[3].x, h/2 + cuber[3].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[3].x, h/2 + cuber[3].y, w/2 + cuber[0].x, h/2 + cuber[0].y, makecol(255, 0, 255));
//
//			line(backBuffer, w/2 + cuber[0].x, h/2 + cuber[0].y, w/2 + cuber[4].x, h/2 + cuber[4].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[1].x, h/2 + cuber[1].y, w/2 + cuber[5].x, h/2 + cuber[5].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[2].x, h/2 + cuber[2].y, w/2 + cuber[6].x, h/2 + cuber[6].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[3].x, h/2 + cuber[3].y, w/2 + cuber[7].x, h/2 + cuber[7].y, makecol(255, 0, 255));
//
//			line(backBuffer, w/2 + cuber[4].x, h/2 + cuber[4].y, w/2 + cuber[5].x, h/2 + cuber[5].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[5].x, h/2 + cuber[5].y, w/2 + cuber[6].x, h/2 + cuber[6].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[6].x, h/2 + cuber[6].y, w/2 + cuber[7].x, h/2 + cuber[7].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + cuber[7].x, h/2 + cuber[7].y, w/2 + cuber[4].x, h/2 + cuber[4].y, makecol(255, 0, 255));
//
//		}
//		else if(draw==1)
//		{
//
//
//			for(j = 0; j < 4; j ++)
//			{
//				for(i = 0; i < 16; i ++)
//				{
//
//					//x axises
//					if((i == 0)||(i % 4 == 0))
//					{
//						grid[j][i].x = modelMid.x - 75;
//					}
//					else if((i == 1)||(i == 5)||(i == 9)||(i == 13))
//					{
//						grid[j][i].x = modelMid.x - 25;
//					}
//					else if((i == 2)||(i == 6)||(i == 10)||(i == 14))
//					{
//						grid[j][i].x = modelMid.x + 25;
//					}
//					else if((i == 3)||(i == 7)||(i == 11)||(i == 15))
//					{
//						grid[j][i].x = modelMid.x + 75;
//					}
//
//			
//					//y axises
//					if((i >= 0)&&(i <= 3))
//					{
//						grid[j][i].y = modelMid.y - 75;
//					}
//					else if((i >= 4)&&(i <= 7))
//					{
//						grid[j][i].y = modelMid.y - 25;
//					}
//					else if((i >= 8)&&(i <= 11))
//					{
//						grid[j][i].y = modelMid.y + 25;
//					}
//					else if((i >= 12)&&(i <= 15))
//					{
//						grid[j][i].y = modelMid.y + 75;
//					}
//
//					//z axises
//					if(j==0)
//					{//layer1 (of 4)
//						grid[j][i].z = modelMid.z - 75;
//					}
//					else if(j==1)
//					{//layer2 (of 4)
//						grid[j][i].z = modelMid.z - 25;
//					}
//					else if(j==2)
//					{//layer3 (of 4)
//						grid[j][i].z = modelMid.z + 25;
//					}
//					else if(j==3)
//					{//layer4 (of 4)
//						grid[j][i].z = modelMid.z + 75;
//					}
//
//				}
//			}
//
//			/*
//
//			int enlargement = 50;
//
//			i = 0;
//			while(i<4)
//			{
//				j=0;
//
//				while(j<16)
//				{
//					grid[i][j].x += enlargement;
//					grid[i][j].y += enlargement;
//					grid[i][j].z += enlargement;
//					j++;
//				}
//
//				i++;
//			}
//
//			*/
//
//			/*
//
//			//enlargerating
//			i = 0;
//			while(i<4)
//			{
//				j=0;
//				while(j<16)
//				{
//
//					int size = 1000;
//
//					grid[i][j].x *= size;
//					grid[i][j].y *= size;
//					grid[i][j].z *= size;
//
//					j++;
//				}
//				i++;
//			}
//
//			*/
//
//
//			i = 0;
//			while(i<4)
//			{
//				j=0;
//				while(j<16)
//				{
//					gridr[i][j] = grid[i][j];
//					j++;
//				}
//				i ++;
//			}
//
//			i = 0;
//			while(i<4)
//			{
//				j = 0;
//				while(j<16)
//				{
//					rotate(gridr[i][j], angle.x, 'x', gridr[i][j]);
//					rotate(gridr[i][j], angle.y, 'y', gridr[i][j]);
//					rotate(gridr[i][j], angle.z, 'z', gridr[i][j]);
//					j++;
//				}
//				i++;
//			}
//
//			for(j = 0; j < 4; j ++)
//			{
//
//				//top left corner
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[0][0].x, h/2 + gridr[0][0].y, makecol(0, 255, 0));
//				//bottom left
//				line(backBuffer, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, w/2 + gridr[0][12].x, h/2 + gridr[0][12].y, makecol(0, 255, 0));
//			
//				//bottom right
//				line(backBuffer, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, w/2 + gridr[0][15].x, h/2 + gridr[0][15].y, makecol(0, 255, 0));
//				//top right
//				line(backBuffer, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, w/2 + gridr[0][3].x, h/2 + gridr[0][3].y, makecol(0, 255, 0));
//			
//			
//				//top left (mid) edge
//				line(backBuffer, w/2 + gridr[j][1].x, h/2 + gridr[j][1].y, w/2 + gridr[j][13].x, h/2 + gridr[j][13].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][1].x, h/2 + gridr[j][1].y, w/2 + gridr[0][1].x, h/2 + gridr[0][1].y, makecol(0, 255, 0));
//				//top right (mid) edge
//				line(backBuffer, w/2 + gridr[j][2].x, h/2 + gridr[j][2].y, w/2 + gridr[j][14].x, h/2 + gridr[j][14].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][2].x, h/2 + gridr[j][2].y, w/2 + gridr[0][2].x, h/2 + gridr[0][2].y, makecol(0, 255, 0));
//				//mid right top (mid) edge
//				line(backBuffer, w/2 + gridr[j][7].x, h/2 + gridr[j][7].y, w/2 + gridr[j][4].x, h/2 + gridr[j][4].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][7].x, h/2 + gridr[j][7].y, w/2 + gridr[0][7].x, h/2 + gridr[0][7].y, makecol(0, 255, 0));
//				//mid right bottom (mid) edge
//				line(backBuffer, w/2 + gridr[j][11].x, h/2 + gridr[j][11].y, w/2 + gridr[j][8].x, h/2 + gridr[j][8].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][11].x, h/2 + gridr[j][11].y, w/2 + gridr[0][11].x, h/2 + gridr[0][11].y, makecol(0, 255, 0));
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + gridr[j][14].x, h/2 + gridr[j][14].y, w/2 + gridr[0][14].x, h/2 + gridr[0][14].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + gridr[j][13].x, h/2 + gridr[j][13].y, w/2 + gridr[0][13].x, h/2 + gridr[0][13].y, makecol(0, 255, 0));
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + gridr[j][4].x, h/2 + gridr[j][4].y, w/2 + gridr[0][4].x, h/2 + gridr[0][4].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + gridr[j][8].x, h/2 + gridr[j][8].y, w/2 + gridr[0][8].x, h/2 + gridr[0][8].y, makecol(0, 255, 0));
//			
//
//				//mid lines
//				//mid top left
//				line(backBuffer, w/2 + gridr[j][5].x, h/2 + gridr[j][5].y, w/2 + gridr[0][5].x, h/2 + gridr[0][5].y, makecol(0, 255, 0));
//				//mid top right
//				line(backBuffer, w/2 + gridr[j][6].x, h/2 + gridr[j][6].y, w/2 + gridr[0][6].x, h/2 + gridr[0][6].y, makecol(0, 255, 0));
//				//mid bottom left
//				line(backBuffer, w/2 + gridr[j][9].x, h/2 + gridr[j][9].y, w/2 + gridr[0][9].x, h/2 + gridr[0][9].y, makecol(0, 255, 0));
//				//mid bottom right
//				line(backBuffer, w/2 + gridr[j][10].x, h/2 + gridr[j][10].y, w/2 + gridr[0][10].x, h/2 + gridr[0][10].y, makecol(0, 255, 0));
//
//
//			}
//
//			//line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(0, 255, 0));
//			//rect(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][6].x, h/2 + gridr[3][6].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][6].x, h/2 + gridr[3][6].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][9].x, h/2 + gridr[3][9].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][9].x, h/2 + gridr[3][9].y, makecol(255, 0, 255));
//
//
//		}
//		else if(draw==2)
//		{
//
//
//			for(j = 0; j < 4; j ++)
//			{
//				for(i = 0; i < 16; i ++)
//				{
//
//					//x axises
//					if((i == 0)||(i % 4 == 0))
//					{
//						grid[j][i].x = modelMid.x - 75;
//					}
//					else if((i == 1)||(i == 5)||(i == 9)||(i == 13))
//					{
//						grid[j][i].x = modelMid.x - 25;
//					}
//					else if((i == 2)||(i == 6)||(i == 10)||(i == 14))
//					{
//						grid[j][i].x = modelMid.x + 25;
//					}
//					else if((i == 3)||(i == 7)||(i == 11)||(i == 15))
//					{
//						grid[j][i].x = modelMid.x + 75;
//					}
//
//			
//					//y axises
//					if((i >= 0)&&(i <= 3))
//					{
//						grid[j][i].y = modelMid.y - 75;
//					}
//					else if((i >= 4)&&(i <= 7))
//					{
//						grid[j][i].y = modelMid.y - 25;
//					}
//					else if((i >= 8)&&(i <= 11))
//					{
//						grid[j][i].y = modelMid.y + 25;
//					}
//					else if((i >= 12)&&(i <= 15))
//					{
//						grid[j][i].y = modelMid.y + 75;
//					}
//
//					//z axises
//					if(j==0)
//					{//layer1 (of 4)
//						grid[j][i].z = modelMid.z - 75;
//					}
//					else if(j==1)
//					{//layer2 (of 4)
//						grid[j][i].z = modelMid.z - 25;
//					}
//					else if(j==2)
//					{//layer3 (of 4)
//						grid[j][i].z = modelMid.z + 25;
//					}
//					else if(j==3)
//					{//layer4 (of 4)
//						grid[j][i].z = modelMid.z + 75;
//					}
//
//				}
//			}
//
//			point axis[7];
//
//			//mid axis
//			axis[0].x = grid[3][15].x + 50;
//			axis[0].y = grid[3][15].y + 50;
//			axis[0].z = grid[3][15].z + 50;
//
//			//x axis
//			axis[1].x = grid[3][14].x - 25;
//			axis[1].y = grid[3][14].y + 50;
//			axis[1].z = grid[3][14].z + 50;
//
//			axis[2].x = grid[3][12].x - 50;
//			axis[2].y = grid[3][12].y + 50;
//			axis[2].z = grid[3][12].z + 50;
//
//			
//			//y axis
//			axis[3].x = grid[3][11].x + 50;
//			axis[3].y = grid[3][11].y - 25;
//			axis[3].z = grid[3][11].z + 50;
//
//			axis[4].x = grid[3][3].x + 50;
//			axis[4].y = grid[3][3].y - 50;
//			axis[4].z = grid[3][3].z + 50;
//
//			
//			//z axis
//			axis[5].x = grid[2][15].x + 50;
//			axis[5].y = grid[2][15].y + 50;
//			axis[5].z = grid[2][15].z - 25;
//
//			axis[6].x = grid[0][15].x + 50;
//			axis[6].y = grid[0][15].y + 50;
//			axis[6].z = grid[0][15].z - 50;
//			
//
//
//
//			i = 0;
//			while(i<7)
//			{
//				rotate(axis[i], angle.x, 'x', axis[i]);
//				rotate(axis[i], angle.y, 'y', axis[i]);
//				rotate(axis[i], angle.z, 'z', axis[i]);
//				i++;
//			}
//
//
//			i = 0;
//			while(i<4)
//			{
//				j=0;
//				while(j<16)
//				{
//					gridr[i][j] = grid[i][j];
//					j++;
//				}
//				i ++;
//			}
//
//			i = 0;
//			while(i<4)
//			{
//				j = 0;
//				while(j<16)
//				{
//					rotate(gridr[i][j], angle.x, 'x', gridr[i][j]);
//					rotate(gridr[i][j], angle.y, 'y', gridr[i][j]);
//					rotate(gridr[i][j], angle.z, 'z', gridr[i][j]);
//					j++;
//				}
//				i++;
//			}
//
//			for(j = 0; j < 4; j ++)
//			{
//
//				/*
//
//				//top left corner
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][0].x, h/2 + gridr[j][0].y, w/2 + gridr[0][0].x, h/2 + gridr[0][0].y, makecol(0, 255, 0));
//				//bottom left
//				line(backBuffer, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][12].x, h/2 + gridr[j][12].y, w/2 + gridr[0][12].x, h/2 + gridr[0][12].y, makecol(0, 255, 0));
//			
//				//bottom right
//				line(backBuffer, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][15].x, h/2 + gridr[j][15].y, w/2 + gridr[0][15].x, h/2 + gridr[0][15].y, makecol(0, 255, 0));
//				//top right
//				line(backBuffer, w/2 + gridr[j][3].x, h/2 + gridr[j][3].y, w/2 + gridr[0][3].x, h/2 + gridr[0][3].y, makecol(0, 255, 0));
//			
//			*/
//			/*
//				//top left (mid) edge
//				line(backBuffer, w/2 + gridr[j][1].x, h/2 + gridr[j][1].y, w/2 + gridr[j][13].x, h/2 + gridr[j][13].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][1].x, h/2 + gridr[j][1].y, w/2 + gridr[0][1].x, h/2 + gridr[0][1].y, makecol(0, 255, 0));
//				//top right (mid) edge
//				line(backBuffer, w/2 + gridr[j][2].x, h/2 + gridr[j][2].y, w/2 + gridr[j][14].x, h/2 + gridr[j][14].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][2].x, h/2 + gridr[j][2].y, w/2 + gridr[0][2].x, h/2 + gridr[0][2].y, makecol(0, 255, 0));
//				//mid right top (mid) edge
//				line(backBuffer, w/2 + gridr[j][7].x, h/2 + gridr[j][7].y, w/2 + gridr[j][4].x, h/2 + gridr[j][4].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][7].x, h/2 + gridr[j][7].y, w/2 + gridr[0][7].x, h/2 + gridr[0][7].y, makecol(0, 255, 0));
//				//mid right bottom (mid) edge
//				line(backBuffer, w/2 + gridr[j][11].x, h/2 + gridr[j][11].y, w/2 + gridr[j][8].x, h/2 + gridr[j][8].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + gridr[j][11].x, h/2 + gridr[j][11].y, w/2 + gridr[0][11].x, h/2 + gridr[0][11].y, makecol(0, 255, 0));
//				*/
//				/*
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + gridr[j][14].x, h/2 + gridr[j][14].y, w/2 + gridr[0][14].x, h/2 + gridr[0][14].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + gridr[j][13].x, h/2 + gridr[j][13].y, w/2 + gridr[0][13].x, h/2 + gridr[0][13].y, makecol(0, 255, 0));
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + gridr[j][4].x, h/2 + gridr[j][4].y, w/2 + gridr[0][4].x, h/2 + gridr[0][4].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + gridr[j][8].x, h/2 + gridr[j][8].y, w/2 + gridr[0][8].x, h/2 + gridr[0][8].y, makecol(0, 255, 0));
//			*/
//
//				
//
//
//
//				
//
//			}
//
//			//mid lines
//			//mid top left
//			line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[0][5].x, h/2 + gridr[0][5].y, makecol(0, 255, 0));
//			//mid top right
//			line(backBuffer, w/2 + gridr[3][6].x, h/2 + gridr[3][6].y, w/2 + gridr[0][6].x, h/2 + gridr[0][6].y, makecol(0, 255, 0));
//			//mid bottom left
//			line(backBuffer, w/2 + gridr[3][9].x, h/2 + gridr[3][9].y, w/2 + gridr[0][9].x, h/2 + gridr[0][9].y, makecol(0, 255, 0));
//			//mid bottom right
//			line(backBuffer, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, w/2 + gridr[0][10].x, h/2 + gridr[0][10].y, makecol(0, 255, 0));
//
//
//			line(backBuffer, w/2 + gridr[1][1].x, h/2 + gridr[1][1].y, w/2 + gridr[1][13].x, h/2 + gridr[1][13].y, makecol(0, 255, 0));
//
//			line(backBuffer, w/2 + gridr[1][2].x, h/2 + gridr[1][2].y, w/2 + gridr[1][14].x, h/2 + gridr[1][14].y, makecol(0, 255, 0));
//
//
//			line(backBuffer, w/2 + gridr[2][1].x, h/2 + gridr[2][1].y, w/2 + gridr[2][13].x, h/2 + gridr[2][13].y, makecol(0, 255, 0));
//
//			line(backBuffer, w/2 + gridr[2][2].x, h/2 + gridr[2][2].y, w/2 + gridr[2][14].x, h/2 + gridr[2][14].y, makecol(0, 255, 0));
//
//
//
//			line(backBuffer, w/2 + gridr[1][4].x, h/2 + gridr[1][4].y, w/2 + gridr[1][7].x, h/2 + gridr[1][7].y, makecol(0, 255, 0));
//
//			line(backBuffer, w/2 + gridr[1][8].x, h/2 + gridr[1][8].y, w/2 + gridr[1][11].x, h/2 + gridr[1][11].y, makecol(0, 255, 0));
//
//
//			line(backBuffer, w/2 + gridr[2][4].x, h/2 + gridr[2][4].y, w/2 + gridr[2][7].x, h/2 + gridr[2][7].y, makecol(0, 255, 0));
//
//			line(backBuffer, w/2 + gridr[2][8].x, h/2 + gridr[2][8].y, w/2 + gridr[2][11].x, h/2 + gridr[2][11].y, makecol(0, 255, 0));
//
//
//			/*
//
//			//line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(0, 255, 0));
//			//rect(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][6].x, h/2 + gridr[3][6].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][6].x, h/2 + gridr[3][6].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][9].x, h/2 + gridr[3][9].y, w/2 + gridr[3][10].x, h/2 + gridr[3][10].y, makecol(255, 0, 255));
//			line(backBuffer, w/2 + gridr[3][5].x, h/2 + gridr[3][5].y, w/2 + gridr[3][9].x, h/2 + gridr[3][9].y, makecol(255, 0, 255));
//
//			*/
//
//
//
//			//axis lines
//
//			int urgle, gurgle, burgle;
//
//			sixShoot(urgle, gurgle, burgle);
//
//			//line(backBuffer, w/2 + bits[0][8].x + 50, h/2 + bits[0][8].y, w/2 + bits[2][8].x + 50, h/2 + bits[2][8].y, makecol(0, 255, 0));
//
//			//x axis
//			line(backBuffer, w/2 + axis[0].x, h/2 + axis[0].y, w/2 + axis[2].x, h/2 + axis[2].y, makecol(urgle, gurgle, burgle));
//			textprintf(backBuffer, font, w/2 + axis[1].x, h/2 + axis[1].y - 3, makecol(urgle, gurgle, burgle), "x");
//			/*
//			line(backBuffer, w/2 + axis[2].x + 10, h/2 + axis[2].y + 10, w/2 + axis[2].x, h/2 + axis[2].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + axis[2].x + 10, h/2 + axis[2].y - 10, w/2 + axis[2].x, h/2 + axis[2].y, makecol(0, 255, 0));
//			*/
//			sixShoot(urgle, gurgle, burgle);
//			line(backBuffer, w/2 + axis[0].x, h/2 + axis[0].y, w/2 + axis[4].x, h/2 + axis[4].y, makecol(urgle, gurgle, burgle));
//			textprintf(backBuffer, font, w/2 + axis[3].x - 3, h/2 + axis[3].y, makecol(urgle, gurgle, burgle), "y");
//			sixShoot(urgle, gurgle, burgle);
//			line(backBuffer, w/2 + axis[0].x, h/2 + axis[0].y, w/2 + axis[6].x, h/2 + axis[6].y, makecol(urgle, gurgle, burgle));
//			textprintf(backBuffer, font, w/2 + axis[5].x - 3, h/2 + axis[5].y - 3, makecol(urgle, gurgle, burgle), "z");
//
//
//			//bits dots
//			i = 0;
//			while(i<3)
//			{
//				j=0;
//				while(j<9)
//				{
//
//					putpixel(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, makecol(0, 255, 0));
//
//					j++;
//				}
//				i++;
//			}
//
//
//		}
//
//
//
//
//		//gameplay
//
//		i = 0;
//		while(i<3)
//		{
//			j = 0;
//			while(j<9)
//			{
//				if(j>=6)
//				{
//					bits[i][j].x = grid[i][j + 2].x + 25;
//					bits[i][j].y = grid[i][j + 2].y + 25;
//					bits[i][j].z = grid[i][j + 2].z + 25;
//				}
//				else if(j>=3)
//				{
//					bits[i][j].x = grid[i][j + 1].x + 25;
//					bits[i][j].y = grid[i][j + 1].y + 25;
//					bits[i][j].z = grid[i][j + 1].z + 25;
//				}
//				else
//				{
//					bits[i][j].x = grid[i][j].x + 25;
//					bits[i][j].y = grid[i][j].y + 25;
//					bits[i][j].z = grid[i][j].z + 25;
//				}
//
//				j++;
//			}
//			i++;
//		}
//
//		i = 0;
//		while(i<3)
//		{
//			j = 0;
//			while(j<9)
//			{
//				rotate(bits[i][j], angle.x, 'x', bits[i][j]);
//				rotate(bits[i][j], angle.y, 'y', bits[i][j]);
//				rotate(bits[i][j], angle.z, 'z', bits[i][j]);
//				j++;
//			}
//			i++;
//		}
//
//		
//		//oreos
//
//
//		/*
//		////selection
//		if(key[KEY_F])
//		{
//			kay = 3;
//		}
//		else if(key[KEY_G])
//		{
//			kay = 4;
//		}
//		else if(key[KEY_H])
//		{
//			kay = 5;
//		}
//		else if(key[KEY_R])
//		{
//			kay = 0;
//		}
//		else if(key[KEY_T])
//		{
//			kay = 1;
//		}
//		else if(key[KEY_Y])
//		{
//			kay = 2;
//		}
//		else if(key[KEY_V])
//		{
//			kay = 6;
//		}
//		else if(key[KEY_B])
//		{
//			kay = 7;
//		}
//		else if(key[KEY_N])
//		{
//			kay = 8;
//		}
//
//		if(key[KEY_UP])
//		{
//			if(level<2)
//			{
//				level ++;
//			}
//		}
//		else if(key[KEY_DOWN])
//		{
//			if(level>0)
//			{
//				level --;
//			}
//		}
//
//		
//		if(((kay>=0)&&(kay<=8))&&((level>=0)&&(kay<=2)))
//		{
//			circleMixer(w/2 + bits[level][kay].x, h/2 + bits[level][kay].y, 25, 2, 1, 0, 0);
//		}*/
//
//		
//
//		if(mouse_b&1)
//		{
//			int mx, my;
//			mx = mouse_x;
//			my = mouse_y;
//			i = 0;
//			while(i<3)
//			{
//				j = 0;
//				while(j<9)
//				{
//					int radical = 10;
//					//if(((mouse_x>bits[i][j].x - 10)&&(mouse_x<bits[i][j].x + 10)) && ((mouse_y>bits[i][j].y - 10)&&(mouse_y<bits[i][j].y + 10)))
//					if(((mx>w/2 + bits[i][j].x - radical)&&(mx<w/2 + bits[i][j].x + radical)) && ((my>h/2 + bits[i][j].y - radical)&&(my<h/2 + bits[i][j].y + radical)))
//					{
//						level = i;
//						kay = j;
//						pick = true;
//					}
//					j++;
//				}
//				i++;
//			}
//		}
//
//		//if(((kay>=0)&&(kay<=8))&&((level>=0)&&(kay<=2)))
//		if(pick)
//		{
//			circleMixer(w/2 + bits[level][kay].x, h/2 + bits[level][kay].y, 8, 2, 6, 1, 0, 1);
//		}
//
//		if(pick)
//		{
//			if((key[KEY_Z])||(key[KEY_O]))
//			{
//				oreos[level][kay] = 2;
//				pick = false;
//			}
//			else if(key[KEY_X])
//			{
//				oreos[level][kay] = 1;
//				pick = false;
//			}
//			else if(key[KEY_C])
//			{
//				oreos[level][kay] = 0;
//				pick = false;
//			}
//
//			if(key[KEY_A])
//			{
//				level = 0;
//			}
//			else if(key[KEY_S])
//			{
//				level = 1;
//			}
//			else if(key[KEY_D])
//			{
//				level = 2;
//			}
//
//
//		}
//
//
//		if(key[KEY_8_PAD])
//		{
//			angle.x -= speed;
//		}
//		if(key[KEY_2_PAD])
//		{
//			angle.x += speed;
//		}
//
//		if(key[KEY_4_PAD])
//		{
//			angle.y += speed;
//		}
//		if(key[KEY_6_PAD])
//		{
//			angle.y -= speed;
//		}
//
//		if(key[KEY_7_PAD])
//		{
//			angle.z += speed;
//		}
//		if(key[KEY_3_PAD])
//		{
//			angle.z -= speed;
//		}
//
//		if(key[KEY_5_PAD])
//		{
//			angle.x = 0;
//			angle.y = 0;
//			angle.z = 0;
//		}
//
//
//		if(key[KEY_MINUS_PAD])
//		{
//			oreos[level][kay] = 2;
//		}
//		if(key[KEY_ASTERISK])
//		{
//			oreos[level][kay] = 1;
//		}
//		if(key[KEY_SLASH_PAD])
//		{
//			oreos[level][kay] = 2;
//		}
//
//
//
//		i = 0;
//		while(i<3)
//		{
//			j = 0;
//			while(j<9)
//			{
//				if(oreos[i][j]==1)
//				{
//					//droreos
//					//circleMixer(w/2 + bits[i][j].x, h/2 + bits[i][j].y, 25, 1, 0, 0, 1);
//					line(backBuffer, w/2 + bits[i][j].x - 5, h/2 + bits[i][j].y - 5, w/2 + bits[i][j].x + 5, h/2 + bits[i][j].y + 5, makecol(255, 0, 0));
//					line(backBuffer, w/2 + bits[i][j].x - 5, h/2 + bits[i][j].y + 5, w/2 + bits[i][j].x + 5, h/2 + bits[i][j].y - 5, makecol(255, 0, 0));
//				}
//				else if(oreos[i][j]==2)
//				{
//					//circleMixer(w/2 + bits[i][j].x, h/2 + bits[i][j].y, 25, 1, 1, 1, 0);
//					circle(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, 5, makecol(0, 255, 255));
//				}
//				j++;
//			}
//			i++;
//		}
//
//
//
//		//////win checker
//		int check[49];
//		i = 0;
//		while(i<49)
//		{
//			check[i] = 0;
//			i ++;
//		}
//		int c = 0;
//
//		
//		//super mid taken
//		if(oreos[1][4]!=0)
//		{
//
//			i = 0;
//			while(i<2)
//			{
//				//supermid
//
//				j = 0;
//					while(j<9)
//					{
//						if((i==1)&&(j==4))
//						{
//							j++;
//						}
//
//						if((oreos[i][j]==oreos[1][4])&&(oreos[2-i][8-j]==oreos[1][4]))
//						{
//							if(oreos[1][4]==1)
//							{
//								line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][8-j].x, h/2 + bits[2-i][8-j].y, makecol(255, 0, 0));
//								//xWin ++;
//							}
//							else if(oreos[1][4]==2)
//							{
//								line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][8-j].x, h/2 + bits[2-i][8-j].y, makecol(0, 255, 255));
//								//oWin ++;
//							}
//						}
//						j++;
//					}
//
//				i++;
//			}
//		}
//		
//
//		
//		//singlemid
//
//		//front and back
//		i = 0;
//		while(i<3)
//		{
//			if(oreos[i][4]!=0)
//			{
//
//				j = 0;
//				while(j<9)
//				{
//					if(j==4)
//					{
//						j++;
//					}
//
//					if((oreos[i][j] == oreos[i][4])&&(oreos[i][8-j] == oreos[i][4]))
//					{
//
//						if(oreos[i][4]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[i][8-j].x, h/2 + bits[i][8-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[i][4]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[i][8-j].x, h/2 + bits[i][8-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//
//					j++;
//				}
//
//			}
//			i += 2;
//		}
//
//		//left and right
//		
//		//left
//		if(oreos[1][3]!=0)
//		{
//			i=0;
//			while(i<3)
//			{
//				j=0;
//				while(j<8)
//				{
//					if((oreos[i][j] == oreos[1][3])&&(oreos[2-i][6-j] == oreos[1][3]))
//					{
//
//						if(oreos[1][3]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][6-j].x, h/2 + bits[2-i][6-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[1][3]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][6-j].x, h/2 + bits[2-i][6-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//					j+=3;
//				}
//				i++;
//			}
//		}
//
//		//right
//		
//		if(oreos[1][5]!=0)
//		{
//			i=0;
//			while(i<3)
//			{
//				j=2;
//				while(j<9)
//				{
//					if((oreos[i][j] == oreos[1][5])&&(oreos[2-i][10-j] == oreos[1][5]))
//					{
//
//						if(oreos[1][5]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][10-j].x, h/2 + bits[2-i][10-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[1][5]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][10-j].x, h/2 + bits[2-i][10-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//					j+=3;
//				}
//				i++;
//			}
//		}
//
//		//top and bottom
//		
//		//top
//		if(oreos[1][1]!=0)
//		{
//			i=0;
//			while(i<3)
//			{
//				j=0;
//				while(j<3)
//				{
//					if((oreos[i][j] == oreos[1][1])&&(oreos[2-i][2-j] == oreos[1][1]))
//					{
//
//						if(oreos[1][1]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][2-j].x, h/2 + bits[2-i][2-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[1][1]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][2-j].x, h/2 + bits[2-i][2-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//					j++;
//				}
//				i++;
//			}
//		}
//		//bottom
//		if(oreos[1][7]!=0)
//		{
//			i=0;
//			while(i<3)
//			{
//				j=6;
//				while(j<9)
//				{
//					if((oreos[i][j] == oreos[1][7])&&(oreos[2-i][14-j] == oreos[1][7]))
//					{
//
//						if(oreos[1][7]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][14-j].x, h/2 + bits[2-i][14-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[1][7]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][14-j].x, h/2 + bits[2-i][14-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//					j++;
//				}
//				i++;
//			}
//		}
//
//
//		
///*
//		//edges
//		i=0;
//		while(i<3)
//		{
//			j=0;
//			while(j<9)
//			{
//
//				if(oreos[i][7]!=0)
//				{
//
//					if((oreos[i][j] == oreos[1][7])&&(oreos[2-i][14-j] == oreos[1][7]))
//					{
//
//						if(oreos[1][7]==1)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][14-j].x, h/2 + bits[2-i][14-j].y, makecol(255, 0, 0));
//							//xWin ++;
//						}
//						else if(oreos[1][7]==2)
//						{
//							line(backBuffer, w/2 + bits[i][j].x, h/2 + bits[i][j].y, w/2 + bits[2-i][14-j].x, h/2 + bits[2-i][14-j].y, makecol(0, 255, 255));
//							//oWin ++;
//						}
//
//					}
//
//
//				}
//
//				j+=2;
//				if(j==4)
//				{
//					j += 2;
//				}
//
//			}
//			i+=2;
//		}
//		*/
//
//
//		////EDGES
//
//		if(oreos[0][0]!=0)
//		{
//
//			if((oreos[0][6] == oreos[0][0])&&(oreos[0][3] == oreos[0][0]))
//			{
//
//				if(oreos[0][0]==1)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][0]==2)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[0][2] == oreos[0][0])&&(oreos[0][1] == oreos[0][0]))
//			{
//
//				if(oreos[0][0]==1)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][0]==2)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[2][0] == oreos[0][0])&&(oreos[1][0] == oreos[0][0]))
//			{
//
//				if(oreos[0][0]==1)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][0]==2)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[0][0].x, h/2 + bits[0][0].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//
//		}
//		
//		if(oreos[2][2]!=0)
//		{
//
//			if((oreos[2][8] == oreos[2][2])&&(oreos[2][5] == oreos[2][2]))
//			{
//
//				if(oreos[2][2]==1)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][2]==2)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[0][2] == oreos[2][2])&&(oreos[1][2] == oreos[2][2]))
//			{
//
//				if(oreos[2][2]==1)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][2]==2)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[2][0] == oreos[2][2])&&(oreos[2][1] == oreos[2][2]))
//			{
//
//				if(oreos[2][2]==1)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][2]==2)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[2][2].x, h/2 + bits[2][2].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//
//		}
//
//		if(oreos[0][8]!=0)
//		{
//
//			if((oreos[0][2] == oreos[0][8])&&(oreos[0][5] == oreos[0][8]))
//			{
//
//				if(oreos[0][8]==1)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][8]==2)
//				{
//					line(backBuffer, w/2 + bits[0][2].x, h/2 + bits[0][2].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[0][6] == oreos[0][8])&&(oreos[0][7] == oreos[0][8]))
//			{
//
//				if(oreos[0][8]==1)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][8]==2)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[2][8] == oreos[0][8])&&(oreos[1][8] == oreos[0][8]))
//			{
//
//				if(oreos[0][8]==1)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[0][8]==2)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[0][8].x, h/2 + bits[0][8].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//
//		}
//
//		if(oreos[2][6]!=0)
//		{
//
//			if((oreos[2][0] == oreos[2][6])&&(oreos[2][3] == oreos[2][6]))
//			{
//
//				if(oreos[2][6]==1)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][6]==2)
//				{
//					line(backBuffer, w/2 + bits[2][0].x, h/2 + bits[2][0].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[2][8] == oreos[2][6])&&(oreos[2][7] == oreos[2][6]))
//			{
//
//				if(oreos[2][6]==1)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][6]==2)
//				{
//					line(backBuffer, w/2 + bits[2][8].x, h/2 + bits[2][8].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//			if((oreos[0][6] == oreos[2][6])&&(oreos[1][6] == oreos[2][6]))
//			{
//
//				if(oreos[2][6]==1)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(255, 0, 0));
//					//xWin ++;
//				}
//				else if(oreos[2][6]==2)
//				{
//					line(backBuffer, w/2 + bits[0][6].x, h/2 + bits[0][6].y, w/2 + bits[2][6].x, h/2 + bits[2][6].y, makecol(0, 255, 255));
//					//oWin ++;
//				}
//
//			}
//
//
//		}
//
//
////////wins
//
////x direction
//
//if((oreos[0][0] == oreos[0][1]) && (oreos[0][2] == oreos[0][1]))
//{
//	wins[0] = oreos[0][1];
//}
//if((oreos[0][3] == oreos[0][4]) && (oreos[0][5] == oreos[0][4]))
//{
//	wins[1] = oreos[0][4];
//}
//if((oreos[0][6] == oreos[0][7]) && (oreos[0][8] == oreos[0][7]))
//{
//	wins[2] = oreos[0][7];
//}
//
//
//if((oreos[1][0] == oreos[1][1]) && (oreos[1][2] == oreos[1][1]))
//{
//	wins[3] = oreos[1][1];
//}
//if((oreos[1][3] == oreos[1][4]) && (oreos[1][5] == oreos[1][4]))
//{
//	wins[4] = oreos[1][4];
//}
//if((oreos[1][6] == oreos[1][7]) && (oreos[1][8] == oreos[1][7]))
//{
//	wins[5] = oreos[1][7];
//}
//
//
//if((oreos[2][0] == oreos[2][1]) && (oreos[2][2] == oreos[2][1]))
//{
//	wins[6] = oreos[2][1];
//}
//if((oreos[2][3] == oreos[2][4]) && (oreos[2][5] == oreos[2][4]))
//{
//	wins[7] = oreos[2][4];
//}
//if((oreos[2][6] == oreos[2][7]) && (oreos[2][8] == oreos[2][7]))
//{
//	wins[8] = oreos[2][7];
//}
//
//
//
////y direction
//
//if((oreos[0][0] == oreos[0][3]) && (oreos[0][6] == oreos[0][3]))
//{
//	wins[9] = oreos[0][3];
//}
//if((oreos[0][1] == oreos[0][4]) && (oreos[0][7] == oreos[0][4]))
//{
//	wins[10] = oreos[0][4];
//}
//if((oreos[0][2] == oreos[0][5]) && (oreos[0][8] == oreos[0][5]))
//{
//	wins[11] = oreos[0][5];
//}
//
//
//if((oreos[1][0] == oreos[1][3]) && (oreos[1][6] == oreos[1][3]))
//{
//	wins[12] = oreos[1][3];
//}
//if((oreos[1][1] == oreos[1][4]) && (oreos[1][7] == oreos[1][4]))
//{
//	wins[13] = oreos[1][4];
//}
//if((oreos[1][2] == oreos[1][5]) && (oreos[1][8] == oreos[1][5]))
//{
//	wins[14] = oreos[1][5];
//}
//
//
//if((oreos[2][0] == oreos[2][3]) && (oreos[2][6] == oreos[2][3]))
//{
//	wins[15] = oreos[2][3];
//}
//if((oreos[2][1] == oreos[2][4]) && (oreos[2][7] == oreos[2][4]))
//{
//	wins[16] = oreos[2][4];
//}
//if((oreos[2][2] == oreos[2][5]) && (oreos[2][8] == oreos[2][5]))
//{
//	wins[17] = oreos[2][5];
//}
//
//
//
////z direction
//
//if((oreos[0][0] == oreos[1][0]) && (oreos[2][0] == oreos[1][0]))
//{
//	wins[18] = oreos[1][0];
//}
//if((oreos[0][1] == oreos[1][1]) && (oreos[2][1] == oreos[1][1]))
//{
//	wins[19] = oreos[1][1];
//}
//if((oreos[0][2] == oreos[1][2]) && (oreos[2][2] == oreos[1][2]))
//{
//	wins[20] = oreos[1][2];
//}
//
//
//if((oreos[0][3] == oreos[1][3]) && (oreos[2][3] == oreos[1][3]))
//{
//	wins[21] = oreos[1][3];
//}
//if((oreos[0][4] == oreos[1][4]) && (oreos[2][4] == oreos[1][4]))
//{
//	wins[22] = oreos[1][4];
//}
//if((oreos[0][5] == oreos[1][5]) && (oreos[2][5] == oreos[1][5]))
//{
//	wins[23] = oreos[1][5];
//}
//
//
//if((oreos[0][6] == oreos[1][6]) && (oreos[2][6] == oreos[1][6]))
//{
//	wins[24] = oreos[1][6];
//}
//if((oreos[0][7] == oreos[1][7]) && (oreos[2][7] == oreos[1][7]))
//{
//	wins[25] = oreos[1][7];
//}
//if((oreos[0][8] == oreos[1][8]) && (oreos[2][8] == oreos[1][8]))
//{
//	wins[26] = oreos[1][8];
//}
//
//
//
////diagonals
//
////front
//if((oreos[0][0] == oreos[0][4]) && (oreos[0][8] == oreos[0][4]))
//{
//	wins[27] = oreos[0][4];
//}
//if((oreos[0][2] == oreos[0][4]) && (oreos[0][6] == oreos[0][4]))
//{
//	wins[28] = oreos[0][4];
//}
////back
//if((oreos[2][0] == oreos[2][4]) && (oreos[2][8] == oreos[2][4]))
//{
//	wins[29] = oreos[2][4];
//}
//if((oreos[2][2] == oreos[2][4]) && (oreos[2][6] == oreos[2][4]))
//{
//	wins[30] = oreos[2][4];
//}
//
//
////top
//if((oreos[0][0] == oreos[1][1]) && (oreos[2][2] == oreos[1][1]))
//{
//	wins[31] = oreos[1][1];
//}
//if((oreos[2][0] == oreos[1][1]) && (oreos[0][2] == oreos[1][1]))
//{
//	wins[32] = oreos[1][1];
//}
////bottom
//if((oreos[0][6] == oreos[1][7]) && (oreos[2][8] == oreos[1][7]))
//{
//	wins[33] = oreos[1][7];
//}
//if((oreos[2][6] == oreos[1][7]) && (oreos[0][8] == oreos[1][7]))
//{
//	wins[34] = oreos[1][7];
//}
//
//
////left
//if((oreos[0][0] == oreos[1][3]) && (oreos[2][6] == oreos[1][3]))
//{
//	wins[35] = oreos[1][3];
//}
//if((oreos[2][0] == oreos[1][3]) && (oreos[0][6] == oreos[1][3]))
//{
//	wins[36] = oreos[1][3];
//}
////right
//if((oreos[0][2] == oreos[1][5]) && (oreos[2][8] == oreos[1][5]))
//{
//	wins[37] = oreos[1][5];
//}
//if((oreos[2][2] == oreos[1][5]) && (oreos[0][8] == oreos[1][5]))
//{
//	wins[38] = oreos[1][5];
//}
//
//
////super mid diagonals
//if((oreos[0][0] == oreos[1][4]) && (oreos[2][8] == oreos[1][4]))
//{
//	wins[39] = oreos[1][4];
//}
//if((oreos[2][0] == oreos[1][4]) && (oreos[0][8] == oreos[1][4]))
//{
//	wins[40] = oreos[1][4];
//}
//
//if((oreos[0][2] == oreos[1][4]) && (oreos[2][6] == oreos[1][4]))
//{
//	wins[41] = oreos[1][4];
//}
//if((oreos[2][2] == oreos[1][4]) && (oreos[0][6] == oreos[1][4]))
//{
//	wins[42] = oreos[1][4];
//}
//
//i = 0;
//xWin = 0;
//oWin = 0;
//while(i<43)
//{
//	if(wins[i]==1)
//	{
//		xWin ++;
//	}
//	else if(wins[i]==2)
//	{
//		oWin ++;
//	}
//	i++;
//}
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//		update();
//	}
//}
//END_OF_MAIN()