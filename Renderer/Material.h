#pragma once
#include "../Math/Color.h"

struct Ray;
struct RaycastHit;

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;

    virtual color3 GetEmissive() { return { 0, 0, 0 }; }
};

class Lambertian : public Material

{

public:

    Lambertian(const color3& albedo) : m_albedo{ albedo } {}

    bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

protected:

    color3 m_albedo;

};

class Metal : public Material

{

public:

    Metal(const color3& albedo, const float& fuzz = 0.1f) : m_albedo{ albedo }, m_fuzz{ fuzz } {}

    bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

protected:

    color3 m_albedo;
    float m_fuzz;

};

class Emissive : public Material

{

    public:

        Emissive(const color3& albedo) : m_albedo{ albedo } {}

        bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override { return false; };

         color3 GetEmissive() override { return m_albedo; }

    protected:

        color3 m_albedo;

};

class Dielectric : public Material

{

public:

    Dielectric(const color3& albedo, const float& index = 0.1f) : m_albedo{ albedo }, m_index{ index } {}

    bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const override;

protected:

    color3 m_albedo;
    float m_index;

};