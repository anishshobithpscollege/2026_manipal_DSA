#import "/template/lib.typ": *
#import "@preview/codly:1.3.0" as codly

#show: assignment.with(
  title: "Linked Lists, Stacks, and a Student Database",
  number: "Assignment 01",
  kind: "Theory",
  keywords: ("singly linked list", "stack", "array list", "C"),
)

// A captured terminal session: shown as a plain block with no line numbers,
// so it reads as output rather than source.
#let terminal(path) = codly.local(number-format: none)[
  #raw(read(path), lang: "text", block: true)
]

= Singly linked list with adjacent-node swap

This program keeps a singly linked list of integers and swaps its nodes in
adjacent pairs. A `Node` holds an `int data` and a `next` link, and one `head`
pointer names the list. `push_back` walks to the last node before appending, so
an insert costs $O(n)$: there is no tail pointer to shortcut the walk.

The swap rewires the links themselves and leaves the stored values untouched. A
dummy node sits before `head`, which spares the first pair a special case. For
each pair the code takes `first` and
`second = first->next`, rewires `first->next = second->next`, `second->next =
first`, and `prev->next = second`, then advances `prev` two nodes. A list
$a, b, c, d$ becomes $b, a, d, c$. When the count is odd the final node has no
partner and stays in place.

#figure(
  table(
    columns: (auto, auto),
    align: (left, center),
    [Operation], [Time],
    [`push_back`], [$O(n)$],
    [`swap_adjacent` (one pass)], [$O(n)$],
    [`display`], [$O(n)$],
  ),
  caption: [Cost of the list operations.],
)

== Implementation

#code(read("1st/main.c"), file: "main.c")

== Output

Compiled with `gcc main.c -o list` and run. Five values are inserted, listed,
swapped in pairs, then listed again. The odd tail `50` keeps its position.

#terminal("1st/output.txt")

#pagebreak()

= Stack using a linked list

The stack is built on a singly linked list, so its depth is limited only by
available memory. The `top` pointer plays the role of the stack pointer. `push` links a new node in front of `top`, and `pop` unlinks the front
node and frees it, reporting underflow when the stack is empty. `peek` reads the
top without removing it, and `display` walks from `top` to the base.

Because every change happens at the front, the three stack operations run in
constant time. Only `display` is linear, since it visits each node.

#figure(
  table(
    columns: (auto, auto),
    align: (left, center),
    [Operation], [Time],
    [`push`], [$O(1)$],
    [`pop`], [$O(1)$],
    [`peek`], [$O(1)$],
    [`display`], [$O(n)$],
  ),
  caption: [Cost of the stack operations.],
)

== Implementation

#code(read("2nd/main.c"), file: "main.c")

== Output

Compiled with `gcc main.c -o stack` and run. Three values are pushed, so the
list shows them in reverse insertion order. `peek` then `pop` both act on the
top, `30`.

#terminal("2nd/output.txt")

#pagebreak()

= Student database: array list versus linked list

Student records here sit behind one interface with two interchangeable back
ends. `student.h` declares the record and the store
operations: `store_add`, `store_remove`, `store_update`, `store_get`,
`store_display`, and the `store_load` / `store_save` pair that persists the
records to a CSV file. `main.c` is the shared, menu driven driver. It links
against exactly one back end, either the array list in `arraylist.c` or the
singly linked list in `sll.c`, without any change to the driver.

The array list keeps the records in one contiguous block and doubles the block
when it fills, so an append is amortised $O(1)$; a remove shifts every later
element down by one. The linked list keeps `head` and `tail` pointers, so an
append is $O(1)$ and a remove only unlinks a node. Both reject a duplicate roll
number, and that check scans the whole store, which makes every operation
linear overall.

#figure(
  table(
    columns: (auto, auto, auto),
    align: (left, center, center),
    [Operation], [Array list], [Linked list],
    [Find / get], [$O(n)$], [$O(n)$],
    [Add (rejects duplicate)], [$O(n)$], [$O(n)$],
    [Remove], [$O(n)$, shifts elements], [$O(n)$, unlinks node],
    [Update], [$O(n)$], [$O(n)$],
  ),
  caption: [Cost of the store operations for each back end.],
)

== Interface: `student.h`

#code(read("3rd/headers/student.h"), file: "student.h")

== Array list back end: `arraylist.c`

`grow` doubles the buffer through `realloc` once it is full. `find_index` is the
linear scan behind every lookup, `store_add` appends after the duplicate check,
and `store_remove` closes the gap by shifting the tail down.

#code(read("3rd/src/arraylist.c"), file: "arraylist.c")

#pagebreak()

== Linked list back end: `sll.c`

The same interface over a list with `head`, `tail`, and `size`. `find_node`
walks the list for each lookup, `store_add` appends at the tail, and
`store_remove` finds the node, repairs its neighbour, and fixes `tail` when the
last node goes.

#code(read("3rd/src/sll.c"), file: "sll.c")

#pagebreak()

== Driver: `main.c`

The driver loads the CSV on start, dispatches each menu choice to a handler, and
saves on exit. `read_student` reads one record, taking the name with `fgets` so
it may contain spaces.

#code(read("3rd/src/main.c"), file: "main.c")

== Output

Built as `gcc main.c arraylist.c -o arraylist` and run against a file holding one
record. The session lists the records, adds a student, finds and updates it, and
removes the loaded record. The linked list build, `gcc main.c sll.c -o sll`,
produces the same transcript, since it shares the driver.

#terminal("3rd/output.txt")
