# exprcalc
A console expression evaluator, more than a calculator. Based on the ideas of tree-walk interpreter from crafting interpreters.

_work under progress by the way ;(_
## The idea
I needed a quick and handy tool to do stuff like number system conversion, unit converters, encoders and decoders. So this is a step forward towards that goal. In this project I try to make a workable prototype of a calculator and hopefully be able to extend the features and capabilities.

This is also going to help me revise the concepts like recursive descent algorithm of tree walk interpreters which I learned in Crafting Interpreters book. Further this will help me make my first proper programming language with my desired features (very ambitious goal, I know).

So, let's see how far I can go.

## Expected final program behaviour :
```bash
 ./calcexpr
```
```
Welcome to calc expr!!
> 3+4*(2-9)^2
199
> log(2,dec(2CD))
9.485 829 308 7
```

## Status
- ✅ Scanner/Tokenizer class complete
	- reconize numbers, basic operators, parenthesis
	- stores alphanumerics (first letter alphabet) as identifiers
	which can later be used for constants and function names