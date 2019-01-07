#include <iostream>
#include <chrono>
#include "i2c.h"
#include "thunderborg.h"

using namespace std;

int main(int argc, char *argv[]) {
	I2C i2c(1);
	i2c.change_address(0x19);
	Init(&i2c);
	float batteryReading = GetBatteryReading(&i2c);
	cout << "Battery charge: " << batteryReading << " V" << endl;
	auto start_time = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000; i++) {
		SetMotor1(&i2c, 0.7);
	}
	auto end_time = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = end_time - start_time;
	double duration_count = duration.count();
	cout << duration_count / 1000.0 << " seconds/command" << endl;
	return 0;
}
