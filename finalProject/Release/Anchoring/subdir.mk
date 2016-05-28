################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Anchoring/LocalizationManager.cpp \
../Anchoring/Particle.cpp 

OBJS += \
./Anchoring/LocalizationManager.o \
./Anchoring/Particle.o 

CPP_DEPS += \
./Anchoring/LocalizationManager.d \
./Anchoring/Particle.d 


# Each subdirectory must supply rules for building sources it contributes
Anchoring/%.o: ../Anchoring/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


