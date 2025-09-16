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


double xy_t::distance(const xy_t& other) const
{
	return std::sqrt(distance_squared(other));
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
