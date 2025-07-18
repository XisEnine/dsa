# Question list :

- Subsets [x]
- Permutation [x]
- Combination sum [x]

### more to solve:
    - N-Queens
    - Soduko Solver

## Basic Template:

```python

def backtrack(path, choices):
    if is_solution(path):
        process_solution(path)
        return

    for choice in valid_choices(path, choices):
        make_choice(path, choice)
        backtrack(path, choices)
        undo_choice(path, choice)


```
