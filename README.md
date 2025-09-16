# ProjWrapCpp
This project provides a C++ class, `ProjWrapper`, that encapsulates the projection
objects from C API defined in `<proj.h>` of the PROJ library. The code provides
lifetime handling of the `PJ` object within the `PJContainer`, constructing a
C++ projection object from PROJ4 strings, and convenient projection facilities.

## Usage
This projects exports the `libprojwrap_dep` Meson dependency so that this
Git repository can be included as a Meson subproject using a `libprojwrap.wrap`
file like this:
```
[wrap-git]
url = git@github.com:mjziebarth/ProjWrapCpp.git
revision = head
```
Once installed, the following API can be included from `<include/projwrapper.hpp>`:
```cpp
namespace projwrapper {

struct xy_t {
    double x;
    double y;

    xy_t(double x, double y);

    double distance(const xy_t& other) const;

    double distance_squared(const xy_t& other) const;

    bool operator==(const xy_t& other) const;

    constexpr xy_t& operator=(const xy_t&) = default;
};

struct geo_t {
    double lambda;
    double phi;

    geo_t(double lambda, double phi);
};

struct geo_degrees_t {
    double lon;
    double lat;

    geo_degrees_t(double lon, double lat);

    geo_t to_radians() const;
};


class ProjWrapper {
public:
    ProjWrapper(const char* proj_str);

    void project(double lam, double phi, double& x, double& y) const;
    xy_t project(double lam, double phi) const;
    xy_t project(const geo_t& lola) const;
    xy_t project(const geo_degrees_t& lola) const;

    geo_t inverse(const xy_t& xy_t) const;
    void inverse(double x, double y, double& lam, double& phi) const;
    bool has_inverse() const;

    double a() const;
    double f() const;
}

}
```
Coordinates `lam`, `phi`, and `geo_t` are expected in radians, `geo_degrees_t` in arc degrees.

If the creation of the `PJ` object or a coordinate transformation fails, an instance of `projwrapper::ProjError` is thrown.

## License
`ProjWrapCpp` is licensed under the European Public License (EUPL) version 1.2 or later. See the LICENSE file in the project root directory.

## Changelog
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

### [Unreleased]
#### Added
- Add support for obtaining the PROJ dependency from the
  [PROJ-Meson-Meta-Wrapper](https://codeberg.org/mjziebarth/PROJ-Meson-Meta-Wrapper)
  by the present author.

#### Changed
- Enable `constexpr` for some of the small-body functions and methods.
- Do not install the static library by default (`install: true`). That did not make sense; its purpose is to be linked anyway.

### [1.3.1] - 2023-01-17
#### Changed
- Fix an undetected Meson error introduced in 1.3.1.

### [1.3.0] - 2023-01-13
#### Changed
- Change the Meson definition and ensure linking with `libproj`.

### [1.2.0] - 2022-08-04
#### Added
- Added querying of projection inverse availability.

### [1.1.0] - 2022-08-04
#### Changed
- Reset the error state in `inverse` before throwing the error. This allows to
  recover by handling the exception, a vital point to test the validity of
  `xy_t` coordinates by inverting.

### [1.0.0] - 2022-06-30
#### Added
- First version.
