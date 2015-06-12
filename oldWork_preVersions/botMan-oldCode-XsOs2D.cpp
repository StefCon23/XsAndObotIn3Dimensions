#include<stdio.h>
#include<allegro.h>
#include<stdlib.h>
#include<math.h>

BITMAP * backBuffer;


//////~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void drawX(int x, int y, int radius, int r, int g ,int b){
	/*
	draws an 'x' 
	in position (x, y)
	at size 'radius'
	in colour specified by (r, g, b)
	*/

	//(1, 1) -> (2, 3)
	line(backBuffer, ((x - radius) + ((2*radius)/5)), ((y - radius) + ((2*radius)/5)), ((x - radius) + ((2*(2*radius))/5)), y, makecol(r, g, b));
	//(1, 4) -> (2, 3)
	line(backBuffer, ((x - radius) + ((2*radius)/5)), ((y + radius) - ((2*radius)/5)), ((x - radius) + ((2*(2*radius))/5)), y, makecol(r, g, b));

	//(4, 1) -> (3, 3)
	line(backBuffer, ((x + radius) - ((2*radius)/5)), ((y - radius) + ((2*radius)/5)), ((x + radius) - ((2*(2*radius))/5)), y, makecol(r, g, b));
	//(4, 4) -> (3, 3)
	line(backBuffer, ((x + radius) - ((2*radius)/5)), ((y + radius) - ((2*radius)/5)), ((x + radius) - ((2*(2*radius))/5)), y, makecol(r, g, b));


	//(2, 1) -> (2, 2)
	line(backBuffer, ((x - radius) + ((2*(2*radius))/5)), ((y - radius) + ((2*radius)/5)), x, ((y - radius) + ((2*(2*radius))/5)), makecol(r, g, b));
	//(3, 1) -> (2, 2)
	line(backBuffer, ((x + radius) - ((2*(2*radius))/5)), ((y - radius) + ((2*radius)/5)), x, ((y - radius) + ((2*(2*radius))/5)), makecol(r, g, b));

	//(2, 4) -> (2, (3?))
	line(backBuffer, ((x - radius) + ((2*(2*radius))/5)), ((y + radius) - ((2*radius)/5)), x, ((y + radius) - ((2*(2*radius))/5)), makecol(r, g, b));
	//(3, 4) -> (2, (3?))
	line(backBuffer, ((x + radius) - ((2*(2*radius))/5)), ((y + radius) - ((2*radius)/5)), x, ((y + radius) - ((2*(2*radius))/5)), makecol(r, g, b));


	//(1, 1) -> (2, 1)
	line(backBuffer, ((x - radius) + ((2*radius)/5)), ((y - radius) + ((2*radius)/5)), ((x - radius) + ((2*(2*radius))/5)), ((y - radius) + ((2*radius)/5)), makecol(r, g, b));
	//(1, 4) -> (2, 4)
	line(backBuffer, ((x - radius) + ((2*radius)/5)), ((y + radius) - ((2*radius)/5)), ((x - radius) + ((2*(2*radius))/5)), ((y + radius) - ((2*radius)/5)), makecol(r, g, b));
	//(4, 1) -> (3, 1)
	line(backBuffer, ((x + radius) - ((2*radius)/5)), ((y - radius) + ((2*radius)/5)), ((x + radius) - ((2*(2*radius))/5)), ((y - radius) + ((2*radius)/5)), makecol(r, g, b));
	//(4, 4) -> (3, 4)
	line(backBuffer, ((x + radius) - ((2*radius)/5)), ((y + radius) - ((2*radius)/5)), ((x + radius) - ((2*(2*radius))/5)), ((y + radius) - ((2*radius)/5)), makecol(r, g, b));


}

void drawO(int x, int y, int radius, int r, int g ,int b){
	/*
	draws an 'o' 
	in position (x, y)
	at size 'radius'
	in colour specified by (r, g, b)
	*/

	//inner
	circle(backBuffer, x, y, (radius - ((2*radius)/5)), makecol(r, g, b));
	//outer
	circle(backBuffer, x, y, (radius - ((2*(2*radius))/5)), makecol(r, g, b));
}

void drawSelection(int x, int y, int radius, int r, int g ,int b){
	/*
	draws concentric circles
	around x, y
	size radius
	r, g, b working on all or nothing system,
	if != 0, active
	*/

	int jimmies = 0;
	while(jimmies < radius){
		//colours
		if(r > 0){
			r = rand()%256;
		}
		if(g > 0){
			g = rand()%256;
		}
		if(b > 0){
			b = rand()%256;
		}
		//circle
		circle(backBuffer, x, y, jimmies, makecol(r, g, b));
		//growing radius
		jimmies ++;
	}
}

