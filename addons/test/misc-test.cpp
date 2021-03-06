// To test:
// ~/cppcheck/cppcheck --dump misc-test.cpp && python ../misc.py -verify misc-test.cpp.dump


// Warn about string concatenation in array initializers..
const char *a[] = {"a" "b"};
const char *b[] = {"a","b" "c"}; // stringConcatInArrayInit
const char *c[] = {
	"a\n"
	"a\n"
	"a\n"
	"a\n"
	"a\n"
	,
	"b\n"
	"b\n"
	"b\n"
	"b\n"
	"b\n"
};


// Function is implicitly virtual
class base {
    virtual void dostuff(int);	
};

class derived : base {
	void dostuff(int); // implicitlyVirtual
};


// Pass struct to ellipsis function
struct {int x;int y;} s;
void ellipsis(int x, ...);
void foo(void) {
    ellipsis(321, s); // ellipsisStructArg
}
