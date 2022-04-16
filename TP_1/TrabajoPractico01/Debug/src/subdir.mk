################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BibliotecaOperaciones.c \
../src/TrabajoPractico01.c 

C_DEPS += \
./src/BibliotecaOperaciones.d \
./src/TrabajoPractico01.d 

OBJS += \
./src/BibliotecaOperaciones.o \
./src/TrabajoPractico01.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/BibliotecaOperaciones.d ./src/BibliotecaOperaciones.o ./src/TrabajoPractico01.d ./src/TrabajoPractico01.o

.PHONY: clean-src

