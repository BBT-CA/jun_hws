################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../.ecut-sources/EcutClient.cpp 

OBJS += \
./.ecut-sources/EcutClient.o 

CPP_DEPS += \
./.ecut-sources/EcutClient.d 


# Each subdirectory must supply rules for building sources it contributes
.ecut-sources/%.o: ../.ecut-sources/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DECUT_MAIN=main -I/home/jun/C++/C++_assignment/jun_hws/cpp4/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