void robtMove(int squares[]){
	/*
	defend
	attack
	acquire valuable property
	*/

	int i = 0;
	int j = 0;
	int rounds = 0;
	int check;

	
	
	
	//DEfence or attack, who knows
	for(i = 0; i < 9; i ++){
		//check each square
		if(rounds==0){
			//one move per turn
			if(squares[i] == 2){
				//if square is o
				if(i == 0){
					//if top left is o
					if(squares[1] == squares[i]){
						//if top mid is also o
						if(squares[2] == 0){
							//make top right o
							squares[2] = 2;
							rounds ++;
						}
					}else if(squares[2] == squares[i]){
						//if top right is also x
						if(squares[1] == 0){
							//make top mid o
							squares[1] = 2;
							rounds ++;
						}
					}else if(squares[3] == squares[i]){
						//if mid left is also x
						if(squares[6] == 0){
							//make bottom left o
							squares[6] = 2;
							rounds ++;
						}
					}else if(squares[6] == squares[i]){
						//if bottom left is also x
						if(squares[3] == 0){
							//make mid left o
							squares[3] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[8] == 0){
							//make bottom right o
							squares[8] = 2;
							rounds ++;
						}
					}else if(squares[8] == squares[i]){
						//if bottom right is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 1){
					//if top mid is x
					if(squares[0] == squares[i]){
						//if top left is also x
						if(squares[2] == 0){
							//make top right o
							squares[2] = 2;
							rounds ++;
						}
					}else if(squares[2] == squares[i]){
						//if top right is also x
						if(squares[0] == 0){
							//make top left o
							squares[0] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[7] == 0){
							//make bottom mid o
							squares[7] = 2;
							rounds ++;
						}
					}else if(squares[7] == squares[i]){
						//if bottom mid is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 2){
					//if top right is x
					if(squares[1] == squares[i]){
						//if top mid is also x
						if(squares[0] == 0){
							//make top left o
							squares[0] = 2;
							rounds ++;
						}
					}else if(squares[0] == squares[i]){
						//if top left is also x
						if(squares[1] == 0){
							//make top mid o
							squares[1] = 2;
							rounds ++;
						}
					}else if(squares[5] == squares[i]){
						//if mid right is also x
						if(squares[8] == 0){
							//make bottom right o
							squares[8] = 2;
							rounds ++;
						}
					}else if(squares[8] == squares[i]){
						//if bottom right is also x
						if(squares[5] == 0){
							//make mid right o
							squares[5] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[6] == 0){
							//make bottom left o
							squares[6] = 2;
							rounds ++;
						}
					}else if(squares[6] == squares[i]){
						//if bottom left is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 3){
					//if mid left is x
					if(squares[6] == squares[i]){
						//if bottom left is also x
						if(squares[0] == 0){
							//make top left o
							squares[0] = 2;
							rounds ++;
						}
					}else if(squares[0] == squares[i]){
						//if top left is also x
						if(squares[6] == 0){
							//make bottom left o
							squares[6] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[5] == 0){
							//make mid right o
							squares[5] = 2;
							rounds ++;
						}
					}else if(squares[5] == squares[i]){
						//if mid right is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 4){
					//if mid mid is x
					for(j = 0; j < 9; j ++){
						//check others for x
						if(j != 4){
							//not current square
							if(squares[j] == squares[i]){
								//if equal
								if(squares[8-i] == 0){
									//and opposing square is free
									squares[8-i] = 2;
									//make it o
									rounds ++;
								}
							}
						}
					}
				}else if(i == 5){
					//if mid right is x
					if(squares[8] == squares[i]){
						//if bottom right is also x
						if(squares[2] == 0){
							//make top right o
							squares[2] = 2;
							rounds ++;
						}
					}else if(squares[2] == squares[i]){
						//if top right is also x
						if(squares[8] == 0){
							//make bottom right o
							squares[8] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[3] == 0){
							//make mid left o
							squares[3] = 2;
							rounds ++;
						}
					}else if(squares[3] == squares[i]){
						//if mid left is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 6){
					if(squares[7] == squares[i]){
						//if bottom mid is also x
						if(squares[8] == 0){
							//make bottom right o
							squares[8] = 2;
							rounds ++;
						}
					}else if(squares[8] == squares[i]){
						//if bottom right is also x
						if(squares[7] == 0){
							//make bottom mid o
							squares[7] = 2;
							rounds ++;
						}
					}else if(squares[3] == squares[i]){
						//if mid left is also x
						if(squares[0] == 0){
							//make top left o
							squares[0] = 2;
							rounds ++;
						}
					}else if(squares[0] == squares[i]){
						//if top left is also x
						if(squares[3] == 0){
							//make mid left o
							squares[3] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[2] == 0){
							//make top right o
							squares[2] = 2;
							rounds ++;
						}
					}else if(squares[2] == squares[i]){
						//if top right is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 7){
					//if bottom mid is x
					if(squares[6] == squares[i]){
						//if bottom left is also x
						if(squares[8] == 0){
							//make bottom right o
							squares[8] = 2;
							rounds ++;
						}
					}else if(squares[8] == squares[i]){
						//if bottom right is also x
						if(squares[6] == 0){
							//make bottom left o
							squares[6] = 2;
							rounds ++;
						}
					}else if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[1] == 0){
							//make top mid o
							squares[1] = 2;
							rounds ++;
						}
					}else if(squares[1] == squares[i]){
						//if top mid is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}else if(i == 8){
					//if bottom right is x
					if(squares[7] == squares[i]){
						//if bottom mid is also x
						if(squares[6] == 0){
							//make bottom left o
							squares[6] = 2;
							rounds ++;
						}
					}else if(squares[6] == squares[i]){
						//if bottom left is also x
						if(squares[7] == 0){
							//make bottom mid o
							squares[7] = 2;
							rounds ++;
						}
					}else if(squares[5] == squares[i]){
						//if mid right is also x
						if(squares[2] == 0){
							//make top right o
							squares[2] = 2;
							rounds ++;
						}
					}else if(squares[2] == squares[i]){
						//if top right is also x
						if(squares[5] == 0){
							//make mid right o
							squares[5] = 2;
							rounds ++;
						}
					}
					if(squares[4] == squares[i]){
						//if mid mid is also x
						if(squares[0] == 0){
							//make top left o
							squares[0] = 2;
							rounds ++;
						}
					}else if(squares[0] == squares[i]){
						//if top left is also x
						if(squares[4] == 0){
							//make mid mid o
							squares[4] = 2;
							rounds ++;
						}
					}
				}
			}
		}
	}
	//defence, unsure at this point
	if(rounds<1){
 		for(i = 0; i < 9; i ++){
			//check each square
			if(rounds==0){
				//one move per turn
				if(squares[i] == 1){
					//if square is x (if it's 1, otherwise it's o)
					if(i == 0){
						//if top left is x
						if(squares[1] == squares[i]){
							//if top mid is also x
							if(squares[2] == 0){
								//make top right o
								squares[2] = 2;
								rounds ++;
							}
						}else if(squares[2] == squares[i]){
							//if top right is also x
							if(squares[1] == 0){
								//make top mid o
								squares[1] = 2;
								rounds ++;
							}
						}else if(squares[3] == squares[i]){
							//if mid left is also x
							if(squares[6] == 0){
								//make bottom left o
								squares[6] = 2;
								rounds ++;
							}
						}else if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[3] == 0){
								//make mid left o
								squares[3] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[8] == 0){
								//make bottom right o
								squares[8] = 2;
								rounds ++;
							}
						}else if(squares[8] == squares[i]){
							//if bottom right is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}else if(squares[4] == 2){
								//double corner mindfuck
								check = 0;
								for(j = 0; j < 9; j ++){
									if((squares[j] == 1) || (squares[j] == 2)){
										check ++;
									}
								}
								if(check==3){
								bool edges = true;
									while(edges){
										check = 0;
										j = rand()%4;
										j *= 2;
										j += 1;
										if(squares[j] == 0){
											squares[j] = 2;
											rounds ++;
											edges = false;
										}else{
											check ++;
										}
										if(check > 3){
											edges = false;
										}
									}
								}
							}
						}
					}else if(i == 1){
						//if top mid is x
						if(squares[0] == squares[i]){
							//if top left is also x
							if(squares[2] == 0){
								//make top right o
								squares[2] = 2;
								rounds ++;
							}
						}else if(squares[2] == squares[i]){
							//if top right is also x
							if(squares[0] == 0){
								//make top left o
								squares[0] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[7] == 0){
								//make bottom mid o
								squares[7] = 2;
								rounds ++;
							}
						}else if(squares[7] == squares[i]){
							//if bottom mid is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 2){
						//if top right is x
						if(squares[1] == squares[i]){
							//if top mid is also x
							if(squares[0] == 0){
								//make top left o
								squares[0] = 2;
								rounds ++;
							}
						}else if(squares[0] == squares[i]){
							//if top left is also x
							if(squares[1] == 0){
								//make top mid o
								squares[1] = 2;
								rounds ++;
							}
						}else if(squares[5] == squares[i]){
							//if mid right is also x
							if(squares[8] == 0){
								//make bottom right o
								squares[8] = 2;
								rounds ++;
							}
						}else if(squares[8] == squares[i]){
							//if bottom right is also x
							if(squares[5] == 0){
								//make mid right o
								squares[5] = 2;
								rounds ++;
							}
						}else if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}else if(squares[4] == 2){
								//double corner mindfuck /////squares 2, 4 and 6
								check = 0;
								for(j = 0; j < 9; j ++){
									if((squares[j] == 1) || (squares[j] == 2)){
										check ++;
									}
								}
								if(check==3){
								bool edges = true;
									while(edges){
										check = 0;
										j = rand()%4;
										j *= 2;
										j += 1;
										if(squares[j] == 0){
											squares[j] = 2;
											rounds ++;
											edges = false;
										}else{
											check ++;
										}
										if(check > 3){
											edges = false;
										}
									}
								}
							}
						}else if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 3){
						//if mid left is x
						if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[0] == 0){
								//make top left o
								squares[0] = 2;
								rounds ++;
							}
						}else if(squares[0] == squares[i]){
							//if top left is also x
							if(squares[6] == 0){
								//make bottom left o
								squares[6] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[5] == 0){
								//make mid right o
								squares[5] = 2;
								rounds ++;
							}
						}else if(squares[5] == squares[i]){
							//if mid right is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 4){
						//if mid mid is x
						for(j = 0; j < 9; j ++){
							//check others for x
							if(j != 4){
								//not current square
								if(squares[j] == squares[i]){
									//if equal
									if(squares[8-j] == 0){
										//and opposing square is free
										squares[8-j] = 2;
										//make it o
										rounds ++;
									}
								}
							}
						}
					}else if(i == 5){
						//if mid right is x
						if(squares[8] == squares[i]){
							//if bottom right is also x
							if(squares[2] == 0){
								//make top right o
								squares[2] = 2;
								rounds ++;
							}
						}else if(squares[2] == squares[i]){
							//if top right is also x
							if(squares[8] == 0){
								//make bottom right o
								squares[8] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[3] == 0){
								//make mid left o
								squares[3] = 2;
								rounds ++;
							}
						}else if(squares[3] == squares[i]){
							//if mid left is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 6){
						if(squares[7] == squares[i]){
							//if bottom mid is also x
							if(squares[8] == 0){
								//make bottom right o
								squares[8] = 2;
								rounds ++;
							}
						}else if(squares[8] == squares[i]){
							//if bottom right is also x
							if(squares[7] == 0){
								//make bottom mid o
								squares[7] = 2;
								rounds ++;
							}
						}else if(squares[3] == squares[i]){
							//if mid left is also x
							if(squares[0] == 0){
								//make top left o
								squares[0] = 2;
								rounds ++;
							}
						}else if(squares[0] == squares[i]){
							//if top left is also x
							if(squares[3] == 0){
								//make mid left o
								squares[3] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[2] == 0){
								//make top right o
								squares[2] = 2;
								rounds ++;
							}
						}else if(squares[2] == squares[i]){
							//if top right is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 7){
						//if bottom mid is x
						if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[8] == 0){
								//make bottom right o
								squares[8] = 2;
								rounds ++;
							}
						}else if(squares[8] == squares[i]){
							//if bottom right is also x
							if(squares[6] == 0){
								//make bottom left o
								squares[6] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[1] == 0){
								//make top mid o
								squares[1] = 2;
								rounds ++;
							}
						}else if(squares[1] == squares[i]){
							//if top mid is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}else if(i == 8){
						//if bottom right is x
						if(squares[7] == squares[i]){
							//if bottom mid is also x
							if(squares[6] == 0){
								//make bottom left o
								squares[6] = 2;
								rounds ++;
							}
						}else if(squares[6] == squares[i]){
							//if bottom left is also x
							if(squares[7] == 0){
								//make bottom mid o
								squares[7] = 2;
								rounds ++;
							}
						}else if(squares[5] == squares[i]){
							//if mid right is also x
							if(squares[2] == 0){
								//make top right o
								squares[2] = 2;
								rounds ++;
							}
						}else if(squares[2] == squares[i]){
							//if top right is also x
							if(squares[5] == 0){
								//make mid right o
								squares[5] = 2;
								rounds ++;
							}
						}else if(squares[4] == squares[i]){
							//if mid mid is also x
							if(squares[0] == 0){
								//make top left o
								squares[0] = 2;
								rounds ++;
							}
						}else if(squares[0] == squares[i]){
							//if top left is also x
							if(squares[4] == 0){
								//make mid mid o
								squares[4] = 2;
								rounds ++;
							}
						}
					}
				}
			}
		}
		}
//Acquiring profitable property
//most likely only for use in first few rounds
//if not only 1st
if(rounds<1){
	//mid mid, top priority
	if(squares[4] == 0){
		//free
		squares[4] = 2;
		//take
		rounds ++;
	}else{
		//corners & edges
		int check = 0;
		bool corners = true;
		bool edges = false;
		while(corners){
			j = rand()%5;
			//random number
			j *= 2;
			//set to corner co-ordinates
			if(squares[j] == 0){
				//if free
				squares[j] = 2;
				//take
				rounds ++;
				//log it
				corners = false;
				//end corner search
			}else{
				check ++;
				//check for taken corners
			}
			if(check > 3){
				//all corners taken
				corners = false;
				//corners off
				edges = true;
				//edges on
			}
		}
		while(edges){
			check = 0;
			//reset check
			j = rand()%4;
			//random number
			j *= 2;
			//set to corner co-ordinates
			j += 1;
			//set to edge co-ordinates
			if(squares[j] == 0){
				//if free
				squares[j] = 2;
				//take
				rounds ++;
				//log it
				edges = false;
				//end edge search
			}else{
				check ++;
				//check for taken corners
			}
			if(check > 3){
				//all edges taken
				edges = false;
				//edges off
			}
		}
	}
	}
}//endFunct

void humnMove(int squares[]){
	/*
	ui
	*/

	int check = 0;
	bool thinking = true;

	int i = 0;
	int j = 0;

	int w = 640;
	int h = 480;

	int x;
	int y;

	int radius = 50;

	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;

	int selection = 9;
	int selectionX;
	int selectionY;
	
	while(thinking){

		clear_to_color(backBuffer, makecol(255, 255, 255));

		r = 0;
		g = 0;
		b = 0;

		//cursor
		line(backBuffer, mouse_x, mouse_y, (mouse_x + 5), (mouse_y + 10), makecol(b, g, r));
		line(backBuffer, mouse_x, mouse_y, (mouse_x + 10), (mouse_y + 5), makecol(b, g, r));
		line(backBuffer, (mouse_x + 5), (mouse_y + 10), (mouse_x + 26), (mouse_y + 30), makecol(b, g, r));
		line(backBuffer, (mouse_x + 10), (mouse_y + 5), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));
		line(backBuffer, (mouse_x + 26), (mouse_y + 30), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));

		//grid
		//   #
		//
		//   |
		line(backBuffer, ((w/2) - 25), ((h/2) - 75), ((w/2) - 25), ((h/2) + 75), makecol(r, g, b));
		//   | |
		line(backBuffer, ((w/2) + 25), ((h/2) - 75), ((w/2) + 25), ((h/2) + 75), makecol(r, g, b));
		//   ---
		line(backBuffer, ((w/2) - 75), ((h/2) - 25), ((w/2) + 75), ((h/2) - 25), makecol(r, g, b));
		//   ===
		line(backBuffer, ((w/2) - 75), ((h/2) + 25), ((w/2) + 75), ((h/2) + 25), makecol(r, g, b));

		//drawLoop
		for(i = 0; i < 9; i ++){
			//checks each box
			//and draws in

			//positions
			if(i==0){
				x = w/2 - 50;
				y = h/2 - 50;
			}else if(i==1){
				x = w/2;
				y = h/2 - 50;
			}else if(i==2){
				x = w/2 + 50;
				y = h/2 - 50;
			}else if(i==3){
				x = w/2 - 50;
				y = h/2;
			}else if(i==4){
				x = w/2;
				y = h/2;
			}else if(i==5){
				x = w/2 + 50;
				y = h/2;
			}else if(i==6){
				x = w/2 - 50;
				y = h/2 + 50;
			}else if(i==7){
				x = w/2;
				y = h/2 + 50;
			}else if(i==8){
				x = w/2 + 50;
				y = h/2 + 50;
			}else{
				x = w + 50;
				y = h + 50;
			}
			if(squares[i] == 1){
				// x
				r = rand()%256;
				g = rand()%256;
				b = rand()%256;
				drawX(x, y, radius, r, 0 ,b);
			}else if(squares[i] == 2){
				// o
				r = rand()%256;
				g = rand()%256;
				b = rand()%256;
				drawO(x, y, radius, 0, g, b);
			}else{
				//do nothing
			}
		}
	

	//selection
	if(check<1){
		if((mouse_x > ((w/2) - 75)) && (mouse_x < ((w/2) + 75))){
			if((mouse_y > ((h/2) - 75)) && (mouse_y < ((h/2) + 75))){

				//clicked
				if(mouse_b&1){
					bool picked = false;
					if(mouse_x < ((w/2) - 25)){
						//boxes[]: 0, 3 or 6
						if(mouse_y < ((h/2) - 25)){
							//boxes[0]
							selection = 0;
							selectionX = w/2 - 50;
							selectionY = h/2 - 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else if(mouse_y > ((h/2) + 25)){
							//boxes[6]
							selection = 6;
							selectionX = w/2 - 50;
							selectionY = h/2 + 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else{
							//boxes[3]
							selection = 3;
							selectionX = w/2 - 50;
							selectionY = h/2;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}
					}else if(mouse_x > ((w/2) + 25)){
						//boxes[]: 2, 5 or 8
						if(mouse_y < ((h/2) - 25)){
							//boxes[2]
							selection = 2;
							selectionX = w/2 + 50;
							selectionY = h/2 - 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else if(mouse_y > ((h/2) + 25)){
							//boxes[8]
							selection = 8;
							selectionX = w/2 + 50;
							selectionY = h/2 + 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else{
							//boxes[5]
							selection = 5;
							selectionX = w/2 + 50;
							selectionY = h/2;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}
					}else{
						//boxes[]: 1, 4 or 7
						if(mouse_y < ((h/2) - 25)){
							//boxes[1]
							selection = 1;
							selectionX = w/2;
							selectionY = h/2 - 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else if(mouse_y > ((h/2) + 25)){
							//boxes[7]
							selection = 7;
							selectionX = w/2;
							selectionY = h/2 + 50;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}else{
							//boxes[4]
							selection = 4;
							selectionX = w/2;
							selectionY = h/2;
							//squares[selection] = 1;
							//check ++;
							picked = true;
						}
					}
					r = rand()%2;
					g = rand()%2;
					b = rand()%2;
					drawSelection(selectionX, selectionY, radius, 1, 0, 0);

					if(key[KEY_X]){
						bool tool;
					}else if(key[KEY_Y]){
						bool stool;
					}


				}
			}
		}

	}
	//moving
	if(selection != 9){
		bool picked = false;
		if(key[KEY_X]){
			//drawX(selectionX, selectionY, radius, r, g, b);
			squares[selection] = 1;
			picked = true;
		}else if(key[KEY_O]){
			//drawO(selectionX, selectionY, radius, r, g, b);
			squares[selection] = 2;
			picked = true;
		}
		if(picked){
			thinking = false;
		}
	}
	/*
	if(check > 0){
		//break away
		thinking = false;
	}
	*/

	//BUTTTTTONNNS

	//exito
	textprintf(backBuffer, font, w/2 + w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "exit");
	circle(backBuffer, w/2 + w/4, h/2 + h/3, 30, makecol(0, 0, 0));
	if((mouse_x > (w/2 + w/4 - 15)) && (mouse_x < (w/2 + w/4 + 15))){
		if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
			if(mouse_b&1){
				thinking = false;
				break;
			}
		}
	}

	//escing
	if(key[KEY_ESC]){
		break;
	}
	blit(backBuffer, screen, 0, 0, 0, 0, w, h);
	}
}

void push(int squares[]){

	int x;
	int y;
	int w = 640;
	int h = 480;
	int r;
	int g;
	int b;
	int radius = 50;

	int i = 0;
	int j = 0;
	float k = 0;
	int ticker = 0;
	int winningface[9];


	for(j = 0; j < 9; j ++){
		winningface[j] = squares[j];
	}


	bool run = true;
	while(run){

		for(k = 0; k < 8; k += 0.01){

			clear_to_color(backBuffer, makecol(255, 255, 255));

			r = 0;
			g = 0;
			b = 0;

			//cursor
			line(backBuffer, mouse_x, mouse_y, (mouse_x + 5), (mouse_y + 10), makecol(b, g, r));
			line(backBuffer, mouse_x, mouse_y, (mouse_x + 10), (mouse_y + 5), makecol(b, g, r));
			line(backBuffer, (mouse_x + 5), (mouse_y + 10), (mouse_x + 26), (mouse_y + 30), makecol(b, g, r));
			line(backBuffer, (mouse_x + 10), (mouse_y + 5), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));
			line(backBuffer, (mouse_x + 26), (mouse_y + 30), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));

			//grid
			//   #
			//
			//   |
			line(backBuffer, ((w/2) - 25), ((h/2) - 75), ((w/2) - 25), ((h/2) + 75), makecol(r, g, b));
			//   | |
			line(backBuffer, ((w/2) + 25), ((h/2) - 75), ((w/2) + 25), ((h/2) + 75), makecol(r, g, b));
			//   ---
			line(backBuffer, ((w/2) - 75), ((h/2) - 25), ((w/2) + 75), ((h/2) - 25), makecol(r, g, b));
			//   ===
			line(backBuffer, ((w/2) - 75), ((h/2) + 25), ((w/2) + 75), ((h/2) + 25), makecol(r, g, b));

			//drawLoop
			for(j = 0; j < 9; j ++){
				//checks each box
				//and draws in

				//positions
				if(j==0){
					x = w/2 - 50;
					y = h/2 - 50;
				}else if(j==1){
					x = w/2;
					y = h/2 - 50;
				}else if(j==2){
					x = w/2 + 50;
					y = h/2 - 50;
				}else if(j==3){
					x = w/2 - 50;
					y = h/2;
				}else if(j==4){
					x = w/2;
					y = h/2;
				}else if(j==5){
					x = w/2 + 50;
					y = h/2;
				}else if(j==6){
					x = w/2 - 50;
					y = h/2 + 50;
				}else if(j==7){
					x = w/2;
					y = h/2 + 50;
				}else if(j==8){
					x = w/2 + 50;
					y = h/2 + 50;
				}else{
					x = w + 50;
					y = h + 50;
				}
				if(squares[j] == 1){
					// x
					/*
					r = rand()%256;
					g = rand()%256;
					b = rand()%256;
					*/
					r = 0;
					g = 0;
					b = 255;

					drawX(x, y, radius, r, g ,b);
				}else if(squares[j] == 2){
					// o
					/*
					r = rand()%256;
					g = rand()%256;
					b = rand()%256;
					*/
					r = 255;
					g = 0;
					b = 0;

					drawO(x, y, radius, r, g, b);
				}else{
					//do nothing
				}
			}

			//regame
			textprintf(backBuffer, font, w/2 - w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "re-do");
			circle(backBuffer, w/2 - w/4, h/2 + h/3, 30, makecol(0, 0, 0));
			if((mouse_x > (w/2 - w/4 - 15)) && (mouse_x < (w/2 - w/4 + 15))){
				if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
					if(mouse_b&1){
						run = false;
					}
				}
			}
			

			if(i==1){
			}


			if(k>6){
				i = 7;
			}else if(k>5){
				i = 6;
			}else if(k>4){
				i = 5;
			}else if(k>3){
				i = 4;
			}else if(k>2){
				i = 3;
			}else if(k>1){
				i = 2;
			}else if(k>0){
				i = 1;
			}else if(k==0){
				i = 0;
			}


			if(ticker==0){
				//P
				if(i==0){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
				}else if(i==1){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
				}else if(i==2){
					squares[0]=1;
					squares[1]=1;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=1;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==4){
					squares[0]=1;
					squares[1]=1;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=1;
					squares[8]=2;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=1;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=1;
					squares[8]=2;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==1){
				//U
				if(i==0){
					squares[0]=2;
					squares[1]=1;
					squares[2]=2;
				}else if(i==1){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=2;
					squares[4]=1;
					squares[5]=2;
				}else if(i==2){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=2;
					squares[7]=1;
					squares[8]=2;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==4){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==2){
				//S
				if(i==0){
					squares[0]=1;
					squares[1]=1;
					squares[2]=2;
				}else if(i==1){
					squares[0]=2;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=1;
					squares[5]=2;
				}else if(i==2){
					squares[0]=2;
					squares[1]=1;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=1;
					squares[8]=2;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=1;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=1;
				}else if(i==4){
					squares[0]=2;
					squares[1]=1;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=1;
					squares[8]=2;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=1;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=1;
					squares[8]=1;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==3){
				//H
				if(i==0){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
				}else if(i==1){
					squares[0]=1;
					squares[1]=1;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
				}else if(i==2){
					squares[0]=1;
					squares[1]=1;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=1;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==4){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=1;
					squares[8]=1;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==4){
				if(i==0){
					squares[0]=winningface[6];
					squares[1]=winningface[7];
					squares[2]=winningface[8];
				}else if(i==1){
					squares[0]=winningface[3];
					squares[1]=winningface[4];
					squares[2]=winningface[5];
					squares[3]=winningface[6];
					squares[4]=winningface[7];
					squares[5]=winningface[8];
				}else if(i==2){
					squares[0]=winningface[0];
					squares[1]=winningface[1];
					squares[2]=winningface[2];
					squares[3]=winningface[3];
					squares[4]=winningface[4];
					squares[5]=winningface[5];
					squares[6]=winningface[6];
					squares[7]=winningface[7];
					squares[8]=winningface[8];
				}
			}

			//do regular stuff

			if(ticker==5){
				run = false;
				break;
			}

			//exito
			textprintf(backBuffer, font, w/2 + w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "exit");
			circle(backBuffer, w/2 + w/4, h/2 + h/3, 30, makecol(0, 0, 0));
			if((mouse_x > (w/2 + w/4 - 15)) && (mouse_x < (w/2 + w/4 + 15))){
				if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
					if(mouse_b&1){
						run = false;
						break;
					}
				}
			}

			//escing
			if(key[KEY_ESC]){
				break;
			}
			blit(backBuffer, screen, 0, 0, 0, 0, w, h);
		}
		
		if(ticker==5){
			run = false;
			break;
		}

		ticker ++;
	}
}

void loseBitch(int squares[]){

	int x;
	int y;
	int w = 640;
	int h = 480;
	int r;
	int g;
	int b;
	int radius = 50;

	int i = 0;
	int j = 0;
	float k = 0;
	int ticker = 0;
	int winningface[9];


	for(j = 0; j < 9; j ++){
		winningface[j] = squares[j];
	}


	bool run = true;
	while(run){

		for(k = 0; k < 8; k += 0.01){

			clear_to_color(backBuffer, makecol(255, 255, 255));

			r = 0;
			g = 0;
			b = 0;

			//cursor
			line(backBuffer, mouse_x, mouse_y, (mouse_x + 5), (mouse_y + 10), makecol(b, g, r));
			line(backBuffer, mouse_x, mouse_y, (mouse_x + 10), (mouse_y + 5), makecol(b, g, r));
			line(backBuffer, (mouse_x + 5), (mouse_y + 10), (mouse_x + 26), (mouse_y + 30), makecol(b, g, r));
			line(backBuffer, (mouse_x + 10), (mouse_y + 5), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));
			line(backBuffer, (mouse_x + 26), (mouse_y + 30), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));

			//grid
			//   #
			//
			//   |
			line(backBuffer, ((w/2) - 25), ((h/2) - 75), ((w/2) - 25), ((h/2) + 75), makecol(r, g, b));
			//   | |
			line(backBuffer, ((w/2) + 25), ((h/2) - 75), ((w/2) + 25), ((h/2) + 75), makecol(r, g, b));
			//   ---
			line(backBuffer, ((w/2) - 75), ((h/2) - 25), ((w/2) + 75), ((h/2) - 25), makecol(r, g, b));
			//   ===
			line(backBuffer, ((w/2) - 75), ((h/2) + 25), ((w/2) + 75), ((h/2) + 25), makecol(r, g, b));

			//drawLoop
			for(j = 0; j < 9; j ++){
				//checks each box
				//and draws in

				//positions
				if(j==0){
					x = w/2 - 50;
					y = h/2 - 50;
				}else if(j==1){
					x = w/2;
					y = h/2 - 50;
				}else if(j==2){
					x = w/2 + 50;
					y = h/2 - 50;
				}else if(j==3){
					x = w/2 - 50;
					y = h/2;
				}else if(j==4){
					x = w/2;
					y = h/2;
				}else if(j==5){
					x = w/2 + 50;
					y = h/2;
				}else if(j==6){
					x = w/2 - 50;
					y = h/2 + 50;
				}else if(j==7){
					x = w/2;
					y = h/2 + 50;
				}else if(j==8){
					x = w/2 + 50;
					y = h/2 + 50;
				}else{
					x = w + 50;
					y = h + 50;
				}
				if(squares[j] == 1){
					// x
					/*
					r = rand()%256;
					g = rand()%256;
					b = rand()%256;
					*/
					r = 0;
					g = 0;
					b = 255;

					drawX(x, y, radius, r, g ,b);
				}else if(squares[j] == 2){
					// o
					/*
					r = rand()%256;
					g = rand()%256;
					b = rand()%256;
					*/
					r = 255;
					g = 0;
					b = 0;

					drawO(x, y, radius, r, g, b);
				}else{
					//do nothing
				}
			}

			//regame
			textprintf(backBuffer, font, w/2 - w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "re-do");
			circle(backBuffer, w/2 - w/4, h/2 + h/3, 30, makecol(0, 0, 0));
			if((mouse_x > (w/2 - w/4 - 15)) && (mouse_x < (w/2 - w/4 + 15))){
				if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
					if(mouse_b&1){
						run = false;
					}
				}
			}
			

			if(i==1){
			}


			if(k>6){
				i = 7;
			}else if(k>5){
				i = 6;
			}else if(k>4){
				i = 5;
			}else if(k>3){
				i = 4;
			}else if(k>2){
				i = 3;
			}else if(k>1){
				i = 2;
			}else if(k>0){
				i = 1;
			}else if(k==0){
				i = 0;
			}


			if(ticker==0){
				//L
				if(i==0){
					squares[0]=1;
					squares[1]=1;
					squares[2]=1;
				}else if(i==1){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=1;
					squares[5]=1;
				}else if(i==2){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=1;
					squares[8]=1;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==4){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==1){
				//O
				if(i==0){
					squares[0]=2;
					squares[1]=1;
					squares[2]=2;
				}else if(i==1){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=2;
					squares[4]=1;
					squares[5]=2;
				}else if(i==2){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=2;
					squares[7]=1;
					squares[8]=2;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==4){
					squares[0]=2;
					squares[1]=1;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=1;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=1;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=1;
					squares[8]=2;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==2){
				//S
				if(i==0){
					squares[0]=1;
					squares[1]=1;
					squares[2]=2;
				}else if(i==1){
					squares[0]=2;
					squares[1]=2;
					squares[2]=1;
					squares[3]=1;
					squares[4]=1;
					squares[5]=2;
				}else if(i==2){
					squares[0]=2;
					squares[1]=1;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=1;
					squares[6]=1;
					squares[7]=1;
					squares[8]=2;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=1;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=1;
				}else if(i==4){
					squares[0]=2;
					squares[1]=1;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=1;
					squares[8]=2;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=1;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=1;
					squares[8]=1;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==3){
				//E
				if(i==0){
					squares[0]=1;
					squares[1]=1;
					squares[2]=1;
				}else if(i==1){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=1;
					squares[5]=1;
				}else if(i==2){
					squares[0]=1;
					squares[1]=1;
					squares[2]=2;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=1;
					squares[8]=1;
				}else if(i==3){
					squares[0]=1;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=1;
					squares[5]=2;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==4){
					squares[0]=1;
					squares[1]=1;
					squares[2]=1;
					squares[3]=1;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=1;
					squares[8]=2;
				}else if(i==5){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=1;
					squares[4]=1;
					squares[5]=1;
					squares[6]=1;
					squares[7]=2;
					squares[8]=2;
				}else if(i==6){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=1;
					squares[7]=1;
					squares[8]=1;
				}else if(i==7){
					squares[0]=2;
					squares[1]=2;
					squares[2]=2;
					squares[3]=2;
					squares[4]=2;
					squares[5]=2;
					squares[6]=2;
					squares[7]=2;
					squares[8]=2;
				}
			}else if(ticker==4){
				if(i==0){
					squares[0]=winningface[6];
					squares[1]=winningface[7];
					squares[2]=winningface[8];
				}else if(i==1){
					squares[0]=winningface[3];
					squares[1]=winningface[4];
					squares[2]=winningface[5];
					squares[3]=winningface[6];
					squares[4]=winningface[7];
					squares[5]=winningface[8];
				}else if(i==2){
					squares[0]=winningface[0];
					squares[1]=winningface[1];
					squares[2]=winningface[2];
					squares[3]=winningface[3];
					squares[4]=winningface[4];
					squares[5]=winningface[5];
					squares[6]=winningface[6];
					squares[7]=winningface[7];
					squares[8]=winningface[8];
				}
			}

			//do regular stuff

			if(ticker==5){
				run = false;
				break;
			}

			//exito
			textprintf(backBuffer, font, w/2 + w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "exit");
			circle(backBuffer, w/2 + w/4, h/2 + h/3, 30, makecol(0, 0, 0));
			if((mouse_x > (w/2 + w/4 - 15)) && (mouse_x < (w/2 + w/4 + 15))){
				if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
					if(mouse_b&1){
						run = false;
						break;
					}
				}
			}

			//escing
			if(key[KEY_ESC]){
				break;
			}
			blit(backBuffer, screen, 0, 0, 0, 0, w, h);
		}


		ticker ++;
	}
}




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

	int i = 0;
	int j = 0;

	int w = 640;
	int h = 480;

	int x;
	int y;

	int v, t;

	int radius = 50;

	int r = rand()%256;
	int g = rand()%256;
	int b = rand()%256;

	int selection = 9;
	int selectionX;
	int selectionY;

	bool game = true;
	int turns = 0;
	int animation = 0;
	float lemonTimer = 0;
	int check3 = 0;
	int winface;

	int boxes[9];
	for(i = 0; i < 9; i ++){
		boxes[i] = 0;
	}

	int runners[9];
	for(int blay = 0; blay < 9; blay ++){
		runners[blay] = 0;
	}

	int statement = 0;

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
		clear_to_color(backBuffer, makecol(255, 255, 255));


//////~~~~~~~~~~~~~~~~~~~~CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		/*
		RULES
		
		'int boxes[]' corresponds to positions

		0 | 1 | 2
		---------
		3 | 4 | 5
		---------
		6 | 7 | 8
		
		value of 'int boxes[i]' corresponds to type
		0   blank
		1   x
		2   o
		*/

		statement = 0;


		//colours basic
		r = 0;
		g = 0;
		b = 0;

		//cursor
		line(backBuffer, mouse_x, mouse_y, (mouse_x + 5), (mouse_y + 10), makecol(b, g, r));
		line(backBuffer, mouse_x, mouse_y, (mouse_x + 10), (mouse_y + 5), makecol(b, g, r));
		line(backBuffer, (mouse_x + 5), (mouse_y + 10), (mouse_x + 26), (mouse_y + 30), makecol(b, g, r));
		line(backBuffer, (mouse_x + 10), (mouse_y + 5), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));
		line(backBuffer, (mouse_x + 26), (mouse_y + 30), (mouse_x + 30), (mouse_y + 26), makecol(b, g, r));

		//grid
		//   #
		//
		//   |
		line(backBuffer, ((w/2) - 25), ((h/2) - 75), ((w/2) - 25), ((h/2) + 75), makecol(r, g, b));
		//   | |
		line(backBuffer, ((w/2) + 25), ((h/2) - 75), ((w/2) + 25), ((h/2) + 75), makecol(r, g, b));
		//   ---
		line(backBuffer, ((w/2) - 75), ((h/2) - 25), ((w/2) + 75), ((h/2) - 25), makecol(r, g, b));
		//   ===
		line(backBuffer, ((w/2) - 75), ((h/2) + 25), ((w/2) + 75), ((h/2) + 25), makecol(r, g, b));

		//drawLoop
		for(i = 0; i < 9; i ++){
			//checks each box
			//and draws in

			//positions
			if(i==0){
				x = w/2 - 50;
				y = h/2 - 50;

				v = w/2 + 50;
				t = h/2 + 50;
			}else if(i==1){
				x = w/2;
				y = h/2 - 50;

				v = w/2;
				t = h/2 + 50;
			}else if(i==2){
				x = w/2 + 50;
				y = h/2 - 50;

				v = w/2 - 50;
				t = h/2 + 50;
			}else if(i==3){
				x = w/2 - 50;
				y = h/2;

				v = w/2 + 50;
				t = h/2;
			}else if(i==4){
				x = w/2;
				y = h/2;

				v = w/2;
				t = h/2;
			}else if(i==5){
				x = w/2 + 50;
				y = h/2;

				v = w/2 - 50;
				t = h/2;
			}else if(i==6){
				x = w/2 - 50;
				y = h/2 + 50;

				v = w/2 + 50;
				t = h/2 - 50;
			}else if(i==7){
				x = w/2;
				y = h/2 + 50;

				v = w/2;
				t = h/2 - 50;
			}else if(i==8){
				x = w/2 + 50;
				y = h/2 + 50;

				v = w/2 - 50;
				t = h/2 - 50;
			}else{
				x = w + 50;
				y = h + 50;
			}
			if(boxes[i] == 1){
				// x
				r = rand()%256;
				g = rand()%256;
				b = rand()%256;
				drawX(x, y, radius, r, g ,b);
				if(game==false){
					int alpha, omega, charltonHeston;
					charltonHeston = 4;
					
					//if j / 3 == 1
					if(j > 50){
						//int runners[9];
						if(runners[6]==2){
							for(int blay = 0; blay < 9; blay ++){
								runners[blay] = 0;
							}
						}
						
						if(j==100){
							runners[2] += 1;
						}else if(j==150){
							runners[1] += 1;
							runners[5] += 1;
						}else if(j==200){
							runners[0] += 1;
							runners[8] += 1;
							runners[4] += 1;
						}else if(j==250){
							runners[3] += 1;
							runners[7] += 1;
						}else if(j==300){
							runners[6] += 1;
						}

						/*
						if(j==100){
							alpha = 2;
							omega = 9;
							charltonHeston = 9;
						}else if(j==150){
							alpha = 1;
							omega = 5;
							charltonHeston = 9;
						}else if(j==200){
							alpha = 0;
							omega = 8;
							charltonHeston = 4;
						}else if(j==250){
							alpha = 3;
							omega = 7;
							charltonHeston = 9;
						}else if(j==300){
							alpha = 6;
							omega = 9;
							charltonHeston = 9;
						}
						if((i==alpha)||(i==charltonHeston)||(i==omega)){
						*/
						int col;
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
						//lose special
						if(check3>0){
							for(float k = radius; k > 0; k --){
								//drawX(v, t, k, b, r, g);
								drawX(x, y, k, b, r, g);
							}
						}
						charltonHeston = rand()%9;
						if(i==charltonHeston){
							for(float k = radius; k > 0; k -= 3){
								drawX(x, y, k, r, g, b);
							}
							if(check3>0){
								for(float k = radius; k > 25; k --){
									drawX(x, y, k, b, r, g);
								}
							}
						}
					}
					
					/*
					if(j > 50){
						if(j==100){
							alpha = 2;
							omega = 9;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==150){
							alpha = 1;
							omega = 5;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==200){
							alpha = 0;
							omega = 8;
							charltonHeston = 4;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==charltonHeston){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==250){
							alpha = 3;
							omega = 7;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==300){
							alpha = 6;
							omega = 9;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}
						*/
					
					j++;
					if(j>350){
						j=0;
						alpha = 9;
						omega = 9;
						charltonHeston = 9;
					}
				}
			}else if(boxes[i] == 2){
				// o
				r = rand()%256;
				g = rand()%256;
				b = rand()%256;
				drawO(x, y, radius, r, g, b);
				if(game==false){
					int alpha, omega, charltonHeston;
					if(j > 50){
						/*
						if(j==100){
							alpha = 2;
							omega = 9;
							charltonHeston = 9;
						}else if(j==150){
							alpha = 1;
							omega = 5;
							charltonHeston = 9;
						}else if(j==200){
							alpha = 0;
							omega = 8;
							charltonHeston = 4;
						}else if(j==250){
							alpha = 3;
							omega = 7;
							charltonHeston = 9;
						}else if(j==300){
							alpha = 6;
							omega = 9;
							charltonHeston = 9;
						}
						if((i==alpha)||(i==charltonHeston)||(i==omega)){
						*/

						if(runners[6]==2){
							for(int blay = 0; blay < 9; blay ++){
								runners[blay] = 0;
							}
						}
						
						if(j==100){
							runners[2] += 1;
						}else if(j==150){
							runners[1] += 1;
							runners[5] += 1;
						}else if(j==200){
							runners[0] += 1;
							runners[8] += 1;
							runners[4] += 1;
						}else if(j==250){
							runners[3] += 1;
							runners[7] += 1;
						}else if(j==300){
							runners[6] += 1;
						}

						//colours
						int col;
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
						//lose special
						if(check3>0){
							for(j = 0; j < 9; j ++){
									if(winface = j){
							for(float k = radius; k > 25; k --){
								//drawO(v, t, k, b, r, g);
								
										if(j==0){
											if((i==0)||(i==3)||(i==6)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==1){
											if((i==1)||(i==4)||(i==7)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==2){
											if((i==2)||(i==5)||(i==8)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==3){
											if((i==0)||(i==1)||(i==2)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==4){
											if((i==3)||(i==4)||(i==5)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==5){
											if((i==6)||(i==7)||(i==8)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==6){
											if((i==0)||(i==4)||(i==8)){
												drawO(x, y, k, b, r, g);
											}
										}else if(j==7){
											if((i==2)||(i==4)||(i==6)){
												drawO(x, y, k, b, r, g);
											}
										}
										
									}
								}
							}
						}
						charltonHeston = rand()%9;
						if(i==charltonHeston){
							for(float k = radius; k > 25; k --){
								drawO(x, y, k, r, g, b);
							}
							if(check3>0){
								for(float k = radius; k > 25; k --){
									drawO(x, y, k, b, r, g);
								}
							}
						}
						
						/*
						if(j==100){
							alpha = 2;
							omega = 9;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==150){
							alpha = 1;
							omega = 5;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==200){
							alpha = 0;
							omega = 8;
							charltonHeston = 4;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==charltonHeston){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==250){
							alpha = 3;
							omega = 7;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
							if(i==omega){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}else if(j==300){
							alpha = 6;
							omega = 9;
							charltonHeston = 9;
							if(i==alpha){
								for(float k = radius; k > 0; k -= 3){
									drawX(x, y, k, r, g, 0);
								}
							}
						}
						*/
					}
					j++;
					if(j>350){
						j=0;
						alpha = 9;
						omega = 9;
						charltonHeston = 9;
					}
				}
			}else{
				//do nothing
			}
		}

		


		//wins
		int check = 0;
		for(i = 0; i < 9; i ++){
			if(boxes[i]==0){
				check++;
			}
		}
		if(check<4){
			if(boxes[4] != 0){
				//   '\'
				if((boxes[0] == boxes[4]) && (boxes[8] == boxes[4])){
					line(backBuffer, w/2 - 50, h/2 - 50, w/2 + 50, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 6;
				}
				//   '/'
				if((boxes[2] == boxes[4]) && (boxes[6] == boxes[4])){
					line(backBuffer, w/2 + 50, h/2 - 50, w/2 - 50, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 7;
				}
				//   '|'
				if((boxes[1] == boxes[4]) && (boxes[7] == boxes[4])){
					line(backBuffer, w/2, h/2 - 50, w/2, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 1;
				}
				//   '---'
				if((boxes[3] == boxes[4]) && (boxes[5] == boxes[4])){
					line(backBuffer, w/2 - 50, h/2, w/2 + 50, h/2, makecol(g, r, r));
					check3 ++;
					winface = 4;
				}
			}
			//   '|  '
			if(boxes[3] != 0){
				if((boxes[0] == boxes[3]) && (boxes[6] == boxes[3])){
					line(backBuffer, w/2 - 50, h/2 - 50, w/2 - 50, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 0;
				}
			}
			//   '  |'
			if(boxes[5] != 0){
				if((boxes[2] == boxes[5]) && (boxes[8] == boxes[5])){
					line(backBuffer, w/2 + 50, h/2 - 50, w/2 + 50, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 2;
				}
			}
			//   '^^^'
			if(boxes[1] != 0){
				if((boxes[0] == boxes[1]) && (boxes[2] == boxes[1])){
					line(backBuffer, w/2 - 50, h/2 - 50, w/2 + 50, h/2 - 50, makecol(g, r, r));
					check3 ++;
					winface = 3;
				}
			}
			//   '___'
			if(boxes[7] != 0){
				if((boxes[6] == boxes[7]) && (boxes[8] == boxes[7])){
					line(backBuffer, w/2 - 50, h/2 + 50, w/2 + 50, h/2 + 50, makecol(g, r, r));
					check3 ++;
					winface = 5;
				}
			}
		}
		if(check3>0){
			game = false;
			//j = 0;
		}
		if((game==false)&&(turns>0)){
			if(animation < 1){
				if(lemonTimer>1000){
					if(check3 < 1){
						push(boxes);
						animation ++;
					}else if(check3 >= 1){
						loseBitch(boxes);
						animation ++;
					}
				}
				lemonTimer ++;
			}
		}
		


		//gaming
		if(game){
			//one turn per thread xxxtra measure
			if(statement==0){
			if(turns==0){
				//humon on evens
				humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==1){
				//robit on odds
				robtMove(boxes);
				//humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==2){
				humnMove(boxes);
				turns ++;
			}else if(turns==3){
				robtMove(boxes);
				//humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==4){
				humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==5){
				robtMove(boxes);
				//humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==6){
				humnMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==7){
				robtMove(boxes);
				turns ++;
				statement ++;
			}else if(turns==8){
				humnMove(boxes);
				turns ++;
				statement ++;
			}
			}
		}
		if(turns>8){
			game = false;
		}

		///BUTTTTONNNS
		//regame
		textprintf(backBuffer, font, w/2 - w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "re-do");
		circle(backBuffer, w/2 - w/4, h/2 + h/3, 30, makecol(0, 0, 0));
		if((mouse_x > (w/2 - w/4 - 15)) && (mouse_x < (w/2 - w/4 + 15))){
			if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
				if(mouse_b&1){
					turns = 0;
					for(i = 0; i < 9; i ++){
						boxes[i] = 0;
					}
					game = true;

					check3 = 0;
					animation = 0;
					lemonTimer = 0;
				}
			}
		}

		//exito
		textprintf(backBuffer, font, w/2 + w/4 - 20, h/2 + h/3, makecol(255, 255, 255), "finish");
		circle(backBuffer, w/2 + w/4, h/2 + h/3, 30, makecol(0, 0, 0));
		if((mouse_x > (w/2 + w/4 - 15)) && (mouse_x < (w/2 + w/4 + 15))){
			if((mouse_y > (h/2 + h/3 - 15)) && (mouse_y < h/2 + h/3 + 15)){
				if(mouse_b&1){
					done = true;
					break;
				}
			}
		}


//////~~~~~~~~~~~~~~~~~~~~/CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


		blit(backBuffer, screen, 0, 0, 0, 0, 640, 480);
	}
}
END_OF_MAIN()