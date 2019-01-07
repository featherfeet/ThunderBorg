#include <cstdio>
#include <cstring>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/types.h>
#include <stdint.h>
#include "i2c.h"

I2C::I2C(int adaptor) {
	// Open the I2C port.
	char filename[20];
	snprintf(filename, 19, "/dev/i2c-%d", adaptor);
	file = open(filename, O_RDWR);
	if (file < 0) {
		printf("Error while opening I2C port:\n");
		printf("%s\n", strerror(errno));
	}
}

void I2C::change_address(int address) {
	if (ioctl(file, I2C_SLAVE, address) < 0) {
		printf("Error while changing I2C address:\n");
		printf("%s\n", strerror(errno));
	}
}

void I2C::read_bytes(uint8_t *data, int len) {
	int result = read(file, data, len);
	printf("I2C Read: {"); // TODO: Remove this (DBG).
	for (int i = 0; i < len; i++) {
		printf("%#08x, ", data[i]);
	}
	printf("\b\b}\n");
	if (result < 0) {
		printf("Error while reading bytes from I2C:\n");
		printf("%s\n", strerror(errno));
	}
}

void I2C::write_bytes(uint8_t *data, int len) {
	int result = write(file, data, len);
	printf("I2C Write: {"); // TODO: Remove this (DBG).
	for (int i = 0; i < len; i++) {
		printf("%#08x, ", data[i]);
	}
	printf("\b\b}\n");
	if (result < 0) {
		printf("Error while writing bytes to I2C:\n");
		printf("%s\n", strerror(errno));
	}
}

I2C::~I2C() {
	close(file);
}
