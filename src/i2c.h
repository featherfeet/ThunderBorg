#ifndef I2C_H
#define I2C_H

#include <linux/types.h>
#include <stdint.h>

/**
Class for using I2C ports.
*/
class I2C {
	int file;
	public:
		I2C(int adaptor);
		void change_address(int address);
		void read_bytes(uint8_t *data, int len);
		void write_bytes(uint8_t *data, int len);
		~I2C();
};

#endif
