#include "var.h"

#define print_times(ch,times) for(int i=0;i<(times);i++){putchar(ch);}

int8_t pool[3000];
int cur_data_ptr = 0;
int cur_var_num = 0;

std::stack<var*> if_flag_stack;

// var index starts from 1
// pool[0] is a helper unit
var::var(const int8_t d) {
    assert(pool[0] == 0);
    // if cur_data_ptr is not at #0, reset it as #0
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    data = d;
    pool[cur_var_num + 1] = d;
    pool_index = cur_var_num + 1;
    cur_var_num++;

    printf("++++++++");
    // pool[0] = 8;

    int inner_increment = data / 8;
    putchar('[');
    print_times('>', pool_index);
    print_times('+', inner_increment);
    print_times('<', pool_index);
    putchar('-');
    putchar(']');

    print_times('>', pool_index);
    int outer_increment = data - inner_increment * 8;
    print_times('+', outer_increment);
    print_times('<', pool_index);
    // pool[0] = 0;
    // cur_data_ptr = 0;
    // the data pointer: #0
}

var::var(var& another) {
    assert(&another != this);
    // create a copy
    pool[cur_var_num + 1] = another.data;
    pool_index = cur_var_num + 1;
    cur_var_num++;
    this->copy(another);
}

// output the value in this unit
void var::output() {
    // if cur_data_ptr is not at #0, reset it as #0
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    putchar('.');
    print_times('<', pool_index);
}

// place the input value in this unit
void var::input() {
    // if cur_data_ptr is not at #0, reset it as #0
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    putchar(',');
    print_times('<', pool_index);
    // pool[pool_index] = getchar();
}

void test_output(int index) {
    printf("test output: %c\n", pool[index]);
}

void var::test_output() {
    printf("test output: %c\n", pool[pool_index]);
}

void var::output_ascii() {
    var tmp(*this);
    tmp.increment('0');
    tmp.output();
    tmp.clear();
    cur_var_num--;
}

void var::decrement(int d) {
    // this can be optimized
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    print_times('-', d);
    print_times('<', pool_index);
    pool[pool_index] -= d;
}

void var::increment(int d) {
    // this can be optimized
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    print_times('+', d);
    print_times('<', pool_index);
    pool[pool_index] += d;
}

void var::while_begin() {
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    putchar('[');
    print_times('<', pool_index);
}

// if pc never enters the loop, it's still correct
void var::while_end() {
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    putchar(']');
    print_times('<', pool_index);
}

void var::move_to(var& another) {
    assert(&another != this);
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    printf("[");
    printf("-");
    print_times('<', pool_index);
    print_times('>', another.pool_index);
    printf("+");
    print_times('<', another.pool_index);
    print_times('>', pool_index);
    printf("]");
    print_times('<', pool_index);

    pool[another.pool_index] = pool[pool_index];
    pool[pool_index] = 0;
}

void var::copy(var& another) {
    assert(&another != this);
    // create a temporary unit at the end of the pool
    var tmp;

    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    clear();

    print_times('>', another.pool_index);
    printf("[");
    printf("-");
    print_times('<', another.pool_index);
    print_times('>', pool_index);
    printf("+");
    print_times('<', pool_index);
    print_times('>', tmp.pool_index);
    printf("+");
    print_times('<', tmp.pool_index);
    print_times('>', another.pool_index);
    printf("]");
    print_times('<', another.pool_index);

    tmp.move_to(another);
    tmp.clear();
    cur_var_num--;      // do not keep `tmp`
    // tmp is the last one in pool
}

void var::clear() {
    print_times('<', cur_data_ptr);
    cur_data_ptr = 0;

    print_times('>', pool_index);
    printf("[-]");
    print_times('<', pool_index);
    data = 0;
}

void var::set(const uint8_t v) {
    clear();

    print_times('<', cur_data_ptr);
    printf("++++++++");     // pool[0] = 8;

    int inner_increment = v / 8;
    putchar('[');
    print_times('>', pool_index);
    print_times('+', inner_increment);
    print_times('<', pool_index);
    putchar('-');
    putchar(']');

    print_times('>', pool_index);
    int outer_increment = v - inner_increment * 8;
    print_times('+', outer_increment);
    print_times('<', pool_index);
    // pool[0] = 0;
    // cur_data_ptr = 0;
    // current data pointer: #0
}

void var::to_bool() {
    var tmp(1);

    if_begin();
    set(1);
    tmp.clear();
    if_end();

    tmp.if_begin();
    clear();
    tmp.if_end();

    tmp.clear();
    cur_var_num--;
}

void var::if_begin() {
    // execute when *this is non-zero
    var* flag = new var(*this);     // *flag is a copy of *this

    if_flag_stack.emplace(flag);
    // enter while-loop when *flag is non-zero
    flag->while_begin();
    // make sure only execute once
    flag->clear();
}

