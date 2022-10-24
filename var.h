#ifndef _var
#define _var

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
#include <cstdio>
#include <cstdint>
#include <stack>
#include <vector>

class var;

extern int8_t pool[3000];
extern int cur_data_ptr;
extern int cur_var_num;
extern std::stack<var*> if_flag_stack;


class var {
    int8_t data;
    int pool_index;

public:
    // var index starts from 1
    // pool[0] is a helper unit
    var(const int8_t d = 0);

    var(var& another);

    // output the value in this unit
    void output();

    // place the input value in this unit
    void input();

    void test_output();

    void output_ascii();

    void increment(int d = 1);

    void decrement(int d = 1);

    void while_begin();

    void while_end();

    void copy(var& another);

    void move_to(var& another);

    void clear();

    void set(const uint8_t v);

    void if_begin();

    void if_end();

    void to_bool();

    void flip();

    void is_negative(var& result);

    void greater(var& another, var& result);

    void equal(var& another, var& ret);

    void add(var& another, var& ret);

    void minus(var& another, var& ret);

    void multiply(var& another, var& ret);

    void divide(var& another, var& ret);

    void swap(var& another);
};

void test_output(int index = cur_data_ptr);

void optimize(FILE*, FILE*);

#endif
