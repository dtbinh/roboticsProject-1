################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Behaviors/BehaviorBase.cpp \
../Behaviors/GoForward.cpp \
../Behaviors/TurnLeft.cpp \
../Behaviors/TurnRight.cpp \
../Behaviors/TurnToWaypoint.cpp 

OBJS += \
./Behaviors/BehaviorBase.o \
./Behaviors/GoForward.o \
./Behaviors/TurnLeft.o \
./Behaviors/TurnRight.o \
./Behaviors/TurnToWaypoint.o 

CPP_DEPS += \
./Behaviors/BehaviorBase.d \
./Behaviors/GoForward.d \
./Behaviors/TurnLeft.d \
./Behaviors/TurnRight.d \
./Behaviors/TurnToWaypoint.d 


# Each subdirectory must supply rules for building sources it contributes
Behaviors/%.o: ../Behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


