#import "/template/lib.typ": *

#show: assignment.with(
  title: "Student Database with a Doubly Linked List",
  number: "Assignment 02",
  kind: "Lab",
  keywords: ("doubly linked list", "CRUD", "menu driven", "C"),
)

= Aim

A menu driven student database built on a doubly linked list. It inserts a
record at either end or at a chosen position, updates and deletes records,
searches by id, swaps two records, and lists them all.

= Data Structure

Each `DLLNode` holds a `void *data` pointer and links to its `next` and `prev`
neighbours, so the list stays generic. The `DLL` header keeps `head`, `tail`,
and `size`, which makes both ends reachable in constant time. Each `Student`
gets its own allocation, and a node reaches it through the `data` pointer.

= Algorithm

+ *Insert front / back.* Splice a new node at the matching end, updating `head`
  or `tail`.
+ *Insert at position $k$.* Reject $k$ outside $[1, "size" + 1]$, then walk to the
  $(k-1)$th node and splice before it.
+ *Find.* Scan from `head` and match on `id`. IDs are unique, since insertion
  rejects a duplicate before allocating.
+ *Update.* Locate the node, then edit its fields in place through a sub-menu.
+ *Delete.* Locate the node, unlink it by repairing the neighbour and
  `head`/`tail` pointers, then free the payload and the node.
+ *Swap.* Exchange the two nodes' `data` pointers rather than relinking.

Since the list stores `head`, `tail`, and each node's `prev` link, the
primitives run in constant time, except a positional insert, which walks to the
index. The menu handlers add an $O(n)$ id lookup on top of these.

#figure(
  table(
    columns: (auto, auto),
    align: (left, center),
    [DLL operation], [Time],
    [`dll_push_front` / `dll_push_back`], [$O(1)$],
    [`dll_insert_at`], [$O(n)$],
    [`dll_unlink`], [$O(1)$],
    [`dll_swap`], [$O(1)$],
  ),
  caption: [Cost of the doubly linked list primitives.],
)

= Program

== Headers

`dll.h` declares the node, the list, and the list primitives. `student.h`
declares the `Student` record and the menu handlers.

#code(read("src/headers/dll.h"), file: "dll.h")

#code(read("src/headers/student.h"), file: "student.h")

#pagebreak()

== Doubly linked list - `dll.c`

`create_node` is the single allocation point. `dll_push_front` and
`dll_push_back` handle the empty list as a special case, then link the new node
at the corresponding end. `dll_insert_at` routes the boundary indices to those
two and walks the list only for an interior index. `dll_unlink` fixes the four
affected pointers and frees the node, while `dll_swap` trades the two payloads.

#code(read("src/dll.c"), file: "dll.c")

#pagebreak()

== Student operations - `functions.c`

`prepare_student` reads one record and refuses a duplicate id before allocating.
`find_node` backs every lookup. The insert, update, delete, find, and swap
handlers wrap the list primitives and report the outcome.

#code(read("src/functions.c"), file: "functions.c")

#pagebreak()

== Driver - `main.c`

The driver creates the list, then loops on the menu until option 9. Each choice
dispatches to one handler.

#code(read("src/main.c"), file: "main.c")

= Output

#figure(
  image("assets/01-compile.png", width: 90%),
  caption: [Compiling the three sources into `student`.],
)

#figure(
  image("assets/02-empty-list.png", width: 80%),
  caption: [Option 8 on an empty list.],
)

#figure(
  image("assets/03-insert-front-duplicate.png", width: 80%),
  caption: [Insert at the front (id 1); a repeated id is then rejected.],
)

#figure(
  image("assets/04-insert-end.png", width: 80%),
  caption: [Insert at the end (id 2).],
)

#figure(
  image("assets/05-print-two.png", width: 80%),
  caption: [Listing after the two inserts.],
)

#figure(
  image("assets/06-insert-at-position.png", width: 80%),
  caption: [Insert at position 2 (id 3).],
)

#figure(
  image("assets/07-print-three.png", width: 80%),
  caption: [Listing after the positional insert.],
)

#figure(
  image("assets/08-swap.png", width: 80%),
  caption: [Swapping ids 3 and 2, then listing.],
)

#figure(
  image("assets/09-find.png", width: 80%),
  caption: [Finding id 1.],
)

#figure(
  image("assets/10-update.png", width: 80%),
  caption: [Updating the marks of id 1.],
)

#figure(
  image("assets/11-print-updated.png", width: 80%),
  caption: [Listing after the update.],
)

#figure(
  image("assets/12-delete.png", width: 80%),
  caption: [Deleting id 3, then listing.],
)

#figure(
  image("assets/13-invalid-exit.png", width: 80%),
  caption: [An invalid choice, then exit.],
)
