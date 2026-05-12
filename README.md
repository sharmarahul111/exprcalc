# exprcalc
A console expression evaluator and utility DSL for arithmetic, conversions, encoding/decoding, and other programmable operations.

Inspired by the tree-walk interpreter architecture from Crafting Interpreters.

_work in progress by the way ;(_
## The idea
I needed a quick and handy tool to do stuff like number system conversions, unit conversions, encoders, and decoders. This project starts as a workable calculator prototype and gradually evolves into a more extensible expression engine with utility-focused features.

This also helps me revisit concepts like recursive descent parsing and AST evaluation that I learned from Crafting Interpreters. This project also serves as groundwork for building my first proper programming language with features I actually want (very ambitious goal, I know).

So, let's see how far I can go.

## Expected final program behaviour
```bash
 ./exprcalc
```
```
exprcalc v0.3
Press Ctrl+C to exit.
> 3+4*(2-9)^2
199
> log(2,dec(2CD))
9.485 829 308 7
```

## Status
### Current capabilities
```
> 3+4*(2-9)^2
199
> ans/2
99.5
> sin((140-20)*cos(60)^2)
0.5
> gcd(4,6)
2
> lcm(68,28)
476
> perm(hypot(3,4),3)
60
> min(34,89)
34
```

### Current Progress
- ✅ Scanner/Tokenizer class complete
	- recognize numbers, basic operators, parenthesis
	- stores alphanumerics (first letter alphabet) as identifiers
	which can later be used for constants and function names
- ✅ Abstract Syntax Tree (AST)
	- handles binary operators `(+,-,*,/,^)`, grouping, unary, literal values.
	- ❌ function call not implemented yet
- ✅ Evaluator
	- evaluates binary operators `(+,-,*,/,^)`, grouping, unary, and literal values
	- ⚠ exponent (`^`) associativity currently incorrect
- ✅ Various mathematical, phisical and chemical constants (pi, G, NA, etc)
- ✅ Runtime variable support internally (can't make variables yet)
	- ✅ `ans` variable support for storing latest answerin memory