#!/bin/sh

mkdir tmp

echo "# Minix Process Scheduler Tests"

# STAGE 1
echo
echo "## Stage 1"
echo
echo "This first stage runs 4 cpu bound processes at the same time, all with the same niceness."

for i in 1 2 3
do
	(time ./cpu_sim_quiet 1&) >tmp/$i.out 2>tmp/$i.err 
done

(time ./cpu_sim_quiet 1) >tmp/4.out 2>tmp/4.err 

sleep 2

for i in 1 2 3 4
do
	echo
	echo "Process $i"
	cat tmp/$i.out
	cat tmp/$i.err
done

# STAGE 2

# First make temporary files

echo
echo "## Stage 2"
echo
echo "Generates random data files and runs the IO tests on them."

for i in 1 2 3 4
do
	dd if=/dev/random of=tmp/t$i.data bs=1048576 count=10 2>/dev/null
done

for i in 1 2 3
do
	(time ./io_sim_quiet tmp/t$i.data tmp/o$i.data&) >tmp/$i.out 2>tmp/$i.err 
done

(time ./io_sim_quiet tmp/t4.data tmp/o4.data) >tmp/4.out 2>tmp/4.err 

sleep 2

for i in 1 2 3 4
do
	echo
	echo "Process $i"
	cat tmp/$i.out
	cat tmp/$i.err
done

# STAGE 3

echo
echo "## Stage 3"
echo
echo "Process 2 runs with half the tickets of process 1."

(time ./cpu_sim_quiet 10&) >tmp/1.out 2>tmp/1.err 
(time nice -n -10 ./cpu_sim_quiet 10) >tmp/2.out 2>tmp/2.err 

sleep 2

for i in 1 2
do
	echo
	echo "Process $i"
	cat tmp/$i.out
	cat tmp/$i.err
done

# STAGE 4 

echo
echo "## Stage 4"
echo
echo "Process 1 has 1 ticket, process 2 has 20, and process 3 has 40 tickets."

(time nice -n -19 ./cpu_sim_quiet 10&) >tmp/1.out 2>tmp/1.err 
(time ./cpu_sim_quiet 10&) >tmp/2.out 2>tmp/2.err 
(time nice -n 20 ./cpu_sim_quiet 10) >tmp/3.out 2>tmp/3.err 

sleep 2

for i in 1 2 3
do
	echo
	echo "Process $i"
	cat tmp/$i.out
	cat tmp/$i.err
done

rm -r tmp

