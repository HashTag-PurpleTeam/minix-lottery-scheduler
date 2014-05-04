run: build
	chmod u+x run_tests.sh
	./run_tests.sh >test_results.md

build: cpu_sim_quiet io_sim cpu_sim io_sim_quiet

cpu_sim_quiet: cpu_sim_quiet.c
	cc -O0 -o cpu_sim_quiet cpu_sim_quiet.c

io_sim_quiet: io_sim_quiet.c
	cc -O0 -o io_sim_quiet io_sim_quiet.c

io_sim: io_sim.c
	cc -O0 -o io_sim io_sim.c

cpu_sim: cpu_sim.c
	cc -O0 -o cpu_sim cpu_sim.c

clean:
	rm cpu_sim io_sim cpu_sim_quiet io_sim_quiet
