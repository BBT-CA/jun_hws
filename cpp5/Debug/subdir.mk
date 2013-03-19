################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../circleNode.cpp \
../data.cpp \
../doubleLinkedList.cpp \
../list.cpp \
../main.cpp \
../node.cpp \
../singleLinkedList.cpp \
../sortDoubleLinkedList.cpp 

OBJS += \
./circleNode.o \
./data.o \
./doubleLinkedList.o \
./list.o \
./main.o \
./node.o \
./singleLinkedList.o \
./sortDoubleLinkedList.o 

CPP_DEPS += \
./circleNode.d \
./data.d \
./doubleLinkedList.d \
./list.d \
./main.d \
./node.d \
./singleLinkedList.d \
./sortDoubleLinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


