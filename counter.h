#ifndef COUNTER_H
#define COUNTER_H

typedef struct {
    int val;
} Counter;

void counter_init(Counter *c);
void counter_inc(Counter *c);
void counter_dec(Counter *c);

#endif