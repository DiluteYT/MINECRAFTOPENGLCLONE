#pragma once

#include "glfw3.h"

#include <chrono>
#include <iostream>

class Time {
public:
	float deltaTime = 0;

	void UpdateTime();
private:
	double old_time = glfwGetTime();
	double time = 0;

};

class Timer {
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!timerStopped)
			Stop();
	}

	void Stop()
	{
		timerStopped = true;
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << ms << std::endl;
	}
private:

	bool timerStopped = false;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};