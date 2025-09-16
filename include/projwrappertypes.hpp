/*
 * Types for coordinate operations.
 *
 * Authors: Malte J. Ziebarth (ziebarth@gfz-potsdam.de)
 *
 * Copyright (C) 2022 Deutsches GeoForschungsZentrum Potsdam,
 *               2025 Technische Universität München
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

#ifndef PROJWRAPPER_PROJWRAPPERTYPES_HPP
#define PROJWRAPPER_PROJWRAPPERTYPES_HPP

namespace projwrapper {

constexpr double PI = 3.14159265358979323846;

constexpr double deg2rad(double deg) noexcept
{
    constexpr double d2r = projwrapper::PI / 180;
    return d2r * deg;
}

constexpr double rad2deg(double rad) noexcept
{
    constexpr double r2d = 180 / projwrapper::PI;
    return r2d * rad;
}



struct xy_t {
    double x;
    double y;

    constexpr xy_t() = default;
    constexpr xy_t(xy_t&&) = default;
    constexpr xy_t(const xy_t&) = default;

    constexpr xy_t(double x, double y) : x(x), y(y)
    {}

    double distance(const xy_t& other) const;

    constexpr double distance_squared(const xy_t& other) const
    {
        const double dx = x - other.x;
        const double dy = y - other.y;
        return dx*dx + dy*dy;
    }

    constexpr bool operator==(const xy_t& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    constexpr xy_t& operator=(const xy_t&) = default;
};


struct geo_t {
    double lambda;
    double phi;

    constexpr geo_t() noexcept = default;
    constexpr geo_t(geo_t&&) noexcept = default;
    constexpr geo_t(const geo_t&) noexcept = default;

    constexpr geo_t(double lambda, double phi) noexcept : lambda(lambda), phi(phi)
    {}


    constexpr geo_t& operator=(const geo_t&) noexcept = default;
};


struct geo_degrees_t {
    double lon;
    double lat;

    constexpr geo_degrees_t() = default;
    constexpr geo_degrees_t(geo_degrees_t&&) = default;
    constexpr geo_degrees_t(const geo_degrees_t&) = default;

    constexpr geo_degrees_t(double lon, double lat) noexcept : lon(lon), lat(lat)
    {}

    constexpr geo_degrees_t& operator=(const geo_degrees_t&) = default;

    constexpr geo_t to_radians() const noexcept
    {
        return geo_t(deg2rad(lon), deg2rad(lat));
    }
};


double modulo(double a, double b);

}

#endif