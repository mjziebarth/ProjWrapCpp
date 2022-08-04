/*
 * Inverse projection based on either PROJ inverse projection or inverting
 * PROJ forward projection.
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

#include <proj.h>
#include <memory>
#include <stdexcept>
#include <projwrappertypes.hpp>

#ifndef FLOTTEKARTE_PROJWRAPPER_HPP
#define FLOTTEKARTE_PROJWRAPPER_HPP

namespace projwrapper {

/* An exception class for PROJ errors: */
class ProjError : public std::exception
{
public:
	ProjError(const char* msg);

	virtual const char* what() const noexcept;

private:
	const char* msg;
};



/* A container for an originally created PJ object: */
class PJContainer {
public:
    PJContainer(const char* proj_str);
    ~PJContainer();
    const PJ* get() const;

	double a() const;
	double f() const;

	bool has_inverse() const;

private:
    PJ_CONTEXT* context;
    PJ* projection;
    double _a;
    double _f;
    bool _has_inverse;
};


/* The main wrapper class. */
class ProjWrapper {
public:
    ProjWrapper(const char* proj_str);
    ProjWrapper(const ProjWrapper& other);
    ~ProjWrapper();

    void project(double lam, double phi, double& x, double& y) const;
    xy_t project(double lam, double phi) const;
	xy_t project(const geo_t& lola) const;
	xy_t project(const geo_degrees_t& lola) const;

	geo_t inverse(const xy_t& xy_t) const;
	void inverse(double x, double y, double& lam, double& phi) const;
	bool has_inverse() const;

	double a() const;
	double f() const;

private:
    std::shared_ptr<PJContainer> proj_source;

    PJ_CONTEXT* context;
    PJ* workhorse;
};


}

#endif