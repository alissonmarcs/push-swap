<div align="center">
	<h1>Push swap</h1>
	<img src="https://i.imgur.com/CYEkMXq.png" alt="Push swap project badge of 42"/>
	<p align="center">We need create a program to sort numbers. We are allowed to use only an specific set of moviments to sort these numbers.</p>
</div>

<div align="center">
	<h2>Final score</h2>
	<img src="https://i.imgur.com/dL7Srhr.png" alt="Project scored with 125/100">
</div>

## How to compile and use

```shell
$ git clone https://github.com/alissonmarcs/push-swap
$ cd push-swap
$ make 
$ make bonus
```

### Mandatory part

`./push_swap` is the mandatory project that will sort the numbers. Example of use:

```shell
$ ./push_swap 2 1
sa
```

`2 1` are the numbers to be sorted, and `sa` is is the movement that the program find out
to sort the sequence. Example of an more complex sequence:

```shell
$ ./push_swap 2 1 3 -1
pb
rra
rra
pa
ra
ra
```

### Explanation of the commands

We have two stacks named `a` and `b` and we must populate `a` with the sequence passed as argument.
We must use the two stacks and the commands in the table bellow to sort the numbers. Of course, we
cannot left numbers in `b` and the sequence in `a` must be sorted.

| Movement | Description                                                    |
|----------|----------------------------------------------------------------|
| sa       | swap two first elements of `a`                                   |
| sb       | swap two first elements of `b`                                   |
| ss       | sa and sb at the same time                                     |
| pa       | take the first of `b` and put it in top of `a`                     |
| pb       | take the first of a and put it in top of `b`                     |
| ra       | shift up all elements of `a` by 1 (the first becomes the last)   |
| rb       | shift up all elements of `b` by 1 (the first becomes the last)   |
| rr       | ra and rb at the same time                                     |
| rra      | shift down all elements of `a` by 1 (the last becomes the first) |
| rrb      | shift down all elements of `b` by 1 (the last becomes the first) |
| rrr      | rra and rrb at the same time                                   |

----

Tip to generate random numbers:

```shell
$ ./push_swap `seq -2500 2500 | shuf -n 10`
```

- `seq -2500 2500` - gerenare an ordened sequence of numbers.
- `shuf -n 10` - capture ten numbers from stdin and randomize these numbers.

---

### Bonus

`./checker` is the bonus project that will check if the commands that
`./push_swap` produces is correct. Example of use:

```shell
$ numbers=$(seq -100 100 | shuf -n 30); ./push_swap $numbers | ./checker $numbers
OK
```

You can also use the checker to try your self to sort an sequence of numbers.
Execute `./checker` with a few numbers and type your commands. When you
are done, type `ctrl + d` to finish the checker.

```shell
$ ./checker 5 4 1 6 9
pb
pb
pb
rrb
pa
rrb
pa
pa
OK
```
