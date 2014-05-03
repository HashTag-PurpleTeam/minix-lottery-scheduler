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
	dd if=/dev/random of=tmp/t$i.data bs=1048576 count=10 >/dev/null
done

for i in 1 2 3
do
	(time ./io_sim_quiet tmp/t$i.data tmp/o$i.data&) >tmp/$i.out 2>tmp/$i.err 
done

(time ./io_sim_quiet tmp/t4.data tmp/o4.data) >tmp/4.out 2>tmp/4.err 

for i in 1 2 3 4
do
	echo
	echo "Process $i"
	cat tmp/$i.out
	cat tmp/$i.err
done

#rm -r tmp
