################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Utils/ParametersFile.cpp \
../Utils/Utils.cpp \
../Utils/lodepng.cpp 

OBJS += \
./Utils/ParametersFile.o \
./Utils/Utils.o \
./Utils/lodepng.o 

CPP_DEPS += \
./Utils/ParametersFile.d \
./Utils/Utils.d \
./Utils/lodepng.d 


# Each subdirectory must supply rules for building sources it contributes
Utils/%.o: ../Utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -I/usr/include/c++/4.2.4 -I/usr/include/c++/4.2 -I/usr/include/c++/4.2.4/i486-linux-gnu -I/usr/include/c++ -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


