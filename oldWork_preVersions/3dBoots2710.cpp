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
//		//projection.x = realworld.x;
//		projection.y = (realworld.y * cos(radian)) + (realworld.z * sin(radian));
//		projection.z = (realworld.z * cos(radian)) - (realworld.y * sin(radian));
//	}
//	else if(axis=='y')
//	{
//		projection.x = (realworld.x * cos(radian)) - (realworld.z * sin(radian));
//		//projection.y = realworld.y;
//		projection.z = (realworld.z * cos(radian)) + (realworld.x * sin(radian));
//	}
//	else if(axis=='z')
//	{
//		projection.x = (realworld.x * cos(radian)) + (realworld.y * sin(radian));
//		projection.y = (realworld.y * cos(radian)) - (realworld.x * sin(radian));
//		//projection.z = realworld.z;
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
//	//point camera = {0, 0, 256};
//	point camera = {0, 0, 45};
//
//	point angle = {0, 0, 0};
//
//	point modelMid = {0, 0, 0};
//
//	int i = 0;
//	int j = 0;
//	int k = 0;
//
//	int draw = 0;
//
//	float speed = 1;
//
//	float buttonX;
//	float buttonY;
//	float buttonRadius;
//
//	bool poonel = false;
//
//	char lastAxis;
//	bool lastAx = false;
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
//		point realsA[9];
//		point realsB[9];
//		point realsC[9];
//
//		point points[4][16];
//
//		for(int j = 0; j < 4; j ++)
//		{
//			for(int i = 0; i < 16; i ++)
//			{
//
//				//x axises
//				if((i == 0)||(i % 4 == 0))
//				{
//					points[j][i].x = modelMid.x - 75;
//				}
//				else if((i == 1)||(i == 5)||(i == 9)||(i == 13))
//				{
//					points[j][i].x = modelMid.x - 25;
//				}
//				else if((i == 2)||(i == 6)||(i == 10)||(i == 14))
//				{
//					points[j][i].x = modelMid.x + 25;
//				}
//				else if((i == 3)||(i == 7)||(i == 11)||(i == 15))
//				{
//					points[j][i].x = modelMid.x + 75;
//				}
//
//			
//				//y axises
//				if((i >= 0)&&(i <= 3))
//				{
//					points[j][i].y = modelMid.y - 75;
//				}
//				else if((i >= 4)&&(i <= 7))
//				{
//					points[j][i].y = modelMid.y - 25;
//				}
//				else if((i >= 8)&&(i <= 11))
//				{
//					points[j][i].y = modelMid.y + 25;
//				}
//				else if((i >= 12)&&(i <= 15))
//				{
//					points[j][i].y = modelMid.y + 75;
//				}
//
//				//z axises
//				if(j==0)
//				{//layer1 (of 4)
//					points[j][i].z = modelMid.z - 75;
//				}
//				else if(j==1)
//				{//layer2 (of 4)
//					points[j][i].z = modelMid.z - 25;
//				}
//				else if(j==2)
//				{//layer3 (of 4)
//					points[j][i].z = modelMid.z + 25;
//				}
//				else if(j==3)
//				{//layer4 (of 4)
//					points[j][i].z = modelMid.z + 75;
//				}
//
//			}
//		}
//
//
//
//		point rotats[4][16];
//
//		for(int j = 0; j < 4; j ++)
//		{
//			for(int i = 0; i < 16; i ++)
//			{
//				rotate(points[j][i], angle.x, 'x', rotats[j][i]);
//				rotate(points[j][i], angle.y, 'y', rotats[j][i]);
//				//rotate(points[j][i], angle.z, 'z', rotats[j][i]);
//
//			}
//		}
//
//
//		point projs[4][16];
//
//		for(int j = 0; j < 4; j ++)
//		{
//			for(int i = 0; i < 16; i ++)
//			{
//				proj3d(rotats[j][i], camera, projs[j][i]);
//			}
//		}
//
//		int w = 640;
//		int h = 480;
//
//		if(draw==0)
//		{
//			for(int j = 0; j < 4; j ++)
//			{
//			
//				//if((j==0)||(j==4))
//			
//					//top left corner
//					line(backBuffer, w/2 + projs[j][0].x, h/2 + projs[j][0].y, w/2 + projs[j][3].x, h/2 + projs[j][3].y, makecol(0, 255, 0));
//					line(backBuffer, w/2 + projs[j][0].x, h/2 + projs[j][0].y, w/2 + projs[j][12].x, h/2 + projs[j][12].y, makecol(0, 255, 0));
//					line(backBuffer, w/2 + projs[j][0].x, h/2 + projs[j][0].y, w/2 + projs[0][0].x, h/2 + projs[0][0].y, makecol(0, 255, 0));
//					//bottom left
//					line(backBuffer, w/2 + projs[j][12].x, h/2 + projs[j][12].y, w/2 + projs[j][15].x, h/2 + projs[j][15].y, makecol(0, 255, 0));
//					line(backBuffer, w/2 + projs[j][12].x, h/2 + projs[j][12].y, w/2 + projs[0][12].x, h/2 + projs[0][12].y, makecol(0, 255, 0));
//			
//					//bottom right
//					line(backBuffer, w/2 + projs[j][15].x, h/2 + projs[j][15].y, w/2 + projs[j][3].x, h/2 + projs[j][3].y, makecol(0, 255, 0));
//					line(backBuffer, w/2 + projs[j][15].x, h/2 + projs[j][15].y, w/2 + projs[0][15].x, h/2 + projs[0][15].y, makecol(0, 255, 0));
//					//top right
//					line(backBuffer, w/2 + projs[j][3].x, h/2 + projs[j][3].y, w/2 + projs[0][3].x, h/2 + projs[0][3].y, makecol(0, 255, 0));
//			
//			
//				//top left (mid) edge
//				line(backBuffer, w/2 + projs[j][1].x, h/2 + projs[j][1].y, w/2 + projs[j][13].x, h/2 + projs[j][13].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projs[j][1].x, h/2 + projs[j][1].y, w/2 + projs[0][1].x, h/2 + projs[0][1].y, makecol(0, 255, 0));
//				//top right (mid) edge
//				line(backBuffer, w/2 + projs[j][2].x, h/2 + projs[j][2].y, w/2 + projs[j][14].x, h/2 + projs[j][14].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projs[j][2].x, h/2 + projs[j][2].y, w/2 + projs[0][2].x, h/2 + projs[0][2].y, makecol(0, 255, 0));
//				//mid right top (mid) edge
//				line(backBuffer, w/2 + projs[j][7].x, h/2 + projs[j][7].y, w/2 + projs[j][4].x, h/2 + projs[j][4].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projs[j][7].x, h/2 + projs[j][7].y, w/2 + projs[0][7].x, h/2 + projs[0][7].y, makecol(0, 255, 0));
//				//mid right bottom (mid) edge
//				line(backBuffer, w/2 + projs[j][11].x, h/2 + projs[j][11].y, w/2 + projs[j][8].x, h/2 + projs[j][8].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projs[j][11].x, h/2 + projs[j][11].y, w/2 + projs[0][11].x, h/2 + projs[0][11].y, makecol(0, 255, 0));
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + projs[j][14].x, h/2 + projs[j][14].y, w/2 + projs[0][14].x, h/2 + projs[0][14].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + projs[j][13].x, h/2 + projs[j][13].y, w/2 + projs[0][13].x, h/2 + projs[0][13].y, makecol(0, 255, 0));
//				//bottom right (mid) edge
//				line(backBuffer, w/2 + projs[j][4].x, h/2 + projs[j][4].y, w/2 + projs[0][4].x, h/2 + projs[0][4].y, makecol(0, 255, 0));
//				//bottom left (mid) edge
//				line(backBuffer, w/2 + projs[j][8].x, h/2 + projs[j][8].y, w/2 + projs[0][8].x, h/2 + projs[0][8].y, makecol(0, 255, 0));
//			
//
//				//mid lines
//				//mid top left
//				line(backBuffer, w/2 + projs[j][5].x, h/2 + projs[j][5].y, w/2 + projs[0][5].x, h/2 + projs[0][5].y, makecol(0, 255, 0));
//				//mid top right
//				line(backBuffer, w/2 + projs[j][6].x, h/2 + projs[j][6].y, w/2 + projs[0][6].x, h/2 + projs[0][6].y, makecol(0, 255, 0));
//				//mid bottom left
//				line(backBuffer, w/2 + projs[j][9].x, h/2 + projs[j][9].y, w/2 + projs[0][9].x, h/2 + projs[0][9].y, makecol(0, 255, 0));
//				//mid bottom right
//				line(backBuffer, w/2 + projs[j][10].x, h/2 + projs[j][10].y, w/2 + projs[0][10].x, h/2 + projs[0][10].y, makecol(0, 255, 0));
//			
//
//			}
//		}
//		else if(draw==1)
//		{
//			point dog[16];
//			/*dog[0] = {0, 50, 100};
//			dog[1] = {0, 40, 100};
//			dog[2] = {0, 50, 75};
//			dog[3] = {0, 40, 75};
//			dog[4] = {0, 0, 50};
//			dog[5] = {-50, -50, 50};
//			dog[6] = {50, -50, 50};
//			dog[7] = {0, 0, -50};
//			dog[8] = {-50, -50, -50};
//			dog[9] = {50, -50, -50};
//			dog[10] = {0, 50, -75};*/
//			dog[0].x = 0;
//			dog[0].y = 50;
//			dog[0].z = 100;
//			dog[1].x = 0;
//			dog[1].y = 40;
//			dog[1].z = 100;
//			dog[2].x = 0;
//			dog[2].y = 50;
//			dog[2].z = 75;
//			dog[3].x = 0;
//			dog[3].y = 40;
//			dog[3].z = 75;
//			dog[4].x = 0;
//			dog[4].y = 0;
//			dog[4].z = 50;
//			dog[5].x = -50;
//			dog[5].y = -50;
//			dog[5].z = 50;
//			dog[6].x = 50;
//			dog[6].y = -50;
//			dog[6].z = 50;
//			dog[7].x = 0;
//			dog[7].y = 0;
//			dog[7].z = -50;
//			dog[8].x = -50;
//			dog[8].y = -50;
//			dog[8].z = -50;
//			dog[9].x = 50;
//			dog[9].y = -50;
//			dog[9].z = -50;
//			dog[10].x = 0;
//			dog[10].y = 50;
//			dog[10].z = -75;
//
//			point rots[16];
//
//			i = 0;
//			while(i<10)
//			{
//				rotate(dog[i], angle.x, 'x', rots[i]);
//				rotate(dog[i], angle.y, 'y', rots[i]);
//				rotate(dog[i], angle.z, 'z', rots[i]);
//				i++;
//			}
//
//			point projs[16];
//
//			i = 0;
//			while(i<10)
//			{
//				proj3d(rots[i], camera, projs[i]);
//				i++;
//			}
//
//			line(backBuffer, w/2 + projs[0].x, h/2 + projs[0].y, w/2 + projs[1].x, h/2 + projs[1].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[1].x, h/2 + projs[1].y, w/2 + projs[3].x, h/2 + projs[3].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[0].x, h/2 + projs[0].y, w/2 + projs[2].x, h/2 + projs[2].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[2].x, h/2 + projs[2].y, w/2 + projs[4].x, h/2 + projs[4].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[5].x, h/2 + projs[5].y, w/2 + projs[4].x, h/2 + projs[4].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[6].x, h/2 + projs[6].y, w/2 + projs[4].x, h/2 + projs[4].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[7].x, h/2 + projs[7].y, w/2 + projs[4].x, h/2 + projs[4].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[7].x, h/2 + projs[7].y, w/2 + projs[10].x, h/2 + projs[10].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[7].x, h/2 + projs[7].y, w/2 + projs[8].x, h/2 + projs[8].y, makecol(0, 255, 0));
//			line(backBuffer, w/2 + projs[7].x, h/2 + projs[7].y, w/2 + projs[9].x, h/2 + projs[9].y, makecol(0, 255, 0));
//
//
//
//		}
//		else if(draw==3)
//		{
//			//simple cross thing
//
//			point cross[16];
//
//			int drow = 0;
//
//			if(drow == 0)
//			{
//
//				cross[0].x = modelMid.x - 25;
//				cross[0].y = modelMid.y + 25;
//				cross[0].z = modelMid.z - 25;
//
//				cross[1].x = modelMid.x - 25;
//				cross[1].y = modelMid.y + 25;
//				cross[1].z = modelMid.z + 25;
//
//				cross[2].x = modelMid.x + 25;
//				cross[2].y = modelMid.y + 25;
//				cross[2].z = modelMid.z - 25;
//
//				cross[3].x = modelMid.x + 25;
//				cross[3].y = modelMid.y + 25;
//				cross[3].z = modelMid.z + 25;
//
//				cross[4].x = modelMid.x - 25;
//				cross[4].y = modelMid.y - 25;
//				cross[4].z = modelMid.z - 25;
//
//				cross[5].x = modelMid.x - 25;
//				cross[5].y = modelMid.y - 25;
//				cross[5].z = modelMid.z + 25;
//
//				cross[6].x = modelMid.x + 25;
//				cross[6].y = modelMid.y - 25;
//				cross[6].z = modelMid.z - 25;
//
//				cross[7].x = modelMid.x + 25;
//				cross[7].y = modelMid.y - 25;
//				cross[7].z = modelMid.z + 25;
//
//			}
//			else if(drow==1)
//			{
//			cross[0].x = modelMid.x + 50;
//			cross[0].y = modelMid.y + 100;
//			cross[0].z = modelMid.z + 50;
//
//			cross[1].x = modelMid.x + 50;
//			cross[1].y = modelMid.y + 100;
//			cross[1].z = modelMid.z + 100;
//
//			cross[2].x = modelMid.x + 100;
//			cross[2].y = modelMid.y + 100;
//			cross[2].z = modelMid.z + 50;
//
//			cross[3].x = modelMid.x + 100;
//			cross[3].y = modelMid.y + 100;
//			cross[3].z = modelMid.z + 100;
//
//			cross[4].x = modelMid.x + 50;
//			cross[4].y = modelMid.y + 50;
//			cross[4].z = modelMid.z + 50;
//
//			cross[5].x = modelMid.x + 50;
//			cross[5].y = modelMid.y + 50;
//			cross[5].z = modelMid.z + 100;
//
//			cross[6].x = modelMid.x + 100;
//			cross[6].y = modelMid.y + 50;
//			cross[6].z = modelMid.z + 50;
//
//			cross[7].x = modelMid.x + 100;
//			cross[7].y = modelMid.y + 50;
//			cross[7].z = modelMid.z + 100;
//			}
//
//
//			point rotors[16];
//
//			i = 0;
//			/*
//			if(lastAx)
//			{
//				if(lastAxis == 'x')
//				{
//					while(i<10)
//					{
//						rotate(cross[i], angle.x, 'x', rotors[i]);
//						i++;
//					}
//				}
//				else if(lastAxis == 'y')
//				{
//					while(i<10)
//					{
//						rotate(cross[i], angle.y, 'y', rotors[i]);
//						i++;
//					}
//				}
//				else if(lastAxis == 'z')
//				{
//					while(i<10)
//					{
//						rotate(cross[i], angle.z, 'z', rotors[i]);
//						i++;
//					}
//				}
//			}
//			else if(!lastAx)
//			{*/
//				while(i<10)
//				{
//					rotate(cross[i], angle.x, 'x', rotors[i]);
//					rotate(cross[i], angle.y, 'y', rotors[i]);
//					rotate(cross[i], angle.z, 'z', rotors[i]);
//					i++;
//				}
//			//}
//
//			point projers[16];
//
//			i = 0;
//			while(i<10)
//			{
//				//proj3d(rotors[i], camera, projers[i]);
//				projNew(rotors[i], camera, projers[i]);
//				i++;
//			}
//
//			int drew;
//
//			drew = 2;
//
//			if(drew==0)
//			{
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[7].x, h/2 + projers[7].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[1].x, h/2 + projers[1].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[2].x, h/2 + projers[2].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[4].x, h/2 + projers[4].y, makecol(0, 255, 0));
//
//			
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[1].x, h/2 + projers[1].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[1].x, h/2 + projers[1].y, w/2 + projers[2].x, h/2 + projers[2].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[2].x, h/2 + projers[2].y, w/2 + projers[3].x, h/2 + projers[3].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[0].x, h/2 + projers[0].y, makecol(0, 255, 0));
//
//			
//				line(backBuffer, w/2 + projers[4].x, h/2 + projers[4].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[5].x, h/2 + projers[5].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[6].x, h/2 + projers[6].y, w/2 + projers[7].x, h/2 + projers[7].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[7].x, h/2 + projers[7].y, w/2 + projers[4].x, h/2 + projers[4].y, makecol(0, 255, 0));
//			
//			
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[4].x, h/2 + projers[4].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[1].x, h/2 + projers[1].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[2].x, h/2 + projers[2].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[7].x, h/2 + projers[7].y, makecol(0, 255, 0));
//			}
//			else if(drew==1)
//			{
//				int p = 0;
//				while(p<8)
//				{
//					circle(backBuffer, w/2 + projers[p].x, h/2 + projers[p].y, 5, makecol(0, 0, 255));
//					p++;
//				}
//			}
//			else if(drew==2)
//			{
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[1].x, h/2 + projers[1].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[4].x, h/2 + projers[4].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[0].x, h/2 + projers[0].y, w/2 + projers[2].x, h/2 + projers[2].y, makecol(0, 255, 0));
//
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[1].x, h/2 + projers[1].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[7].x, h/2 + projers[7].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[3].x, h/2 + projers[3].y, w/2 + projers[2].x, h/2 + projers[2].y, makecol(0, 255, 0));
//
//				line(backBuffer, w/2 + projers[1].x, h/2 + projers[1].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[2].x, h/2 + projers[2].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				
//				line(backBuffer, w/2 + projers[4].x, h/2 + projers[4].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[4].x, h/2 + projers[4].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[7].x, h/2 + projers[7].y, w/2 + projers[5].x, h/2 + projers[5].y, makecol(0, 255, 0));
//				line(backBuffer, w/2 + projers[7].x, h/2 + projers[7].y, w/2 + projers[6].x, h/2 + projers[6].y, makecol(0, 255, 0));
//				
//			}
//			
//
//		}
//
//		i=0;
//		j=0;
//		while(j<4)
//		{
//			while(i<16)
//			{
//				if((mouse_x == projs[j][i].x)&&(mouse_y == projs[j][i].y))
//				{
//					textprintf(backBuffer, font, 20, 240, makecol(150, 150, 150), "layer %d\npoint %d", j, i);
//				}
//				i++;
//			}
//			j++;
//		}
//
//		//cursor
//		circle(backBuffer, mouse_x, mouse_y, 5, makecol(255,255,255));
//		int x = 0;
//		int y = 0;
//		x = archer(0, mouse_x, 5, k);
//		y = archer(1, mouse_y, 5, k);
//		k ++;
//		if(k>=360)
//		{
//			k = 0;
//		}
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
//		if(mouse_b&1)
//		{
//			circle(backBuffer, mouse_x, mouse_y, 5, makecol(r,g,b));
//			putpixel(backBuffer, x, y, makecol(r,g,b));
//			line(backBuffer, mouse_x, mouse_y, x, y, makecol(r,g,b));
//		}
//
//		
//		buttonX = 25;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 3), makecol(150, 150, 150), ">>>");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 1;
//			}
//		}
//
//		buttonX = 50;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 4), (buttonY - 3), makecol(150, 150, 150), ">>");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 0.5;
//			}
//		}
//
//		buttonX = 75;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), ">");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				speed = 0.1;
//			}
//		}
//
//
//		if(key[KEY_Q])
//		{
//			angle.x += speed;
//			while(angle.x >=360)
//			{angle.x -=360;}
//			lastAx = true;
//			lastAxis = 'x';
//		}
//		if(key[KEY_W])
//		{
//			angle.y += speed;
//			while(angle.y >=360)
//			{angle.y -=360;}
//			lastAx = true;
//			lastAxis = 'y';
//		}
//		if(key[KEY_E])
//		{
//			angle.z += speed;
//			while(angle.z >=360)
//			{angle.z -=360;}
//			lastAx = true;
//			lastAxis = 'z';
//		}
//
//		if(key[KEY_A])
//		{
//			angle.x -= speed;
//			while(angle.x < 0)
//			{angle.x +=360;}
//			lastAx = true;
//			lastAxis = 'x';
//		}
//		if(key[KEY_S])
//		{
//			angle.y -= speed;
//			while(angle.y < 0)
//			{angle.y +=360;}
//			lastAx = true;
//			lastAxis = 'y';
//		}
//		if(key[KEY_D])
//		{
//			angle.z -= speed;
//			while(angle.z < 0)
//			{angle.z +=360;}
//			lastAx = true;
//			lastAxis = 'z';
//		}
//
//
//
//		//camera point fuckings
//		textprintf(backBuffer, font, 600, 20, makecol(150, 150, 150), "%0.1f", camera.x);
//		textprintf(backBuffer, font, 600, 40, makecol(150, 150, 150), "%0.1f", camera.y);
//		textprintf(backBuffer, font, 600, 60, makecol(150, 150, 150), "%0.1f", camera.z);
//
//		buttonX = 575;
//		buttonY = 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.x += speed;
//			}
//		}
//		buttonX = 575;
//		buttonY = 40;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.y += speed;
//			}
//		}
//		buttonX = 575;
//		buttonY = 60;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.z += speed;
//			}
//		}
//		buttonX = 550;
//		buttonY = 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.x -= speed;
//			}
//		}
//		buttonX = 550;
//		buttonY = 40;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.y -= speed;
//			}
//		}
//		buttonX = 550;
//		buttonY = 60;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				camera.z -= speed;
//			}
//		}
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 15), makecol(150, 150, 150), "camera point");
//
//
//
//		//model mid point fuckings
//		textprintf(backBuffer, font, 500, 20, makecol(150, 150, 150), "%0.1f", modelMid.x);
//		textprintf(backBuffer, font, 500, 40, makecol(150, 150, 150), "%0.1f", modelMid.y);
//		textprintf(backBuffer, font, 500, 60, makecol(150, 150, 150), "%0.1f", modelMid.z);
//
//		buttonX = 475;
//		buttonY = 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.x += speed;
//			}
//		}
//		buttonX = 475;
//		buttonY = 40;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.y += speed;
//			}
//		}
//		buttonX = 475;
//		buttonY = 60;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.z += speed;
//			}
//		}
//		buttonX = 450;
//		buttonY = 20;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.x -= speed;
//			}
//		}
//		buttonX = 450;
//		buttonY = 40;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.y -= speed;
//			}
//		}
//		buttonX = 450;
//		buttonY = 60;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				modelMid.z -= speed;
//			}
//		}
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY + 15), makecol(150, 150, 150), "model mid");
//
//
//
//
//
//
//		//angling
//		textprintf(backBuffer, font, 600, 420, makecol(150, 150, 150), "%0.1f", angle.x);
//		textprintf(backBuffer, font, 600, 440, makecol(150, 150, 150), "%0.1f", angle.y);
//		textprintf(backBuffer, font, 600, 460, makecol(150, 150, 150), "%0.1f", angle.z);
//
//		buttonX = 575;
//		buttonY = 420;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.x += speed;
//				lastAx = true;
//				lastAxis = 'x';
//				while(angle.x > 360)
//				{angle.x -=360;}
//			}
//		}
//		buttonX = 575;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.y += speed;
//				lastAx = true;
//				lastAxis = 'y';
//				while(angle.y > 360)
//				{angle.y -=360;}
//			}
//		}
//		buttonX = 575;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z+");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.z += speed;
//				lastAx = true;
//				lastAxis = 'z';
//				while(angle.z > 360)
//				{angle.z -=360;}
//			}
//		}
//		buttonX = 550;
//		buttonY = 420;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "x-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.x -= speed;
//				lastAx = true;
//				lastAxis = 'x';
//				while(angle.x < 0)
//				{angle.x +=360;}
//			}
//		}
//		buttonX = 550;
//		buttonY = 440;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "y-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.y -= speed;
//				lastAx = true;
//				lastAxis = 'y';
//				while(angle.y < 0)
//				{angle.y +=360;}
//			}
//		}
//		buttonX = 550;
//		buttonY = 460;
//		buttonRadius = 10;
//		circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//		textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//			if(mouse_b&1){
//				angle.z -= speed;
//				lastAx = true;
//				lastAxis = 'z';
//				while(angle.z < 0)
//				{angle.z +=360;}
//			}
//		}
//		textprintf(backBuffer, font, (buttonX - buttonRadius), (buttonY - 60), makecol(150, 150, 150), "angle");
//
//
//		//control panel
//		//  out to 500 (480)
//		buttonX = w;
//		buttonY = h / 2;
//		buttonRadius = 25;
//		int panel = 425;
//		circle(backBuffer, w, h / 2, 25, makecol(150, 150, 150));
//		textprintf(backBuffer, font, w - 10, (h / 2) - 2, makecol(150, 150, 150), "<");
//		if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//			&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				poonel = true;
//		}
//
//		if(poonel)
//		{
//
//			line(backBuffer, panel, 0, panel, 480, makecol(150,150,150));
//			/*
//			buttonX = 450;
//			buttonY = 80;
//			buttonRadius = 10;
//			circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//			textprintf(backBuffer, font, (buttonX - buttonRadius + 8), (buttonY - 3), makecol(150, 150, 150), "z-");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//
//
//				}
//			}
//			*/
//
//			buttonX = 475;
//			buttonY = 95;
//			buttonRadius = 10;
//			circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//			textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "clr");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//
//					modelMid.x = 0;
//					modelMid.y = 0;
//					modelMid.z = 0;
//
//				}
//			}
//
//
//			buttonX = 575;
//			buttonY = 95;
//			buttonRadius = 10;
//			circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//			textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "clr");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//
//					camera.x = 0;
//					camera.y = 0;
//					camera.z = 0;
//
//				}
//			}
//
//			buttonX = 575;
//			buttonY = 385;
//			buttonRadius = 10;
//			circle(backBuffer, buttonX, buttonY, buttonRadius, makecol(100, 100, 100));
//			textprintf(backBuffer, font, (buttonX - buttonRadius + 5), (buttonY - 3), makecol(150, 150, 150), "clr");
//			if( ((mouse_x>(buttonX-buttonRadius))&&(mouse_x<(buttonX+buttonRadius)))
//				&& ((mouse_y>(buttonY-buttonRadius))&&(mouse_y<(buttonY+buttonRadius))) ){
//				if(mouse_b&1){
//
//					angle.x = 0;
//					angle.y = 0;
//					angle.z = 0;
//
//				}
//			}
//
//
//
//
//
//
//		}
//
//
//		if(mouse_x < panel)
//		{
//			poonel = false;
//		}
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