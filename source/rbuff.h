#ifndef __RING_BUFFER_C__
#define __RING_BUFFER_C__

/**
 * some definitions of data types
 */
 
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;


/** \addtogroup lib
 * @{ */
 
 /**
  * \defgroup ringbuf Ring buffer library
  * @{
  *
  * this is a ring buffer implementation in which bytes can be read 
  * and written independently. A ring buffer is
  * this kind of buffer is particularly useful in low level driver development.
  *
  */

/**
 * @brief      Structure that holds the state of a ring buffer.
 *             This structure holds the state of a ring buffer.
 *
 */ 
#pragma pack(1) 
typedef struct _rbuff_t{
    uint8_t *ptr;
    uint16_t mask;
    uint8_t read;
    uint8_t write;
}rbuff_t;

/**
 * @brief      Initialize the ring buffer
 * @param r    A pointer to a struct ringbuf to hold the state of the ring buffer
 * @param holder    A pointer to an array to hold the data in the buffer
 * @param size The size of the ring buffer
 *
 */
void rbuff_init(rbuff_t *r, uint8_t *holder, uint16_t size);


/**
 * @brief      writes to the ring buffer
 * @param r    A pointer to a struct ringbuf to hold the state of the ring buffer
 * @param out  data buffer holding the data to be written
 * @param len length of data to be written
 *
 */
 uint16_t rbuff_write(rbuff_t *r, uint8_t *out, uint16_t len);
 
/**
 * @brief      reads from the ring buffer
 * @param r    A pointer to a struct ringbuf to hold the state of the ring buffer
 * @param in  data buffer which will hold the data to be read
 * @param len length of data to be read
 *
 */
 uint16_t rbuff_read(rbuff_t *r, uint8_t *in, uint16_t len);



#endif