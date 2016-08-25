# ringbuff
This is a simple library to be included in your C/C++ projects to provide ring buffer capability to your system. ring buffer or circular buffer is widely useful in applications involving driver development.

## Documentation
### Functions
#### rbuff_init(rbuff_t *r, uint8_t *a, uint16_t size)
###### Initialize the ring buffer
### Parameters
* r------>ring buffer structure 
* a------>a array to hold the data in the ringbuffer
* size--->size of the ring buffer

#### uint16_t rbuff_read(rbuff_t *r, uint8_t *out , uint16_t len)
###### read from ring buffer
### Parameters
* r------>ring buffer structure 
* out------>buffer to hold read data
* len------>size to be read from ringbuffer
* return------>number of actual bytes read

#### uint16_t rbuff_write(rbuff_t *r, uint8_t *in, uint16_t size)
###### write in to the ring buffer
### Parameters
* r------>ring buffer structure 
* in------>buffer holding data to be written in to ring buffer
* size------>size to be read from ringbuffer
* return------>number of actual bytes written

### Usage
```c
uint8_t holder[256];
rbuff_t r;
rbuff_t *r_ptr = &r;

/**initialize the ring buffer*/
rbuff_init(r_ptr, holder, 256);

/**write in to ring buffer*/
uint8_t data[] = {0x11,0x22,0x33,0x44};
rbuff_write(r_ptr, data, 4)

/**read from ring buffer*/
rbuff_read(r_ptr, data, 4)
