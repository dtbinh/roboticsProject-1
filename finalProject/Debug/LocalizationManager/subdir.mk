################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LocalizationManager/localization_manager.cpp 

OBJS += \
./LocalizationManager/localization_manager.o 

CPP_DEPS += \
./LocalizationManager/localization_manager.d 


# Each subdirectory must supply rules for building sources it contributes
LocalizationManager/%.o: ../LocalizationManager/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


