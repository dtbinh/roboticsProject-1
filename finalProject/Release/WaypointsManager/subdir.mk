################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WaypointsManager/node.cpp \
../WaypointsManager/waypoints_manager.cpp 

OBJS += \
./WaypointsManager/node.o \
./WaypointsManager/waypoints_manager.o 

CPP_DEPS += \
./WaypointsManager/node.d \
./WaypointsManager/waypoints_manager.d 


# Each subdirectory must supply rules for building sources it contributes
WaypointsManager/%.o: ../WaypointsManager/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


