#include "library.h"
#include <cmath>
#include <ctime>
#include <numeric>

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

	ctx.nullaryFn = {
		{"rand", []() { return static_cast<double>(std::rand()) / RAND_MAX; }},
		{"time", []() { return static_cast<double>(std::time(nullptr)); }},
		{"clock", []() { return static_cast<double>(std::clock()); }}
	};

	ctx.unaryFn = {
		// Trigonometric (input in degrees)
		{"sin", [](double x) { return std::sin(x * M_PI / 180.0); }},
		{"cos", [](double x) { return std::cos(x * M_PI / 180.0); }},
		{"tan", [](double x) { return std::tan(x * M_PI / 180.0); }},

		{"csc", [](double x) { return 1.0 / std::sin(x * M_PI / 180.0); }},
		{"sec", [](double x) { return 1.0 / std::cos(x * M_PI / 180.0); }},
		{"cot", [](double x) { return 1.0 / std::tan(x * M_PI / 180.0); }},

		// Inverse trig (returns degrees)
		{"asin", [](double x) { return std::asin(x) * 180.0 / M_PI; }},
		{"acos", [](double x) { return std::acos(x) * 180.0 / M_PI; }},
		{"atan", [](double x) { return std::atan(x) * 180.0 / M_PI; }},

		// Hyperbolic
		{"sinh", [](double x) { return std::sinh(x); }},
		{"cosh", [](double x) { return std::cosh(x); }},
		{"tanh", [](double x) { return std::tanh(x); }},

		{"asinh", [](double x) { return std::asinh(x); }},
		{"acosh", [](double x) { return std::acosh(x); }},
		{"atanh", [](double x) { return std::atanh(x); }},

		// Exponential / logarithmic
		{"exp", [](double x) { return std::exp(x); }},
		{"exp2", [](double x) { return std::exp2(x); }},
		{"expm1", [](double x) { return std::expm1(x); }},

		{"ln", [](double x) { return std::log(x); }},
		{"log", [](double x) { return std::log10(x); }},
		{"log2", [](double x) { return std::log2(x); }},
		{"log1p", [](double x) { return std::log1p(x); }},

		// Power / roots
		{"sqrt", [](double x) { return std::sqrt(x); }},
		{"cbrt", [](double x) { return std::cbrt(x); }},

		// Rounding
		{"floor", [](double x) { return std::floor(x); }},
		{"ceil", [](double x) { return std::ceil(x); }},
		{"round", [](double x) { return std::round(x); }},
		{"trunc", [](double x) { return std::trunc(x); }},

		// Absolute / sign
		{"abs", [](double x) { return std::abs(x); }},
		{"sign", [](double x) { return (x > 0) - (x < 0); }},

		// Angle conversion
		{"deg", [](double x) { return x * 180.0 / M_PI; }},
		{"rad", [](double x) { return x * M_PI / 180.0; }},

		// Misc math
		{"fact", [](double x) {
			// TODO: input validation for factorial
			double result = 1;
			for (int i = 1; i <= static_cast<int>(x); i++) result *= i;
			return result;
		}},

		// temprature
		{"c2f", [](double x) { return x * 9.0 / 5.0 + 32.0; }},
		{"f2c", [](double x) { return (x - 32.0) * 5.0 / 9.0; }},
		{"c2k", [](double x) { return x + 273.15; }},
		{"k2c", [](double x) { return x - 273.15; }},

	};
	
	ctx.binaryFn = {
		  // Powers / logarithms / roots
		{"pow", [](double a, double b) { return std::pow(a, b); }},
		{"root", [](double n, double x) { return std::pow(x, 1.0 / n); }},
		{"logn", [](double base, double x) {
			return std::log(x) / std::log(base);
		}},

		// Basic comparisons
		{"min", [](double a, double b) { return std::min(a, b); }},
		{"max", [](double a, double b) { return std::max(a, b); }},

		// Remainder / modular arithmetic
		{"mod", [](double a, double b) { return std::fmod(a, b); }},
		{"rem", [](double a, double b) { return std::remainder(a, b); }},

		// Geometry
		{"hypot", [](double a, double b) { return std::hypot(a, b); }},
		{"atan2", [](double y, double x) {
			return std::atan2(y, x) * 180.0 / M_PI;
		}},

		// Number theory
		{"gcd", [](double a, double b) {
			return static_cast<double>(
				std::gcd(
					static_cast<int>(a),
					static_cast<int>(b)
				)
			);
		}},

		{"lcm", [](double a, double b) {
			return static_cast<double>(
				std::lcm(
					static_cast<int>(a),
					static_cast<int>(b)
				)
			);
		}},

		// Distance / difference
		{"dist", [](double a, double b) { return std::abs(a - b); }},

		// Means
		{"avg", [](double a, double b) { return (a + b) / 2.0; }},
		{"gmean", [](double a, double b) { return std::sqrt(a * b); }},
		{"hmean", [](double a, double b) {
			return 2.0 * a * b / (a + b);
		}},

		// Combinatorics
		{"perm", [](double n, double r) {
			if (n < 0 || r < 0 || r > n)
				throw std::string("invalid nPr");

			double result = 1;
			for (int i = 0; i < static_cast<int>(r); ++i)
				result *= (n - i);

			return result;
		}},

		{"comb", [](double n, double r) {
			if (n < 0 || r < 0 || r > n)
				throw std::string("invalid nCr");

			double num = 1;
			double den = 1;

			for (int i = 1; i <= static_cast<int>(r); ++i) {
				num *= (n - i + 1);
				den *= i;
			}

			return num / den;
		}},

	};
	return ctx;
}