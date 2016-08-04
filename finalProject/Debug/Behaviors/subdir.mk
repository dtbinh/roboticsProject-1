################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Behaviors/behavior.cpp \
../Behaviors/move_forward.cpp \
../Behaviors/move_to_way_point.cpp \
../Behaviors/turn_left.cpp \
../Behaviors/turn_right.cpp 

OBJS += \
./Behaviors/behavior.o \
./Behaviors/move_forward.o \
./Behaviors/move_to_way_point.o \
./Behaviors/turn_left.o \
./Behaviors/turn_right.o 

CPP_DEPS += \
./Behaviors/behavior.d \
./Behaviors/move_forward.d \
./Behaviors/move_to_way_point.d \
./Behaviors/turn_left.d \
./Behaviors/turn_right.d 


# Each subdirectory must supply rules for building sources it contributes
Behaviors/%.o: ../Behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


