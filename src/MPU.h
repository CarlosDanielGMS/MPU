#ifndef MPU_H
#define MPU_H

#define MPU_ADDRESS 0x68

#define MOT_THR_REGISTER 0x1F
#define MOT_DUR_REGISTER 0x20
#define INT_ENABLE_REGISTER 0x38

#define ACCEL_XOUT_H_REGISTER 0x3B
#define ACCEL_XOUT_L_REGISTER 0x3C
#define ACCEL_YOUT_H_REGISTER 0x3D
#define ACCEL_YOUT_L_REGISTER 0x3E
#define ACCEL_ZOUT_H_REGISTER 0x3F
#define ACCEL_ZOUT_L_REGISTER 0x40

#define TEMP_OUT_H_REGISTER 0x41
#define TEMP_OUT_L_REGISTER 0x42

#define GYRO_XOUT_H_REGISTER 0x43
#define GYRO_XOUT_L_REGISTER 0x44
#define GYRO_YOUT_H_REGISTER 0x45
#define GYRO_YOUT_L_REGISTER 0x46
#define GYRO_ZOUT_H_REGISTER 0x47
#define GYRO_ZOUT_L_REGISTER 0x48

#define PWR_MGMT_1_REGISTER 0x6B
#define PWR_MGMT_2_REGISTER 0x6C

class MPU
{
private:
  void changeRegister(int, int);
  int readRegister(int);

public:
  void initialize();

  int readAccelerometerXAxis();
  int readAccelerometerYAxis();
  int readAccelerometerZAxis();
  void readAccelerometer(int *, int *, int *);

  int readTemperature();

  int readGyroscopeXAxis();
  int readGyroscopeYAxis();
  int readGyroscopeZAxis();
  void readGyroscope(int *, int *, int *);
  
  void disableAccelerometer();
  void disableTemperature();
  void disableGyroscope();

  void enableInterruption();
};

#endif