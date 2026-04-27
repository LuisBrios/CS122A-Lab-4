#include "counter.h"

void counter_init(Counter *c) {
    c->val = 0;
}

void counter_inc(Counter *c) {
    if (c->val == 15) {
        c->val = 0;
    } else {
        c->val++;
    }
}

void counter_dec(Counter *c) {
    if (c->val == 0) {
        c->val = 15;
    } else {
        c->val--;
    }
}