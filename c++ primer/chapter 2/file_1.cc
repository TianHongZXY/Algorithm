int f(){return 99;}
// To share a const obj among multiple files, you must define the variable as extern.
extern const int F = f();
