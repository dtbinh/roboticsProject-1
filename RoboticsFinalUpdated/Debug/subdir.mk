################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AvoidObstaclesPlan.cpp \
../ConfigurationManager.cpp \
../LocalizationManager.cpp \
../Location.cpp \
../Main.cpp \
../Map.cpp \
../Matrix.cpp \
../Particle.cpp \
../Position.cpp \
../Robot.cpp \
../Utils.cpp \
../lodepng.cpp 

OBJS += \
./AvoidObstaclesPlan.o \
./ConfigurationManager.o \
./LocalizationManager.o \
./Location.o \
./Main.o \
./Map.o \
./Matrix.o \
./Particle.o \
./Position.o \
./Robot.o \
./Utils.o \
./lodepng.o 

CPP_DEPS += \
./AvoidObstaclesPlan.d \
./ConfigurationManager.d \
./LocalizationManager.d \
./Location.d \
./Main.d \
./Map.d \
./Matrix.d \
./Particle.d \
./Position.d \
./Robot.d \
./Utils.d \
./lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


