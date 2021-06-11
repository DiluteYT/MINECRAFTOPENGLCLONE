#include "Time.h"

void Time::UpdateTime() {

	time = glfwGetTime();
	deltaTime = (float)(time - old_time);
	old_time = time;
}
