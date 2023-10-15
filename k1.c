#include <karel.h>

#define DELAY 500

void turn_right() {

	set_step_delay(1);
	for (int i=0;i<3;i++){
		turn_left();
	}
	set_step_delay(DELAY);
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

	for (int i=0;i<3;i++){
		put_beeper();
	}
}
	
void main() {
	
	turn_on("stairs.kw");
	set_step_delay(DELAY);

	step();
	for (int i=0;i<4;i++){
		move();
	}
	
	put_beepers();
}


