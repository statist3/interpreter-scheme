#scheme

Implemented an interpreter for
a lisp-like programming language, namely a certain subset of scheme.

The language consists of:
  - Primitive types: integers, bools and _characters_ (identifiers).
  - Composite types: pairs and lists.
  - Variables with syntactic scope.
  - Functions and lambda expressions.

The program executes language expressions and returns the execution result.

```
     1 => 1
     (+ 1 2) => 3
```
The notation `=>` in the examples here and below separates the expression and the result of its execution.

## Executing expressions
Language execution occurs in 3 stages:

**Tokenization** - converts program text into a sequence
    atomic lexemes.

**Parsing** - converts a sequence of tokens
    in [AST]

**Compute** - recursively traverses the program's AST and converts it
    according to a set of rules.

### Example

Expression
```
     (+ 2 (/ -5 +4))
```
as a result of tokenization it will turn into a list of tokens:
```
     {
         OpenParen()
         Symbol("+"),
         Number(2),
         OpenParen()
         Symbol("/"),
         Number(-5),
         Number(4),
         CloseParen()
         CloseParen()
     }
```

  Sequence of tokens resulting from parsing
  will turn into a tree:

```
     Cell{
         Symbol("+"),
         Cell{
             Number(2),
             Cell{
                 Cell{
                     Symbol("/"),
                     Cell{
                         Number(-5),
                         Cell{
                             Number(4),
                             nullptr
                         }
                     }
                 }
                 nullptr
             }
         }
     }
```
The result of executing the expression will be

```
     (+ 2 (/ -5 +4)) => 1
```


## Error processing



   1. SyntaxError - syntax errors. Occurs when the program does not comply
      formal syntax of the language. Or when the program is wrong
      uses special forms.

   2. NameError - errors when accessing undefined variables.

   3. RuntimeError - runtime errors. These errors include all others
      errors that may occur during execution
      programs. For example: incorrect number of arguments passed to
      function, wrong argument type.
