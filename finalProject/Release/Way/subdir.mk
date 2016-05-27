################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Way/AStar.cpp \
../Way/Node.cpp \
../Way/PathPlanner.cpp \
../Way/WaypointsManager.cpp 

OBJS += \
./Way/AStar.o \
./Way/Node.o \
./Way/PathPlanner.o \
./Way/WaypointsManager.o 

CPP_DEPS += \
./Way/AStar.d \
./Way/Node.d \
./Way/PathPlanner.d \
./Way/WaypointsManager.d 


# Each subdirectory must supply rules for building sources it contributes
Way/%.o: ../Way/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


