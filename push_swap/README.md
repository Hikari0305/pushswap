*This project has been created as part of the 42 curriculum by hyoshida, skawawak.*

## Description

Push_swap is a project focused on sorting algorithms and algorithmic
complexity.

The program uses two stacks named `a` and `b`.

- Stack `a` initially contains a list of integers.
- Stack `b` is initially empty.
- The goal is to sort all integers in ascending order in stack `a`.

The program can use only a restricted set of stack operations, such as
`pa`, `pb`, `ra`, and `rra`. These operations are described in the
[Available Operations](#available-operations) section.

The program prints a sequence of operations that sorts the given integers.
A solution that uses fewer operations is considered more efficient.

To reduce the total number of operations, this implementation provides
three sorting strategies:

- Simple strategy
- Medium strategy
- Complex strategy

The user can explicitly select one of these strategies. When no strategy
is specified, the program runs in Adaptive mode, which automatically
selects a strategy based on how disordered the input is.

Before sorting, the input values are converted into ranks from `0` to
`n - 1` using coordinate compression. This allows the sorting algorithms
to work with normalized values while preserving their relative order.

## Contributors

This project was developed by `hyoshid` and `skawawak`.

- `hyoshid` mainly implemented the core program, including argument
  parsing, stack operations, and the general program structure.
- `skawawak` mainly implemented the sorting algorithms, Adaptive mode,
  and benchmark functionality.

## Instructions

| Command       | Description                                           |
| ------------- | ----------------------------------------------------- |
| `make`        | Builds the `push_swap` executable.                    |
| `make clean`  | Removes object files.                                 |
| `make fclean` | Removes object files and the `push_swap` executable.  |
| `make re`     | Rebuilds the project from scratch.                    |

## Usage

```bash
./push_swap [strategy] [--bench] <integers>
```

The strategy selector and the `--bench` option are optional.

When no strategy selector is specified, the program uses Adaptive mode.

### Examples

Run the program in Adaptive mode:

```bash
./push_swap 3 2 1
```

Select the Simple strategy:

```bash
./push_swap --simple 5 3 1 4 2
```

Select the Medium strategy and enable benchmark output:

```bash
./push_swap --medium --bench 5 3 1 4 2
```

An already sorted input produces no sorting operations:

```bash
./push_swap 1 2 3
```

## Available Operations

| Operation | Description |
| --------- | ----------- |
| `sa` | Swaps the first two elements of stack `a`. Does nothing if stack `a` contains fewer than two elements. |
| `sb` | Swaps the first two elements of stack `b`. Does nothing if stack `b` contains fewer than two elements. |
| `ss` | Executes `sa` and `sb` simultaneously. |
| `pa` | Moves the top element of stack `b` to the top of stack `a`. Does nothing if stack `b` is empty. |
| `pb` | Moves the top element of stack `a` to the top of stack `b`. Does nothing if stack `a` is empty. |
| `ra` | Rotates stack `a` upward. The first element becomes the last element. |
| `rb` | Rotates stack `b` upward. The first element becomes the last element. |
| `rr` | Executes `ra` and `rb` simultaneously. |
| `rra` | Rotates stack `a` downward. The last element becomes the first element. |
| `rrb` | Rotates stack `b` downward. The last element becomes the first element. |
| `rrr` | Executes `rra` and `rrb` simultaneously. |

## Algorithms

Only one strategy selector can be specified at a time.

The complexity values below refer to the number of generated stack
operations, which is the primary performance metric of this project.

| Selector     | Algorithm              | Operation complexity             |
| ------------ | ---------------------- | -------------------------------- |
| `--simple`   | Selection sort         | `O(n²)`                          |
| `--medium`   | Chunk sort             | `O(n√n)`                         |
| `--complex`  | Binary radix sort      | `O(n log n)`                     |
| `--adaptive` | Automatically selected | Depends on the selected strategy |

### Selection Sort

Selection sort works as follows:

1. Find the smallest remaining value in stack `a`.
   After coordinate compression, the first target value is rank `0`.
2. Move the target value to the top of stack `a` using `ra` or `rra`,
   whichever requires fewer operations.
3. Push the target value from stack `a` to stack `b` using `pb`.
4. Repeat the process with the next-smallest value until only two elements
   remain in stack `a`.
5. Compare the remaining two elements and use `ra` if they are not in
   ascending order.
6. Push all elements from stack `b` back to stack `a` using `pa`.

The smallest values are pushed to stack `b` first. Because stack `b`
uses last-in, first-out order, the larger values are returned first.
This results in stack `a` being sorted in ascending order.

### Chunk Sort

Chunk sort works as follows:

1. Divide the values into chunks.
   Both the number of chunks and the maximum size of each chunk are based
   on the ceiling of the square root of the total number of values.
2. Find a value that belongs to the current chunk and is closest to either
   the top or the bottom of stack `a`.
3. Move the target value to the top of stack `a` using `ra` or `rra`,
   whichever requires fewer operations.
4. Push the target value from stack `a` to stack `b` using `pb`.
5. Repeat the process until all values in the current chunk have been
   moved to stack `b`.
6. Continue with the next chunk and repeat the same process until stack
   `a` is empty.
7. Find the largest remaining value in stack `b`.
8. Move the target value to the top of stack `b` using `rb` or `rrb`,
   whichever requires fewer operations.
9. Push the target value from stack `b` back to stack `a` using `pa`.
10. Repeat the process until stack `b` is empty.

Because the values are pushed back to stack `a` from largest to smallest,
the final order of stack `a` is ascending.

### Binary Radix Sort

Binary radix sort processes the compressed values one bit at a time,
starting with the least significant bit.

It works as follows:

1. Check the current bit of the value at the top of stack `a`.
2. If the current bit is `0`, push the value from stack `a` to stack `b`
   using `pb`.
3. If the current bit is `1`, move the value to the bottom of stack `a`
   using `ra`.
4. Repeat the process until every value in stack `a` has been checked for
   the current bit.
5. Push all values from stack `b` back to stack `a` using `pa`.
6. Move to the next bit and repeat the same process.
7. Continue until all bits required to represent the largest rank have
   been processed.

After all required bits have been processed, the values in stack `a` are
sorted in ascending order.

### Adaptive Mode

When no strategy selector is specified, the program runs in Adaptive mode.

Adaptive mode calculates the disorder ratio of the input and selects a
strategy according to the following rules:

| Disorder level | Condition | Selected strategy |
| -------------- | --------- | ----------------- |
| Low | `disorder < 0.2` | Simple |
| Medium | `0.2 <= disorder < 0.5` | Medium |
| High | `disorder >= 0.5` | Complex |

The disorder ratio is calculated by examining every possible pair of
values in stack `a`.

When a larger value appears before a smaller value, that pair is counted
as an inverted pair.

The ratio is calculated as:

```text
number of inverted pairs / total number of pairs
```

A completely sorted input has a disorder ratio of `0`, while a
reverse-sorted input has a disorder ratio of `1`.

However, for small inputs, Selection sort often produces fewer operations
than Chunk sort or Binary radix sort, even when the disorder ratio is
medium or high.

Therefore, when the input contains fewer than 20 elements, the Medium and
Complex strategies internally use Selection sort instead. This threshold
was determined experimentally by comparing the number of generated
operations.

This small-input optimization does not affect the overall asymptotic
complexity of the Medium and Complex strategies because it is applied only
to a fixed range of input sizes.

## Benchmark Mode

The optional `--bench` flag displays additional information about the
sorting process.

```bash
./push_swap --bench 5 3 1 4 2
```

It can also be combined with a strategy selector:

```bash
./push_swap --complex --bench 5 3 1 4 2
```

Sorting operations are printed to standard output, while benchmark
information is printed to standard error.

The benchmark output includes:

- The disorder percentage
- The selected strategy or strategy mode
- The algorithmic complexity
- The total number of generated operations
- The number of times each operation was used

## Input Validation

The program accepts signed integers within the range of the C `int` type.

The program prints `Error` to standard error when:

- An argument is not a valid integer.
- An integer is outside the range of the C `int` type.
- Duplicate integers are provided.
- More than one strategy selector is specified.
- An option is provided without any integers.

When the program is executed without any arguments, it exits without
printing anything.

## Resources

- [push_swapの理解](https://docs.google.com/presentation/d/1hBR9R5TOrpS7cJvRjidt7Yv9Yfc3li5lRuAVypkql9E/edit?usp=sharing)  
  A presentation that helped us understand the purpose and requirements
  of the project. It was created by `smukai`, a student in the 42 Tokyo
  cursus.

- [(Outdated) push swapとは何だったのか](https://qiita.com/42yliu/items/ad2567113de5536d14a1)  
  Although some parts are outdated, this article helped supplement our
  understanding of the project's core ideas.

## Use of Generative AI

We used generative AI as a learning and support tool during this project.

Specifically, we used it for:

- Reviewing our code before submission
- Deepening our understanding of the algorithms through interactive
  conversations
- Improving the clarity and English wording of this README

Generative AI was used only to support our learning and review process.

All implementation, debugging, testing, and final design decisions were
carried out by us.
