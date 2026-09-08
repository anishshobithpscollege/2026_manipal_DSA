#import "/template/lib.typ": *

#show: assignment.with(
  title: "Priority Queues",
  number: "Assignment 05",
  kind: "Lab",
  date: datetime(year: 2026, month: 9, day: 8),
  keywords: ("queue", "priority queue", "heap"),
)

= Aim

The assignment builds one priority queue with two backends behind a single
driver, a binary heap and a sorted linked list. Every container stores
`void *`, so the structure holds a pointer and never looks at what it points
to.

= Priority Queue

A priority queue hands back the most urgent element rather than the oldest one.
Each element carries an `int priority` alongside its `void *`, and a smaller
number means the element leaves first, so priority 1 outranks priority 5.
`removeHighest` and `peak` both take an `int *`, so the caller learns the
priority of the element it gets back.

- *Binary heap.* An `Entry { dataElement data; int priority; }` array holding a
  complete binary tree in level order. The children of index $i$ sit at
  $2i + 1$ and $2i + 2$, and the parent at $(i - 1) \/ 2$. Insert appends at the
  end and walks the entry up while its parent is less urgent. Remove takes index
  0, moves the last entry into the hole, and walks it down toward whichever
  child is more urgent.
- *Sorted linked list.* A singly linked list kept in priority order, so the head
  is always the answer. Insert walks until it finds the first node with a larger
  priority number and splices in front of it. Remove unlinks and frees the head.

#figure(
  table(
    columns: (auto, auto, auto),
    align: (left, center, center),
    [Operation], [Binary heap], [Sorted linked list],
    [`insert`], [$O(log n)$], [$O(n)$],
    [`removeHighest`], [$O(log n)$], [$O(1)$],
    [`peak`], [$O(1)$], [$O(1)$],
    [`display`], [$O(n)$], [$O(n)$],
  ),
  caption: [Priority queue costs. The heap balances both ends, while the list
    pays on insert to make removal free.],
)

== Header and driver

`priority_queue.h` declares the element, the capacity, and the seven functions
each backend fills in: `init`, `isEmpty`, `isFull`, `insert`, `removeHighest`,
`peak`, and `display`. The driver boxes an int with its priority, and
`printInteger` prints the value with its priority in parentheses, as `10(p1)`.

#code(read("src/headers/priority_queue.h"), file: "priority_queue.h")

#code(read("src/priority_queue.c"), file: "priority_queue.c")

#pagebreak()

== Heap - `heap_priority_queue.c`

`heapifyUp` swaps a new entry with its parent while the parent is less urgent,
so a new minimum climbs to the root. `heapifyDown` compares a node against both
children and sinks it toward the more urgent one. Each walk covers one path of a
complete tree, so both stop after $log_2 n$ steps.

#code(read("src/data_structures/heap_priority_queue.c"), file: "heap_priority_queue.c")

== Sorted linked list - `linkedlist_priority_queue.c`

Insert has two cases. An empty list or a new highest priority takes the front
branch and becomes the head. Anything else walks forward while the next node is
at least as urgent, using `<=` so equal priorities queue behind the ones already
there. `isFull` returns 0, since the list stops only when `malloc` does.

#code(read("src/data_structures/linkedlist_priority_queue.c"), file: "linkedlist_priority_queue.c")

= Output

== Priority queue with a heap

Five inserts arrive in scrambled priority order. The display prints level order
rather than sorted order, so `40(p5)` sits ahead of `30(p2)`, and `peak` still
reports `10(p1)`. The removals then drain in priority order down to underflow.

#transcript(read("outputs/heap_priority_queue.txt"))

#pagebreak()

== Priority queue with a sorted linked list

The same session runs against the list. Removal order matches the heap, and
here the display matches it too, with `10(p1)` ahead of `20(p1)` because equal
priorities keep their insertion order.

#transcript(read("outputs/linkedlist_priority_queue.txt"))
