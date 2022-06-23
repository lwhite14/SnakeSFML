#pragma once


class Scene 
{
private:
	int width, height;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};