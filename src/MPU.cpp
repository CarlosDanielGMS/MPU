#include "MPU.h"
#include <Wire.h>

void MPU::changeRegister(int address, int value)
{
    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(address);
    Wire.write(value);
    Wire.endTransmission();
}

int MPU::readRegister(int address)
{
    Wire.beginTransmission(MPU_ADDRESS);
    Wire.write(address);
    Wire.endTransmission();

    Wire.requestFrom(MPU_ADDRESS, 1);
    return Wire.read();
}

void MPU::initialize()
{
    Wire.begin();
    
    changeRegister(PWR_MGMT_1_REGISTER, 0b00000000);
    changeRegister(PWR_MGMT_2_REGISTER, 0b00000000);
}

int MPU::readAccelerometerXAxis()
{
    return readRegister(ACCEL_XOUT_H_REGISTER) << 8 | readRegister(ACCEL_XOUT_L_REGISTER);
}

int MPU::readAccelerometerYAxis()
{
    return readRegister(ACCEL_YOUT_H_REGISTER) << 8 | readRegister(ACCEL_YOUT_L_REGISTER);
}

int MPU::readAccelerometerZAxis()
{
    return readRegister(ACCEL_ZOUT_H_REGISTER) << 8 | readRegister(ACCEL_ZOUT_L_REGISTER);
}

void MPU::readAccelerometer(int *xAxis, int *yAxis, int *zAxis)
{
    *xAxis = readAccelerometerXAxis();
    *yAxis = readAccelerometerYAxis();
    *zAxis = readAccelerometerZAxis();
}

int MPU::readTemperature()
{
    return readRegister(TEMP_OUT_H_REGISTER) << 8 | readRegister(TEMP_OUT_L_REGISTER);
}

int MPU::readGyroscopeXAxis()
{
    return readRegister(GYRO_XOUT_H_REGISTER) << 8 | readRegister(GYRO_XOUT_L_REGISTER);
}

int MPU::readGyroscopeYAxis()
{
    return readRegister(GYRO_YOUT_H_REGISTER) << 8 | readRegister(GYRO_YOUT_L_REGISTER);
}

int MPU::readGyroscopeZAxis()
{
    return readRegister(GYRO_ZOUT_H_REGISTER) << 8 | readRegister(GYRO_ZOUT_L_REGISTER);
}

void MPU::readGyroscope(int *xAxis, int *yAxis, int *zAxis)
{
    *xAxis = readGyroscopeXAxis();
    *yAxis = readGyroscopeYAxis();
    *zAxis = readGyroscopeZAxis();
}

void MPU::disableAccelerometer()
{
    changeRegister(PWR_MGMT_2_REGISTER, 0b00100000);
}

void MPU::disableTemperature()
{
    changeRegister(PWR_MGMT_1_REGISTER, 0b00001000);
}

void MPU::disableGyroscope()
{
    changeRegister(PWR_MGMT_2_REGISTER, 0b00000111);
}

void MPU::enableInterruption()
{
    changeRegister(MOT_THR_REGISTER, 0b00000001);
    changeRegister(MOT_DUR_REGISTER, 0b00000001);
    changeRegister(INT_ENABLE_REGISTER, 0b01000000);
}