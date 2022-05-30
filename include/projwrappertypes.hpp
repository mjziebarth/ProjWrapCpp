/*
 *
 */

#ifndef PROJWRAPPER_PROJWRAPPERTYPES_HPP
#define PROJWRAPPER_PROJWRAPPERTYPES_HPP

namespace projwrapper {

constexpr double PI = 3.14159265358979323846;

struct xy_t {
	double x;
	double y;

	xy_t() = default;
	xy_t(xy_t&&) = default;
	xy_t(const xy_t&) = default;
	xy_t(double x, double y);

	double distance(const xy_t& other) const;

	double distance_squared(const xy_t& other) const;

	bool operator==(const xy_t& other) const;

	constexpr xy_t& operator=(const xy_t&) = default;
};

struct geo_t {
	double lambda;
	double phi;

	geo_t() = default;
	geo_t(geo_t&&) = default;
	geo_t(const geo_t&) = default;
	geo_t(double lambda, double phi);

	constexpr geo_t& operator=(const geo_t&) = default;
};

struct geo_degrees_t {
	double lon;
	double lat;

	geo_degrees_t() = default;
	geo_degrees_t(geo_degrees_t&&) = default;
	geo_degrees_t(const geo_degrees_t&) = default;
	geo_degrees_t(double lon, double lat);

	constexpr geo_degrees_t& operator=(const geo_degrees_t&) = default;

	geo_t to_radians() const;
};


double deg2rad(double deg);
double rad2deg(double rad);

double modulo(double a, double b);

}

#endif