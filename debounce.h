#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include <stdbool.h>

typedef struct {
    bool state;
} Debounce;

void db_init(Debounce *d);
bool db_upd(Debounce *d, bool input);

#endif