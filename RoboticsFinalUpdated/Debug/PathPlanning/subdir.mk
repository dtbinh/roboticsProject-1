################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PathPlanning/PathFinder.cpp \
../PathPlanning/PathPlanner.cpp \
../PathPlanning/Point.cpp \
../PathPlanning/WaypointsManager.cpp 

OBJS += \
./PathPlanning/PathFinder.o \
./PathPlanning/PathPlanner.o \
./PathPlanning/Point.o \
./PathPlanning/WaypointsManager.o 

CPP_DEPS += \
./PathPlanning/PathFinder.d \
./PathPlanning/PathPlanner.d \
./PathPlanning/Point.d \
./PathPlanning/WaypointsManager.d 


# Each subdirectory must supply rules for building sources it contributes
PathPlanning/%.o: ../PathPlanning/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