void var::if_end() {
    assert(!if_flag_stack.empty());

    var* flag = if_flag_stack.top();
    if_flag_stack.pop();
    
    flag->while_end();
    
    delete flag;
    // flag cannot be easily released in pool
    // for the reason that *flag may not be the last unit
}

void var::flip() {
    // flip a Boolean value
    var tmp(1);

    if_begin();
    clear();
    tmp.clear();
    if_end();

    tmp.if_begin();
    set(1);
    tmp.if_end();

    // release tmp from the pool
    tmp.clear();
    cur_var_num--;
}

void var::is_negative(var& result) {
    assert(&result != this);
    var tmp(127);
    result.clear();
    greater(tmp, result);
    // if (uint8_t)*this is greater than 0x7f,
    // then *this is negative as an unsigned
    tmp.clear();
    cur_var_num--;
}

void var::greater(var& another, var& result) {
    assert(&result != this);
    // `another` can be a reference of *this, that works!
    // return true if (uint8_t)*this > (uint8_t)another
    // assert(this->data >= 0 && another.data >= 0);
    // consider both as unsigned interger, although not always as such
    var tmp1(*this);
    var tmp2(another);
    var tmp3;
    result.clear();

    tmp1.while_begin();

    tmp3.copy(tmp2);
    tmp3.flip();
    tmp3.if_begin();    // when tmp2 is zero and tmp1 isn't zero
    result.set(1);      // the result is true
    tmp3.if_end();

    tmp1.decrement();
    tmp2.decrement();

    tmp1.while_end();

    // delete tmp1, tmp2, tmp3 from the pool
    tmp1.clear();
    tmp2.clear();
    tmp3.clear();
    cur_var_num -= 3;
}

void var::equal(var& another, var& ret) {
    var ret1;
    var ret2;
    this->greater(another, ret1);
    another.greater(*this, ret2);

    ret1.flip();
    ret2.flip();
    ret.clear();

    ret1.if_begin();    // when ret1 == 0 && ret2 == 0
    ret2.if_begin();
    ret.set(1);
    ret2.if_end();
    ret1.if_end();

    // delete ret1, ret2 from the pool
    ret1.clear();
    ret2.clear();
    cur_var_num -= 2;
}

void var::add(var& another, var& ret) {
    var tmp(another);
    ret.copy(*this);
    // tmp is an copy of `another`
     
    tmp.while_begin();
    tmp.decrement();
    ret.increment();
    tmp.while_end();
    cur_var_num--;
}

void var::minus(var& another, var& ret) {
    var tmp(another);
    ret.copy(*this);
    // tmp is an copy of `another`

    tmp.while_begin();
    tmp.decrement();
    ret.decrement();
    tmp.while_end();
    cur_var_num--;
}

void var::multiply(var& another, var& ret) {
    var tmp(another);
    var tt(*this);
    tmp.while_begin();
    tmp.decrement();
    ret.add(*this, tt);     // tt <- ret + *this
    ret.copy(tt);           // ret <- tt
    tmp.while_end();
    tt.clear();
    cur_var_num -= 2;
}

void var::divide(var& another, var& ret) {
    // substract `another` until tmp is no greater than `another`
    // *this and `another` are considered as unsigned int (8 bits)
    var tmp(*this);
    var tt;
    var ttt;
    ret.clear();

    another.greater(tmp, tt);      // tt == (another > tmp)
    tt.flip();                     // tt == (tmp >= another)

    tt.while_begin();              // while tt is true
    ret.increment();               // ret++
    tmp.minus(another, ttt);
    tmp.copy(ttt);                 // tmp = tmp - another
    another.greater(tmp, tt);      // tt == (another > tmp)
    tt.flip();                     // tt == (tmp >= another)
    tt.while_end();

    ttt.clear();
    tmp.clear();
    cur_var_num -= 3;
}

void var::swap(var& another) {
    var tmp(*this);
    copy(another);
    another.copy(tmp);
    tmp.clear();
    cur_var_num--;
}

void optimize(FILE* fin, FILE* fout) {
    assert(fin && fout);
    std::vector<char> S;
    char ch = 0;
    while (fscanf(fin, "%c", &ch) == 1 && !feof(fin)) {
        switch (ch) {
        case '<':
            if (!S.empty() && S.back() == '>') {
                S.pop_back();
            }
            else S.emplace_back(ch);
            break;
        case '>':
            if (!S.empty() && S.back() == '<') {
                S.pop_back();
            }
            else S.emplace_back(ch);
            break;
        default:
            for (auto c : S) {
                fprintf(fout, "%c", c);
            }
            fprintf(fout, "%c", ch);
            S.clear();
        }
    }
    fclose(fin);
    fclose(fout);
    // discard the '<' and '>' at the end
}