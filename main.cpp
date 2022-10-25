#include "var.h"


void test() {
	// finish your code here
	var flag;
	var val;
	val.input();
	
	val.greater_eq('0', flag);		// flag = (val >= '0');
	flag.if_begin();				// if(flag == true)
	val.greater('9', flag);			// flag = (val > '9);
	flag.flip();					// flag = !flag
	flag.if_end();
	flag.output_ascii();
}



int main(void) {
	freopen("tmp.bf", "w", stdout);
	test();

#ifndef __linux__
	freopen("CON", "w", stdout);
#else
	freopen("/dev/tty", "w", stdout);
#endif
	
	FILE* fin = fopen("tmp.bf", "r");
	FILE* fout = fopen("out.bf", "w");
	optimize(fin, fout);
	
	printf("code is generated in out.bf\n");
	if (remove("tmp.bf") != 0) {
		perror("remove");
	}
	return 0;
}