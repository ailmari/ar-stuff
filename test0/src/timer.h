#pragma once

#include <ctime>

class Timer {
	
	public:
		Timer();
		
		void reset();
		void update();
		
		float getDelta() const;
		float getTotal() const;
		
	private:
		clock_t t;
		float delta;
		float total;
};