## Library demo (`main.c`)

Generic insert / remove / display driver over any one implementation.

```bash
gcc main.c data_structures/array_stack.c -o array_stack
gcc main.c data_structures/linkedlist_stack.c -o linkedlist_stack
gcc main.c data_structures/array_queue.c -o array_queue
gcc main.c data_structures/linkedlist_queue.c -o linkedlist_queue
```

## Applications (`applications/`)

```bash
gcc applications/balancing_symbols.c utils/common.c data_structures/linkedlist_stack.c -o balancing
gcc applications/infix_to_postfix.c utils/common.c data_structures/linkedlist_stack.c -o infix2postfix
gcc applications/postfix_evaluation.c utils/common.c data_structures/linkedlist_stack.c -o postfix_eval

# Any program also works with the array stack (bounded by CAPACITY, currently 100)
gcc applications/balancing_symbols.c applications/common.c data_structures/array_stack.c -o balancing
```
