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
//	float f = realworld.z - origin.z;
//
//	projection.x = ((realworld.x - origin.x) * (f / realworld.z)) + origin.x;
//	projection.y = ((realworld.y - origin.y) * (f / realworld.z)) + origin.y;
//
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
//	float radian = (angle * 3.14159265) / 180;
//
//
//	if(axis=='x')
//	{
//		projection.y = (realworld.y * cos(radian)) + (realworld.z * sin(radian));
//		projection.z = (realworld.z * cos(radian)) - (realworld.y * sin(radian));
//	}
//	else if(axis=='y')
//	{
//		projection.x = (realworld.x * cos(radian)) - (realworld.z * sin(radian));
//		projection.z = (realworld.z * cos(radian)) + (realworld.x * sin(radian));
//	}
//	else if(axis=='z')
//	{
//		projection.x = (realworld.x * cos(radian)) + (realworld.y * sin(radian));
//		projection.y = (realworld.y * cos(radian)) - (realworld.x * sin(radian));
//	}
//
//}
//
//float project(float xyPoint, float z)
//{
//	float pp;
//
//	//x point
//	pp = xyPoint * 256 / z;
//
//	return(pp);
//}
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
//	point camera = {0, 0, 0};
//
//	point angle = {0, 0, 0};
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
//		////#########PreWrites#########
//
//
//		// Colour 6 Shooter
//		//   solid rand colours
//		//   reproduces [respectively]:
//		//      red				0
//		//      green			1
//		//      blue			2
//		//      yellow/orange	3
//		//      purple			4
//		//      turkoise?		5
//		int col, r, g, b;
//		col = rand()%6;
//		if(col==0){
//			r=rand()%256;
//			g=0;
//			b=0;}
//		if(col==1){
//			r=0;
//			g=rand()%256;
//			b=0;}
//		if(col==2){
//			r=0;
//			g=0;
//			b=rand()%256;}
//		if(col==3){
//			r=rand()%256;
//			g=rand()%256;
//			b=0;}
//		if(col==4){
//			r=rand()%256;
//			g=0;
//			b=rand()%256;}
//		if(col==5){
//			r=0;
//			g=rand()%256;
//			b=rand()%256;}
//		//colours
//
//
//		
//		//Button Template
//		float buttonX = 45;
//		float buttonY = 40;
//		float buttonRadius = 25;
//		//copy-paste from here, (use same floats through code to avoid find replaces)--> to be confirmed
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		//   y co-ordinates vary in textprint lines
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 5), makecol(150, 150, 150), "2 Line");
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 5), makecol(150, 150, 150), "Button Title");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				//while mouse is still within button
//				while( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//					&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//
//				}
//			}
//		}
//
//		/*
//		float archer(int xOrY, float centerP, float radius, float angle){
//
//			int x;
//
//			float radian=(angle*3.14159265)/180;
//	
//			float differ;
//			differ = xOrY == 0 ? (radius * cos(radian)) : (radius * sin(radian));
//
//			//if(
//			x = centerP + differ;
//
//			return x;
//
//		}
//		*/
//
//		
//
//		////#########/PreWrites#########
//
//
//
//
//		//   3d xs and os
//		// conor stefanini
//		//
//		//   working with:
//		//      http://membres.multimania.fr/amycoders/tutorials/3dbasics.html
//		//
//
//		// user point (b) = (0, 0, 0)
//		// a = 3d point
//		// a = (x, y, z)
//		// a' = transformation of 3d point to projected point
//		// a' = (u, v, 256)
//		//     on the z=256 plane
//		//   u = x * 256 / z
//		//   v = y * 256 / z
//
//
//		//hardcode
//
//
//		//write function for that (px, py) and hardcode more
//		//px = x * 256 / z;
//		//py = y * 256 / z;
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
//		////layer b
//		//top line
//		point b1 = {-75, -75, 125};
//		point b2 = {-25, -75, 125};
//		point b3 = {25, -75, 125};
//		point b4 = {75, -75, 125};
//		//2nd top
//		point b5 = {-75, -25, 125};
//		point b6 = {-25, -25, 125};
//		point b7 = {25, -25, 125};
//		point b8 = {75, -25, 125};
//		//2nd bottom
//		point b9 = {-75, 25, 125};
//		point b10 = {-25, 25, 125};
//		point b11 = {25, 25, 125};
//		point b12 = {75, 25, 125};
//		//bottom line
//		point b13 = {-75, 75, 125};
//		point b14 = {-25, 75, 125};
//		point b15 = {25, 75, 125};
//		point b16 = {75, 75, 125};
//		////layer c
//		//top line
//		point c1 = {-75, -75, 175};
//		point c2 = {-25, -75, 175};
//		point c3 = {25, -75, 175};
//		point c4 = {75, -75, 175};
//		//2nd top
//		point c5 = {-75, -25, 175};
//		point c6 = {-25, -25, 175};
//		point c7 = {25, -25, 175};
//		point c8 = {75, -25, 175};
//		//2nd bottom
//		point c9 = {-75, 25, 175};
//		point c10 = {-25, 25, 175};
//		point c11 = {25, 25, 175};
//		point c12 = {75, 25, 175};
//		//bottom line
//		point c13 = {-75, 75, 175};
//		point c14 = {-25, 75, 175};
//		point c15 = {25, 75, 175};
//		point c16 = {75, 75, 175};
//
//
//		/*
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
//		*/
//
//
//
//
//
//		/*
//		float px;
//		float py;
//
//		px = project(a1.x, a1.z);
//		py = project(a1.y, a1.z);
//
//		putpixel(backBuffer, px, py, makecol(0, 0, 0));
//		*/
//
//		int w = 640;
//		int h = 480;
//
//		point realworld = a1;
//		point projectA[16] = {0, 0, 0};
//		proj3d(a1, camera, projectA[0]);
//		proj3d(a2, camera, projectA[1]);
//		proj3d(a3, camera, projectA[2]);
//		proj3d(a4, camera, projectA[3]);
//
//		proj3d(a5, camera, projectA[4]);
//		proj3d(a8, camera, projectA[7]);
//
//		proj3d(a9, camera, projectA[8]);
//		proj3d(a12, camera, projectA[11]);
//
//		proj3d(a13, camera, projectA[12]);
//		proj3d(a14, camera, projectA[13]);			
//		proj3d(a15, camera, projectA[14]);
//		proj3d(a16, camera, projectA[15]);
//
//		point projectB[16];
//		proj3d(b1, camera, projectB[0]);
//		proj3d(b2, camera, projectB[1]);
//		proj3d(b3, camera, projectB[2]);
//		proj3d(b4, camera, projectB[3]);
//
//		proj3d(b5, camera, projectB[4]);
//		proj3d(b8, camera, projectB[7]);
//
//		proj3d(b9, camera, projectB[8]);
//		proj3d(b12, camera, projectB[11]);
//
//		proj3d(b13, camera, projectB[12]);
//		proj3d(b14, camera, projectB[13]);			
//		proj3d(b15, camera, projectB[14]);
//		proj3d(b16, camera, projectB[15]);
//
//
//		//layer A
//		//topline
//		line(backBuffer, w/2 + projectA[0].x, h/2 + projectA[0].y, w/2 + projectA[1].x, h/2 + projectA[1].y, makecol(0,255,0));
//		line(backBuffer, w/2 + projectA[1].x, h/2 + projectA[1].y, w/2 + projectA[2].x, h/2 + projectA[2].y, makecol(0,255,0));
//		line(backBuffer, w/2 + projectA[2].x, h/2 + projectA[2].y, w/2 + projectA[3].x, h/2 + projectA[3].y, makecol(0,255,0));
//		//2nd top line
//		line(backBuffer, w/2 + projectA[4].x, h/2 + projectA[4].y, w/2 + projectA[7].x, h/2 + projectA[7].y, makecol(0,255,0));
//		//2nd bottom
//		line(backBuffer, w/2 + projectA[8].x, h/2 + projectA[8].y, w/2 + projectA[11].x, h/2 + projectA[11].y, makecol(0,255,0));
//		//bottom
//		line(backBuffer, w/2 + projectA[12].x, h/2 + projectA[12].y, w/2 + projectA[15].x, h/2 + projectA[15].y, makecol(0,255,0));
//
//		//verticle lines
//		//1st
//		line(backBuffer, w/2 + projectA[0].x, h/2 + projectA[0].y, w/2 + projectA[12].x, h/2 + projectA[12].y, makecol(0,255,0));
//		//2nd
//		line(backBuffer, w/2 + projectA[1].x, h/2 + projectA[1].y, w/2 + projectA[13].x, h/2 + projectA[13].y, makecol(0,255,0));
//		//3rd
//		line(backBuffer, w/2 + projectA[2].x, h/2 + projectA[2].y, w/2 + projectA[14].x, h/2 + projectA[14].y, makecol(0,255,0));
//		//rightmost
//		line(backBuffer, w/2 + projectA[3].x, h/2 + projectA[3].y, w/2 + projectA[15].x, h/2 + projectA[15].y, makecol(0,255,0));
//
//
//		//layer B
//		//topline
//		line(backBuffer, w/2 + projectB[0].x, h/2 + projectB[0].y, w/2 + projectB[1].x, h/2 + projectB[1].y, makecol(0,255,0));
//		line(backBuffer, w/2 + projectB[1].x, h/2 + projectB[1].y, w/2 + projectB[2].x, h/2 + projectB[2].y, makecol(0,255,0));
//		line(backBuffer, w/2 + projectB[2].x, h/2 + projectB[2].y, w/2 + projectB[3].x, h/2 + projectB[3].y, makecol(0,255,0));
//		//2nd top line
//		line(backBuffer, w/2 + projectB[4].x, h/2 + projectB[4].y, w/2 + projectB[7].x, h/2 + projectB[7].y, makecol(0,255,0));
//		//2nd bottom
//		line(backBuffer, w/2 + projectB[8].x, h/2 + projectB[8].y, w/2 + projectB[11].x, h/2 + projectB[11].y, makecol(0,255,0));
//		//bottom
//		line(backBuffer, w/2 + projectB[12].x, h/2 + projectB[12].y, w/2 + projectB[15].x, h/2 + projectB[15].y, makecol(0,255,0));
//
//		//verticle lines
//		//1st
//		line(backBuffer, w/2 + projectB[0].x, h/2 + projectB[0].y, w/2 + projectB[12].x, h/2 + projectB[12].y, makecol(0,255,0));
//		//2nd
//		line(backBuffer, w/2 + projectB[1].x, h/2 + projectB[1].y, w/2 + projectB[13].x, h/2 + projectB[13].y, makecol(0,255,0));
//		//3rd
//		line(backBuffer, w/2 + projectB[2].x, h/2 + projectB[2].y, w/2 + projectB[14].x, h/2 + projectB[14].y, makecol(0,255,0));
//		//rightmost
//		line(backBuffer, w/2 + projectB[3].x, h/2 + projectB[3].y, w/2 + projectB[15].x, h/2 + projectB[15].y, makecol(0,255,0));
//
//
//		if(key[KEY_Z])
//		{
//			angle.z +=1;
//		}
//		if(key[KEY_X])
//		{
//			angle.x +=1;
//		}
//		if(key[KEY_C])
//		{
//			angle.y +=1;
//		}
//
//		
//		point projectA[16] = {0, 0, 0};
//		proj3d(a1, camera, projectA[0]);
//		proj3d(a2, camera, projectA[1]);
//		proj3d(a3, camera, projectA[2]);
//		proj3d(a4, camera, projectA[3]);
//
//		proj3d(a5, camera, projectA[4]);
//		proj3d(a8, camera, projectA[7]);
//
//		proj3d(a9, camera, projectA[8]);
//		proj3d(a12, camera, projectA[11]);
//
//		proj3d(a13, camera, projectA[12]);
//		proj3d(a14, camera, projectA[13]);			
//		proj3d(a15, camera, projectA[14]);
//		proj3d(a16, camera, projectA[15]);
//
//		point projectB[16];
//		proj3d(b1, camera, projectB[0]);
//		proj3d(b2, camera, projectB[1]);
//		proj3d(b3, camera, projectB[2]);
//		proj3d(b4, camera, projectB[3]);
//
//		proj3d(b5, camera, projectB[4]);
//		proj3d(b8, camera, projectB[7]);
//
//		proj3d(b9, camera, projectB[8]);
//		proj3d(b12, camera, projectB[11]);
//
//		proj3d(b13, camera, projectB[12]);
//		proj3d(b14, camera, projectB[13]);			
//		proj3d(b15, camera, projectB[14]);
//		proj3d(b16, camera, projectB[15]);
//
//		point projectB[16];
//		proj3d(b1, camera, projectB[0]);
//		proj3d(b2, camera, projectB[1]);
//		proj3d(b3, camera, projectB[2]);
//		proj3d(b4, camera, projectB[3]);
//
//		proj3d(b5, camera, projectB[4]);
//		proj3d(b8, camera, projectB[7]);
//
//		proj3d(b9, camera, projectB[8]);
//		proj3d(b12, camera, projectB[11]);
//
//		proj3d(b13, camera, projectB[12]);
//		proj3d(b14, camera, projectB[13]);			
//		proj3d(b15, camera, projectB[14]);
//		proj3d(b16, camera, projectB[15]);
//
//
////////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//		blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
//	}
//}
//END_OF_MAIN()