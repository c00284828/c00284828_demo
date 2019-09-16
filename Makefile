

# export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:log_path=/home/ch3ng/demo/asan.log:suppressions=$SUPP_FILE


#support asan:heap-use-after-free
#support asan:attempting double-free
#support asan:
# -fsanitize-recover=address
	# $(shell export LSAN_OPTIONS=exitcode=0:use_unaligned=4)
all:
	gcc -g main.c -fsanitize=address -fno-omit-frame-pointer -o main
	$(shell export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:suppressions=$SUPP_FILE)
	./main
