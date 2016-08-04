################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Utils/Location.cpp \
../Utils/Position.cpp \
../Utils/Utils.cpp \
../Utils/general.cpp 

OBJS += \
./Utils/Location.o \
./Utils/Position.o \
./Utils/Utils.o \
./Utils/general.o 

CPP_DEPS += \
./Utils/Location.d \
./Utils/Position.d \
./Utils/Utils.d \
./Utils/general.d 


# Each subdirectory must supply rules for building sources it contributes
Utils/%.o: ../Utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


