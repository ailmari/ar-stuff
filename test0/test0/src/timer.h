#pragma once

#include <ctime>

class Timer {
	
	public:
		Timer();
		
		void reset();
		void update();
		
		float getDelta();
		float getTotal();
		
	private:
		clock_t t;
		float delta;
		float total;
};