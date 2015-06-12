//#include<stdio.h>
//#include<allegro.h>
//#include<stdlib.h>
//#include<math.h>
//
//BITMAP * backBuffer;
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
//	int w = 640;
//	int h = 480;
//
//	int ticker;
//
//	point disp = {0, 0, 0};
//
//	int i = 0;
//	int j = 0;
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
//
//		//////#########PreWrites#########
//
//
//		///*
//		//Colour 6 Shooter
//		//solid rand colours
//		//reproduces [respectively]:
//		//red				0
//		//green			1
//		//blue			2
//		//yellow/orange	3
//		//purple			4
//		//turkoise?		5
//		//*/
//		//int col, r, g, b;
//		//col = rand()%6;
//		//if(col==0){
//		//	r=rand()%256;
//		//	g=0;
//		//	b=0;}
//		//if(col==1){
//		//	r=0;
//		//	g=rand()%256;
//		//	b=0;}
//		//if(col==2){
//		//	r=0;
//		//	g=0;
//		//	b=rand()%256;}
//		//if(col==3){
//		//	r=rand()%256;
//		//	g=rand()%256;
//		//	b=0;}
//		//if(col==4){
//		//	r=rand()%256;
//		//	g=0;
//		//	b=rand()%256;}
//		//if(col==5){
//		//	r=0;
//		//	g=rand()%256;
//		//	b=rand()%256;}
//		////colours
//
//
//		///*
//		//Button Template
//		//*/
//		//float buttonX = 45;
//		//float buttonY = 40;
//		//float buttonRadius = 25;
//		////copy-paste from here, (use same floats through code to avoid find replaces)--> to be confirmed
//		//circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		////   y co-ordinates vary in textprint lines
//		//textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 5), makecol(150, 150, 150), "2 Line");
//		//textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 5), makecol(150, 150, 150), "Button Title");
//		//if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//		//	&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//		//	if(mouse_b&1){
//		//		//while mouse is still within button
//		//		while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//		//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//
//		//		}
//		//	}
//		//}
//
//
//
//		//////#########/PreWrites#########
//
//
//		//cursor
//		line(backBuffer, mouse_x, mouse_y, mouse_x + 5, mouse_y + 5, makecol(255, 255, 255));
//
//
//
//		/*
//		Grid
//
//		a for layer 1
//		b layer 2
//		c layer 3
//
//		4 points per line
//		16 points per face/layer
//		*/
//
//
//		
//		////layer a
//		//top line
//		point a1 = {-75, -75, 75};
//		point a2 = {-25, -75, 75};
//		point a3 = {25, -75, 75};
//		point a4 = {75, -75, 75};
//		//2nd top
//		point a5 = {-75, -25, 75};
//		point a6 = {-25, -25, 75};
//		point a7 = {25, -25, 75};
//		point a8 = {75, -25, 75};
//		//2nd bottom
//		point a9 = {-75, 25, 75};
//		point a10 = {-25, 25, 75};
//		point a11 = {25, 25, 75};
//		point a12 = {75, 25, 75};
//		//bottom line
//		point a13 = {-75, 75, 75};
//		point a14 = {-25, 75, 75};
//		point a15 = {25, 75, 75};
//		point a16 = {75, 75, 75};
//
//
//		point pos;
//		pos.x = w/2;
//		pos.y = h/2;
//
//		////draw grid
//		//horizontal lines
//		line(backBuffer, disp.x + (pos.x + a1.x), (pos.y + a1.y), disp.x + (pos.x +  a4.x), (pos.y +  a4.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a5.x), (pos.y + a5.y), disp.x + (pos.x +  a8.x), (pos.y +  a8.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a9.x), (pos.y + a9.y), disp.x + (pos.x +  a12.x), (pos.y +  a12.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a13.x), (pos.y + a13.y), disp.x + (pos.x +  a16.x), (pos.y +  a16.y), makecol(255, 0, 0));
//		//verticle lines
//		line(backBuffer, disp.x + (pos.x + a1.x), (pos.y + a1.y), disp.x + (pos.x +  a13.x), (pos.y +  a13.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a2.x), (pos.y + a2.y), disp.x + (pos.x +  a14.x), (pos.y +  a14.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a3.x), (pos.y + a3.y), disp.x + (pos.x +  a15.x), (pos.y +  a15.y), makecol(255, 0, 0));
//		line(backBuffer, disp.x + (pos.x + a4.x), (pos.y + a4.y), disp.x + (pos.x +  a16.x), (pos.y +  a16.y), makecol(255, 0, 0));
//
//
//		//mousing
//		/*if(mouse_b&1)
//		{
//			point init;
//			init.x = mouse_x;
//			init.y = mouse_y;
//
//			point end;
//			end
//		}*/
//
//		//attempt to rotate about up axis
//		if(key[KEY_RIGHT])
//		{
//			ticker = 0;
//
//			while(key[KEY_RIGHT])
//			{
//				ticker ++;
//			}
//
//			disp.x = ticker;
//
//		}
//		else if(key[KEY_LEFT])
//		{
//			ticker = 0;
//
//			while(key[KEY_LEFT])
//			{
//				ticker --;
//			}
//
//			disp.x = ticker;
//
//		}
//
//
//		while((disp.x * disp.x) > (75 * 75))
//		{
//			disp.x -= 75;
//		}
//
//
//
//
//
////////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//		blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
//	}
//}
//END_OF_MAIN()