<div align="center">
	<h1>Push swap</h1>
	<img src="https://raw.githubusercontent.com/alissonmarcs/alissonmarcs/main/images/pipexm.png" alt="Pipex project badge of 42"/>
	<p align="center">We need create a program to sort numbers. We are allowed to use only an specific set of moviments to sort these numbers.</p>
</div>

<div align="center">
	<h2>Final score</h2>
	<img src="https://i.imgur.com/dL7Srhr.png" alt="Project scored with 125/100">
</div>

## How to compile and use

```shell
git clone https://github.com/alissonmarcs/push-swap
cd push-swap
make 
make bonus
```

`./push_swap` is the mandatory project what will sort the numbers.

```shell
./push_swap 9 0 1 5 2 3 10
```

Tip to generate random numbers:

```shell
./push_swap `seq -2500 2500 | shuf -n 10`
```

- `seq -2500 2500` - gerenare an ordened sequence of numbers.
- `shuf -n 10` - capture ten numbers from stdin and randomize these numbers.

`./checker` is the bonus project what will check if the commands that `./push_swap` produces is correct.

```shell

```

## What are rules for sort these numners ?

We have two stacks named `A` and `B`, and we must populate A with numbers received as arguments.