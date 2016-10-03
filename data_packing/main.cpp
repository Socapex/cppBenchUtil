#include "../benchUtil.h"

struct NotPacked {
	char c = 'c';
	long l = 42;
	char a = 'a';
	char b = 'b';
	int i = 42;
	double d = 3.22;
};

struct Packed {
	char c = 'c';
	long l = 42;
	char a = 'a';
	char b = 'b';
	int i = 42;
	double d = 3.22;
} __attribute((packed));

const int qty = 1000000000;
int main (int argc, char** argv)
{
	int temp;
	Packed pack;
	NotPacked npack;

	Bench::title("Iterating over packed data vs non-packed.");
	printf("%d iterations. Packed size : %d bytes, Non-packed size : %d bytes\n",
			qty, sizeof(Packed), sizeof(NotPacked));

	Bench::start();
	for (int i = 0; i < qty; ++i) {
		temp += npack.c;
		temp += npack.l;
		temp += npack.a;
		temp += npack.b;
		temp += npack.i;
		temp += npack.d;
		Bench::clobber();
	}
	Bench::end("Non-Packed Data");

	Bench::start();
	for (int i = 0; i < qty; ++i) {
		temp += pack.c;
		temp += pack.l;
		temp += pack.a;
		temp += pack.b;
		temp += pack.i;
		temp += pack.d;
		Bench::clobber();
	}
	Bench::end("Packed Data");

	printf("%d", temp);
	return 0;
}
