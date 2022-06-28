/*
 * Types for coordinate operations.
 *
 * Authors: Malte J. Ziebarth (ziebarth@gfz-potsdam.de)
 *
 * Copyright (C) 2022 Deutsches GeoForschungsZentrum Potsdam
 *
 * Licensed under the EUPL, Version 1.2 or – as soon they will be approved by
 * the European Commission - subsequent versions of the EUPL (the "Licence");
 * You may not use this work except in compliance with the Licence.
 * You may obtain a copy of the Licence at:
 *
 * https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the Licence is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the Licence for the specific language governing permissions and
 * limitations under the Licence.
 */

#include <../include/projwrappertypes.hpp>
#include <cmath>

using projwrapper::xy_t;
using projwrapper::geo_t;
using projwrapper::geo_degrees_t;
using projwrapper::deg2rad;



xy_t::xy_t(double x, double y) : x(x), y(y)
{
}


double xy_t::distance(const xy_t& other) const
{
	return std::sqrt(distance_squared(other));
}

double xy_t::distance_squared(const xy_t& other) const
{
	const double dx = x - other.x;
	const double dy = y - other.y;
	return dx*dx + dy*dy;
}


bool xy_t::operator==(const xy_t& other) const
{
	return (x == other.x) && (y == other.y);
}


geo_t::geo_t(double lambda, double phi) : lambda(lambda), phi(phi)
{
}


geo_degrees_t::geo_degrees_t(double lon, double lat) : lon(lon), lat(lat)
{
}


geo_t geo_degrees_t::to_radians() const
{
	return {deg2rad(lon), deg2rad(lat)};
}


double projwrapper::deg2rad(double deg){
	return projwrapper::PI / 180.0 * deg;
}

double projwrapper::rad2deg(double rad){
	return 180.0 / projwrapper::PI * rad;
}

double projwrapper::modulo(double a, double b){
	/* True modulo operation (similar to Python's (a % b)).
	 * Implemented here only for positive b (which is what we use).
	 */
	double y = std::fmod(a,b);
	if (y < 0.0)
		return y+b;
	return y;
}
