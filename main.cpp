#include "source/runner.h"
#include "source/scenes/scene.h"
#include "source/scenes/basic_scene.h"

int main()
{
	Runner runner{400, 400, "Snake"};
	Scene* base{};
	BasicScene derived{};
	base = &derived;
	return runner.Run(base);
}