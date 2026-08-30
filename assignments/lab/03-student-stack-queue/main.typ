#import "/template/lib.typ": *

#show: assignment.with(
  title: "Student Database with Stacks and Queues",
  number: "Assignment 03",
  kind: "Lab",
  keywords: ("stack", "queue", "array", "linked list", "C"),
)

= Aim

One driver, one record, four backends. The program keeps a small student
database and acts as either a stack or a queue depending on which backend I
link against it. Insert pushes or enqueues, remove pops or dequeues, and display
reads the container out from whichever end it hands records back.

= Data Structures

The record never changes. Every backend stores `Student` values, each holding a
name, roll number, branch, and grade, and exposes the same four functions to
`main.c`: `init`, `insertStudent`, `removeStudent`, and `display`. I choose the
behaviour at compile time by linking one backend file, and the driver never
learns which one it got.

- *Array stack.* `Student items[CAPACITY]` with a `top` index. `top` starts at
  $-1$ and points at the last record pushed.
- *Linked-list stack.* A singly linked list where `top` is the head. Each push
  calls `malloc`, so nothing caps the size.
- *Array queue.* The same fixed array read as a circular buffer, with `front`
  and a running `count`. `indexAt` wraps an offset with `% CAPACITY`, so a slot
  freed at the front comes back into use.
- *Linked-list queue.* A singly linked list holding both `front` and `tail`.
  Enqueue appends at `tail`, dequeue removes at `front`.

= Algorithm

*Stack, LIFO.*
+ *Push.* When the array is full, return failure. Otherwise write the record at
  the new top.
+ *Pop.* When empty, return failure. Otherwise hand back the top record and step
  `top` back by one.
+ *Display.* Read from `top` down to the bottom.

*Queue, FIFO.*
+ *Enqueue.* When the array is full, return failure. Otherwise write the record
  after the last one.
+ *Dequeue.* When empty, return failure. Otherwise hand back the front record
  and move `front` forward.
+ *Display.* Read from `front` to the back.

The two array backends stop at `CAPACITY` and report overflow. The two linked
backends grow on every `malloc` and never overflow. Each operation reaches its
working end through a stored index or pointer, so insert and remove cost the
same no matter how many records sit inside.

#figure(
  table(
    columns: (auto, auto, auto),
    align: (left, center, center),
    [Operation], [Array], [Linked list],
    [`insertStudent` (push / enqueue)], [$O(1)$], [$O(1)$],
    [`removeStudent` (pop / dequeue)], [$O(1)$], [$O(1)$],
    [`display`], [$O(n)$], [$O(n)$],
  ),
  caption: [Cost of each operation, the same across all four backends.],
)

= Program

== Shared header - `student.h`

This declares the `Student` record, the capacity, and the four functions each
backend fills in.

#code(read("src/headers/student.h"), file: "student.h")

== Driver - `main.c`

The driver reads one record, runs the menu, and prints what happened. It calls
`insertStudent` and `removeStudent` without naming any backend, so the same file
links against all four.

#code(read("src/main.c"), file: "main.c")

#pagebreak()

== Array stack - `arraystack.c`

`top` marks the last record pushed. Push guards on `isFull`, pop guards on
`isEmpty`, and display counts down from `top`.

#code(read("src/arraystack.c"), file: "arraystack.c")

#pagebreak()

== Linked-list stack - `linkedliststack.c`

Each push allocates a node and points it at the old top, so the head always
holds the most recent record. Pop frees the head. `isFull` returns 0 every time.

#code(read("src/linkedliststack.c"), file: "linkedliststack.c")

#pagebreak()

== Array queue - `arrayqueue.c`

`indexAt` folds a logical offset onto the array with a modulo. Enqueue writes at
`count`, dequeue reads at `front` and moves it forward, so a run of inserts and
removes cycles around the array instead of running off the end.

#code(read("src/arrayqueue.c"), file: "arrayqueue.c")

#pagebreak()

== Linked-list queue - `linkedlistqueue.c`

`front` and `tail` keep both ends one hop away. Enqueue links a node onto
`tail`, dequeue unlinks at `front` and resets `tail` when the last record
leaves.

#code(read("src/linkedlistqueue.c"), file: "linkedlistqueue.c")

#pagebreak()

= Output

Each backend runs the same session: build it, insert three students, list them,
remove one, then list the rest. The three shots under each backend are the top,
middle, and end of one continuous run, scrolled down. The stacks give back the
record entered last, the queues the record entered first.

== Array stack

#figure(
  image("assets/01-array-stack-a.png", width: 62%),
  caption: [Compiling `arraystack.c`, then pushing three students.],
)

#figure(
  image("assets/01-array-stack-b.png", width: 62%),
  caption: [The three pushes, then a display led by the top of the stack.],
)

#figure(
  image("assets/01-array-stack-c.png", width: 62%),
  caption: [The pop returns the last record pushed, and the next display drops it (LIFO).],
)

#pagebreak()

== Linked-list stack

#figure(
  image("assets/02-linkedlist-stack-a.png", width: 62%),
  caption: [Compiling `linkedliststack.c`, then pushing three students.],
)

#figure(
  image("assets/02-linkedlist-stack-b.png", width: 62%),
  caption: [The pushes, then a display led by the most recent record.],
)

#figure(
  image("assets/02-linkedlist-stack-c.png", width: 62%),
  caption: [The pop returns the most recent record; the nodes sit on the heap, so nothing overflows.],
)

#pagebreak()

== Array queue

#figure(
  image("assets/03-array-queue-a.png", width: 62%),
  caption: [Compiling `arrayqueue.c`, then enqueuing three students.],
)

#figure(
  image("assets/03-array-queue-b.png", width: 62%),
  caption: [The three enqueues, then a display led by the front of the queue.],
)

#figure(
  image("assets/03-array-queue-c.png", width: 62%),
  caption: [The dequeue returns the first record in, and the next display drops it (FIFO).],
)

#pagebreak()

== Linked-list queue

#figure(
  image("assets/04-linkedlist-queue-a.png", width: 62%),
  caption: [Compiling `linkedlistqueue.c`, then enqueuing three students.],
)

#figure(
  image("assets/04-linkedlist-queue-b.png", width: 62%),
  caption: [The enqueues, then a display led by the front record.],
)

#figure(
  image("assets/04-linkedlist-queue-c.png", width: 62%),
  caption: [The dequeue returns the first record in; `front` and `tail` keep it $O(1)$.],
)
