## 1. Recursion (`recursion/`)

### Towers of Hanoi

```bash
gcc recursion/tower_of_hanoi.c -o toh
./toh
```

### GCD, brute force and recursive

```bash
gcc recursion/gcd.c -o gcd
./gcd
```

### Matrix addition

```bash
gcc recursion/matrix.c -o matrix
./matrix
```

## 2. Linear and circular queue (`queue.c`)

One driver, two backends. `CAPACITY` is 5 in `headers/queue.h`.

```bash
gcc queue.c data_structures/linear_queue.c -o linearqueue
gcc queue.c data_structures/circular_queue.c -o circularqueue
```

Deleting from the linear queue shifts every remaining element left, which is
`O(n)`. The circular queue moves `front` forward instead and reuses the freed
slot through `% CAPACITY`, so the same delete is `O(1)`.

## 3. Priority queue (`priority_queue.c`)

One driver, two backends. A smaller priority number leaves first.

```bash
gcc priority_queue.c data_structures/heap_priority_queue.c -o heap_pq
gcc priority_queue.c data_structures/linkedlist_priority_queue.c -o ll_pq
```

The heap keeps insert and remove at `O(log n)` and caps out at `CAPACITY`
(100 in `headers/priority_queue.h`). The sorted linked list pays `O(n)` on
insert, returns the head in `O(1)`, and grows until `malloc` fails.
