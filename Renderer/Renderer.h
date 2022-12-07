#pragma once
#include <SDL.h>
#include "Canvas.h"
#include "Camera.h"


struct Ray;
class Object;
class Scene;

class Renderer
{
public:
	Renderer() = default;
	bool Initialize();
	void Shutdown();
	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, Scene& scene, Camera& camera);

	friend class Canvas;
private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	color3 GetBackgroundFromRay(const Ray& ray);
};