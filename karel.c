#include <karel.h>

#define DELAY 500

void turn_right() {
	turn_left();
	turn_left();
	turn_left();
}

bool facing_east() {
	bool east;
	east = false;
	
	turn_left();
	if (facing_north()) {
		east = true;
	}
	turn_right();
	return(east);
}

void turn_north() {

	while (! facing_north()) {
		turn_left();
	}
}

bool front_is_blocked () {
	if (front_is_clear()) 
		return(false);
	else 
		return(true);
}
	
void move() {

	if ( facing_north() ) {
		step();
		turn_right();
		step();
		if ( beepers_present() ) pick_beeper();
	} else {
		turn_left();
		move();
	}
}
	
void put_beepers() {

	for (int i=0;i<3;i++) put_beeper();
}
	
void main() {
	
	turn_on("stairs.kw");
	set_step_delay(DELAY);

	step();
	for (int i=0;i<4;i++) move();
	
	put_beepers();
	turn_off();
}

