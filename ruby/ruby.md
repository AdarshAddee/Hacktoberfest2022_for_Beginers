---
title: Ruby 
description: Ruby cheatsheet contains useful code syntax with examples which is handy while coding.
created: 2022-10-5
updated: 2022-10-05
---

## Basics

### Sample program
```ruby
puts "Hello, World!"
```
* ***puts*** :  Used to print the given text to the console.
* `#` : Single line Comment
* `=begin`
Multi 
line 
comment
`=end`

## Variables

### 1. Global variables

Begins with `$` and will have global scope
```ruby
$var_scope = "GLOBAL"
```

### 2. Local variables

Begins with a `lowercase letter` or `underscore (_)` and will have scope limited to block of it's initialization.
```ruby
_greeting = "Hello"
age = 21
```
### 3. Instance variables

Belongs to one instance of a class and starts with a `@` sign.
```ruby
@name = "OneCompiler"
```
### 4. Class variables

Belongs to the entire class and starts with `@@`.

```ruby
@@id = 111
```

## Operators
|Type|Operators|
|----|----|
| Arithmetic Operators| + , - , * , / , % , ** |
| Comparision Operators| == , != , > , >= , < , <= , <=>, .eql?, ===, equal? |
| Bitwise Operators| & , ^ , \| , ^ , ~ , << , >> |
| Logical Operators| && , \|\| , ! , and , or, not|
| Assignment Operators|= , += , -= , *= , /= , %= , **= |
| Ternary Operators | ? :|
| Range Operators | .. , ...|
| Special Operators | defined?, . , :: |

## Arrays

Array is a collection of data items and they no need to be of same type.

```ruby
array_name = Array.new(size)
# or
array_name = Array.new
```
### Example
```ruby
arr = [ "Good", "morning", 9, 5.32 , true]
```
## Hashes

Hashes represents key-value pairs. `=>` is used to assign value to it's key. 

```ruby
hsh = nationalGame = { "Australia" => "Cricket", "Japan" => "Wrestling", "NewZealand" => "Rugby","USA" => "Baseball"}
```

## Conditional Statements

### 1. If

```ruby
if conditional-expression 
    #code
end
```
### 2. If-else

```ruby
if conditional-expression
    #code
else 
    #code
end
```
### 3. Nested If-else

```ruby
if conditional-expression
    #code
elsif conditional-expression
    #code
else 
    #code
end
```

### 4. Case

```ruby
case exp
[when exp [then]
   #code ]...
[else
   #code ]
end
```

## Loops

### 1. For

```ruby
for variable [, variable ...] in range [do]
   #code
end
```

### 2. While

```ruby
while conditional-expression [do]
   #code
end
```

### 3. Until

```ruby
until conditional-expression [do]
   #code
end
```
## Methods

```ruby
def methodName [( [arg [= default]]...[, * arg [, &expr ]])]
   #code  
end 
```
### Example
```ruby
def sum(x , y)
   sum = x+y
   puts "Sum: #{sum}"
end
sum(10,20) # passing parameters to method sum
```
