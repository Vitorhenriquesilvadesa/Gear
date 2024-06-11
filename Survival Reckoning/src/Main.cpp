#include "SurvivalReckoning.h"

int main()
{
	Engine::GetInstance().Init<SurvivalReckoning>();
	Engine::GetInstance().Run();
}