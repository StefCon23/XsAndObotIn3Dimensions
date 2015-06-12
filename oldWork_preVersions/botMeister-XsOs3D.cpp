#include<stdio.h>
#include<allegro.h>
#include<stdlib.h>
#include<math.h>

BITMAP * backBuffer;


//////~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



//////~~~~~~~~~~~~~~~~~~~~/FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



void main()
{
	if(allegro_init() != 0)
	{
		return;
	}
	set_color_depth(desktop_color_depth());
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0)
	{
		return;
	}
	backBuffer = create_bitmap(640, 480);

//////~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



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
		Colour 6 Shooter
		solid rand colours
		reproduces [respectively]:
		red
		green
		blue
		yellow/orange
		purple
		turkoise?
		*/
		//colours
		int col, r, g, b;
		col = rand()%6;
		if(col==0){
			r=rand()%256;
			g=0;
			b=0;}
		if(col==1){
			r=0;
			g=rand()%256;
			b=0;}
		if(col==2){
			r=0;
			g=0;
			b=rand()%256;}
		if(col==3){
			r=rand()%256;
			g=rand()%256;
			b=0;}
		if(col==4){
			r=rand()%256;
			g=0;
			b=rand()%256;}
		if(col==5){
			r=0;
			g=rand()%256;
			b=rand()%256;}


//////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


		blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
	}
}
END_OF_MAIN()