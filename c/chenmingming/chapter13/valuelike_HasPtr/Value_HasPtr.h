#ifndef VALUE_HASPTR_H
#define VALUE_HASPTR_H
class Value_HasPtr {
public:
    Value_HasPtr(const int &p, int i):ptr(new int(p)),val(i){ }
    Value_HasPtr(const Value_HasPtr &orig):ptr(new int(*orig.ptr)),val(orig.val){ }
    Value_HasPtr& operator=(const Value_HasPtr&);
    ~Value_HasPtr() { delete ptr; }
    int get_ptr_val()const { return *ptr; }
    int get_int()const { return val; }
    void set_ptr(int *p) { ptr = p; }
    void set_int(int i) { val = i; }
    int *get_ptr()const { return ptr; }
    void set_ptr_val(int i)const { *ptr = i; }
private:
    int *ptr;
    int val;
};
#endif