#import "/template/lib.typ": *

#show: assignment.with(
  title: "Array Palindrome Check",
  number: "Assignment 01",
  kind: "Lab",
  keywords: ("palindrome", "two pointer", "arrays", "C"),
)

= Aim

Read an array of integers and decide whether it reads the same in both
directions, using the two pointer method in a single pass.

= Algorithm

+ Reject a null array or a non-positive size $n$ with `INVALID_INPUT`.
+ Set $l = 0$ and $r = n - 1$.
+ While $l < r$, compare $A[l]$ with $A[r]$. On a mismatch return
  `NOT_A_PALINDROME`. Otherwise advance $l$ and step $r$ back.
+ When the indices meet with no mismatch, return `IS_A_PALINDROME`.

Time complexity $O(n)$, auxiliary space $O(1)$.

= Program

== Header - `palindrome.h`

#code(read("src/headers/palindrome.h"), file: "palindrome.h")

#pagebreak()

== Core logic - `is_palindrome`

A null pointer or a non-positive size returns `INVALID_INPUT` before the
function reads an element. Past that guard, `left` and `right` walk inward. The
first mismatched pair returns `NOT_A_PALINDROME`. When the indices meet with no
mismatch, every pair matched and the array is a palindrome.

#code(read("src/functions.c"), file: "functions.c", lines: (47, 65))

== Driver - `main.c`

The driver runs the assertions first, then loops on the menu until you exit.
Option 1 reads a size between 1 and `MAX_ARRAY_SIZE`, then fills that many slots
of a fixed buffer. Choose option 2 or 3 before entering anything and the program
sends you back to option 1.

#code(read("src/main.c"), file: "main.c")

= Testing

`assertPalindrome` runs thirteen assertions before the menu appears. They cover
the cases a hand check gets wrong: null and empty inputs, a single element, even
and odd length palindromes, and arrays with negative numbers. A failed assertion
aborts the program, so a broken build never reaches the menu. Every one passes
on the current code.

#code(read("src/functions.c"), file: "functions.c", lines: (67, 94))

= Output

#figure(
  image("assets/pic2.png", width: 90%),
  caption: [Entering and verifying a palindromic array.],
)

#figure(
  image("assets/pic2.png", width: 90%),
  caption: [A run that reports the array is not a palindrome.],
)
