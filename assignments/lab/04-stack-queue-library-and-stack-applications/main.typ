#import "/template/lib.typ": *

#show: assignment.with(
  title: "Stack/Queue Library and Stack Applications",
  number: "Assignment 04",
  kind: "Lab",
  keywords: ("stack", "queue", "generic", "expression parsing", "C"),
)

= Aim

The assignment has two halves. First, a stack and queue library with one
interface and four backends behind it, generic over the element so a container
holds a pointer to anything. Second, three programs that lean on the stack half
of that library: checking whether brackets balance, turning an infix expression
into postfix, and evaluating a postfix expression.

= Data Structures

The library element is `void *`, so a container stores a pointer and never
looks at what it points to. `data_element.h` fixes that type, the capacity, and
the seven functions every backend fills in: `init`, `isEmpty`, `isFull`,
`push`, `pop`, `peak`, and `display`. `display` takes a print callback, since a
container cannot format an element it never understood.

Four backends sit behind that interface, and the caller picks one at link time.

- *Array stack.* `dataElement items[CAPACITY]` with a `top` index that starts at
  $-1$ and points at the last value pushed.
- *Linked-list stack.* A singly linked list where `top` is the head, so a push
  is one `malloc` and nothing caps the size.
- *Array queue.* The same fixed array read as a ring, with `front` and a running
  `count`. `indexAt` wraps an offset with `% CAPACITY`, so a slot freed at the
  front comes back into use.
- *Linked-list queue.* A singly linked list holding `head` and `tail`, appending
  at the tail and removing at the head.

#figure(
  table(
    columns: (auto, auto, auto),
    align: (left, center, center),
    [Primitive], [Array], [Linked list],
    [`push`], [$O(1)$], [$O(1)$],
    [`pop`], [$O(1)$], [$O(1)$],
    [`peak`], [$O(1)$], [$O(1)$],
    [`display`], [$O(n)$], [$O(n)$],
  ),
  caption: [Cost of the library primitives, the same across all four backends.],
)

= Program

== Headers

`data_element.h` declares the generic element, the capacity, and the container
interface. `common.h` declares the helper layer: the int boxing, the menu loop,
and the predicates the programs share for bracket matching, operator precedence,
and one arithmetic step.

#code(read("src/headers/data_element.h"), file: "data_element.h")

#code(read("src/headers/common.h"), file: "common.h")


== Library driver - `main.c`

The driver runs the library on its own with plain integers. Insert boxes an int
and pushes the pointer, remove pops one and frees it, and display hands
`printInteger` to the container as the callback. It names no backend, so the same
file links against all four.

#code(read("src/main.c"), file: "main.c")


== Array stack - `array_stack.c`

`top` marks the last value pushed. Push guards on `isFull`, pop guards on
`isEmpty`, and display counts down from `top`.

#code(read("src/data_structures/array_stack.c"), file: "array_stack.c")


== Linked-list stack - `linkedlist_stack.c`

Each push allocates a node and points it at the old top, so the head always
holds the most recent value. Pop frees the head. `isFull` returns 0 every time.

#code(read("src/data_structures/linkedlist_stack.c"), file: "linkedlist_stack.c")


== Array queue - `array_queue.c`

`indexAt` folds a logical offset onto the array with a modulo. Push writes at
`count`, pop reads at `front` and moves it forward, so a run of inserts and
removes cycles around the array instead of running off the end.

#code(read("src/data_structures/array_queue.c"), file: "array_queue.c")

#pagebreak()

== Linked-list queue - `linkedlist_queue.c`

`head` and `tail` keep both ends one hop away. Push links a node onto `tail`, pop
unlinks at `head` and resets `tail` when the last value leaves.

#code(read("src/data_structures/linkedlist_queue.c"), file: "linkedlist_queue.c")


== Shared helpers - `common.c`

This file carries everything the three programs reuse. `pushInt`, `popInt`, and
`peekInt` box integers over the pointer container, and `clearStack` frees the
rest. `runMenu` is the loop each program shares. The predicates decide what is
an opener, what is a closer, whether a pair matches, an operator's precedence,
whether the stack top should be popped before the next operator, and how to
apply one operator to two operands.

#code(read("src/utils/common.c"), file: "common.c")


== Balancing of symbols - `balancing_symbols.c`

The scan pushes each opener and pops on each closer, matching the two by type. A
pop from an empty stack, a mismatched pair, or a leftover opener at the end all
mark the expression as not balanced.

#code(read("src/applications/balancing_symbols.c"), file: "balancing_symbols.c")


== Infix to postfix - `infix_to_postfix.c`

Operands go straight to the output. Operators wait on the stack until one of
lower precedence arrives, and a `(` holds its group open until the matching `)`
drains it.

#code(read("src/applications/infix_to_postfix.c"), file: "infix_to_postfix.c")


== Postfix evaluation - `postfix_evaluation.c`

Each digit pushes its value. Each operator pops two operands, applies itself,
and pushes the result, so the stack shrinks toward the single final answer.

#code(read("src/applications/postfix_evaluation.c"), file: "postfix_evaluation.c")

= Output

Each program is compiled against the linked-list stack, then run through its
menu. The two shots per program are the top and the end of one continuous
session, scrolled down.

== Balancing of symbols

#figure(
  image("assets/SCR-20260901-oghu.png", width: 68%),
  caption: [Compiling against the linked-list stack, then `()` balances and `{(())}]` reports the extra `]`.],
)

#figure(
  image("assets/SCR-20260901-ogoy.png", width: 68%),
  caption: [`{(())}` and `{(())}[]` balance, `[{(` leaves openers unclosed, then exit.],
)


== Infix to postfix

#figure(
  image("assets/SCR-20260901-okzf.png", width: 68%),
  caption: [`2+4/5*(5-3)^5^4` becomes `245/53-54^^*+`, with `^` binding to the right.],
)

#figure(
  image("assets/SCR-20260901-oktt.png", width: 68%),
  caption: [`abc+*d/` becomes `abcd*/+`, an unsupported `{` is rejected, then exit.],
)


== Postfix evaluation

#figure(
  image("assets/SCR-20260901-oqxh.png", width: 68%),
  caption: [Compiling, then `234*+` gives 14 and `2342^6-*5/+` gives 8.],
)

#figure(
  image("assets/SCR-20260901-orac.png", width: 68%),
  caption: [The same evaluation, then a stray `22+` at the menu is read as an invalid choice and the leftover input ends the loop.],
)
