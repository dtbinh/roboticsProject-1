################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Utils/Converter.cpp \
../Utils/general.cpp \
../Utils/lodepng.cpp \
../Utils/position.cpp \
../Utils/structs.cpp 

OBJS += \
./Utils/Converter.o \
./Utils/general.o \
./Utils/lodepng.o \
./Utils/position.o \
./Utils/structs.o 

CPP_DEPS += \
./Utils/Converter.d \
./Utils/general.d \
./Utils/lodepng.d \
./Utils/position.d \
./Utils/structs.d 


# Each subdirectory must supply rules for building sources it contributes
Utils/%.o: ../Utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


