#include "library.h"
#include <cmath>

Context library(){
	Context ctx;
    // Mathematical constants
    ctx.constants["pi"] = 3.14159265358979323846;
    ctx.constants["e"] = 2.71828182845904523536;
    ctx.constants["tau"] = 6.28318530717958647692;
    ctx.constants["phi"] = 1.61803398874989484820;
    ctx.constants["sqrt2"] = 1.41421356237309504880;
    ctx.constants["sqrt3"] = 1.73205080756887729353;
    ctx.constants["ln2"] = 0.69314718055994530942;
    ctx.constants["ln10"] = 2.30258509299404568402;

    // Fundamental physics constants
    ctx.constants["c"] = 299792458.0;                 // speed of light (m/s)
    ctx.constants["G"] = 6.67430e-11;                 // gravitational constant
    ctx.constants["g"] = 9.80665;                     // standard gravity (m/s^2)
    ctx.constants["h"] = 6.62607015e-34;              // Planck constant (J·s)
    ctx.constants["hbar"] = 1.054571817e-34;          // reduced Planck constant
    ctx.constants["kB"] = 1.380649e-23;               // Boltzmann constant
    ctx.constants["R"] = 8.314462618;                 // gas constant
    ctx.constants["NA"] = 6.02214076e23;              // Avogadro constant

    // Electromagnetism
    ctx.constants["e_charge"] = 1.602176634e-19;      // elementary charge (C)
    ctx.constants["eps0"] = 8.8541878128e-12;         // vacuum permittivity
    ctx.constants["mu0"] = 1.25663706212e-6;          // vacuum permeability
    ctx.constants["ke"] = 8.9875517923e9;             // Coulomb constant

    // Atomic / chemistry constants
    ctx.constants["amu"] = 1.66053906660e-27;         // atomic mass unit (kg)
    ctx.constants["me"] = 9.1093837015e-31;           // electron mass (kg)
    ctx.constants["mp"] = 1.67262192369e-27;          // proton mass (kg)
    ctx.constants["mn"] = 1.67492749804e-27;          // neutron mass (kg)
    ctx.constants["a0"] = 5.29177210903e-11;          // Bohr radius (m)
    ctx.constants["rydberg"] = 10973731.568160;       // Rydberg constant (1/m)
    ctx.constants["F"] = 96485.33212;                 // Faraday constant
    ctx.constants["sigma"] = 5.670374419e-8;          // Stefan-Boltzmann constant

    // Astronomy
    ctx.constants["AU"] = 1.495978707e11;             // astronomical unit (m)
    ctx.constants["ly"] = 9.4607304725808e15;         // light year (m)
    ctx.constants["pc"] = 3.08567758149137e16;        // parsec (m)
    ctx.constants["M_sun"] = 1.98847e30;              // solar mass (kg)
    ctx.constants["R_earth"] = 6.371e6;               // Earth radius (m)
    ctx.constants["M_earth"] = 5.9722e24;             // Earth mass (kg)

    // Binary/data sizes
    ctx.constants["KB"] = 1024.0;
    ctx.constants["MB"] = 1024.0 * 1024.0;
    ctx.constants["GB"] = 1024.0 * 1024.0 * 1024.0;
    ctx.constants["TB"] = 1024.0 * 1024.0 * 1024.0 * 1024.0;

	// Funtion implementation
	ctx.functions["sin"] = [](auto& args){
		double x = std::get<double>(args[0]);
		return std::sin(x);
	};
	ctx.functions["abs"] = [](auto& args){
		double x = std::get<double>(args[0]);
		return std::abs(x);
	};
	return ctx;
}