#include "rbuff.h"

static uint8_t rbuff_write_internal(rbuff_t *r, uint8_t c){
     if ( ( (r->write - r->read ) & r->mask ) == r->mask ){
         return 0;
     }  
     r->ptr[r->write] = c;
     r->write = ( r->write + 1 ) & r->mask;
     return 1;
}

static uint8_t rbuff_read_internal(rbuff_t *r, uint8_t *c){
    if ( ( (r->write - r->read ) & r->mask ) > 0 ){
        *c = r->ptr[r->read];
        r->read = ( r->read + 1) & r->mask ;
        return 1;
    }else{
        return 0;
    }
}

void rbuff_init(rbuff_t *r, uint8_t *holder, uint16_t size){
    r->mask = size -1;
    r->ptr = holder;
    r->write = 0;
    r->read = 0;
}

uint16_t rbuff_write(rbuff_t *r, uint8_t *out, uint16_t len){
    uint16_t written = 0;
    while( written != len ){
        if ( rbuff_write_internal(r, *out++) == 0){
            break;
        }
        written++;
    }
    return written;
}
 
uint16_t rbuff_read(rbuff_t *r, uint8_t *in, uint16_t len){
    uint16_t read = 0;
    while ( read != len ){
        if ( rbuff_read_internal ( r, in++) == 0){
            break;
        }
        read++;
    }
    return read;
}
