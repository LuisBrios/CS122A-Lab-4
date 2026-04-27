#include "debounce.h"

void db_init(Debounce *d) {
    d->state = false;
}

bool db_upd(Debounce *d, bool input) {
    if (input && !d->state) {
        d->state = true;
        return true;   
    }
    else if (!input) {
        d->state = false;
    }
    return false;
}