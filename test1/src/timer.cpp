#include "timer.h"

Timer::Timer() {
	
	this->reset();
}

void Timer::reset() {
	
	this->t = clock();
	this->total = 0;
	this->delta = 0;
}

void Timer::update() {
	
	this->delta = ((float) (clock() - this->t)) / CLOCKS_PER_SEC;
	this->total += delta;
	this->t = clock();
}

float Timer::getDelta() const {
	
	return this->delta;
}

float Timer::getTotal() const {
	
	return this->total;
}
