all:
	gcc -o XsAndObotIn3Dimensions XsAndObotIn3Dimensions.c `allegro-config --libs` -lm
