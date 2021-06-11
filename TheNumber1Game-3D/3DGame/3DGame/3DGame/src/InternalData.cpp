#include "InternalData.h"
#include "WindowCreation.h"
#include "Time.h"
#include "Input.h"
#include "Scene.h"
#include "Camera.h"

InternalData::InternalData(Scene* in_boundScene, Shader* in_mainShader, WindowCreation* in_wc, Time* in_time)
	: wc{ in_wc },
	mainShader{ in_mainShader },
	time{ in_time },
	boundScene{ in_boundScene }
{

}

void InternalData::SoF_InternalUpdate()
{
	time->UpdateTime();
	boundScene->Update();
}

void InternalData::EoF_InternalUpdate()
{
	boundScene->SceneCamera.CalculateMatrices(*mainShader);
}

