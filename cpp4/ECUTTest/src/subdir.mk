################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/data.cpp \
../src/list.cpp \
../src/node.cpp \
../src/sortList.cpp 

OBJS += \
./src/data.o \
./src/list.o \
./src/node.o \
./src/sortList.o 

CPP_DEPS += \
./src/data.d \
./src/list.d \
./src/node.d \
./src/sortList.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -DECUT_MAIN=main -I/home/jun/C++/C++_assignment/jun_hws/cpp4/src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


