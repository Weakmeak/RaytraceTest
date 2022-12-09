#pragma once
#include <vector>

#include <memory>

#include "../Math/Color.h"



class Object;

struct Ray;

struct RaycastHit;



class Scene

{

public:

    Scene() = default;
    Scene(const color3& top_color, const color3& bottom_color) :
        grad_top{ top_color }, grad_bottom{ bottom_color } {};



    color3 Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth);

    void AddObject(std::unique_ptr<Object> object);



private:
    color3 grad_top = {0.5f, 0.7f, 1.0f};
    color3 grad_bottom = {1, 1, 1};

    std::vector <std::unique_ptr<Object>> m_objects;

};