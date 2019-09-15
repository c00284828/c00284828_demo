

# export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:log_path=/home/ch3ng/demo/asan.log:suppressions=$SUPP_FILE

all:
	gcc -g main.c -fsanitize=address -g1 -o main
	$(shell export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:suppressions=$SUPP_FILE)
	./main
