#include <iostream>
#include "i2c.h"
#include "thunderborg.h"

using namespace std;

int main(int argc, char *argv[]) {
	I2C i2c(1);
	i2c.change_address(I2C_ID_THUNDERBORG);
	Init(i2c);
	return 0;
}
