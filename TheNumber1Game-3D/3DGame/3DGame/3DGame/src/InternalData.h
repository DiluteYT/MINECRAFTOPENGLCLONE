#pragma once

class Shader;
class Scene;
class WindowCreation;
class Time;

class InternalData
{
public:

	WindowCreation* wc;
	Time* time;
	Scene* boundScene;
	Shader* mainShader;

	InternalData(Scene* in_boundScene, Shader* in_mainShader, WindowCreation* in_wc, Time* in_time);

	void SoF_InternalUpdate();
	void EoF_InternalUpdate();
};
