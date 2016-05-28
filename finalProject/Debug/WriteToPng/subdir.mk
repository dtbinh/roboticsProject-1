################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../WriteToPng/main.cpp \
../WriteToPng/pngUtil.cpp 

OBJS += \
./WriteToPng/main.o \
./WriteToPng/pngUtil.o 

CPP_DEPS += \
./WriteToPng/main.d \
./WriteToPng/pngUtil.d 


# Each subdirectory must supply rules for building sources it contributes
WriteToPng/%.o: ../WriteToPng/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


